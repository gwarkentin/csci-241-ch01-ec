/*-----------------------------------------------------------------------------------------
Student: Gabriel Warkentin
ID: 01738084
Class: CSCI 241
Instructor: Ding
Assignment: Ch01 Extra Credit, Twos_Complement_with_Hexadecimal
Due Date: 2/5/2020

Description:
This program converts a user defined 4-digit Hexadecimal to its Hexidecimal Two's Complement
-----------------------------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctype.h>
#include<cstring>

// ============================================================================
// Function:	TwosComplement
// Description: This function converts a Hexadecimal to its Two's Complement
//
// Parameter:   s [IN] - a C-string with a 4-digit Hexadecimal received
//              s2 [out] - a C-string with a 4-digit of s two's complement
// Return:      None
// ============================================================================
void TwosComplement(char* s, char* s2) {
	int i = 3;
	int carry = 1; //first digit on right always starts with a "carry", for Ones Complement this would just be 0.
	int value = 0;
	s2[4] = '\0';

	while (i >= 0) {
		s[i] = toupper(s[i]);

		//convert hex digit to value
		if (s[i] >= '0' && s[i] <= '9') {
			value = s[i] - '0';
		}
		else if (s[i] >= 'A' && s[i] <= 'F') {
			value = s[i] + 10 - 'A';
		}
		else {
			//catch out of bounds character values and leave loop.
			strcpy(s2, "Err.");
			return;
		}

		//invert value and add carry
		value = 15 - value + carry;

		//propagate carry
		if (value > 15) {
			value = value - 16;
			carry = 1;
		}
		else {
			carry = 0;
		}

		//convert back to hex
		if (value >= 10) {
			s2[i] = value - 10 + 'A';
		}
		else {
			s2[i] = value + '0';
		}
			
		i--;
	}
	return;
}

int main() {

	char cont = 'y';

	while (cont == 'y') {
		char istring[5];
		char ostring[5];

		std::cout << "Please Enter 4-digit Hexadecimal integer (e.g., A1B2): ";
		std::cin >> istring;
		TwosComplement(istring, ostring);
		
		std::cout << "Two's Complement of Hex " << istring << " is " << ostring << "\n";
		std::cout << "Try again ? (y / n) ";
		std::cin >> cont;
		std::cout << "\n";
	}

	return 0;
}