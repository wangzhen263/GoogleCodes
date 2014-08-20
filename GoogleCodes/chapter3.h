//
//  chapter3.h
//  GoogleCodes
//
//  Created by Jeff wang on 19/08/2014.
//  Copyright (c) 2014 Jeff. All rights reserved.
//

#include <vector>

// question 3.1 - solution

// question 3.2 - solution
class Stack3_2 {
    typedef struct _node {
        int value;
        int min;
    } Node;
public:
    Stack3_2() {
        m_min = 0;
        m_stack.reserve(20);
    }
    void push(int elem) {
        if (elem < m_min)
            m_min = elem;
        Node node;
        node.value = elem;
        node.min = m_min;
        m_stack.push_back(node);
    }
    int pop() {
        int node = m_stack.at(m_stack.size()-1).value;
        m_stack.pop_back();
        return node;
    }
    int min() {
        return m_stack.at(m_stack.size()-1).min;
    }
    size_t size() {
        return m_stack.size();
    }
private:
    int m_min;
    std::vector<Node> m_stack;
};

// question 3.3 - solution
class SetOfStacks {
private:
    std::vector<Stack3_2> m_stacks;
    int max_size;
public:
    SetOfStacks(int max) {
        max_size = max;
        Stack3_2 stack;
        m_stacks.push_back(stack);
    }
    
    void push(int elem) {
        if (m_stacks.at(m_stacks.size() - 1).size() == max_size) {
            Stack3_2 stack;
            stack.push(elem);
            m_stacks.push_back(stack);
        } else
            m_stacks.at(m_stacks.size() - 1).push(elem);
    }
    
    int pop() {
        int elem = m_stacks.at(m_stacks.size() - 1).pop();
        if (m_stacks.at(m_stacks.size() - 1).size() == 0)
            m_stacks.pop_back();
        return elem;
    }
    
    int popAt(int index) {
        if (index >= m_stacks.size())
            return -1;
        int elem = m_stacks.at(index).pop();
        if (m_stacks.at(index).size() == 0)
            m_stacks.erase(m_stacks.begin() + index);
        return elem;
    }
    
    int size() {
        int ret = 0;
        for (int i = 0; i < m_stacks.size(); ++i)
            ret += m_stacks.at(i).size();
        return ret;
    }
};

// question 3.5 - solution
class MyQueue {
private:
    Stack3_2 stack_in, stack_out;
public:
    void enqueue(int elem) {
        stack_in.push(elem);
    }
    int dequeue() {
        if (stack_out.size() > 0)
            return stack_out.pop();
        while (stack_in.size() > 0)
            stack_out.push(stack_in.pop());
        if  (stack_out.size() > 0)
            return stack_out.pop();
        else
            return -1;
    }
    size_t size() {
        return stack_out.size() + stack_in.size();
    }
};

// run
static void chapter3_run() {
    // question 3.2
    {
        Stack3_2 _stack;
        for (int i = 0; i < 10; ++i)
            _stack.push(i);
        while (_stack.size() > 0) {
            int min = _stack.min();
            int pop = _stack.pop();
            
            if (_stack.size() != pop
                || min != 0)
                printf("ERROR: wrong value %d is popped, min is %d, total size is %zu \n", pop, min, _stack.size());
        }
    }
    
    // question 3.3
    {
        SetOfStacks stacks(4);
        for (int i = 0; i < 10; ++i)
            stacks.push(i);
        while (stacks.size() > 0) {
            int pop = stacks.pop();
            
            if (stacks.size() != pop)
                printf("ERROR: wrong value %d is popped, total size is %d \n", pop, stacks.size());
        }
    }
    
    // question 3.5
    {
        MyQueue queue;
        for (int i = 0; i < 10; ++i)
            queue.enqueue(i);
        while (queue.size() > 0) {
            int elem = queue.dequeue();
            if (9 - queue.size() != elem)
                printf("ERROR: wrong value %d is popped, total size is %zu \n", elem, queue.size());
        }
    }
}