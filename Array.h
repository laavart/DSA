//
// Created by Oballium on 15-09-2021.
//
#include <iostream>

using namespace std;

#ifndef DSA_ARRAY_H
#define DSA_ARRAY_H

class Array{
    int aElements[20];
    int aSize;
    int aLength;
    static void swap(int &x, int &y){
        int temp = x;
        x = y;
        y = temp;
    }
public:
    Array(int Elements[] = {}, int Size = 0, int Length = 0){
        aSize = Size;
        aLength = Length;
        while(Length-1>=0){
            aElements[Length - 1] = Elements[Length - 1];
            Length--;
        }
    }

    void display(){
        cout<<"aElements are as follows:";
        for(int i=0; i < aLength; i++){
            cout << " " << aElements[i];
        }
        cout << endl << "With a Size of " << aSize << " containing " << aLength << " elements" << endl<<endl;
    }

    void append(int Element){
        if(aLength < aSize){
            cout<< Element <<" is been added at tail"<<endl<<endl;
            aElements[aLength] = Element;
            aLength++;
        }
        else{
            cout<<"Insufficient space..."<<endl<<endl;
        }
    }


    void insert(int Index, int Element){
        if(aLength < aSize){
            cout<< Element <<" is been added at index "<<Index<<endl<<endl;
            for(int i = aLength-1; i>=Index; i--){
                aElements[i+1] = aElements[i];
            }
            aElements[Index] = Element;
            aLength++;
        }
        else{
            cout<<"Insufficient space..."<<endl<<endl;
        }
    }

    void drop(int Index){
        if(Index < aLength){
            cout<<"Index "<< Index <<" is been deleted"<<endl<<endl;
            while(Index<aLength){
                aElements[Index] = aElements[Index+1];
                Index++;
            }
            aLength--;
        }
        else{
            cout<<"Incorrect Index..."<<endl<<endl;
        }
    }

    bool lSearch(int Element){
        for(int i=0; i<aLength; i++){
            if(aElements[i] == Element){
                return true;
            }
        }
        return false;
    }

    bool lSearch_aTransposition(int Element){
        for(int i=0; i<aLength; i++){
            if(aElements[i] == Element){
                swap(aElements[i-1], aElements[i]);
                return true;
            }
        }
        return false;
    }

    bool lSearch_aMoveToHead(int Element){
        for(int i=0; i<aLength; i++){
            if(aElements[i] == Element){
                swap(aElements[0], aElements[i]);
                return true;
            }
        }
        return false;
    }

    bool bSearch(int Element){
        int min=0, max=aLength-1;
        int mid = (min+max)/2;
        int i=0;
        while(i<=aLength){
            if(aElements[mid] == Element)
                return true;
            else if(aElements[mid] < Element)
                min = mid;
            else
                max = mid;
            mid = (min+max+1)/2;
            i++;
        }
        return false;
    }

    bool bSearch_Recursive(int min, int max,int Element){
        if(min<=max){
            int mid = (min +max)/2;
            if(aElements[mid] == Element)
                return true;
            else if(aElements[mid] < Element)
                return bSearch_Recursive(mid+1, max, Element);
            else
                return bSearch_Recursive(min, mid-1, Element);
        }
    }

    int getElementAt(int Index){
        if(Index<aLength){
            return aElements[Index];
        }
        else{
            cout<<"Incorrect Index..."<<endl<<endl;
        }
    }

    void setElementAt(int Index, int Element){
        if(Index>=0 && Index<20){
            cout<< Element <<" is set to Index "<< Index <<endl<<endl;
            if(Index<aLength){
                aElements[Index] = Element;
            }
            else if(Index==aLength){
                aElements[Index] = Element;
                aLength++;
            }
            else{
                int i=aLength;
                aLength+=(Index-aLength+1);
                while(i<=Index){
                    if(i!=Index){
                        aElements[i] = 0;
                    }
                    else{
                        aElements[i] = Element;
                    }
                    i++;
                }
            }
        }
        else{
            cout<<"Incorrect Index..."<<endl<<endl;
        }
    }

    int maxElement(){
        int max = 0;
        for(int i=0; i<aLength; i++){
            if(aElements[i]>aElements[max])
                max = i;
        }
        return aElements[max];
    }

    int minElement(){
        int min = 0;
        for(int i=0; i<aLength; i++){
            if(aElements[i]<aElements[min])
                min = i;
        }
        return aElements[min];
    }

    void reverse(){
        int i=0;
        while(i <= ((aLength-1)/2)){
            swap(aElements[i],aElements[aLength-i-1]);
            i++;
        }
        cout<<"Array has been reversed"<<endl<<endl;
    }

    void rotate(int Index){
        cout<<"Array has been rotated from index "<<Index<<endl<<endl;
        int i=0;
        while(i <= ((aLength-Index-1)/2)){
            swap(aElements[Index+i],aElements[aLength-i-1]);
            i++;
        }
    }

    void Test(){

        cout << endl;
        display();
        cout << "5 is" << (bSearch(5) == true ? "" : " NOT") << " present" << endl << endl;
        display();

        cout << endl;
        display();
        cout << "0 is" << (bSearch_Recursive(0, 4, 0) == true ? "" : " NOT") << " present" << endl << endl;
        display();

        cout << endl;
        display();
        append(6);
        display();

        cout << endl;
        display();
        cout << "2 is" << (bSearch(2) == true ? "" : " NOT") << " present" << endl << endl;
        display();

        cout << endl;
        display();
        insert(3, 7);
        display();

        cout << endl;
        display();
        drop(2);
        display();

        cout << endl;
        display();
        cout << "6 is" << (lSearch(6) == true ? "" : " NOT") << " present" << endl << endl;
        display();

        cout << endl;
        display();
        cout << "6 is" << (lSearch_aTransposition(6) == true ? "" : " NOT") << " present" << endl << endl;
        display();

        cout << endl;
        display();
        cout << "6 is" << (lSearch_aMoveToHead(6) == true ? "" : " NOT") << " present" << endl << endl;
        display();

        cout << endl;
        display();
        cout << "Element at Index 3 is " << getElementAt(3) << endl << endl;
        display();

        cout << endl;
        display();
        setElementAt(9, 15);
        display();

        cout << endl;
        display();
        cout << maxElement() << " is Largest element in the Array" << endl << endl;
        display();

        cout << endl;
        display();
        cout << minElement() << " is Smallest element in the Array" << endl << endl;
        display();

        cout << endl;
        display();
        reverse();
        display();

        cout << endl;
        display();
        rotate(5);
        display();
    }
};

#endif //DSA_ARRAY_H