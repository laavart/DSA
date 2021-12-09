//
// Created by Oballium on 08-10-2021.
//

#ifndef DSA_POLYNOMIAL_H
#define DSA_POLYNOMIAL_H

#include <iostream>
#include <cmath>
using namespace std;

struct Term{
    int e,c;
};

class Polynomial{
public:
    int n;
    struct Term *t;

    Polynomial(){
        cout<<"Enter the Degree of Polynomial:"<<endl;
        cin>>n;
        cout<<endl;

        t = new Term[n];
        cout<<"ENTER IN ORDER OF POWER MAX TO MIN!!!"<<endl;
        for(int i=0; i<n; i++){
            cout<<"Enter Exponent Value:"<<endl;
            cin>>t[i].e;
            cout<<"Enter Related Coefficient Value:"<<endl;
            cin>>t[i].c;
        }
        cout<<endl;
    }

    Polynomial(int n){
        this->n = n;
        cout<<endl;

        t = new Term[n];
        cout<<"ENTER IN ORDER OF POWER MAX TO MIN!!!"<<endl;
        for(int i=0; i<n; i++){
            cout<<"Enter Exponent Value:"<<endl;
            cin>>t[i].e;
            cout<<"Enter Related Coefficient Value:"<<endl;
            cin>>t[i].c;
        }
        cout<<endl;
    }

    Polynomial(int n, Term *t){
        this->n = n;

        this->t = new Term[n];
        for(int i=0; i<n; i++){
            this->t[i].e = t[i].e;
            this->t[i].c = t[i].c;
            cout<<this->t[i].e<<"="<<t[i].e<<" "<<this->t[i].c<<"="<<t[i].c<<endl;
        }
    }

    void evaluate(int x){
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += t[i].c * ( (int) pow(x, t[i].e) );
            cout<<" "<<sum<<" ";
        }
        cout<<"Value of Polynomial :"<<sum<<endl;
    }

    static Polynomial add(Polynomial p1, Polynomial p2){
        Term null[0];
        Polynomial p(max(p1.n,p2.n), null);

        int i=0, j=0, k=0;
        while(i<p1.n && j<p2.n){

            if(p1.t[i].e == p2.t[j].e){
                p.t[k].e = p1.t[i].e;
                p.t[k++].c = p1.t[i++].c + p2.t[j++].c;
            }
            else if(p1.t[i].e > p2.t[j].e){
                p.t[k++] = p1.t[i++];
            }
            else if(p1.t[i].e < p2.t[j].e){
                p.t[k++] = p2.t[j++];
            }

        }

        while(i<p1.n){
            p.t[k++] = p1.t[i++];
        }

        while(j<p2.n){
            p.t[k++] = p2.t[j++];
        }

        return p;
    }
};

#endif //DSA_POLYNOMIAL_H
