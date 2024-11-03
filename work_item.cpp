#include "work_item.h"
#include "workers_stl_thread.h"

using namespace std;

void Integer::process()
{
    char s[180];
    snprintf(s, sizeof(s), "Integer::process: %d, ThreadID=%x\n", m_Int,
            std::this_thread::get_id());
    cout << s;
} 

void String::process()
{
   char s[180];
   snprintf(s, sizeof(s), "String::process: %s, ThreadID=%x\n", 
            m_Str.c_str(), std::this_thread::get_id());
   cout << s;
} 

void Double::process()
{
    char s[180];
    snprintf(s, sizeof(s), "Double: Consumer Thread=%x is now a producer", 
             std::this_thread::get_id());

    string str = s;
    WorkItem * w = new String(str);
    GetThreadPool().EnqueueWorkItem(w);

    snprintf(s, sizeof(s), "Double::process: %lf, ThreadID=%x\n", 
            m_Double, std::this_thread::get_id());
    cout << s;
} 
