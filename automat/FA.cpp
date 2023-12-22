#include "FA.h"

FA::FA(State _startState, std::vector<State> _endStates, std::vector<State> _states, std::vector<Transition> _transitions)
{
	this->id = 0;
	this->startState = _startState;
	this->endStates = _endStates;
	this->States = _states;
	this->id = 0;
	for (auto& state : _states)
	{
		state.setID(id);
		hash[id] = state.getName();
		id++;
	}
};

FA::FA(std::vector<State> _states, std::vector<Transition> _transitions)
{
	this->id = 0;
	State st;
	this->startState = st;
	std::vector<State> ends;
	for (auto& state : _states)
	{
		state.setID(id);
		hash[id] = state.getName();
		id++;
		if (state.isStartState())
		{
			if (startState.getID() == INIT_ID)
			{
				startState = state;
			}
			else
			{
				STEXP;
			}
		}
		else if (state.isEndState())
		{
			ends.emplace_back(state);
		}
	}
	this->endStates = ends;
	this->States = _states;
};

std::string FA::getStateName(int _id)
{
	return hash[_id];
};

void FA::addState(State _state)
{
	if (_state.getType() == END_TYPE)
	{
		endStates.emplace_back(_state);
	}
	else if (_state.getType() == START_TYPE)
	{
		if (startState.getID() == INIT_ID)
		{
			startState = _state;
		}
		else
		{
			STEXP;
			return;
		}
	}
	_state.setID(id);
	hash[id] = _state.getName();
	id++;
	States.emplace_back(_state);
};

int FA::size()
{
	return (int)States.size();
}

State FA::addState(std::string _name, int _type)
{
	State st(_name, _type);
	if (_type == END_TYPE)
	{
		endStates.emplace_back(st);
	}
	else if (_type == START_TYPE)
	{
		if (startState.getID() == INIT_ID)
		{
			startState = st;
		}
		else
		{
			STEXP;
			return st;
		}
	}
	st.setID(id);
	hash[id] = _name;
	id++;
	States.emplace_back(st);
	return st;
};

State FA::getStartState()
{
	return this->startState;
};

std::vector<State> FA::getEndStates()
{
	return this->endStates;
}
