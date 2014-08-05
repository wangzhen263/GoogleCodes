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

// question 1.1 - solution 3
static bool checkUniqueString3(std::string input) {
    if (input.size() > 74)
        return false;
    
    int lowbits = 0;
    int midbits = 0;
    int highbits = 0;
    for (int i = 0; i < input.size();++i) {
        int bits = input.at(i) - '1';
        if (bits > 63) {
            if ( (highbits & (1 << (bits - 63))) > 0)
                return false;
            else
                highbits |= (1 << (bits - 63));
        } else if (31 < bits && bits <= 63){
            if ( (midbits & (1 << (bits - 31))) > 0)
                return false;
            else
                midbits |= (1 << (bits - 31));
        } else {
            if ( (lowbits & (1<<bits)) > 0 )
                return false;
            else
                lowbits |= (1 << bits);
        }
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

// question 1.3 - solution 1
static bool isPermutation1(std::string str1, std::string str2) {
    if (str1.size() != str2.size())
        return false;
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    for(int i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

// question 1.3 - solution 2
static bool isPermutation2(std::string str1, std::string str2) {
    if (str1.size() != str2.size())
        return false;
    int* ascii_set = new int[256]();
    for(int i = 0; i < str1.size(); ++i) {
        ascii_set[str1.at(i)]++;
    }
    for(int i = 0; i < str2.size(); ++i) {
        if ( (--ascii_set[str2.at(i)]) < 0 ) {
            return false;
        }
    }
    return true;
}

// question 1.4 - solution 1
static void replaceSpace(char str[], int length) {
    bool isBetweenChars = false;
    char* tempString = new char[length]();
    int tempPos = 0;
    for(int i = 0; i < length; ++i){
        if (str[i] != ' ') {
            isBetweenChars = true;
            if (tempPos < length)
                tempString[tempPos++] = str[i];
        } else {
            if (isBetweenChars) {
                isBetweenChars = false;
                if (tempPos < length) tempString[tempPos++] = '%';
                if (tempPos < length) tempString[tempPos++] = '2';
                if (tempPos < length) tempString[tempPos++] = '0';
            }
        }
    }
    memcpy(str, tempString, length);
}

// question 1.4 - solution 2
static void replaceSpace2(char str[], int length) {
    bool isBetweenChars = false;
    int writePos = length - 1, spaceCount = 0;
    for(int i = length -1; i >= 0; --i){
        if (str[i] != ' ') {
            isBetweenChars = true;
            for (int j = 0; j < spaceCount; ++j) {
                str[writePos--] = '0';
                str[writePos--] = '2';
                str[writePos--] = '%';
            }
            spaceCount = 0;
            if (writePos >= 0 )
                str[writePos--] = str[i];
        } else {
            if (isBetweenChars) {
                spaceCount++;
            }
        }
    }
}

// question 1.5 - solution 1
static std::string compress(std::string input) {
    
    std::string ret;
    char lastChar = 0;
    int count = 0;
    for (int i = 0; i < input.size(); ++i) {
        if (lastChar != input[i] && count > 0) {
            ret.push_back(lastChar);
            char itoa;
            sprintf(&itoa,"%d",count);
            ret.push_back(itoa);
            
            lastChar = input[i];
            count = 1;
        }
        else {
            lastChar = input[i];
            count++;
        }
    }
    ret.push_back(lastChar);
    char itoa;
    sprintf(&itoa,"%d",count);
    ret.push_back(itoa);
    
    if (ret.size() >= input.size())
        return input;

    return ret;
}

// run
static void chapter1_run() {
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
    
    char input1_4_1[] = "Mr John Smith    ";
    replaceSpace(input1_4_1, 17);
    printf("result10: question 1.4 expect: Mr%sJohn%sSmith, actually: %s\n", "%20", "%20", input1_4_1);
    
    char input1_4_2[] = "Mr John Smith    ";
    replaceSpace2(input1_4_2, 17);
    printf("result11: question 1.4 expect: Mr%sJohn%sSmith, actually: %s\n", "%20", "%20", input1_4_2);
    
    std::string input1_5_1 = "aabcccccaaa";
    printf("result12: question 1.5 expect: a2b1c5a3, actually: %s\n", compress(input1_5_1).c_str());
}
#endif
