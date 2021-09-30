#ifndef NODE_HPP
#define NODE_HPP

#include "memory"

template<typename T>
class CNode {
private:
    T m_Data;
    std::shared_ptr<CNode> m_Next;
    std::shared_ptr<CNode> m_Prev;
public:
    //constructor
    explicit CNode(const T &val = T(), std::shared_ptr<CNode> ptrPrev = nullptr,
                   std::shared_ptr<CNode> ptrNext = nullptr);


    //getter / setter
    const T &GetData() const;

    std::shared_ptr<CNode> GetNextNode() const;

    void SetNextNode(std::shared_ptr<CNode>);

    std::shared_ptr<CNode> GetPrevNode() const;

    void SetPrevNode(std::shared_ptr<CNode>);
};


template<typename T>
CNode<T>::CNode(const T &val, std::shared_ptr<CNode> ptrPrev, std::shared_ptr<CNode> ptrNext) :m_Data(val),
                                                                                               m_Next(ptrNext),
                                                                                               m_Prev(ptrPrev) {

}


template<typename T>
const T &CNode<T>::GetData() const {
    return m_Data;
}

template<typename T>
std::shared_ptr<CNode<T>> CNode<T>::GetNextNode() const {
    return m_Next;
}


template<typename T>
void CNode<T>::SetNextNode(std::shared_ptr<CNode> ANode) {
    m_Next = ANode;
}

template<typename T>
std::shared_ptr<CNode<T>> CNode<T>::GetPrevNode() const {
    return m_Prev;
}

template<typename T>
void CNode<T>::SetPrevNode(std::shared_ptr<CNode> prev) {
    m_Prev = prev;

}


#endif // NODE_HPP
