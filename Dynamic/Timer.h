//
//  Timer.h
//  test
//
//  Created by DANIEL SALAZAR on 9/23/17.
//  Copyright © 2017 DANIEL SALAZAR. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

#ifndef Timer_h
#define Timer_h

class Timer {
    steady_clock::time_point start;
    steady_clock::time_point end;
    
public:
    Timer();
    void resetTime();
    double endTime();
};

#endif /* Timer_h */
