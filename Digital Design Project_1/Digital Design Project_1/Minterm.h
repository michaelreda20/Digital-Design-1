
#pragma once
#include "term.h"
#include <iostream>
using namespace std;
class Minterm : public term
{
public:
	Minterm(long long num, int var_num);
};
