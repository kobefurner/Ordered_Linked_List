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
    Node<Type>* temp = other.front;
    while (temp != nullptr)
    {
        this->insert(temp->data);
        temp = temp->next;
    }
}

template <typename Type>
OrderedLinkedList<Type>& OrderedLinkedList<Type>::operator=(const OrderedLinkedList& other)
{
    if (this != &other)
    {
        this->clear();
        Node<Type>* temp = other.front;
        while (temp != nullptr)
        {
            this->insert(temp->data);
            temp = temp->next;
        }
    }
   return *this;
}

template <typename Type>
OrderedLinkedList<Type>::~OrderedLinkedList()
{
    this->clear();
}

template <typename Type>
int OrderedLinkedList<Type>::size() const
{
  return count;
}

template <typename Type>
bool OrderedLinkedList<Type>::empty() const
{
    if (count == 0){
        return true;
    }
    else{
        return false;
    }
}

template <typename Type>
Type OrderedLinkedList<Type>::get(int pos) const
{
    if (pos < 0 || pos >= count)
    {
        throw std::out_of_range("Invalid position");
    }

    Node<Type>* temp = front;
    for (int i = 0; i < pos; i++){
        temp = temp->next;
    }
    return temp->data;
}

template <typename Type>
Type OrderedLinkedList<Type>::getFirst() const
{
    if (count == 0)
    {
        throw std::out_of_range("List is empty");
    }
    else
    {
        return front->data;
    }
}

template <typename Type>
Type OrderedLinkedList<Type>::getLast() const
{
    if (front == nullptr)
    {
        throw std::runtime_error("List is empty");
    }
    Node<Type>* temp = front;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->data;
}

template <typename Type>
void OrderedLinkedList<Type>::insert(const Type& item)
{
    Node<Type>* newNode = new Node<Type>;
    newNode->data = item;

    if (front == nullptr || item < front->data)
    {
        newNode->next = front;
        front = newNode;
        if (back == nullptr)
        {
            back = newNode;
        }
    }
    else
    {
        Node<Type>* temp = front;
        while (temp->next != nullptr && temp->next->data < item)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr)
        {
            back = newNode;
        }
    }
    count++;
}

template <typename Type>
int OrderedLinkedList<Type>::find( const Type& item ) const
{
    Node<Type>* temp = front;
    int pos = 0;
    while (temp != nullptr){
        if (temp->data == item){
            return pos;
        }
        else {
            temp = temp->next;
            pos++;
        }
    }
    return -1;
}

template <typename Type>
void OrderedLinkedList<Type>::remove( const Type& item )
{
    if (front == nullptr)
    {
        return;
    }
   if (front->data == item)
   {
       Node<Type>* temp = front;
       front = front->next;
       delete temp;
       count--;
   }
   else {
        Node<Type> * temp = front;
        while (temp->next != nullptr && temp->next->data != item)
        {
            temp = temp->next;
        }
        if (temp->next != nullptr)
        {
            Node<Type>* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            count--;
        }
   }
}

template <typename Type>
void OrderedLinkedList<Type>::clear()//same as the ~delete?
{
    Node<Type>* temp = front;
    while (front != nullptr)
    {
        front = front->next;
        delete temp;
        temp = front;
    }
    back = nullptr;
    count = 0;
}

template <typename Type>
OrderedLinkedList<Type> OrderedLinkedList<Type>::everyOtherOdd() 
{
    OrderedLinkedList<Type> oddList;
    Node<Type>* temp = front;
    while (temp != nullptr) {
        oddList.insert(temp->data);
        if (temp->next != nullptr) {
            temp = temp->next->next;
        }
        else {
            temp = temp->next;
        }
    }
    return oddList;
}

template <typename Type>
OrderedLinkedList<Type> OrderedLinkedList<Type>::everyOtherEven()
{
    OrderedLinkedList<Type> evenList;
    Node<Type>* temp = front->next;
     while (temp != nullptr) {
        evenList.insert(temp->data);
        if (temp->next != nullptr) {
            temp = temp->next->next;
        }
        else {
            temp = temp->next;
        }
    }
    return evenList;
}

template <typename Type>
std::ostream& operator<<(std::ostream& out, const OrderedLinkedList<Type>& list)
{
    Node<Type>* temp = list.front;
    while (temp != nullptr)
    {
        out << temp->data;
        if (temp->next != nullptr)
        {
            out << "->";
        }
        temp = temp->next;
    }
    return out;
}
#endif
