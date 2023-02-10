//
// Created by camde on 2/8/2023.
//

#ifndef RAPID_TRIG_H
#define RAPID_TRIG_H

namespace RAPID {
    class Trig {

    public:
        static long double RapidSin(double x);

        static long double RapidCos(double x);

        static void precompute();

        static double RSin(double x);

        virtual ~Trig();

        static void release();

        double RCos(double x);
    };

} // RAPID

#endif //RAPID_TRIG_H
