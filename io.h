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
        if (number < 1 || number > 8){
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
        switch(number){
            case 1:
                cout << "Выбранная для интегрирования функция: 7 / (x^2 + 1)" << endl;
                break;
            case 2:
                cout << "Выбранная для интегрирования функция: 1 / ln(x)" << endl;
            case 3:
                cout << "Выбранная для интегрирования функция: (x^3 - x^2) / (x - 1)" << endl;
        }
    }

};


#endif //COMPMATH3_IO_H
