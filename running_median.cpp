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

    



    cout << "Sorted\t\t\t\tMedian"<<endl;
    int median;
    int size = arr.size();
    for(int i=1; i<=size;i++){
    
      int num_list[i];

      for(int j=0; j<i; j++){
          num_list[j] = arr[j];
      }


      quickSort(num_list, 0, i-1);

      if(size%2==1){
          median =  num_list[i/2];

  
      }else{
          median = (num_list[i/2] + num_list[i/2 -1])/2.0;
      }

    
    
        cout << "[ ";
        for(int j=0; j<i;j++){
            
            cout << num_list[j]<< " ";
        }
        cout << "]";
      
      printf("\t\t\t\t%0.1f", (float) median);
      cout << endl;

    }
    return 0;

}