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
    
    printf("result1: question 1.1 expect: 0, actually: %d. \n", checkUniqueString1(input1_1));
    printf("result2: question 1.1 expect: 0, actually: %d. \n", checkUniqueString2(input1_1));
    printf("result3: question 1.1 expect: 0, actually: %d. \n", checkUniqueString3(input1_1));
    printf("result4: question 1.1 expect: 1, actually: %d. \n", checkUniqueString1(input1_1_2));
    printf("result5: question 1.1 expect: 1, actually: %d. \n", checkUniqueString2(input1_1_2));
    printf("result6: question 1.1 expect: 1, actually: %d. \n", checkUniqueString3(input1_1_2));
    
    std::string input1_2 = "abcdefgGFEDCBA";
    reverse(input1_2);
    printf("result7: question 1.2 expect: ABCDEFGgfedcba, actually: %s\n", input1_2.c_str());
    
    std::string input1_3_1 = "abcdefgGFEDCBA";
    std::string input1_3_2 = "ABCDEFGgfedcba";
    printf("result8: question 1.3 expect: 1, actually: %d\n", isPermutation1(input1_3_1, input1_3_2));
    printf("result9: question 1.3 expect: 1, actually: %d\n", isPermutation2(input1_3_1, input1_3_2));
    
    char input1_4[] = "Mr John Smith    ";
    replaceSpace(input1_4, 17);
    printf("result10: question 1.4 expect: Mr%sJohn%sSmith, actually: %s\n", "%20", "%20", input1_4);
    
    return 0;
}

