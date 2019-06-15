//
// Created by gacova on 22/05/19.
//

#ifndef DISK_NODE_H
#define DISK_NODE_H
template <class T>
class Node {
private:
    T data;
    Node<T> *next;

public:
    Node(T data) {
        Node::data = data;
        next = nullptr;
    }

    void setData(T data) {
        Node::data = data;
    }

    T getData() {
        return data;
    }

    void setNext(Node *next) {
        Node::next = next;
    }

    Node* getNext() {
        return next;
    }
};
#endif //DISK_NODE_H
