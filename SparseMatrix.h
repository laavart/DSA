//
// Created by Oballium on 07-10-2021.
//
#include <iostream>
using namespace std;

#ifndef DSA_SPARSEMATRIX_H
#define DSA_SPARSEMATRIX_H

struct Element{
    int i,j,x;
};

class SparseMatrix{
public:
    int m=0, n=0, num=0;
    struct Element *e;

    SparseMatrix(){
        cout<<"Enter no. of Rows:"<<endl;
        cin>>m;
        cout<<"Enter no. of Columns:"<<endl;
        cin>>n;
        cout<<"Enter total no. of Elements:"<<endl;
        cin>>num;
        cout<<endl;

        if(num <= m*n){
            e = new Element[num];
            cout<<"Enter all Elements:"<<endl<<endl;
            for(int i=0; i<num; i++){
                cout<<"Row:"<<endl;
                cin>>e[i].i;
                cout<<"Column:"<<endl;
                cin>>e[i].j;
                cout<<"Element:"<<endl;
                cin>>e[i].x;
                cout<<endl;
            }
        }
    }

    SparseMatrix(int m, int n, int num){
        this->m = m;
        this->n = n;
        this->num = num;

        if(num <= m*n){
            e = new Element[num];
        }
    }

    SparseMatrix(int m, int n, int num, Element e[]){
        this->m = m;
        this->n = n;
        this->num = num;

        if(num <= m*n){
            e = new Element[num];
            for(int i=0; i<num; i++){
                this->e[i] = e[i];
            }
        }
    }

     void display() const{
        cout<<"Sparse Matrix :"<<endl;
        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                bool c = false;
                for(int k=0; k < num; k++){

                    if (i+1 == (e[k].i) && j+1 == (e[k].j)){
                        cout<<" "<<e[k].x;
                        c = true;
                        break;
                    }
                }
                if(!c){
                    cout<<" 0";
                }

            }
            cout<<endl;

        }
    }

    static void add(SparseMatrix s1, SparseMatrix s2){
        if(s1.m == s2.m || s1.n == s2.n){

            int num = s1.num + s2.num;
            SparseMatrix sum(s1.m, s2.n, num);

            int i=0,j=0,k=0;
            while(i<s1.num && j<s2.num){

                if(s1.e[i].i < s2.e[j].i){
                    sum.e[k++] = s1.e[i++];
                }
                else if(s1.e[i].i > s2.e[j].i){
                    sum.e[k++] = s2.e[j++];
                }
                else{

                    if(s1.e[i].j < s2.e[j].j){
                        sum.e[k++] = s1.e[i++];
                    }
                    else if(s1.e[i].j > s2.e[j].j){
                        sum.e[k++] = s2.e[j++];
                    }
                    else{
                        sum.e[k].i = s1.e[i].i;
                        sum.e[k].j = s2.e[j].j;
                        sum.e[k++].x = s1.e[i++].x + s2.e[j++].x;
                    }
                }
            }
            while(i<s1.num){
                sum.e[k++] = s1.e[i++];
            }
            while(j<s2.num){
                sum.e[k++] = s2.e[j++];
            }
            sum.display();
        }
        else{
            cout<<"Sparse Matrices cannot be Added!"<<endl;
        }
    }
};

#endif //DSA_SPARSEMATRIX_H
