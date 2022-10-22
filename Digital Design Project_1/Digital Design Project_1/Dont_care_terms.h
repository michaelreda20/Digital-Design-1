#pragma once
#include "term.h"

using namespace std;
class Dont_care_terms : public term
{
public:
	Dont_care_terms(long long num, int var_num);
};
