#pragma once
#include "global.h"
#include "DFA.h"
#include "NFA.h"
class RG
{
public:
	RG(int _V_size);
	void addExp(char _V, std::string _exp);
	bool isEle(char _V);
	void print();
private:
	const std::vector<char> Alpha = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};  //��д��ĸ�����RGʱ��������
	const std::vector<char> T = { 0,1 }; //�ս��
	std::vector<char> V;   //���ս��
	std::unordered_map<char, std::vector<std::string>> P; //����ʽ
};

