//
// Created by Oballium on 24-10-2021.
//

#ifndef DSA_SWAPNIBBLE_H
#define DSA_SWAPNIBBLE_H

class SwapNibble{
    static void algo(int a){
        int l = 0xff & (a<<4);
        int r = 0xff & (a>>4);
        cout<< (l|r) <<endl;
    }

public:
    static void Test(){
        int x;
        cin>>x;
        algo(x);
    }
};

#endif //DSA_SWAPNIBBLE_H
