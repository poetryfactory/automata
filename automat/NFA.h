#pragma once
#include "FA.h"
#include "helper.cpp"
class NFA:public FA
{
public:
	NFA();
	NFA(State _startState, std::vector<State> _endStates, std::vector<State> _states, std::vector<Transition> _transitions);
	NFA(const std::string regex);
	NFA(std::vector<State> _states, std::vector<Transition> _transitions);
	NFA(std::vector<State> _states, std::vector<Transition> _transitions,int* _nextname);
	virtual void print();
	std::vector<State> getTransitionStates(State _from, int _input);
	virtual void addTransition(Transition _tr);
	Transition addTransition(State _from, std::vector<State> _to, char _input);
	Transition addTransition(State _from, State _to, char _input);
	NFA cat(NFA nfa2);
	NFA operator+(NFA nfa2);
	NFA close();
protected:
	std::unordered_map<std::pair<State, char>, std::vector<State>, Hash, Equal> Transitions;
	int *nextname = new int(1);    //保证状态不重名
};
