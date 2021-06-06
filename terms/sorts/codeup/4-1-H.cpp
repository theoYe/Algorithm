//
// Created by dell on 2021/6/6.
//


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(){

    int n;
    int arr[10];
    int odd = 0, even =0;

    while(true){
        for(int i = 0;  i < 10; i ++){
            if(cin >>n)
            {
                //奇数
                if( n % 2){
                    arr[odd++] = n;
                //偶数
                }else{
                    arr[9 - even++] = n;
                }
            }
            else goto out;
        }

        sort(arr, arr +odd, cmp);
        sort(arr + odd, arr+10);
        odd =0 ;
        even = 0;

        for(int i = 0;  i < 10; i ++){
            printf("%d ", arr[i]);
        }
        cout << endl;
    }
out:
//    int arr[100];

    return 0;
}

