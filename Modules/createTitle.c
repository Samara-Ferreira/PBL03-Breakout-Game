#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <intelfpgaup/accel.h>
#include <intelfpgaup/video.h>
#include "alfa.h"

void titulo15x17 (coordX, coordY) {

short cor1 = 0x3f9e; //ciano
short cor2 = 0xf81f; //magenta

// Letra B

video_box(coordX     , coordY     , coordX +  4, coordY + 16, cor1);
video_box(coordX +  5, coordY     , coordX + 12, coordY +  2, cor1);
video_box(coordX + 13, coordY     , coordX + 13, coordY + 16, cor2);
video_box(coordX +  5, coordY +  3, coordX +  5, coordY + 13, cor2);
video_box(coordX + 10, coordY +  3, coordX + 14, coordY +  6, cor1);
video_box(coordX + 15, coordY +  3, coordX + 15, coordY +  6, cor2);
video_box(coordX +  5, coordY +  7, coordX + 12, coordY +  9, cor1);
video_box(coordX + 10, coordY + 10, coordX + 14, coordY + 13, cor1);
video_box(coordX + 15, coordY + 10, coordX + 15, coordY + 13, cor2);
video_box(coordX +  5, coordY + 14, coordX + 12, coordY + 16, cor1);

coordX += 18;

// Letra r

video_box(coordX     , coordY +  4, coordX +  4, coordY + 16, cor1);
video_box(coordX +  5, coordY +  4, coordX +  5, coordY +  6, cor2);
video_box(coordX +  6, coordY +  4, coordX + 12, coordY +  6, cor1);
video_box(coordX + 13, coordY +  4, coordX + 13, coordY +  6, cor2);
video_box(coordX +  5, coordY +  7, coordX +  6, coordY +  9, cor1);
video_box(coordX +  7, coordY +  7, coordX +  7, coordY +  9, cor2);
video_box(coordX +  5, coordY + 10, coordX +  5, coordY + 16, cor2);

coordX += 14;

// Letra e

video_box(coordX +  2, coordY +  4, coordX + 11, coordY +  6, cor1);
video_box(coordX + 12, coordY +  4, coordX + 12, coordY +  6, cor2);
video_box(coordX     , coordY +  7, coordX +  4, coordY + 13, cor1);
video_box(coordX +  5, coordY +  7, coordX +  5, coordY + 13, cor2);
video_box(coordX + 10, coordY +  7, coordX + 13, coordY +  8, cor1);
video_box(coordX + 14, coordY +  7, coordX + 14, coordY + 11, cor2);
video_box(coordX +  5, coordY +  9, coordX + 13, coordY + 11, cor1);
video_box(coordX +  2, coordY + 14, coordX + 11, coordY + 16, cor1);
video_box(coordX + 12, coordY + 14, coordX + 12, coordY + 16, cor2);

coordX += 15;

// Letra a

video_box(coordX +  2, coordY +  4, coordX + 11, coordY +  6, cor1);
video_box(coordX + 12, coordY +  4, coordX + 12, coordY +  6, cor2);
video_box(coordX     , coordY + 12, coordX +  4, coordY + 13, cor1);
video_box(coordX +  5, coordY + 12, coordX +  5, coordY + 13, cor2);
video_box(coordX +  2, coordY +  9, coordX +  8, coordY + 11, cor1);
video_box(coordX +  2, coordY + 14, coordX +  8, coordY + 16, cor1);
video_box(coordX +  9, coordY + 17, coordX + 13, coordY + 16, cor1);
video_box(coordX + 14, coordY +  7, coordX + 14, coordY + 16, cor2);

coordX += 15;

// Letra k

video_box(coordX     , coordY     , coordX +  4, coordY + 16, cor1);
video_box(coordX +  5, coordY     , coordX +  5, coordY + 16, cor2);
video_box(coordX +  5, coordY +  9, coordX +  9, coordY + 10, cor1);
video_box(coordX + 10, coordY +  9, coordX + 10, coordY + 10, cor2);
video_box(coordX +  9, coordY +  4, coordX + 13, coordY +  5, cor1);
video_box(coordX + 14, coordY +  4, coordX + 14, coordY +  5, cor2);
video_box(coordX +  7, coordY +  6, coordX + 11, coordY +  8, cor1);
video_box(coordX + 12, coordY +  6, coordX + 12, coordY +  8, cor2);
video_box(coordX +  7, coordY + 11, coordX + 11, coordY + 13, cor1);
video_box(coordX + 12, coordY + 11, coordX + 12, coordY + 13, cor2);
video_box(coordX +  9, coordY + 14, coordX + 13, coordY + 16, cor1);
video_box(coordX + 14, coordY + 14, coordX + 14, coordY + 16, cor2);

coordX += 15;

//Letra o

video_box(coordX +  2, coordY +  4, coordX + 11, coordY +  6, cor1);
video_box(coordX + 12, coordY +  4, coordX + 12, coordY +  6, cor2);
video_box(coordX     , coordY +  7, coordX +  4, coordY + 13, cor1);
video_box(coordX +  5, coordY +  7, coordX +  5, coordY + 13, cor2);
video_box(coordX + 10, coordY +  7, coordX + 13, coordY + 13, cor1);
video_box(coordX + 14, coordY +  7, coordX + 14, coordY + 13, cor2);
video_box(coordX +  2, coordY + 14, coordX + 11, coordY + 16, cor1);
video_box(coordX + 12, coordY + 14, coordX + 12, coordY + 16, cor2);

coordX += 15;

// Letra u

video_box(coordX     , coordY +  4, coordX +  4, coordY + 13, cor1);
video_box(coordX +  5, coordY +  4, coordX +  5, coordY + 13, cor2);
video_box(coordX +  2, coordY + 14, coordX +  9, coordY + 16, cor1);
video_box(coordX + 10, coordY +  4, coordX + 13, coordY + 16, cor1);
video_box(coordX + 14, coordY +  4, coordX + 14, coordY + 16, cor2);

coordX += 16;

// Letra t

video_box(coordX +  1, coordY +  4, coordX +  4, coordY +  6, cor1);
video_box(coordX +  5, coordY     , coordX +  9, coordY + 16, cor1);
video_box(coordX + 10, coordY     , coordX + 10, coordY + 16, cor2);
video_box(coordX + 10, coordY +  4, coordX + 13, coordY +  6, cor1);
video_box(coordX + 14, coordY +  4, coordX + 14, coordY +  6, cor2);

}

void titulo30x34 (coordX, coordY) {

short cor1 = 0x3f9e; //ciano
short cor2 = 0xf81f; //magenta

// Letra B

video_box(coordX     , coordY     , coordX +  9, coordY + 33, cor1);
video_box(coordX + 10, coordY     , coordX + 23, coordY +  5, cor1);
video_box(coordX + 10, coordY +  6, coordX + 11, coordY + 13, cor2);
video_box(coordX + 10, coordY + 20, coordX + 11, coordY + 27, cor2);
video_box(coordX + 10, coordY + 14, coordX + 23, coordY + 19, cor1);
video_box(coordX + 10, coordY + 28, coordX + 23, coordY + 33, cor1);
video_box(coordX + 20, coordY +  6, coordX + 27, coordY + 13, cor1);
video_box(coordX + 20, coordY + 20, coordX + 27, coordY + 27, cor1);
video_box(coordX + 24, coordY     , coordX + 25, coordY +  5, cor1);
video_box(coordX + 28, coordY +  6, coordX + 29, coordY + 13, cor2);
video_box(coordX + 24, coordY + 14, coordX + 25, coordY + 19, cor2);
video_box(coordX + 28, coordY + 20, coordX + 29, coordY + 27, cor2);
video_box(coordX + 24, coordY + 28, coordX + 25, coordY + 33, cor2);

coordX += 33;

// Letra r

video_box(coordX     , coordY +  8, coordX +  9, coordY + 33, cor1);
video_box(coordX + 10, coordY +  8, coordX + 11, coordY + 13, cor2);
video_box(coordX + 12, coordY +  8, coordX + 23, coordY + 13, cor1);
video_box(coordX + 24, coordY +  8, coordX + 25, coordY + 13, cor2);
video_box(coordX + 10, coordY + 14, coordX + 13, coordY + 19, cor1);
video_box(coordX + 14, coordY + 14, coordX + 15, coordY + 19, cor2);
video_box(coordX + 10, coordY + 20, coordX + 11, coordY + 33, cor2);

coordX += 29;

// Letra e

video_box(coordX +  4, coordY +  8, coordX + 21, coordY + 13, cor1);
video_box(coordX + 22, coordY +  8, coordX + 23, coordY + 13, cor2);
video_box(coordX     , coordY + 14, coordX +  9, coordY + 37, cor1);
video_box(coordX + 10, coordY + 14, coordX + 11, coordY + 17, cor2);
video_box(coordX + 10, coordY + 24, coordX + 11, coordY + 27, cor2);
video_box(coordX + 10, coordY + 18, coordX + 25, coordY + 23, cor1);
video_box(coordX + 20, coordY + 14, coordX + 25, coordY + 17, cor1);
video_box(coordX + 26, coordY + 14, coordX + 27, coordY + 23, cor2);
video_box(coordX +  4, coordY + 28, coordX + 21, coordY + 33, cor1);
video_box(coordX + 22, coordY + 28, coordX + 23, coordY + 33, cor2);

coordX += 30;

// Letra a

video_box(coordX +  4, coordY +  8, coordX + 21, coordY + 13, cor1);
video_box(coordX + 22, coordY +  8, coordX + 23, coordY + 13, cor2);
video_box(coordX + 18, coordY + 14, coordX + 26, coordY + 17, cor1);
video_box(coordX +  4, coordY + 18, coordX + 25, coordY + 23, cor1);
video_box(coordX     , coordY + 24, coordX +  9, coordY + 27, cor1);
video_box(coordX + 10, coordY + 24, coordX + 12, coordY + 27, cor2);
video_box(coordX + 18, coordY + 24, coordX + 25, coordY + 27, cor1);
video_box(coordX +  4, coordY + 28, coordX + 25, coordY + 33, cor1);
video_box(coordX +  26, coordY +  14, coordX + 27, coordY + 33, cor2);

coordX += 30;

// Letra k

video_box(coordX     , coordY     , coordX +  9, coordY + 33, cor1);
video_box(coordX + 10, coordY     , coordX + 11, coordY + 17, cor2);
video_box(coordX + 10, coordY + 22, coordX + 11, coordY + 33, cor2);
video_box(coordX + 10, coordY + 18, coordX + 18, coordY + 21, cor1);
video_box(coordX + 18, coordY + 18, coordX + 19, coordY + 21, cor2);
video_box(coordX + 18, coordY +  6, coordX + 25, coordY + 11, cor1);
video_box(coordX + 26, coordY +  6, coordX + 27, coordY + 11, cor2);
video_box(coordX + 14, coordY + 12, coordX + 21, coordY + 17, cor1);
video_box(coordX + 22, coordY + 12, coordX + 23, coordY + 17, cor2);
video_box(coordX + 14, coordY + 22, coordX + 21, coordY + 17, cor1);
video_box(coordX + 22, coordY + 22, coordX + 23, coordY + 27, cor2);
video_box(coordX + 18, coordY + 28, coordX + 25, coordY + 33, cor1);
video_box(coordX + 26, coordY + 28, coordX + 27, coordY + 33, cor2);

coordX += 30;

//Letra o

video_box(coordX +  4, coordY +  8, coordX + 21, coordY + 13, cor1);
video_box(coordX + 22, coordY +  8, coordX + 23, coordY + 13, cor2);
video_box(coordX     , coordY + 14, coordX +  9, coordY + 27, cor1);
video_box(coordX + 10, coordY + 14, coordX + 11, coordY + 27, cor2);
video_box(coordX + 20, coordY + 14, coordX + 25, coordY + 27, cor1);
video_box(coordX + 26, coordY + 14, coordX + 27, coordY + 27, cor2);
video_box(coordX +  4, coordY + 28, coordX + 21, coordY + 33, cor1);
video_box(coordX + 22, coordY + 28, coordX + 23, coordY + 33, cor2);

coordX += 30;

// Letra u

video_box(coordX     , coordY +  8, coordX +  9, coordY + 27, cor1);
video_box(coordX + 10, coordY +  8, coordX + 11, coordY + 27, cor2);
video_box(coordX + 20, coordY +  8, coordX + 25, coordY + 33, cor1);
video_box(coordX + 26, coordY +  8, coordX + 27, coordY + 33, cor2);
video_box(coordX + 4, coordY +  28, coordX + 19, coordY + 33, cor1);

coordX += 31;

// Letra t

video_box(coordX +  8, coordY     , coordX + 17, coordY +  7, cor1);
video_box(coordX + 18, coordY     , coordX + 19, coordY +  7, cor2);
video_box(coordX     , coordY +  8, coordX + 25, coordY + 13, cor1);
video_box(coordX + 26, coordY +  8, coordX + 27, coordY + 13, cor2);
video_box(coordX +  8, coordY + 14, coordX + 17, coordY + 33, cor1);
video_box(coordX + 18, coordY + 14, coordX + 19, coordY + 33, cor2);

}