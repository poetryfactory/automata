#include "RG.h"

RG::RG(int _V_size)
{
	std::vector<char> _v;
	for (int i = 0;i < _V_size;++i)
	{
		_v.push_back(Alpha[i]);
	}
	this->V = _v;
};

	
bool RG::isEle(char _V)
{
	for (int i = 0;i < V.size();++i)
	{
		if (V[i] == _V)	return true;
	}
	return false;
};

void RG::addExp(char _V, std::string _exp)
{
	if (!isEle(_V))
	{
		NVEXP;
		return;
	}
	P[_V].push_back(_exp);
};

void RG::print()
{
	for (auto e : V)
	{
		if (!P[e].empty())
		{
			std::string raw = std::string(1,e);
			raw+=" > ";
			for (int i = 0;i<P[e].size()-1;++i)
			{
				raw += P[e][i] + "|";
			}
			raw += P[e][P[e].size() - 1];
			std::cout << raw << std::endl;
		}
	}
}

