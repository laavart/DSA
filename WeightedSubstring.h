//
// Created by Oballium on 24-11-2021.
//

#ifndef DSA_WEIGHTEDSUBSTRING_H
#define DSA_WEIGHTEDSUBSTRING_H

class WeightedSubstring{

    static int algo(string s, string w, int n){
        int l = s.length();
        vector<string> v;

        int count = 0;
        for(int i=1; i<=l; i++){
            for(int j=0; j+i<=l; j++){
                string b = s.substr(j,i);
                bool check = true;
                for(auto x: v){
                    if(x == b){
                        check = false;
                        break;
                    }
                }
                if(check){
                    int sum = 0;
                    for(int k=0; k<i; k++){
                        sum += (b[k]>=97 && b[k]<=122) ? w[b[k]-97]-48 : w[b[k]-65]-48 ;
                    }
                    if(sum <= n){
                        v.push_back(b);
                        cout<<b<<endl;
                        count++;
                    }
                }
            }
        }
        return count;
    }

public:

    static void test(){

        string s,w;
        cin>>s>>w;
        int k;
        cin>>k;
        cout<<algo(s,w,k)<<endl;

    }

};

#endif //DSA_WEIGHTEDSUBSTRING_H
