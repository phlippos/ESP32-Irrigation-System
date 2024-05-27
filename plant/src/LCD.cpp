#include <LCD.h>

LCD::LCD(uint8_t lcd_Addr,uint8_t lcd_columns, uint8_t lcd_rows, String greeting)
    : lcd_Addr(lcd_Addr), lcd_columns(lcd_columns), lcd_rows(lcd_rows),
     greeting(greeting),lcd(lcd_Addr,lcd_columns,lcd_rows){

    std::cout << "LCD object created" << std::endl;
}

void LCD::begin(){
    lcd.init();
    lcd.backlight();
    lcd.print(greeting);
    for(int i = 0; i < 4; i ++){
        lcd.setCursor(i,1);
    }
}

void LCD::update_display(uint8_t col,uint8_t row,String msg){
    lcd.setCursor(col,row);
    lcd.print(msg);
}

LCD::~LCD(){
    std::cout << "LCD object is deleted" << std::endl;
}