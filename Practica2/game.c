#include "game.h"
#include "draw.h"

void fflushnou () {
    char buffer[20];   
    fgets (buffer,20,stdin);
    //while((getchar()) != '\n);
}

int sacarNumero (char *aux) {
    int num = 0;
    int i_aux = 2, i_cad = 0;
    char *cad = (char*)malloc(sizeof(char) * 5);
    printf ("AUX: %s\n", aux);
    printf ("AUX NUM: %c\n", aux[i_aux]);
    while (aux[i_aux] != '\n') {
        cad[i_cad++] = aux[i_aux++];
    }
    cad[i_cad] = '\0';
    num = myAtoi(cad);
    printf ("num: %d\n", num);
    return num;
}

Taulell sacarTaulell (FILE *f_taulell) {
    Taulell taulell;
    int i, j;
    int i_aux;
    char *aux = (char*)malloc(sizeof(char) * MAXAUX);
    
    fgets (aux, MAXAUX, f_taulell);
    taulell.col = sacarNumero (aux);
    fgets (aux, MAXAUX, f_taulell);
    taulell.fila = sacarNumero (aux);
    fgets (aux, MAXAUX, f_taulell);
    taulell.num_mines = sacarNumero (aux);
    
    // Guardem memoria per al taulell
    taulell.mines = (char**)malloc(sizeof(char*) * taulell.fila);
    for (i = 0; i < taulell.fila; i++) {
        taulell.mines[i] = (char*)malloc(sizeof(char) * taulell.col);
    }
    
    // Llegir cada fila del fitxer per construir el taulell
    for (i = 0; i < taulell.fila; i++) {
        i_aux = 0;
        fgets (aux, MAXAUX, f_taulell);
        for (j = 0; j < taulell.col; j++) {
            taulell.mines[i][j] = aux[i_aux++];
        }
        aux[i_aux] = '\0';
        printf ("F%d: %s\n",i, taulell.mines[i]);
    }
    
    // Inicialitzar que totes les caselles no estan girades
    // 0: no girada; 1: girada
    taulell.turned = (int**)malloc(sizeof(int*) * taulell.fila);
    for (i = 0; i < taulell.fila; i++) {
        taulell.turned[i] = (int*)calloc(taulell.col, sizeof(int));
    }
    
    printf ("GIR:\n");
    for (i = 0; i < taulell.fila; i++) {
        for (j = 0; j < taulell.col; j++)
            printf ("%d", taulell.turned[i][j]);
        printf ("\n");
    }
    return taulell;
}

void startGame (Taulell *taulell, Player player) {
    int nSortir = 0;
    //int header_size = 100;
    int width, height;
    
    width = 81 * taulell->col + 1;
    height = HEADER_SIZE + 81 * taulell->fila;
  
    printf ("c:%d f:%d m:%d\n", taulell->col, taulell->fila, taulell->num_mines);
    printf ("w: %d h: %d\n", width, height);
    
    //Inicialitzem Allegro
    LS_allegro_init(width, height, "Buscamines");
    //LS_allegro_init(1280,720, "hello");
    
    //Bucle infinit del joc
    while(!nSortir){
        //Escoltem el teclat esperant la tecla ESC
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            nSortir = 1;
        }
        
        //Donem l'ordre d'escriure el text de benvinguda
        //al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),200,300,0,"%s","Benvingut a Allegro! Prem ESC per sortir...");

        draw_header (player, width);
        draw_squares (*taulell);
        //Pintem la pantalla de la finestra gràfica
        LS_allegro_clear_and_paint(BLACK);
        
        
    }

    //Tanquem la finestra gràfica
    LS_allegro_exit();
}

int myAtoi (char *num) {
    int number = 0;
    int negatiu = 0;
    int i_num = 0;
    
    // Mirem si el numero es negatiu
    if (num[i_num] == '-') {
        negatiu = 1;
        ++i_num;
    }
    while (num[i_num] != '\0') {
        number = number * 10 + num[i_num++] - '0';
    }
    if (negatiu == 1) {
        number *= -1;
    }
    return number;
}
