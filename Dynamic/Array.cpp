//
//  Array.cpp
//  test
//
//  Created by DANIEL SALAZAR on 9/23/17.
//  Copyright © 2017 DANIEL SALAZAR. All rights reserved.
//

#include "Array.h"

Array::Array()
{
    arr = new vector<int>(10, 0);
}
Array::Array(int num)
{
    if(num <= 0)
    {
        num = 10;
    }
    arr = new vector<int>(num, 0);
}
Array::Array(const Array &m)
{
    arr = new vector<int>(all(*(m.arr)));
}
Array::Array(Array &&m)
{
    arr = m.arr;
    m.arr = nullptr;
}
Array::~Array()
{
    if(arr != nullptr)
    {
        delete[] arr;
    }
}
int& Array::operator [](const int pos)
{
    if(pos >= arr->size())
        arr->resize(pos + 1);
    return arr[pos];
}
Array &Array::operator =(Array &rhs)
{
    if( &rhs == this )
        return *this;
    if(rhs.arr->size() != arr->size())
    {
        delete[] arr;
        arr = new vector<int>(all(*(rhs.arr)));
    }
    forallU(i, 0, arr->size())
        arr[i] = rhs.arr[i];
    return *this;
}
Array &Array::operator =( Array &&rhs )
{
    if( &rhs == this )
        return *this;
    if( arr != nullptr)
        delete[] arr;
    arr = rhs.arr;
    rhs.arr = nullptr;
    return *this;
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
void Array::merge_sort(vector<int>::iterator low, vector<int>::iterator high)
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
void Array::q_sort(vector<int>::iterator left, vector<int>::iterator right)
{
    int pivot = *left;
    vector<int>::iterator l_hold = left, r_hold = right, pivot_pos;
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

// Searching

/*
 Best case: Ω(1)
 Worst case: O(n)
 Average case: Θ(n)
 */
vector<int>::iterator Array::linear(int key)
{
    foreachD(i, arr->begin(), arr->end())
    if (key == *i)
        return i;
    return arr->end();
}
/*
 Best case: Ω(1)
 Worst case: O(log n)
 Average case: Θ(log n)
 */
vector<int>::iterator Array::binary(int key)
{
    vector<int>::iterator low = arr->begin(), high = arr->end();
    while(high >= low)
    {
        auto mid = arr->begin() + distance(low, high) / 2;
        if (key < *mid)
            high = mid - 1;
        else if (key > *mid)
            low = mid + 1;
        else
            return mid;
    }
    return arr->end();
}
// Mix up array for use in testing sort algorithms
void Array::randomize()
{
    random_device rd;
    mt19937 g(rd());
    shuffle(*(arr), g);
}

void Array::test()
{
    int choice, item;
    bool done = false;
    while(!done)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"Vector Implementation in Stl"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the Vector"<<endl;
        cout<<"2.Delete Last Element of the Vector"<<endl;
        cout<<"3.Size of the Vector"<<endl;
        cout<<"4.Display by Index"<<endl;
        cout<<"5.Dislplay by Iterator"<<endl;
        cout<<"6.Clear the Vector"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter value to be inserted: ";
                cin>>item;
                arr->push_back(item);
                break;
            case 2:
                cout<<"Delete Last Element Inserted:"<<endl;
                arr->pop_back();
                break;
            case 3:
                cout<<"Size of Vector: ";
                cout << arr->size() << endl;
                break;
            case 4:
                cout<<"Displaying Vector by Index: ";
                cout << arr;
                cout << endl;
                break;
            case 5:
                cout<<"Displaying Vector by Iterator: ";
                foreachU(i, arr->begin(), arr->end())
                    cout << " " << *i;
                cout << endl;
                cout<<endl;
                break;
            case 6:
                arr->clear();
                cout<<"Vector Cleared"<<endl;
                break;
            default:
                done = true;
                break;
        }
    }
}





















