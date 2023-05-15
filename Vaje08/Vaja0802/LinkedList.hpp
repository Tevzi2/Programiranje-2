#pragma once

#include <iostream>
#include <Node.hpp>

template<typename T>
class LinkedList {
public:
    ~LinkedList() {
        Node<T>* current = head;
        while(current != nullptr)
        {
            Node<T>* now = current;
            current = current->getNext();
            delete now;
        }
    }

    [[nodiscard]] bool is_empty() const {
        return size == 0;
    }

    [[nodiscard]] size_t get_size() const {
        return size;
    }

    void add(T element) {
        if(head == nullptr)
        {
            head = new Node<T>(element);
            size++;
            return;
        }

        Node<T>* current = head;

        while(current->getNext() != nullptr)
        {
            current = current->getNext();
        }

        current->setNext(new Node<T>(element));

        size++;
    }

    void insert_at(T element, uint32_t index)
    {
        if(index >= size) return;

        Node<T>* current = head;
        Node<T>* prev = nullptr;
        uint32_t i = 0;

        while(i != index)
        {
            prev = current;
            current = current->getNext();
            i++;
        }

        Node<T>* new_el = new Node<T>(element, current);

        prev->setNext(new_el);

        size++;
    }

    [[nodiscard]] T* at(uint32_t index) const
    {
        if(index >= size) return nullptr;

        Node<T>* current = head;

        for(uint32_t i = 0; i < index; i++)
        {
            current = current->getNext();
        }

        return current->getKey();
    }

    private:
        size_t size = 0;
        Node<T>* head = nullptr;
};