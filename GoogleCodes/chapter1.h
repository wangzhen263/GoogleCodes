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
#endif
