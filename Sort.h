//
// Created by Oballium on 26-09-2021.
//

#include "Heap.h"
#include "Tree.h"

using namespace std;

#ifndef DSA_SORT_H
#define DSA_SORT_H

class Sorting{

    static void swap(int &a, int &b){

        a = a^b;
        b = a^b;
        a = a^b;
    }

    static void merge(int a[], int low, int key, int high){  //for merging in ascending order of elements in mergeSort sort

        int i=low, j=key+1, k= 0, r[high-low+1];

        while(i<=key && j<=high){

            if(a[i]<a[j]){

                r[k++] = a[i++];
            }
            else{

                r[k++] = a[j++];
            }
        }

        while(i<=key){

            r[k++] = a[i++];
        }

        while(j<=high){

            r[k++] = a[j++];
        }

        for(int n=low; n<=high; n++){

            a[n] = r[n-low];
        }
    }

public:

     static void bubbleSort(int a[], int n){
        for(int i=0; i<=n; i++){
            for(int j=0; j<=i; j++){
                if(a[i]<a[j]){
                    swap(a[i],a[j]);
                }
            }
        }

         cout<<"Sorted array by BubbleSort:"<<endl;

         for(int i=0; i<=n; i++){

             cout<<a[i]<<endl;
         }

         cout<<endl;
    }

    static void selectionSort(int a[], int n){

        for(int i=0; i<=n; i++){

            int min = i;

            for(int j=i; j<=n; j++){

                if(a[min]>a[j]){

                    min=j;
                }
            }

            if(min != i){

                swap(a[min],a[i]);
            }
        }

        cout<<"Sorted array by SelectionSort:"<<endl;

        for(int i=0; i<=n; i++){

            cout<<a[i]<<endl;
        }

        cout<<endl;
    }

    static void mergeSort(int a[], int n){

        int i=2;

        while(i<=n){

            for(int j=0; j+i-1<n; j+=i){

                int low = j, high = j+i-1, key = (low+high)/2;

                merge(a,low,key,high);
            }

            i*=2;
        }

        if(i/2<=n){

            merge(a,0,i/2-1,n);
        }

        cout<<"Sorted array by MergeSort:"<<endl;

        for(int x=0; x <= n; x++){

            cout << a[x] << endl;
        }

        cout<<endl;
    }

    static void quickSort(int a[], int l, int i, int j){
        if(i<j){
            int f = i+1, r = j-1;
            while(f<=r){
                if(a[f]>a[i] && a[r]<a[i])
                    swap(a[f++], a[r--]);
                else{
                    if(a[f]<a[i])
                        f++;
                    if(a[r]>a[i])
                        r--;
                }
            }
            if(a[i]>a[r]){
                swap(a[i], a[r]);
            }
            quickSort(a,l,i,r);
            quickSort(a,l,r+1,j);
        }
    }

    static void heapSort(int a[], int l){
        Heap<int> h;
        for(int i=0; i<l; i++){
            h.insert(a[i]);
        }
        for(int i = l-1; i>=0; i--){
            a[i] = h.deleteFromHeap();
        }
        cout<<"Sorted array by HeapSort:"<<endl;
        for(int i=0; i<l; i++)
            cout<<a[i]<<endl;
        cout<<endl;
    }

    static void insertionSort(int a[], int n){
        for(int i=1; i<=n; i++)
            for(int j=i-1; j>0; j--)
                if(a[j]<a[j-1])
                    swap(a[j],a[j-1]);
        cout<<"Sorted array by HeapSort:"<<endl;
        for(int i=0; i<n; i++)
            cout<<a[i]<<endl;
        cout<<endl;
    }

    static void treeSort(int a[], int n){
        BST<int> b;
        for(int i=0; i<n; i++)
            b.insert(a[i]);
        cout<<"Sorted array by TreeSort:"<<endl;
        BST<int>::inOrdered(b.getROOT());
        cout<<endl<<endl;
    }

    static void countSort(int a[], int n){
        int max = INT_MIN, min = INT_MAX;
        for(int i=0; i<n; i++){
            if(a[i]<min)
                min = a[i];
            if(a[i]>max)
                max = a[i];
        }
        int l = max-min+1, h[l];
        for(int i=0; i<l; i++)
            h[i] = 0;
        for(int i=0; i<n; i++)
            h[a[i]-min]++;
        int i=0, j=0;
        while(i < l){
            if(h[i] > 0){
                h[i]--;
                a[j++] = i+min;

            }
            else i++;
        }
        cout<<"Sorted array by CountSort:"<<endl;
        for(int i=0; i<n; i++)
            cout<<a[i]<<endl;
        cout<<endl;
    }

    static void bucketOrBinSort(int a[], int n){
        int max = INT_MIN, min = INT_MAX;
        for(int i=0; i<n; i++){
            if(a[i]<min)
                min = a[i];
            if(a[i]>max)
                max = a[i];
        }
        int l = max-min+1;
        Queue<int> h[l];
        for(int i=0; i<n; i++)
            h[a[i]-min].enQueue(a[i]);
        int i=0, j=0;
        while(i < l){
            if(!h[i].isEmpty())
                a[j++] = h[i].deQueue();
            else i++;
        }
        cout<<"Sorted array by BucketOrBinSort:"<<endl;
        for(int i=0; i<n; i++)
            cout<<a[i]<<endl;
        cout<<endl;
    }

    static void radixSort(int a[], int n){
        int max = INT_MIN;
        for(int i=0; i<n; i++){
            if(a[i]>max)
                max = a[i];
        }
        max = log10(max)+1;
        int k=1;
        while(k<=max){
            Queue<int> h[10];
            for (int i = 0; i < n; i++) {
                h[(a[i]/k)%10].enQueue(a[i]);
            }
            int i = 0, j = 0;
            while (i < 10) {
                if (!h[i].isEmpty())
                    a[j++] = h[i].deQueue();
                else i++;
            }
            k++;
        }
        cout<<"Sorted array by RadixSort:"<<endl;
        for(int i=0; i<n; i++)
            cout<<a[i]<<endl;
        cout<<endl;
    }

    static void shellSort(int a[], int n){
        int k=n/2;
        while(k>=1){
            for(int i=0; i+k<n; i++){
                if(a[i]>a[i+k]){
                    int j = i;
                    while(j>=0 && a[j]>a[j+k]){
                        swap(a[j], a[j+k]);
                        j-=k;
                    }
                }
            }
            k/=2;
        }
        cout<<"Sorted array by ShellSort:"<<endl;
        for(int i=0; i<n; i++)
            cout<<a[i]<<endl;
        cout<<endl;
    }

    static void Test(){

        int a[] = {10,6,5,1,9};
        bubbleSort(a,sizeof(a)/sizeof(int)-1);

        int b[] = {10,6,5,1,9};
        selectionSort(b,sizeof(a)/sizeof(int)-1);

        int c[] = {10,6,5,1,9};
        mergeSort(c,sizeof(a)/sizeof(int)-1);

        int d[] = {10,6,5,1,9};
        quickSort(d,sizeof(d)/sizeof(int),0,sizeof(d)/sizeof(int));
        cout<<"Sorted array by QuickSort:"<<endl;
        for(auto x: d)
            cout<<x<<endl;
        cout<<endl;

        int e[] = {10,6,5,1,9};
        heapSort(e, sizeof(d)/sizeof(int));

        int f[] = {10,6,5,1,9};
        insertionSort(f, sizeof(f)/sizeof(int));

        int g[] = {10,6,5,1,9};
        treeSort(g, sizeof(g)/sizeof(int));

        int h[] = {10,6,5,1,9};
        countSort(h, sizeof(h)/sizeof(int));

        int i[] = {10,6,5,1,9};
        bucketOrBinSort(i, sizeof(i)/sizeof(int));

        int j[] = {10,6,5,1,9};
        radixSort(j, sizeof(j)/sizeof(int));

        int k[] = {10,6,5,1,9};
        shellSort(k, sizeof(k)/sizeof(int));
    }

};

#endif //DSA_SORT_H
