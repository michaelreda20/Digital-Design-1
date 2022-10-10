#include "term.h"
void term::Initialize() {
	Binary_Representation = "";
	long temp = number;
	while (temp > 0) {
		Binary_Representation = to_string(temp % 2) + Binary_Representation;
		temp = temp / 2;
	}
	Var_Representation = "";
	for (int i = 0; i < Binary_Representation.length(); i++) {
		Var_Representation += 65 + i;
		if (Binary_Representation[i] == '0') {
			Var_Representation += 39;
		}
	}

 }