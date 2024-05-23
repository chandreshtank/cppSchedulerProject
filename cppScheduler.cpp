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

#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void show()  { // Override base class method
        std::cout << "Derived class" << std::endl;
    }
};


class task {
        int taskId;
        TASKPRIORITY taskPriority;

    public:


        task(int id): taskId(id), taskPriority(MEDIUM)
        {
            cout << "Task with TaskID " << id << "created." << endl;
        }

        task(int id, TASKPRIORITY prio): taskId(id), taskPriority(prio)
        {
            cout << "Task with TaskID " << id << "created with Priority " << prio << endl;
        }

        // copy construtor
        // inside the scope{} of copy construcor, the new object which is going to be the copy of the src object passed in the argument already resides. 
        // so inside the copy constrorctor, when you use taskID or taskPrioirity, Variable and what ever would be the end value in the copy constrorcor will be the 
        // output value of the copy constror. 
        task (const task &cpObjectSrc)
        {
            cout << "Copy Constructor called" << endl ;
            taskId = cpObjectSrc.taskId;
            taskPriority = cpObjectSrc.taskPriority; 
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

    // The copy constrocor will be called here
    taskObj.printTaskDetails(taskObj);

    // the copy constroctor will not be called here because we are passing by reference
    taskObj.modifyTaskAttr(taskObj, HIGH);

    // copy constrorer will be called here. 
    taskObj.printTaskDetails(taskObj);

    cout << sizeof(taskObj) << " is the size of the object" ;


// RUN TIME POLYMORPHISM Example
    Base* b;
    Derived d;
    b = &d;
    b->show(); // Calls Derived's show method due to virtual function
    return 0;


}