// Programmer: Dhanush Patel
// Programmer's ID: 1553428

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include<cstdlib>

#include "SortableArray.h"

const bool PLACED = true;

int main(){
  cout << "Programmer: Dhanush Patel\n";
  cout << "Programmer's ID: 1553428\n";
  cout << "File: " << __FILE__ << endl;
  cout << endl;

  SortableArray<double> valStore;
  SortableArray<bool> storeStatus;
  int storeTotal = 0;
  string index;
  string value;

  do{
    cout << "Input an index and a value [Q to quit]: ";
    cin >> index;
    if(index == "Q" || index == "q"){
      break;
    }

    cin >> value;
    cin.ignore(1000,10);
    valStore[atof(index.c_str())] = atof(value.c_str());
    storeStatus[atof(index.c_str())] = PLACED;
  }while(index != "Q" || index != "q");
  cout << endl;

  for(int i = 0; i < storeStatus.capacity(); i++){
    if(storeStatus[i] == PLACED){
      storeTotal++;
    }
  }
  cout << "You stored this many values: " << storeTotal << endl;

  cout << "The index-value pairs are:" << endl;
  for(int i = 0; i < storeStatus.capacity(); i++){
    if(storeStatus[i] != 0){
      cout << i << "=>" << valStore[i] << " ";
    }
  }
  cout << endl;

  SortableArray<double> valStore2 = valStore;

  string endI;
  cout << "Input max index to sort up to: ";
  cin >> endI;
  valStore.sort(atoi(endI.c_str()));
  cout << endl;
  cout << "The sorted index-value pairs are:" << endl;
  for(int i = 0; i < storeStatus.capacity(); i++){
    if(storeStatus[i] != 0){
      cout << i << "=>" << valStore[i] << " ";
    }
  }
  cout << endl;

  do{
    cout << "Input an index and a value [Q to quit]: ";
    cin >> index;
    if(index == "Q" || index == "q"){
      break;
    }
    else if(atof(index.c_str()) >=0 && atof(index.c_str()) < valStore.capacity()){
      for(int i = 0; i < valStore2.capacity(); i++) {
        if (valStore2[i] == valStore[atoi(index.c_str())] && storeStatus[i] == PLACED) {
          double valFind = valStore[atoi(index.c_str())];
          cout << "Found it -- the value stored at " << index << " is " << valFind << "\n";
          break;
        }
      }
    }
    else{
      cout << "I didn't find it\n";
    }
  }while(index != "Q" || index != "q");
}
