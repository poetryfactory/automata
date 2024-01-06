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
	std::cout << "\t0\t1" << std::endl;  //��һ��
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
	}
};

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
	for (const auto& state : this->getStates())
	{
		stateToLetter[state] = toLetter++;
	}

	// ����DFA������ת��  
	for (auto& transition : this->Transitions)
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

