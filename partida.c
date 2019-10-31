typedef struct tablero * tTablero;
typedef struct partida * tPartida;

/**
Inicializa una nueva partida, indicando:
 - Modo de partida (Usuario vs. Usuario o Usuario vs. Agente IA).
 - Jugador que comienza la partida (Jugador 1, Jugador 2, o elecci�n al azar).
 - Nombre que representa al Jugador 1.
 - Nombre que representa al Jugador 2.
**/
void nueva_partida(tPartida * p, int modo_partida, int comienza, char * j1_nombre, char * j2_nombre){
*p=(tPartida) malloc(sizeof(struct partida));
if ((*p) == NULL) exit(PART_ERROR_MEMORIA);
tTablero tab=(tTablero) malloc(sizeof(struct tablero));
if(tab==NULL) exit((PART_ERROR_MEMORIA));
(*p)->tablero=tab;
(*p)->modo_partida=modo_partida;
(*p)->estado=PART_EN_JUEGO
if(comienza==PART_JUGADOR_RANDOM){
    int random=rand()%2;
    if (random==0) comienza=PART_JUGADOR_1;
    else comienza=PART_JUGADOR_2;
}
(*p)->turno_de=comienza;
strcpy((*p)->nombre_jugador_1,j1_nombre);
strcpy((*p)->nombre_jugador_2,j2_nombre);
}

/**
Actualiza, si corresponde, el estado de la partida considerando que el jugador al que le corresponde jugar, decide hacerlo en la posici�n indicada (X,Y).
En caso de que el movimiento a dicha posici�n sea posible, retorna PART_MOVIMIENTO_OK; en caso contrario, retorna PART_MOVIMIENTO_ERROR.
Las posiciones (X,Y) deben corresponderse al rango [0-2]; X representa el n�mero de fila, mientras Y el n�mero de columna.
**/
int nuevo_movimiento(tPartida p, int mov_x, int mov_y){
if((p->tablero)->grilla[mov_x][mov_y]!=PART_SIN_MOVIMIENTO||mov_x<0||mov_x>2||mov_y<0||mov_y>2) return PART_MOVIMIENTO_ERROR;
else{
((p->tablero)->grilla[mov_x][mov_y])= p->turno_de;
(p->turno_de==PART_JUGADOR_1)?PART_JUGADOR_2:PART_JUGADOR_1;
return PART_MOVIMIENTO_OK;
}
}

/**
Finaliza la partida referenciada por P, liberando toda la memoria utilizada.
**/
void finalizar_partida(tPartida * p){




}
