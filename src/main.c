#include <gb/gb.h>
#include <gb/font.h>
#include <stdio.h>
#include "res/Tileset1.c"
#include "res/background.c"
#include "res/backgroundtiles.c"
#include "res/windowmap.c"

/*void main() {
    UINT8 currentSpriteIndex=0;
    set_sprite_data(0, 2, Boxes);
    set_sprite_tile(0, 0);
    move_sprite(0, 88, 87);
    SHOW_SPRITES;

    while(1){
        switch (joypad())
        {
        case J_LEFT:
            scroll_sprite(0,-5,0);
            break;
        case J_RIGHT:
            scroll_sprite(0,5,0);
            break;
        case J_UP:
            scroll_sprite(0,0,-5);
            break;
        case J_DOWN:
            scroll_sprite(0,0,5);
            break;
        
        
        }
        
        delay(500);
        
    }
}*/

void main() {

    

    font_t min_font;
    font_init();
    min_font = font_load(font_min);
    font_set(min_font);
    set_bkg_data(37, 7, backgroundtiles);
    set_bkg_tiles(0,0, 40,18, background);

    set_win_tiles(0,0,5,1,windowmap);
    move_win(7,120);
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;
    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;
    while(1) {
        scroll_bkg(1,0);
        delay(100);
        if (joypad()){
            NR10_REG = 0x16;
            NR11_REG = 0x40;
            NR12_REG = 0x73;
            NR13_REG = 0x00;
            NR14_REG = 0xC3;
            delay(100);
        }
    }
}