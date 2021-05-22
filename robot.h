#ifndef ROBOT_H
#define ROBOT_H


#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cassert>

#define PI 3.1415926


class Robot {
private:
    int const& dofs_;
    void Validate_() { 
        if (dofs_ <= 0)
            throw std::invalid_argument("WRONG DEGREES OF FREEDOM \n");
    }
        
public:
    Robot (int& dofs) : dofs_(dofs) { Validate_(); }
    struct dhparameters
    {
        std::vector<double> theta;
        std::vector<double> d;
        std::vector<double> alpha;
        std::vector<double> a;
    };
    int const& GetDofs() { return dofs_; }

    std::vector<double> InitRobot();
    
};

#endif