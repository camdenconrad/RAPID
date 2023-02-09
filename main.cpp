#include <iostream>
#include <math.h>
#include "Trig.h"


double roundTo(long double sin, double d);

using namespace std;

int main() {
    double x = 0;
    while(true) {
        cout << "Enter x: ";
        cin >> x;
        cout << endl;
//
//    while (x < 4 * numbers::pi) {
        double rV = roundTo(RAPID::Trig::RapidSin(x), 0.0001);
        double cV = roundTo(sin(x), 0.0001);

        cout << "Rapid Sin of " << x << ": " << rV << " Rads\n";
        cout << "CPP   Sin of " << x << ": " << cV << " Rads\n";

        cout << "In degrees: " << rV * (180./numbers::pi) << endl;

        double difference = (abs(rV - cV) / ((rV + cV) / 2)) * 100;

        printf("Percent Difference = %.2f \%\n", difference);
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

double roundTo(long double value, double precision)
{
    return std::round(value / precision) * precision;
}
