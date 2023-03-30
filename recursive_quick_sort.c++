#include <iostream>
using namespace std;

#include <chrono>

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}


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

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}


int main() {

    cout << "recursive\n";
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
        quickSort(data, 0, n - 1);

        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop-start);


        cout << duration.count()<<endl;

    }
  





  
}