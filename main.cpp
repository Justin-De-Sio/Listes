#include <iostream>
#include "node.hpp"
#include "list.hpp"
using namespace std;
#include <memory>

void ListeSimple ()
{
    std::cout << "ListeSimple : \n\n";

    shared_ptr<CNode<int>>Tete = nullptr;

    // Le dernier element cree est toujours le premier de la liste


    for (unsigned i (0); i < 5; ) {
        shared_ptr<CNode <int>> tmp  (new CNode<int>(i++, nullptr, Tete));
        Tete = tmp;
    }

    for (shared_ptr<CNode<int>>  Ptr (Tete); Ptr; Ptr = Ptr->GetNextNode ())
        std::cout << Ptr->GetData()<< "; ";

    std::cout << '\n';

    // Dans cette version, le destructeur de C1Link detruit son
    //   suivant donc la destruction de la liste est recursive



}// ListeSimple ()


void ListeSimpleV2 ()
{
    cout << "ListeSimpleV2 : \n\n";

    CList<int> AList;

    // Le dernier element cree est toujours le premier de la liste

    /*for (unsigned i = 20; i; i -= 2) AList.AddAfter (AList.Begin (), i);
    cout << "hfejkrhg " << endl;
*/
    for (unsigned i (0); i < 5; ) {
        AList.push_front (i++);
    }

    cout << AList.Find(3)->GetPrevNode();


    AList.Show ();
//	AList.Show ();
/*	int i;
    cin >>i;
    CNodeInt* ptr = AList.Find (i);
    AList.Add (3*i, ptr);
    AList.Show ();

    cout << ((ptr != NULL)?  " " : "non ") << "trouve" << endl;
*/
    //cout << "valeur trouvée" << ptr -> GetData () << endl;

    //delete AList;

    /*CNodeInt* ptr = AList.Find (2);
    cout << ((ptr != NULL)?  " " : "non ") << "trouve" << endl;
    AList.Delete (ptr);
    AList.Show ();*/

    //AList.Delete (AList.Find (0));

/*    AList.push_back (6);
    AList.push_back (7);


    AList.Delete (AList.Find (2));
    AList.Delete (AList.Find (12));
    AList.Delete (AList.Find (20));
    AList.Show ();
    //delete ptr;
    cout << endl;*/
    AList.AddAfter(AList.Find(10),66);
    AList.AddBefore(AList.Find(66),33);
    AList.Show();
}

int main(int argc, char *argv[])
{
    CList<int> Alist;
    for(int i=0 ;i<5;++i){
         Alist.push_back(i);

    }
    Alist.Delete(Alist.Find(1));
    Alist.Show();
}
