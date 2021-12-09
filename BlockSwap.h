//
// Created by Oballium on 24-10-2021.
//

#ifndef DSA_BLOCKSWAP_H
#define DSA_BLOCKSWAP_H

class BlockSwap{
    static void swap(int &a, int &b){
        a = a^b;
        b = a^b;
        a = a^b;
    }

    static void anyhow(int a[], int n, int k){
        if(k<n){
            int b[k];
            for(int i=0; i<k; i++){
                b[i] = a[i];
            }
            for(int i=k; i<n; i++){
                swap(a[i], a[i-k]);
            }
            for(int i = (n-k); i<n; i++){
                a[i] = b[i - (n-k)];
            }
            for(int i=0; i<n; i++){
                cout<<a[i]<<endl;
            }
        }
        else{
            cout<<"Nice Joke!!!"<<endl;
        }
    }

public:
    static void Test(){
        int a[] = {1,2,3,4,5,6,7,8};

        anyhow(a, sizeof(a)/ sizeof(int) , 8);
    }
};

#endif //DSA_BLOCKSWAP_H
