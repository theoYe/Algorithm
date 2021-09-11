//
// Created by dell on 2021/6/7.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;


const int maxn = 100010;
int arr[maxn];

void merge(int A[] , int L1, int R1, int L2 , int R2){
    int temp[maxn];
    int i = L1 ,j = L2 , index = 0;


    while(i <= R1 && j <= R2){
        if(A[i] <= A[j]) { temp[index++] = A[i++] ;}
        else { temp[index++] = A[j++] ;}
    }

    while(i<=R1) temp[index++] =A[i++];
    while(j<=R2) temp[index++] =A[j++];

    for (int k= 0 ; k < index ; k ++){
        A[L1 + k] = temp[k];
    }
}

void mergeSort(int A[] , int left ,int right){
    if(left < right){
        int mid = (left + right) /2;
        mergeSort(A, left, mid);
        mergeSort(A, mid +1, right);
        merge(A , left, mid , mid +1 , right);
    }
}

int main(){

    for(int j = 0; j < 10000; j ++){
        for (int i= 0; i < maxn; i ++){
            srand((unsigned)time(NULL));
            arr[i] =  rand();
        }

        mergeSort(arr , 0 , maxn-1);
    }
    return 0;



    int n;
    int m;

       while(cin >> n){
           while (cin >>m ){ //m 数字个数
               for (int i= 0 ; i < m; i ++){
                   cin >> arr[i];
               }
               mergeSort(arr , 0 , m-1);
               for (int i = 0 ; i < m ; i ++){
                   cout << arr[i] <<endl;
               }
           }
       }


    return 0;
}
