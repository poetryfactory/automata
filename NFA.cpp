#include "NFA.h"

std::string preOperation(const std::string &ex) // 预处理加连接号
{
	std::string infix;
	for (int i = 0; i < ex.size(); ++i)
	{
		if (i == ex.size() - 1)
		{
			infix += ex[i];
			break;
		}
		if (ex[i + 1] == '*' || (ex[i + 1] == '+') || ex[i] == '+' || ex[i] == '(' || ex[i + 1] == ')')
		{
			infix += ex[i];
			continue;
		}
		infix = infix + ex[i] + '.';
	}
	return infix;
}

bool isOperator(char c)
{
	return c == '*' || c == '.' || c == '+';
}

int getPrecedence(char op)
{
	switch (op)
	{
	case '*':
		return 3;
	case '.':
		return 2;
	case '+':
		return 1;
	default:
		return 0;
	}
}

std::string infixToPostfix(std::string infix)
{
	infix = preOperation(infix);
	// std::cout << infix << std::endl;   预处理结果test
	std::stack<char> opStack;
	std::string postfix;

	for (char c : infix)
	{
		if (isdigit(c))
		{
			postfix += c;
		}
		else if (c == '(')
		{
			opStack.push(c);
		}
		else if (c == ')')
		{
			while (!opStack.empty() && opStack.top() != '(')
			{
				postfix += opStack.top();
				opStack.pop();
			}
			if (!opStack.empty())
				opStack.pop(); // 弹出'('
		}
		else if (isOperator(c))
		{
			while (!opStack.empty() && getPrecedence(opStack.top()) >= getPrecedence(c))
			{
				postfix += opStack.top();
				opStack.pop();
			}
			opStack.push(c);
		}
	}

	while (!opStack.empty())
	{
		postfix += opStack.top();
		opStack.pop();
	}

	return postfix;
}

NFA::NFA(State _startState, std::vector<State> _endStates, std::vector<State> _states, std::vector<Transition> _transitions) : FA(_startState, _endStates, _states, _transitions)
{
	for (auto &t : _transitions)
	{
		Transitions[{t.getFromState(), t.getInput()}] = t.getToState_NFA();
	}
};

NFA::NFA(std::vector<State> _states, std::vector<Transition> _transitions) : FA(_states, _transitions)
{
	for (auto &t : _transitions)
	{
		Transitions[{t.getFromState(), t.getInput()}] = t.getToState_NFA();
	}
};

NFA::NFA(std::vector<State> _states, std::vector<Transition> _transitions, int *_nextname) : FA(_states, _transitions)
{
	for (auto &t : _transitions)
	{
		Transitions[{t.getFromState(), t.getInput()}] = t.getToState_NFA();
	}
	this->nextname = _nextname;
};

NFA::NFA(){

};

NFA::NFA(std::string regex)
{
	std::string postfix = infixToPostfix(regex);
	// std::cout << postfix << std::endl;   后缀结果test
	std::stack<NFA> nfaStack;

	for (char c : postfix)
	{
		if (isdigit(c))
		{
			NFA nfa({}, {}, this->nextname);
			State start("q" + std::to_string((*nextname)++), START_TYPE), end("q" + std::to_string((*nextname)++), END_TYPE);
			nfa.addState(start);
			nfa.addState(end);
			nfa.addTransition(start, end, c);
			nfaStack.push(nfa);
		}
		else
		{
			switch (c)
			{
			case '.':
			{ // 连接操作
				NFA nfa2 = nfaStack.top();
				nfaStack.pop();
				NFA nfa1 = nfaStack.top();
				nfaStack.pop();
				nfa1 = nfa1.cat(nfa2);
				nfaStack.push(nfa1);
				break;
			}
			case '+':
			{
				NFA nfa2 = nfaStack.top();
				nfaStack.pop();
				NFA nfa1 = nfaStack.top();
				nfaStack.pop();
				nfa1 = nfa1 + nfa2;
				nfaStack.push(nfa1);
				break;
			}
			case '*':
			{
				NFA nfa = nfaStack.top();
				nfaStack.pop();
				nfa = nfa.close();
				nfaStack.push(nfa);
				break;
			}
			}
		}
	}
	if (!nfaStack.empty())
	{
		*this = nfaStack.top();
	}
};

std::vector<State> NFA::getTransitionStates(State _from, int _input)
{
	return Transitions[{_from, _input}];
};

void NFA::print()
{
	std::cout << "\t" << epsilon << "\t\t0\t\t1" << std::endl; // 第一行
	for (int i = 0; i < (int)this->States.size(); ++i)
	{
		std::string raw = "";
		if (this->States[i].isStartState())
		{
			raw += "#";
		}
		else if (this->States[i].isEndState())
		{
			raw += "*";
		}
		raw += this->States[i].getName() + "\t{"; // 状态
		bool flag = 0;
		for (auto &state : getTransitionStates(States[i], epsi))
		{
			flag = 1;
			raw += state.getName() + ",";
		}
		if (flag)
		{
			raw.pop_back(); // 去掉最后一个逗号
			flag = 0;
		}
		raw += "}\t\t{"; // 空转移
		for (auto &state : getTransitionStates(States[i], '0'))
		{
			flag = 1;
			raw += state.getName() + ",";
		}
		if (flag)
		{
			raw.pop_back(); // 去掉最后一个逗号
			flag = 0;
		}
		raw += "}\t\t{"; // 0转移
		for (auto &state : getTransitionStates(States[i], '1'))
		{
			flag = 1;
			raw += state.getName() + ",";
		}
		if (flag)
		{
			raw.pop_back(); // 去掉最后一个逗号
			flag = 0;
		}
		raw += "}";
		std::cout << raw << std::endl;
	}
};

void NFA::addTransition(Transition _tr)
{
	Transitions[{_tr.getFromState(), _tr.getInput()}].push_back(_tr.getToState_NFA()[0]);
};

Transition NFA::addTransition(State _from, std::vector<State> _to, char _input)
{
	Transitions[{_from, _input}] = _to;
	return Transition(_from, _to, _input);
};

Transition NFA::addTransition(State _from, State _to, char _input)
{
	Transitions[{_from, _input}].push_back(_to);
	return Transition(_from, Transitions[{_from, _input}], _input);
}

NFA NFA::cat(NFA nfa2)
{
	std::vector<State> states = this->getStates();
	for (auto &state : states)
	{
		for (auto &s : this->getEndStates())
		{
			if (state == s)
			{
				state.setType(NORMAL_TYPE);
			}
		}
	}
	std::vector<State> state2 = nfa2.getStates();
	for (auto &state : state2)
	{
		if (state == nfa2.getStartState())
		{
			state.setType(NORMAL_TYPE);
		}
	}
	states.insert(states.end(), state2.begin(), state2.end());
	NFA nfa(states, {}, this->nextname);
	for (auto endState : this->getEndStates())
	{
		State st = nfa2.getStartState();
		endState.setType(NORMAL_TYPE);
		st.setType(NORMAL_TYPE);
		nfa.addTransition(endState, st, (char)epsi);
	}
	for (auto transition : nfa2.Transitions)
	{
		/*std::cout << transition.first.first.getName() << std::endl;
		for (auto s : transition.second)	std::cout << s.getName() << " ";
		std::cout << std::endl;*/
		nfa.addTransition(transition.first.first, transition.second, transition.first.second);
	}
	for (auto transition : this->Transitions)
	{
		/*std::cout << transition.first.first.getName() << std::endl;
		for (auto s : transition.second)	std::cout << s.getName() << " ";
		std::cout << std::endl;*/
		nfa.addTransition(transition.first.first, transition.second, transition.first.second);
	}
	return nfa;
}

NFA NFA::operator+(NFA nfa2)
{
	std::vector<State> states = this->getStates();
	for (auto &state : states)
	{
		for (auto &s : this->getEndStates())
		{
			if (state == s)
			{
				state.setType(NORMAL_TYPE);
			}
		}
		if (state == this->getStartState())
		{
			state.setType(NORMAL_TYPE);
		}
	}
	std::vector<State> state2 = nfa2.getStates();
	for (auto &state : state2)
	{
		if (state == nfa2.getStartState())
		{
			state.setType(NORMAL_TYPE);
		}
		for (auto &s : nfa2.getEndStates())
		{
			if (state == s)
			{
				state.setType(NORMAL_TYPE);
			}
		}
	}
	states.insert(states.end(), state2.begin(), state2.end());
	NFA nfa(states, {}, this->nextname);
	State newStart("q" + std::to_string((*nextname)++), START_TYPE), newEnd("q" + std::to_string((*nextname)++), END_TYPE);
	nfa.addState(newStart);
	nfa.addState(newEnd);

	nfa.addTransition(newStart, this->getStartState(), epsi);
	nfa.addTransition(newStart, nfa2.getStartState(), epsi);

	for (const auto &endState : this->getEndStates())
	{
		nfa.addTransition(endState, newEnd, epsi);
	}

	for (const auto &endState : nfa2.getEndStates())
	{
		nfa.addTransition(endState, newEnd, epsi);
	}
	for (auto &transition : nfa2.Transitions)
	{
		nfa.addTransition(transition.first.first, transition.second, transition.first.second);
	}
	for (auto &transition : this->Transitions)
	{
		nfa.addTransition(transition.first.first, transition.second, transition.first.second);
	}
	return nfa;
}

NFA NFA::close()
{
	std::vector<State> states = this->getStates();
	State st = this->getStartState();
	State ed = this->getEndStates()[0];
	for (auto &state : states)
	{
		if (state == st)
		{
			state.setType(NORMAL_TYPE);
		}
		if (state == ed)
		{
			state.setType(NORMAL_TYPE);
		}
	}
	NFA nfa(states, {}, this->nextname);
	State newStart("q" + std::to_string((*nextname)++), START_TYPE), newEnd("q" + std::to_string((*nextname)++), END_TYPE);
	nfa.addState(newStart);
	nfa.addState(newEnd);

	nfa.addTransition(newStart, {st}, epsi);
	nfa.addTransition(newStart, {newEnd}, epsi);

	for (const auto &endState : this->getEndStates())
	{
		nfa.addTransition(endState, {this->getStartState()}, epsi);
		nfa.addTransition(endState, {newEnd}, epsi);
	}
	for (auto &transition : this->Transitions)
	{
		nfa.addTransition(transition.first.first, transition.second, transition.first.second);
	}
	return nfa;
}

bool isEqual(const std::vector<State> &a, const std::vector<State> &b)
{

	if (a.size() != b.size())
		return false;
	int i, j;
	for (i = 0; i < a.size(); ++i)
	{
		for (j = 0; j < b.size(); ++j)
		{
			if (a[i].getName() == b[j].getName())
				break;
		}
		if (j == b.size()) // 没找到
			return false;
	}

	return true;
}

DFA NFA::toDFA()
{

	std::set<char> inputs = {'0', '1'}; // 输入集合

	std::vector<std::vector<State>> DFAStates; // DFA的状态集合,每个元素是一个状态集合
	std::vector<Transition> DFATransitions;	   // DFA的转换集合

	std::vector<State> startState = closure({this->getStartState()}); // NFA的起始状态集合

	// 用来存储DFA的状态集合的队列
	std::queue<std::vector<State>> stateQueue;
	stateQueue.push(startState);
	while (!stateQueue.empty())
	{
		// std::cout << stateQueue.size() << std::endl;
		auto state = stateQueue.front();
		stateQueue.pop();
		for (auto &input : inputs)
		{
			if (state.empty())
				continue;
			auto newState = closure(move(state, input));
			// std::cout << std::endl;
			if (newState.empty())
				continue;
			// 如果新状态集合不在DFA的状态集合中，则加入队列
			bool isNewState = true;
			if (DFAStates.empty())
			{
				DFAStates.push_back(state); // 加入队列
			}
			else
			{
				for (const auto &s : DFAStates)
				{
					if (isEqual(s, newState)) // 如果新状态集合已经在DFA的状态集合中，则不加入队列
					{
						isNewState = false; // 不是新状态
						break;
					}
				}
			}
			if (isNewState)
			{
				// for (const auto &s : DFAStates)
				// {
				// 	std::cout << "DFAStates:" << std::endl;
				// 	for (const auto &i : s)
				// 	{
				// 		std::cout << i.getName() << " ";
				// 	}
				// 	std::cout << std::endl;
				// }

				// std::cout << "newState:" << std::endl;
				// for (const auto &i : newState)
				// {
				// 	std::cout << i.getName() << " ";
				// }
				// std::cout << std::endl;

				stateQueue.push(newState);
				DFAStates.push_back(newState);
			}
		}
	}

	// 状态重新编号
	std::vector<State> newStates;
	State newStartState;

	std::vector<State> DFAEndStates; // DFA的终止状态集合

	for (int i = 0; i < (int)DFAStates.size(); ++i)
	{
		// 如果是开始状态
		if (std::find(DFAStates[i].begin(), DFAStates[i].end(), this->getStartState()) != DFAStates[i].end())
		{
			newStartState = State("q" + std::to_string(i), START_TYPE);
			newStates.push_back(newStartState);
			continue;
		}

		// 如果是终止状态
		bool isEndState = false;
		for (auto &endState : this->getEndStates())
		{
			if (std::find(DFAStates[i].begin(), DFAStates[i].end(), endState) != DFAStates[i].end())
			{
				isEndState = true;
				break;
			}
		}
		if (isEndState)
		{
			newStates.push_back(State("q" + std::to_string(i), END_TYPE));
			DFAEndStates.push_back(State("q" + std::to_string(i), END_TYPE));
		}
		else
		{
			newStates.push_back(State("q" + std::to_string(i), NORMAL_TYPE));
		}
	}
	// 打印DFA的状态集合
	// std::cout << "DFAStates:" << std::endl;
	// int i = 0;
	// for (const auto &state : newStates)
	// {
	// 	std::cout << state.getName() << " ";
	// 	for (int j = 0; j < DFAStates[i].size(); ++j)
	// 	{
	// 		std::cout << DFAStates[i][j].getName() << " ";
	// 	}
	// 	std::cout << std::endl;
	// 	++i;
	// }
	State trap("q100", NORMAL_TYPE);
	bool hasTrap = false;
	int n = DFAStates.size();
	for (int i = 0; i < n; ++i)
	{
		for (auto &input : inputs)
		{
			auto newState = closure(move(DFAStates[i], input));
			if (newState.empty())
			{
				continue;
			}
			// 如果新状态集合不在DFA的状态集合中，则加入队列
			int j = 0;
			bool hasState = false;
			for (; j < DFAStates.size(); ++j)
			{
				if (isEqual(DFAStates[j], newState))
				{
					hasState = true;
					break;
				}
			}
			if (hasState)
				DFATransitions.push_back(Transition(newStates[i], newStates[j], input));
		}
	}
	return DFA(newStartState, DFAEndStates, newStates, DFATransitions);
}

std::vector<State> NFA::closure(const std::vector<State> &_states)
{
	if (_states.empty())
		return {};
	std::vector<State> res;
	for (auto &state : _states)
	{
		res.push_back(state); // 先把自己加进去
	}
	bool isNewState = true; // 判断是否有新的状态加入
	while (isNewState)
	{
		isNewState = false;
		// std::cout << res.size() << "aaa" << std::endl;
		int cnt = 0;
		for (auto &state : res)
		{
			cnt++;
			if (getTransitionStates(state, epsi).empty())
				continue;
			for (auto newState : getTransitionStates(state, epsi))
			{
				// 如果新状态集合中没有该状态，则加入
				int i = 0;
				for (; i < res.size(); ++i)
				{
					if (res[i].getName() == newState.getName())
						break;
				}
				if (i == res.size())
				{
					res.push_back(newState);
					isNewState = true;
				}
			}
		}
	}
	return res;
}

std::vector<State> NFA::move(const std::vector<State> &_states, char _input)
{
	if (_states.empty())
		return {};
	std::vector<State> res;
	for (auto &state : _states)
	{
		if (getTransitionStates(state, _input).empty())
			continue;
		for (auto &newState : getTransitionStates(state, _input))
		{
			// 如果新状态集合中没有该状态，则加入
			int i = 0;
			for (; i < res.size(); ++i)
			{
				if (res[i].getName() == newState.getName())
					break;
			}
			if (i == res.size())
				res.push_back(newState);
		}
	}
	return res;
};