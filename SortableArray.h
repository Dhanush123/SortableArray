// Programmer: Dhanush Patel
// Programmer's ID: 1553428

#ifndef DynamicArray_h
#define DynamicArray_h

#include <algorithm>
using namespace std;

template <typename V>
class SortableArray
{
  V* values;
  int cap;
  V dummy;

  public:
  SortableArray(int=2);
  SortableArray(const SortableArray<V>&);
  ~SortableArray(){delete [] values;}
  int capacity() const {return cap;}
  void capacity(int);
  V operator[](int) const;
  V& operator[](int);
  SortableArray<V>& operator=(const SortableArray<V>&);
  void sort(int);
};

template <typename V>
SortableArray<V>::SortableArray(int cap)
{
  this->cap = cap;
  values = new V[cap];

  for (int index = 0; index < cap; index++){
    values[index] = V();
  }
}

template <typename V>
V SortableArray<V>::operator[](int index) const
{
  if (index < 0 || index >= cap)
    return V(); // a copy
  return values[index]; // a copy
}

template <typename V>
V& SortableArray<V>::operator[](int index)
{
  if (index < 0){
    return dummy; // a copy
  }
  else if (index >= cap){
    capacity(2 * index);
  }
  return values[index]; // a copy
}

template <typename V>
void SortableArray<V>::capacity(int newCap){
  V* temp = new V[newCap];

  // get the lesser of the new and old capacities
  int limit = min(newCap,cap);

  // copy the contents
  for (int i = 0; i < limit; i++){
   temp[i] = values[i];
  }

  // set added values to their defaults
  for (int i = limit; i < cap; i++){
   temp[i] = V();
  }

  // deallocate original array
  delete [] values;

  // switch newly allocated array into the object
  values = temp;

  // update the capacity
  cap = newCap;
}

template <typename V>
SortableArray<V>::SortableArray(const SortableArray<V>& original)
{
  cap = original.cap; // still copy
  values = new V[cap]; // not copy, is new
  for (int i = 0; i < cap; i++){ // contents copy original to new
    values[i] = original.values[i];
  }
}

template <typename V>
SortableArray<V>& SortableArray<V>::operator=(const SortableArray<V>& original)
{
  if (this != &original) //check if copy or not, better not be tho
  {
    // same as destructor
    delete [] values;

    // same as copy constructor
    cap = original.cap;
    values = new V[cap]; // not copy, is new
    for (int i = 0; i < cap; i++){ // contents copy original to new
      values[i] = original.values[i];
    }
  }
  return *this; // return self reference
}

template <typename V>
void SortableArray<V>::sort(int endIndex)
{
  int* temp = new int[endIndex];
  for (int delta = 1; delta < endIndex; delta *= 2)
  {
    int index = 0;
    for (int i = 0; i < endIndex; i++) temp[i] = values[i];
    for (int i = 0; i < endIndex; i += 2 * delta)
    {
      int left = i;
      int leftMax = min(left + delta, endIndex);
      int right = leftMax;
      int rightMax = min(right + delta, endIndex);
      while (true)
      {
        if (left == leftMax && right == rightMax) break;
        if (left == leftMax) values[index++] = temp[right++];
        else if (right == rightMax) values[index++] = temp[left++];
        else if (temp[right] < temp[left]) values[index++] = temp[right++];
        else values[index++] = temp[left++];
      }
    }
  }
}

#endif
