//
// Created by Oballium on 24-10-2021.
//

#ifndef DSA_HOURGLASS_H
#define DSA_HOURGLASS_H

class Hourglass{
    static void hourGlass(int m, int n, vector<vector<int>> &v){
        m-=(3-1);
        n-=(3-1);

        int max = 0;
        for(int k=0; k < (m*n); k++){

            int c=0;

            for(int i=0; i<3; i++){

                for(int j=0; j<3; j++){

                    if(i!=1 || j==1){

                        int x = i + (k/3);
                        int y = j + k - (k/3)*3;

                        c+=v[x][y];
                    }
                }
            }

            if(max < c){

                max = c;
            }
        }

        cout<<max<<endl;
    }

public:

    static void Test(){
        vector<vector<int>> v = {{1,2,4,5,6}, {7,5,2,3,6}, {0,0,0,0,0}, {7,5,1,3,5}, {0,0,0,0,0}};
        hourGlass(5, 5, v);
    }

};

#endif //DSA_HOURGLASS_H
