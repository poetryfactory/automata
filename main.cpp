#include "global.h"
#include "FA.h"
#include "State.h"
#include "Transition.h"
#include "DFA.h"
#include "NFA.h"
#include "RG.h"

int main()
{
	std::string a = "0+1";
	std::string b = "0*10(01+1*)*01";
	std::string c = "(10*1+00*10*1)*00*";
	NFA f1(c);
	f1.print();
	DFA f2 = f1.toDFA();
	f2.print();
	DFA f3 = f2.minimizeDFA();
	f3.print();
	RG r1 = f3.convert();
	r1.print();
	return 0;
}