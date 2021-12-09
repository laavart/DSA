//
// Created by Oballium on 27-09-2021.
//

#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

#ifndef DSA_SEIVEOFERATOSTHENES_H
#define DSA_SEIVEOFERATOSTHENES_H


class SeiveOfEratosthenes {

public:

    void simpleSeive(int n, vector<int> &v){

        bool a[n+1];

        for(int i=0; i<=n; i++){

            a[i] = true;
        }

        for(int i=2; i*i<=n; i++){

            for(int j=(i*i); j<=n; j+=i){

                if(a[j] == true){

                    a[j] = false;
                }
            }
        }

        for(int i=2; i<=n; i++){

            if(a[i] == true){

                v.push_back(i);
            }
        }

        for(int x: v){

            cout<<x<<endl;
        }
    }

    void segmentedSeive(int n, vector<int> &v){

        int r = sqrt(n);

        simpleSeive(r,v);

        int c = 1, low = (c*r)+1, high = (c*r)+r;

        while(low<=n){

            if(high>n){

                high = n;
            }

            bool a[(high-low)+1];

            for(int i=0; i<=(high-low); i++){

                a[i] = true;
            }

            for(int i: v){

                for(int j = i*i; j<=high; j+=i){

                    if(j>=low && j<=high){

                        int k = j-low;

                        if(a[k] == true){

                            a[k] = false;
                        }
                    }
                }
            }

            for(int i=0; i<=(high-low); i++){

                if(a[i] == true){

                    v.push_back(low+i);
                }
            }

            c+=1;
            low = (c*r)+1;
            high = (c*r)+r;
        }

        for(int x: v){

            cout<<x<<endl;
        }
    }

    void incrementalSeive( vector<int> &v){

        int r = 10;

        simpleSeive(r,v);

        int c = 1, low = (c*r)+1, high = (c*r)+r;

        while(c<100){

            bool a[(high-low)+1];

            for(int i=0; i<=(high-low); i++){

                a[i] = true;
            }

            for(int i: v){

                for(int j = i*i; j<=high; j+=i){

                    if(j>=low && j<=high){

                        int k = j-low;

                        if(a[k] == true){

                            a[k] = false;
                        }
                    }
                }
            }

            for(int i=0; i<=(high-low); i++){

                if(a[i] == true){

                    v.push_back(low+i);
                }
            }

            c+=1;
            low = (c*r)+1;
            high = (c*r)+r;
        }

        for(int x: v){

            cout<<x<<endl;
        }
    }

    void Test(){

        vector<int> v;

        cout<<"Prime Numbers using Simple Sieve:"<<endl;
        simpleSeive(100, v);
        cout<<endl;
        v.clear();

        cout<<"Prime Numbers using Segmented Sieve:"<<endl;
        segmentedSeive(100, v);
        cout<<endl;
        v.clear();

        cout<<"Prime Numbers using Incremental Sieve:"<<endl;
        incrementalSeive(v);
        cout<<endl;
        v.clear();

    }
};


#endif //DSA_SEIVEOFERATOSTHENES_H
