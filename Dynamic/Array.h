//
//  Array.h
//  test
//
//  Created by DANIEL SALAZAR on 9/23/17.
//  Copyright © 2017 DANIEL SALAZAR. All rights reserved.
//

#include <iostream>
#include <vector>
#include <random>
using namespace std;

#define all(a)                  (a).begin(), (a).end()
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
    friend std::ostream& operator<< (std::ostream& os, const Array& myArray)
    {
        for (auto& x : *(myArray.arr)) os << " " << x;
        return os;
    }
    void merge_sort(vector<int>::iterator low, vector<int>::iterator high);
    void q_sort(vector<int>::iterator left, vector<int>::iterator right);
    vector<int> *arr;
    
public:
    Array();                            // default constructor
    Array( int num );                   // normal constructor
    Array( const Array &m );            // copy constructor
    Array( Array &&m );                 // move constructor
    ~Array();                           // destructor
    int &At( int pos );                 // get value at position pos
    int getSize( void ) const;          // return number of elements in the array
    int &operator [](const int pos);      // operator [], equivalent to At()
    Array &operator =( Array &rhs );    // deep copy (copy assignment)
    Array &operator =( Array &&rhs );   // move assignment
    
    
    void randomize();
    void test();
    
    // Sorting
    void bubbleSort();
    void rippleSort();
    void insertionSort();
    void shellSort();
    void selectionSort();
    void mergeSort();
    void quickSort();
    
    // Searching
    vector<int>::iterator linear(int key);
    vector<int>::iterator binary(int key);
};

#endif /* Array_h */
