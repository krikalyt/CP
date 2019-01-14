//
// Created by krishna on 1/14/2019.
//

#ifndef HACKERRANKPB_TIMER_H
#define HACKERRANKPB_TIMER_H

#include <chrono>
class timer{
private:
    std::chrono::high_resolution_clock::time_point now;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<double> duration;
public:
    void start()
    {
        now = std::chrono::high_resolution_clock::now();
    }

    double calculatecost()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end-now;
        return duration.count();
    }
};

#endif //HACKERRANKPB_TIMER_H

