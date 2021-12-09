//
// Created by Oballium on 04-11-2021.
//

#ifndef DSA_QUEUE_H
#define DSA_QUEUE_H

template <typename T>

class Queue{

    struct queueNode{
        queueNode *p;
        T x;
        queueNode *n;
    };

    queueNode *first;
    queueNode *last;

public:

    Queue(){
        first = nullptr;
        last = nullptr;
    }

    void enQueue(T x){
        if( isFull() ) cout<<"Queue Overflow!!!"<<endl;
        else{
            auto *t = new queueNode;
            t->x = x;
            t->n = nullptr;

            if(first == nullptr){
                t->p = nullptr;
                first = t;
            }
            else{
                t->p = last;
                last->n = t;
            }

            last = t;
        }
    }

    T deQueue(){
        if( isEmpty() ) cout<<"Empty Queue!!!"<<endl;
        else{
            queueNode *t = first;
            first = first->n;
            T x = t->x;
            delete t;
            if(isEmpty()) last = nullptr;
            return x;
        }
        return NULL;
    }

    bool isEmpty(){
        return first == nullptr;
    }

    bool isFull(){
        auto *t = new queueNode;
        if(t == nullptr) return true;
        else{
            delete t;
            return false;
        }
    }

    T getFirst(){
        return first->x;
    }

    T getLast(){
        return last->x;
    }

    static void test(){
        Queue<int> q;
        q.enQueue(100);
        q.enQueue(200);
        q.enQueue(345);
        cout<<q.deQueue()<<endl;
        q.enQueue(525);
        q.enQueue(723);
        cout<<"First: "<<q.getFirst()<<endl;
        cout<<"Last: "<<q.getLast()<<endl;
    }
};

#endif //DSA_QUEUE_H
