#include "checker.h"
#include "functions.h"
#include "io.h"
#include "my_locale.h"
#include "trapezoid_method.h"

#include <ctime>
#include <iostream>

using namespace std;

int main() {
    locale out_comma (cout.getloc(), new my_locale);
    cout.imbue(out_comma);
    locale in_comma (cin.getloc(), new my_locale);
    cin.imbue(in_comma);

    io io;
    functions f;
    checker check;
    trapezoid_method tr;
    cout << "Выберите функцию для интегрирования от 1 до 7" << endl;
    int number = io.get_number();
    auto func = f.get_function(number);
    io.print_function(number);
    cout << "Введите границы интегрирования" << endl;
    double a, b;
    cin >> a >> b;
    int sign = check.sign(a, b);
    if (sign == -1){
        double tmp = a;
        a = b;
        b = tmp;
    }

    cout << "Введите точность вычислений" << endl;
    double eps = io.get_accuracy();

    vector<double> brs = check.function_break(a, b, eps, func);

    if (check.flag){
        clock_t begin = clock();
        double result = tr.integrate(brs, eps, func);
        double time = (clock() - begin) / (double) CLOCKS_PER_SEC;
        cout << "Результат вычисления интеграла: " << round(result / eps) * eps << endl;
        double r = tr.get_R(a, b, eps, func);
        cout << "Погрешность квадратурной формулы на [" << a << ", " << b << "]: R = " << r << endl;
        cout << "Время выполнения метода: " << time << endl;
    }

    return 0;
}
