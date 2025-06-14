/*Problem Statement: You have to implement Dynamic Array (vector) without using vector*/
#include<bits/stdc++.h>
using namespace std;

class DynamicArray{
    private: 
        int nextIndex;
        int capacity;
        int *array; 
    public: 
        // we have to create a new array pointer with capacity 5 at the time of creation
        // default constructor
        DynamicArray(){
            this->array = new int[5];
            capacity = 5;
            nextIndex = 0;
        }
        // parameterised constructor
        DynamicArray(int capacity){
            this->array = new int[capacity];
            this->capacity = capacity;
            nextIndex = 0;
        }
        /* we have to do pass by reference to save from unending loop of copy constructor*/
        /* we are using const because we are not changing the value of nums*/
        // copy Constructor
        DynamicArray(DynamicArray const &nums){
            // this->array = nums.array;// this will copy the same address and we have to change it to deep copy
            int *newArray = new int[nums.capacity];
            for(int i = 0;i<nums.nextIndex;i++){
                newArray[i] = nums.array[i];
            }
            this->array = newArray;
            this->capacity = nums.capacity;
            this->nextIndex = nums.nextIndex;
        }
        // copy assigment operator overloading
        void operator=(DynamicArray const &nums){
            // this->array = nums.array;// this will copy the same address and we have to change it to deep copy
            int *newArray = new int[nums.capacity];
            for(int i = 0;i<nums.nextIndex;i++){
                newArray[i] = nums.array[i];
            }
            this->array = newArray;
            this->capacity = nums.capacity;
            this->nextIndex = nums.nextIndex;
        }

        void push_back(int number){
            if(capacity == nextIndex){
                // this means array size is already reached we have to increase the size
                int *newArray = new int[this->capacity*2];
                for(int i = 0;i<nextIndex;i++){
                    newArray[i] = array[i];
                }
                /*
                * this newArray of get delete after this function all because it is locally created
                * we have to assign array pointer to it and release it memory(stored in the heap memory) also
                */
                delete[] array;
                array = newArray;
                capacity = 2*capacity;
            }
            array[nextIndex] = number;
            nextIndex++;
        }
        void pop_back(){
            if(nextIndex==0) return;
            nextIndex--;
        }
        int get(int index){
            if(index<nextIndex) return array[index];
            else return -1;
        }
        void print(){
            for(int i = 0;i<capacity;i++){
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }
        int getCapacity(){
            cout<<capacity<<endl;
        }
        int getSize(){
            cout<<nextIndex<<endl;
        }
        
};
int main(){
    DynamicArray nums;//it will call default constructor and create the array of size 5 for us;
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);

    // Now 
    DynamicArray d2(nums);
    d2.push_back(40);
    DynamicArray d3;
    d3 = d2;
    d3.push_back(50);
    
    /*
    * What happen with this senario Copy constructor calls and we know that copy constructor will always do shallow copy
    * Which means we have things in nums will exactly get copied to d2 and if we change in nums array it will also reflect 
    * in d2 array which we don't want therefore we have to implement deep copy to solve this problem
    * same this happen with copy assignment operator it also implement shallow copy 
    */
    nums.print();
    d2.print();
    d3.print();
    nums.getCapacity();
    nums.getSize();
    return 0;
}
/*
* Point to Note:
* user don't have to Initialize the size
* When the array doesn't have space it automatically doubles the size 
*/