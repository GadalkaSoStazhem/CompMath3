//
// Created by Boss on 15.03.2023.
//

#ifndef COMPMATH3_FUNCTIONS_H
#define COMPMATH3_FUNCTIONS_H

#include <cmath>
#include <functional>

using namespace std;
class functions {
public:
    function <double(double)> get_function(int number){
        switch (number) {
            case 1:
                return [](double x){return 7 / (pow(x, 2) + 1);};
            case 2:
                return [](double x){return 1 / x;};
            case 3:
                return [] (double x){return (pow(x, 3) - pow(x, 2)) / (x - 1);};
            case 4:
                return [](double x){return 1 / (pow(x, 2) + x);};
            case 5:
                return [](double x){return sin(x) / x;};
            case 6:
                return [](double x){return 2 * (abs(x + 3) / (x + 3)) * x + 6;};
            case 7:
                return [](double x){return 0.08 * pow(x,4) + 0.33 * x - 0.02;};
        }
    }
    function<double(double)> get_antiderivative(int number){
        switch (number) {
            case 1:
                return [](double x){return 7 * atan(x);};
            case 2:
                return [](double x){return log(abs(x));};
            case 3:
                return [] (double x){return pow(x, 3) / 3;};
            case 4:
                return [](double x){return log(abs(x)) - log(abs(x + 1));};
            case 5:
                return NULL;
            case 6:
                return [](double x){
                    if ((x + 3) >= 0)
                        return pow(x, 2) + 6 * x;
                    else
                        return -pow(x, 2) + 6 * x;
                };
            case 7:
                return [](double x){return (2 * pow(x, 5) / 125) + (33 * pow(x, 2) / 200) - 0.02 * x;};
        }
    }
};


#endif //COMPMATH3_FUNCTIONS_H
