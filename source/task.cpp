#include "task.hpp"

using namespace std;

bool task::assignTask(TASKFUNC func)
{
    bool retVal = false;
    if (taskFunc == NULL)
    {
        taskFunc = func;
        retVal = true;
    }
    else
    {
        cout << "Error: Unable to assign task, Object already has task function assigned." << endl;
    }

    return retVal;
}

bool task::isTaskAssigned()
{
    if (this->taskFunc != NULL)
        return true;
    else
        return false;
}

// copy construtor
// inside the scope{} of copy construcor, the new object which is going to be the copy of the src object passed in the argument already resides. 
// so inside the copy constrorctor, when you use taskID or taskPrioirity, Variable and what ever would be the end value in the copy constrorcor will be the 
// output value of the copy constror. 
task::task (const task &cpObjectSrc)
{
    cout << "Copy Constructor called" << endl ;
    taskId = cpObjectSrc.taskId;
    taskPriority = cpObjectSrc.taskPriority; 
}

void task::printTaskDetails(task tsk)
{
    cout << "TaskID is " << taskId << "and Priority " << tsk.taskPriority << endl;
}

//        Doing it like this will call the copy constructor while and copy the taskObj from caller function and past in tsk object so base taskObj function will never get the changes reflected.  
//        void modifyTaskAttr(task tsk, TASKPRIORITY newPrio)

//        Doing it like this, The object is passed by reference so the changes made in this function in the tsk object will be reflected in called object i.e taskObj
void task::modifyTaskAttr(task &tsk, TASKPRIORITY newPrio)
{
    tsk.taskPriority = newPrio;
    cout << "Modify :TaskID " << tsk.taskId << "modified and Priority " << tsk.taskPriority << endl;
}
