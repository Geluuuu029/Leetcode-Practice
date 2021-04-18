#include <chrono>
#include <windows.h>
#include <psapi.h>
#include <iostream>

using namespace std;

class PerfTool
{
public:
    PerfTool() {};
    ~ PerfTool() {};

    void StartPerfTool();

    void EndPerfTool();

    double GetCostMemory();

    void PrintPerfInfo();

private:
    chrono::high_resolution_clock::time_point startT_;
    chrono::high_resolution_clock::time_point endT_;

    double durationMillisecond_; //ms;
    double costMemory_; // MB;
};

void PerfTool::StartPerfTool()
{
    startT_ = chrono::high_resolution_clock::now();
}

void PerfTool::EndPerfTool()
{
    endT_ = chrono::high_resolution_clock::now();
    chrono::duration<double,std::ratio<1,1000>> duration_ms(endT_ - startT_); //millisecond time
    durationMillisecond_ = duration_ms.count();
}


/* Get Current Process Cost Memory MB*/
double PerfTool::GetCostMemory()
{
    HANDLE handle = GetCurrentProcess();
    HINSTANCE hDll = LoadLibrary("psapi.dll");

    typedef int(*pGetProcMemoryFunc)(HANDLE Process,PPROCESS_MEMORY_COUNTERS ppsmemCounters,DWORD cb);
    pGetProcMemoryFunc GetProcMemoryFunc;
    
    GetProcMemoryFunc = (pGetProcMemoryFunc)GetProcAddress(hDll, "GetProcessMemoryInfo");
    
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcMemoryFunc(handle, &pmc, sizeof(pmc));

    costMemory_ = (double)(pmc.WorkingSetSize/1024/1024);

    FreeLibrary(hDll);

    return costMemory_;
}

void PerfTool::PrintPerfInfo()
{
    cout << "Program Running Time is " << durationMillisecond_ << " millisecond and Cost Memory is " 
         << GetCostMemory() << " MB" << endl;
}
