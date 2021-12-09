//
// Created by Oballium on 10-10-2021.
//

#ifndef DSA_LINKEDLIST_H
#define DSA_LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node{
    Node *p;
    int x;
    Node *n;
};

class SinglyLinkedList{
    Node *head;

public:

    SinglyLinkedList(const int a[], int n){
        Node *l;
        for(int i=0; i<n; i++){
            Node *t = new Node;
            t->x = a[i];
            t->n = nullptr;
            if(i == 0){
                head = t;
            }
            else{
                l->n = t;
            }
            l = t;
        }
    }

    void display(){
        Node *t = head;
        cout<<"List elements are:"<<endl;
        while(t != nullptr){
            cout<< t->x <<endl;
            t = t->n;
        }
    }

    int count(){
        Node *t = head;
        int c=0;
        while(t != nullptr){
            c++;
            t = t->n;
        }
        return c;
    }

    int sum(){
        Node *t = head;
        int s=0;
        while(t != nullptr){
            s += t->x;
            t = t->n;
        }
        return s;
    }

    int max(){
        Node *t = head;
        int mx = t->x;
        while(t != nullptr){
            if(mx < t->x){
                mx = t->x;
            }
            t = t->n;
        }
        return mx;
    }

    int min(){
        Node *t = head;
        int mn = t->x;
        while(t != nullptr){
            if(mn > t->x){
                mn = t->x;
            }
            t = t->n;
        }
        return mn;
    }

    Node * search(int k){
        Node *t = head;
        while(t != nullptr){
            if(k == t->x){
                return t;
            }
            t = t->n;
        }
        return nullptr;
    }

    Node * search_MTH(int k){
        Node *tmp, *f = head, *t = head;
        while(head != nullptr){
            if(k == t->x){
                    tmp = f->n;
                    f->n = t->n;
                    t->n = tmp;
                delete tmp;
                return t;
            }
            t = t->n;
        }
        return nullptr;
    }

    void insertAt(int pos, int x){
        if(pos<=count()+1 && pos>0){
            Node * t = new Node;
            t->x = x;
            if(count() == 0){
                t->n = nullptr;
                head = t;
            }
            else if(pos == 1){
                t->n = head;
                head = t;
            }
            else{
                Node * l = head;
                for(int i=1; i < pos-1; i++){
                    l = l->n;
                }
                t->n = l->n;
                l->n = t;
            }
        }
        else{
            cout<<"Position Not Available!!! Current Node Count: "<<count()<<endl;
        }
    }

    void insertAtFirst(int x){
        Node * t = new Node;
        t->x = x;
        t->n = head;
        head = t;
    }

    void insertAtLast(int x){
        Node * t = new Node;
        Node * l = head;
        t->x = x;
        while(l->n){
            l = l->n;
        }
        t->n = l->n;
        l->n = t;
    }

    void deleteNode(int pos){
        if(pos <= count() && pos>0){
            if(pos == 1){
                Node *q = head;
                head = head->n;
                delete q;
            }
            else {
                Node *l = head;

                for (int i=1; i < pos-1; i++) {
                    l = l->n;
                }

                if (pos == count()) {
                    delete l->n;
                    l->n = nullptr;
                }

                else {
                    Node *q = l->n;
                    l->n = q->n;
                    delete q;
                }
            }
        }
        else{
            cout<<"Invalid Position!!! Current Node Count: "<<count()<<endl;
        }
    }

    void deleteFirstNode(){
        Node *q = head;
        head = head->n;
        delete q;
    }

    void deleteLastNode(){
        Node *l = head;

        for (int i=1; i < count()-1; i++) {
            l = l->n;
        }

        delete l->n;
        l->n = nullptr;
    }

    bool isSorted(){
        Node *l = head;
        for (int i=1; i <= count()-1; i++) {
            if(l->x > l->n->x){
                return false;
            }
            l = l->n;
        }
        return true;
    }

    void deleteDuplicates(){
        Node *l = head;
        while(l->n != nullptr){
            if(l->x == l->n->x){
                Node * m = l->n->n;
                Node *o = l->n;
                delete o;
                l->n = m;
            }
            else{
                l = l->n;
            }
        }
    }

    void reverseValues(){
        Node * l = head;
        int a[count()];
        for(int i=0; i<count(); i++, l = l->n){
            a[i] = l->x;
        }
        l = head;
        for(int i = count()-1; i>=0; i--, l = l->n){
            l->x = a[i];
        }
    }

    void reverseLinks(){
        Node *l = head;
        Node *m = l->n;
        Node *o = m->n;
        Node *t;
        int c = count();
        l->n = nullptr;
        for(int i=1; i<c; i++){
            if(o->n != nullptr ){
                t = o->n;
            }
            m->n = l;
            head=m;
            if(i != c-1){
                l=m;
                m=o;
                o=t;
            }
        }
    }

    void concatWithList(Node *s){
        Node *l = head;
        while(l->n != nullptr){
            l = l->n;
        }
        l->n = s;
    }

    void mergeWithList(Node *s){
        Node *f = head;
        Node *l;

        if(f->x < s->x){
            l = f;
            head = l;
            f = f->n;
            l->n = nullptr;
        }
        else{
            l = s;
            head = l;
            s = s->n;
            l->n = nullptr;
        }

        while(f != nullptr && s != nullptr){
            if(f->x < s->x){
                l->n = f;
                l = f;
                f = f->n;
                l->n = nullptr;
            }
            else{
                l->n = s;
                l = s;
                s = s->n;
                l->n = nullptr;
            }
        }

        while(f != nullptr){
            l->n = f;
            l = f;
            f = f->n;
            l->n = nullptr;
        }

        while(s != nullptr){
            l->n = s;
            l = s;
            s = s->n;
            l->n = nullptr;
        }
    }

    bool isLOOP(){
        Node *l = head, *dl = head;
        while(dl != nullptr){
            l = l->n;
            dl = dl->n;
            dl = dl != nullptr ? dl->n : nullptr;

            if(l==dl){
                return true;
            }
        }
        return false;
    }

    Node * getPointer(){
        return head;
    }
};

class CircularSinglyLinkedList {
    Node *head;

public:

    CircularSinglyLinkedList(const int a[], int n) {
        Node *l;
        for (int i = 0; i < n; i++) {
            Node *t = new Node;
            t->x = a[i];
            t->n = head;
            if (i == 0) {
                head = t;
            }
            else{
                l->n = t;
            }
            l = t;
        }
    }

    void display() {
        Node *t = head;
        int flag = 0;
        cout << "List elements are:" << endl;
        while (t != head || flag==0) {
            flag++;
            cout << t->x << endl;
            t = t->n;
        }
    }

    int count(){
        Node *t = head;
        int flag = 0;
        int c=0;
        while(t != head || flag==0){
            flag++;
            c++;
            t = t->n;
        }
        return c;
    }

    int sum(){
        Node *t = head;
        int flag = 0;
        int s=0;
        while(t != head || flag==0){
            s += t->x;
            t = t->n;
            flag++;
        }
        return s;
    }

    int max(){
        Node *t = head;
        int flag = 0;
        int mx = t->x;
        while(t != head || flag==0){
            flag++;
            if(mx < t->x){
                mx = t->x;
            }
            t = t->n;
        }
        return mx;
    }

    int min(){
        Node *t = head;
        int flag = 0;
        int mn = t->x;
        while(t != head || flag==0){
            flag++;
            if(mn > t->x){
                mn = t->x;
            }
            t = t->n;
        }
        return mn;
    }

    Node * search(int k){
        Node *t = head;
        int flag = 0;
        while(t != head || flag==0){
            flag++;
            if(k == t->x){
                return t;
            }
            t = t->n;
        }
        return nullptr;
    }

    void insertAt(int pos, int x){
        if(pos-1 <= count() && pos>0){
            Node *t = new Node;
            t->x = x;
            if(count() == 0){
                t->n = t;
                head = t;
            }
            else if(pos == 1){
                Node *l = head;
                while(l->n != head){
                    l = l->n;
                }
                t->n = head;
                head = t;
                l->n = head;
            }
            else{
                Node *l = head;
                for(int i=1; i < pos-1; i++){
                    l = l->n;
                }
                t->n = l->n;
                l->n = t;
            }
        }
        else{
            cout<<"Position Not Available!!! Current Node Count: "<<count()<<endl;
        }
    }

    void deleteNodeAt(int pos){
        if(pos > count() || pos<0){
            cout<<"Invalid Position!!! Current Node Count: "<<count()<<endl;
        }
        else{
            Node *l = head;
            if(pos == 1){
                Node *t = head;
                while(t->n != head){
                    t = t->n;
                }
                l = head;
                head = head->n;
                delete l;
                t->n = head;
            }
            else{
                for(int i=1; i < pos-1; i++){
                    l = l->n;
                }
                Node *t = l->n;
                l->n = t->n;
                delete t;
            }
        }
    }
};

class DoublyLinkedList {
    Node *head;
    Node *tail;

public:

    DoublyLinkedList(const int a[], int n) {
        Node *l;
        for(int i=0; i<n; i++){
            Node *t = new Node;
            t->x = a[i];
            t->n = nullptr;
            if(i==0){
                head = t;
                t->p = nullptr;
            }
            else{
                t->p = l;
                l->n = t;
                if(i == n-1){
                    tail = t;
                }
            }
            l = t;
        }
    }

    void display() {
        Node *t = head;
        cout << "List elements are:" << endl;
        while (t != nullptr) {
            cout << t->x << endl;
            t = t->n;
        }
    }

    void displayR() {
        Node *t = tail;
        cout << "Reversed List:" << endl;
        while (t != nullptr) {
            cout << t->x << endl;
            t = t->p;
        }
    }

    int count() {
        Node *t = head;
        int c = 0;
        while (t != nullptr) {
            c++;
            t = t->n;
        }
        return c;
    }

    int sum() {
        Node *t = head;
        int s = 0;
        while (t != nullptr) {
            s += t->x;
            t = t->n;
        }
        return s;
    }

    int max() {
        Node *t = head;
        int mx = t->x;
        while (t != nullptr) {
            if (mx < t->x) {
                mx = t->x;
            }
            t = t->n;
        }
        return mx;
    }

    int min() {
        Node *t = head;
        int mn = t->x;
        while (t != nullptr) {
            if (mn > t->x) {
                mn = t->x;
            }
            t = t->n;
        }
        return mn;
    }

    Node *search(int k) {
        Node *t = head;
        while (t != nullptr) {
            if (k == t->x) {
                return t;
            }
            t = t->n;
        }
        return nullptr;
    }

    Node *search_MTH(int k) {
        Node *l = head;
        while (l != nullptr) {
            if (k == l->x) {
                if(l != head){
                    if(l == tail){

                        //others
                        head->n->p = l;
                        l->p->n = head;

                        //previous
                        head->p = l->p;
                        l->p = nullptr;

                        //next
                        l->n = head->n;
                        head->n = nullptr;

                        //finisher
                        tail = head;
                        head = l;
                    }
                    else{
                        Node *t;

                        //others
                        head->n->p = l;
                        l->n->p = head;
                        l->p->n = head;

                        //previous
                        head->p = l->p;
                        l->p = nullptr;

                        //next
                        t = l->n;
                        l->n = head->n;
                        head->n = t;

                        head = l;
                    }
                }
                return l;
            }
            l = l->n;
        }
        return nullptr;
    }

    Node *search_T(int k) {
        Node *l = head;
        while (l != nullptr) {
            if (k == l->x) {

                if(l != head){
                    Node *t;

                    //others
                    if(l == tail){
                        tail = l->p;
                    }
                    else{
                        l->n->p = l->p;
                    }
                    l->p->p->n = l;

                    //next
                    l->p->n = l->n;
                    l->n = l->p;

                    //previous
                    t = l->p;
                    l->p = l->p->p;
                    t->p = l;
                }
                return l;
            }
            l = l->n;
        }
        return nullptr;
    }

    void insertAt(int pos, int x){
        if(pos>0 && pos <= count()+1){
            Node *t = new Node;
            t->x = x;
            if(pos == 1){
                t->p = nullptr;
                t->n = head;
                head->p = t;
                head = t;
            }
            else if(pos == count()+1){
                t->p = tail;
                t->n = nullptr;
                tail->n = t;
                tail = t;
            }
            else{
                Node *l = head;
                for(int i=1; i<pos; i++){
                    l = l->n;
                }
                l->p->n = t;
                t->p = l->p;
                t->n = l;
                l->p = t;
            }
        }
        else{
            cout<<"Position Not Available!!! Current Node Count: "<<count()<<endl;
        }
    }

    void deleteElementAt(int pos){
        if(pos>=1 && pos<=count()){
            if(pos == 1){
                Node *t;
                t = head;
                head = head->n;
                head->p = nullptr;
                delete t;
            }
            else if(pos == count()){
                Node *t;
                t = tail;
                tail = tail->p;
                tail->n = nullptr;
                delete t;
            }
            else{
                Node *t;
                Node *l = head;
                for(int i=1; i<pos-1; i++){
                    l = l->n;
                }
                t = l->n;
                t->n->p = l;
                l->n = t->n;
                delete t;
            }
        }
        else{
            cout<<"Invalid Position!!! Current Node Count: "<<count()<<endl;
        }
    }
};

class DoublyCircularLinkedList {
    Node *head;
    Node *tail;

public:

    DoublyCircularLinkedList(const int a[], int n) {
        Node *l;
        for(int i=0; i<n; i++){
            Node *t = new Node;
            t->x = a[i];
            t->n = head;

            if(i==0){
                head = t;
            }
            else{
                t->p = l;
                l->n = t;

                if(i == n-1){
                    tail = t;
                    head->p = tail;
                }
            }
            l = t;
        }
    }

    void display() {
        Node *t = head;
        int flag  = 0;
        cout << "List elements are:" << endl;
        while (t != head || flag==0) {
            flag++;
            cout << t->x << endl;
            t = t->n;
        }
    }

    void displayR() {
        Node *t = tail;
        int flag  = 0;
        cout << "Reversed List:" << endl;
        while (t != tail || flag==0) {
            flag++;
            cout << t->x << endl;
            t = t->p;
        }
    }

    int count() {
        Node *t = head;
        int flag  = 0;
        int c = 0;
        while (t != head || flag==0) {
            flag++;
            c++;
            t = t->n;
        }
        return c;
    }

    int sum() {
        Node *t = head;
        int flag  = 0;
        int s = 0;
        while (t != head || flag==0) {
            flag++;
            s += t->x;
            t = t->n;
        }
        return s;
    }

    int max() {
        Node *t = head;
        int flag = 0;
        int mx = t->x;
        while (t != head || flag==0) {
            flag++;
            if (mx < t->x) {
                mx = t->x;
            }
            t = t->n;
        }
        return mx;
    }

    int min() {
        Node *t = head;
        int flag = 0;
        int mn = t->x;
        while (t != head || flag==0) {
            flag++;
            if (mn > t->x) {
                mn = t->x;
            }
            t = t->n;
        }
        return mn;
    }

    Node *search(int k) {
        Node *t = head;
        int flag = 0;
        while (t != head || flag==0) {
            flag++;
            if (k == t->x) {
                return t;
            }
            t = t->n;
        }
        return nullptr;
    }

    Node *search_MTH(int k) {
        Node *l = head;
        int flag = 0;
        while (l != head || flag==0) {
            flag++;
            if (k == l->x) {
                if(l != head){
                    if(l == tail){
                        tail->p->n = head;
                        head->p = tail->p;

                        head->n->p = tail;
                        tail->n = head->n;

                        head->n = tail;
                        tail->p = head;

                        Node *t = head;
                        head = tail;
                        tail = t;
                    }
                    else{
                        Node *t;

                        tail->n = l;
                        head->n->p = l;

                        l->p->n = head;
                        l->n->p = head;

                        head->p = l->p;
                        l->p = tail;

                        t = head->n;
                        head->n = l->n;
                        l->n = t;

                        head = l;
                    }
                }
                return l;
            }
            l = l->n;
        }
        return nullptr;
    }

    Node *search_T(int k) {
        Node *l = head;
        int flag = 0;
        while (l != head || flag==0) {
            flag++;
            if (k == l->x) {

                if(l != head) {
                    Node *q = l->p;

                    q->p->n = l;
                    l->p = q->p;

                    l->n->p = q;
                    q->n = l->n;

                    q->p = l;
                    l->n = q;

                    if(l == tail){
                       tail = q;
                    }
                }
                return l;
            }
            l = l->n;
        }
        return nullptr;
    }

    void insertAt(int pos, int x){
        if(pos>0 && pos <= count()+1){
            Node *t = new Node;
            t->x = x;
            if(pos == 1){
                t->p = tail;
                t->n = head;
                head->p = t;
                head = t;
                tail->n = head;
            }
            else if(pos == count()+1){
                t->p = tail;
                t->n = head;
                tail->n = t;
                tail = t;
                head->p = tail;
            }
            else{
                Node *l = head;
                for(int i=1; i<pos; i++){
                    l = l->n;
                }
                l->p->n = t;
                t->p = l->p;
                t->n = l;
                l->p = t;
            }
        }
        else{
            cout<<"Position Not Available!!! Current Node Count: "<<count()<<endl;
        }
    }

    void deleteElementAt(int pos){
        if(pos>=1 && pos<=count()){
            if(pos == 1){
                Node *t;
                t = head;
                head = head->n;
                head->p = tail;
                tail->n = head;
                delete t;
            }
            else if(pos == count()){
                Node *t;
                t = tail;
                tail = tail->p;
                tail->n = head;
                head->p = tail;
                delete t;
            }
            else{
                Node *t;
                Node *l = head;
                for(int i=1; i<pos-1; i++){
                    l = l->n;
                }
                t = l->n;
                t->n->p = l;
                l->n = t->n;
                delete t;
            }
        }
        else{
            cout<<"Invalid Position!!! Current Node Count: "<<count()<<endl;
        }
    }
};

#endif //DSA_LINKEDLIST_H
