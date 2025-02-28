#include "queueService.hpp"
#include "processService.hpp"
#include <memory>

QueueService::QueueService()
{
}

void QueueService::push_element(Process *process)
{
    readyQueue.push(process);
}
void QueueService::pop_element()
{
    readyQueue.pop();
}
bool QueueService::is_empty()
{
    return readyQueue.empty();
}

void QueueService::print_queue()
{
    std::priority_queue<Process *, std::vector<Process *>, Compare> tempQueue = readyQueue;
    while (!tempQueue.empty())
    {
        Process *process = tempQueue.top();
        std::cout << "PID: " << process->pid << " Priority: " << process->priority << std::endl;
        tempQueue.pop();
    }
/*
    // another way could be using auto and just printing the data of auto
    auto tempQueue2 = readyQueue;
    for (auto i = 0; i < tempQueue2.size(); i++)
    {
        Process *process = tempQueue2.top();
        std::cout << "PID: " << process->pid << " Priority: " << process->priority << std::endl;
        tempQueue2.pop();
    }
*/}