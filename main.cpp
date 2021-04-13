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

class Valor{
    private:
    char valor;

    public:
		Valor(char c){
    	    valor=c;
    	}

    	void setvalor(char c){
        	valor=c;
    	}

        char setvalor(){
        	return valor;
    	}
};
struct Posic{
    public:
		int p[2];

		Posic(){}

    	Posic(int f, int c){
    	   p[0]=f;
    	   p[1]=c;
    	}
};

struct TTT{
public:
    Posic *t[3];
    TTT(){}

    TTT(int f1,int c1,int f2,int c2,int f3,int c3){
        t[0]=new Posic(f1,c1);
        t[1]=new Posic(f2,c2);
        t[2]=new Posic(f3,c3);
    }
};

class Casilla{
public:
        optional<Valor> Vcasilla;
    	int Vteor;
    	int Vreal;
    	TTT *ttt[];

        Casilla(int i) {
            switch (i) {
                case 1:
                    Vteor = 3;
                    Vreal = 3;
                    ttt[0]=new TTT(1, 1, 1, 2, 1, 3);
                    ttt[1]=new TTT(1, 1, 2, 2, 3, 3);
                    ttt[2]=new TTT(1, 1, 2, 1, 3, 1);
                break;
                case 2:
                    Vteor = 2;
                    Vreal = 2;
                    ttt[0]=new TTT(1, 2, 2, 2, 3, 2);
                    ttt[1]=new TTT(1, 1, 1, 2, 1, 3);
                    break;
                case 3:
                    Vteor = 3;
                    Vreal = 3;
                    ttt[0]=new TTT(1, 3, 2, 3, 3, 3);
                    ttt[1]=new TTT(1, 3, 2, 3, 3, 3);
                    ttt[2]=new TTT(1, 3, 2, 2, 3, 1);
                    break;
                case 4:
                    Vteor = 2;
                    Vreal = 2;
                    ttt[0]=new TTT(2, 1, 2, 2, 2, 3);
                    ttt[1]=new TTT(1, 1, 2, 2, 3, 3);
                    break;
                case 5:
                    Vteor = 4;
                    Vreal = 4;
                    ttt[0]=new TTT(1, 1, 2, 2, 3, 3);
                    ttt[1]=new TTT(2, 1, 2, 2, 2, 3);
                    ttt[2]=new TTT(1, 2, 2, 2, 3, 2);
                    ttt[3]=new TTT(3, 1, 2, 2, 1, 3);
                    break;
                case 6:
                    Vteor = 2;
                    Vreal = 2;
                    ttt[0]=new TTT(1, 3, 2, 3, 3, 3);
                    ttt[1]=new TTT(2, 1, 2, 2, 2, 3);
                    break;
                case 7:
                    Vteor = 3;
                    Vreal = 3;
                    ttt[0]=new TTT(3, 1, 3, 2, 3, 3);
                    ttt[1]=new TTT(1, 1, 2, 2, 3, 3);
                    ttt[2]=new TTT(3, 1, 2, 2, 1, 3);
                    break;
                case 8:
                    Vteor = 2;
                    Vreal = 2;
                    ttt[0]=new TTT(3, 2, 2, 2, 1, 2);
                    ttt[1]=new TTT(3, 1, 3, 2, 3, 3);
                    break;
                case 9:
                    Vteor = 3;
                    Vreal = 3;
                    ttt[0]=new TTT(1, 3, 2, 3, 3, 3);
                    ttt[1]=new TTT(3, 1, 3, 2, 3, 3);
                    ttt[2]=new TTT(1, 1, 2, 2, 3, 3);
                    break;
            }
        }

        void setValor(char c){
            Vcasilla->setvalor(c);
        }
};
/*
class Fila{
    private:
        Casilla c1;
        Casilla c2;
        Casilla c3;
    public:
        Fila(int 1vt,int 1vr,TTT *1tt, int 2vt,int 2vr,TTT *2tt, int 3vt,int 3vr,TTT *3tt){
            c1= new Casilla(1vt,1vr,*1tt);
            c2= new Casilla(2vt, 2vr,*2tt);
            c3= new Casilla(3vt, 3vr,*3tt);
        }

};
class Tablero{
    private:
        Fila f1;
        Fila f2;
        Fila f3;
    public:
        Tablero(){
            TTT *1tt[]=[new TTT()->addPos(1,1),new TTT(1,1),new TTT(1,1),new TTT(1,1),new TTT(1,1),,new TTT(1,1),]
        }

};
*/
int main() {
    Casilla *a= new Casilla(5);
    a->setValor('X');
    cout<<a->ttt[0]->t[0]->p[0];

    return 0;
}
