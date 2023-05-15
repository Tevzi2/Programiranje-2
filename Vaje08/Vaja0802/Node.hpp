#pragma once

template<typename T>
class Node
{
    public:
        explicit Node(T key, Node* next = nullptr)
            : key(key), next(next)
        {
            ;
        }

    [[nodiscard]] T* getKey()
    {
        return &key;
    }

    void setKey(T key)
    {
        Node::key = key;
    }

    [[nodiscard]] Node *getNext() const
    {
        return next;
    }

    void setNext(Node *next)
    {
        Node::next = next;
    }

private:
        T key;
        Node* next;
};