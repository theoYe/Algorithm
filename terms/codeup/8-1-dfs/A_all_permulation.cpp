//
// Created by dell on 2021/9/10.
//


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 10;



int arr[maxn];
int main(){

    int n;

   cin >> n;

    //assign
    for(int i =0;  i < n; i ++){
        arr[i] = i +1;
    }


    do{
        for(int i = 0;  i<  n ; i ++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }while (next_permutation(arr  , arr + n));


    return 0;
}

