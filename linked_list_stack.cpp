
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    

    Node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};
  
class Stack {
    Node* top;
  
public:
    Stack() { top = NULL; }
  
    void push(int data)
    {
  

        Node* temp = new Node(data);
        if (!temp) {
   
            cout << "\nStack Overflow";
            exit(1);
        }
  

        temp->data = data;
  

        temp->next = top;

        top = temp;
    }
  

    bool isEmpty()
    {

        return top == NULL;
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
  
            top = top->next;

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
  
              
                temp = temp->next;
                if (temp != NULL)
                    cout << " ";
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