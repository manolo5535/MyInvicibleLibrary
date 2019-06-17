#ifndef INVINCIBLESERVER_LINKEDLIST_H
#define INVINCIBLESERVER_LINKEDLIST_H

#include <iostream>
#include "Node.h"

template <class T>
class LinkedList
{
private:
    Node<T> *first;
    int size;

public:
    /**
     * @brief Constructor
     * @tparam T tipo de dato
     */
    LinkedList()
    {
        first = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    /**
     * @brief Inserta un elemento al inicio de la lista
     * @tparam T tipo de dato
     * @param data
     */
    void insertAtFirst(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if(first == nullptr)
        {
            first = newNode;
        }else
        {
            newNode->setNext(first);
            first = newNode;
        }
        size++;
    }

    /**
     * @brief Inserta un elemnto al final de la lista
     * @tparam T tipo de dato
     * @param data
     */
    void insertAtEnd(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (first == nullptr)
        {
            first = newNode;
        }else
        {
            Node<T> *current = first;
            while (current->getNext() != nullptr)
            {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
        size++;
    }

    /**
     * @brief Obtiene el elemento con un indice especifico
     * @param position
     * @return Node<T>
     */
    Node<T>* getElement(int position) {
        Node<T> *current = first;

        if(position < size && position >= 0) {
            for (int i = 0; i < position; i++) {
                current = current->getNext();
            }
        } else{
            return nullptr;
        }
        return current;
    }

    /**
     * @brief Obtiene un elemento si este coincide con el dato buscado, sino devuelve un nodo nulo
     * @tparam T tipo de dato
     * @param data
     * @return Node<T>
     */
    Node<T>* getElement2(T data) {
        Node<T> *current = first; //Punto de partida en la busqueda

        for (int i = 0; i < size; ++i) {
            if (current->getData() == data){ //Coincide el elemento actual con el que se esta buscando
                return current; //Se retorna
            } else //No coinciden los elementos
                current = current->getNext(); //Se continua con el siguiente nodo en la lista
        }
        Node<T>* notFoundNode = new Node<T>(nullptr); //Se crea un nodo con un data nulo
        return notFoundNode; //Elemento no estaba en la lista
    }

    /**
     * @brief Metodo para establecer el dato que se estaba guardando en una posicion especifica
     * @tparam T tipo de dato
     * @param element Elemento que se desea almacenar
     * @param position Posicion en la que se desea almacenar el elemento
     */
    void setElement(T element, int position) {
        Node<T> *current = first;

        if (first != nullptr && position < size) {
            if (1 <= position && position < size) {
                for (int i = 0; i < (position - 1); i++) { //Se detiene en el nodo anterior al de la posición deseada
                    current = current->getNext();
                }
                current->getNext()->setData(element);
            }
            if (position == 0) { //caso en que la posicion deseada es como primer elemento
                first->setData(element);
            }
            if (size <= position) {
                for (int i = 0; i < (size - 1); i++) { //Se detiene en el último nodo de la lista
                    current = current->getNext();
                }
                current->getNext()->setData(element);
            }
        }
    }

    /**
     * @brief Metodo para eliminar un elemento en el indice indicado
     * @tparam T tipo de dato
     * @param position Posicion del elemento a eliminar
     */
    void deleteElement(int position) {
        if (position == 0 && size > 0) {
            first = first->getNext();
            size--;
        } else {
            if (position <= (size - 1)) {
                Node<T>* current = first;
                for (int i = 0; i < (position - 1); i++) {
                    current = current->getNext();
                }
                current->setNext(current->getNext()->getNext());
                size--;
            }
        }
    }

    /**
     * @brief Metodo para eliminar un elemento de la lista
     * @tparam T Tipo de dato
     * @param data
     */
    void deleteElement2(T data) {
        Node<T> *current = first;

        if (size > 0){
            if (*current->getData() == *data) {
                first = first->getNext();
                this->size--;
            } else {
                while (current != nullptr && current->getNext() != nullptr) {
                    if (*current->getNext()->getData() == *data) {
                        current->setNext(current->getNext()->getNext());
                        this->size--;
                    }
                    current = current->getNext();
                }
            }
        }
    }

    /**
     * @brief Metodo que verifica si dentro de la lista se encuentra un elemento ingresado
     * @tparam T Tipo de dato
     * @param data
     * @return bool
     */
    bool containsElement(T data) {
        Node<T> *current = first; //Punto de partida en la busqueda

        for (int i = 0; i < size; ++i) {
            if (current->getData() == data){ //Coincide el elemento actual con el que se esta buscando
                return true; //Se retorna true
            } else //No coinciden los elementos
                current = current->getNext(); //Se continua con el siguiente nodo en la lista
        }
        return false; //No se ha encontrado el elemento en la lista
    }

    /**
     * @brief Imprime la lista en consola
     */
    void printList() {
        Node<T> *current = first;
        while(current != nullptr){
            std::cout << (current->getData()) << ", ";
            current = current->getNext();
        }
        std::cout << std::endl;
    }
};

#endif //INVINCIBLESERVER_LINKEDLIST_H
