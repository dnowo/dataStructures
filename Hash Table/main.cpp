#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <list>
using namespace std;

struct hashTablica
{
    int klucz;
    int wartosc;
    string znaki;
};

list<hashTablica> tablica[16];

int hashe(string klucz)
{
    int x = 0, hasz;
    while(klucz.length() != 0)
    {
        x += (int)klucz[klucz.length()-1];
       klucz.erase(klucz.size()-1);
    }

    hasz = x%16;

    return hasz;
}

void dodaj(int wartosc, string klucz)
{
        int wygenerowany = hashe(klucz);
        hashTablica *nowy = new hashTablica();
        nowy->klucz = wygenerowany;
        nowy->wartosc = wartosc;
        nowy->znaki = klucz;
        tablica[wygenerowany].push_back(*nowy);

}

void wypisz(string klucz)
{
    int wygenerowany = hashe(klucz);

    list<hashTablica>::iterator i;
    for(i = tablica[wygenerowany].begin();i!=tablica[wygenerowany].end();i++)
    {
        if(i->znaki == klucz)  cout << i->wartosc;
    }

}
int elementy(string klucz)
{
    int wygenerowany = hashe(klucz);

    int zlicz = tablica[wygenerowany].size();
    return zlicz;
}

int main() {
    int stop=0,steruj,wartosc;
    string klucz;
    hashTablica nowy;

    while(stop!=1)
    {
        cin >> steruj;
        if(steruj == 5)
            stop = 1;
        if(steruj == 1)
        {
            cin >> klucz;
            cin >> wartosc;
            dodaj(wartosc, klucz);
        }
        if(steruj == 2)
        {
            cin >> klucz;
            wypisz(klucz);
        }

        if(steruj == 3)
        {
            cin >> klucz;
            cout << elementy(klucz);
        }

    }
    return 0;
}