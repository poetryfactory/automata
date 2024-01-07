#include "DFA.h"

DFA::DFA(State _startState, std::vector<State> _endStates, std::vector<State> _states, std::vector<Transition> _transitions) :FA(_startState, _endStates, _states, _transitions)
{
	for (auto& t : _transitions)
	{
		Transitions[{t.getFromState(), t.getInput()}] = t.getToState();
	}
};

DFA::DFA(std::vector<State> _states, std::vector<Transition> _transitions) :FA(_states, _transitions)
{
	for (auto& t : _transitions)
	{
		Transitions[{t.getFromState(), t.getInput()}] = t.getToState();
	}
};

State DFA::getTransitionState(State _from, int _input)
{
	return Transitions[{_from, _input}];
};

void DFA::print()
{
	std::cout << "\t0\t1" << std::endl;  //第一行

	for (int i = 0;i < (int)this->States.size();++i)
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
};

void DFA::printGraph(const std::string& col) {
	std::fstream printDFA;
	printDFA.open("DFA.dot", std::ios::app);
	printDFA << "digraph graphDFA{ " << std::endl;
	printDFA << "s[shape=circle, color=white];q1;" << std::endl;
	//std::cout << col[0] << std::endl;
	if (col[0] == '#') {
		std::cout << "aaa" << std::endl;
		printDFA << "{rank=\"same\";s;q1}" << std::endl;
		printDFA << "s->q1[label=\"\\n\"];" << std::endl;
	}
	if (col[5] == '1' || col[5] == '2' || col[5] == '3') {
		std::cout << "bbb" << std::endl;
		printDFA << "q" << col[5] << ";" << std::endl;
		printDFA << "{rank=\"same\";q1;" << "q" << col[5] << "}" << std::endl;
		printDFA << "q1->" << "q" << col[5] << "[label=\"0\"]" << std::endl;
	}
	else if (col[8] == '1' || col[8] == '2' || col[8] == '3') {
		printDFA << "q" << col[8] << std::endl;
	}
	/*if (col[0] == 'q1' || col[0] == 'q2' || col[0] == 'q3') {
		printDFA << col[0] << ";" << std::endl;
		printDFA << "{rank=\"same\";q1;" << col[0] << "}" << std::endl;
		printDFA << "q1->" << col[0] << "[label=\"0\"]" << std::endl;
	}*/
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
	// 创建一个RG的实例，其非终结符的数量等于DFA中状态的数量  
	RG rg(this->getStates().size());

	// 创建一个映射，将每个状态与一个大写字母关联  
	std::map<State, char> stateToLetter;
	char toLetter = 'A'; // 开始的字母  

	// 遍历DFA的所有状态，为每个状态分配一个大写字母  
	for (const auto& state : this->getStates())
	{
		stateToLetter[state] = toLetter++;
	}

	// 遍历DFA的所有转换  
	for (auto& transition : this->Transitions)
	{
		// 获取DFA的起始状态、结束状态和输入符号  
		State fromState = transition.first.first;
		char inputSymbol = transition.first.second;
		State toState = transition.second;

		// 将DFA的每个转换转换为一个RG表达式，转换规则为：δ(q,a)=p~q->ap、δ(q,a)=p∈F~q->a，格式为“非终结符 > (字符)(非终结符)”、“非终结符 > 字符”
		char letter = static_cast<char>(stateToLetter[toState]);
		std::string expression = inputSymbol + std::string(1, letter);

		// 将表达式“非终结符 > (字符)(非终结符)”添加到RG中，使用状态对应的大写字母作为参数
		rg.addExp(stateToLetter[fromState], expression);

		// 若toState是终止状态，则将表达式“非终结符 > 字符”添加到RG中
		if (toState.isEndState()) 
			rg.addExp(stateToLetter[fromState], std::string(1, inputSymbol));
	}

	// 返回转换后的RG  
	return rg;
}

