// C++ program to Implement a stack
// using singly linked list
#include <bits/stdc++.h>
using namespace std;
  
// creating a linked list;
class Node {
public:
    int data;
    Node* link;
    
    // Constructor
    Node(int n)
    {
        this->data = n;
        this->link = NULL;
    }
};
  
class Stack {
    Node* top;
  
public:
    Stack() { top = NULL; }
  
    void push(int data)
    {
  
        // Create new node temp and allocate memory in heap
        Node* temp = new Node(data);
  
        // Check if stack (heap) is full.
        // Then inserting an element would
        // lead to stack overflow
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }
  

        temp->data = data;
  

        temp->link = top;

        top = temp;
    }
  

    bool isEmpty()
    {

        return top == NULL;
    }

    int peek()
    {

        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }
  

    void pop()
    {
        Node* temp;
  

        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
  

            temp = top;
  
            top = top->link;

            free(temp);
        }
    }
  

    void display()
    {
        Node* temp;
  
        if (top == NULL) {
            cout << "\nStack Underflow";
            exit(1);
        }
        else {
            temp = top;
            while (temp != NULL) {
  
                
                cout << temp->data;
  
              
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};
  
int main() {



    auto start = chrono::high_resolution_clock::now();
    
    Stack stk = Stack();

    for(int i=0; i<5000;i++){
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