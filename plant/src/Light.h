#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <BH1750.h>
#include <Wire.h>

class Light {
    private:
        /* data */
        BH1750 lightMeter;
        int sda;
        int scl;
        byte addr;
        BH1750::Mode mod;
        float light_intensity;
        void read_light_intensity();
    public:
        Light(int sda, int scl, byte addr, BH1750::Mode mod);
        void begin();
        float get_light_intensity();
        void print_light_intensity();
        ~Light();
};

#endif