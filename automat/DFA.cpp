#include "DFA.h"

DFA::DFA(State _startState, std::vector<State> _endStates, std::vector<State> _states, std::vector<Transition> _transitions) : FA(_startState, _endStates, _states, _transitions)
{
	for (auto &t : _transitions)
	{
		Transitions[{t.getFromState(), t.getInput()}] = t.getToState();
	}
};

DFA::DFA(std::vector<State> _states, std::vector<Transition> _transitions) : FA(_states, _transitions)
{
	for (auto &t : _transitions)
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
