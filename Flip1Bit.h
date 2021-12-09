//
// Created by Oballium on 15-10-2021.
//

#ifndef DSA_FLIP1BIT_H
#define DSA_FLIP1BIT_H

class Flip1Bit{
    static int maxCount(string s){
        if(s[0] != '0'){
            s = "0"+s;
        }

        int l=0;
        for(int i=1; i<s.length()-1; i++){
            if(s[i] == '0'){
                l++;
            }
        }

        if(l != 0){
            int r[l+1], j=0, c=0;
            r[0] = 0;
            for(int i=1; i<s.length(); i++){
                if(s[i] == '0'){
                    r[j++] = c;
                    c = 0;
                }
                else if(s[i] == '1'){
                    c++;
                    if(i == s.length()-1){
                        r[j] = c;
                    }
                }
            }

            int max = 0;
            for(int i=0; i<l; i++){
                int t = r[i]+r[i+1];
                if(max<t){
                    max = t;
                }
            }

            return max+1;
        }
        else{
            return s.length();
        }
    }

public:
    static void Test(){
        cout<<maxCount("10110111011110011111")<<endl;
    }
};

#endif //DSA_FLIP1BIT_H
