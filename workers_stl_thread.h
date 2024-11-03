#ifndef WORKERS_H_INCLUDE
#define WORKERS_H_INCLUDE

#include <bits/stdc++.h>
#include "work_item.h"

using namespace std;

void* thread_start_func_cpp (void* p);

extern "C"
{
void* thread_start_func (void* p);
}

class Workers
{
    private:
        int m_NumWorkers;
        std::atomic<bool> m_Running;
        vector<std::thread> m_Threads;
        //vector<std::thread *> m_Threads;
        mutable std::mutex m_Mutex;
        std::condition_variable m_WorkCondVar;
        std::condition_variable m_WaitCondVar;
        queue<WorkItem *> m_WorkItems;

        void ThreadStart();
    public:
        friend void *thread_start_func_cpp(void *p);

        Workers(int NumThreads);
#if 0
        static Workers & Instance(int NumThread = 5)
        {
            static Workers workers(NumThread);

            return workers;
        }
#endif
        ~Workers();

        Workers(Workers &rhs) = delete;
        Workers & operator = (const Workers & rhs) = delete;

        int GetNumJobs() const
        {
            std::lock_guard<std::mutex> lkg(m_Mutex);
            return m_WorkItems.size();
        }

        void SpawnThread();

        void EnqueueWorkItem(WorkItem *item);

        void Wait();

        void TerminateThreadPool();
};

extern "C"
{
Workers & GetThreadPool();
}
#endif
