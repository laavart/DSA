//
// Created by Oballium on 15-10-2021.
//

#ifndef DSA_KARATSUBA_H
#define DSA_KARATSUBA_H

class Karatsuba{
    static int multiply(int M, int N){
        int ml = log10(M)+1;
        int nl = log10(N)+1;

        int m[ml], n[nl];

        for(int i=0; i<ml; i++){
            m[i] = M%10;
            M/=10;

            n[i] = N%10;
            N/=10;
        }

        int a = m[1]*n[1];
        int c = m[0]*n[0];
        int b = (m[1]+m[0])*(n[1]+n[0])-a-c;

        return a*100 + b*10 + c;
    }

public:
    static void Test(){
        int a, b;
        cin>>a>>b;
        cout<<multiply(a,b)<<endl;
    }
};

#endif //DSA_KARATSUBA_H
