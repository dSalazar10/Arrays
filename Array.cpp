//
//  Array.cpp
//  test
//
//  Created by DANIEL SALAZAR on 9/22/17.
//  Copyright © 2017 DANIEL SALAZAR. All rights reserved.
//

#include "Array.h"
// default to an array of 100 integers, fill with 0
Array::Array()
{
    arr = new array<int, MAX>();
    arr->fill(0);
}
// copy constructor - deep copy assignment
Array::Array(const Array &m)
{
    arr = new array<int, MAX>();
    forallU(i, 0, m.arr->size()) arr[i] = m.arr[i];
}
// move constructor - move data from parameter, don't copy it
Array::Array(Array &&m)
{
    arr = m.arr;
    m.arr = nullptr;
}
// destructor - needed to deallocate RAM allocated in constructors
// unless moved in move constructor or move assignment
Array::~Array()
{
    if(arr != nullptr) delete[] arr;
}
// get value at position pos
int &Array::At(int pos)
{
    if( pos < 0 || pos >= MAX )
    {
        cout << "Illegal index, pos = " << pos << endl;
        exit( -1 );
    }
    return arr->at(pos);
}

// get value at position pos using [] indexing operator
int & Array::operator [](int pos)
{
    if( pos < 0 || pos >= MAX )
    {
        cout << "Illegal index, pos = " << pos << endl;
        exit( -1 );
    }
    return arr->at(pos);
}
// deep copy - REQUIRED if allocated RAM is used by object!
// copy assignment
Array &Array::operator =(Array &rhs)
{
    if(&rhs == this) return *this;
    forallU(i, 0, rhs.arr->size()) arr[i] = rhs.arr[i];
    return *this;
}
// move assignment
Array &Array::operator =(Array &&rhs)
{
    if(&rhs == this) return *this;
    if(arr != nullptr) delete[] arr;
    arr = rhs.arr;
    rhs.arr = nullptr;
    return *this;
}
// Mix up array for use in testing sort algorithms
void Array::randomize()
{
    random_device rd;
    mt19937 g(rd());
    shuffle(*(arr), g);
}

// Sorting

/*
 Best case: Ω(n)
 Worst case: O(n^2)
 Average case: Θ(n^2)
 */
void Array::bubbleSort()
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        foreachU(i, arr->begin(), arr->end() - 1)
        {
            if(*i > *(i + 1))
            {
                swap(*i, *(i + 1));
                sorted = false;
            }
        }
    }
}
/*
 Best case: O(n)
 Worst case: O(n^2)
 Average case: O(n^2)
 */
void Array::rippleSort()
{
    foreachU(i, arr->begin(), arr->end())
        foreachU(j, i + 1, arr->end())
            if (*i > *j)
                swap(*i, *j);
}
/*
 Best case: Ω(n)
 Worst case: O(n^2)
 Average case: Θ(n^2)
 */
void Array::insertionSort()
{
    foreachU(i, arr->begin() + 1, arr->end())
        foreachD(j, i, arr->begin())
            if(*(j - 1) > *j)
                swap(*j, *(j - 1));
}
/*
 Best case: Ω(n log(n))
 Worst case: O(n(log(n))^2)
 Average case: Θ(n(log(n))^2)
 */
void Array::shellSort()
{
    for(auto h = arr->begin() + arr->size() / 2; h != arr->begin(); advance(h, (distance(h, arr->begin()) - 1) / 2))
    {
        foreachU(i, h, arr->end())
        {
            for(auto j = i; j >= h; advance(j, distance(h, arr->begin())))
            {
                auto gap = distance(arr->begin(), h);
                if(*(j - gap) > *j)
                {
                    swap(*j, *(j - gap));
                }
            }
        }
    }
}
/*
 Best case: Ω(n^2)
 Worst case: O(n^2)
 Average case: Θ(n^2)
 */
void Array::selectionSort()
{
    foreachU(i, arr->begin(), arr->end())
    {
        auto min = i;
        foreachU(j, i + 1, arr->end())
            if (*j < *min)
                min = j;
        if(min != i)
            swap(*min, *i);
    }
}
// Merge Sort Helper
void Array::merge_sort(int* low, int* high)
{
    if(low >= high) return;
    auto mid = low + (distance(low, high)) / 2;
    merge_sort(low, mid);
    merge_sort(mid + 1, high);
    std::sort (low,mid);
    std::sort (mid+1,high);
    inplace_merge(low, mid + 1, high + 1);
}
/*
 Best case: Ω(n log(n))
 Worst case: O(n log(n))
 Average case: Θ(n log(n))
 */
void Array::mergeSort()
{
    merge_sort(arr->begin(), arr->end() - 1);
}
// Quick Sort Helper
void Array::q_sort(int* left, int* right)
{
    int pivot = *left;
    int *l_hold = left, *r_hold = right, *pivot_pos;
    while (left < right)
    {
        while( (left < right) && (*right >= pivot) )
            right--;
        if( left != right )
        {
            *left = *right;
            left++;
        }
        while( (left < right) && (*left <= pivot) )
            left++;
        if (left != right)
        {
            *right = *left;
            right--;
        }
    }
    *left = pivot;
    pivot_pos = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot_pos)
        q_sort(left, pivot_pos-1);
    if (right > pivot_pos)
        q_sort(pivot_pos+1, right);
}
/*
 Best case: Ω(n log(n))
 Worst case: O(n^2)
 Average case: Θ(n log(n))
 */
void Array::quickSort()
{
    q_sort(arr->begin(), arr->end() - 1);
}




