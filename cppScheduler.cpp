#include <iostream>

#include "task.hpp"
#include "taskScheduler.hpp"

using namespace std;
namespace chandresh {
    int valueOfA = 10;
}

class Base {
public:

    virtual void showInsideVirtual() {
        std::cout << "\nBase class inner function" << std::endl;
    }

    void show() {
        std::cout << "\nBase class" << std::endl;
        showInsideVirtual();
    }

    virtual void normalPoly()  { // Override base class method
        std::cout << "\nNormal Poly Base class" << std::endl;
    }


    // VERY IMPORTANT, SEE THE MAIN FUNCTION AND SAME COMMENT THERE AS WELL
    // THIS ALSO CREATES A PROBLEM BECAUSE NOW WHEN WE CALL the delete function to remove the object
    // When you will do this
    // delete b;
    // this will cause the destructor of the base class to be called so in case if you have assigned 
    // any memory in the constructor of the derived class, When you called new Derived() -> It called 
    // the constructor of the derived class and destructor of the derived class where you have to free that memory 
    // That never got called 

    // TO AVOID TIS< you always should make the destructor of the base class as virtual so that 
    // Upon delete, It will call the destructor of the derived class and then it will call the destrucotr of the of the base class.

    virtual ~Base()
    {
        cout << "\n Destructor of Base class" << endl;
    }
};

class Derived : public Base {
public:

    void showInsideVirtual() {
        std::cout << "\nDerived class inner function class" << std::endl;
    }

    void show()  { // Override base class method
        std::cout << "\nDerived class" << std::endl;
    }

    void normalPoly()  { // Override base class method
        std::cout << "\nNormal Poly Derived class" << std::endl;
    }

    ~Derived() {
        cout << "\n Destructor of Derived class" << endl;
    }
};

void task1(void)
{
    int i=10;
    while (i--)
    {
        cout << "Task is running" << endl;
    }
}

int main()
{
    int valueOfA = 5; 
    cout <<"std namespace " << valueOfA << " and chandresh name space has " << chandresh::valueOfA << "\n\n" ;

    task taskObj(1, HIGH);

    taskObj.assignTask(&task1);

    taskScheduler *pSchObj = taskScheduler::getInstance();

    pSchObj->getTotalNumOfTasks();

    // The copy constrocor will be called here
    taskObj.printTaskDetails(taskObj);

    // the copy constroctor will not be called here because we are passing by reference
    taskObj.modifyTaskAttr(taskObj, HIGH);

    // copy constrorer will be called here. 
    taskObj.printTaskDetails(taskObj);

    cout << sizeof(taskObj) << " is the size of the object" ;


// RUN TIME POLYMORPHISM Example
    Base* b = new Derived();
     Base *bb = new Base();
    // This will call normalPoly of derived class
    b->normalPoly();
    
    // This will call the show function of the derived class
    b->show(); // Calls Derived's show method due to virtual function

    // THIS ALSO CREATES A PROBLEM BECAUSE NOW WHEN WE CALL the delete function to remove the object
    // When you will do this
    delete b;
    // this will cause the destructor of the base class to be called so in case if you have assigned 
    // any memory in the constructor of the derived class, When you called new Derived() -> It called 
    // the constructor of the derived class and destructor of the derived class where you have to free that memory 
    // That never got called 

    // TO AVOID TIS< you always should make the destructor of the base class as virtual so that 
    // Upon delete, It will call the destructor of the derived class and then it will call the destrucotr of the of the base class.

    bb->normalPoly();

    delete bb;   

    return 0;


}