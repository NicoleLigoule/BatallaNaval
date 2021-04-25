#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "rlutil.h"

int menu(int);
void cargarnombres(char[], char[]);
void juego1(int[12][12], char[]);
int VerificacionesHV1(int [12][12], int, int, int, int, bool);
void dispararJ1(int[12][12], char[], int);
void juego2(int[12][12], int, char[], char[], int&, int&);
void CargarBarcos(int[12][12]);
void mostrarMatriz(int[12][12]);
void mostrarmatriz2modo1(char[12][12], char[], int, int, int, int, int);
void mostrarmatriz2(char[12][12], char [], char [], int , int , int , int , int);
void disparar(int[12][12], char[], char[], int, int&, int&);
void mostrarpuntuacion(int&, int&, char [], char[]);
void MatrizEnCero(int [12][12]);

///menu ;)
int menu (int opcion){
do{
rlutil::setColor(rlutil::RED);
rlutil::locate(40,8);
cout << "------------------------------------" << endl;
rlutil::locate(51,12);
rlutil::setColor(rlutil::YELLOW);
cout << "BATALLA NAVAL" << endl << endl;
rlutil::locate(40,16);
rlutil::setColor(rlutil::RED);
cout << "------------------------------------" << endl;
rlutil::setColor(rlutil::BROWN);
rlutil::locate(57,17);
cout << "||" << endl;
rlutil::locate(57,18);
cout << "||" << endl;
rlutil::locate(57,19);
cout << "||" << endl;

rlutil::locate(23,19);
rlutil::setColor(rlutil::LIGHTBLUE);
cout << "-----------------------------------------------------------------------" << endl;
rlutil::setColor(rlutil::LIGHTGREEN);
rlutil::locate(24,20);
cout << "Presione       1       para        juego          de     1    jugador" << endl;
rlutil::locate(25,21);
rlutil::setColor(rlutil::LIGHTBLUE);
cout << "------------------------------------------------------------------" << endl;
rlutil::locate(26,22);
rlutil::setColor(rlutil::LIGHTGREEN);
cout << "Presione       2     para        juego      de     2   jugadores" << endl;
rlutil::locate(27,23);
rlutil::setColor(rlutil::LIGHTBLUE);
cout << "--------------------------------------------------------------" << endl;

rlutil::locate(28,24);
rlutil::setColor(rlutil::LIGHTGREEN);
cout << "Presione       3   para    mostrar   puntuacion   mas  alta" << endl;
rlutil::locate(29,25);
rlutil::setColor(rlutil::LIGHTBLUE);
cout << "---------------------------------------------------------" << endl;
rlutil::locate(30,26);
rlutil::setColor(rlutil::LIGHTGREEN);
cout << "Presione       0      para     finalizar   el    juego" << endl;
rlutil::locate(31,27);
rlutil::setColor(rlutil::LIGHTBLUE);
cout << "----------------------------------------------------" << endl;

rlutil::setColor(rlutil::YELLOW);

cin >> opcion;
system("cls");
}while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=0);

cin.ignore();
return opcion;
}










/// cargar nombres
void cargarnombres(char j1[25], char j2[25]){

    cout << "NOMBRE DEL JUGADOR 1: ";
    cin.getline(j1,25);
    system("cls");
    cout << "NOMBRE DEL JUGADOR 2: ";
    cin.getline(j2,25);
    system("cls");


}










/// poner matriz en 0
void MatrizEnCero(int m[12][12]){
    int i, j;
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
                m[i][j] = 0;
        }
    }
}










///cargar barcos
void CargarBarcos(int m[12][12]){
 int j, i, l, X, Y, h_v;
 bool direcciones = false;


/// pongo la matriz en 0 aca para poder volver a usarla
MatrizEnCero(m);

 for(i=1;i<=5;i++){
    cout << "Ingrese la posicion del barco de " << i << " casilleros." << endl;
/// do while para que si agregas una ubicacion negativa, te de la opcion de insertar otra
        mostrarMatriz(m);

 do{
    cout << "Fila (del 1 al 10): ";
    cin >> X;
    cout << "Columna (del 1 al 10): ";
    cin >> Y;
    direcciones = true;

                /// VERIFICACION NUMERO 1
                if(X<1 || Y<1 || X>10 || Y>10 || m[X][Y] != 0){
                rlutil::setColor(rlutil::RED);
                cout << "No se puede ubicar el barco ahi." << endl;
                direcciones = false;
                rlutil::setColor(rlutil::YELLOW);
                }

    }while(X<1 || Y<1 || X>10 || Y>10 || m[X][Y] != 0 || direcciones == false); /// Primera vuelta lo aplica sin preguntar direccion porque es de 1
        m[X][Y]=i;
       system("cls");
         /// porque sino queda en infinito validando y solo te pide los ingresos
        if(i !=1){
            mostrarMatriz(m);
            cout << endl << endl;
            cout << "Elija direccion: " << endl;
            cout << "1_ Posicion Vertical hacia ARRIBA." << endl;
            cout << "2_ Posicion Vertical hacia ABAJO." << endl;
            cout << "3_ Posicion Horizontal hacia la DERECHA." << endl;
            cout << "4_ Posicion Horizontal hacia la IZQUIERDA." << endl;
            cin >> h_v;

                while(h_v<1 || h_v>5){
                    cout << "Ingresa una direccion valida.";
                    cin >> h_v;
                }
                system("cls");

            /// SEGUNDO FOR en el que i es el barco y J es los lugares faltantes de lo que va a ocupar el barco - Informa las ocupaciones que tendrá el barco en la matriz [informar < verificar]
            for(j=1;j<=i-1;j++){
/// En esta seccion hay 2 IFS iguales, pero pasa que en el primero, si se pone algun case en false, seguiria haciendo lo de abajo
/// que basicamente es escribir en la matriz TALES POSICIONES, entonces para evitar eso, se hace otro if direcciones == true

                    if(direcciones==true){

                        switch(h_v){
                            case 1:
                            /// VERTICAL ARRIBA
                               /// Si J esta en 0, es porque no tiene nada q borrar, porque si hubiera tenido estaria 1

                            if((X-j)<=0 || m[X-j][Y] != 0){
                                cout << "Eso esta mal, volveme a colocar las direcciones1: " << endl;
                                cin.get();
                                for(l=1;l<=j-1;l++){ /// FOR para limpiar cuando hubo un error
                                    m[X-l][Y] = 0;
                                    }
                                m[X][Y] = 0;
                                direcciones = false;
                                i=i-1;

                                }
                                break;
                            case 2:
                            /// VERTICAL ABAJO
                            if((X+j)>10 || m[X+j][Y] != 0){
                                cout << "Eso esta mal, volveme a colocar las direcciones2: " << endl;
                                cin.get();
                                for(l=1;l<=j-1;l++){ /// FOR para limpiar cuando hubo un error
                                    m[X+l][Y] = 0;
                                    }
                                m[X][Y] = 0;
                                direcciones = false;
                                i=i-1;

                                }
                                break;

                            case 3:
                            /// HORIZONTAL DERECHA
                            if((Y+j)>10 || m[X][Y+j] != 0 ){
                                cout << "Eso esta mal, volveme a colocar las direcciones3";
                                cin.get();
                                for(l=1;l<=j-1;l++){ /// FOR para limpiar cuando hubo un error
                                    m[X][Y+l] = 0;
                                }
                                m[X][Y] = 0;
                                direcciones = false;
                                i=i-1;

                                }
                                break;

                            case 4:
                            /// HORIZONTAL IZQUIERDA
                            if((Y-j)<=0 || m[X][Y-j] != 0){
                                cout << "Eso esta mal, volveme a colocar las direcciones4";
                                cin.get();
                                    for(l=1;l<=j-1;l++){ /// FOR para limpiar cuando hubo un error
                                    m[X][Y-l] = 0;
                                    }
                                    m[X][Y] = 0;
                                    direcciones = false;
                                    i=i-1;

                                    }
                                break;
                            }
/// ACA LO QUE HACE ES INSERTAR EN LA MATRIZ LO QUE VERIFICO EN LA VERIFICACION 2
                    if(direcciones == true){
                        switch(h_v){
                        case 1:
                        /// VERTICAL ARRIBA
                        m[X-j][Y]=i;
                break;

            case 2:
                /// VERTICAL ABAJO
                        m[X+j][Y]=i;
                break;

            case 3:
                /// HORIZONTAL DERECHA
                        m[X][Y+j]=i;
                break;

            case 4:
                /// HORIZONTAL IZQUIERDA
                        m[X][Y-j]=i;
                break;
            }
                        } /// direcciones true2
                    }/// direcciones true1
                            } /// FOR
        }/// IF distinto de 1
        mostrarMatriz(m);
        cin.get();
        system("cls");
        } /// este es del FOR GRANDE

    direcciones = false;
 }













void mostrarMatriz(int m[12][12]){
    int i, j;
    cout << endl << endl;

    for(i=0;i<=10;i++){
            if(i==0){
            rlutil::setColor(rlutil::YELLOW);
            cout << "f/c   ";
            }else{
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << i << "  ";
            }

        for(j=1;j<=10;j++){
            if(i == 0 && j!=0){
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << j << "\t" << "   ";
            }else{
                if(i==10 && j==1){
                rlutil::setColor(rlutil::YELLOW);
                cout<< "  ";
                cout << m[i][j]<< "\t";
                }else{
                rlutil::setColor(rlutil::YELLOW);
                cout<< "   ";
                cout << m[i][j]<< "\t";
                }
            }

        }
        cout << "\n";

    }
    cin.ignore();

}










/// Funcion del juego para 1 Jugador
void juego1(int m[12][12], char jugador[25]){


int i, X = 0, Y = 0, h_v, disparosestimados;
bool direcciones=true;

cout << "NOMBRE DEL JUGADOR: ";
cin >> jugador;
cout << endl;
system("pause");
system("cls");
cin.ignore();

/// EXPLICACION DEL MODO
cout << "EN ESTE MODO SE TE PEDIRA UNA CANTIDAD DE TIROS EN LAS QUE CREAS QUE PODRAS HUNDIR LA FLOTA ENEMIGA." << endl;
cout << "SI ELIMINAS TODA LA FLOTA EN UNA CANTIDAD MENOR O IGUAL A LA ESTIMADA GANAS, DE LO CONTRARIO PERDES." << endl;
cin.get();
system("cls");


do{
cout << "EN CUANTOS DISPAROS CREES PODER DERRIBAR TODA LA FLOTA ENEMIGA?" << endl;
cout << "(recorda que para derribar toda la flota enemiga necesitas al menos 15 disparos)" << endl;
cin >> disparosestimados; /// MODO 1 JUGADOR


///verificacion para que no sea menor a 15 ni mayor a 100
if(disparosestimados<15 || disparosestimados>100){

cout << "Esta cantidad de disparos no es posible. Vuelva a ingresar la cantidad de disparos. " << endl;
system("pause");
system("cls");

}
}while(disparosestimados<15 || disparosestimados>100);


cin.ignore();
cout << "BUENO... YA VEREMOS ;)";
cin.get();
system("cls");
cout << "Ok, voy a posicionar mi flota y luego te dejare atacarme... o intentarlo ;)" << endl;
cout << "Espera unos segundos mientras planifico mi estrategia..." << endl;
cin.get();
system("cls");

    /// UBICACION ALEATORIA DE BARCOS

    for(i=1;i<=5;i++){
    direcciones = false;
     /// do while para que los numeros randoms no se pisen
     do{
     X = (rand()%10+1);
     Y = (rand()%10+1);
     direcciones = true;
     }while (m[X][Y]!= 0 || direcciones == false);
        m[X][Y]=i;
        if(i!=1){
        srand(time(NULL));
        h_v = (rand()%4+1);
    i = VerificacionesHV1(m, X, Y, h_v, i, direcciones);
       }/// if i!=1
    }/// for de 5

    cout << "Estoy listo. Ya podes empezar a atacar!" << endl;
    system("pause");
    system("cls");
    cout << "ATENTO QUE SI NO ME HUNDIS LA FLOTA EN " << disparosestimados << " DISPAROS, PERDES!" << endl;
    cin.get();
    system("cls");

    dispararJ1(m, jugador, disparosestimados);


}












/// funcion para verificaciones del juego 1
int VerificacionesHV1(int m[12][12], int X, int Y, int h_v, int i, bool direcciones){
    int j, l;
         for(j=1;j<=i-1;j++){ /// SEÑALA AL PROGRAMA CUANTAS POSICIONES TIENE QUE AGREGAR EN CASO DE UBICARLO ASI
               if(direcciones == true){
                        switch(h_v){
                            case 1:
                            /// VERTICAL ARRIBA
                    /// Si J esta en 0, es porque no tiene nada q borrar, porque si hubiera tenido estaria 1
                    /// "x-l" es para que no se vaya afuera de la matriz
                    /// m[X-l][Y] != 0 para verificar que la posicion en la que pongamos los otros puntos restantes no este ocupada
                            if((X-j)<=0 || m[X-j][Y] != 0){

                                for(l=1;l<=j-1;l++){ /// FOR para limpiar cuando hubo un error
                                    m[X-l][Y] = 0;
                                    }
                                m[X][Y] = 0;
                                direcciones = false;
                                i=i-1;

                                }
                                break;
                            case 2:
                            /// VERTICAL ABAJO
                            if((X+j)> 10 || m[X+j][Y] != 0){

                                for(l=1;l<=j-1;l++){
                                    m[X+l][Y] = 0;
                                    }
                                m[X][Y] = 0;
                                direcciones = false;
                             i=i-1;

                                }
                                break;

                            case 3:
                            /// HORIZONTAL DERECHA
                            if((Y+j)> 10 || m[X][Y+j] != 0 ){

                                for(l=1;l<=j-1;l++){
                                    m[X][Y+l] = 0;
                                }
                                m[X][Y] = 0;
                                direcciones = false;
                               i=i-1;

                                }
                                break;

                            case 4:
                            /// HORIZONTAL IZQUIERDA
                            if((Y-j)<=0 || m[X][Y-j] != 0){

                                    for(l=1;l<=j-1;l++){
                                    m[X][Y-l] = 0;
                                    }
                                    m[X][Y] = 0;
                                    direcciones = false;
                                 i=i-1;

                                    }
                                break;
                            }

                    /// ACA LO QUE HACE ES INSERTAR EN LA MATRIZ LO QUE VERIFICO EN LA VERIFICACION 2
                    if(direcciones == true){

                        switch(h_v){
                    case 1:
                        /// VERTICAL ARRIBA
                        m[X-j][Y]=i;
                            break;

                    case 2:
                /// VERTICAL ABAJO
                        m[X+j][Y]=i;
                            break;

                    case 3:
                /// HORIZONTAL DERECHA
                        m[X][Y+j]=i;
                            break;

                    case 4:
                /// HORIZONTAL IZQUIERDA
                        m[X][Y-j]=i;
                            break;
                        }

                    } /// direcciones true

               }
            }///FOR de J

      return i;
    }













/// funcion para la puntuacion
void mostrarpuntuacion(int& dtotalesj1, int& dtotalesj2, char jugador1[25], char jugador2[25]){

if(dtotalesj1<dtotalesj2){
cout << " ============================================================" << endl;
cout << "           "<<" GANADOR    ------->  " << jugador1 << "             " << endl;
cout << " ============================================================" << endl;
cout << "Disparos totales: " << dtotalesj1 << endl;
cout << "Disparos a los barcos: " << 15 << endl;
cout << "Disparos al agua: " << dtotalesj1-15 << endl;
}
else{
if(dtotalesj2<dtotalesj1){
cout << " ============================================================" << endl;
cout << "           "<<" GANADOR    ------->  " << jugador2 << "             " << endl;
cout << " ============================================================" << endl;
cout << "Disparos totales: " << dtotalesj2 << endl;
cout << "Disparos a los barcos: " << 15 << endl;
cout << "Disparos al agua: " << dtotalesj2-15 << endl;
}
else{
    cout << " ====================================" << endl;
    cout << " ||            "<<" EMPATE" << "             ||" << endl;
    cout << " ====================================" << endl;
    cout << "JUGADOR 1: " << jugador1 << endl;
    cout << "JUGADOR 2: " << jugador2 << endl << endl;
    cout << "Disparos totales: " << dtotalesj1 << endl;
    cout << "Disparos a los barcos: " << 15 << endl;
    cout << "Disparos al agua: " << dtotalesj1-15 << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    cout << "¡¡FELICITACIONES!!" << endl;
    cout << "Ambos son ganadores :)" << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

}

system("pause");
system("cls");

}











///funcion 2 jugadores
void juego2(int m[12][12], int opcion_menu, char jugadorA[25], char jugadorB[25], int& dtotalesj1, int& dtotalesj2){

int cambiarturnos=0;

cargarnombres(jugadorA,jugadorB);
cout << "JUGADOR 1: " << jugadorA << endl;
cout << "JUGADOR 2: " << jugadorB << endl;
cin.get();
system("cls");

cout << "EN ESTE MODO, EL JUGADOR 1 DEBERA UBICAR SU FLOTA Y EL JUGADOR 2 TENDRA QUE ELIMINAR SUS BARCOS.";
cin.get();
cout << "CUANDO EL JUGADOR 2 ACABE CON LA FLOTA ENEMIGA, SE INVERTIRAN LOS ROLES.";
cin.get();
cout << "QUIEN LOGRE HUNDIR TODA LA FLOTA EN MENOS DISPAROS GANA." << endl;
system("pause");
system("cls");
cout << "Okey " << jugadorA << " es hora de posicionar a tu flota!";
cin.get();
system("cls");
CargarBarcos(m);
disparar(m, jugadorA, jugadorB, cambiarturnos, dtotalesj1, dtotalesj2);

cambiarturnos++;

cout << "Okey " << jugadorB << " es hora de posicionar a tu flota!";
cin.get();
system("cls");
CargarBarcos(m);
disparar(m, jugadorA, jugadorB, cambiarturnos, dtotalesj1, dtotalesj2);

cout << "JUGADOR 1: " << jugadorA << endl;
cout << "DISPAROS TOTALES: " << dtotalesj1 << endl;
cout << endl << endl << "JUGADOR 2: " << jugadorB << endl;
cout << "DISPAROS TOTALES: " << dtotalesj2 << endl;

system("pause");
system("cls");

mostrarpuntuacion(dtotalesj1, dtotalesj2,jugadorA, jugadorB);

}












/// mostrar la matriz 2 para el modo de un jugador
void mostrarmatriz2modo1(char m2[12][12], char j1[25], int cd, int gb, int ta, int bh, int disparosestimados){

int i, j;

cout << j1 << " | GOLPES A BARCOS: " << gb << " | DISPAROS AL AGUA: " << ta << " DE " << disparosestimados-15 << " PERMITIDO/S | DISPAROS TOTALES: " << cd << "/" << disparosestimados << " |" << endl;


cout << endl << endl << "Mostrando matriz: \n" << endl;
  for(i=0;i<=10;i++){
            if(i==0){
               cout << "f/c   ";
            }else{
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << i << "  ";
            }
        for(j=1;j<=10;j++){
            if(i == 0 && j!=0){
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << j << "\t" << "   ";
            }else{
            rlutil::setColor(rlutil::YELLOW);
               if(i==10 && j==1){
                cout<< "  ";
                cout << m2[i][j]<< "\t";
                }else{
                cout<< "   ";
                cout << m2[i][j]<< "\t";
                }
            }
        }
        cout << "\n";
  }
cout << endl;
cout << "BARCOS HUNDIDOS: " << bh << " |";



}














///funcion mostrar matriz 2 PARA EL MODO 2
void mostrarmatriz2(char m2[12][12], char jA[25], char jB[25], int cd, int gb, int ta, int bh, int ct){

int i, j;

if(ct==0){
cout << jB << " | GOLPES A BARCOS: " << gb << " | DISPAROS AL AGUA: " << ta << " | DISPAROS TOTALES: " << cd << " |" << endl;
}
else{
cout << jA << " | GOLPES A BARCOS: " << gb << " | DISPAROS AL AGUA: " << ta << " | DISPAROS TOTALES: " << cd << " |" << endl;
}

cout << endl << endl << "Mostrando matriz: \n" << endl;
  for(i=0;i<=10;i++){
            if(i==0){
               cout << "f/c   ";
            }else{
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << i << "  ";
            }
        for(j=1;j<=10;j++){
            if(i == 0 && j!=0){
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << j << "\t" << "   ";
            }else{
            rlutil::setColor(rlutil::YELLOW);
               if(i==10 && j==1){
                cout<< "  ";
                cout << m2[i][j]<< "\t";
                }else{
                cout<< "   ";
                cout << m2[i][j]<< "\t";
                }
            }
        }
        cout << "\n";

  }
cout << endl;
cout << "BARCOS HUNDIDOS: " << bh << " |";


}














/// Funcion de disparos 2 jugadores
void disparar (int m1[12][12], char jA[25], char jB[25], int cturnos, int& dtotalesj1, int& dtotalesj2){

int i, j, Y, X, barcos_hundidos=0, crucero=0, submarino=0, buque=0, portaviones=0;
int tirosalagua=0, cant_disparos=0, golpesabarcos=0;
char m2[12][12];

 for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
                m2[i][j]='O';
        }
 }

/// aca es para ir cambiando el nombre segun el turno
if(cturnos==0){
cout << "Okey, " << jB << " es hora de derribar la flota enemiga!" << endl;
cin.get();
system("cls");
}
else{
cout << "Okey, " << jA << " es hora de derribar la flota enemiga!" << endl;
cin.get();
system("cls");
}



do{

do{
mostrarmatriz2(m2, jA, jB, cant_disparos, golpesabarcos,  tirosalagua, barcos_hundidos, cturnos);

cout << endl << endl;
cout << "Ingresa las coordenadas del lugar que queres atacar" << endl;
cout << "Fila (del 1 al 10): ";
cin >> X;
cout << "Columna (del 1 al 10): ";
cin >> Y;

if(X<1 || Y<1 || X>10 || Y>10 || m2[X][Y] =='X'){
cout << endl << endl;

if(X<1 || Y<1 || X>10 || Y>10){
rlutil::setColor(rlutil::LIGHTRED);
cout << "las coordenadas deben ser del 1 al 10" << endl;
}
else{
    cout << "Ya disparaste a esa posicion" << endl;
}


cin.ignore();
cin.get();
system("cls");
}
}while(X<1 || Y<1 || X>10 || Y>10 || m2[X][Y] =='X');



/// una vez que se verifico que las coordenadas son correctas se cuenta el disparo
cant_disparos++;

/// aca va cambiando la matriz 2, se cuentan los golpes para saber si hunden los barcos y cuenta los barcos hundidos
    if(m2[X][Y]== 'O'){

       if(m1[X][Y]!=0){
    rlutil::setColor(rlutil::LIGHTRED);
            m2[X][Y]= 'X';
            golpesabarcos++;


   if(m1[X][Y]==1){
    barcos_hundidos++;
    }
    else{
        if(m1[X][Y]==2){
            crucero++;
            if(crucero==2){
            barcos_hundidos++;
            }
            }

        else{
            if(m1[X][Y]==3){
                submarino++;
                if(submarino==3){
                barcos_hundidos++;
                }
                }

            else{
                if(m1[X][Y]==4){
                    buque++;
                    if(buque==4){
                    barcos_hundidos++;
                    }
                    }

                else{

                    if(m1[X][Y]==5){
                    portaviones++;
                    if(portaviones==5){
                    barcos_hundidos++;
                    }
                    }
                    }
          }
        }
    }

}

else{
rlutil::setColor(rlutil::LIGHTCYAN);
        m2[X][Y]= '~' ;
            tirosalagua++;
        }

}


system("cls");


/// Se actualiza la matriz
mostrarmatriz2(m2, jA, jB, cant_disparos, golpesabarcos,  tirosalagua, barcos_hundidos, cturnos);



if(m1[X][Y]==1){
    cout << endl << endl;
    cout << "Has hundido la lancha enemiga!" << endl;
    cin.ignore();
    cin.get();

    }
    else{
        if(m1[X][Y]==2){
            if(crucero==2){
            cout << endl << endl;
            cout << "Has hundido el crucero enemigo!" << endl;
            cin.ignore();
            cin.get();
            }
            }

        else{
            if(m1[X][Y]==3){
                if(submarino==3){
                cout << endl << endl;
                cout << "Has hundido el submarino enemigo!" << endl;
                cin.ignore();
                cin.get();
                }
                }

            else{
                if(m1[X][Y]==4){
                    if(buque==4){
                    cout << endl << endl;
                    cout << "Has hundido el buque enemigo!" << endl;
                    cin.ignore();
                    cin.get();
                    }
                    }

                else{

                    if(m1[X][Y]==5){
                    if(portaviones==5){
                    cout << endl << endl;
                    cout << "Has hundido el portaviones enemigo!" << endl;
                    cin.ignore();
                    cin.get();
                    }
                    }
                    }
          }
        }
    }



cout << endl << endl;
system("pause");
system("cls");

}while(barcos_hundidos!=5);
rlutil::setColor(rlutil::YELLOW);
cout << "FELICIDADES, HAS HUNDIDO TODA LA FLOTA ENEMIGA!" << endl << endl;

if(cturnos==0){
cout << jB << endl;
cout << "DISPAROS AL AGUA: " << tirosalagua << endl;
cout << "DISPAROS A LOS BARCOS: " << golpesabarcos << endl;
cout << "DISPAROS TOTALES: " << cant_disparos << endl;

dtotalesj2=cant_disparos;
}
else{
cout << jA << endl;
cout << "DISPAROS AL AGUA: " << tirosalagua << endl;;
cout << "DISPAROS A LOS BARCOS: " << golpesabarcos << endl;;
cout << "DISPAROS TOTALES: " << cant_disparos << endl;;
dtotalesj1=cant_disparos;

}

system("pause");
system("cls");

}










/// Funcion de disparos PARA UN JUGADOR
void dispararJ1(int m1[12][12], char j1[25], int disparosestimados){

int i, j, Y, X, tapermitidos, barcos_hundidos=0, crucero=0, submarino=0, buque=0, portaviones=0;
int tirosalagua=0, cant_disparos=0, golpesabarcos=0, opcionmm;
char m2[12][12];


 for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
                m2[i][j]='O';
        }
 }

tapermitidos=disparosestimados-15;

if(disparosestimados==16){
cout << "SOLO TENES PERMITIDO FALLAR (DISPARAR AL AGUA) "  << tapermitidos << " VEZ" << endl;
cout << "DE LO CONTRARIO PERDES PORQUE NO TE ALCANZAN LOS DISPAROS PARA DERRIBAR LA FLOTA ENEMIGA" << endl;
cin.get();
system("cls");
}
else{
cout << "SOLO TENES PERMITIDO FALLAR (DISPARAR AL AGUA) "  << tapermitidos << " VECES" << endl;
cout << "DE LO CONTRARIO PERDES PORQUE NO TE ALCANZAN LOS DISPAROS PARA DERRIBAR LA FLOTA ENEMIGA" << endl;
cin.get();
system("cls");
}



//muestra la matriz enemiga para testear
do{
cout << "Antes de disparar, si queres entrar al modo TEST(ver el mapa del enemigo para realizar pruebas), presiona 1. " << endl;
cout << "Si queres continuar el juego, presiona 2" << endl;


cin >> opcionmm;
system("cls");

if(opcionmm==1){
    rlutil::setColor(rlutil::LIGHTRED);
    cout << "Mapa enemigo" << endl;
    rlutil::setColor(rlutil::YELLOW);
    mostrarMatriz(m1);
}
else{
    if(opcionmm==2){
        cout << "Muy bien, sin hacer trampa ;)";
        cin.ignore();
    }
    else{
        cout << "Numero incorrecto" << endl;
        cin.ignore();
    }
}

cin.get();
system("cls");

}while(opcionmm!=1 && opcionmm!=2);
do{


    do{

    mostrarmatriz2modo1(m2, j1, cant_disparos, golpesabarcos, tirosalagua, barcos_hundidos, disparosestimados);


    cout << endl << endl;
    cout << "Ingresa las coordenadas del lugar que queres atacar" << endl;
    cout << "Fila (del 1 al 10): ";
    cin >> X;
    cout << "Columna (del 1 al 10): ";
    cin >> Y;


if(X<1 || Y<1 || X>10 || Y>10 || m2[X][Y] =='X'|| m2[X][Y]!= 'O'){

cout << endl << endl;

if(X<1 || Y<1 || X>10 || Y>10){

cout << "las coordenadas deben ser del 1 al 10" << endl;
}
else{
    cout << "Ya disparaste a esa posicion" << endl;
}

            cin.ignore();
            cin.get();
            system("cls");
    }

}while(X<1 || Y<1 || X>10 || Y>10 || m2[X][Y] =='X' || m2[X][Y]!= 'O');

/// una vez que se verifico que las coordenadas son correctas se cuenta el disparo
    cant_disparos++;

/// aca va cambiando la matriz 2, se cuentan los golpes para saber si hunden los barcos y cuenta los barcos hundidos


       if(m1[X][Y]!=0){ /// si m2[X][Y] == 0 es porque todavía no pegó, sino tendriamos un ~ o X
            rlutil::setColor(rlutil::LIGHTRED);
            m2[X][Y]= 'X';
            golpesabarcos++;


   if(m1[X][Y]==1){
    barcos_hundidos++;
    }
    else{
        if(m1[X][Y]==2){
            crucero++;
            if(crucero==2){
            barcos_hundidos++;
            }
            }

        else{
            if(m1[X][Y]==3){
                submarino++;
                if(submarino==3){
                barcos_hundidos++;
                }
                }

            else{
                    if(m1[X][Y]==4){
                        buque++;
                        if(buque==4){
                        barcos_hundidos++;
                        }
                    }

                else{

                        if(m1[X][Y]==5){
                        portaviones++;
                            if(portaviones==5){
                            barcos_hundidos++;
                            }
                        }
                    }
                }
            }
    }

                        }else{
                            rlutil::setColor(rlutil::LIGHTCYAN);
                            m2[X][Y]= '~' ;
                            tirosalagua++;
                        }




system("cls");


/// Se actualiza la matriz
mostrarmatriz2modo1(m2, j1, cant_disparos, golpesabarcos, tirosalagua, barcos_hundidos, disparosestimados);


if(m1[X][Y]==1){
    cout << endl << endl;
    cout << "Has hundido la lancha enemiga!" << endl;
    cin.ignore();
    cin.get();

    }
    else{
        if(m1[X][Y]==2){
            if(crucero==2){
            cout << endl << endl;
            cout << "Has hundido el crucero enemigo!" << endl;
            cin.ignore();
            cin.get();
            }
            }

        else{
            if(m1[X][Y]==3){
                if(submarino==3){
                cout << endl << endl;
                cout << "Has hundido el submarino enemigo!" << endl;
                cin.ignore();
                cin.get();
                }
                }

            else{
                if(m1[X][Y]==4){
                    if(buque==4){
                    cout << endl << endl;
                    cout << "Has hundido el buque enemigo!" << endl;
                    cin.ignore();
                    cin.get();
                    }
                    }

                else{

                    if(m1[X][Y]==5){
                    if(portaviones==5){
                    cout << endl << endl;
                    cout << "Has hundido el portaviones enemigo!" << endl;
                    cin.ignore();
                    cin.get();
                    }
                    }
                    }
          }
        }
    }


    cout << endl << endl;
    system("pause");
    system("cls");


}while(tirosalagua <= tapermitidos && barcos_hundidos!=5);
rlutil::setColor(rlutil::YELLOW);
if(tirosalagua>tapermitidos){
       cout << "Que lastima, gastaste tus " << tapermitidos << " tiros al agua permitidos" << endl;
       cout << "Mas suerte la proxima, crack ;)" << endl << endl;

   }else{
        cout << "FELICIDADES, HAS HUNDIDO TODA LA FLOTA ENEMIGA!" << endl << endl;
    }

system("pause");
system("cls");
}
#endif // FUNCTIONS_H_INCLUDED
