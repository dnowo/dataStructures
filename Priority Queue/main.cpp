#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;
struct queue{
    int kolejka;
    int priorytet;
};
int main() {
    list<queue> lista;
    int wartosc;
    int maxPriorytet;
    int stop = 0;



    while(stop != -1)
    {
        cin >> wartosc;
        if(wartosc == 0)
        {
            queue* Element = new queue;
            cin >> Element->kolejka;
            cin >> Element->priorytet;

            lista.push_front(*Element);
        }
            if(wartosc == 1)
            {
                list<queue>::iterator itr;
                list<queue>::reverse_iterator iteruj,_temp;
                list<queue>::iterator iteratorPriorytetu = lista.begin();
                maxPriorytet = lista.front().priorytet;
                for(itr = lista.begin();itr != lista.end();itr++)
                {
                    if(itr->priorytet > maxPriorytet)
                    {
                        maxPriorytet = itr->priorytet;
                    }
                }
                for(iteruj = lista.rbegin(); iteruj != lista.rend(); iteruj++)
                {
                    if(iteruj->priorytet == maxPriorytet)
                    {
                        cout << iteruj->kolejka;
                        _temp = iteruj;
                        break;
                    }
                }
                lista.erase(--(_temp.base()));

            }
            if(wartosc == -1)
            {
                stop = -1;
            }



    }





    return 0;
}