//
// Created by dell on 2021/9/9.
//

#include <iostream>
#include <algorithm>

using namespace  std;

const int maxn = 100000;

void merge(int A[], int L1 , int R1 , int L2 , int R2){
    int temp[maxn];
    int i = L1 , j = L2, index= 0 ;
    //当 i < R1, j < R2
    while(i <= R1 && j<=R2){
        //如果 A[i] <= A[j] , index ++  A[i] 放入 temp [index]
        if (A[i] <= A[j]) {temp[index++] = A[i++]; }
        //如果 A[i] > A[j] , index ++ A[j] 放入 temp [index]
        else {temp[index++] = A[j++]; }
    }

    while(i <= R1) {temp[index++] = A[i++]; }
    while(j <= R2) {temp[index++] = A[j++]; }

    for (int k = 0 ; k < index ; k ++){
        A[L1+k] = temp[k];
    }
}

void merge_sort(int A[] , int left ,int right){
    if(left <  right){
        int mid = (left + right) / 2;
        merge_sort(A , left, mid );
        merge_sort(A ,mid+1, right);
        merge(A , left , mid , mid + 1,right );
    }
}


int main(){
    int A[] = {3,54,1,345,6,2,5};

    merge_sort(A , 0 , 6);

    for(int i = 0;  i < 6; i ++){
        cout << A[i]<< endl;
    }

}