#include "draw.h"

void draw_header (Player player, int width) {
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),5,5,0,"%s","NOM:");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),width/2,5,0,"%s","TEMPS:");
    if (strlen(player.nom_player) <= 10) {
        al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(WHITE),25,20,0,"%s", player.nom_player);
        al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(WHITE),width/2 + 20, 20,0,"%d", player.temps);
    }
    else {
        if (strlen(player.nom_player) <= 15) {
            al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),25,20,0,"%s", player.nom_player);
            al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),width/2 + 20, 20,0,"%d", player.temps);
        }
        else {
            al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),25,20,0,"%s", player.nom_player);
            al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),width/2 + 20, 20,0,"%d", player.temps);
        }
    }
}

void draw_squares (Taulell taulell) {
    int i_fil, j_col;
    int x1 = 1;
    int y1 = HEADER_SIZE + 1;
    int x2 = x1 + SQUARE_SIZE;
    int y2 = y1 + SQUARE_SIZE;
    
    //al_draw_filled_rectangle (x1, y1, x2, y2,LS_allegro_get_color(GRAY));
    //printf ("F %d C %d\n", taulell.fila, taulell.col);
    for (i_fil = 0; i_fil < taulell.fila; i_fil++) {
        for (j_col = 0; j_col < taulell.col; j_col++) {
            al_draw_filled_rectangle (x1, y1, x2, y2,LS_allegro_get_color(GRAY));
            x1 += (SQUARE_SIZE + 1);
            x2 += (SQUARE_SIZE + 1);
        }
        x1 = 1;
        x2 = x1 + SQUARE_SIZE;
        y1 += (SQUARE_SIZE + 1);
        y2 += (SQUARE_SIZE + 1);
    }
}