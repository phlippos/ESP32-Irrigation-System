#ifndef LCD_H
#define LCD_H

#include <inttypes.h>
#include <iostream>
#include <LiquidCrystal_I2C.h>
class LCD{
    private:
        /* data */
        uint8_t lcd_Addr;
        uint8_t lcd_columns;
        uint8_t lcd_rows;
        String greeting;
        LiquidCrystal_I2C lcd;

    public:
        LCD(uint8_t lcd_Addr,uint8_t lcd_columns, uint8_t lcd_rows, String greeting);
        void begin();
        void update_display(uint8_t col,uint8_t row,String msg);
        ~LCD();
};

#endif