#include <iostream>

using namespace std;
namespace chandresh {
    int valueOfA = 10;
}


class task {
    public:
        int taskId;

        task(int id): taskId(id)
        {
            cout << "Task with TaskID " << id << "created." << endl;
        }

        void printTaskID()
        {
            cout << "TaskID is " << taskId << endl;
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

}