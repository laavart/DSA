//
// Created by Oballium on 15-10-2021.
//

#ifndef DSA_STROBOGRAMMATIC_H
#define DSA_STROBOGRAMMATIC_H

#include <iostream>

class Strobogrammatic{
    static bool isStrobogrammatic(int n){
        string s = to_string(n);
        int l = s.length();
        int c = 0;
        for(int i=0; i<=(l-1)/2; i++){
            if(s[i] == '0' || s[i] == '1' || s[i] == '6' || s[i] == '8' || s[i] == '9'){
                if(s[i] == s[l-i-1] && s[i] != '6' && s[i] != '9'){
                    c++;
                }
                else if(s[i] == '6' && s[l-i-1] == '9'){
                    c++;
                }
                else if(s[i] == '9' && s[l-i-1] == '6'){
                    c++;
                }
            }
        }
        return c == (l-1)/2+1;
    }

    static void strobogrammaticUpto(int n){
        int i=1;
        while(i<=n){
            if(isStrobogrammatic(i)){
                cout<<i<<endl;
            }
            i++;
        }
    }

public:
    static void Test(){
        cout<<(isStrobogrammatic(16891)?"Yes":"No")<<endl;
        strobogrammaticUpto(100);
    }
};

#endif //DSA_STROBOGRAMMATIC_H
