//
// Created by Oballium on 24-10-2021.
//

#ifndef DSA_MAXIMUMPRODUCTSUBARRAY_H
#define DSA_MAXIMUMPRODUCTSUBARRAY_H

class MaximumProductSubarray{
    static void algo(int a[], int n){
        int max = INT32_MIN;
        for(int i=0; i<n; i++){
            if(a[i] >= 0){
                max = 0;
                break;
            }
        }
        int l=0;
        int r=1;
        for(int i=0; i<n; i++){
            if(a[i]!=0){
                r*=a[i];
                if(i == n-1){
                    for(int j = i; j>=l; j--){
                        if(max<r){
                            max = r;
                        }
                        r/=a[j];
                    }
                }
            }
            else{
                for(int j = (i-1); j>=l; j--){
                    if(max<r){
                        max = r;
                    }
                    r/=a[j];
                }
                r=1;
                l = i+1;
            }
        }
        cout<<max<<endl;
    }

public:
    static void Test(){
        int b[] = {2,3,-2,4};//{-2,0,-1};//{6,-3,-10,0,2};

        algo(b, sizeof(b)/sizeof(int) );
    }
};

#endif //DSA_MAXIMUMPRODUCTSUBARRAY_H
