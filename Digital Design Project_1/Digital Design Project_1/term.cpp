#include "term.h"
// this function initialize the term's variable representation and Binary Representation using its number and the number of the 
// variables
void term::Initialize() {
	Binary_Representation = "";
	long temp = number;

	while (temp > 0) {
		Binary_Representation = to_string(temp % 2) + Binary_Representation;
		temp = temp / 2;
	}
	if (Binary_Representation.size() < var_numbers) {
		int x = Binary_Representation.size();
		for (int i = 0; i < var_numbers - x; i++) {
			Binary_Representation = '0' + Binary_Representation;
		}
	}
	boolean_expression();
	count_ones();
}
// This function transforms the binary representation of the term to a boolean expression

void term::boolean_expression() {
	Var_Representation = "";
	for (int i = 0; i < Binary_Representation.length(); i++) {
		if (Binary_Representation[i] == '-') continue;
		Var_Representation += 65 + i;
		if (Binary_Representation[i] == '0') {
			Var_Representation += 39;
		}
	}
}
// this function count the number of ones in the term
void term::count_ones() {
	for (int i = 0; i < var_numbers; i++) {
		if (Binary_Representation[i] == '1') {
			ones++;
		}
	}
}
// this function calculates the logic distance between two terms
pair<int, int> term::calc_distance(term const& another){
	int distance= 0;
	pair<int, int> res;
	for(int i = 0; i < var_numbers; i++){
		if(Binary_Representation[i] != another.Binary_Representation[i]){
			if (distance == 0)res.second = i;
			distance ++;
		}
	}
	res.first = distance;
	return res;
}

term term::operator+(term const& another)
{
	term sum;
	sum = *this;
	sum.covered_minterms.insert(sum.covered_minterms.end(), another.covered_minterms.begin(), another.covered_minterms.end());
	sum.covered_dont_cares.insert(sum.covered_dont_cares.end(), another.covered_dont_cares.begin(), another.covered_dont_cares.end());

	sum.Binary_Representation[this->calc_distance(another).second] = '-';
	sum.boolean_expression();
	return sum;
}