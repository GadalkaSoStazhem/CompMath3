//
// Created by Boss on 15.03.2023.
//

#ifndef COMPMATH3_TRAPEZOID_METHOD_H
#define COMPMATH3_TRAPEZOID_METHOD_H

#include "checker.h"
#include "functions.h"

class trapezoid_method {
public:
    double integrate(vector<double> breakpoints, double eps, function<double(double)> func, int n){
        double res = 0;

        for (int i = 0; i < breakpoints.size() - 1; i++){
            if (breakpoints.size() == 2) {
                a = breakpoints[i];
                b = breakpoints[i + 1];
            }
            else {
                if (i == 0){
                    a = breakpoints[i];
                    b = breakpoints[i + 1] - eps / 2;
                }
                else{
                    if (i + 1 == breakpoints.size() - 1){
                        a = breakpoints[i] + eps / 2;
                        b = breakpoints[i + 1];
                    }
                    else{
                        a = breakpoints[i] + eps / 2;
                        b = breakpoints[i + 1] - eps / 2;
                    }
                }
            }

            double part_res = 0;

            double h = (b - a) / n;
            part_res += (func(a) + func(b));
            for (int j = 1; j < n; j++){
                double x = a + j * h;
                part_res += (2 * func(x));
            }
            part_res *= (h / 2);
            res += part_res;
        }
        return res;
    }
    int get_n (double a, double b, double eps, function<double(double)> func){
        double maximum = max_der(a, b, eps, func);
        int n = count_n(maximum, a, b, eps);
        return n;
    }
    double get_R (double a, double b, double eps, function<double(double)> func){
        double maximum = max_der(a, b, eps, func);
        int n = count_n(maximum, a, b, eps);
        return maximum * pow((b - a), 3) / (12 * pow(n, 2));
    }
private:
    double a;
    double b;
    double max_der(double a, double b, double eps, function<double(double)> func){
        double maximum = abs((func(a + eps) - 2 * func(a) + func(a - eps)) / pow(eps, 2));
        a += eps;
        while (a < b){
            double tmp = abs((func(a + eps) - 2 * func(a) + func(a - eps)) / pow(eps, 2));
            maximum = max(maximum, tmp);
            a += eps;
        }
        return maximum;
    }
    int count_n(double maximum, double a, double b, double eps){
        int n = 1;
        while (maximum * pow(b - a, 3) / (12 * pow(n, 2)) > eps){
            n += 1;
        }
        return n;
    }

};


#endif //COMPMATH3_TRAPEZOID_METHOD_H
