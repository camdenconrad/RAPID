#include <iostream>
#include <cmath>
#include <numbers>
#include <chrono>
#include "Trig.h"


long double roundTo(long double value, double precision);

long double difference(long double x, long double y);

using namespace std;
using namespace RAPID;

int main() {
    //int k;

    auto begin = std::chrono::high_resolution_clock::now();
    RAPID::Trig::precompute();

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Setup time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms"
              << std::endl;

    begin = std::chrono::high_resolution_clock::now();
//    for(int z = 0; z < 5000000; z++) {
//        for (int i = -16 * numbers::pi; i < 16 * numbers::pi; i++) {
//            Trig::RSin(i);
//            //cout << Trig::O1Sin(i) << endl;
//        }
//    }
    Trig::RSin(2 * numbers::pi);


    end = std::chrono::high_resolution_clock::now();
    printf("%lld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count());

    long double timeOne = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

    begin = std::chrono::high_resolution_clock::now();
//    for(int z = 0; z < 5000000; z++) {
//        for (int i = -16 * numbers::pi; i < 16 * numbers::pi; i++) {
//            sin(i);
//            //cout << sin(i) << endl;
//        }
//    }
    sin(2 * numbers::pi);


    end = std::chrono::high_resolution_clock::now();
    printf("%lld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count());

    long double timeTwo = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

    printf("Percent difference: %.2Lf\%\n", difference(timeOne, timeTwo));
    printf("Percent difference: %.2Lfx faster\n", timeTwo / timeOne);

    Trig::release();

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

long double roundTo(long double value, double precision) {
    return std::round(value / precision) * precision;
}

long double difference(long double x, long double y) {

    return (abs(x - y) / ((x + y) / 2)) * 100;
}
