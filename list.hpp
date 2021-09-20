#pragma once
#include "node.hpp"

template<typename T>

class CList
{
private:
    CNode<T>* m_Head;
public:
    CList(CNode<T>* head = nullptr);
    ~CList();
    //ajout en t�te de liste
    void push_front(const T& data);
    //affichage
    void Show() const;
    //recherche d'un �l�ment dans la liste, renvoie le pointeur du maillon si l'�l�ment est pr�sent, nullptr sinon
    CNode<T>* Find(const T& data) const;
    //ajout d'une valeur apr�s un maillon de la liste
    void Add(const T& data, CNode<T>*);
    //d�tache un maillon de la liste et le supprime
    void Delete(CNode<T>*);
};

template<typename T>
 CList<T>::CList(CNode<T>* head) : m_Head(head)
{
}

 template<typename T>
 inline CList<T>::~CList()
 {
     delete m_Head;
 }

 template<typename T>
 inline void CList<T>::push_front(const T& data)
 {
     m_Head = new CNode<T>(data, m_Head);
 }

 template<typename T>
 inline void CList<T>::Show() const
 {
     for(CNode<T>* ptr(m_Head);ptr!=nullptr;ptr=ptr->GetNextNode())
        std::cout << "| data : " << ptr->GetData() << " | address : " << ptr << " | next address : " << ptr->GetNextNode() << " |\n";
     std::cout << "\n";

 }

 template<typename T>
 inline CNode<T>* CList<T>::Find(const T& data) const
 {
     CNode<T>* ptr(m_Head);
     for (; ptr!= nullptr &&ptr->GetData() !=data; ptr = ptr->GetNextNode());
     return ptr;

 }

 template<typename T>
 inline void CList<T>::Add(const T& data, CNode<T>* ptr)
 {
     if (ptr == nullptr)return;
     CNode<T>* ptrTemp = new CNode<T>(data, ptr->GetNextNode());
     ptr->SetNextNode(ptrTemp);

 }

 template<typename T>
 inline void CList<T>::Delete(CNode<T>* ptr)
 {
     if (ptr == m_Head) {
         m_Head = ptr->GetNextNode();
         ptr->SetNextNode(nullptr);
         delete ptr;
         return;
     }
     if (ptr == nullptr) return;
     CNode<T>* ptrTemp(m_Head);
     for (; ptrTemp->GetNextNode() != ptr; ptrTemp = ptrTemp->GetNextNode());
     ptrTemp->SetNextNode(ptr->GetNextNode());
     ptr->SetNextNode(nullptr); 
     delete ptr;

 }

