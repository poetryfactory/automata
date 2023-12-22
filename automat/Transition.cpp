#include "Transition.h"

Transition::Transition(State _from, State _to) :fromState(_from), toState(_to)
{
	this->input = epsi;
};

Transition::Transition(State _from, State _to, char _input) : fromState(_from), toState(_to), input(_input)
{

};

Transition::Transition(State _from, std::vector<State> _to) :fromState(_from), toState_NFA(_to)
{
	this->input = epsi;
};

Transition::Transition(State _from, std::vector<State> _to, char _input) : fromState(_from), toState_NFA(_to), input(_input)
{

};

State Transition::getFromState() const
{
	return this->fromState;
};

State Transition::getToState() const
{
	return this->toState;
};

char Transition::getInput() const
{
	return this->input;
};

std::vector<State> Transition::getToState_NFA() const
{
	return this->toState_NFA;
}

bool transitionSortCMP(Transition a, Transition b)
{
	if (a.getFromState() < b.getFromState())	return true;
	if (a.getToState() < b.getToState())	return true;
	return a.getInput() < b.getInput();
};
