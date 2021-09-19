#include <iostream>
#include "node.hpp"
#include "list.hpp"
using namespace std;
void ListeSimple(void)
{
	CNode<int> *Head = nullptr;
	for (int i = 0; i < 5; i++)
	{
		Head = new CNode<int>(i, Head);
	}

	for (CNode<int> *ptr(Head); ptr != nullptr; ptr = ptr->GetNextNode())
		cout << "| data : " << ptr->GetData() << " | address : " << ptr << " | next address : " << ptr->GetNextNode() << " |\n";
	delete Head;
}
void ListeSimpleV2()
{

	int i;
	CList<int> liste;
	for (int i = 1; i < 5; i++)
	{
		liste.push_front(i);
	}
	liste.ShowAdvanced();

	cout << "nombre a ajouter a la fin: ";
	cin >> i;
	liste.push_back(i);
	liste.ShowAdvanced();

	cout << "nombre a ajouter: ";
	cin >> i;
	CNode<int> *ptr = liste.Find(i);
	liste.AddAfter(ptr, i);
	liste.ShowAdvanced();

	cout << ((ptr != NULL) ? " " : "non ") << "trouve" << endl;

	cout << "nombre a supprime: ";
	cin >> i;
	liste.Delete(liste.Find(i));
	liste.ShowAdvanced();
}
void ListeSimpleV3()
{
	cout << "ListeSimpleV2 : \n\n";

	CList<int> AList;

	// Le dernier element cree est toujours le premier de la liste

	for (unsigned i = 20; i; i -= 2)
		AList.AddAfter(AList.Begin(), i);
	cout << "hfejkrhg " << endl;

	for (unsigned i(0); i < 5;)
	{
		AList.push_front(i++);
	}

	AList.Show();
	//	AList.Show ();
	/*	int i;
		cin >>i;
		CNodeInt* ptr = AList.Find (i);
		AList.Add (3*i, ptr);
		AList.Show ();

		cout << ((ptr != NULL)?  " " : "non ") << "trouve" << endl;
	*/
	//cout << "valeur trouv�e" << ptr -> GetData () << endl;

	//delete AList;

	/*CNodeInt* ptr = AList.Find (2);
	cout << ((ptr != NULL)?  " " : "non ") << "trouve" << endl;
	AList.Delete (ptr);
	AList.Show ();*/

	//AList.Delete (AList.Find (0));

	AList.push_back(6);
	AList.push_back(7);

	AList.Delete(AList.Find(2));
	AList.Delete(AList.Find(12));
	AList.Delete(AList.Find(20));
	AList.Show();
	//delete ptr;
	cout << endl;
}
int main()
{
	ListeSimpleV2();
}