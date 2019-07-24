#include <iostream>
#include <list>
#include <string>

using namespace std;
struct dwukierunkowa
{
    int numer;
    string tekst;

};
void szukaj(list<dwukierunkowa> &lista, int numer)
{
    list<dwukierunkowa>::iterator i;
    for(i=lista.begin();i!=lista.end();i++)
    {
        if(i->numer == numer)
        {
            cout << endl << "Znalazlem nastepujaca wartosc: " << i->tekst << endl;
        }
    }
}
void wyswietl(list<dwukierunkowa> &lista)
{
    list<dwukierunkowa>::iterator i;
    for(i=lista.begin();i!=lista.end();i++)
    {
        cout << "Numer: " << i->numer << " Tekst: " << i->tekst << endl;
    }
}

int main() {
    list<dwukierunkowa> lista;
    int stop=0, steruj,podaj;

    while(stop!=1)
    {
        cout << "Sterowanie: " << endl << "1. Wprowadza wartosc do listy" << endl << "2. Szuka podanego numeru" << endl << "3. Wyswietla cala liste" << endl<< "-1. Konczy prace"<<endl;

        cin >> steruj;

        if(steruj == 1) //wcisnij 1 i dodaj do listy
        {
            cout << "Wprowadzasz wartosc do listy(numer): " << endl;
            dwukierunkowa *nowy = new dwukierunkowa();
            cin >> nowy->numer;
            cout << "Wprowadzasz wartosc do listy(tekst): "<<endl;
            cin >> nowy->tekst;
            lista.push_back(*nowy);

        }
        if(steruj == 2) //jesli 2 to wypisz element podany po 2
        {
            if(lista.size()==0)
                break;
            cout << "Podaj numer ktorego tekst chcesz wyswietlic ";
            cin >> podaj;
            szukaj(lista, podaj);
        }
        if(steruj == 3)
        {
            wyswietl(lista);
        }
        if(steruj == -1)
        {
            stop = 1;
        }
    }

    return 0;
}