#include <string>
#include <functional>
#include <numeric>
#include <iostream>
#include <vector>
#include <optional>
#include <tuple>

using namespace std;
/*--------------------------------CLASES----------------------------*/
// El valor le meti un char, no deberia ser mas complejo
class Valor {
private:
    optional<char> valor;
public:
    Valor(){}
    Valor(char c) {valor = c;}

    void setValor(char c) {valor = c;}

    optional<char> getValor() {
        if (valor.has_value())
            return valor;
        return '0';
    }
};

//Una clase posic que seria un tupla (c,f)
struct Posic {
public:
    int p[2];
    Posic(){}

    Posic(int f, int c) {
        p[0] = f;
        p[1] = c;
    }

    void readPos(){
        int f,c;
        cout<<"Fila:";
        cin>>f;
        cout<<"Columna:";
        cin>>c;
        if(((f==1||f==2||f==3)&&(c==1||c==2||c==3))){
            this->p[0]=f;
            this->p[1]=c;
        }
        else{
            cout<<"valores invalidos"<<endl;
            this->readPos();
        }
    }
};

//La clase TTT le vamos a meter las 3 combinaciones de casillas que van a dar tateti
struct TTT {
public:
    vector<Posic> t;                                    //Por eso cada arreglo tiene 3 lugares
    TTT() {}

    TTT(int f1, int c1, int f2, int c2, int f3, int c3) { //Los cargo manualmente, solo eso
        t.push_back(Posic(f1, c1));
        t.push_back(Posic(f2, c2));
        t.push_back(Posic(f3, c3));
    }

};

class Casilla {
public:
    Valor Vcasilla;                   //Es opcional por si es nulo, necesario segun la consigna
    int Vteor;
    int Vreal;
    vector<TTT> ttt;                                 //Esto es un arreglo de TTT que ya de por si es un arreglo de tuplas
    //Ojo al piojo
    Casilla() {}

    Casilla(int i) {                            //Aca me canse de renegar y ya le creo con un case cada casilla, lue
        switch (i) {                            //-go en Fila le ejecuto el cons con el indice de casilla que y listo
            case 1:                             //Creo que no hace falta complicarse mas. Los valores irian de 1 arriba
                Vteor = 3;                      //a la derecha hasta el 9 abajo a la izquierda.
                Vreal = 3;
                ttt.push_back(TTT(1, 1, 1, 2, 1, 3));
                ttt.push_back(TTT(1, 1, 2, 2, 3, 3));
                ttt.push_back(TTT(1, 1, 2, 1, 3, 1));
                break;
            case 2:
                Vteor = 2;
                Vreal = 2;
                ttt.push_back(TTT(1, 2, 2, 2, 3, 2));
                ttt.push_back(TTT(1, 1, 1, 2, 1, 3));
                break;
            case 3:
                Vteor = 3;
                Vreal = 3;
                ttt.push_back(TTT(1, 3, 2, 3, 3, 3));
                ttt.push_back(TTT(1, 3, 2, 3, 3, 3));
                ttt.push_back(TTT(1, 3, 2, 2, 3, 1));
                break;
            case 4:
                Vteor = 2;
                Vreal = 2;
                ttt.push_back(TTT(2, 1, 2, 2, 2, 3));
                ttt.push_back(TTT(1, 1, 2, 2, 3, 3));
                break;
            case 5:
                Vteor = 4;
                Vreal = 4;
                ttt.push_back(TTT(1, 1, 2, 2, 3, 3));
                ttt.push_back(TTT(2, 1, 2, 2, 2, 3));
                ttt.push_back(TTT(1, 2, 2, 2, 3, 2));
                ttt.push_back(TTT(3, 1, 2, 2, 1, 3));
                break;
            case 6:
                Vteor = 2;
                Vreal = 2;
                ttt.push_back(TTT(1, 3, 2, 3, 3, 3));
                ttt.push_back(TTT(2, 1, 2, 2, 2, 3));
                break;
            case 7:
                Vteor = 3;
                Vreal = 3;
                ttt.push_back(TTT(3, 1, 3, 2, 3, 3));
                ttt.push_back(TTT(1, 1, 2, 2, 3, 3));
                ttt.push_back(TTT(3, 1, 2, 2, 1, 3));
                break;
            case 8:
                Vteor = 2;
                Vreal = 2;
                ttt.push_back(TTT(3, 2, 2, 2, 1, 2));
                ttt.push_back(TTT(3, 1, 3, 2, 3, 3));
                break;
            case 9:
                Vteor = 3;
                Vreal = 3;
                ttt.push_back(TTT(1, 3, 2, 3, 3, 3));
                ttt.push_back(TTT(3, 1, 3, 2, 3, 3));
                ttt.push_back(TTT(1, 1, 2, 2, 3, 3));
                break;
        }
    }
};

auto getVcasilla(Casilla c){return c.Vcasilla;}

int getVteor(Casilla casilla) {return casilla.Vteor;}

auto getVreal(Casilla casilla) {return casilla.Vreal;}

auto getttt(Casilla c){return c.ttt;}

class Fila { //A implementar. Solo notar que cada Fila tiene sus 3 columnas/casillas que predefini en el constructor de casilla
public:
    Casilla c1;
    Casilla c2;
    Casilla c3;

    Fila() {}

    Fila(int f) {
        switch (f) {
            case 1:
                c1 = Casilla(1);
                c2 = Casilla(2);
                c3 = Casilla(3);
                break;
            case 2:
                c1 = Casilla(4);
                c2 = Casilla(5);
                c3 = Casilla(6);
                break;
            case 3:
                c1 = Casilla(7);
                c2 = Casilla(8);
                c3 = Casilla(9);
                break;
        }
    }
    void putrow(int c, Valor v){
        switch (c) {
            case 1:
                this->c1.Vcasilla=v;
                break;
            case 2:
                this->c2.Vcasilla=v;
                break;
            case 3:
                this->c3.Vcasilla=v;
                break;
        }
    }
    template<typename T>
    T getvalgeneric(int columna,function<T(Casilla)> funcion){
        switch (columna) {
            case 1:
                return funcion(this->c1);
            case 2:
                return funcion(this->c2);
            case 3:
                return funcion(this->c3);
        }
    }
//    Valor getValRow (int columna) {
//        return getvalgeneric<Valor>(columna, getVcasilla);
//    }
};

class Tablero { //A implementar. Solo notar que cada tablero tiene 3 filas con sus respectivas columnas/casillas
public:
    Fila f1;
    Fila f2;
    Fila f3;

    Tablero() {
        f1 = Fila(1);
        f2 = Fila(2);
        f3 = Fila(3);
    }


    void newState(Valor valor) {
        Tablero t;
        if (valor.getValor() == 'X')
            newStatePlayer();
        else
            bestPlay();
        if (valor.getValor() == 'Y')
            cout << "machine:"<<endl;
        else
            cout << "player:"<<endl;
        printTablero();

        if (!finished()) {
            Valor otro;
            if(valor.getValor() == 'Y')
                otro.setValor('X');
            else
                otro.setValor('Y');
            newState(otro);
        }
    }

    void newStatePlayer() {
        Posic p = Posic();
        p.readPos();
        this->playx(p);
    }
    void playx(Posic p){
        Valor v = Valor('X');
        this -> putval(v,p);
    }


    void playy(Posic p) {
        Valor v = Valor('Y');
        this->putval(v,p);
    }

    vector<tuple<Posic,int>> evalTablero(){
        auto allPos=[]() {
            vector<Posic> pos;
            int a[3] = {1, 2, 3};
            for (int i:a) {
                for (int j:a) {
                    Posic paux = Posic(i, j);
                    pos.push_back(paux);
                }
            }
            return pos;
        };
        vector<Posic> posiciones;
        vector<tuple<Posic,int>> vtupla;
        vtupla.resize(9);
        posiciones=allPos();
        transform(posiciones.begin(),posiciones.end(),vtupla.begin(),[&] (Posic p){return make_tuple(p,evalpos(p));});
        return vtupla;
    }

    int evalpos(Posic posicion){
        return evalttts(posicion, getvalttt(posicion));
    }

    int evalttts(Posic posicion,vector<TTT> vttt){
        vector<int> Vreales;
        Vreales.resize(vttt.size());
        transform(vttt.begin(),vttt.end(),Vreales.begin(),[&](TTT ttt){return evalttt(posicion,ttt);});
        return accumulate(Vreales.begin(),Vreales.end(),0,[&](int x, int y){return max(x,y);});
    }

    int evalttt (Posic posicion, TTT ttt) {
        if (ocupado(posicion)) return 0;
        else if (dosMios(ttt)) return 10;
        else if (dosRival(ttt)) return 8;
        else if (unoyuno(ttt)) return 1;
        else if (unoMio(ttt)) return 7;
        else if (unoRival(ttt)) return 5;
        else if (trioVacio(ttt)) return getvalteor(posicion);
        else    return 0;
    }
    vector<TTT> getvalttt(Posic p){
        return getrowgeneric<vector<TTT>>(p, getttt);
    }
    int getvalteor(Posic p){
        return getrowgeneric<int>(p, getVteor);
    }

    template<typename T>
    T getrowgeneric(Posic p, function<T(Casilla)> fu){
        int f = p.p[0];
        int c = p.p[1];

        switch (f) {
            case 1:
                return this->f1.getvalgeneric<T>(c, fu);
                break;
            case 2:
                return this->f2.getvalgeneric<T>(c, fu);
                break;
            case 3:
                return this->f3.getvalgeneric<T>(c, fu);
                break;
        }
    }

//---------------------------------jugadas------------------------------
    vector<Valor> tttToVal(TTT jugadas) {
        vector<Valor> valores;
        valores.resize(jugadas.t.size());
        transform(jugadas.t.begin(),jugadas.t.end(),valores.begin(),[&]   (Posic pos)    { return getVal(pos); });
        //for_each(jugadas.t.begin() , jugadas.t.end() ,[&]   (Posic pos)    { valores.push_back(getVal(pos));});
        return valores;
    }

    int count(char val, TTT jugadas) {
        vector <Valor> valores = tttToVal(jugadas);
        vector <Valor> :: iterator pend;
        pend = remove_if(valores.begin(), valores.end(), [&](Valor x){return x.getValor()!=val;});
        return distance(valores.begin(),pend);
    }
    bool trioVacio(TTT jugadas) {
        vector <Valor> valores = tttToVal(jugadas);
        return all_of(valores.begin(), valores.end(), [&](Valor x){return x.getValor()=='0';});
    }

    bool dosMios (TTT jugadas) {
        return (count('Y',jugadas)==2);
    }

    bool  dosRival (TTT jugadas) {
        return (count('X',jugadas)==2);
    }

    bool unoMio (TTT jugadas) {
        return (count('Y',jugadas)==1);
    }

    bool unoRival (TTT jugadas) {
        return (count('X',jugadas)==1);
    }

    bool unoyuno (TTT jugadas) {
        return ((count('Y',jugadas)==1) && (count('X',jugadas)==1));
    }

    bool ocupado (Posic posicion) {
        return (getVal(posicion).getValor() != '0');
    }

    void bestPlay() {
        playy(bestpos());
    }

    Posic bestpos() {
        Posic p = Posic(0,0);
        int Vr = 0;
        tuple<Posic,int> tu (p,Vr);
        vector<tuple<Posic,int>> vtupla = evalTablero();
        return get<0>(accumulate(vtupla.begin(), vtupla.end(), tu, [&](tuple<Posic,int> tuple1, tuple<Posic,int> tuple2){return maxpos(tuple1,tuple2);}));
    }

    tuple<Posic, int> maxpos(tuple<Posic, int> a, tuple<Posic, int> b) {
        if (get<1>(a) > get<1>(b)) {
            return a;
        } else {
            return b;
        }
    }

    void putval(Valor v, Posic p) {
        int f = p.p[0];
        int c = p.p[1];

        switch (f) {
            case 1:
                this->f1.putrow(c, v);
                break;
            case 2:
                this->f2.putrow(c, v);
                break;
            case 3:
                this->f3.putrow(c, v);
                break;
        }
    }

    bool gano (char valor) {
        vector<TTT> alltrios = {TTT(1,1,1,2,1,3),TTT(2,1,2,2,2,3),TTT(3,1,3,2,3,3),
                                TTT(1,1,2,1,3,1),TTT(1,2,2,2,3,2),TTT(1,3,2,3,3,3),
                                TTT(1,1,2,2,3,3),TTT(1,3,2,2,3,1)};

        return any_of(alltrios.begin(),alltrios.end(),[&](TTT y){
            vector<Valor> vecVal = tttToVal(y);
            return all_of(vecVal.begin(),vecVal.end(),[&](Valor z){return z.getValor() == valor;});
        });
    }

    void resultado() {
        if(gano('X')) cout << "Gano X";
        else if (gano('Y')) cout << "Gano Y";
        else cout << "Empate";
    }

    bool noFreePlace() {
        auto allPos=[]() {
            vector<Posic> pos;
            int a[3] = {1, 2, 3};
            for (int i:a) {
                for (int j:a) {
                    Posic paux = Posic(i, j);
                    pos.push_back(paux);
                }
            }
            return pos;
        };
        vector<Posic> posiciones;
        vector<Valor> vVreal;
        vVreal.resize(9);
        posiciones=allPos();

        transform(posiciones.begin(),posiciones.end(),vVreal.begin(),[&](Posic x){return getVal(x);});
        return all_of(vVreal.begin(),vVreal.end(),[&](Valor val){return val.getValor()!='0';});
    }

    bool finished() {
        if(gano('X')||gano('Y')||noFreePlace()) {
            return true;
        }
        return false;
    }

    void printTablero() {
        cout << this->f1.c1.Vcasilla.getValor().value() << "     " << this->f1.c2.Vcasilla.getValor().value()
             << "     " << this->f1.c3.Vcasilla.getValor().value() << '\n' <<
             this->f2.c1.Vcasilla.getValor().value() << "     " << this->f2.c2.Vcasilla.getValor().value()
             << "     " << this->f2.c3.Vcasilla.getValor().value() << '\n' <<
             this->f3.c1.Vcasilla.getValor().value() << "     " << this->f3.c2.Vcasilla.getValor().value()
             << "     " << this->f3.c3.Vcasilla.getValor().value() << '\n';
    }
    Valor getVal (Posic pos) {
        return getrowgeneric<Valor>(pos, getVcasilla);
    }
};

int main() {
    Tablero t;

    char jugador;

    cout<<"Ta-Te-Ti Funcional"<<endl;
    cout<<"X persona Y machine"<<endl;
    cout<<"empieza (S/N)?"<<endl;
    cin >> jugador;
    Valor valor = Valor(jugador);
    if(jugador=='S')
        valor.setValor('X');
    else if(jugador=='N')
        valor.setValor('Y');
    else
        cout<<"Entrada no valida. :(";
    t.newState(valor);
    t.resultado();
    return 0;
}