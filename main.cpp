#include <iostream>
#include <cmath>
#include <numbers>
#include "Trig.h"


long double roundTo(long double value, double precision);

using namespace std;
using namespace RAPID;

int main() {
    //int k;

    RAPID::Trig::precompute();

    auto begin = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 2 * numbers::pi; i += 1) {
        Trig::O1Sin(i);
    }
    for(int i = 0; i < 2 * numbers::pi; i += 1) {
        Trig::O1Sin(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " ns" << std::endl;

    begin = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 2 * numbers::pi; i += 1) {
        sin(i);
    }

    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " ns" << std::endl;

    //cin >> k;
//    double x = 0;
//    while(true) {
//        cout << "Enter x: ";
//        cin >> x;
//        cout << endl;
////
////    while (x < 4 * numbers::pi) {
//        long double rV = roundTo(RAPID::Trig::RapidSin(x), 0.0001);
//        long double cV = roundTo(sin(x), 0.0001);
//
//        cout << "Rapid Sin of " << x << ": " << rV << " Rads\n";
//        cout << "CPP   Sin of " << x << ": " << cV << " Rads\n";
//
//        cout << "In degrees: " << rV * (180./numbers::pi) << endl;
//
//        long double difference = (abs(rV - cV) / ((rV + cV) / 2)) * 100;
//
//        printf("Percent Difference = %.2Lf \%\n\n", difference);
//
//        long double rC = roundTo(RAPID::Trig::RapidCos(x), 0.0001);
//        long double cC = roundTo(cos(x), 0.0001);
//
//        cout << "Rapid Cos of " << x << ": " << rC << " Rads\n";
//        cout << "CPP   Cos of " << x << ": " << cC << " Rads\n\n";
//
//        cout << "Rapid Tan of " << x << ": " << rV / rC << endl;
//        cout << "CPP   Tan of " << x << ": " << tan(x) << endl;


   // }
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

long double roundTo(long double value, double precision)
{
    return std::round(value / precision) * precision;
}
