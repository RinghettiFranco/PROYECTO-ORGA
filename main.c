#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ia.h"
#include "partida.h"


void imprimir_tablero(tTablero t){
    char ficha;
    ficha=' ';
    printf("*********************************\n");
    printf("  |y0|y1|y2|\n");
    for(int j=0;j<3;j++){
        printf("x%i|",j);
        for (int i=0;i<3;i++){
            if(t->grilla[j][i]==PART_SIN_MOVIMIENTO)
                ficha=' ';
            else
                if(t->grilla[j][i]==PART_JUGADOR_1)
                    ficha='x';
                else
                if(t->grilla[j][i]==PART_JUGADOR_2)
                    ficha='o';
                    printf("%c |",ficha);

        }
        printf("\n");
    }
    printf("\n");
    printf("*********************************\n");
}

int main(){
    int ret;
    int x,y;
    int modo_juego,comienzo;
    tBusquedaAdversaria busq;
    char jug1[50],jug2[50],labelIA[50]={'I','A','\0'};
    tPartida partida;

    printf("************************************************\n");
    printf("Bienvenido al juego:\n");
    printf("************************************************\n");
    printf("SE CUENTA CON 3 MODALIDADES, INGRESE UN NUMERO Y PRESIONE ENTER: \n");
    printf("OPCION N°1: USUARIO VS USUARIO.\n");
    printf("OPCION N°2: USUARIO VS AGENTE_IA.\n");
    printf("OPCION N°3: AGENTE_IA VS AGENTE_IA.\n\n");
    printf("INGRESE LA MODALIDAD DE JUEGO: ");
    scanf("%d",&modo_juego);

    do{
        if(modo_juego==1)printf("\n ELIGIO LA OPCION USUARIO VS USUARIO\n");
        else
            if(modo_juego==2)printf("\n ELIGIO LA OPCION USUARIO VS AGENTE_IA\n");
            else
                if(modo_juego==3)printf("\n ELIGIO LA OPCION AGENTE_IA VS AGENTE_IA\n");
                else{
                    printf("\n ERROR,DEBE INGRESAR UN VALOR CORRECTO,INTENTELO DE NUEVO\n");
                    printf("************************************************\n");
                    printf("INGRESE LA MODALIDAD DE JUEGO: ");
            scanf("%d",&modo_juego);}
    }while(modo_juego<1 || modo_juego>3);

    if(modo_juego==1){
        printf("************************************************\n");
        fflush(stdin);
        printf("Introduzca un Nombre para el jugador 1: "); scanf("%49[^\n]", jug1);
        fflush(stdin);
        printf("\nIntroduzca un Nombre para el jugador 2: "); scanf("%49[^\n]", jug2); fflush(stdin);

        printf("\n************************************************\n\n");
        printf("AHORA DEBE ELEGIR QUE JUGADOR DESEA QUE COMIENCE LA PARTIDA:\n");
        printf("PARA QUE COMIENCE A JUGAR EL JUGADOR 1 , INGRESE UN 1\n");
        printf("PARA QUE COMIENCE A JUGAR EL JUGADOR 2 , INGRESE UN 2\n");
        printf("SI QUIERE QUE EL JUGADOR QUE INICIE LA PARTIDA SEA ELEGIDO DE FORMA ALEATORIA , INGRESE UN 3\n");
        printf("OPCION: ");
        scanf("%d",&comienzo);
        printf("\n");

        do{
            if(comienzo==1) printf("\n COMIENZA EL JUGADOR 1\n");
            else
                if(comienzo==2) printf("\n COMIENZA EL JUGADOR 2\n");
                else
                    if(comienzo==3) printf("\n COMENZARA UN JUGADOR AL AZAR\n");
                    else {printf("\n ERROR,DEBE INGRESAR UN VALOR CORRECTO,INTENTELO DE NUEVO\n");
            printf("************************************************\n");
            printf("OPCION: ");
            scanf("%d",&comienzo);}
        }while(comienzo<1 || comienzo>3);
        comienzo=comienzo+99;

        nueva_partida(&partida,modo_juego,comienzo,jug1,jug2);
        do{
            // se crea la partida

            if(partida->turno_de==PART_JUGADOR_1)
                printf("ES EL TURNO DE ' %s ' DE JUGAR \n",jug1);
            else
                printf("ES EL TURNO DE ' %s ' DE JUGAR \n",jug2);

            printf("Seleccione valor de x : ");scanf("%d",&x); printf("\n");
            printf("Seleccione valor de y : ");scanf("%d",&y); printf("\n");

            ret=nuevo_movimiento(partida,x,y);
            if(ret==PART_MOVIMIENTO_OK)
                imprimir_tablero(partida->tablero);
            else
                printf("Ingrese un valor valido\n");

            if(partida->estado==PART_GANA_JUGADOR_1) printf("GANO %s\n",jug1);
            if(partida->estado==PART_GANA_JUGADOR_2) printf("GANO %s\n",jug2);
            if(partida->estado==PART_EMPATE) printf("HUBO UN EMPATE!! \n");
        }while(partida->estado==PART_EN_JUEGO);
    }else{
        if(modo_juego==2){
            printf("************************************************\n");
            fflush(stdin);
            printf("Introduzca un Nombre para el jugador 1: "); scanf("%49[^\n]", jug1);
            fflush(stdin);

            printf("\n************************************************\n\n");
            printf("AHORA DEBE ELEGIR QUE JUGADOR DESEA QUE COMIENCE LA PARTIDA:\n");
            printf("PARA QUE COMIENCE A JUGAR EL JUGADOR 1 , INGRESE UN 1\n");
            printf("PARA QUE COMIENCE A JUGAR LA IA , INGRESE UN 2\n");
            printf("SI QUIERE QUE EL JUGADOR QUE INICIE LA PARTIDA SEA ELEGIDO DE FORMA ALEATORIA , INGRESE UN 3\n");
            printf("OPCION: ");
            scanf("%d",&comienzo);
            printf("\n");

            do{
                if(comienzo==1) printf("\n COMIENZA EL JUGADOR 1\n");
                else
                    if(comienzo==2) printf("\n COMIENZA LA IA\n");
                    else
                        if(comienzo==3) printf("\n COMENZARA UN JUGADOR AL AZAR\n");
                        else {printf("\n ERROR,DEBE INGRESAR UN VALOR CORRECTO,INTENTELO DE NUEVO\n");
                printf("************************************************\n");
                printf("OPCION: ");
                scanf("%d",&comienzo);}
            }while(comienzo<1 || comienzo>3);

            // se crea la partida:

            comienzo=comienzo+99;

            nueva_partida(&partida,modo_juego,comienzo,jug1,labelIA);
            imprimir_tablero(partida->tablero);
            do{
                if(partida->turno_de==PART_JUGADOR_1){
                    printf("Seleccione valor de x : ");scanf("%d",&x); printf("\n");
                    printf("Seleccione valor de y : ");scanf("%d",&y); printf("\n");
                    ret=nuevo_movimiento(partida,x,y);
                    if(ret!=PART_MOVIMIENTO_OK)printf("Ingrese un valor valido\n");
                }else{
                    crear_busqueda_adversaria(&busq,partida);
                    proximo_movimiento(busq,&x,&y);
                    nuevo_movimiento(partida,x,y);
                    destruir_busqueda_adversaria(&busq);
                }
                if(partida->turno_de==PART_JUGADOR_1)
                    printf("ES EL TURNO DE  ' %s ' DE JUGAR \n",jug1);
                else
                    printf("ES EL TURNO DE  LA IA DE JUGAR \n");
                imprimir_tablero(partida->tablero);
                if(partida->estado==PART_GANA_JUGADOR_1) printf("GANO %s\n",jug1);
                if(partida->estado==PART_GANA_JUGADOR_2) printf("GANO LA IA\n",jug2);
                if(partida->estado==PART_EMPATE) printf("HUBO UN EMPATE!! \n");
            }while(partida->estado==PART_EN_JUEGO);
        }
    else{
        comienzo=comienzo+99;
        nueva_partida(&partida,modo_juego,comienzo,labelIA,labelIA);
        imprimir_tablero(partida->tablero);
        do{
            crear_busqueda_adversaria(&busq,partida);
            proximo_movimiento(busq,&x,&y);
            nuevo_movimiento(partida,x,y);
            destruir_busqueda_adversaria(&busq);
            printf("%d",partida->estado);
            if(partida->turno_de==PART_JUGADOR_1)
                printf("ES EL TURNO DE LA IA 1 DE JUGAR \n");
            else
                printf("ES EL TURNO DE LA IA 2 DE JUGAR \n");
            imprimir_tablero(partida->tablero);
            if(partida->estado==PART_GANA_JUGADOR_1)printf("GANO %s\n",jug1);
            if(partida->estado==PART_GANA_JUGADOR_2)printf("GANO %s\n",jug2);
            if(partida->estado==PART_EMPATE) printf("HUBO UN EMPATE!! \n");
        }while(partida->estado==PART_EN_JUEGO);
    }

    }
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

