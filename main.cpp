#include "global.h"
#include "FA.h"
#include "State.h"
#include "Transition.h"
#include "DFA.h"
#include "NFA.h"
#include "RG.h"

int main()
{
	std::string re;
	int output_name_index = 1;
	while (output_name_index <= 5)
	{
		freopen(((std::string)("re_" + std::to_string(output_name_index) + ".txt")).c_str(), "r", stdin);
		std::cin >> re;
		NFA f1(re);
		// f1.print();
		DFA f2 = f1.toDFA();
		// f2.print();
		DFA f3 = f2.minimizeDFA();
		freopen(((std::string)("ans_" + std::to_string(output_name_index) + ".txt")).c_str(), "w", stdout);
		f3.print(output_name_index);
		RG r1 = f3.convert();
		freopen(((std::string)("rg_" + std::to_string(output_name_index) + ".txt")).c_str(), "w", stdout);
		r1.print();
		output_name_index++;
	}
	return 0;
}