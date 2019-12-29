#ifndef HEADER_FILE
#define HEADER_FILE

#include <iostream>
#include <cstring>

#define LATIME_TABEL 400
#define INALTIME_TABEL 400
#define LINII 9
#define COLOANE 9
#define LIBER 0
#define OCUPAT 9

/* Informeaza compilatorul despre existenta acestor variabile, iar acesta va cauta
 * declaratia acestor variabile in fisierele sursa ce includ aceasta librarie */
extern unsigned int tabla[LINII][COLOANE];
extern unsigned int nrBuline;

using namespace std;


/* Creeaza in mod vizual tabla de joc.
 * Tabelul este creat utilizand linii.
 */
void creeaza_tabla()
{
    char numar_linie[2];

    // deseneaza conturul tablei cu linii intrerupte, groase
    setlinestyle(DASHED_LINE, 0x3333, THICK_WIDTH);
    line(LATIME_TABEL, INALTIME_TABEL, 2 * LATIME_TABEL, INALTIME_TABEL);
    line(LATIME_TABEL, INALTIME_TABEL, LATIME_TABEL, 2 * INALTIME_TABEL);
    line(LATIME_TABEL, 2 * INALTIME_TABEL, 2 * LATIME_TABEL, 2 * INALTIME_TABEL);
    line(2 * LATIME_TABEL, 2 * INALTIME_TABEL, 2 * LATIME_TABEL, INALTIME_TABEL);

    // restabileste stilul liniilor la normal pentru a desena celulele tablei
    setlinestyle(SOLID_LINE, 0x3333, NORM_WIDTH);
    settextstyle(10, HORIZ_DIR, 4);

    // numerotare pe verticala
    for (int i = 410, c = 1; c < 9; i += 50, c++) {
        itoa(c, numar_linie, 10);	// converteste variabila c in sir de caractere
        outtextxy(370, i, numar_linie);
    }

    // numerotare pe orizontala
    for (int i = 415, c = 1; c < 9; i += 50, c++) {
        itoa(c, numar_linie, 10);
        outtextxy(i, 365, numar_linie);
    }

    // deseneaza celulele tablei
    for (int i = 50; i <= 400; i += 50)
    {
        line(LATIME_TABEL + i, INALTIME_TABEL, LATIME_TABEL + i, 2 * INALTIME_TABEL);
        line(LATIME_TABEL, INALTIME_TABEL + i, 2 * LATIME_TABEL, INALTIME_TABEL + i);
    }
}


/* Deseneaza o bulina intr-un patrat din tabla de joc */
void deseneaza_bulina(int x, int y)
{
    unsigned int linie, coloana;

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    linie = (y - LATIME_TABEL) / 50 + 1;
    coloana = (x - INALTIME_TABEL) / 50 + 1;

    if (x > LATIME_TABEL&& x < 2 * LATIME_TABEL && y > INALTIME_TABEL&& y < 2 * INALTIME_TABEL)
        if (tabla[linie][coloana] == LIBER)
        {
            nrBuline++;
            tabla[linie][coloana] = OCUPAT;
            circle(LATIME_TABEL + coloana * 50 - 25, INALTIME_TABEL + linie * 50 - 25, 20);
            fillellipse(LATIME_TABEL + coloana * 50 - 25, INALTIME_TABEL + linie * 50 - 25, 20, 20);
        }
}

void sterge_bulina(int x,int y)
{
    if(x > 400 && x < 800 && y > 400 && y < 800 && tabla[(y-400)/50+1][(x - 400) / 50 + 1]==OCUPAT)
            {

           nrBuline--;
           setcolor(0);
           circle((x-400)/50*50+425,(y - 400) / 50*50+425,20);
           setfillstyle(SOLID_FILL,0);
           fillellipse((x-400)/50*50+425,(y - 400) / 50*50+425,20,20);
           tabla[(y-400)/50+1][(x - 400) / 50 + 1]=0;
            }
}

void buton_restart()
{
    outtextxy(10,20,"RESTART");
    outtextxy(10,40,"MIC");
    for(int k=1;k<=5;k++)
    {
     setcolor(15);
    line(150+k,0,150+k,105);
    line(0,100+k,150,100+k);
    line(k-1,0,k-1,100);
    line(0,k-1,150,k-1);
    }
}

#endif
