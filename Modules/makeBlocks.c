void make_blocks (Block blocksList[]) {

int i, j, count = 0;
short colors1[6] = {0xf012, 0xe800, 0xf301, 0xdd82, 0xf37, 0x5ec}; //rosa forte, vermelho escuro, laranja, amarelo dourado, ciano claro, verde vivo
short colors2[6] = {0x3dbf, 0x5f1c, 0xdd82, 0xf301, 0xe800, 0xf012}; //azul claro, aqua suave, amarelo dourado, laranja, vermelho escuro, rosa forte

for (i = 0; i < 6; i++) { 
    for (j = 0; j < 8; j++) {
        blocksList[count].coordX =  5 + (39 * j);
        blocksList[count].coordY = 20 + (i * 14); blocksList[count].flagVisible = 1; 
        blocksList[count].life   =  1;
        blocksList[count].points =  1 + ( i * 2); 
        blocksList[count].color  =  colors1[i];

        count++;  
        }  
    }  
}