//
// Created by dell on 2021/9/8.
//

#include <iostream>
#include <algorithm>

using namespace  std;


// binarySearch 在区间 [left, right] 查找元素x
// 若未找到返回 -1
int binarySearch(int A[] , int left , int right , int x ){
    while(left <= right){
       int mid = (left+right) / 2;
       if (A[mid] == x) return mid;
       if(A[mid] < x )
           left = mid +1;
       else
           right = mid -1 ;
    }
    return  -1;
}

int main(){
    int A[10] = {1,2,3,4,5,6,7,8,9,10};

   int res =  binarySearch(A , 0 , 9 , 11);

   cout << res;
    return 0;
}
