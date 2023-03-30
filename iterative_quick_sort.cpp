// An iterative implementation of quick sort
#include <bits/stdc++.h>
using namespace std;
  

  
int partition(int array[], int low, int high) {
    
  int pivot = array[high];
  
  int i = (low - 1);


  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(array[i], array[j]);
    }
  }
  

  swap(array[i + 1], array[high]);
  

  return (i + 1);
}
  

void quickSortIterative(int arr[], int l, int h)
{

    int stack[h - l + 1];
  

    int top = -1;
  
 
    stack[++top] = l;
    stack[++top] = h;
  

    while (top >= 0) {

        h = stack[top--];
        l = stack[top--];
        int p = partition(arr, l, h);
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
  

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
  
int main() {

    cout << "Iterative\n";
    int sizes[] = {100, 500, 1000, 5000, 10000};

    for(int i=0; i<5; i++){

        int size = sizes[i];
        int data[size];
        for(int j=0; j<size; j++){
            data[j] = rand()%100;
            }

        int n = sizeof(data) / sizeof(data[0]);
        
        cout << "size is" << size<<endl;

        auto start = chrono::high_resolution_clock::now();
        quickSortIterative(data, 0, n - 1);

        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop-start);


        cout << duration.count()<<endl;

    }
  
  // perform quicksort on data




  
}