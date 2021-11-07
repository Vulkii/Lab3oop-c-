#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <stdio.h>
#include <strstream>
#include <cstdlib>
#include "Number.h"

namespace Prog3 {


	//Constructors
	Number::Number(){ // empty Const
		{ 
			SIZE_OF_ARRAY = 1;
			value = new char[SIZE_OF_ARRAY];
			for (int i = 0; i < SIZE_OF_ARRAY - 1; i++) {
				value[i] = '0';
			}
		};
	}

	Number::Number(long number) { // const by Long
			int negative = 0;
			int size = 0;
			if (number < 0) {
				number = number * (-1);
				negative = 1;
			}
			if (number >= ((pow(2, MAXSIZE) / 2) - 1)) {
				throw std::logic_error("Too big number!");
			}
			for (int i = 0; i < MAXSIZE - 1; i++) {
				if (negative == 0) {
					if (number <= ((pow(2, i) / 2) - 1)) {
						size = i;
						break;
					}
				}
				if (negative == 1) {
					if (number <= ((pow(2, i) / 2))) {
						size = i;
						break;
					}
				}
			}
			value = new char[size + 1];
			SIZE_OF_ARRAY = size;
			if (negative == 1) {
				value[0] = '1';
			}
			else value[0] = '0';
			for (int i = size - 1; i > 0; i--) {
				value[i] = (number % 2) + '0';
				number = number / 2;
			}
			value[size] = '\0';
		
	}

	Number::Number(char* ByChar) { // const by Char
		int len = strlen(ByChar);
		int i = 1;
		int size = 0;
		int negative = 0;
		int number = 0;
		if (ByChar[0] == '-') {
			negative = 1;
		}
		else {
			negative = 0;
		}
		for (int j = len; j > 1; j--) {
			number = number + (i * (ByChar[j - 1] - '0'));
			size = size + 1;
			i = i * 10;
		}
		if (number >= ((pow(2, MAXSIZE) / 2) - 1)) {
			throw std::logic_error("Too big number!");
		}
		for (int i = 0; i < MAXSIZE - 1; i++) {
			if (negative == 0) {
				if (number <= ((pow(2, i) / 2) - 1)) {
					size = i;
					break;
				}
			}
			if (negative == 1) {
				if (number <= ((pow(2, i) / 2))) {
					size = i;
					break;
				}
			}
		}
		value = new char[size + 1];
		SIZE_OF_ARRAY = size;
		if (ByChar[0] == '-') {
			value[0] = '1';
		}
		else {
			value[0] = '0';
		}
		for (int i = size - 1; i > 0; i--) {
			value[i] = (number % 2) + '0';
			number = number / 2;
		}
		value[size] = '\0';
	}

	Number::Number(const Number& right) : SIZE_OF_ARRAY(right.SIZE_OF_ARRAY)
	{
		value = new char[SIZE_OF_ARRAY+1];
		for (int i = SIZE_OF_ARRAY-1; i > -1; i--) {
			value[i] = right.value[i];
		}
		value[SIZE_OF_ARRAY] = '\0';
	}

	Number::Number(Number&& num) : SIZE_OF_ARRAY(num.SIZE_OF_ARRAY) {
		num.value = nullptr;
	}


	// Setters
	Number& Number::SetByLong(long ByLong) { 
		int negative = 0;
		int size = 0;
		if (ByLong < 0) {
			ByLong = ByLong * (-1);
			negative = 1;
		}
		if (ByLong >= ((pow(2, MAXSIZE) / 2) - 1)) {
			throw std::logic_error("Too big number!");
		}
		for (int i = 0; i < MAXSIZE - 1; i++) {
			if (negative == 0) {
				if (ByLong <= ((pow(2, i) / 2) - 1)) {
					size = i;
					break;
				}
			}
			if (negative == 1) {
				if (ByLong <= ((pow(2, i) / 2))) {
					size = i;
					break;
				}
			}
		}

		value = new char[size + 1];
		SIZE_OF_ARRAY = size;
		if (negative == 1) {
			value[0] = '1';
		}
		else value[0] = '0';
		for (int i = size - 1; i > 0; i--) {
			value[i] = (ByLong % 2) + '0';
			ByLong = ByLong / 2;
		}
		value[size] = '\0';
		return *this;
	}


	Number& Number::SetByChar(char *ByChar) { 
		int len = strlen(ByChar);
		int i = 1;
		int checker_of_digit =0;
		int size = 0;
		int negative = 0;
		int number = 0;

		if (ByChar[0] == '-') { 
			negative = 1;
			checker_of_digit = 1;
		}
		else {
			negative = 0;
			checker_of_digit = 0;
		}
		for (checker_of_digit; checker_of_digit < len; checker_of_digit++) {
			if (!isdigit(ByChar[checker_of_digit])) {
				throw std::logic_error("Incorrect string!");
			}
		}
		for (int j = len; j > negative; j--) {
			number = number + (i * (ByChar[j - 1] - '0'));
			size = size + 1;
			i = i * 10;
		}
		if (number >= ((pow(2, MAXSIZE) / 2) - 1)) {
			throw std::logic_error("Too big number!");
		}
		std::cout << number;
		for (int i = 0; i < MAXSIZE - 1; i++) {
			if (negative == 0) {
				if (number <= ((pow(2, i) / 2) - 1)) {
					size = i;
					break;
				}
			}
			if (negative == 1) {
				if (number <= ((pow(2, i) / 2))) {
					size = i;
					break;
				}
			}
		}
		value = new char[size + 1];
		SIZE_OF_ARRAY = size;
		if (ByChar[0] == '-') {
			value[0] = '1';
		}
		else {
			value[0] = '0';
		}
		for (int i = size - 1; i > 0; i--) {
			value[i] = (number % 2) + '0';
			number = number / 2;
		}
		value[size] = '\0';
		return *this;
	}

	const char *Number::GetChar() {
		int result = 0;
		int degree_of_two = 0;
			for (int i = SIZE_OF_ARRAY-1; i > 0; i--) {
				result = result + ((value[i] - '0') * pow(2, degree_of_two));
				degree_of_two++;
			}
			if ((result == 0) && (value[0] == '1')) {
				result = ((value[0] - '0') * pow(2, degree_of_two));
			}
			if (value[0] == '1')
				result = result * (-1);
		std::cout << "Straight code for " << result << " is" << std::endl;
		return value;
	}

	int Number::GetSizeOfArray() {
		return SIZE_OF_ARRAY;
	}

	AdditionalCodeValue MakeAdditionalFromStraight(const char* array, struct AdditionalCodeValue Code) {

		if (array[0] == '0') {
			for (int i = 0; i < MAXSIZE-1; i++) {
				Code.Additional[i] = array[i];
			}
		}
		if (array[0] == '1') {
			Code.Additional[0] = '1';
			for (int i = 1; i < MAXSIZE-1; i++) {
				if (array[i] == '0')
					Code.Additional[i] = '1';
				if (array[i] == '1') {
					Code.Additional[i] = '0';
				}
			}
			for (int i = MAXSIZE-1; i > 0; i--) {
				if (Code.Additional[i] == '0') { 
					Code.Additional[i] = '1';
					break;
				}
				if (Code.Additional[i] == '1') {
					Code.Additional[i] = '0';
				}
			}
		}
		Code.Additional[MAXSIZE-1] = '\0';
		return Code;
	}


	 AdditionalCodeValue Number::AdditionalCode() {
		struct AdditionalCodeValue Code = {};
		int result = 0;
		int degree_of_two = 0;
		Code = MakeAdditionalFromStraight(value, Code);
		if (Code.Additional[0] != '1') {
			for (int i = SIZE_OF_ARRAY-1; i > 0; i--) {
				result = result + ((Code.Additional[i] - '0') * pow(2, degree_of_two));
				degree_of_two++;
			}
		}
		else if (Code.Additional[0] == '1') {
			result = -1;
			for (int i = SIZE_OF_ARRAY-1; i > 0; i--) {
				if (Code.Additional[i] == '0') {
					result = result - (1 * pow(2, degree_of_two));
				}
				degree_of_two++;
			}
		}
		std::cout <<"Additional code for "<< result << " is "<<std::endl;
		return Code;
	}

	int CountDigits(long i) {
		int k = 0; // Number of digits
		if (i < 0)
			i = i * -1;
		while (i > 0){
			i = i / 10;
			k = k++;
		}
		return k;
	}

	int Number::Addition(long operatnum) { // Sum
		struct AdditionalCodeValue MyCode = {};
		struct AdditionalCodeValue OperationCode = {};
		struct AdditionalCodeValue SumCode = {};
		char* helper;
		char* code_of_arr;
		char* sum;
		int result = 0;
		int degree_of_two = 0;
		int negative = 0;
		int size = 0;
		int real_size = 0;
		int k = 0; 
		if (operatnum < 0) {
			operatnum = operatnum * (-1);
			negative = 1;
		}
		if (operatnum >= ((pow(2, MAXSIZE) / 2) - 1)) {
			throw std::logic_error("Too big number!");
		}
		for (int i = 0; i < MAXSIZE - 1; i++) {
			if (negative == 0) {
				if (operatnum <= ((pow(2, i) / 2) - 1)) {
					size = i;
					break;
				}
			}
			if (negative == 1) {
				if (operatnum <= ((pow(2, i) / 2))) {
					size = i;
					break;
				}
			}
		}
		if (SIZE_OF_ARRAY > size)
			real_size = SIZE_OF_ARRAY;
		else
			real_size = size;

		helper = new char[real_size];
		if (negative == 1) {
			helper[0] = '1';
		}
		else helper[0] = '0';
		for (int i = real_size - 1; i > 0; i--) {
			helper[i] = (operatnum % 2) + '0';
			operatnum = operatnum / 2;
		}
		helper[real_size] = '\0';
		negative = 0;
		for (int i = SIZE_OF_ARRAY - 1; i > 0; i--) {
			result = result + ((value[i] - '0') * pow(2, degree_of_two));
			degree_of_two++;
		}
		if ((result == 0) && (value[0] == '1')) {
			result = ((value[0] - '0') * pow(2, degree_of_two));
		}
		if (value[0] == '1') {
			result = result * (-1);
			negative = 1;
		}


		code_of_arr = new char[real_size];
		if (negative == 1) {
			code_of_arr[0] = '1';
			result = result * (-1);
		}
		else code_of_arr[0] = '0';
		for (int i = real_size - 1; i > 0; i--) {
			code_of_arr[i] = (result % 2) + '0';
			result = result / 2;
		}
		code_of_arr[real_size] = '\0';
		sum = new char[real_size];
		for (int i = 0; i < real_size; i++) {
			sum[i] = '0';
		}
		sum[real_size] = '\0';

		MyCode = MakeAdditionalFromStraight(code_of_arr, MyCode);
		OperationCode = MakeAdditionalFromStraight(helper, OperationCode);
		SumCode = MakeAdditionalFromStraight(sum, SumCode);

		for (int i = real_size - 1; i > -1; i--) {
			if (MyCode.Additional[i] == '0' && OperationCode.Additional[i] == '0' && k == 0) {
				SumCode.Additional[i] = '0';
			}
			else if (MyCode.Additional[i] == '0' && OperationCode.Additional[i] == '0' && k != 0) {
				SumCode.Additional[i] = '1';
				k--;
			}
			else if (MyCode.Additional[i] == '1' && OperationCode.Additional[i] == '1' && k == 0) {
				SumCode.Additional[i] = '0';
				k++;
			}
			else if (MyCode.Additional[i] == '1' && OperationCode.Additional[i] == '1' && k != 0) {
				SumCode.Additional[i] = '1';
			}
			else if (MyCode.Additional[i] == '1' && OperationCode.Additional[i] == '0' && k == 0) {
				SumCode.Additional[i] = '1';
			}
			else if (MyCode.Additional[i] == '1' && OperationCode.Additional[i] == '0' && k != 0) {
				SumCode.Additional[i] = '0';
			}
			else if (MyCode.Additional[i] == '0' && OperationCode.Additional[i] == '1' && k == 0) {
				SumCode.Additional[i] = '1';
			}
			else if (MyCode.Additional[i] == '1' && OperationCode.Additional[i] == '0' && k != 0) {
				SumCode.Additional[i] = '0';
			}
		}
		result = 0;
		degree_of_two = 0;
		if (SumCode.Additional[0] != '1') {
			for (int i = real_size-1; i > 0; i--) {
				result = result + ((SumCode.Additional[i] - '0') * pow(2, degree_of_two));
				degree_of_two++;
			}
		}
		else if (SumCode.Additional[0] == '1') {
			result = -1;
			for (int i = real_size-1 ; i > 0; i--) {
				if (SumCode.Additional[i] == '0') {
					result = result - (1 * pow(2, degree_of_two));
				}
				degree_of_two++;
			}
		}
		return result;
	}


	int Number::Multiplication() {
		char helper[MAXSIZE];
		char superhelper[MAXSIZE];
		char res[MAXSIZE];
		char code_of_arr[MAXSIZE];
		int result = 0;
		int degree_of_two = 0;
		int negative = 0;
		int k = 0;
		for (int i = 0; i < MAXSIZE-1; i++) {
			res[i] = '0';
			helper[i] = '0';
			superhelper[i] = '0';
			code_of_arr[i] = '0';
		}
		res[MAXSIZE-1] = '\0';
		helper[MAXSIZE-1] = '\0';
		superhelper[MAXSIZE-1] = '\0';
		



		for (int i = SIZE_OF_ARRAY - 1; i > 0; i--) {
			result = result + ((value[i] - '0') * pow(2, degree_of_two));
			degree_of_two++;
		}
		if ((result == 0) && (value[0] == '1')) {
			result = ((value[0] - '0') * pow(2, degree_of_two));
		}
		if (value[0] == '1') {
			result = result * (-1);
			negative = 1;
		}
		if (negative == 1) {
			value[0] = '1';
			result = result * (-1);
		}
		else value[0] = '0';
		for (int i = MAXSIZE - 2; i > 0; i--) {
			code_of_arr[i] = (result % 2) + '0';
			result = result / 2;
		}
		code_of_arr[MAXSIZE-1] = '\0';





		for (int i = MAXSIZE-2; i > 3; i--) {
			helper[i - 1] = code_of_arr[i];
			superhelper[i - 3] = code_of_arr[i];
		}
		for (int i = 0; i < MAXSIZE-1; i++) {
			res[i] = '0';
		}

		for (int i = MAXSIZE; i > -1; i--) {
			if (helper[i] == '0' && superhelper[i] == '0' && k == 0) {
				res[i] = '0';
			}
			else if (helper[i] == '0' && superhelper[i] == '0' && k != 0) {
				res[i] = '1';
				k--;
			}
			else if (helper[i] == '1' && superhelper[i] == '1' && k == 0) {
				res[i] = '0';
				k++;
			}
			else if (helper[i] == '1' && superhelper[i] == '1' && k != 0) {
				res[i] = '1';
			}
			else if (helper[i] == '1' && superhelper[i] == '0' && k == 0) {
				res[i] = '1';
			}
			else if (helper[i] == '1' && superhelper[i] == '0' && k != 0) {
				res[i] = '0';
			}
			else if (helper[i] == '0' && superhelper[i] == '1' && k == 0) {
				res[i] = '1';
			}
			else if (helper[i] == '1' && superhelper[i] == '0' && k != 0) {
				res[i] = '0';
			}
		}
		result = 0;
		degree_of_two = 0;
		for (int i = MAXSIZE-2; i > 0; i--) {
			result = result + ((res[i] - '0') * pow(2, degree_of_two));
			degree_of_two++;
		}
		if (value[0] == '1')
			result = result * (-1);
		return result;
	}

	Number & Number::operator +(const Number &r){
		long result = 0;
		int res = 0;
		int degree_of_two = 0;
		for (int i = r.SIZE_OF_ARRAY-1; i > 0; i--) {
			result = result + ((r.value[i] - '0') * pow(2, degree_of_two));
			degree_of_two++;
		}
		if (r.value[0] == '1')
			result = result * (-1);
		result=this->Addition(result);
		this->SetByLong(result);
		return *this;
	}

	AdditionalCodeValue & Number::operator ~() {
		struct AdditionalCodeValue Code = {};
		int result = 0;
		int degree_of_two = 0;
		Code = MakeAdditionalFromStraight(this->value, Code);
		if (Code.Additional[0] != '1') {
			for (int i = this->SIZE_OF_ARRAY - 1; i > 0; i--) {
				result = result + ((Code.Additional[i] - '0') * pow(2, degree_of_two));
				degree_of_two++;
			}
		}
		else if (Code.Additional[0] == '1') {
			result = -1;
			for (int i = this->SIZE_OF_ARRAY - 1; i > 0; i--) {
				if (Code.Additional[i] == '0') {
					result = result - (1 * pow(2, degree_of_two));
				}
				degree_of_two++;
			}
		}
		std::cout << "Additional code for " << result << " is " << std::endl;
		return Code;

	}

	Number& Number::operator =(const Number& r) {
		delete[] this->value;
		this->value = new char[r.SIZE_OF_ARRAY+1];
		this->SIZE_OF_ARRAY = r.SIZE_OF_ARRAY;
		for (int i = r.SIZE_OF_ARRAY; i > -2; i--) {
			this->value[i]=r.value[i];
		}
		this->value[SIZE_OF_ARRAY] = '\0';
		return *this;
	}
}

