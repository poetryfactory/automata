#pragma once
#include "global.h"
#include "State.h"
#include "Transition.h"

//自定义哈希函数，用于unordered_map
struct Equal
{
	bool operator () (const std::pair<State, char>& lhs, const std::pair<State, char>& rhs) const
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}
};

struct Hash
{
	std::size_t operator() (const std::pair<State, char>& self) const
	{
		static 	std::hash<std::string> hash_str;
		return hash_str(self.first.getName() + self.second);
	}
};

class FA
{
public:
	FA(State _startState, std::vector<State> _endStates, std::vector<State> _states, std::vector<Transition> _transitions);
	FA(std::vector<State> _states, std::vector<Transition> _transitions);
	std::string getStateName(int _id);
	State getStartState();
	int size();
	std::vector<State> getEndStates();
	void addState(State _state);
	State addState(std::string _name,int _type);
	virtual void addTransition(Transition _tr)=0;
	virtual void print()=0;
	//static size_t myHash(const std::pair<State,char>& self) noexcept;
protected:
	State startState;
	std::vector<State> endStates;
	std::vector<State> States;
	int id;
	std::unordered_map<int, std::string> hash;
};
