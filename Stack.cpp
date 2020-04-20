//
// Created by shirin dora on 14/04/2020.
//

#include "Stack.h"

Stack::Stack(int size) {
    items = new int[size];
    count = 0;
    max_capacity = size;
}