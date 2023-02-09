#include <iostream>
#include <math.h>
#include "Trig.h"


using namespace std;

int main() {
    double x = 0;
    while(true) {
        cout << "Enter x: ";
        cin >> x;
        cout << endl;
//
//    while (x < 4 * numbers::pi) {
        cout << "Rapid Sin of " << x << ": " << RAPID::Trig::RapidSin(x) << "\n";
        cout << "CPP Sin of " << x << ": " << sin(x) << "\n";
    }
//
//        long double accuracy = RAPID::Trig::RapidSin(x) - sin(x);
//        //cout << accuracy << endl;
//        if(accuracy < -0.0001 || accuracy > 0.0001) {
//            printf("Inaccurate at: %.12f\nInaccuracy: %.12Lf\n", x, accuracy);
//            break;
//        }

        //x += 0.0000001;

    //}

    return 0;
}
