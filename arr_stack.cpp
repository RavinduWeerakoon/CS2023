#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Stack{
private:
    int top=-1;
    int *stack_arr;
    int size;

public:

    Stack(int length, int arr[]){
        
        
        size = length;
        stack_arr = arr;
      

    }

    void push(int item){

        if(top==size-1){
            cout << "Error Stack Overflow";
            return;
        }
        ++top;

        stack_arr[top] = item;
        
       

              
    }

    void pop(){

        if(top==-1){
            cout << "Stack Underflow";
            return;
        }
        
        cout << *(stack_arr+top)<<endl;
        --top;
       


    }

    void display(){
        cout << "[";
        for(int x=0; x<=top; x++){
            cout <<  stack_arr[x] <<" ";
        }
        cout << "]" << endl;

    }




};




int main() {



    auto start = chrono::high_resolution_clock::now();
    int size = 10; //specifiy the size of the file
    int arr[size];
    Stack stk = Stack(size, arr);

    for(int i=0; i<5;i++){
        stk.push(rand()%100);
    }
 
    stk.display();
    for(int j=0;j<3;j++){
        stk.pop() ;
    }
    stk.display();
    stk.push(4);
    stk.push(30);
    stk.push(3);
    stk.push(1);
    stk.display();

        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop-start);


        cout <<"Time "<< duration.count()<<endl;
    return 0;

    }