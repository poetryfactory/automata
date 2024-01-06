#pragma once
#include "FA.h"
#include "RG.h"


class DFA :public FA
{
public:
	DFA(State _startState, std::vector<State> _endStates, std::vector<State> _states, std::vector<Transition> _transitions);
	DFA(std::vector<State> _states, std::vector<Transition> _transitions);
	virtual void print();
	State getTransitionState(State _from, int _input);
	virtual void addTransition(Transition _tr);
	Transition addTransition(State _from, State _to, char _input);
	std::vector<State> getStates();
	RG convert();
protected:
	std::unordered_map<std::pair<State, char>, State, Hash, Equal> Transitions;
};

