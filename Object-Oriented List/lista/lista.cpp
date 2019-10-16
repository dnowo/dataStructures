
#include <iostream>
#include "List.h"
#include "ListElement.h"


using namespace std;

int main()
{
	List* lista = new List();
	lista->addToEnd(3);
	lista->addToBeginning(2);

	lista->printList();

	lista->addToBeginning(1);
	lista->addToBeginning(4);

	lista->printList();

	lista->contains(3);
	lista->contains(5);

	lista->removeKey(3);
	lista->printList();

	lista->removeKey(5);
	lista->printList();

	lista->removeKey(1);
	lista->printList();

	lista->clearAll();
	lista->addToEnd(0);

	lista->printList();

	
}

