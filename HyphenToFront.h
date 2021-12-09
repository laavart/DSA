//
// Created by Oballium on 24-11-2021.
//

#ifndef DSA_HYPHENTOFRONT_H
#define DSA_HYPHENTOFRONT_H

class HyphenToFront{

    static string algo(string s){

        int l = s.length();
        string n = "";
        for(int i=0; i<l; i++){
            if(s[i] == '-')
                n = '-' + n;
            else
                n += s[i];
        }

        return n;
    }

public:

    static void test(){

        string s;
        cin>>s;
        cout<<algo(s)<<endl;

    }

};

#endif //DSA_HYPHENTOFRONT_H
