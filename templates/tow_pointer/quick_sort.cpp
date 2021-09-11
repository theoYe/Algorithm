//
// Created by dell on 2021/9/9.
//

#include <iostream>
#include <algorithm>


using namespace  std;


//使得 A[1] 处于正确位置
int Partition(int A[] , int left , int right){
    int temp = A[left];
    while(left < right){
        while(left < right && A[right] >= temp) right --;
            A[left] = A[right];
        while(left < right &&  A[left] <= temp) left ++;
            A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

void quickSort(int A[] , int left, int right){
    if(left < right){
        int pos = Partition(A , left, right);
        quickSort(A, left, pos );
        quickSort(A, pos+1, right );
    }
}

int main(){
    int A[] = {3,54,1,345,6,2,5};

    quickSort(A , 0 , 6);

    for(int i = 0;  i < 6; i ++){
        cout << A[i]<< endl;
    }

    return 0;
}