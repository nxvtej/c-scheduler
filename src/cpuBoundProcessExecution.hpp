#ifndef CPU_BOUND_PROCESS_EXECUTION_HPP
#define CPU_BOUND_PROCESS_EXECUTION_HPP

#include "processService.hpp"
#include "queueService.hpp"

double weightFunction(int priority);

void executeCPUBoundProcess(Process *process, int timeSlice, QueueService &readyQueue);

#endif