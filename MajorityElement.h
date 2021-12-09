//
// Created by Oballium on 24-11-2021.
//

#ifndef DSA_MAJORITYELEMENT_H
#define DSA_MAJORITYELEMENT_H

class MajorityElement{

    static void algo(vector<int> a){
        for(auto x: a){

            int c = 0;
            for(auto y: a){

                if(x == y)
                    c++;

            }

            if(c == a.size()/2+1){
                cout<<x<<" is the Majority Element."<<endl;
                return;
            }
        }

        cout<<"NO Majority Element Found."<<endl;
    }

public:

    static void test(){

        vector<int> a = {4,4,4,5,6,8,4,4};
        algo(a);

    }
};

#endif //DSA_MAJORITYELEMENT_H
