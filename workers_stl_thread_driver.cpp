#include <bits/stdc++.h>
#include "workers_stl_thread.h"

using namespace std;

int main()
{
    Workers & threadPool = GetThreadPool();

    threadPool.SpawnThread();

    for (int i = 0; i < 10000; ++i)
    {
        WorkItem * I = new Integer(33+i);

        WorkItem * d = new Double(11.11 + i);

        string str = "Hello World: " + to_string(i);
        WorkItem * s = new String(str);

        threadPool.EnqueueWorkItem(I);
        threadPool.EnqueueWorkItem(d);
        threadPool.EnqueueWorkItem(s);
    }

    /* Wait for all data to be processed in the Queue */
    threadPool.Wait();
    /* All data is processed */

    // Set up for gracefull exit of threads and this process
    threadPool.TerminateThreadPool();
    
    exit(0);
}
