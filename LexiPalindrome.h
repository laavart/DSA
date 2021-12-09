//
// Created by Oballium on 24-11-2021.
//

#ifndef DSA_LEXIPALINDROME_H
#define DSA_LEXIPALINDROME_H

class LexiPalindrome{

    static string algo(string s){

        int a[26];
        for(int i=0; i < sizeof(a)/sizeof(int); i++)
            a[i] = 0;

        for(char x: s){
            x = x>=97 && x<=122 ? x-97 : x-65;
            a[x]++;
        }

        string l = "", r = "", e = "";
        for(int i=0; i<26; i++){
            while(a[i]-2 >= 0){
                l += (char) (i+97);
                r = (char) (i+97) + r;
                a[i]-=2;
            }
            if(a[i] == 1){
                if(e == "")
                    e = (char) (i+97);
                else{
                    cout<<"LexiPalindrome NOT Possible."<<endl;
                    return "";
                }
            }
        }

        return l+e+r;
    }

public:

    static void test(){

        string s;
        cin>>s;
        cout<<algo(s)<<endl;

    }

};

#endif //DSA_LEXIPALINDROME_H
