//
//  chapter2.h
//  GoogleCodes
//
//  Created by Jeff Wang on 5/08/2014.
//  Copyright (c) 2014 Jeff. All rights reserved.
//

#ifndef GoogleCodes_chapter2_h
#define GoogleCodes_chapter2_h

#include <map>
#include <iostream>
#include <math.h> 

typedef struct LList {
    int value;
    LList* next;
} LList_t;

// question 2.1 - solution 1
static void removeDuplicate(LList_t* list) {
    LList_t* checkPos = list;
    LList_t* lastPos = list;
    list = list->next;
    
    while (list) {
        if (checkPos->value == list->value) {
            lastPos->next = list->next;
            LList_t* temp = list;
            list = list->next;
            delete temp;
        } else {
            lastPos = list;
            list = list->next;
        }
        
        if (list == NULL) {
            checkPos = checkPos->next;
            lastPos = checkPos;
            if (checkPos)
                list = checkPos->next;
        }
    }
}

// question 2.1 - solution 2
static void removeDuplicate2(LList_t* list) {
    LList_t* curPos = list;
    while (curPos) {
        LList_t* runner = curPos;
        while (runner->next) {
            if (curPos->value == runner->next->value){
                LList_t* tmp = runner->next;
                runner->next = tmp->next;
                delete tmp;
            }
            else
                runner = runner->next;
        }
        
        curPos = curPos->next;
    }
}

// question 2.1 - solution 3
static void removeDuplicate3(LList_t* list) {
    LList_t* current = list;
    std::map<int, int> mapVal;
    mapVal[current->value] = 1;
    
    while (current->next) {
        if (mapVal[current->next->value] == 1) {
            LList_t* tmp = current->next;
            current->next = current->next->next;
            std::cout << "Duplicate Found: " << tmp->value << " removed" << std::endl;
            delete tmp;
        }
        else {
            mapVal[current->next->value] = 1;
            current = current->next;
        }
    }
}

// question 2.2 - solution 1
static LList_t* findKthElement(LList_t* list, int k) {
    if (!list)
        return NULL;
    
    LList_t* head = list;
    for (int i = 0; i < k; ++i)
        list = list->next;
    
    while (list->next) {
        head = head->next;
        list = list->next;
    }
    
    return head;
}

// question 2.3 - solution 1
static void removeMid(LList_t* list) {
    if (!list)
        return;
    
    LList_t* mid = list;
    if (list->next)
        list= list->next->next;
    while (list) {
        list = list->next->next;
        mid = mid->next;
    }
    
    LList_t* tmp = mid->next;
    mid->next = mid->next->next;
    printf("remove element: %d \n", tmp->value);
    delete tmp;
}

// question 2.4 - solution 1
static LList_t* midByX(LList_t* list, int x) {
    if (!list)
        return NULL;
    
    LList_t* lower = NULL, *lptr = NULL, *higher = NULL, *hptr = NULL;
    
    while (list) {
        if (list->value < x) {
            if (!lower)
                lower = lptr = list;
            else {
                lptr->next = list;
                lptr = lptr->next;
            }
        } else {
            if (!higher)
                higher = hptr = list;
            else {
                hptr->next = list;
                hptr = hptr->next;
            }
        }
        
        list = list->next;
    }
    lptr->next = NULL;
    hptr->next = NULL;
    list = lower;
    lptr->next = higher;
    return list;
}

// question 2.5 - solution part 1
static int intReverseParser(LList_t* num) {
    int power = 0;
    int ret = 0;
    while (num) {
        ret += num->value * pow(10, power++);
        num = num->next;
        
    }
    return ret;
}

static LList_t* intToReverseList(int num) {
    LList_t* ret = NULL;
    LList_t* head = NULL;
    int temp = 0;
    while (num != 0) {
        int value = (num - (temp = num/10) * 10);
        LList_t* elem = new LList_t;
        elem->value = value;
        elem->next = NULL;
        if (ret){
            ret->next = elem;
            ret = ret->next;
        }
        else {
            head = elem;
            ret = elem;
        }
        
        num = temp;
    }
    
    return head;
}

static LList_t* addReverseLists(LList_t* num1, LList_t* num2) {
    if (!num1 || !num2)
        return NULL;
    return intToReverseList(intReverseParser(num1) + intReverseParser(num2));
}

// question 2.5 - solution part 2
static int intForwardParser(LList_t* num) {
    int ret = 0;
    while(num) {
        ret = ret*10 + num->value;
        num = num->next;
    }
    return ret;
}

static LList_t* intToForwardList(int num) {
    LList_t* ret = NULL;
    int temp = 0;
    while (num != 0) {
        int value = num - (temp = num/10)*10;
        LList_t* elem = new LList_t;
        elem->value = value;
        if (!ret) {
            elem->next = NULL;
            ret = elem;
        } else {
            elem->next = ret;
            ret = elem;
        }
        num = temp;
    }
    return ret;
}

static LList_t* addForwardLists(LList_t* num1, LList_t* num2) {
    if (!num1 || !num2)
        return NULL;
    
    return intToForwardList(intForwardParser(num1) + intForwardParser(num2));
}

// question 2.6 - solution
static LList_t* findCircular(LList_t* list, int length) {
    int trials = length*2;
    LList_t* first = list;
    LList_t* second = list;
    LList_t* ret = NULL;
    while(first->next != second && trials >= 0) {
        first = first->next->next;
        second = second->next;
        --trials;
    }
    
    if (trials >= 0)
        ret = second;
    return ret;
}

// question 2.7 - solution
static bool checkPalindrome(LList_t* list) {
    LList_t* head = list;
    LList_t* reverse = new LList_t;
    reverse->value = list->value;
    reverse->next = NULL;
    list = list->next;
    int len = 0;
    while (list) {
        LList_t* temp = new LList_t;
        temp->value = list->value;
        temp->next = reverse;
        reverse = temp;
        list = list->next;
        ++len;
    }
    
    int run = 0;
    while (run <=len/2) {
        if (reverse->value != head->value)
            return false;
        reverse = reverse->next;
        head = head->next;
        ++run;
    }
    
    return true;
}

// run
static void chapter2_run() {
    LList_t* list = new LList_t;
    list->value = 0;
    list->next = NULL;
    LList_t* back = list;
    
    for (int i = 1; i < 100; ++i) {
        LList_t* item = new LList_t;
        item->value = i;
        item->next = NULL;
        back->next = item;
        back = item;
    }
    
    for (int i = 1; i < 100; i+=2) {
        LList_t* item = new LList_t;
        item->value = i;
        item->next = NULL;
        back->next = item;
        back = item;
    }
    
    // question 2.1
    {
        LList_t* input = list;
//    removeDuplicate(list);
//    removeDuplicate2(list);
        removeDuplicate3(input);
    
        while (input) {
            printf("print list: %d \n", input->value);
            input = input->next;
        }
    }
    
    // question 2.2
    {
        int k = 2;
        LList_t* input = list;
        LList_t* ret = findKthElement(input, k);
        printf("print element at %d to the last element value: %d \n", k, (ret->value));
    }
    
    // question 2.3
    {
        LList_t* input = list;
        removeMid(input);
    }
    
    // question 2.4
    {
        LList_t* input = list;
        LList* ret = midByX(input, 50);
        
        while (ret) {
            printf("print element in midByX %d seperated by value: %d \n", (ret->value), 50);
            ret = ret->next;
        }
    }
    
    // question 2.5
    {
        // part 1
        {
            LList_t* input1 = new LList_t;
            input1->value = 7;
            input1->next = new LList_t;
            input1->next->value = 1;
            input1->next->next = new LList_t;
            input1->next->next->value = 6;
            input1->next->next->next = NULL;
            
            LList_t* input2 = new LList_t;
            input2->value = 5;
            input2->next = new LList_t;
            input2->next->value = 9;
            input2->next->next = new LList_t;
            input2->next->next->value = 2;
            input2->next->next->next = NULL;
            
            LList_t* ret = addReverseLists(input1, input2);

            while (ret) {
                printf("print int result: %d \n", (ret->value));
                ret = ret->next;
            }
        }
        
        // part 2
        {
            LList_t* input1 = new LList_t;
            input1->value = 6;
            input1->next = new LList_t;
            input1->next->value = 1;
            input1->next->next = new LList_t;
            input1->next->next->value = 7;
            input1->next->next->next = NULL;
            
            LList_t* input2 = new LList_t;
            input2->value = 2;
            input2->next = new LList_t;
            input2->next->value = 9;
            input2->next->next = new LList_t;
            input2->next->next->value = 5;
            input2->next->next->next = NULL;
            
            LList_t* ret = addForwardLists(input1, input2);
            while (ret) {
                printf("try forward: %d \n", (ret->value));
                ret = ret->next;
            }
        }
    }
    
    // question 2.6
    {
        LList_t* input1 = new LList_t;
        LList_t* circular = NULL;
        input1->value = 0;
        input1->next = new LList_t;
        input1->next->value = 1;
        input1->next->next = circular = new LList_t;
        input1->next->next->value = 2;
        input1->next->next->next = NULL;
        
        circular->next = new LList_t;
        circular->next->value = 3;
        circular->next->next = new LList_t;
        circular->next->next->value = 4;
        circular->next->next->next = circular;
        
        LList_t* ret = findCircular(input1, 5);
        printf("find circular: %d \n", ret->value);
    }
    
    // question 2.7
    {
        LList_t* input = new LList_t;
        input->value=0;
        input->next = new LList_t;
        input->next->value = 1;
        input->next->next = new LList_t;
        input->next->next->value = 0;
        input->next->next->next = NULL;
        
        printf("is it a palindrome: %d\n", checkPalindrome(input));
        
        LList_t* input2 = new LList_t;
        input2->value=0;
        input2->next = new LList_t;
        input2->next->value = 1;
        input2->next->next = new LList_t;
        input2->next->next->value = 2;
        input2->next->next->next = NULL;
        
        printf("is it a palindrome2: %d\n", checkPalindrome(input2));
    }
}

#endif
