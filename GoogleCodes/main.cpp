//
//  main.cpp
//  GoogleCodes
//
//  Created by Jeff Wang on 15/07/2014.
//  Copyright (c) 2014 Jeff. All rights reserved.
//

#include <iostream>
#include <chrono>
#include "chapter1.h"

int main(int argc, const char * argv[])
{
    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
    
    // input: 3yWYfPLfplC3f5k
    std::string input = "3yWYfPLfplC3f5k";
    
    auto t0 = Time::now();
    printf("result1: %d. \n", checkUniqueString1(input));
    auto t1 = Time::now();
    fsec fs = t1 - t0;
    ms d = std::chrono::duration_cast<ms>(fs);
    std::cout << d.count() << "ms\n";
    
    auto t2 = Time::now();
    printf("result2: %d. \n", checkUniqueString2(input));
    auto t3 = Time::now();
    fsec fs2 = t2 - t3;
    ms d2 = std::chrono::duration_cast<ms>(fs2);
    std::cout << d2.count() << "ms\n";
    
    reverse(input);
    printf("result 1.2: %s\n", input.c_str());
    
    printf("result 1.3: %d\n", isPermutation("abcd", "dbac"));
    
    return 0;
}

