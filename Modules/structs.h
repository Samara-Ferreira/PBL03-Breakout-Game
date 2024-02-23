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
    int typeCollision;
} Bar;

typedef struct Explosion {

    int coordX;         /* x do canto superior esquerdo */ 
    int coordY;
	int color;
    struct Explosion *prox;
    
} Explosion;

typedef struct {

    int len;
    Explosion *begin;

} List;