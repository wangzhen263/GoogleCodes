//
//  chapter1.h
//  GoogleCodes
//
//  Created by Jeff Wang on 21/07/2014.
//  Copyright (c) 2014 Jeff. All rights reserved.
//

#ifndef GoogleCodes_chapter1_h
#define GoogleCodes_chapter1_h

// question 1.1 - solution 1
static bool checkUniqueString1(std::string input) {
    for (int index = 0; index < input.length(); ++index) {
        char atpos = input.at(index);
        for (int subindex = index+1; subindex < input.length(); ++subindex) {
            if (atpos == input.at(subindex))
                return false;
        }
    }
    return true;
}

// question 1.1 - solution 2
static bool checkUniqueString2(std::string input) {
    if (input.length() == 0) return false;
    if (input.length() == 1) return true;
    
    std::sort(input.begin(), input.end());
    int first = 1, second = 0;
    
    for(; first < input.length(); ++first, ++second){
        if (input.at(first) <= input.at(second))
            return false;
    }
    
    return true;
}

// question 1.2
static void reverse(std::string& input) {
    size_t length = input.length();
    char tmp;
    for (size_t begin = 0, end = length -1; begin < end; ++begin, --end) {
        tmp = input.at(begin);
        input[begin] = input[end];
        input[end] = tmp;
    }
}

// question 1.3
#include <map>
static bool isPermutation(std::string str1, std::string str2) {
    if (str1.length() != str2.length())
        return false;
    
    std::map<char, int> mstr1;
    std::map<char, int>::iterator it1;
    for (int index = 0; index < str1.length(); ++index){
        if ((it1 = mstr1.find( str1[index] )) != mstr1.end())
            mstr1[ str1[index] ]++;
        else
            mstr1[ str1[index] ] = 1;
    }
    
    std::map<char, int> mstr2;
    std::map<char, int>::iterator it2;
    for (int index = 0; index < str2.length(); ++index){
        if ((it2 = mstr2.find( str2[index] )) != mstr2.end())
            mstr2[ str2[index] ]++;
        else
            mstr2[ str2[index] ] = 1;
    }
    
    return mstr1.size() == mstr2.size() && std::equal(mstr1.begin(), mstr1.end(), mstr2.begin());
}
#endif
