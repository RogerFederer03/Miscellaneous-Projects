//
//  Numeric_Limits.cpp
//  
//  Created by 罗铮 on 10/29/12.
//  Copyright (c) 2012 罗铮. All rights reserved.
//

// numeric_limits example
#include <iostream>
#include <limits>
using namespace std;

int main (int argc, const char * argv[]) {
    cout << boolalpha;
    
    cout << "Minimum value for int: " 
    	 << numeric_limits<int>::min() << endl;
    cout << "Maximum value for int: " 
    	 << numeric_limits<int>::max() << endl;
    cout << "int is signed: " 
    	 << numeric_limits<int>::is_signed << endl;
    cout << "Non-sign bits in int: " 
    	 << numeric_limits<int>::digits << endl;
    cout << "int has infinity: " 
    	 << numeric_limits<int>::has_infinity << endl;
    
    return 0;
}

