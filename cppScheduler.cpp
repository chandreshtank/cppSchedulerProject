#include <iostream>

using namespace std;
namespace chandresh {
    int valueOfA = 10;
}
enum TASKPRIORITY {
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2
} ;

class task {
    public:
        int taskId;
        TASKPRIORITY taskPriority;

        task(int id): taskId(id), taskPriority(MEDIUM)
        {
            cout << "Task with TaskID " << id << "created." << endl;
        }

        task(int id, TASKPRIORITY prio): taskId(id), taskPriority(prio)
        {
            cout << "Task with TaskID " << id << "created with Priority " << prio << endl;
        }

        void printTaskDetails(task tsk)
        {
            cout << "TaskID is " << taskId << "and Priority " << tsk.taskPriority << endl;
        }

//        Doing it like this will call the copy constructor while and copy the taskObj from caller function and past in tsk object so base taskObj function will never get the changes reflected.  
//        void modifyTaskAttr(task tsk, TASKPRIORITY newPrio)

//        Doing it like this, The object is passed by reference so the changes made in this function in the tsk object will be reflected in called object i.e taskObj
        void modifyTaskAttr(task &tsk, TASKPRIORITY newPrio)
        {
            tsk.taskPriority = newPrio;
            cout << "Modify :TaskID " << tsk.taskId << "modified and Priority " << tsk.taskPriority << endl;
        }
};

class taskScheduler {
public:
    static int numOfTasks;

    static void printNumOfTasks()
    {
        cout << "Total Num of tasks are " << numOfTasks << "\n\n";
    }
}; 

int taskScheduler::numOfTasks = 9;
int main()
{
    int valueOfA = 5;
    cout <<"std namespace " << valueOfA << " and chandresh name space has " << chandresh::valueOfA << "\n\n" ;

    task taskObj(1);

    taskScheduler schedulerObject;

    schedulerObject.printNumOfTasks();

    taskObj.printTaskDetails(taskObj);

    taskObj.modifyTaskAttr(taskObj, HIGH);

    taskObj.printTaskDetails(taskObj);

    cout << sizeof(taskObj) << " is the size of the object" ;

}