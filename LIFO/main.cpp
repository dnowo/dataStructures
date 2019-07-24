#include <iostream>
#include <list>
using namespace std;
struct kolejka{
    int wartosc;
};
int main() {
    list<kolejka> lista;
    int zatrzymaj = 1;
    int pomoc, _temp;
    while(zatrzymaj != 0)
    {
        cin >> pomoc;

        if(pomoc == 0)
        {
            kolejka *nowy = new kolejka;
            cin >> nowy->wartosc;
            lista.push_front(*nowy);
        }
        if(pomoc == 1)
        {
            list<kolejka>::iterator i=lista.end();
            cout << i->wartosc;
            lista.pop_back();
            if(lista.size() < 1) zatrzymaj=0;
        }
        if(pomoc == -1)
        {
            zatrzymaj = 0;
        }
    }



    return 0;
}