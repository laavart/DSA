//
// Created by Oballium on 23-11-2021.
//

#ifndef DSA_MAXEQUILIBRIUMSUM_H
#define DSA_MAXEQUILIBRIUMSUM_H

class MaxEquilibriumSum{

    static int algo(int a[], int l){
        int sum = 0;

        for(int i=0; i<l; i++){
            sum += a[i];
        }

        int c = 0, max = INT32_MIN;
        for(int i = l-1; i>=0; i--){
            c += a[i];
            if( c == sum-c+a[i] && max<sum ){
                max = c;
            }
        }

        return max;
    }

public:

    static void test(){

        int a[] = {-2,5,3,1,2,6,-4,2};
        cout<<algo(a, sizeof(a)/ sizeof(int) )<<endl;

    }
};

#endif //DSA_MAXEQUILIBRIUMSUM_H
