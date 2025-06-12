#include<bits/stdc++.h>
using namespace std;

class Student{
    private: 
        int age;
        int rollNo;
        static int totalStudents;
    public:
        // default Constructor
        Student(){
            totalStudents++;
        }
        // parameterised constructor

        Student(int age, int rollNo){
            this->age = age;
            this->rollNo = rollNo;
            totalStudents++;
        }
        int getRollNo(){
            return rollNo;
        }
        int getAge() {
            return age;
        }

        static int getTotalStudents(){
            return totalStudents;
        }
};
int Student:: totalStudents = 0;
/*
    Note : WE have to declare static members (propertics outside the class)
    But Why?
    Reason 1: the static member is not the object (instance ) property it is class property so There should be 
              one comman global/static space of it. so that every instance can access the space
    Reason 2: Inside the class we only define that their would be a static member called totalStudents present
              but we didn't allocate memory to it. So outside the class we are declaring the member to allocate memory to it
              in global space
    In summary: 
    Static is shared among all objects ->	So it can’t live inside any one object
    Declaration in class ≠ memory	-> It only tells the compiler "it exists"
    Must be defined globally	-> So it gets one shared memory spot
*/

int main(){
    Student s1(20,1);
    Student s2,s3,s4;
    cout<<Student::getTotalStudents();
}
/*
    1. we can call only static function with the class name
    2. static functions can only access static members and properties. 
    3. we have to use :: -> scope resolution operater while calling the static functions
*/

/* IMPORTANT : Static functions doesn't have this keyword because they cann't access any object*/