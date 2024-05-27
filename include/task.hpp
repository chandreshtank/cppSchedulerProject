#ifndef SCHEDULER_TASK_HPP
#define SCHEDULER_TASK_HPP

#include <iostream>

using namespace std;

enum TASKPRIORITY {
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2
} ;

typedef void (*TASKFUNC) (void); 

class task
{
private:
    /* data */
    int taskId;
    TASKPRIORITY taskPriority;
    TASKFUNC taskFunc;

public:
    task(int id, TASKPRIORITY prio): taskId(id), taskPriority(prio), taskFunc(NULL)
    {
        
    }
    ~task()
    {

    }

    bool assignTask(TASKFUNC func);

    bool isTaskAssigned();

    task (const task &cpObjectSrc);

    void printTaskDetails(task tsk);

//        Doing it like this will call the copy constructor while and copy the taskObj from caller function and past in tsk object so base taskObj function will never get the changes reflected.  
//        void modifyTaskAttr(task tsk, TASKPRIORITY newPrio)

//        Doing it like this, The object is passed by reference so the changes made in this function in the tsk object will be reflected in called object i.e taskObj
    void modifyTaskAttr(task &tsk, TASKPRIORITY newPrio);
};

#endif /* SCHEDULER_TASK_HPP */ 