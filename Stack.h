//
// Created by shirin dora on 14/04/2020.
//

#ifndef GRAPHS_STACK_H
#define GRAPHS_STACK_H


class Stack {
public:
    Stack(int size=100);
    void push(int item);
    void pop();
    int top();
    bool is_empty();

private:
    int* items;
    int count;
    int max_capacity;
};


#endif //GRAPHS_STACK_H
