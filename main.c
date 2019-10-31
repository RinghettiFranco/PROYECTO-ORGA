#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\fede.000\Documents\GitHub\PROYECTO-ORGA\ia.h>
#include <C:\Users\fede.000\Documents\GitHub\PROYECTO-ORGA\partida.h>

/**
void mostrar(int grid[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%i|",grid[i][j]);
        }
        printf("\n");
    }
}
**/
int main()
{
 int mov_x,mov_y,correcto,modo,comienza;
 tPartida partida;
 tBusquedaAdversaria busq;

 correcto=0;
 modo=PART_MODO_AGENTE_IA_VS_AGENTE_IA;
 comienza=PART_JUGADOR_1;
 nueva_partida(&partida,modo,comienza,"Jugador1","Jugador2");
 crear_busqueda_adversaria(&busq,partida);
 while(partida->estado==PART_EN_JUEGO){
    proximo_movimiento(busq,&mov_x,&mov_y);//para la ia
    correcto=nuevo_movimiento(partida,mov_x,mov_y);




}








































   /** int G[3][3]={{PART_SIN_MOVIMIENTO,PART_SIN_MOVIMIENTO,PART_SIN_MOVIMIENTO},
                 {PART_SIN_MOVIMIENTO,PART_SIN_MOVIMIENTO,PART_SIN_MOVIMIENTO},
                 {PART_SIN_MOVIMIENTO,PART_SIN_MOVIMIENTO,PART_SIN_MOVIMIENTO}};

    tTablero T = (tTablero) malloc(sizeof(struct  tablero));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            (T->grilla[i][j])=G[i][j];
        }
    }

    tPartida P = (tPartida) malloc(sizeof(struct partida));
    (P->modo_partida)=1;
    (P->turno_de)=PART_JUGADOR_1;
    (P->estado)=PART_EN_JUEGO;
    (P->tablero)=T;

    tBusquedaAdversaria bA = (tBusquedaAdversaria) malloc(sizeof(struct busqueda_adversaria));
    crear_arbol(&(bA->arbol_busqueda));
    bA->jugador_max=PART_JUGADOR_1;
    bA->jugador_min=PART_JUGADOR_2;


    (T->grilla[1][1])=PART_JUGADOR_1;
    crear_busqueda_adversaria(&bA,P);
    int x,y;
    proximo_movimiento(bA,&x,&y);
    (T->grilla[x][y])=PART_JUGADOR_2;

    mostrar((T->grilla));**/
}
