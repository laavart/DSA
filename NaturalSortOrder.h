//
// Created by Oballium on 24-11-2021.
//

#ifndef DSA_NATURALSORTORDER_H
#define DSA_NATURALSORTORDER_H

class NaturalSortOrder{

    static void algo(vector<string> a){

        int l = a.size();
        string s[l];
        int n[l];

        for(int i=0; i<l; i++){
            for(int j=0; j<sizeof(a.at(i))/sizeof(int); j++){
                if(a.at(i)[j]>=48 && a.at(i)[j]<=57){
                    n[i] = j;
                    break;
                }
            }
        }

        for(int i=0; i<l; i++){
            s[i] = a.at(i).substr(0,n[i]);
            n[i] = stoi(a.at(i).substr(n[i]));
        }

        for(int i=0; i<l; i++){

            int m = i;
            for(int j=i; j<l; j++){
                int b = s[m].compare(s[j]);
                if(b>0)
                    m = j;
                else if(b==0 && n[m]>n[j])
                    m = j;
            }

            if(m != i){

                string t = s[i];
                s[i] = s[m];
                s[m] = t;

                n[m] = n[m]^n[i];
                n[i] = n[m]^n[i];
                n[m] = n[m]^n[i];

            }

        }

        for(int i=0; i<l; i++){
            cout<<s[i]<<n[i]<<endl;
        }

    }

public:

    static void test(){

        vector<string> a = {"z11","a31","a2","l6","n9","y10","l11"};
        algo(a);

    }

};

#endif //DSA_NATURALSORTORDER_H
