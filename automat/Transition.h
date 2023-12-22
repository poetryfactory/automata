#pragma once
#include "State.h"
#include "global.h"

class Transition
{
public:
	Transition(State _from, State _to);
	Transition(State _from, State _to, char _input);
	Transition(State _from, std::vector<State> _to);
	Transition(State _from, std::vector<State> _to, char _input);
	State getFromState() const;
	State getToState() const;
	char getInput() const;
	std::vector<State> getToState_NFA() const;
private:
	State fromState;
	State toState;
	std::vector<State> toState_NFA;
	char input;
};

bool transitionSortCMP(Transition a, Transition b);