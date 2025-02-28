#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <processService.hpp>

PROCESS_NATURE getProcessNature(const std::string &nature)
{
    if (nature == "CPU_BOUND")
        return PROCESS_NATURE::CPU_BOUND;
    if (nature == "IO_BOUND")
        return PROCESS_NATURE::IO_BOUND;

    throw std::invalid_argument("Invalid Process Nature Value");
}

std::vector<Process *> extractProcessFromJSON(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file of processes" + filePath);
    }

    json processJSON;
    file >> processJSON;
    file.close();

    std::vector<Process *> processes;

    // get each process from json
    for (const auto &processInfo : processJSON)
    {
        Process *process = new Process();
        process->pid = processInfo["pid"];
        process->vRunTime = processInfo["vRunTime"];
        process->cpuBurstTime = processInfo["cpuBurstTime"];
        process->processState.counter = processInfo["processState"]["counter"];
        process->priority = processInfo["priority"];
        process->processNature = getProcessNature(processInfo["processNature"]);
        processes.push_back(process);
    }
    return processes;
    std::cout << "Extracted processes from JSON file" << std::endl;
}