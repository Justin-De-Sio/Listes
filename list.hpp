#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "node.hpp"


template <typename T>
class CList
{
private:
    std::shared_ptr<CNode<T>>  m_fictionaHead;
    std::shared_ptr<CNode<T>>  m_fictionaTail;

public:
    CList ();

    void push_front (const T & val);
    void push_back (const T & val);
    void Show () const;
    std::shared_ptr<CNode<T>>  Find (const T & val) const;
    void Delete (std::shared_ptr<CNode<T>> );
    std::shared_ptr<CNode<T>>  Begin () const;
    void AddAfter (const std::shared_ptr<CNode<T>> &, const T & val);
    void AddBefore (const std::shared_ptr < CNode < T>> &, const T & val);
};

template <typename T>
std::shared_ptr<CNode<T>>  CList<T>::Begin () const
{
    return m_fictionaHead;
}

template <typename T>
void CList<T>::AddAfter (const std::shared_ptr<CNode<T>>  &ptr, const T & val)
{
    std::shared_ptr<CNode<T>> tmp {new CNode<T>(val, ptr, ptr->GetNextNode())};
    ptr -> SetNextNode (tmp);
    tmp->GetNextNode()->SetPrevNode(tmp);
}



template<typename T>
void CList<T>::AddBefore(const std::shared_ptr<CNode<T>> & ptr, const T &val) {
    AddAfter(ptr->GetPrevNode(),val);
}


template <typename T>
CList<T>::CList () : m_fictionaHead (new CNode<T>()), m_fictionaTail (new CNode<T>()) {
    m_fictionaHead->SetNextNode(m_fictionaTail);
    m_fictionaTail->SetPrevNode(m_fictionaHead);
};



template <typename T>
std::shared_ptr<CNode<T>>  CList<T>::Find (const T & val) const
{
    auto  Ptr (m_fictionaHead->GetNextNode ());
    for (; Ptr != nullptr && Ptr -> GetData () != val ; Ptr = Ptr->GetNextNode ());

    return Ptr;
}



template <typename T>
void CList<T>::push_front (const T & val)
{
    AddAfter(m_fictionaHead,val);
}
template <typename T>
void CList<T>::push_back (const T & val)
{
    AddBefore(m_fictionaTail,val);
}

template <typename T>
void CList<T>::Show () const
{
    //for (CNodeInt* Ptr (m_Head); Ptr; ++*Ptr)
    for (auto Ptr (m_fictionaHead -> GetNextNode()); Ptr!=m_fictionaTail; Ptr = Ptr->GetNextNode ())
              std::cout  << Ptr->GetData()<<";";

    std::cout << std::endl;
}

template <typename T>
void CList<T>::Delete (std::shared_ptr<CNode<T>>  pDelete)
{
    auto pFind (m_fictionaHead);
    for ( ; pFind -> GetNextNode () != pDelete ; pFind = pFind -> GetNextNode ());


    pFind -> SetNextNode (pDelete -> GetNextNode ());
    pDelete->GetNextNode()->SetPrevNode(pFind);
    pDelete -> SetNextNode (nullptr);
    pDelete ->SetPrevNode(nullptr);

}





#endif // LIST_HPP
