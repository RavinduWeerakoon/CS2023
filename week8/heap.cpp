#include <iostream>
#include <bits/stdc++.h>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int left = 2 * root +1;
   int right = 2 * root +2;

   int largest = root;

   if(left<n && arr[left]>arr[largest]){ 
      largest = left;
      }

   if(right<n && arr[right]>arr[largest]) {
      largest = right;
      }

   if(largest != root){
      swap(arr[root], arr[largest]);

      heapify(arr, n, largest);
   }
  
   
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
  
// implementing heap sort
void heapSort(int arr[], int n)
{

   //create the heap
   for(int i=n/2 -1; i>=0; i--){
      heapify(arr, n, i);
   }

   
  
   
      //select the maximum items iteratively and swap them to the end
       for (int i = n - 1; i > 0; i--) {
 
   
        swap(arr[0], arr[i]);
 
        
        heapify(arr, i, 0);
    }
   
}
  

// main program
int main()
{
   
   
   //create a vector to store the user inputs
   vector<int> arr;
   string input;
    
    cout << "Enter your numbers seperated by white spaces and press enter: ";
    getline(cin, input);
   //conveting the numbers into a string stream
    istringstream is(input);
    int num;

    while(is >> num)
        arr.push_back(num);
   int n = arr.size();

   int heap_arr[n];

   for(int i=0; i<n;i++){
      heap_arr[i] = arr[i];
   }
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
   return 0;
}