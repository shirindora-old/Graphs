//
// Created by shirin dora on 14/04/2020.
//

#ifndef GRAPHS_QUEUE_H
#define GRAPHS_QUEUE_H


class Queue {
public:
    Queue(int size=100);

    void enqueue(int item);
    void dequeue();
    bool is_empty();
    int peek();

private:
    int* items;
    int current_capacity;
    int max_capacity;

    int front;
    int rear;
};


#endif //GRAPHS_QUEUE_H
