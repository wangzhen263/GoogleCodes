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
}

#endif
