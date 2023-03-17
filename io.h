//
// Created by Boss on 15.03.2023.
//

#ifndef COMPMATH3_IO_H
#define COMPMATH3_IO_H

#include <iostream>

using namespace std;
class io {
public:
    int get_number(){
        int number;
        cin >> number;
        if (number < 1 || number > 7){
            cout << "Неверный номер примера" << endl;
            return NULL;
        }
        return number;
    }
    double get_accuracy(){
        double eps;
        cin >> eps;
        if (eps < 0 || eps >= 1){
            cout << "Неверная точность" << endl;
            return NULL;
        }
        return eps;
    }
    void print_function(int number){
        cout << "Выбранная для интегрирования функция: ";
        switch(number){
            case 1: {
                cout << "7 / (x^2 + 1)" << endl;
                break;
            }
            case 2: {
                cout << "1 / x" << endl;
                break;
            }
            case 3: {
                cout << "(x^3 - x^2) / (x - 1)" << endl;
                break;
            }
            case 4: {
                cout << "1 / (x^3 + 1)" << endl;
                break;
            }
            case 5: {
                cout << "sin(x) / x" << endl;
                break;
            }
            case 6:{
                cout << "2 * x * |x + 3| / (x + 3) + 6" << endl;
                break;
            }
            case 7:{
                cout << "0,08 * x^3 + 0,33 * x - 0,02" << endl;
                break;
            }

        }
    }

};


#endif //COMPMATH3_IO_H
