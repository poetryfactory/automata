#include "NFA.h"

NFA::NFA(State _startState, std::vector<State> _endStates, std::vector<State> _states, std::vector<Transition> _transitions) :FA(_startState, _endStates, _states, _transitions)
{
	for (auto& t : _transitions)
	{
		Transitions[{t.getFromState(), t.getInput()}] = t.getToState_NFA();
	}
};

NFA::NFA(std::vector<State> _states, std::vector<Transition> _transitions) :FA(_states, _transitions)
{
	for (auto& t : _transitions)
	{
		Transitions[{t.getFromState(), t.getInput()}] = t.getToState_NFA();
	}
};

std::vector<State> NFA::getTransitionStates(State _from, int _input)
{
	return Transitions[{_from, _input}];
};

void NFA::print()      //还没写完！！！！！！！！
{
	std::cout << "\t"<<epsilon<<"\t\t0\t\t1" << std::endl;  //第一行
	for (int i = 0;i < (int)this->States.size();++i)
	{
		std::string raw = "";
		if (this->States[i].isStartState())
		{
			raw += "#";
		}
		else if (this->States[i].isEndState())
		{
			raw += "*";
		}
		raw += this->States[i].getName() + "\t{";   //状态
		bool flag = 0;
		for (auto &state : getTransitionStates(States[i], epsi))
		{
			flag = 1;
			raw += state.getName() + ",";
		}
		if (flag)
		{
			raw.pop_back();    //去掉最后一个逗号
			flag = 0;
		}
		raw += "}\t\t{";                               //空转移
		for (auto &state : getTransitionStates(States[i], '0'))
		{
			flag = 1;
			raw += state.getName() + ",";
		}
		if (flag)
		{
			raw.pop_back();    //去掉最后一个逗号
			flag = 0;
		}
		raw += "}\t\t{";								//0转移
		for (auto &state : getTransitionStates(States[i], '1'))
		{
			flag = 1;
			raw += state.getName() + ",";
		}
		if (flag)
		{
			raw.pop_back();    //去掉最后一个逗号
			flag = 0;
		}
		raw += "}";
		std::cout << raw << std::endl;
	}
};

void NFA::addTransition(Transition _tr)
{
	Transitions[{_tr.getFromState(), _tr.getInput()}] = _tr.getToState_NFA();
};

Transition NFA::addTransition(State _from, std::vector<State> _to, char _input = epsi)
{
	Transitions[{_from, _input}] = _to;
	return Transition(_from, _to, _input);
};