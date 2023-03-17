//
// Created by Boss on 15.03.2023.
//

#ifndef COMPMATH3_TRAPEZOID_METHOD_H
#define COMPMATH3_TRAPEZOID_METHOD_H

#include "checker.h"
#include "functions.h"

class trapezoid_method {
public:
    double integrate(vector<double> breakpoints, double eps, function<double(double)> func){
        double res = 0;
        for (int i = 0; i < breakpoints.size() - 1; i++){
            double part_res = 0;
            double maximum = max_der(breakpoints[i], breakpoints[i + 1], eps, func);
            //cout << "max " << maximum << endl;
            int n = count_n(maximum, breakpoints[i], breakpoints[i + 1], eps);
            //cout << "n " << n << endl;
            double h = (breakpoints[i + 1] - breakpoints[i]) / n;
            //cout << "h " << h << endl;
            double a = breakpoints[i];
            double b = breakpoints[i + 1];

            //int nn = find_n(eps, a, b);
            //cout <<"n " << nn << endl;
            //double hh = (b - a) / nn;
            //cout << "h " << hh << endl;
            part_res += func(a);
            part_res += func(b);
            double to_mul = 0;
            for (int j = 1; j < n; j++){
                double x = a + j * h;
                //cout << j<<" "<<x<< " f(x) " << func(x) <<endl;
                to_mul += func(x);
            }
            to_mul *= 2;
            part_res += to_mul;
            part_res *= (h / 2);
            res += part_res;
        }
        return res;
    }
private:
    double count_h (double a, double b, double eps, function<double(double)> func){
        double h = eps / (func(b) - func(a));
        return h;
    }
    int find_n(double eps, double a, double b){
        return ceil((b - a) / eps);
    }
    double max_der(double a, double b, double eps, function<double(double)> func){
        double maximum = (func(a + eps) - 2 * func(a) + func(a - eps)) / (eps * eps);
        a += eps;
        //cout << "tmp " << maximum << endl;
        //cout << "part " << func(a + eps) << " part " << 2 * func(a) << " part "<<func(a - eps)<<endl;
        while (a < b){
            double tmp = (func(a + eps) - 2 * func(a) + func(a - eps)) / pow(eps, 2);
            //cout << "tmp " << tmp << endl;
            //cout << "part " << func(a + eps) << " part " << 2 * func(a) << " part "<<func(a - eps)<<endl;
            maximum = max(maximum, tmp);
            a += eps;
        }
        return maximum;
    }
    int count_n(double maximum, double a, double b, double eps){
        int n = 1;
        //cout << "smth " << maximum * pow(b - a, 3) / (12 * pow(n, 2)) << endl;
        while (maximum * pow(b - a, 3) / (12 * pow(n, 2)) > eps){
            n += 1;
        }
        return n;
    }

};


#endif //COMPMATH3_TRAPEZOID_METHOD_H
