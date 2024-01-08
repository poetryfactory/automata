#include "global.h"
#include "FA.h"
#include "State.h"
#include "Transition.h"
#include "DFA.h"
#include "NFA.h"
#include "RG.h"

int main()
{
	State q1("q1",START_TYPE), q2("q2",NORMAL_TYPE), q3("q3",END_TYPE), q4("q4", END_TYPE),q5("q5", END_TYPE),q6("q6", NORMAL_TYPE);   //创建一些状态，调用状态的构造函数(状态名，状态类型)
	Transition t1(q1, q3, '0'), t2(q1, q2, '1'), t3(q2, q2, '0'), t4(q2, q1, '1'), t5(q3, q3, '0'), t6(q3, q2, '1');   //创建状态间的转换(DFA)
	//创建状态间的转换(NFA)
	Transition t01(q1, std::vector<State>{ q3 }, '0'), t02(q1, std::vector<State>{ q2,q3 }, '1'), t03(q2, std::vector<State>{ q2 }, '0'), t04(q2, std::vector<State>{ q1 }, '1'), t05(q3, std::vector<State>{ q3 }, '0'), t06(q3, std::vector<State>{ q2 }, '1');
	//将状态添加到一个vector里，方便到时候传给FA的构造函数
	State q11("q11", START_TYPE), q12("q12", NORMAL_TYPE), q13("q13", END_TYPE);  
	Transition t11(q11, std::vector<State>{ q13 }, '0'), t12(q11, std::vector<State>{ q12, q13 }, '1'), t13(q12, std::vector<State>{ q12 }, '0'), t14(q12, std::vector<State>{ q11 }, '1'), t15(q13, std::vector<State>{ q13 }, '0'), t16(q13, std::vector<State>{ q12 }, '1');
	std::vector<State> ss1;   
	ss1.push_back(q1);
	ss1.push_back(q2);
	ss1.push_back(q3);
	std::vector<State> ss2;
	ss2.push_back(q11);
	ss2.push_back(q12);
	ss2.push_back(q13);
	//转换同状态
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
	std::vector<Transition> tt3;
	tt3.push_back(t11);
	tt3.push_back(t12);
	tt3.push_back(t13);
	tt3.push_back(t14);
	tt3.push_back(t15);
	tt3.push_back(t16);
	//构造FA
	//DFA f1(ss1, tt1);
	//NFA f2(ss1, tt2);
	//NFA f3(ss2, tt3);
	////FA有成员函数addState用来在自动机内添加状态，返回State
	//State q4 = f1.addState("q4", NORMAL_TYPE);
	//State q5 = f1.addState("q5", START_TYPE);
	//f2.addState(q4);
	////添加转换
	//Transition t7 = f1.addTransition(q4, q1, '0');
	//Transition t8 = f1.addTransition(q4, q3, '1');
	//Transition t9 = f2.addTransition(q4, { q1,q2 }, '0');
	//Transition t10 = f2.addTransition(q4, { q3,q4 }, '1');
	//std::string a = "(0+1)*";
	//std::string b = "0*10(01+1*)*01";

	//NFA f1(a);
	//f1.print();
	std::vector<State> f1s;
	f1s.push_back(q1);
	f1s.push_back(q2);
	f1s.push_back(q3);
	f1s.push_back(q4);
	f1s.push_back(q5);
	f1s.push_back(q6);
	Transition a(q1, q2, '0'),b(q1,q3,'1'),c(q2,q1,'0'),d(q2,q4,'1'),e(q3,q6,'1'),f(q3,q5,'0'),g(q4,q5,'0'),h(q4,q6,'1'),hh(q5,q5,'0'),hhh(q5,q6,'1'),hhhh(q6,q6,'0'),hhhhh(q6,q6,'1');
	std::vector<Transition> tttt;
	tttt.push_back(a);
	tttt.push_back(b);
	tttt.push_back(c);
	tttt.push_back(d);
	tttt.push_back(e);
	tttt.push_back(f);
	tttt.push_back(g);
	tttt.push_back(h);
	tttt.push_back(hh);
	tttt.push_back(hhh);
	tttt.push_back(hhhh);
	tttt.push_back(hhhhh);

	DFA f1(f1s, tttt);
	f1.print();
	DFA f2 = f1.minimizeDFA();
	f2.print();
	//NFA f2(b);
	//f2.print();
	//Transition t11 = f2.addTransition(q4, { q1,q3,q4 },epsi);
	//打印
	//f1.print();
	/*NFA f4 = f2.cat(f3);
	NFA f5 = f2 + f3;
	NFA f6 = f2.close();
	f2.print();
	f3.print();
	f4.print();
	f5.print();
	f6.print();*/
	//正则文法的构造，括号里传的是状态数，也就是非终结符的个数
	//RG r1(2);
	////正则文法添加表达式
	//r1.addExp('A', "0B");
	//r1.addExp('A', "0");
	//r1.addExp('B', "1B");
	//r1.addExp('B', "1");
	////正则文法打印
	//f1.print();
	//RG r1 = f1.convert();
	//r1.print();
	return 0;
}