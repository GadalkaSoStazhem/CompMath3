//
// Created by Boss on 15.03.2023.
//

#ifndef COMPMATH3_CHECKER_H
#define COMPMATH3_CHECKER_H

#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
class checker {
public:
    bool flag = true;
    vector <double> function_break(double a, double b, double eps, function <double(double)> func){
        vector <double> breakpoints;
        breakpoints.push_back(a);
        while (a < b){
            if (isnan(func(round(a / eps) * eps)) == true) {
                cout << "epta" << endl;
                if (is_removable(func, a - eps, a + eps, eps)){
                    cout << "is " << endl;
                    breakpoints.push_back(round(a / eps) * eps);
                }
                else {
                    cout << "На интервале интегрирования есть неустранимый разрыв 1 рода " << endl;
                    flag = false;
                }

            }
            if (isinf((func(round(a / eps) * eps)))) {
                cout << "Разрыв 2 рода" << endl;
                flag = false;
            }
            //cout << a << " " << func(round(a / eps) * eps ) << endl;
            //cout << a << " " << func(a ) << endl;
            a += eps;
        }
        breakpoints.push_back(b);
        //cout << breakpoints[0] << " " << breakpoints.size() << endl;

        return breakpoints;
    }
private:
    bool is_removable(function <double(double)> f, double left, double right, double eps){
        if (abs(abs(f(left) - f(right))  / 2 - abs(f(right + eps) - f(right))) <= eps)
            return true;
        return false;
    }

};


#endif //COMPMATH3_CHECKER_H
