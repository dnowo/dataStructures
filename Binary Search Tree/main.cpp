#include <iostream>
#include <cstdio>
#include <string>
#include <malloc.h>
#include <cstdlib>

using namespace std;
struct drzewoBST{
    int liczba;
    struct drzewoBST* lewy;
    struct drzewoBST* prawy;
};
typedef drzewoBST* tree;

void insert(tree &wezel, int liczba)
{
    if(wezel == NULL)
    {
        wezel = new drzewoBST;
        wezel->prawy = wezel->lewy = NULL;
        wezel->liczba = liczba;
    }
    else if(liczba < wezel->liczba)
    {
        insert(wezel->lewy, liczba);
    }
    else if(liczba > wezel->liczba)
    {
        insert(wezel->prawy,liczba);
    }
}
string pomoc;
char bufor[5];
drzewoBST search(tree wezel, int liczba)
{
    if(wezel)
    {
       if(liczba == wezel->liczba)
       {
           sprintf(bufor,"%d",wezel->liczba);
           pomoc += bufor;
           cout << pomoc;
           return  *wezel;
       }
       if(liczba < wezel->liczba)
       {
           sprintf(bufor,"%d",wezel->liczba);
           pomoc += bufor;
           search(wezel->lewy, liczba);
       }
       if(liczba > wezel->liczba)
       {
           sprintf(bufor,"%d",wezel->liczba);
           pomoc += bufor;
           search(wezel->prawy, liczba);
       }

    }
    else
    {
        cout << "A";
    }

}

int main() {
    tree korzen = NULL;

    int stop = 0,steruj,liczba;
    while(stop!=1)
    {
        cin >> steruj;

        if(steruj == 1)
        {
            cin >> liczba;
            insert(korzen, liczba);
        }
        if(steruj == 2)
        {
            cin >> liczba;
            search(korzen, liczba);

        }
        if(steruj == 0)
        {
            stop = 1;
        }

    }

    return 0;
}
