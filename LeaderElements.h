//
// Created by Oballium on 23-11-2021.
//

#ifndef DSA_LEADERELEMENTS_H
#define DSA_LEADERELEMENTS_H

class LeaderElements{

    static void algo(vector<int> a){

        int max = INT32_MIN;
        for(auto x = a.rbegin(); x != a.rend(); x++)
            if(max < *x){
                max = *x;
                cout<<*x<<endl;
            }

    }

public:

    static void test(){

        vector<int> a = {16,17,4,3,5,2};//{7,6,4,5,0,1};
        algo(a);

    }
};

#endif //DSA_LEADERELEMENTS_H
