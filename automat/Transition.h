#pragma once
#include "State.h"
#include "global.h"

class Transition
{
public:
	Transition();
	Transition(State _from, State _to);
	Transition(State _from, State _to, char _input);
	Transition(State _from, std::vector<State> _to);
	Transition(State _from, std::vector<State> _to, char _input);
	State getFromState() const;
	State getToState() const;
	char getInput() const;
	void setFromState(State _state);
	void setToState(State _state);
	void setToState_NFA(State _state);
	void setInput(char _input);
	std::vector<State> getToState_NFA() const;
private:
	State fromState;
	State toState;
	std::vector<State> toState_NFA;
	char input;
};

bool transitionSortCMP(Transition a, Transition b);