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

	cout << "|   HEAD   | address : " << Head << " |\n";

	for (CNode<int>* ptr(Head); ptr != nullptr; ptr = ptr->GetNextNode())
		cout << "| data : " << ptr->GetData() << " | address : " << ptr << " | next address : " << ptr->GetNextNode() << " |\n";
	delete Head;
}
int main()
{

	CList<int> liste;
	for (int i = 0; i < 8; i++)
	{
		liste.push_front(i);
	}
	liste.Show();
	
	int i;
	cout << "nombre a ajouter: ";
	cin >> i;
	CNode<int>* ptr = liste.Find(5);
	liste.Add(3 * 5, ptr);
	liste.Show();

	cout << ((ptr != NULL) ? " " : "non ") << "trouve" << endl;

	cout << "nombre a supprime: ";
	cin >> i;
	liste.Delete(liste.Find(i));
	liste.Show();

}