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
	std::cout << "\t0\t1" << std::endl;  //µÚÒ»ÐÐ
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
