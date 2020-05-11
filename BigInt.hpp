//
//  Header.hpp
//  Daily 7
//
//  Created by Ojas Mehta on 11/6/17.
//  Copyright © 2017 Ojas Mehta. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <string>
class BigInt{
public:
    BigInt(); // Initializes the BigInt to zero.
    BigInt(int x); //Initializes the BigInt to have the same value as x
    explicit BigInt(std::string x);//Initializes the BigInt to have the value of the given string BUT
    //must check that the string is valid or exit(1) otherwise.
    friend std::ostream& operator<<(std::ostream& out, const BigInt& right);
    friend const BigInt operator+(const BigInt& left, const BigInt& right);
    friend const BigInt operator-(const BigInt& left, const BigInt& right);
    friend const BigInt operator*(const BigInt& left, const BigInt& right);
    friend const BigInt operator/(const BigInt& dividend, const BigInt& divisor);
    // I was provided an extension by Dr. Wilkes
    friend bool operator==(const BigInt& left, const BigInt& right);
    friend bool operator<(const BigInt& left, const BigInt& right);
    friend bool operator>(const BigInt& left, const BigInt& right);
    friend int divideExt(BigInt& dividend, const BigInt& divisor,int& counter);
    friend void removeLeadingZeros(BigInt& obj);
    
private:
    std::string data;
    bool isNegative;
};

#endif /* Header_hpp */
