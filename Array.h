//
//  Array.h
//  test
//
//  Created by DANIEL SALAZAR on 9/22/17.
//  Copyright © 2017 DANIEL SALAZAR. All rights reserved.
//

#include <array>
#include <iostream>
#include <random>

using namespace std;
#define foreachU(it, a, b)      for(auto it = (a);  it != (b); ++it)
#define foreachD(it, a, b)      for(auto it = (a);  it != (b); --it)
#define forallU(i,a,b)          for(int i = (a); i < (b); ++i)
#define forallD(i,a,b)          for(int i = (a); i >= (b); --i)
#define is_sorted(a)            is_sorted((a).begin(),(a).end())
#define shuffle(a, g)           shuffle((a).begin(), (a).end(), (g))
#define MAX 1000

#ifndef Array_h
#define Array_h

class Array {
private:
    friend std::ostream& operator<< (std::ostream& os, const Array& myArray)
    {
        for (int& x : *(myArray.arr)) os << ' ' << x;
        return os;
    }
    void merge_sort(int* low, int* high);
    void q_sort(int* left, int* right);
    array<int, MAX> * arr;
    
public:
    Array();                        // default constructor
    Array(const Array &m);          // copy constructor
    Array(Array &&m);               // move constructor
    ~Array();                       // destructor
    int &At(int pos);               // get value at position pos
    int &operator [](int pos);      // operator [], equivalent to At()
    Array &operator =(Array &rhs);  // deep copy (copy assignment)
    Array &operator =(Array &&rhs); // move assignment
    
    void randomize();
    
    // Sorting
    void bubbleSort();
    void rippleSort();
    void insertionSort();
    void shellSort();
    void selectionSort();
    void mergeSort();
    void quickSort();
};

#endif /* Array_h */
