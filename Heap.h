//
// Created by Oballium on 25-11-2021.
//

#ifndef DSA_HEAP_H
#define DSA_HEAP_H

#include <vector>

template <typename T>
class Heap{
    vector<T> v;
    int size;

public:

    Heap(){
        size = 0;
    }

    void insert(T n){
        v.push_back(n);
        size++;
        int i = size-1, j = (i-1)/2;
        while(v.at(i) > v.at(j) && i>0){
            v.at(i) = v.at(j);
            v.at(j) = n;
            i = j, j = (i-1)/2;
        }
    }

    void create(T a[], int l){
        for(int i=0; i<l; i++){
            insert(a[i]);
        }
    }

    T deleteFromHeap(){
        T x = v.at(0);
        v.at(0) = v.at(size-1);
        v.erase(v.end()-1);
        size--;
        int i = 0, j = 2*(i+1);
        while(j-1 < size){
            if(j<size){
                if( v.at(j) > v.at(j-1) ){
                    if( v.at(j) > v.at(i) ){
                        swap(v.at(j),v.at(i));
                        i = j, j = 2*(i+1);
                    }
                    else break;
                }
                else{
                    if( v.at(j-1) > v.at(i) ){
                        swap(v.at(j-1),v.at(i));
                        i = j-1, j = 2*(i+1);
                    }
                    else break;
                }
            }
            else{
                if( v.at(j-1) > v.at(i) ){
                    swap(v.at(j-1),v.at(i));
                    i = j-1, j = 2*(i+1);
                }
                else break;
            }
        }
        return x;
    }

    void show(){
        cout<<"Heap:"<<endl;
        for(auto x: v)
            cout<<" "<<x;
        cout<<endl;
    }

    static T * heapify(T *a, int l){
        int i = l-1;
        while(i >= 0){
            int k = i;
            int j = 2*(i+1);
            while(j-1 < l){
                if(j<l){
                    if( a[j] > a[j-1] ){
                        if( a[j] > a[i] ){
                            swap(a[j],a[i]);
                            i = j, j = 2*(i+1);
                        }
                        else break;
                    }
                    else{
                        if( a[j-1] > a[i] ){
                            swap(a[j-1],a[i]);
                            i = j-1, j = 2*(i+1);
                        }
                        else break;
                    }
                }
                else{
                    if( a[j-1] > a[i] ){
                        swap(a[j-1],a[i]);
                        i = j-1, j = 2*(i+1);
                    }
                    else break;
                }
            }
            i = --k;
        }
        return a;
    }

    static void test(){
        Heap<T> h;
        int a[] = {11,123,36,54,51,63,77};
        h.create(a, sizeof(a)/sizeof(int));
        h.show();
        h.insert(8);
        h.show();
        cout<<endl<<h.deleteFromHeap()<<endl<<endl;
        h.show();
        cout<<endl;
        int *b = heapify(a,7);
        cout<<"Heapify:"<<endl;
        for(int i=0; i<7; i++)
            cout<<" "<<b[i];
    }
};

#endif //DSA_HEAP_H
