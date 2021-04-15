#include <string>
#include <functional>
#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <unistd.h>
#include <vector>
#include <optional>

using namespace std;
/*--------------------------------CLASES----------------------------*/
// El valor le meti un char, no deberia ser mas complejo
class Valor {
private:
    optional<char> valor;

public:
    Valor(){

    }
    Valor(char c) {
        valor = c;
    }

    void setValor(char c) {
        valor = c;
    }

    optional<char> getValor() {
        if(valor==nullopt){
            return valor;
        }
        return 'O';
    }
};

//Una clase posic que seria un tupla (c,f)
struct Posic {
public:
    int p[2];

    Posic(int f, int c) {
        p[0] = f;
        p[1] = c;
    }
};

//La clase TTT le vamos a meter las 3 combinaciones de casillas que van a dar tateti
struct TTT {
public:
    Posic *t[3];                                    //Por eso cada arreglo tiene 3 lugares
    TTT() {                                          //no sabes lo que renegue hasta que me faltaba el constructor vacio

    }

    TTT(int f1, int c1, int f2, int c2, int f3, int c3) { //Los cargo manualmente, solo eso
        t[0] = new Posic(f1, c1);
        t[1] = new Posic(f2, c2);
        t[2] = new Posic(f3, c3);
    }

};

class Casilla {
public:
    Valor *Vcasilla;                   //Es opcional por si es nulo, necesario segun la consigna
    int Vteor;
    int Vreal;
    TTT *ttt[];                                 //Esto es un arreglo de TTT que ya de por si es un arreglo de tuplas
    //Ojo al piojo
    Casilla() {

    }

    Casilla(int i) {                            //Aca me canse de renegar y ya le creo con un case cada casilla, lue
        switch (i) {                            //-go en Fila le ejecuto el cons con el indice de casilla que y listo
            case 1:                             //Creo que no hace falta complicarse mas. Los valores irian de 1 arriba
                Vteor = 3;                      //a la derecha hasta el 9 abajo a la izquierda.
                Vreal = 3;
                ttt[0] = new TTT(1, 1, 1, 2, 1, 3);
                ttt[1] = new TTT(1, 1, 2, 2, 3, 3);
                ttt[2] = new TTT(1, 1, 2, 1, 3, 1);
                break;
            case 2:
                Vteor = 2;
                Vreal = 2;
                ttt[0] = new TTT(1, 2, 2, 2, 3, 2);
                ttt[1] = new TTT(1, 1, 1, 2, 1, 3);
                break;
            case 3:
                Vteor = 3;
                Vreal = 3;
                ttt[0] = new TTT(1, 3, 2, 3, 3, 3);
                ttt[1] = new TTT(1, 3, 2, 3, 3, 3);
                ttt[2] = new TTT(1, 3, 2, 2, 3, 1);
                break;
            case 4:
                Vteor = 2;
                Vreal = 2;
                ttt[0] = new TTT(2, 1, 2, 2, 2, 3);
                ttt[1] = new TTT(1, 1, 2, 2, 3, 3);
                break;
            case 5:
                Vteor = 4;
                Vreal = 4;
                ttt[0] = new TTT(1, 1, 2, 2, 3, 3);
                ttt[1] = new TTT(2, 1, 2, 2, 2, 3);
                ttt[2] = new TTT(1, 2, 2, 2, 3, 2);
                ttt[3] = new TTT(3, 1, 2, 2, 1, 3);
                break;
            case 6:
                Vteor = 2;
                Vreal = 2;
                ttt[0] = new TTT(1, 3, 2, 3, 3, 3);
                ttt[1] = new TTT(2, 1, 2, 2, 2, 3);
                break;
            case 7:
                Vteor = 3;
                Vreal = 3;
                ttt[0] = new TTT(3, 1, 3, 2, 3, 3);
                ttt[1] = new TTT(1, 1, 2, 2, 3, 3);
                ttt[2] = new TTT(3, 1, 2, 2, 1, 3);
                break;
            case 8:
                Vteor = 2;
                Vreal = 2;
                ttt[0] = new TTT(3, 2, 2, 2, 1, 2);
                ttt[1] = new TTT(3, 1, 3, 2, 3, 3);
                break;
            case 9:
                Vteor = 3;
                Vreal = 3;
                ttt[0] = new TTT(1, 3, 2, 3, 3, 3);
                ttt[1] = new TTT(3, 1, 3, 2, 3, 3);
                ttt[2] = new TTT(1, 1, 2, 2, 3, 3);
                break;
        }
    }

    void setValor(char c) {
        Vcasilla->setValor(c);
    }
};


class Fila { //A implementar. Solo notar que cada Fila tiene sus 3 columnas/casillas que predefini en el constructor de casilla
public:
    Casilla *c1;
    Casilla *c2;
    Casilla *c3;

    Fila() {

    }

    Fila(int f) {
        switch (f) {
            case 1:
                c1 = new Casilla(1);
                c2 = new Casilla(2);
                c3 = new Casilla(3);
                break;
            case 2:
                c1 = new Casilla(4);
                c2 = new Casilla(5);
                c3 = new Casilla(6);
                break;
            case 3:
                c1 = new Casilla(7);
                c2 = new Casilla(8);
                c3 = new Casilla(9);
                break;
        }
    }
};

class Tablero { //A implementar. Solo notar que cada tablero tiene 3 filas con sus respectivas columnas/casillas
public:
    Fila *f1;
    Fila *f2;
    Fila *f3;

    Tablero() {
        f1 = new Fila(1);
        f2 = new Fila(2);
        f3 = new Fila(3);
    }
/*
    Tablero newState(Valor *valor) {
        if (valor->getValor() == 'X')
            return newStatePlayer();
        else
            return bestPlay();

        if (valor->getValor() == 'Y')
            cout << "player";
        else
            cout << "machine";

        printTablero();

        if (!finished()) {
            Valor otro;
            if(valor->getValor() == 'Y')
                otro.setValor('X');
            else
                otro.setValor('Y');

            newState(otro);
        }
    }

    Tablero newStatePlayer() {

    }

    Tablero bestPlay() {

    }

    bool finished() {

    }
    */
    void printTablero() {
        cout << this->f1->c1->Vcasilla->getValor()<<"     "<<this->f1->c2->Vcasilla->getValor()<<"     "<<this->f1->c3->Vcasilla->getValor()<<'\n'<<
                this->f2->c1->Vcasilla->getValor()<<"     "<<this->f2->c2->Vcasilla->getValor()<<"     "<<this->f2->c3->Vcasilla->getValor()<<'\n'<<
                this->f1->c1->Vcasilla->getValor()<<"     "<<this->f1->c2->Vcasilla->getValor()<<"     "<<this->f1->c3->Vcasilla->getValor()<<'\n';
    }
};
/*---------------------------------FUNCIONES-------------------------*/

int main() {
    Tablero *t = new Tablero();
    char jugador;
    /*
    cin >> jugador;
    Valor *valor = new Valor(jugador);
    if(jugador=='S')
        valor->setValor('X');
    else if(jugador=='N')
        valor->setValor('Y');
    else
        cout<<"Entrada no valida. :(";
    t->newState(valor);
   */
    t->f1->c1->Vcasilla->setValor('X');
    t->f2->c2->Vcasilla->setValor('X');
    t->f3->c3->Vcasilla->setValor('X');
    t->printTablero();
    return 0;
}
