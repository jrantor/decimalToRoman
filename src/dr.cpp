/*
 * dr.cpp
 *
 *  Created on: Nov 18, 2020
 *      Author: jrantor
 */

#include <iostream>
using namespace std;
#include <math.h>
#include "dr.h"

int get_value(char roman){

	switch(roman){
	case 'I':
		return 1;
		break;

	case 'V':
		return 5;
		break;

	case 'X':
		return 10;
		break;

	case 'L':
		return 50;
		break;

	case 'C':
		return 100;
		break;

	case 'D':
		return 500;
		break;

	case 'M':
		return 1000;
		break;

	default:
		return -1;
		break;
	}
}

char get_roman(int number){

	switch(number){
	case 1:
		return 'I';
		break;
	case 5:
		return 'V';
		break;
	case 10:
		return 'X';
		break;
	case 50:
		return 'L';
		break;
	case 100:
		return 'C';
		break;
	case 500:
		return 'D';
		break;
	case 1000:
		return 'M';
		break;
	default:
		return 'Z';
		break;
	}
}

string str_repeat(string s, int n){
	string s1 = s;

	for(int i=1; i<n ;i++){
		s+=s1;
	}
	return s;
}

string dec_to_roman(int decimal){
	int offset = 1;
	string result, inc;
	while(decimal >= offset){
		offset *= 10;
	}
	offset /= 10;

 while(decimal) {
	int num = (int)decimal/offset;

	if(num <= 3 ){
		inc = get_roman(offset);
		result += str_repeat(inc,num);
	}

	else if( num == 4){
		result += get_roman(offset);
		result += get_roman(offset*5);
	}

	else if(num >= 5 && num <= 8){
		inc = get_roman(offset);
		result += get_roman(offset*5);
		if(num==5){
			result += "";
		}
		else{
			result += str_repeat(inc,(num-5));
		}
	}

	else if(num == 9){
		result += get_roman(offset);
		result += get_roman(offset*10);
	}

	decimal = floor(decimal % offset);
	offset /= 10;
 }

 if(result.find('Z') != string::npos) return "Couldn't resolve to any Roman numeral.";
 else return result;

}

int roman_to_decimal(string roman){
	int result = 0;

	for(size_t i = 0; i<roman.length(); i++){
		int s1 = get_value(roman[i]);

		if(i+1 < roman.length()){
			int s2 = get_value(roman[i+1]);

			if(s1 >= s2){
				result+=s1;
			}
			else{
				result+=s2;
				result-=s1;
				i++;
			}
		}

		else{
			result+=s1;
		}
	}

	return result;
}





