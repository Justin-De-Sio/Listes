
#pragma once

template <typename T>
class CNode
{
private:
    T m_Data;
    CNode* m_NextNode;
public:
    //constructor
    CNode(const T& data = T(), CNode* nextNode = nullptr);
    //destructor
    ~CNode();

    //getter / setter
    const T& GetData() const;
    CNode* GetNextNode () const;
    void SetData(const T& data);
    void SetNextNode(CNode*);
};

template<typename T>
CNode<T>::CNode(const T& data, CNode* nextNode): m_Data(data), m_NextNode(nextNode)
{
}

template<typename T>
 CNode<T>::~CNode()
{
     delete m_NextNode;
}

template<typename T>
 const T & CNode<T>::GetData() const
{
    return m_Data;
}

template<typename T>
 CNode<T>* CNode<T>::GetNextNode() const
{
    return m_NextNode;
}

template<typename T>
 void CNode<T>::SetNextNode(CNode* NextNode)
{
    m_NextNode = NextNode;
}
