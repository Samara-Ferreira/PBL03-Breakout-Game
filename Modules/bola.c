#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <intelfpgaup/accel.h>
#include <intelfpgaup/video.h>
#include "alfa.h"

void bola7x7 (int coordX, int coordY, short cor) {
    video_box(coordX - 1, coordY - 3, coordX + 1, coordY - 3, cor);
	video_box(coordX - 2, coordY - 2, coordX + 2, coordY - 2, cor);
	video_box(coordX - 3, coordY - 1, coordX + 3, coordY + 1, cor);
	video_box(coordX - 2, coordY + 2, coordX + 2, coordY + 2, cor);
	video_box(coordX - 1, coordY + 3, coordX + 1, coordY + 3, cor);
}

void bola9x9 (int coordX, int coordY, short cor) {
    video_box(coordX - 1, coordY - 4, coordX + 1, coordY - 4, cor);
	video_box(coordX - 3, coordY - 3, coordX + 3, coordY - 2, cor);
	video_box(coordX - 4, coordY - 1, coordX + 4, coordY + 1, cor);
	video_box(coordX - 3, coordY + 2, coordX + 3, coordY + 3, cor);
	video_box(coordX - 1, coordY + 4, coordX + 1, coordY + 4, cor);
}