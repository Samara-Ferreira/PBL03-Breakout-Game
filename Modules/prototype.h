#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED

#include <intelfpgaup/video.h>
#include <intelfpgaup/accel.h>
#include <intelfpgaup/KEY.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SCREEN_X                320
#define SCREEN_Y                240
#define WALL_WIDHT_X            3
#define WALL_WIDHT_Y            15
#define RADIUS                  4
#define COLLISION_RADIUS        5
#define BAR_SIZE                30
#define BAR_WIDHT               1
#define QUANTITY_BLOCKS         48  // valor original: 48
#define BLOCK_LENGTH            37 
#define BLOCK_WIDHT             12

typedef struct {
    int coordX;         /* x do canto superior esquerdo */ 
    int coordY;         /* y do canto superior esquerdo */
    int flagVisible;    /* flag para saber se o bloco esta visivel */
    int life;           /* vida do bloco */ 
    int points;         /* pontos do bloco */
	int color;
} Block;

typedef struct {
    int ballPositionX;
    int ballPositionY;
    int ballSpeedX;
    int ballSpeedY;
    int collision;
} Ball;

typedef struct {
    int coordX;
    int coordY;
} Bar;

void alfanumerico    (int coordX, int coordY, char caracter, short cor);
void phrase          (int coordX, int coordY, char *list, int lenList, short cor);
void screen_defeat   (int score);
void screen_victory  ();
void create_menu     (); 
void game_field(Block blocksList[], int score, int state_game);

void makeBlocks      (Block blocksList[]);
void removeBlocks    (Block blocksList[], int *score,  Ball *ball);
 
void bola9x9         (int coordX, int coordY, short cor);
int detect_collision (int x_rect, int y_rect, int length_rect, int width_rect,  
                      int x_boll, int y_boll, int ray, int *x_point, int *y_point);
int getTypeCollision (Ball *ball, Block blocksList[], Bar *bar);
int getMoveBall      (Ball *ball, Block blocksList[], Bar *bar);
void moveBall        (Ball *ball, Block blocksList[], Bar *bar);

void moveBar         (Bar *bar, int accelX);

void change_state    (int *pointer_state, int *pointer_buttons);

#endif // PROTOTYPE_H_INCLUDED