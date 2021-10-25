#pragma once

#ifndef number_h
#define number_h


#endif

#define MAXSIZE 30

namespace Prog3 {

    struct AdditionalCodeValue {
        char Additional[MAXSIZE];
    };
    int CountDigits(long i);

    class Number {
    private:
        char *value;
        int SIZE_OF_ARRAY;
        


    public:
        // Constructors
        Number(); // empty const
        Number(long number); // Const by long
        Number(char* ByChar);
        Number(const Number&);

        // Setters
        Number& SetByLong(long ByLong);
        Number& SetByChar(char* ByChar);

        // Getters
        const char *GetChar(); 
        int GetSizeOfArray();

        // Methods
        AdditionalCodeValue AdditionalCode();
        int Addition(long operatnum);
        int Multiplication();

        Number & operator +(const Number &r);
        Number& operator =(const Number& r);
        AdditionalCodeValue & operator ~();

        // Destructor
        ~Number() {
            std::cout << "Destructor called for Number" << std::endl;
            delete[] value;
        }

    };

}


#include "Number.cpp"