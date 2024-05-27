#ifndef SCHEDULER_TASK_SC_HPP
#define SCHEDULER_TASK_SC_HPP

#include "task.hpp"
#include <mutex>

using namespace std;

enum SCHE_TYPE {
    PRIORITY_BASED = 0,
    ROUND_ROBIN = 1,
};

class taskScheduler {

    private:
        static int totalNumOfTasks;
        SCHE_TYPE schedulerType;
        static taskScheduler *pSchedulerObj;
        static std::once_flag once_init_flag;

        //@TODO: delete the methods for copy constructor and = operator 

        taskScheduler() : schedulerType(PRIORITY_BASED) {
            cout << "Scheduler Object Created" << endl;
        }

        static void initTaskScheduler() {
            pSchedulerObj = new taskScheduler();

            if (pSchedulerObj != NULL)
                cout << "Singleton object Created" << endl;
            else
                cout << "Singleton Object creation FAILED" << endl;
        }


    public:

        static taskScheduler *getInstance(void)
        {
            std::call_once(once_init_flag, initTaskScheduler);
            return pSchedulerObj;
        }

        int getTotalNumOfTasks(void)
        {
            return totalNumOfTasks;
        }

};

int taskScheduler::totalNumOfTasks = 0;
taskScheduler* taskScheduler::pSchedulerObj = nullptr;
std::once_flag taskScheduler::once_init_flag;

#endif /* SCHEDULER_TASK_SC_HPP */