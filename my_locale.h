//
// Created by Boss on 15.03.2023.
//

#ifndef COMPMATH3_MY_LOCALE_H
#define COMPMATH3_MY_LOCALE_H

#include <locale>

using namespace std;

class my_locale : public numpunct<char> {
public:
    char do_decimal_point() const {
        return ',';
    }
};


#endif //COMPMATH3_MY_LOCALE_H
