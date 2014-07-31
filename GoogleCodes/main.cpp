//
//  main.cpp
//  GoogleCodes
//
//  Created by Jeff Wang on 15/07/2014.
//  Copyright (c) 2014 Jeff. All rights reserved.
//

#include <iostream>
#include "chapter1.h"

int main(int argc, const char * argv[])
{
    // input: 3yWYfPLfplC3f5k
    std::string input1_1 = "3yWYfPLfplC3f5k";
    std::string input1_1_2 = "abcdefgABCDEFG";
    
    printf("result1: expect: 0, actually: %d. \n", checkUniqueString1(input1_1));
    printf("result2: expect: 0, actually: %d. \n", checkUniqueString2(input1_1));
    printf("result3: expect: 0, actually: %d. \n", checkUniqueString3(input1_1));
    printf("result4: expect: 1, actually: %d. \n", checkUniqueString1(input1_1_2));
    printf("result5: expect: 1, actually: %d. \n", checkUniqueString2(input1_1_2));
    printf("result6: expect: 1, actually: %d. \n", checkUniqueString3(input1_1_2));
    
    std::string input1_2 = "abcdefgGFEDCBA";
    reverse(input1_2);
    printf("result 1.2: expect: ABCDEFGgfedcba, actually: %s\n", input1_2.c_str());
    
    printf("result 1.3: %d\n", isPermutation("abcd", "dbac"));
    
    return 0;
}

