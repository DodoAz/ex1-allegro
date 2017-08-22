/***************************************************************************
 *   Copyright (C) 2017 by Douglas Azevedo Pereira Dantas                  *
 *   douglasazevedo839@gmail.com                                           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/* Para compilar use:
 *     $gcc ex1.c -o ex1.x -Wall `allegro-config --cflags --libs`
 *     $make ex1.x
 */


/* Definicoes de algumas cores */

#define CORBRANCO (makecol(255,255,255))
#define CORPRETO 1
#define CORCINZA (makecol(160,160,160))
#define CORAZUL (makecol(0, 0, 255))
#define CORVERDE (makecol(0, 255, 0))
#define CORAMARELO (makecol(255,255,100))
#define CORVERMELHO (makecol(255, 0, 0))

#define IMAGENAME "ex1.bmp" /* nome do arquivo de imagem */

#define WIDTH 360 /* Pixels de largura da imagem gerada */
#define HEIGHT 200 /* Pixels de altura da imagem gerada */

#include <stdio.h>
#include <allegro.h>

void linetriangle(BITMAP *bmp, int x1, int y1, int x2, int y2, int x3, int y3, int color); /* Cria as linhas laterais de um triangulo */

/*
 * A funcao main realizada todo o processamento principal do programa, gerando ao final um arquivo de extensao .bmp com as figuras e formados programados.
 * Nesta versao foi criado o simbolo das reliquias da morte.
*/
int main(void)
{
    BITMAP *buff;
    PALETTE pal;

    if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
        exit(EXIT_FAILURE);

    set_color_depth(16);
    get_palette(pal);

    // Create a buffer for smooth animation.
    buff = create_bitmap(WIDTH, HEIGHT);
    if(buff == NULL)
    {
        printf("Could not create buffer!\n");
        exit(EXIT_FAILURE);
    }

    /* Onde existe HEIGHT-N (N para qualquer numero inteiro), isto se deve ao fato da relacao de Y ser invertida ao plano cartesiano. */
    linetriangle(buff, 60, HEIGHT-30, 300, HEIGHT-30, 180, HEIGHT-190, CORBRANCO); /* A capa */
    circle(buff, 180, HEIGHT-90, 60, CORBRANCO); /* A pedra */
    vline(buff, 180, HEIGHT-30, HEIGHT-190, CORBRANCO); /* A varinha */
    textprintf_ex(buff, font, 1, HEIGHT-20, CORBRANCO, CORPRETO, "    TOGETHER THEY MAKE ONE MASTER OF DEATH");

    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();

    printf("Imagem %s salva com sucesso!\n", IMAGENAME);

    return EXIT_SUCCESS;
}
END_OF_MAIN();

/***************************************************************************/
/* linetriangle
 * Funcao que cria as linhas laterais de um triangulo, baseando-se nos 3 vertices, na cor e no BITMAP recebidos.
*/
void linetriangle(BITMAP *bmp, int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
    line(bmp, x1, y1, x2, y2, color);
    line(bmp, x1, y1, x3, y3, color);
    line(bmp, x2, y2, x3, y3, color);
}

