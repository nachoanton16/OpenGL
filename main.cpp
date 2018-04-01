#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


#define M 0x10
#define N 0x40
#define MAX_VIDAS 3
#define VIDAS 3
#define POS_VACIA " "
#define POS_LLENA ""
#define J1 "🎮"

enum {ACTUAL, NUEVA, PANTALLAS};

/*Rellena aleatoriamente las posiciones de los marcianos*/
void rellena(int matriz[M][N]){
    system("clear");
    int x, y;

    for(int n = 0; n<2; n++){
        x = rand() % M;
        y = rand() % N;
        matriz[x][y] = 1;

    }
}

/*Pinta la matriz para mostrar por pantalla marcianos y jugador*/
void pintar(int matriz[M][N]){
    for(int f=0; f<M; f++){
        for(int c=0; c<N; c++)
            printf("%s", matriz[f][c]? POS_LLENA);
    }

    } 
    void main()
    {
        char a;
        clrscr();
        a=getche();
        if (a==13){ printf("Enter");}
        if (a==75){ printf("Flecha izquierda");}
        if (a==80){ printf("Flecha abajo");}
        if (a==77){ printf("Flecha derecha");}
        if (a==72){ printf("Flecha arriba");}
        getch();
    }

int main(){

    int pantalla[PANTALLAS][M][N];/*Se declara el tamaño de las matrices*/
    int (*actual)[M][N] = &pantalla[ACTUAL];/*Se guardan los datos de la matriz ACTUAL en *actual*/
    int (*nueva)[M][N] = &pantalla[NUEVA];/*Se guardan los datos de la matriz NUEVA en *nueva*/
    int (*temporal)[M][N];
    bzero(pantalla[ACTUAL], sizeof(pantalla[ACTUAL]));

    system("toilet --gay -fpagga Welcome to the CANION");

/*Continuar jugando*/
    while(VIDAS >= 1){
        system("clear");
        pintar(pantalla[ACTUAL]);


    }
/*Fin del juego por acabarse el numero de vidas*/
system("clear");
printf("Fin del juego");

    return EXIT_SUCCESS;
}
