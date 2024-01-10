#include "DFA.h"

DFA::DFA(){

};

DFA::DFA(State _startState, std::vector<State> _endStates, std::vector<State> _states, std::vector<Transition> _transitions) : FA(_startState, _endStates, _states, _transitions)
{
	State trap = State("q100", NORMAL_TYPE);
	bool flag = 1;
	for (auto &t : _transitions)
	{
		Transitions[{t.getFromState(), t.getInput()}] = t.getToState();
		if (_transitions.size() < 2 * _states.size())
		{
			flag = 0;
		}
	}
	if (!flag)
	{
		this->addState(trap);
		for (auto state : States)
		{
			for (char i = '0'; i <= '1'; ++i)
			{
				if (Transitions.find({state, i}) == Transitions.end())
				{
					this->addTransition(state, trap, i);
				}
			}
		}
	}
};

DFA::DFA(std::vector<State> _states, std::vector<Transition> _transitions) : FA(_states, _transitions)
{
	State trap = State("q100", NORMAL_TYPE);
	bool flag = 1;
	for (auto &t : _transitions)
	{
		Transitions[{t.getFromState(), t.getInput()}] = t.getToState();
		if (_transitions.size() < 2 * _states.size())
		{
			flag = 0;
		}
	}
	if (!flag)
	{
		this->addState(trap);
		for (auto state : States)
		{
			for (char i = '0'; i <= '1'; ++i)
			{
				if (Transitions.find({state, i}) == Transitions.end())
				{
					this->addTransition(state, trap, i);
				}
			}
		}
	}
};

State DFA::getTransitionState(State _from, int _input)
{
	return Transitions[{_from, _input}];
};

void DFA::print()
{
	std::cout << "\t0\t1" << std::endl; // ��һ��
	std::fstream printDFA;
	printDFA.open("DFA.dot", std::ios::out);
	printDFA.close();
	for (int i = 0; i < (int)this->States.size(); ++i)
	{
		std::string col = "";
		if (this->States[i].isStartState())
		{
			col += "#";
		}
		else if (this->States[i].isEndState())
		{
			col += "*";
		}
		col += this->States[i].getName() + "\t";
		col += this->getTransitionState(States[i], '0').getName() + "\t";
		col += this->getTransitionState(States[i], '1').getName() + "\t";
		std::cout << col << std::endl;
		printGraph(col);
	}
	printDFA.open("DFA.dot", std::ios::app);
	printDFA << "}" << std::endl;
	system("dot -Tpng DFA.dot -o DFA.png");
};

void DFA::printGraph(const std::string &col)
{
	std::fstream printDFA;
	printDFA.open("DFA.dot", std::ios::app);
	if (printdfa_flag == 0)
	{
		printDFA << "digraph graphDFA{ " << std::endl;
		printDFA << "s[shape=circle, color=white];" << std::endl;
		printdfa_flag = 1;
	}
	if (col[0] == '#')
	{
		printDFA << "q" << col[2] << ";" << std::endl;
		printDFA << "{rank=\"same\";s;"
				 << "q" << col[2] << "}" << std::endl;
		printDFA << "s->q" << col[2] << "[label = \"\\n\"];" << std::endl;
		if (col[5] == '1' || col[5] == '2' || col[5] == '3')
		{
			printDFA << "q" << col[5] << ";" << std::endl;
			printDFA << "{rank=\"same\";q" << col[2] << ";"
					 << "q" << col[5] << " }" << std::endl;
			printDFA << "q" << col[2] << "->"
					 << "q" << col[5] << "[label = \"0\"];" << std::endl;
		}
		if (col[8] == '1' || col[8] == '2' || col[8] == '3')
		{
			printDFA << "q" << col[8] << ";" << std::endl;
			printDFA << "q" << col[2] << "->q" << col[8] << "[label=\"1\"];" << std::endl;
		}
	}
	if (col[0] != '#' && col[0] != '*')
	{
		printDFA << "q" << col[1] << ";" << std::endl;
		if (col[4] == '1' || col[4] == '2' || col[4] == '3')
		{
			printDFA << "q" << col[4] << ";" << std::endl;
			printDFA << "q" << col[1] << "->q" << col[4] << "[label = \"0\"];" << std::endl;
		}
		if (col[7] == '1' || col[7] == '2' || col[7] == '3')
		{
			printDFA << "q" << col[7] << ";" << std::endl;
			printDFA << "q" << col[1] << "->q" << col[7] << "[label=\"1\"];" << std::endl;
		}
	}
	if (col[0] == '*')
	{
		printDFA << "q" << col[2] << "[shape=\"doublecircle\"];" << std::endl;
		if (col[5] == '1' || col[5] == '2' || col[5] == '3')
		{
			printDFA << "q" << col[5] << ";" << std::endl;
			printDFA << "q" << col[2] << "->"
					 << "q" << col[5] << "[label = \"0\"];" << std::endl;
		}
		if (col[8] == '1' || col[8] == '2' || col[8] == '3')
		{
			printDFA << "q" << col[8] << ";" << std::endl;
			printDFA << "q" << col[2] << "->"
					 << "q" << col[8] << "[label = \"1\"];" << std::endl;
		}
	}
	printDFA.close();
}

void DFA::addTransition(Transition _tr)
{
	Transitions[{_tr.getFromState(), _tr.getInput()}] = _tr.getToState();
};

Transition DFA::addTransition(State _from, State _to, char _input)
{
	Transitions[{_from, _input}] = _to;
	return Transition(_from, _to, _input);
};

std::vector<State> DFA::getStates()
{
	return States;
}

RG DFA::convert()
{
	// ����һ��RG��ʵ��������ս������������DFA��״̬������
	RG rg(this->getStates().size());

	// ����һ��ӳ�䣬��ÿ��״̬��һ����д��ĸ����
	std::map<State, char> stateToLetter;
	char toLetter = 'A'; // ��ʼ����ĸ

	// ����DFA������״̬��Ϊÿ��״̬����һ����д��ĸ
	for (const auto &state : this->getStates())
	{
		stateToLetter[state] = toLetter++;
	}

	// ����DFA������ת��
	for (auto &transition : this->Transitions)
	{
		// ��ȡDFA����ʼ״̬������״̬���������
		State fromState = transition.first.first;
		char inputSymbol = transition.first.second;
		State toState = transition.second;

		// ��DFA��ÿ��ת��ת��Ϊһ��RG���ʽ��ת������Ϊ����(q,a)=p~q->ap����(q,a)=p��F~q->a����ʽΪ�����ս�� > (�ַ�)(���ս��)���������ս�� > �ַ���
		char letter = static_cast<char>(stateToLetter[toState]);
		std::string expression = inputSymbol + std::string(1, letter);

		// �����ʽ�����ս�� > (�ַ�)(���ս��)����ӵ�RG�У�ʹ��״̬��Ӧ�Ĵ�д��ĸ��Ϊ����
		rg.addExp(stateToLetter[fromState], expression);

		// ��toState����ֹ״̬���򽫱��ʽ�����ս�� > �ַ�����ӵ�RG��
		if (toState.isEndState())
			rg.addExp(stateToLetter[fromState], std::string(1, inputSymbol));
	}

	// ����ת�����RG
	return rg;
}

DFA DFA::minimizeDFA()
{
	// �����ȼ۹�ϵ����
	int n = this->size();
	std::vector<std::vector<bool>> equivalent(n + 5, std::vector<bool>(n + 5, false));

	// ��ʼ����Ǿ���
	std::vector<std::vector<bool>> marked(n + 5, std::vector<bool>(n + 5, false));

	// ��Ƿǽ���״̬�����״̬������
	for (State s1 : this->getStates())
	{
		for (State s2 : this->getStates())
		{
			if ((s1.isEndState() && !s2.isEndState()) || (!s1.isEndState() && s2.isEndState()))
			{
				equivalent[s1.getName()[1] - '0'][s2.getName()[1] - '0'] = true;
				equivalent[s2.getName()[1] - '0'][s1.getName()[1] - '0'] = true;
			}
		}
	}
	// �𲽱�ǵȼ�״̬
	markEquivalentStates(equivalent, marked);
	/*for (int i = 1;i <= n + 1;++i)
	{
		for (int j = 1;j <= n + 1;++j)
		{
			if(i!=j&&equivalent[i][j]==0)
			std::cout << "i=" << i << " j=" << j << " e[i][j]=" << equivalent[i][j] << " ";
		}
		std::cout<<std::endl;
	}*/
	// ������С��DFA
	std::vector<std::set<State>> equivalence_classes;
	std::vector<bool> vis(n + 1, false);
	for (auto s1 : this->getStates())
	{
		if (vis[s1.getName()[1] - '0'])
			continue;
		std::set<State> eq_class;
		eq_class.insert(s1);
		for (auto s2 : this->getStates())
		{
			if (!equivalent[s1.getName()[1] - '0'][s2.getName()[1] - '0'])
			{
				eq_class.insert(s2);
				vis[s2.getName()[1] - '0'] = 1;
			}
		}
		equivalence_classes.push_back(eq_class);
	}

	// ������С��DFA����״̬���Ϻ�ת�ƹ�ϵ
	int m = equivalence_classes.size();
	// std::cout << m << std::endl;
	std::vector<Transition> min_transitions;
	std::vector<State> min_states(m);

	for (int i = 0; i < m; ++i)
	{
		State s("q" + std::to_string(i + 1), NORMAL_TYPE);
		for (auto state : equivalence_classes[i])
		{
			if (state.isEndState())
			{
				s.setType(END_TYPE);
			}
			else if (state.isStartState())
			{
				s.setType(START_TYPE);
			}
		}
		min_states[i] = s;
	}
	DFA dfa(min_states, {});
	for (int i = 0; i < m; ++i)
	{
		for (int j = '0'; j <= '1'; ++j)
		{
			std::set<State> next_states;
			for (auto state : equivalence_classes[i])
			{
				State nxt = Transitions[{state, j}];
				for (int idx = 0; idx < m; ++idx)
				{
					if (equivalence_classes[idx].find(nxt) != equivalence_classes[idx].end())
					{
						dfa.addTransition(min_states[i], min_states[idx], j);
					}
				}
			}
		}
	}
	return dfa;
}

void DFA::markEquivalentStates(std::vector<std::vector<bool>> &equivalent, std::vector<std::vector<bool>> &marked)
{
	int n = this->size();
	bool changes = true;

	while (changes)
	{
		changes = false;
		for (State s1 : this->getStates())
		{
			for (State s2 : this->getStates())
			{
				if (!marked[s1.getName()[1] - '0'][s2.getName()[1] - '0'] && !equivalent[s1.getName()[1] - '0'][s2.getName()[1] - '0'])
				{
					for (int k = '0'; k <= '1'; ++k)
					{
						State state1 = Transitions[{s1, k}];
						State state2 = Transitions[{s2, k}];
						if (equivalent[state1.getName()[1] - '0'][state2.getName()[1] - '0'])
						{
							equivalent[s1.getName()[1] - '0'][s2.getName()[1] - '0'] = true;
							equivalent[s2.getName()[1] - '0'][s1.getName()[1] - '0'] = true;
							changes = true;
							break;
						}
					}
					if (changes)
					{
						break;
					}
				}
			}
		}
		// ����Ѵ����״̬
		for (State s1 : this->getStates())
		{
			for (State s2 : this->getStates())
			{
				if (equivalent[s1.getName()[1] - '0'][s2.getName()[1] - '0'])
				{
					marked[s1.getName()[1] - '0'][s2.getName()[1] - '0'] = true;
					marked[s2.getName()[1] - '0'][s1.getName()[1] - '0'] = true;
				}
			}
		}
	}
}