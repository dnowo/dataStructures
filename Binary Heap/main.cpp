#include <iostream>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

int rozmiar = 0;
int nowy_rozmiar = 0;
int * tablica = NULL;

void pamiecdynamiczna()
{
    int * nowa_tablica = (int*)malloc(nowy_rozmiar*sizeof(int));
    if (tablica != NULL)
    {
        for(int i=0; i<rozmiar; i++) nowa_tablica[i] = tablica[i];
    }
    int * temp = tablica;
    tablica = nowa_tablica;
    free(temp);
}

void sprawdzGore(int i)
{
   while (i >= 1 && tablica[i] > tablica[(i-1)/2])
    {
        swap(tablica[i], tablica[(i-1)/2]);
        i=(i-1)/2;
    }
}

void dodawanie(int liczba)
{
    int i=rozmiar;
    nowy_rozmiar=rozmiar+1;
    pamiecdynamiczna();
    rozmiar=nowy_rozmiar;
    tablica[i]=liczba;
    sprawdzGore(i);
}

void wypisz (int i)
{

        cout << tablica[i] << " ";
        if(2*i+1 < rozmiar) wypisz (2*i+1);
        if (2*i+2 < rozmiar) wypisz (2*i+2);
}

void sprawdzDol()
{
    int i = 0, index = 1;
    while (index < rozmiar)
    {

        if(index + 1 < rozmiar && tablica[index + 1] > tablica[index]) index++;
        if(tablica[index] > tablica[i])
        {
            swap(tablica[i],tablica[index]);
            i = index;
            index = 2*index + 1;
        }
        else index = rozmiar;

    }
}

void usun()
{
    rozmiar--;
    nowy_rozmiar = rozmiar;
    swap(tablica[0],tablica[nowy_rozmiar]);
    pamiecdynamiczna();
    if (rozmiar > 1) sprawdzDol();

}

int main()
{
    int licznik=1;
    dodawanie(80);
    dodawanie(48);
    dodawanie(33);
    dodawanie(14);
    dodawanie(7);
    dodawanie(25);

    while(licznik!=0)
    {
      int i;
      cin>>i;
      if(i==-1)
      {
          licznik=0;
      }
      else if(i==0)
      {
          cin >> licznik;
          dodawanie(licznik);
      }
      else if(i==1)
      {
          if(rozmiar != 0) usun();
      }
      else if(i==2)
      {
          wypisz(0);
      }
    }

    return 0;
}