//
// Created by Oballium on 15-10-2021.
//

#ifndef DSA_BINARYPALINDROME_H
#define DSA_BINARYPALINDROME_H

class BP{
    static string dToB(int n){
        string b = "";
        while(n>0){
            b = to_string(n%2) + b;
            n/=2;
        }
        return b;
    }

    static bool isBP(int n){
        string s = dToB(n);
        int l = s.length();
        int c=0;
        for(int i=0; i<=(l-1)/2; i++){
            if(s[i] == s[l-i-1]){
                c++;
            }
        }
        return c == (l-1)/2+1;
    }

    static void nBP(int n){
        for(int i=1; n>0; i++){
            if(isBP(i)){
                if(n==1){
                    cout<<i<<endl;
                }
                n--;
            }
        }
    }

public:
    static void Test(){
        cout<<(isBP(21)?"Yes":"No")<<endl;
        nBP(100);
    }
};

#endif //DSA_BINARYPALINDROME_H
