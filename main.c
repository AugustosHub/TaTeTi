#include <stdio.h>
#include <stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<time.h>
#include<unistd.h>

void inicializarTablero(char tablero[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = '-';
        }
    }

}

void imprimirTablero(char tablero[3][3]) {
        printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("|");
            printf(" %c ", tablero[i][j]);
            if (j == 2){
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("----+---+----\n");
        }
        if (i == 2){
            printf("-------------\n");
        }
    }
}
int verificarGanador(char tablero[3][3]) {
    /////CASOS X
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == 'X' && tablero[i][1] == 'X' && tablero[i][2] == 'X') {
            return 1; // Ganó en una fila
        }
        if (tablero[0][i] == 'X' && tablero[1][i] == 'X' && tablero[2][i] == 'X') {
            return 1; // Ganó en una columna
        }
    }
    if (tablero[0][0] == 'X' && tablero[1][1] == 'X' && tablero[2][2] == 'X') {
        return 1; // Ganó en la diagonal principal
    }
    if (tablero[0][2] == 'X' && tablero[1][1] == 'X' && tablero[2][0] == 'X') {
        return 1; // Ganó en la diagonal secundaria
    }
    /////CASOS O
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == 'O' && tablero[i][1] == 'O' && tablero[i][2] == 'O') {
            return 1; // Ganó en una fila
        }
        if (tablero[0][i] == 'O' && tablero[1][i] == 'O' && tablero[2][i] == 'O') {
            return 1; // Ganó en una columna
        }
    }
    if (tablero[0][0] == 'O' && tablero[1][1] == 'O' && tablero[2][2] == 'O') {
        return 1; // Ganó en la diagonal principal
    }
    if (tablero[0][2] == 'O' && tablero[1][1] == 'O' && tablero[2][0] == 'O') {
        return 1; // Ganó en la diagonal secundaria
    }
    return 0; // Nadie ganó aún
}

void jugarTurno(char tablero[3][3]){
    char jugX[20],jugO[20];
    int fila, columna;

    printf("Ingrese el nombre del Jugador(X): ");
    scanf("%s",jugX);
    puts("////////////////////////////////////");
    printf("Ingrese el nombre del Jugador(O): ");
    scanf("%s",jugO);

    for (int turno = 1; turno <= 9; turno++) {
        system("cls");
        imprimirTablero(tablero);
        puts("/////////////////////////");

        if(turno % 2 != 0){
            printf("Turno %d: Jugador %s\n", turno,jugX);

            //LE PIDE AL JUGADOR ACTUAL DONDE QUIERE UBICAR SU FICHA
            printf("Ingrese la fila (0-2): ");
            scanf("%d", &fila);
            printf("Ingrese la columna (0-2): ");
            scanf("%d", &columna);
            puts("/////////////////////////");

            //VERIFICA QUE LA POSICIÓN ESTÉ LIBRE
            if (tablero[fila][columna] != '-') {
                printf("¡Esa posición ya está ocupada! Intente de nuevo.\n");
                turno--; // Reintentar el mismo turno
                continue;
            }

            // Colocar la ficha del jugador en la posición seleccionada
            tablero[fila][columna] = 'X';
        }else{
            printf("Turno %d: Jugador %s\n", turno,jugO);

            //LE PIDE AL JUGADOR ACTUAL DONDE QUIERE UBICAR SU FICHA
            printf("Ingrese la fila (0-2): ");
            scanf("%d", &fila);
            printf("Ingrese la columna (0-2): ");
            scanf("%d", &columna);
            puts("/////////////////////////");

            //VERIFICA QUE LA POSICIÓN ESTÉ LIBRE
            if (tablero[fila][columna] != '-') {
                printf("¡Esa posición ya está ocupada! Intente de nuevo.\n");
                turno--; // Reintentar el mismo turno
                continue;
            }

            // Colocar la ficha del jugador en la posición seleccionada
            tablero[fila][columna] = 'O';
        }
        // Verificar si el jugador ganó
        if (verificarGanador(tablero)) {
            imprimirTablero(tablero);
            if(turno % 2 != 0){
                printf("¡Jugador %s ha ganado!\n",jugX);
            }else if(turno % 2 == 0){
                printf("¡Jugador %s ha ganado!\n",jugO);
            }else{
                printf("¡Hubo un empate!\n");
            }
            return;
        }
    }
}

void jugarTurnoCPU(char tablero[3][3]){
    char nombre[20];
    int rellenar, fila, columna, aleatorio;

    printf("Ingrese su nombre: ");
    scanf("%s",nombre);
    system("cls");

    for (int turno = 1; turno <= 9; turno++) {
        rellenar = 0;

        system("cls");
        imprimirTablero(tablero);
        puts("/////////////////////////");
        if (turno % 2 != 0){
            printf("Turno %d: Jugador %s\n", turno, nombre);

            //LE PIDE AL USUARIO LA POSICIÓN DONDE QUIERE JUGAR
            printf("Ingrese la fila (0-2): ");
            scanf("%d", &fila);
            printf("Ingrese la columna (0-2): ");
            scanf("%d", &columna);
            puts("/////////////////////////");

            //VERIFICA QUE ESTÉ LIBRE LA POSICIÓN
            if (tablero[fila][columna] != '-') {
                printf("¡Esa posición ya está ocupada! Intente de nuevo.\n");
                turno--; //REPITE EL TURNO
                continue;
                }
            //PONE LA CRUZ EN EL CASILLERO DESEADO
            tablero[fila][columna] = 'X';
            }else{
                printf("Turno %d: CPU\n",turno);
                puts("La CPU está eligiendo, espere...");
                sleep(2);
                puts("La CPU ya eligió");
                system("pause");

            //CASILLEROS VACIOS PARA QUE LA CPU JUEGUE
            while(rellenar==0){
                aleatorio = (rand() % 9) + 1;
                if (aleatorio == 1 && tablero[0][0] == '-'){
                    tablero[0][0] = 'O';
                    rellenar = 1;
                }else if (aleatorio == 2 && tablero[0][1] == '-'){
                    tablero[0][1] = 'O';
                    rellenar = 1;
                }else if (aleatorio == 3 && tablero[0][2] == '-'){
                    tablero[0][2] = 'O';
                    rellenar = 1;
                }else if (aleatorio == 4 && tablero[1][0] == '-'){
                    tablero[1][0] = 'O';
                    rellenar = 1;
                }else if (aleatorio == 5 && tablero[1][1] == '-'){
                    tablero[1][1] = 'O';
                    rellenar = 1;
                }else if (aleatorio == 6 && tablero[1][2] == '-'){
                    tablero[1][2] = 'O';
                    rellenar = 1;
                }else if (aleatorio == 7 && tablero[2][0] == '-'){
                    tablero[2][0] = 'O';
                    rellenar = 1;
                }else if (aleatorio == 8 && tablero[2][1] == '-'){
                    tablero[2][1] = 'O';
                    rellenar = 1;
                }else if (aleatorio == 9 && tablero[2][2] == '-'){
                    tablero[2][2] = 'O';
                    rellenar = 1;
                }
            }

                puts("La CPU ya eligió");
                imprimirTablero(tablero);
                system("pause");
            }
            // Verificar si el jugador ganó
        if (verificarGanador(tablero)) {
            imprimirTablero(tablero);
            if (turno % 2 != 0){
                printf("¡Jugador %s ha ganado!\n",nombre);
            }else if (turno % 2 == 0){
                printf("¡La CPU le ha ganado!\n");
            }else{
                printf("¡Hubo un empate!\n");
            }
            return;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    char tablero[3][3];
    int op,bandera;

    bandera = 0;

    printf("Preparando tablero...\n");
    sleep(2);
    inicializarTablero(tablero);
    system("pause");
    system("cls");
    printf("Tablero listo: \n\n");
    imprimirTablero(tablero);
    printf("\n");
    system("pause");

    do{
        system("cls");
        puts("*********************************");
        puts("***********TA-TE-TI**************");
        puts("*********************************");
        puts("Menú");
        puts("1. Modo 1vs1");
        puts("2. Modo vs CPU");
        puts("3. Salir");
        puts("----------");
        printf("Opción: ");
        scanf("%d",&op);

        while(op>3 || op<1){
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts("Opción invalida, intente de nuevo...");
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            printf("Opción: ");
            scanf("%d",&op);
        }

        switch(op){
            case 1:
                system("cls");
                inicializarTablero(tablero);
                jugarTurno(tablero);
                printf("Volviendo al menú...\n");
                system("pause");
                break;
            case 2:
                system("cls");
                inicializarTablero(tablero);
                jugarTurnoCPU(tablero);
                printf("Volviendo al menú...\n");
                system("pause");
                break;
            case 3:
                bandera = 1;
                break;
        }
    }while (bandera!=1);

    return 0;
}
