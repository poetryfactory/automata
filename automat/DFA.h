#pragma once
#include "FA.h"
#include "RG.h"


class DFA :public FA
{
public:
	DFA();
	DFA(State _startState, std::vector<State> _endStates, std::vector<State> _states, std::vector<Transition> _transitions);
	DFA(std::vector<State> _states, std::vector<Transition> _transitions);
	virtual void print();
	void printGraph(const std::string& col);
	State getTransitionState(State _from, int _input);
	virtual void addTransition(Transition _tr);
	Transition addTransition(State _from, State _to, char _input);
	std::vector<State> getStates();
	RG convert();
	DFA minimizeDFA();
	void markEquivalentStates(std::vector<std::vector<bool>>& equivalent, std::vector<std::vector<bool>>& marked);
protected:
	std::unordered_map<std::pair<State, char>, State, Hash, Equal> Transitions;
	bool printdfa_flag = 0;
};

