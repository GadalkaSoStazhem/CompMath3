//
// Created by Boss on 15.03.2023.
//

#ifndef COMPMATH3_FUNCTIONS_H
#define COMPMATH3_FUNCTIONS_H
#include <functional>
#include <cmath>
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
                return [](double x){return 1 / (pow(x, 3) + 1);};
            case 5:
                return [](double x){return sin(x) / x;};
            case 6:
                return [](double x){return 2 * (abs(x + 3) / (x + 3)) * x + 6;};
            case 7:
                return [](double x){return sin(x - 1) / (x - 1);};
            case 8:
                return [](double x){return 0.08 * pow(x,4) + 0.33 * x - 0.02;};
        }
    }
};


#endif //COMPMATH3_FUNCTIONS_H
