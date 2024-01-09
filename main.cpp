#include "global.h"
#include "FA.h"
#include "State.h"
#include "Transition.h"
#include "DFA.h"
#include "NFA.h"
#include "RG.h"

int main()
{
	std::string re = "0*10(01+1*)*01";
	// std::cin >> re;
	NFA f1(re);
	f1.print();
	DFA f2 = f1.toDFA();
	f2.print();
	DFA f3 = f2.minimizeDFA();
	// freopen("ans_1.txt", "w", stdout);
	f3.print();
	RG r1 = f3.convert();
	// freopen("rg_1.txt", "w", stdout);
	r1.print();
	return 0;
}