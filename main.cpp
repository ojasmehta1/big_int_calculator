//
//  main.cpp
//  Daily 7
//
//  Created by Ojas Mehta on 10/23/17.
//  Copyright © 2017 Ojas Mehta. All rights reserved.
//
#include <iostream>
#include "BigInt.hpp"
using namespace std;

int main()
{
    BigInt a("220");
    BigInt b("2");
    
  //  removeLeadingZeros(a);
  //  cout << a<< endl;
    cout << a << "/"<< b << endl << " = " << (a/b) << endl;
    
   // cout<< "The return value is:" << recursiveDivide(BigInt("99"),BigInt("33"))<<endl;
    
    
    
    
    
    /*
    for(int i = 1; i < 100;i++)
    {
        for(int j = 10; j > -200; j--)
        {
            cout<< j <<" * " << i << " = " << (BigInt(j) - BigInt(i)) << endl;
        }
    }
   // cout << "1.Expecting 1, got: " << (BigInt("3") < BigInt("9")) << endl;
    
     cout << "1.Expecting 0, got: " << (BigInt("0") < BigInt("0")) << endl;
     cout << "2.Expecting 0, got: " << (BigInt("-1") < BigInt("-1")) << endl;
     cout << "3.Expecting 1, got: " << (BigInt("-1") < BigInt("1")) << endl;
     cout << "4.Expecting 0, got: " << (BigInt("1") < BigInt("-1")) << endl;
     cout << "5.Expecting 0, got: " << (BigInt("1") < BigInt("1")) << endl;
     cout << "6.Expecting 0, got: " << (BigInt("-30") < BigInt("-300")) << endl;
     cout << "7.Expecting 1, got: " << (BigInt("-300") < BigInt("-30")) << endl;
     cout << "8.Expecting 1, got: " << (BigInt("30") < BigInt("300")) << endl;
     cout << "9.Expecting 0, got: " << (BigInt("300") < BigInt("30")) << endl;
     cout << "10.Expecting 1, got: " << (BigInt("-30") < BigInt("300")) << endl;
     cout << "11.Expecting 1, got: " << (BigInt("-300") < BigInt("30")) << endl;
     cout << "12.Expecting 0, got: " << (BigInt("30") < BigInt("-300")) << endl;
     cout << "13.Expecting 0, got: " << (BigInt("300") < BigInt("-30")) << endl;
     a = BigInt("1000");
     b = BigInt("999");
     cout << a << "-" << b << endl << "= " << a - b << endl;
    // a = BigInt("99999999999999999999999999999999999999999999999999999999999999999999999999999999");
    // b = BigInt("1");
     
    // cout << " " << a << "+" << b << endl << "= " << a+b << endl;
     
     cout << "14.Expecting 1, got: " << (BigInt("-30") < BigInt("-1")) << endl;
     cout << "15.Expecting 0, got: " << (BigInt("30") < BigInt("-1")) << endl;
     cout << "16.Expecting 1, got: " << (BigInt("30") < BigInt("300")) << endl;
     cout << "17.Expecting 0, got: " << (BigInt("-30") < BigInt("-300")) << endl;
    cout << "17.Expecting 1, got: " << (BigInt("005") < BigInt("19")) << endl;
*/
     
    return 0;
}
