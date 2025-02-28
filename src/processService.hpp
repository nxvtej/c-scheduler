#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <iostream>
#include <vector>
#include "./nlohmann/json.hpp"

using json = nlohmann::json;

enum PROCESS_NATURE
{
    CPU_BOUND,
    IO_BOUND,
};

struct ProcessState
{
    long long counter;
};
struct Process
{
    int pid;
    long long vRunTime;
    int cpuBurstTime;
    int priority;

    ProcessState processState;
    PROCESS_NATURE processNature;
};

PROCESS_NATURE
getProcessNature(const std::string &nature);
std::vector<Process *> getProcessFromJSON(const std::string &filePath);

#endif
