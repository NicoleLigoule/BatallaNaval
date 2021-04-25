#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "functions.h"
#include "rlutil.h"


int main(){
    int m[12][12]={0};
    int opcion_menu, dtotalesj1, dtotalesj2, mp = 0, dosjugadores = 0;
    char jugador[25], jugador1[25], jugador2[25];
rlutil::setColor(rlutil::YELLOW);
cout << "PRESIONE ENTER PARA COMENZAR" << endl;
cin.get();
system("cls");

do{
opcion_menu=menu(mp);


switch(opcion_menu)
{
case 1:

    juego1(m, jugador);
    system("cls");


break;

case 2:
    juego2(m, opcion_menu, jugador1, jugador2, dtotalesj1, dtotalesj2);
    dosjugadores++;
    MatrizEnCero(m);
break;

case 3:

    if(dosjugadores == 0){
        cout << "ESTA OPCION SOLO ESTARA DISPONIBLE PARA EL JUEGO DE 2 JUGADORES" << endl << endl;
        cout << "PRESIONE ENTER PARA CONTINUAR" << endl;
        cin.get();
        system("cls");
    }
    else{

     mostrarpuntuacion(dtotalesj1, dtotalesj2, jugador1, jugador2);

    }
}

}while(opcion_menu!=0);

system("pause");

    return 0;
}
