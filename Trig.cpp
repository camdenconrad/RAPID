//
// Created by camde on 2/8/2023.
//

#include "Trig.h"
#include <math.h>
#include <numbers>

namespace RAPID {


    //6248
    auto sins = new short[628319];
    auto coss = new short[628319];


    void Trig::release() {
        free(sins);
        free(coss);
    }

    static long double exp(double x, int ex) {
        double total = x;

        for (int i = 1; i < ex; i++) {
            total *= x;
        }

        return total;
    }

    static long double factorial(int x) {
        int total = 1;

        for (int i = 1; i <= x; i++) {
            total *= i;
        }

        return total;
    }

    long double Trig::RapidSin(double x) {

        int moves = 0;

        if (x > std::numbers::pi || x < 0) {
            while (x > std::numbers::pi) {
                x -= std::numbers::pi;
                moves++;
            }
            while (x < 0) {
                x += std::numbers::pi;
                moves--;
            }
        }

        long double total = x;

        for (int i = 3; i < 15; i += 4) {


            long double diff = (-1 * ((exp(x, i)) / (factorial(i)))) + ((exp(x, i + 2)) / (factorial(i + 2)));

            if (isnan(diff) || isinf(diff)) {
                break;
            }
            total += diff;
        }

        if (abs(moves) % 2 == 0) {
            return total;
        } else {
            return -1 * total;
        }

    }

    long double Trig::RapidCos(double x) {

        int moves = 0;

        if (x > std::numbers::pi || x < 0) {
            while (x > std::numbers::pi) {
                x -= std::numbers::pi;
                moves++;
            }
            while (x < 0) {
                x += std::numbers::pi;
                moves--;
            }
        }

        long double total = 1;

        for (int i = 2; i < 15; i += 4) {


            long double diff = (-1 * ((exp(x, i)) / (factorial(i)))) + ((exp(x, i + 2)) / (factorial(i + 2)));

            if (isnan(diff) || isinf(diff)) {
                break;
            }
            total += diff;
        }

        if (abs(moves) % 2 == 0) {
            return total;
        } else {
            return -1 * total;
        }
    }

    float Trig::RSin(double x) {
        while (x < 0 && x < 6.248) {
            x += 2 * std::numbers::pi;
        }
        while (x > 6.248 && x > 0) {
            x -= 2 * std::numbers::pi;
        }
        return (float) sins[(int) (x * 100000)] / (float) 10000.;
    }

    double Trig::RCos(double x) {
        while (x < 0 && x < 6.248) {
            x += 2 * std::numbers::pi;
        }
        while (x > 6.248 && x > 0) {
            x -= 2 * std::numbers::pi;
        }
        return (float) coss[(int) (x * 100000)] / (float) 10000. ;
    }


    void Trig::precompute() {
        double x = 0;

        for (int i = 0; i < 314159; i++) {
            sins[i] = RapidSin(x) * 10000;
            x += 0.00001;
        }

        x = 0;
        for (int i = 314159; i < 628319; i++) {
            sins[i] = RapidSin(x) * -10000;
            x += 0.00001;
        }

        x = 0;
        for (int i = 0; i < 314159; i++) {
            coss[i] = RapidCos(x) * 10000;
            x += 0.00001;
        }

        x = 0;
        for (int i = 314159; i < 628319; i++) {
            coss[i] = RapidCos(x) * -10000;
            x += 0.00001;
        }



    }

    Trig::~Trig() {
        free(sins);
        free(coss);
    }

    Trig::Trig() {
        precompute();
    }
    // RAPID
}