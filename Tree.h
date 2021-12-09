//
// Created by Oballium on 08-11-2021.
//

#ifndef DSA_TREE_H
#define DSA_TREE_H

#include "Queue.h"
#include "Stack.h"
#include "math.h"

template <typename T>
class Tree{
    struct treeNode{
        treeNode *left;
        T x;
        treeNode *right;
    };
    treeNode *root;

public:

    Tree(){
        cout<<"Enter ROOT value:"<<endl;
        T x;
        cin>>x;
        root = new treeNode;
        root->left = nullptr;
        root->x = x;
        root->right = nullptr;

        Queue<treeNode *> q;
        q.enQueue(root);

        while( ! q.isEmpty() ){

            treeNode *t;
            t = q.deQueue();

            cout<<"Enter left leaf of "<<t->x<<":"<<endl;
            cin>>x;
            if(x!=NULL){
                auto *p = new treeNode;
                p->left = nullptr;
                p->x = x;
                p->right = nullptr;
                t->left = p;
                q.enQueue(p);
            }

            cout<<"Enter right leaf of "<<t->x<<":"<<endl;
            cin>>x;
            if(x!=NULL){
                auto *p = new treeNode;
                p->left = nullptr;
                p->x = x;
                p->right = nullptr;
                t->right = p;
                q.enQueue(p);
            }
        }
        cout<<endl;
    }

    treeNode * getROOT(){
        return root;
    }

    int count(){
        int c = 0;
        Queue<treeNode *> q;
        q.enQueue(root);
        while( ! q.isEmpty() ){
            treeNode *t = q.deQueue();
            c++;
            if(t->left != nullptr) q.enQueue(t->left);
            if(t->right != nullptr) q.enQueue(t->right);
        }
        return c;
    }

    int height(){
        int n = count();
        Queue<treeNode *> q;
        q.enQueue(root);
        while( ! q.isEmpty() ){
            treeNode *t = q.deQueue();
            if(t->left != nullptr) q.enQueue(t->left);
            else n++;
            if(t->right != nullptr) q.enQueue(t->right);
            else n++;
        }
        return (int) log2(n);
    }

    static void preOrdered(treeNode *t){
        if(t!= nullptr){
            cout<<t->x<<" ";
            preOrdered(t->left);
            preOrdered(t->right);
        }
    }

    static void inOrdered(treeNode *t){
        if(t!= nullptr){
            inOrdered(t->left);
            cout<<t->x<<" ";
            inOrdered(t->right);
        }
    }

    static void postOrdered(treeNode *t){
        if(t!= nullptr){
            postOrdered(t->left);
            postOrdered(t->right);
            cout<<t->x<<" ";
        }
    }

    static void levelOrdered(treeNode *t){
        Queue<treeNode *> q;
        q.enQueue(t);
        while( ! q.isEmpty() ){
            t = q.deQueue();
            cout<<t->x<<" ";
            if(t->left != nullptr) q.enQueue(t->left);
            if(t->right != nullptr) q.enQueue(t->right);
        }
    }

    static void test(){
        Tree<int> t;
        preOrdered(t.root);cout<<endl;
        inOrdered(t.root); cout<<endl;
        postOrdered(t.root); cout<<endl;
        levelOrdered(t.root); cout<<endl<<endl;
        cout<<"Number of Nodes: "<<t.count()<<endl;
        cout<<"Height of Tree: "<<t.height()<<endl;
    }
};

template<typename T>
class BST {
    struct treeNode{
        treeNode *left;
        T x;
        treeNode *right;
    };
    treeNode *root;

    int count(treeNode *p){
        int c = 0;
        Queue<treeNode *> q;
        q.enQueue(p);
        while( ! q.isEmpty() ){
            treeNode *t = q.deQueue();
            c++;
            if(t->left != nullptr) q.enQueue(t->left);
            if(t->right != nullptr) q.enQueue(t->right);
        }
        return c;
    }

    int height(treeNode *p){
        int n = count(p);
        Queue<treeNode *> q;
        q.enQueue(p);
        while( ! q.isEmpty() ){
            treeNode *t = q.deQueue();
            if(t->left != nullptr) q.enQueue(t->left);
            else n++;
            if(t->right != nullptr) q.enQueue(t->right);
            else n++;
        }
        return (int) log2(n);
    }

public:

    BST(){
        root = nullptr;
    }

    treeNode * getROOT(){
        return root;
    }

    bool search(T x){
        treeNode *t = root;
        Queue<treeNode *> q;
        q.enQueue(root);
        while(t != nullptr){
            if(t->x < x) q.enQueue(t->right);
            else if(t->x > x) q.enQueue(t->left);
            else return true;
            t = q.deQueue();
        }
        return false;
    }

    void insert(T x){
        auto * n = new treeNode;
        n->left = nullptr;
        n->x = x;
        n->right = nullptr;
        if(root == nullptr) root = n;
        else if(!search(x)){
            treeNode *t = root;
            Queue<treeNode *> q;
            q.enQueue(root);
            while(t != nullptr){
                if(t->x < x && t->right != nullptr){
                    q.enQueue(t->right);
                }
                else if(t->x > x && t->left != nullptr){
                    q.enQueue(t->left);
                }
                else{
                    if(t->x < x) t->right = n;
                    else t->left = n;
                    return;
                }
                t = q.deQueue();
            }
        }
    }

    T deleteLeaf(T x){
        if(search(x)){
            treeNode *t = root, *p = nullptr;
            Queue<treeNode *> q;
            q.enQueue(root);
            while(t != nullptr){
                T r = t->x;
                if(t->x == x){
                    treeNode *n;
                    if(t->left != nullptr && t->right != nullptr){
                        if(height(t->left) > height(t->right)) {
                            n = t->left;
                            while(n->right != nullptr){
                                n = n->right;
                            }
                            t->x = deleteLeaf(n->x);
                        }
                        else{
                            n = t->right;
                            while(n->left != nullptr){
                                n = n->left;
                            }
                            t->x = deleteLeaf(n->x);
                        }
                    }
                    else if(t->left != nullptr){
                        n = t->left;
                        while(n->right != nullptr){
                            n = n->right;
                        }
                        t->x = deleteLeaf(n->x);
                    }
                    else if(t->right != nullptr){
                        n = t->right;
                        while(n->left != nullptr){
                            n = n->left;
                        }
                        t->x = deleteLeaf(n->x);
                    }
                    else{
                        if(p->left == t){
                            p->left = nullptr;
                        }
                        else{
                            p->right = nullptr;
                        }
                        delete t;
                    }
                    return r;
                }
                else if(t->x < x)
                    q.enQueue(t->right);
                else if(t->x > x)
                    q.enQueue(t->left);
                p = t;
                t = q.deQueue();
            }
        }
        return NULL;
    }

    void createBST(T io[], unsigned int n) {
        for(int i=0; i<n; i++)
            insert(io[i]);
    }

    static void preOrdered(treeNode *t){
        if(t!= nullptr){
            cout<<t->x<<" ";
            preOrdered(t->left);
            preOrdered(t->right);
        }
    }

    static void inOrdered(treeNode *t){
        if(t!= nullptr){
            inOrdered(t->left);
            cout<<t->x<<" ";
            inOrdered(t->right);
        }
    }

    static void postOrdered(treeNode *t){
        if(t!= nullptr){
            postOrdered(t->left);
            postOrdered(t->right);
            cout<<t->x<<" ";
        }
    }

    static void levelOrdered(treeNode *t){
        Queue<treeNode *> q;
        q.enQueue(t);
        while( ! q.isEmpty() ){
            t = q.deQueue();
            cout<<t->x<<" ";
            if(t->left != nullptr) q.enQueue(t->left);
            if(t->right != nullptr) q.enQueue(t->right);
        }
    }

    static void test(){
        BST<int> b;
        int x;
        int a[] = {6,2,1,3,5,4,9,7,8,10};
        b.createBST(a, sizeof a / sizeof(int));
        inOrdered(b.root); cout<<endl;
        cin>>x;
        cout<<b.deleteLeaf(x)<<endl;
        inOrdered(b.root); cout<<endl;
    }
};

template<typename T>
class AVL {
    struct treeNode{
        treeNode *left;
        T x;
        treeNode *right;
    };
    treeNode *root;

    static int count(treeNode *p){
        int c = 0;
        Queue<treeNode *> q;
        q.enQueue(p);
        while(!q.isEmpty()){
            treeNode *t = q.deQueue();
            if(t!= nullptr){
                c++;
                if(t->left != nullptr) q.enQueue(t->left);
                if(t->right != nullptr) q.enQueue(t->right);
            }
        }
        return c;
    }

    static int height(treeNode *p){
        int n = count(p);
        Queue<treeNode *> q;
        q.enQueue(p);
        while(!q.isEmpty()){
            treeNode *t = q.deQueue();
            if(t != nullptr){
                if(t->left != nullptr) q.enQueue(t->left);
                else n++;
                if(t->right != nullptr) q.enQueue(t->right);
                else n++;
            }
        }
        return (int) log2(n);
    }

    static int balanceFactor(treeNode *p){
        if(p->left != nullptr && p->right != nullptr) return abs(height(p->left) - height(p->right));
        else if(p->left != nullptr) return height(p->left);
        else if(p->right != nullptr) return height(p->right);
        else return 0;
    }

    static treeNode * rLL(treeNode *p){
        treeNode *t = p->left;
        p->left = t->right;
        t->right = p;
        p = t;
        return p;
    }

    static treeNode * rRR(treeNode *p){
        treeNode *t = p->right;
        p->right = t->left;
        t->left = p;
        p = t;
        return p;
    }

    static treeNode * rLR(treeNode *p){
        treeNode *t = p->left;
        treeNode *q = t->right;
        //simply rRR(t);
        t->right = q->left;
        q->left = t;
        t = q;
        //simply rLL(p);
        p->left = t->right;
        t->right = p;
        p = t;
        return p;
    }

    static treeNode * rRL(treeNode *p){
        treeNode *t = p->right;
        treeNode *q = t->left;
        //simply rLL(t);
        t->left = q->right;
        q->right = t;
        t = q;
        //simply rRR(p);
        p->right = t->left;
        t->left = p;
        p = t;
        return p;
    }

    static treeNode * rotate(treeNode *t){
        if(t!= nullptr){
            if(balanceFactor(t)>1){
                if(t->left != nullptr || t->right != nullptr){
                    int le=0, ll=0, lr=0, ri=0, rl=0, rr=0, bf=0;
                    if(t->left != nullptr){
                        le = height(t->left);
                        if(t->left->left != nullptr) ll = height(t->left->left);
                        if(t->left->right != nullptr) lr = height(t->left->right);
                    }
                    if(t->right != nullptr){
                        ri = height(t->right);
                        if(t->right->left != nullptr) rl = height(t->right->left);
                        if(t->right->right != nullptr) rr = height(t->right->right);
                    }
                    if(le>ri){
                        if(ll>lr) t = rLL(t);
                        else if(t->left->right!=nullptr) t = rLR(t);
                    }
                    else if(t->right!=nullptr){
                        if(rl>rr) t = rRL(t);
                        else if(t->right->right!=nullptr) t = rRR(t);
                    }
                }
            }
            t->left = rotate(t->left);
            t->right = rotate(t->right);
            return t;
        }
    }

public:

    AVL(){
        root = nullptr;
    }

    treeNode * getROOT(){
        return root;
    }

    bool search(T x){
        treeNode *t = root;
        Queue<treeNode *> q;
        q.enQueue(root);
        while(t != nullptr){
            if(t->x < x) q.enQueue(t->right);
            else if(t->x > x) q.enQueue(t->left);
            else return true;
            t = q.deQueue();
        }
        return false;
    }

    void insert(T x){
        auto * n = new treeNode;
        n->left = nullptr;
        n->x = x;
        n->right = nullptr;
        if(root == nullptr) root = n;
        else if(!search(x)){
            treeNode *t = root;
            Queue<treeNode *> q;
            q.enQueue(root);
            while(t != nullptr){
                if(t->x < x && t->right != nullptr){
                    q.enQueue(t->right);
                }
                else if(t->x > x && t->left != nullptr){
                    q.enQueue(t->left);
                }
                else{
                    if(t->x < x) t->right = n;
                    else t->left = n;
                    root = rotate(root);
                    return;
                }
                t = q.deQueue();
            }
        }
    }

    void createAVL(T io[], int n) {
        for(int i=0; i<n; i++)
            insert(io[i]);
    }

    T deleteLeaf(T x){
        if(search(x)){
            treeNode *t = root, *p = nullptr;
            Queue<treeNode *> q;
            q.enQueue(root);
            while(t != nullptr){
                T r = t->x;
                if(t->x == x){
                    treeNode *n;
                    if(t->left != nullptr && t->right != nullptr){
                        if(height(t->left) > height(t->right)) {
                            n = t->left;
                            while(n->right != nullptr){
                                n = n->right;
                            }
                            t->x = deleteLeaf(n->x);
                        }
                        else{
                            n = t->right;
                            while(n->left != nullptr){
                                n = n->left;
                            }
                            t->x = deleteLeaf(n->x);
                        }
                    }
                    else if(t->left != nullptr){
                        n = t->left;
                        while(n->right != nullptr){
                            n = n->right;
                        }
                        t->x = deleteLeaf(n->x);
                    }
                    else if(t->right != nullptr){
                        n = t->right;
                        while(n->left != nullptr){
                            n = n->left;
                        }
                        t->x = deleteLeaf(n->x);
                    }
                    else{
                        if(p->left == t){
                            p->left = nullptr;
                        }
                        else{
                            p->right = nullptr;
                        }
                        delete t;
                        t = nullptr;
                    }
                    root = rotate(root);
                    return r;
                }
                else if(t->x < x)
                    q.enQueue(t->right);
                else if(t->x > x)
                    q.enQueue(t->left);
                p = t;
                t = q.deQueue();
            }
        }
        return NULL;
    }

    static void preOrdered(treeNode *t){
        if(t!= nullptr){
            cout<<t->x<<" ";
            preOrdered(t->left);
            preOrdered(t->right);
        }
    }

    static void inOrdered(treeNode *t){
        if(t!= nullptr){
            inOrdered(t->left);
            cout<<t->x<<" ";
            inOrdered(t->right);
        }
    }

    static void postOrdered(treeNode *t){
        if(t!= nullptr){
            postOrdered(t->left);
            postOrdered(t->right);
            cout<<t->x<<" ";
        }
    }

    static void levelOrdered(treeNode *t){
        Queue<treeNode *> q;
        q.enQueue(t);
        while( ! q.isEmpty() ){
            t = q.deQueue();
            cout<<t->x<<" ";
            if(t->left != nullptr) q.enQueue(t->left);
            if(t->right != nullptr) q.enQueue(t->right);
        }
    }

    static void test(){
        AVL<int> a;
        int x;
        int arr[] = {112,24,35,48,15,186,720,11};
        a.createAVL( arr, sizeof(arr)/sizeof(int) );
        preOrdered(a.root); cout << endl;
        inOrdered(a.root); cout<<endl;
        cin>>x;
        cout << a.deleteLeaf(x) << endl;
        preOrdered(a.root); cout << endl;
        inOrdered(a.root); cout<<endl;
        cin>>x;
        cout << a.deleteLeaf(x) << endl;
        preOrdered(a.root); cout << endl;
        inOrdered(a.root); cout<<endl;
    }
};

#endif //DSA_TREE_H
