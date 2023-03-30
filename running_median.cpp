#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
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

void quickSort(int array[], int low, int high) {
  if (low < high) {
      

    int pi = partition(array, low, high);


    quickSort(array, low, pi - 1);


    quickSort(array, pi + 1, high);
  }
}


int main(){



    vector<int> arr;
    string input;
    
    cout << "Enter your numbers seperated by white spaces and press enter: ";
    getline(cin, input);

    istringstream is(input);
    int num;

    while(is >> num)
        arr.push_back(num);



    
    int median;
    int size = arr.size();


    int num_list[size];



    for(int i=0; i<size; i++){
        num_list[i] = arr[i];
    }

    quickSort(num_list, 0, size-1);

    if(size%2==1){
        median =  num_list[size/2];

 
    }else{
        median = (num_list[size/2] + num_list[size/2 -1])/2.0;
    }

    cout << "Sorted: ";
    for(int i=0; i<size;i++){
        cout << num_list[i] << " ";
    }

    cout << endl;

    printf("Median %0.1f", (float) median);

    return 0;
}