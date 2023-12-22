#include "global.h"
#include "FA.h"
#include "State.h"
#include "Transition.h"
#include "DFA.h"
#include "NFA.h"
#include "RG.h"

int main()
{
	State q1("q1",START_TYPE), q2("q2",NORMAL_TYPE), q3("q3",END_TYPE);   //����һЩ״̬������״̬�Ĺ��캯��(״̬����״̬����)
	Transition t1(q1, q3, '0'), t2(q1, q2, '1'), t3(q2, q2, '0'), t4(q2, q1, '1'), t5(q3, q3, '0'), t6(q3, q2, '1');   //����״̬���ת��(DFA)
	//����״̬���ת��(NFA)
	Transition t01(q1, std::vector<State>{ q3 }, '0'), t02(q1, std::vector<State>{ q2,q3 }, '1'), t03(q2, std::vector<State>{ q2 }, '0'), t04(q2, std::vector<State>{ q1 }, '1'), t05(q3, std::vector<State>{ q3 }, '0'), t06(q3, std::vector<State>{ q2 }, '1');
	//��״̬��ӵ�һ��vector����㵽ʱ�򴫸�FA�Ĺ��캯��
	std::vector<State> ss1;   
	ss1.push_back(q1);
	ss1.push_back(q2);
	ss1.push_back(q3);
	//ת��ͬ״̬
	std::vector<Transition> tt1;
	tt1.push_back(t1);
	tt1.push_back(t2);
	tt1.push_back(t3);
	tt1.push_back(t4);
	tt1.push_back(t5);
	tt1.push_back(t6);
	std::vector<Transition> tt2;
	tt2.push_back(t01);
	tt2.push_back(t02);
	tt2.push_back(t03);
	tt2.push_back(t04);
	tt2.push_back(t05);
	tt2.push_back(t06);
	//����FA
	DFA f1(ss1, tt1);
	NFA f2(ss1, tt2);
	//FA�г�Ա����addState�������Զ��������״̬������State
	State q4 = f1.addState("q4", NORMAL_TYPE);
	State q5 = f1.addState("q5", START_TYPE);
	f2.addState(q4);
	//���ת��
	Transition t7 = f1.addTransition(q4, q1, '0');
	Transition t8 = f1.addTransition(q4, q3, '1');
	Transition t9 = f2.addTransition(q4, { q1,q2 }, '0');
	Transition t10 = f2.addTransition(q4, { q3,q4 }, '1');
	Transition t11 = f2.addTransition(q4, { q1,q3,q4 },epsi);
	//��ӡ
	f1.print();
	f2.print();
	//�����ķ��Ĺ��죬�����ﴫ����״̬����Ҳ���Ƿ��ս���ĸ���
	RG r1(2);
	//�����ķ���ӱ��ʽ
	r1.addExp('A', "0B");
	r1.addExp('A', "0");
	r1.addExp('B', "1B");
	r1.addExp('B', "1");
	//�����ķ���ӡ
	r1.print();
	return 0;
}