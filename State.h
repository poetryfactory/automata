#pragma once
#include "global.h"
class State
{
public:
	State();
	// ”“÷µøΩ±¥
	State(std::string _name);
	State(std::string _name, int _type);
	State(const State &_state);
	int getID() const;
	std::string getName() const;
	int getType() const;
	void setID(int _id);
	void setName(std::string _name);
	void setType(int _type);
	bool isStartState();
	bool isEndState();
	bool operator<(State b) const;
	bool operator==(State b) const;

private:
	std::string state_name;
	int state_id;
	int type; // 1:start 2:end 0:normal
};