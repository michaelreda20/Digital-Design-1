#include "Minterm.h"
Minterm::Minterm(long long num, int var_num) {
	number = num;
	var_numbers = var_num;
	Initialize();
	covered_minterms.push_back(*this);
}