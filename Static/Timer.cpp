//
//  Timer.cpp
//  test
//
//  Created by DANIEL SALAZAR on 9/23/17.
//  Copyright © 2017 DANIEL SALAZAR. All rights reserved.
//

#include "Timer.h"

Timer::Timer(): start(steady_clock::now()) {}

void Timer::resetTime()
{
    start = steady_clock::now();
}
double Timer::endTime()
{
    end = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(end - start);
    return time_span.count();
}
