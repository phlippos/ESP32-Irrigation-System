#include <Light.h>

Light::Light(int sda, int scl, byte addr, BH1750::Mode mod) 
    : sda(sda), scl(scl), addr(addr), mod(mod){
    std::cout << "Light intensity sensor created" << std::endl;
}

void Light::begin(){
    Wire1.begin(sda,scl); // Initialize the I2C bus (BH1750 library doesn't do this automatically)
    if(lightMeter.begin(mod,addr,&Wire1)){
        std::cout << "BH1750 Advanced begin" << std::endl;
    }else {
        std::cout << "Error initialising BH1750" << std::endl;
    }
}

void Light::read_light_intensity(){
    light_intensity = lightMeter.readLightLevel();
}

void Light::print_light_intensity(){
    std::cout << "lightk : " << light_intensity << " lx" << std::endl;
}

float Light::get_light_intensity(){
    this->read_light_intensity();
    return light_intensity;
}
Light::~Light(){
    std::cout << "light destructor called" << std::endl;
}