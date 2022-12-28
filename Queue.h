
#ifndef HEALTHPOINTS_CPP_QUEUE_H
#define HEALTHPOINTS_CPP_QUEUE_H



template <typename T>

class Queue{

    struct Node{
        T data;
        Node* next;
    };

    Node *back;
    Node *front;
    int size;

public:

    class EmptyQueue{};
    Queue()
    {
        back = front = nullptr;
        size = 0;
    }

    void pushBack(T data)
    {
        Node newNode = new Node;
        newNode.data = data;
        newNode.next = nullptr;
        if (size == 0)
        {
            back = newNode;
            front = newNode;
            size++;
        }
        else if (size > 0)
        {
            back->next = newNode;
            back = newNode;
            size ++;
        }
    }

    void popFront()
    {
       if(size == 0)
       {
           throw EmptyQueue();
       }
       else if (size > 0)
       {
           Node* temp = front;
           front = front->next;
           if(front == nullptr)
           {
               back = nullptr;
           }
           delete temp;
       }
    }



};
#endif //HEALTHPOINTS_CPP_QUEUE_H
