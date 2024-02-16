#ifndef ORDEREDLINKEDLIST_HPP
#define ORDEREDLINKEDLIST_HPP
#include <iostream>
#include <stdexcept>

template <typename Type>
struct Node
{
    Type data{};
    Node<Type>* next{ nullptr };
};

template <typename Type>
class OrderedLinkedList;

template <typename Type>
std::ostream& operator<<(std::ostream&, const OrderedLinkedList<Type>& list);

template <typename Type>
class OrderedLinkedList
{
public:
    OrderedLinkedList() { } // Default constructor has no code boy has data members initialize themselves
    OrderedLinkedList(const OrderedLinkedList& other);
    OrderedLinkedList<Type>& operator=(const OrderedLinkedList<Type>& other);
    ~OrderedLinkedList();

    int size() const;
    bool empty() const;
    Type get(int) const;
    Type getFirst() const;
    Type getLast() const;
    void insert(const Type&);
    int find(const Type&) const;
    void remove(const Type&);
    void clear();
    OrderedLinkedList<Type> everyOtherOdd();
    OrderedLinkedList<Type> everyOtherEven();
    friend std::ostream& operator<< <>(std::ostream&, const OrderedLinkedList<Type>& list);
private:
    Node<Type>* front{nullptr};
    Node<Type>* back{nullptr};
    int count{0};
};

template <typename Type>
OrderedLinkedList<Type>::OrderedLinkedList(const OrderedLinkedList<Type>& other)
{

}

template <typename Type>
OrderedLinkedList<Type>& OrderedLinkedList<Type>::operator=(const OrderedLinkedList& other)
{
   return *this;
}

template <typename Type>
OrderedLinkedList<Type>::~OrderedLinkedList()
{

}

template <typename Type>
int OrderedLinkedList<Type>::size() const
{
  return -1;
}

template <typename Type>
bool OrderedLinkedList<Type>::empty() const
{
     return true;
}

template <typename Type>
Type OrderedLinkedList<Type>::get(int pos) const
{
    Type ret;
    return ret;
}

template <typename Type>
Type OrderedLinkedList<Type>::getFirst() const
{
    Type ret;
    return ret;
}

template <typename Type>
Type OrderedLinkedList<Type>::getLast() const
{
    Type ret;
    return ret;
}

template <typename Type>
void OrderedLinkedList<Type>::insert(const Type& item)
{

}

template <typename Type>
int OrderedLinkedList<Type>::find( const Type& item ) const
{
    return -1;
}

template <typename Type>
void OrderedLinkedList<Type>::remove( const Type& item )
{
    
}

template <typename Type>
void OrderedLinkedList<Type>::clear()//same as the ~delete?
{
    
}

template <typename Type>
OrderedLinkedList<Type> OrderedLinkedList<Type>::everyOtherOdd() 
{
    OrderedLinkedList<Type> retVal;
    return retVal;
}
template <typename Type>
OrderedLinkedList<Type> OrderedLinkedList<Type>::everyOtherEven()
{
    OrderedLinkedList<Type> retVal;
    return retVal;
}

template <typename Type>
std::ostream& operator<<(std::ostream& out, const OrderedLinkedList<Type>& list)
{
    return out;
}
#endif
