#ifndef INVINCIBLESERVER_NODE_H
#define INVINCIBLESERVER_NODE_H

template <class T>
class Node
{
private:
    T data;
    Node<T> *next;

public:
    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }

    void setData(T data)
    {
        this->data = data;
    }

    T getData()
    {
        return data;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }

    Node* getNext()
    {
        return next;
    }
};

#endif //INVINCIBLESERVER_NODE_H
