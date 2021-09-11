//
// Created by dell on 2021/6/6.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int main(){

    int n, m;
    int arr[10010];
    while(cin >> n, n){

        for(int i = 0;  i < n; i ++){
            cin >> arr[i];
        }
        sort(arr, arr+n);  //n logn
        int a = n%2;
        if (!(n%2)){
            m = (arr[n/2-1] + arr[n/2])/2;
        }else{
            m = arr[n/2];
        }
        printf("%d\n", m);
    }
    return 0;
}