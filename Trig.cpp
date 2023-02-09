//
// Created by camde on 2/8/2023.
//

#include <iostream>
#include "Trig.h"
#include <math.h>

namespace RAPID {

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
                while(x > std::numbers::pi) {
                    x -= std::numbers::pi;
                    moves++;
                }
                while(x < 0) {
                    x += std::numbers::pi;
                    moves--;
                }
            }

            long double total = x;

            for (int i = 3; i < 100; i += 4) {


                long double diff = (-1 * ((exp(x, i)) / (factorial(i)))) + ((exp(x, i + 2)) / (factorial(i + 2)));
                if(isnan(diff) || isinf(diff)) {
                    break;
                }
                total += diff;
            }

            if( abs(moves) % 2 == 0 ) {
                return total;
            }
            else {
                return -1 * total;
            }

        }

} // RAPID