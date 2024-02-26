/**
 * @file bar.c
 * @date 2021-10-17
 * @brief Arquivo que contém as funções para movimentar a barra
*/

#include "prototype.h"

void moveBar(Bar *bar, int accelX) {
    if ((WALL_WIDHT_X < (bar->coordX - BAR_SIZE) + accelX) && ((bar->coordX + BAR_SIZE) + accelX < SCREEN_X - WALL_WIDHT_X))
        bar->coordX += accelX;
    else {
        if (SCREEN_X / 2 >= bar->coordX) 
            bar->coordX -= bar->coordX - BAR_SIZE - WALL_WIDHT_X;
        else 
            bar->coordX += -(bar->coordX + BAR_SIZE) + SCREEN_X - WALL_WIDHT_X - 1;
    }
}