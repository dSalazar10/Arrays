//
//  main.cpp
//  test
//
//  Created by DANIEL SALAZAR on 9/21/17.
//  Copyright © 2017 DANIEL SALAZAR. All rights reserved.
//
// Calculate time for popular sorting algorithms on a 1000 element array

#include "Array.h"
#include "Timer.h"
#include <iostream>
#include <chrono>
#include <unistd.h>


int main(int argc, const char * argv[]) {
    ostream &out = cout;
    out << "\t\t\t\tBest Cases" << "\tAverage Cases" << "\tWorst Cases";
    
    Array a, b, c, d, e, f, g, h, i, j, k, l, m, n;
    Timer at, bt, ct, dt, et, ft, gt;
    
    out << "\nBubbleSort\t";
    // best
    forallU(i, 0, MAX) a[i] = i;
    at.resetTime();
    a.bubbleSort();
    out << "\t" << at.endTime();
    // average
    a.randomize();
    at.resetTime();
    a.bubbleSort();
    out << "\t" << at.endTime();
    // worst
    forallD(i, MAX - 1, 0) h[i] = i;
    at.resetTime();
    h.bubbleSort();
    out << "\t\t" << ct.endTime();
    
    out << "\nRippleSort\t";
    // best
    forallU(i, 0, MAX) b[i] = i;
    bt.resetTime();
    b.rippleSort();
    out << "\t" << bt.endTime();
    // average
    b.randomize();
    bt.resetTime();
    b.rippleSort();
    out << "\t" << bt.endTime();
    // worst
    forallD(x, MAX - 1, 0) i[x] = x;
    bt.resetTime();
    i.rippleSort();
    out << "\t\t" << ct.endTime();
    
    out << "\nInsertionSort";
    // best
    forallU(i, 0, MAX) c[i] = i;
    ct.resetTime();
    c.insertionSort();
    out << "\t" << ct.endTime();
    // average
    c.randomize();
    ct.resetTime();
    c.insertionSort();
    out << "\t" << ct.endTime();
    // worst
    forallD(i, MAX - 1, 0) j[i] = i;
    ct.resetTime();
    j.insertionSort();
    out << "\t\t" << ct.endTime();
    
    out << "\nShellSort\t";
    // best
    forallU(i, 0, MAX) d[i] = i;
    dt.resetTime();
    d.shellSort();
    out << "\t" << dt.endTime();
    // average
    d.randomize();
    dt.resetTime();
    d.shellSort();
    out << "\t" << dt.endTime();
    // worst
    forallD(i, MAX - 1, 0) k[i] = i;
    dt.resetTime();
    k.shellSort();
    out << "\t\t" << ct.endTime();
    
    out << "\nSelectionSort";
    // best
    forallU(i, 0, MAX) e[i] = i;
    et.resetTime();
    e.selectionSort();
    out << "\t" <<  et.endTime();
    // average
    e.randomize();
    et.resetTime();
    e.selectionSort();
    out << "\t" <<  et.endTime();
    // worst
    forallD(i, MAX - 1, 0) l[i] = i;
    et.resetTime();
    l.selectionSort();
    out << "\t\t" << ct.endTime();
    
    out << "\nMergeSort\t";
    // best
    forallU(i, 0, MAX) f[i] = i;
    ft.resetTime();
    f.mergeSort();
    out << "\t" << ft.endTime();
    // average
    f.randomize();
    ft.resetTime();
    f.mergeSort();
    out << "\t" << ft.endTime();
    // worst
    forallD(i, MAX - 1, 0) m[i] = i;
    ft.resetTime();
    m.mergeSort();
    out << "\t\t" << ct.endTime();
    
    out << "\nQuickSort\t";
    // best
    forallU(i, 0, MAX) g[i] = i;
    gt.resetTime();
    g.selectionSort();
    out << "\t" << gt.endTime();
    // average
    g.randomize();
    gt.resetTime();
    g.selectionSort();
    out << "\t" << gt.endTime();
    // worst
    forallD(i, MAX - 1, 0) n[i] = i;
    gt.resetTime();
    n.quickSort();
    out << "\t\t" << ct.endTime() << endl;
    
    //Timer t;
    //cout << "It took me " << t.endTime() << " seconds." << endl;
    return 0;
}





