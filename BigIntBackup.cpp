//
//  BigInt.cpp
//  Daily 7
//
//  Created by Ojas Mehta on 12/9/17.
//  Copyright © 2017 Ojas Mehta. All rights reserved.
//

#include "BigInt.hpp"
#include <iostream>
using namespace std;

bool isNum(char x);
bool isSign(char x);
int smallerstr(string str1, string str2);
BigInt::BigInt()
{
    data = "0";
    isNegative = false;
}

BigInt::BigInt(int x)
{
    data = to_string(x);
    if (x < 0)
        isNegative = true;
    else
        isNegative = false;
}

BigInt::BigInt(string x)
{
    string my_new_str,temp = "";
    int i = 0;
    int j = 0;
    
    while(isSign(x[i]) == false && isNum(x[i]) == false)
    {
        i++;
    }
    while (isSign(x[i]) == true || isNum(x[i]) == true)
    {
        temp+= x[i];
        i++;
    }
    
    if(isSign(temp[j]) && isSign(temp[j+1]))
    {
        cout << "Tried to construct an invalid BigInt from string:" << x <<endl;
        cout << "exiting!"<<endl;
        exit(1);
    }
    else if(temp[j] == '-')
    {
        isNegative = true;
        j++;
    }
    else
    {
        isNegative = false;
    }
    
    while(isnumber(temp[j]) == true)
    {
        data+=temp[j];
        j++;
    }
}
bool isNum(char x)
{
    int val = x - '0';
    for(int i = 0; i <= 10; i++)
    {
        if (val == i)
            return true;
    }
    return false;
}

bool isSign(char x)
{
    if (x == '+' || x == '-')
        return true;
    
    return false;
}
ostream& operator<<(ostream& out, const BigInt& right)
{
    if(right.isNegative == true)
    {
        out << "-" << right.data;
    }
    else
    {
        out << right.data;
    }
    return out;
}
BigInt& operator+(const BigInt& left, const BigInt& right)
{
    int leftLength = left.data.length();
    int rightLength = right.data.length();
    int longestStrLength = 0;
    string leftData = left.data;
    string rightData = right.data;
    string newStr = "";
    int newStrLength = 0;;
    int l = 0;
    int r = 0;
    int sum = 0;
    BigInt my_new_Big_Int("");
    int carry = 0;
    string temp = "";
    
    if (left.isNegative == 1 && right.isNegative == 0)
    {
        BigInt new_left(left.data);
        //  new_left.isNegative = 1;
	// modified by michael. please delete after bug is fixed.
        //BigInt c(right-new_left);
	BigInt c = BigInt(right-new_left);
        return c;
    }
    else if(left.isNegative == 0 && right.isNegative == 1)
    {
        BigInt new_right(right.data);
        BigInt c(left-new_right);
        return c;
    }
    else
    {
        if(leftLength < rightLength)
        {
            string newLeftStr;
            for(int i = 0; i < rightLength-leftLength;i++)
            {
                newLeftStr += '0';
            }
            newLeftStr += left.data;
            leftData = newLeftStr;
            longestStrLength = rightLength;
        }
        else if(leftLength > rightLength)
        {
            string newRightStr;
            for(int i = 0;i < leftLength-rightLength;i++)
            {
                newRightStr += '0';
            }
            newRightStr += right.data;
            rightData = newRightStr;
            longestStrLength = leftLength;
        }
        else
        {
            longestStrLength = rightLength;
        }
        
        if(longestStrLength > 1)
        {
            l = leftData[1] - '0';
            r = rightData[1] - '0';
        }
        else
        {
            l = leftData[0] - '0';
            r = rightData[0] - '0';
        }
        
        if(left.isNegative == right.isNegative)
        {
            if((l+r) > 9)
            {
                newStrLength = longestStrLength+1;
            }
            else
            {
                newStrLength = longestStrLength;
            }
            
            for(int i = longestStrLength-1; i >= 0;i--)
            {
                sum = (leftData[i] - '0') + (rightData[i] - '0');
                
                if (carry == 1)
                {
                    sum += carry;
                    carry = 0;
                }
                
                if (sum > 9)
                {
                    sum = sum % 10;
                    carry++;
                }
                temp = (sum + '0');
                reverse(temp.begin(),temp.end());
                
                newStr += temp;
            }
            if( carry > 0)
                newStr += (carry + '0');
            reverse(newStr.begin(),newStr.end());
            my_new_Big_Int.data = newStr;
            my_new_Big_Int.isNegative = 0;
        }
        if(left.isNegative == 1 && right.isNegative == 1)
        {
            my_new_Big_Int.isNegative = 1;
        }
        return my_new_Big_Int;
    }
}

BigInt& operator-(const BigInt& left, const BigInt& right)
{
    int topLength = 0;
    int bottomLength = 0;
    int longerStrLength = 0;
    string topData;
    string bottomData;
    string newStr = "";
    int newStrLength = 0;;
    int t = 0;
    int b = 0;
    int difference = 0;
    BigInt my_new_Big_Int("");
    int borrow = 0;
    string temp = "";
    int shorterStr = smallerstr(left.data,right.data);
    bool sign = true;
    
    if (left.isNegative == 1 && right.isNegative == 0)
    {
        BigInt newRight(right.data);
        newRight.isNegative = 1;
        BigInt c(left+newRight);
        return c;
    }
    else if(left.isNegative == 0 && right.isNegative == 1)
    {
        BigInt new_right(right.data);
        BigInt c(left+new_right);
        return c;
    }
    else
    {
        if(shorterStr == 1)
        {
            topLength = right.data.length();
            bottomLength = left.data.length();
            topData = right.data;
            sign = false;
            longerStrLength = right.data.length();
            string newLeftStr = "";
            for(int i = 0; i < topLength-bottomLength;i++)
            {
                newLeftStr += '0';
            }
            newLeftStr += left.data;
            bottomData = newLeftStr;
        }
        else
        {
            topLength = left.data.length();
            bottomLength = right.data.length();
            topData = left.data;
            //  bottomData = right.data;
            longerStrLength = left.data.length();
            string newRightStr = "";
            for(int i = 0; i < topLength-bottomLength;i++)
            {
                newRightStr += '0';
            }
            newRightStr += right.data;
            bottomData = newRightStr;
        }
        if(longerStrLength > 1)
        {
            t = topData[1] - '0';
            b = bottomData[1] - '0';
        }
        else
        {
            t = topData[0] - '0';
            b = bottomData[0] - '0';
        }
        if((t-b) < 0)
        {
            newStrLength = longerStrLength-1;
        }
        else
        {
            newStrLength = longerStrLength;
        }
        
        for(int i = longerStrLength-1;i >= 0; i--)
        {
            difference = ((topData[i] - '0')) - (bottomData[i] - '0') + borrow;
            if (difference < 0)
            {
                //  borrow--;
                difference += 10;
                borrow = -1;
            }
            else
            {
                borrow = 0;
            }
            temp = (difference + '0');
            reverse(temp.begin(),temp.end());
            newStr += temp;
        }
        if( borrow < 0)
            newStr += (borrow + '0');
        reverse(newStr.begin(),newStr.end());
        my_new_Big_Int.data = newStr;
        if(sign == true)
        {
            sign = left.isNegative;
        }
        else
        {
            sign = !left.isNegative;
        }
        my_new_Big_Int.isNegative = sign;
        return my_new_Big_Int;
    }
}
bool operator<(const BigInt& left, const BigInt& right)
{
    int leftLength = left.data.length();
    int rightLength = right.data.length();
    string leftData = left.data;
    string rightData = right.data;
    
    if (left.isNegative == 1 && right.isNegative == 0)
    {
        return true;
    }
    else if (left.isNegative == 0 && right.isNegative == 1)
    {
        return false;
    }
    else if ( left.isNegative == 0 && right.isNegative == 0)
    {
        if (leftLength < rightLength)
        {
            return true;
        }
        else if (rightLength < leftLength)
        {
            return false;
        }
        else
        {
            for(int i = 0; i < leftLength; i++)
            {
                if (leftData[i] < rightData[i])
                {
                    return true;
                }
            }
            return false;
        }
    }
    else
    {
        if (leftLength < rightLength)
        {
            return false;
        }
        else if (rightLength < leftLength)
        {
            return true;
        }
        else
        {
            for(int i = 0; i < leftLength; i++)
            {
                if (leftData[i] < rightData[i])
                {
                    return false;
                }
            }
            return false;
        }
    }
}
int smallerstr(string str1, string str2)
{
    int str1Length = str1.length();
    int str2Length = str2.length();
    
    if (str1Length < str2Length)
    {
        return 1;
    }
    else if (str1Length > str2Length)
    {
        return 2;
    }
    
    for(int i = 0; i < str1Length; i++)
    {
        if(str1[i] < str2[i])
        {
            return 1;
        }
    }
    return 2;
}
bool operator==(const BigInt& left, const BigInt& right)
{
    int leftLength = left.data.length();
    int rightLength = right.data.length();
    
    if ((left.isNegative != right.isNegative) || (leftLength != rightLength))
    {
        return false;
    }
    else
    {
        for(int i = rightLength; i > 0; i--)
        {
            if(right.data[i] != left.data[i])
            {
                return false;
            }
        }
    }
    return true;
}
bool operator>(const BigInt& left, const BigInt& right)
{
    if((left < right) || left == right)
    {
        return false;
    }
    return true;
}

BigInt& operator*(const BigInt& left, const BigInt& right)
{
    string leftStr = left.data;
    string rightStr = right.data;
    int left_num = leftStr.size();
    int right_num = rightStr.size();
    BigInt returnZero("0");
    BigInt finalBigInt("");
    string reverseOutput;
    if (left_num == 0 || right_num == 0)
    {
        return returnZero;
    }
    
    int left_num_counter = 0;
    int right_num_counter = 0;
    for (int i=left_num-1; i>=0; i--)
    {
        int carry = 0;
        int left_num = leftStr[i] - '0';
        right_num_counter = 0;
        for (int j=right_num-1; j>=0; j--)
        {
            int right_num = rightStr[j] - '0';
            int sum = left_num*right_num + reverseOutput[left_num_counter + right_num_counter] + carry;
            carry = sum/10;
            reverseOutput += (sum % 10) +'0';
            right_num_counter++;
        }
        if (carry > 0)
        {
            reverseOutput += (carry + '0');
        }
        left_num_counter++;
    }
    int i = reverseOutput.size() - 1;
    while (i>=0 && reverseOutput[i] == 0)
    {
        i--;
    }
    if (i == -1)
    {
        return returnZero;
    }
    string finalStr = "";
    while (i >= 0)
    {
        finalStr += reverseOutput[i];
        i--;
    }
    finalBigInt.data = finalStr;
    finalBigInt.isNegative = false;
   // BigInt returnObj(s);
    return (finalBigInt);
    //return idk;
}
