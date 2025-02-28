#ifndef QUEUE_SERVICE_HPP
#define QUEUE_SERVICE_HPP

#include <iostream>
#include <queue>
#include <vector>
#include <processService.hpp>

class QueueService
{
private:
    struct Compare
    {
        bool operator()(Process *p1, Process *p2)
        {
            return p1->priority > p2->priority;
        }
    };
    std::priority_queue<Process *, std::vector<Process *>, Compare> readyQueue;
    // why cant we directly use the compare function in the priority queue, why do we need to use decltype
    // because the compare function is a member function of the class and the priority queue expects a static functionS
    // so inorder to make it statuc we can wrap it in a struct and directly pass the struct to it

public:
    QueueService();
    void push_element(Process *process);
    void pop_element();
    bool is_empty();

    Process *top_element();
    void print_queue();
};

#endif