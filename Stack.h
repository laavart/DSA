//
// Created by Oballium on 04-11-2021.
//

#ifndef DSA_STACK_H
#define DSA_STACK_H

template <typename T>

class Stack{

    struct stackNode{
        T x;
        stackNode *n;
    };

    stackNode *top;
public:
    Stack(){
        top = nullptr;
    }

    void push(T x){
        if( isFull() ) cout<<"Stack Overflow!!!"<<endl;
        else{
            auto *p = new stackNode;
            p->x = x;
            p->n = top;
            top = p;
        }
    }

    T pop(){
        if( isEmpty() ) cout<<"Empty Stack!!!"<<endl;
        else{
            stackNode *p = top;
            T x = top->x;
            top = top->n;
            delete p;
            return x;
        }
        return NULL;
    }

    T peek(int pos){
        stackNode *p = top;

        for(int i=1; i<pos && p!= nullptr; i++) p = p->n;

        return p != nullptr ? p->x : -1;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    bool isFull(){
        auto *p = new stackNode;
        if(p == nullptr) return true;
        else{
            delete p;
            return false;
        }
    };

    T getTop(){
        return top->x;
    }

    static void test(){
        Stack<int> s;
        cout<<"Empty: "<<s.isEmpty()<<endl;
        s.push(10);
        s.push(2);
        s.push(3);
        cout<<s.pop()<<endl;
        s.push(22);
        s.push(100);
        cout<<s.getTop()<<endl;
        cout<<s.peek(3)<<endl;
        cout<<"Full: "<<s.isFull()<<endl;
    }
};

#endif //DSA_STACK_H
