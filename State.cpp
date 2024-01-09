#include "State.h"

State::State()
{
	this->state_id = INIT_ID;
	this->state_name = INIT_NAME;
	this->type = INIT_TYPE;
};

State::State(std::string name) :state_name(name), type(INIT_TYPE),state_id(INIT_ID)
{

};

State::State(std::string _name, int _type) :state_name(_name), type(_type),state_id(INIT_ID)
{

};

State::State(const State& _state)
{
	if(this != &_state)
	{
		this->state_name = _state.getName();
		this->state_id = _state.getID();
		this->type = _state.getType();
	}
};

int State::getID() const
{
	return this->state_id;
};

int State::getType() const
{
	return this->type;
};

std::string State::getName() const
{
	return this->state_name;
};

void State::setID(int _id)
{
	this->state_id = _id;
};

bool State::operator < (State b) const
{
	return this->getName() < b.getName();
};

bool State::operator == (State b) const
{
	return this->state_name == b.getName();
};

void State::setName(std::string _name)
{
	this->state_name = _name;
};

void State::setType(int _type)
{
	this->type = _type;
}

bool State::isEndState()
{
	return this->getType() == END_TYPE;
}

bool State::isStartState()
{
	return this->getType() == START_TYPE;
}