//
// Created by Oballium on 15-10-2021.
//

#ifndef DSA_CHINEESEREMAINDERTHEOREM_H
#define DSA_CHINEESEREMAINDERTHEOREM_H

class CRT{
    static bool check(int a[], int b[], int n, int r, int i){
        if(i == n){
            return true;
        }
        if((r-b[i])%a[i] == 0){
           return check(a, b, n, r, i+1);
        }
        else return false;
    }

    static int find(int a[], int b[], int n){
        int i=1;
        while(true){
            int r = a[0]*i + b[0];
            if(check(a, b, n, r, 1)){
                return r;
            }
            i++;
        }
    }

public:
    static void Test(){
        int a[] = {5,7};
        int b[] = {1,3};
        cout<<find(a, b, 2)<<endl;
        int c[] = {3,4,5};
        int d[] = {2,3,1};
        cout<<find(c, d, 3)<<endl;
    }
};

#endif //DSA_CHINEESEREMAINDERTHEOREM_H
