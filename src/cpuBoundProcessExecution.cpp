#include "processService.hpp"
#include "queueService.hpp"

constexpr int NICE_0_LOAD = 1024;

double weightFunction(int priority)
{
    return NICE_0_LOAD / (1.0 + 0.4 * priority);
}

void executeCPUBoundProcess(Process *process, int timeSlice, QueueService &readyQueue)
{
    const int executedTime = std::min(timeSlice, process->cpuBurstTime);
    process->cpuBurstTime -= executedTime;
    const double weight = weightFunction(process->priority);
    process->vRunTime += (executedTime * NICE_0_LOAD) / weight;
    if (process->cpuBurstTime > 0)
    {
        readyQueue.push_element(process);
    }
}
void gpt_executeCPUBoundProcess(Process *process, int timeSlice, QueueService &readyQueue)
{
    int timeQuantum = timeSlice;
    while (timeQuantum > 0)
    {
        if (process->cpuBurstTime <= timeQuantum)
        {
            timeQuantum -= process->cpuBurstTime;
            process->cpuBurstTime = 0;
            process->processState.counter = 0;
            break;
        }
        else
        {
            process->cpuBurstTime -= timeQuantum;
            process->processState.counter += timeQuantum;
            timeQuantum = 0;
        }
    }

    if (process->cpuBurstTime == 0)
    {
        process->priority = process->priority - (int)weightFunction(process->priority);
        readyQueue.push_element(process);
    }
    else
    {
        readyQueue.push_element(process);
    }
}