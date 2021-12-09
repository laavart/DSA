//
// Created by Oballium on 24-11-2021.
//

#ifndef DSA_LONGESTPALINDROMESUBSTRING_H
#define DSA_LONGESTPALINDROMESUBSTRING_H

class LongestPalindromeSubstring{

    static string algo(string s){ //Manacher's Algorithm
        int l = s.length();
        for(int i = l; i>1; i--){
            for(int j=0; j+i<=l; j++){
                string b = s.substr(j,i);
                int bl = b.length();
                int f=0, r =  bl-1, check = 0;
                while(f<=r){
                    if(b[f] == b[r] || b[f] == b[r]-32 || b[f] == b[r]+32){
                        check++;
                    }
                    else
                        break;
                    f++, r--;
                }
                if(check == (bl+1)/2)
                    return b;
            }
        }
        cout<<"NONE..."<<endl;
        return "";
    }

public:

    static void test(){
        string s;
        cin>>s;
        cout<<algo(s)<<endl;
    }

};

#endif //DSA_LONGESTPALINDROMESUBSTRING_H
