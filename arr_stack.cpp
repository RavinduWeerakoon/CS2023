#include <iostream>
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
        for(int x=0; x<=top; x++){
            cout << "[" << stack_arr[x] <<" ";
        }
        cout << "]" << endl;

    }




};


int main(){

    int arr[10];
    Stack stk = Stack(10, arr);
    stk.push(10);
    stk.push(20);

    




    return 0;

}