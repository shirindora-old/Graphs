//
// Created by shirin dora on 14/04/2020.
//

#include "Queue.h"

Queue::Queue(int size) {
    items = new int[size];
    max_capacity = size;

    front = -1;
    rear = -1;
}

void Queue::enqueue(int item) {
    if (rear == -1) {
        rear++;
        front++;
    } else {
        rear = (rear + 1) % max_capacity;
    }

    items[rear] = item;
}

void Queue::dequeue() {
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % max_capacity;
    }
}

bool Queue::is_empty() {
    return front == -1;
}

int Queue::peek() {
    return items[front];
}