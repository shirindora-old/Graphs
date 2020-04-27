//
// Created by shirin dora on 14/04/2020.
//

#include "Stack.h"

Stack::Stack(int size) {
    items = new int[size];
    count = 0;
    max_capacity = size;
}

void Stack::pop() {
    if (count != 0) {
        count--;
    }
}

void Stack::push(int item) {
    if (count != max_capacity) {
        items[count] = item;
        count++;
    }
}

int Stack::top() {
    if (count != 0) {
        return items[count - 1];
    }
}

bool Stack::is_empty() {
    return count == 0;
}
