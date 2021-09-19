#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "node.hpp"

template <typename T>
class CList
{
private:
    CNode<T> *m_fictionalHead;
    CNode<T> *m_realTail;

public:
    CList();
    ~CList();
    void push_front(const T &val);
    void Show() const;
    void ShowAdvanced() const;
    CNode<T> *Find(const T &val) const;
    void Add(const T &val, CNode<T> *);
    void Delete(CNode<T> *);
    void push_back(const T &val);
    CNode<T> *Begin() const;
    void AddAfter(CNode<T> *, const T &val);
};

template <typename T>
CNode<T> *CList<T>::Begin() const
{
    return m_fictionalHead;
}

template <typename T>
void CList<T>::AddAfter(CNode<T> *ptr, const T &val)
{
    if (ptr != nullptr)
    {
        ptr->SetNextNode(new CNode<T>(val, ptr->GetNextNode()));
        if (ptr == m_realTail)
            m_realTail = ptr->GetNextNode();
    }
    else
        std::cout << "nombre pas dans la liste\n";
}

template <typename T>
void CList<T>::Add(const T &val, CNode<T> *ptr)
{
    CNode<T> *ptrTmp = new CNode<T>(val, ptr->GetNextNode());
    ptr->SetNextNode(ptrTmp);
    if (ptr == m_realTail)
        m_realTail = ptr->GetNextNode();
}

template <typename T>
CList<T>::CList() : m_fictionalHead(new CNode<T>()), m_realTail(m_fictionalHead){};

template <typename T>
CList<T>::~CList()
{
    delete m_fictionalHead;
}

template <typename T>
CNode<T> *CList<T>::Find(const T &val) const
{
    CNode<T> *Ptr(m_fictionalHead->GetNextNode());
    for (; Ptr != nullptr && Ptr->GetData() != val; Ptr = Ptr->GetNextNode())
        ;

    return Ptr;
}

template <typename T>
void CList<T>::push_front(const T &val)
{
    m_fictionalHead->SetNextNode(new CNode<T>(val, m_fictionalHead->GetNextNode()));
    if (m_realTail == m_fictionalHead)
        m_realTail = m_fictionalHead->GetNextNode();
}

template <typename T>
void CList<T>::Show() const
{
    //for (CNodeInt* Ptr (m_Head); Ptr; ++*Ptr)
    for (CNode<T> *Ptr(m_fictionalHead->GetNextNode()); Ptr; Ptr = Ptr->GetNextNode())
        std::cout << Ptr->GetData() << "; ";
    std::cout << std::endl;
}

template <typename T>
inline void CList<T>::ShowAdvanced() const
{
    //last data is pointer
    cout << "|   HEAD FICTIVE   | address : " << m_fictionalHead << " |\n";
    for (CNode<T> *ptr(m_fictionalHead->GetNextNode()); ptr != nullptr; ptr = ptr->GetNextNode())
        cout << "| data : " << ptr->GetData() << " | address : " << ptr << " | next address : " << ptr->GetNextNode() << " |\n";
    cout << "|   queue  | address : " << m_realTail << " |\n";
    //first data is Queue
    cout << "\n";
}

template <typename T>
void CList<T>::Delete(CNode<T> *pDelete)
{
    if (pDelete == nullptr)
        return;
    CNode<T> *pFind(m_fictionalHead);
    for (; pFind->GetNextNode() != pDelete; pFind = pFind->GetNextNode())
        ;

    pFind->SetNextNode(pDelete->GetNextNode());
    if (pDelete == m_realTail)
        m_realTail = pFind;
    pDelete->SetNextNode(nullptr);

    delete pDelete;
}

template <typename T>
void CList<T>::push_back(const T &val)
{
    CNode<T> *pTmp = new CNode<T>(val, nullptr);
    m_realTail->SetNextNode(pTmp);
    m_realTail = pTmp;
}

#endif // LIST_HPP
