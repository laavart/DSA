//
// Created by Oballium on 06-10-2021.
//

#ifndef DSA_MATRICES_H
#define DSA_MATRICES_H

class DiagonalMatrix{
    /*
         * 0 0 0 0
         0 * 0 0 0
         0 0 * 0 0
         0 0 0 * 0
         0 0 0 0 *
    */
    int *A;
    int n;

public:
    DiagonalMatrix(int Size){
        n = Size;
        A = new int[n];
    }

    ~DiagonalMatrix(){
        delete[] A;
    }

    void setElements(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    cout<<"Enter element for Index["<<(i+1)<<"]["<<(j+1)<<"]:";
                    cin>>A[i];
                }
                else{
                    cout<<"Element for Index["<<(i+1)<<"]["<<(j+1)<<"] is set to 0"<<endl;
                }
            }
        }
        cout<<endl;
    }

    int getElementAt(int i, int j){
        if(i==j)
            return A[i-1];
        else
            return 0;
    }

    void displayMatrix(){
        cout<<"Matrix:"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    cout<<" "<<A[i];
                }
                else{
                    cout<<" "<<0;
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

class LowerTriangularMatrix{
    /*
         * 0 0 0 0
         * * 0 0 0
         * * * 0 0
         * * * * 0
         * * * * *
    */
    int *A;
    int n;

public:
    LowerTriangularMatrix(int Size){
        n = Size;
        A = new int[(n*(n+1))/2];
    }

    ~LowerTriangularMatrix(){
        delete[] A;
    }

    void setElements(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i>=j){
                    cout<<"Enter element for Index["<<(i+1)<<"]["<<(j+1)<<"]:";
                    cin>>A[ (i*(i+1))/2 + j - 1 ];
                }
                else{
                    cout<<"Element for Index["<<(i+1)<<"]["<<(j+1)<<"] is set to 0"<<endl;
                }
            }
        }
        cout<<endl;
    }

    int getElementAt(int i, int j){
        i-=1; j-=1;
        if(i>=j)
            return A[ (i*(i+1))/2 + j - 1 ];
        else
            return 0;
    }

    void displayMatrix(){
        cout<<"Matrix:"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i>=j){
                    cout<<" "<<A[ (i*(i+1))/2 + j - 1 ];
                }
                else{
                    cout<<" "<<0;
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

class UpperTriangularMatrix{
    /*
         * * * * *
         0 * * * *
         0 0 * * *
         0 0 0 * *
         0 0 0 0 *
    */
    int *A;
    int n;

public:
    UpperTriangularMatrix(int Size){
        n = Size;
        A = new int[(n*(n+1))/2];
    }

    ~UpperTriangularMatrix(){
        delete[] A;
    }

    void setElements(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i<=j){
                    cout<<"Enter element for Index["<<(i+1)<<"]["<<(j+1)<<"]:";
                    cin>>A[ (n*(n-1))/2 + ((n-i)*(n-i+1))/2 + (n-j) - 1 ];
                }
                else{
                    cout<<"Element for Index["<<(i+1)<<"]["<<(j+1)<<"] is set to 0"<<endl;
                }
            }
        }
        cout<<endl;
    }

    int getElementAt(int i, int j){
        i-=1; j-=1;
        if(i<=j)
            return A[ (n*(n-1))/2 + ((n-i)*(n-i+1))/2 + (n-j) - 1 ];
        else
            return 0;
    }

    void displayMatrix(){
        cout<<"Matrix:"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i<=j){
                    cout<<" "<<A[ (n*(n-1))/2 + ((n-i)*(n-i+1))/2 + (n-j) - 1 ];
                }
                else{
                    cout<<" "<<0;
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

class SymmetricMatrix{
    /*
         2 7 8 9 *
         7 3 @ % #
         8 @ 4 / -
         9 % / 5 +
         * # - + 6
    */
    int *A;
    int n;

public:
    SymmetricMatrix(int Size){
        n = Size;
        A = new int[(n*(n+1))/2];
    }

    ~SymmetricMatrix(){
        delete[] A;
    }

    void setElements(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i>=j){
                    cout<<"Enter element for Index["<<(i+1)<<"]["<<(j+1)<<"]:";
                    cin>>A[ (i*(i+1))/2 + j - 1 ];
                }
                else{
                    cout<<"Element for Index["<<(i+1)<<"]["<<(j+1)<<"] is set to "<<A[ (j*(j+1))/2 + i - 1 ]<<endl;
                }
            }
        }
        cout<<endl;
    }

    int getElementAt(int i, int j){
        i-=1; j-=1;
        if(i>=j)
            return A[ (i*(i+1))/2 + j - 1 ];
        else
            return A[ (j*(j+1))/2 + i - 1 ];
    }

    void displayMatrix(){
        cout<<"Matrix:"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i>=j)
                    cout<<" "<<A[ (i*(i+1))/2 + j - 1 ];
                else
                    cout<<" "<<A[ (j*(j+1))/2 + i - 1 ];
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

class TriDiagonalMatrix{
    /*
         * * 0 0 0
         * * * 0 0
         0 * * * 0
         0 0 * * *
         0 0 0 * *
    */
    int *A;
    int n;

public:
    TriDiagonalMatrix(int Size){
        n = Size;
        A = new int[(3*n)-2];
    }

    ~TriDiagonalMatrix(){
        delete[] A;
    }

    void setElements(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if( i-j == -1 ){
                    cout<<"Enter element for Index["<<(i+1)<<"]["<<(j+1)<<"]:";
                    cin>>A[ i-1 ];
                }
                else if(i==j){
                    cout<<"Enter element for Index["<<(i+1)<<"]["<<(j+1)<<"]:";
                    cin>>A[ (n-1)+i-1 ];
                }
                else if( i-j == 1 ){
                    cout<<"Enter element for Index["<<(i+1)<<"]["<<(j+1)<<"]:";
                    cin>>A[ ((2*n)-1)+i-1 ];
                }
                else{
                    cout<<"Element for Index["<<(i+1)<<"]["<<(j+1)<<"] is set to 0"<<endl;
                }
            }
        }
        cout<<endl;
    }

    int getElementAt(int i, int j){
        if( i-j == -1 )
            return A[ i-1 ];
        else if(i==j)
            return A[ (n-1)+i-1 ];
        else if( i-j == 1 )
            return A[ ((2*n)-1)+i-1 ];
        else
            return 0;
    }

    void displayMatrix(){
        cout<<"Matrix:"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if( i-j == -1 )
                    cout<<" "<<A[ i-1 ];
                else if(i==j)
                    cout<<" "<<A[ (n-1)+i-1 ];
                else if( i-j == 1 )
                    cout<<" "<<A[ ((2*n)-1)+i-1 ];
                else
                    cout<<" "<<0;
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

class ToeplitzMatrix{
    int *A;
    int n;

public:
    ToeplitzMatrix(int Size){
        n = Size;
        A = new int[(2*n)-1];
        for(int i=0; i<((2*n)-1); i++){
            A[i] = 0;
        }
    }

    ~ToeplitzMatrix(){
        delete[] A;
    }

    void setElements(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if( A[ i-j+n-1 ] == 0 ){
                    cout<<"Enter element for Index["<<(i+1)<<"]["<<(j+1)<<"]:";
                    cin>>A[ i-j+n-1 ];
                }
                else{
                    cout<<"Element for Index["<<(i+1)<<"]["<<(j+1)<<"] is already set to "<<A[ i-j+n-1 ]<<endl;
                }
            }
        }
        cout<<endl;
    }

    int getElementAt(int i, int j){
        return A[ i-j+n-1 ];
    }

    void displayMatrix(){
        cout<<"Matrix:"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<" "<<A[ i-j+n-1 ];
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

#endif //DSA_MATRICES_H
