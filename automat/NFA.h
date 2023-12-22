#pragma once
#include "FA.h"
class NFA:public FA
{
public:
	NFA(State _startState, std::vector<State> _endStates, std::vector<State> _states, std::vector<Transition> _transitions);
	NFA(std::vector<State> _states, std::vector<Transition> _transitions);
	virtual void print();
	std::vector<State> getTransitionStates(State _from, int _input);
	virtual void addTransition(Transition _tr);
	Transition addTransition(State _from, std::vector<State> _to, char _input);
protected:
	std::unordered_map<std::pair<State, char>, std::vector<State>, Hash, Equal> Transitions;
};

