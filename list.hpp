#pragma once
#include "node.hpp"

template<typename T>

class CList
{
private:
    CNode<T>* m_Head; //  premier élément
    CNode<T>* m_Queue; // dernier élément
public:
    CList();
    ~CList();
    //ajout en tête de liste
    void push_front(const T& data);

    //ajout en queue de liste
    void push_back(const T& data);

    //affichage
    void Show() const;

    //recherche d'un élément dans la liste, renvoie le pointeur du maillon si l'élément est présent, nullptr sinon
    CNode<T>* Find(const T& data) const;

    //ajout d'une valeur après un maillon de la liste
    void AddAfter(const T& data, CNode<T>*);

    //détache un maillon de la liste et le supprime
    void Delete(CNode<T>*);

    //  GetNextNode ()
    CNode<T>* Begin() const;

    
};

template<typename T>
 CList<T>::CList() : m_Head(new CNode<T> ()),m_Queue(m_Head)
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
     if (m_Queue == nullptr)m_Queue = m_Head;
 }

 template<typename T>
 inline void CList<T>::push_back(const T& data)
 {

     CNode<T>* ptrTemp = new CNode<T>(data, nullptr);
     m_Queue->SetNextNode(ptrTemp);
     m_Queue = ptrTemp;
     
 }

 template<typename T>
 inline void CList<T>::Show() const
 {
     //last data is pointer
     cout << "|   HEAD   | address : " << m_Head << " |\n";
     for(CNode<T>* ptr(m_Head);ptr!=nullptr;ptr=ptr->GetNextNode())
        cout << "| data : " << ptr->GetData() << " | address : " << ptr << " | next address : " << ptr->GetNextNode() << " |\n";
     cout << "|   queue  | address : " << m_Queue << " |\n";
     //first data is Queue 
     cout << "\n";
 }

 template<typename T>
 inline CNode<T>* CList<T>::Find(const T& data) const
 {
     CNode<T>* ptr(m_Head);
     for (; ptr!= nullptr &&ptr->GetData() !=data; ptr = ptr->GetNextNode());
     return ptr;
 }

 template<typename T>
 inline void CList<T>::AddAfter(const T& data, CNode<T>* ptr)
 {
     if (ptr != nullptr) {
         CNode<T>* ptrTemp = new CNode<T>(data, ptr->GetNextNode());
         ptr->SetNextNode(ptrTemp);
     }
     else
         m_Head = new CNode<T>(data, m_Head);
     
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

 template<typename T>
 inline CNode<T>* CList<T>::Begin() const
 {
     return m_Head;
 }
