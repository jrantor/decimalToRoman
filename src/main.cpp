//============================================================================
// Name        : DecimanToRoman.cpp
// Author      : jrantor
// Version     : 0.0
// Copyright   : CC
// Description : Getting equivalent Roman numeral of a decimal number and vice-versa.
//============================================================================

#include <iostream>
#include<math.h>
#include "dr.h"
using namespace std;

int main() {
	int result2, decimal;
	string numeral,result1,temp;
	int check;

	cout << "Select From Options. Write 1 or 2 and hit enter: " << endl;
	cout << "1. Decimal to Roman" << endl;
	cout << "2. Roman to Decimal" << endl;
	cin >> check;


	switch(check){

	case 1:
		cout << "Enter a decimal number: "<< endl;
		cin >> decimal;
		if(decimal > 0){
		  result1 = dec_to_roman(decimal);
		  cout << result1 << endl;
		}
		else {cout << "Don't enter zero or negative integers." << endl;}
		break;
	case 2:
		cout << "Enter a numeral: " << endl;
		cin >> numeral;
		 for (size_t i=0; i<numeral.length(); i++){
			 if(numeral[i] == 'I' || numeral[i] == 'V' || numeral[i] == 'X' || numeral[i] == 'L' || numeral[i] == 'C' || numeral[i] == 'D' || numeral[i] == 'M'){
				 temp = temp + numeral[i];
			 }
		 }

		 if(temp.length() != numeral.length()){
			 cout << "You just entered an invalid numeral.";
		 }
		 else{
			 result2 = roman_to_decimal(numeral);
			 cout << result2;
		 }

		break;

	default:
		cout << "Run again and choose a correct option." << endl;
		break;

	}

   return EXIT_SUCCESS;
}

