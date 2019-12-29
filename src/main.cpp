#include <graphics.h>
#include <winbgim.h>
#include "../include/functions.h"   // Merge un folder inapoi, dupa care intra in folder-ul "include"

#define LATIME 1200
#define INALTIME 1000
#define TITLU "Impartirea Careului"

/* Declara variabilele marcate ca "extern" in fisierul header "functions.h" */
unsigned int tabla[LINII][COLOANE];
unsigned int nrBuline = 1;


int main() {
    int eroare, x, y, linie, coloana, patrat = 7, culoare = 1;

    // Initializeaza fereastra
    initwindow(LATIME, INALTIME, TITLU);

    // Verificare erori si inchiderea imediata a programului in cazul in care acestea apar, informand utilizatorul
    eroare = graphresult();

    if (eroare != grOk) {    // a aparut o eroare
        cout << "[Eroare]: " << grapherrormsg(eroare) << endl;
        cout << "Apasati orice tasta pentru a opri programul..." << endl;

        getch();
        return -1;  // inchiderea programului si indicarea faptului ca procesul nu s-a terminat cu succes
    }

    // Deseneaza tabla de joc
    creeaza_tabla();

    // Creeaza butoanele
    soft_reset();
    hard_reset();
    buton_afisare_instructiuni();

    while(nrBuline <= 8)
    {
        getmouseclick(WM_LBUTTONDOWN, x, y);
        deseneaza_bulina(x, y);
        getmouseclick(WM_RBUTTONDOWN,x,y);
            sterge_bulina(x,y);
    }

bucla:
    while(true)
    {
        getmouseclick(WM_LBUTTONDOWN, x, y);

        // Verificare pentru butonul "SOFT RESET"
        if(x < 210 && y < 50 && x > 10 && y > 10)
        {
            restart_mic2:
                for(int i=1;i<=8;i++)
                    for(int j=1;j<=8;j++)
                    {
                      if(tabla[i][j]!=OCUPAT)
                        {
                            tabla[i][j]=LIBER;
                            setfillstyle(SOLID_FILL,0);
                            floodfill(j*50+355,i*50+355,15);
                        }else{
                            setfillstyle(SOLID_FILL,0);
                            floodfill(j*50+355,i*50+355,15);
                        }
                    }
                culoare=1;
                patrat=7;
                goto bucla;
        }else if (x < 420 && y < 50 && x > 220 && y > 10) {
            // Verificare pentru butonul "HARD RESET"
        }else if (x < 675 && y < 50 && x > 430 && y > 10) {
            // Verificare pentru butonul "INSTRUCTIUNI"
        }

        linie = (y - 400) / 50 + 1;
        coloana = (x - 400) / 50 + 1;

        if(tabla[linie][coloana] == OCUPAT)
        {
            setcolor(culoare);
            culoare++;
            for(int i = 1; i <= 4; i++) {
                rectangle((x - 400) / 50 * 50 + i + 400, (y - 400) / 50 * 50 + i + 400,
                          (x - 400) / 50 * 50 + 50 - i + 400, (y - 400) / 50 * 50 + 50 - i + 400);
            }

            while(patrat)
            {
                getmouseclick(WM_LBUTTONDOWN, x, y);
                if(x<150 && y<100 && x>0 && y>0)
                    goto restart_mic2;

                if(x > 400 && x < 800 && y > 400 && y < 800) {
                    if(((((x - 400) / 50 + 2 == coloana) || ((x - 400) / 50 == coloana)) && (linie == (y - 400) / 50 + 1)) ||
                       ((((y - 400) / 50 + 2 == linie) || ((y - 400) / 50 == linie)) && (coloana == (x - 400) / 50 + 1))) {
                        if(tabla[(y - 400) / 50 + 1][(x - 400) / 50 + 1] == 0)
                        {
                            for(int i = 1; i <= 4; i++)
                                rectangle((x - 400) / 50 * 50 + i + 400, (y - 400) / 50 * 50 + i + 400,
                                          (x - 400) / 50 * 50 + 50 - i + 400, (y - 400) / 50 * 50 + 50 - i + 400);

                            patrat--;
                            linie = (y - 400) / 50 + 1;
                            coloana = (x - 400) / 50 + 1;
                            tabla[linie][coloana] = 1;
                        } // sfarsit if
                    }   // sfarsit if
                } // sfarsit if
            }   // sfarsit while
        }   // sfarsit if mare
        patrat = 7;
    }   // sfarsit while mare

        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
                cout<<tabla[i][j]<<" ";
                cout<<endl;
        }

    // "curatare"
    getch();
    closegraph();
    return 0;
}
