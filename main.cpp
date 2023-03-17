#include "checker.h"
#include "io.h"
#include "functions.h"
#include "trapezoid_method.h"
#include <iostream>

using namespace std;

int main() {
    io io;
    functions f;
    checker check;
    trapezoid_method tr;
    cout << "Выберите функцию для интегрирования от 1 до 6" << endl;
    int number = io.get_number();
    /*if(1/tan(0) == INFINITY){
        cout << "hoho" << endl;
    }
    cout << log(-1) << endl;*/
//inf -inf nan
    cout << "Введите границы интегрирования" << endl;
    double a, b;
    cin >> a >> b;
    auto ff = f.get_function(number);
    cout << "Введите точность вычислений" << endl;
    double eps = io.get_accuracy();
    //double br = check.function_break(a, b, eps, ff);
    //cout << br;
    vector<double> brs = check.function_break(a, b, eps, ff);
    //cout << brs[0] << " " << brs[1] << " " << brs[2] << endl;
    //function<double(double)> x = [](double x){return sin(x-1)/ (x-1);};
    //cout << x(1) << endl;
    /*double i = 0;
    while (i < 2){
        cout <<"hoho " << ff(i) <<"jops " << ff(i - 0) << " " << ff(i + 0) << endl;
        double dr = ff(round(i / eps) * eps ) ;
        cout<<"der "<< dr<<endl;
        i += 0.1;
    }*/
    if (check.flag == true){
        double r = tr.integrate(brs, eps, ff);
        cout <<"res " <<  r << endl;
    }
    //cout<<ff(2)<<endl;
    //cout << sin(0)/0 << endl;
    //auto x = [](double x){return 1/(x*x*x + 1);};
    //cout << x(-1) << endl;
    return 0;
}
