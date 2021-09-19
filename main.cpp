#include <iostream>
#include "node.hpp"
#include "list.hpp"
using namespace std;
void ListeSimple(void) {
	CNode<int>* Head = nullptr;
	for (int i = 0; i < 5; i++)
	{
		Head = new CNode<int>(i, Head);
	}

	

	for (CNode<int>* ptr(Head); ptr != nullptr; ptr = ptr->GetNextNode())
		cout << "| data : " << ptr->GetData() << " | address : " << ptr << " | next address : " << ptr->GetNextNode() << " |\n";
	delete Head;
}


int main()
{
	
	
	int i;
	CList<int> liste;
	for (int i = 1; i < 5; i++)
	{
		liste.push_front(i);
	}
	liste.Show();
	
	cout << "nombre a ajouter au d�but: ";
	cin >> i;
	liste.push_back(i);
	liste.Show();

	
	cout << "nombre a ajouter: ";
	cin >> i;
	CNode<int>* ptr = liste.Find(i);
	liste.Add(i, ptr);
	liste.Show();

	cout << ((ptr != NULL) ? " " : "non ") << "trouve" << endl;

	cout << "nombre a supprime: ";
	cin >> i;
	liste.Delete(liste.Find(i));
	liste.Show();

}