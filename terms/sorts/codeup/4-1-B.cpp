//
// Created by dell on 2021/6/6.
//

// Problem B: 特殊排序
// http://codeup.hustoj.com/problem.php?cid=100000581&pid=1

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int main(){
    int n;
    int arr[1000];

    while(cin >> n){
        for(int i = 0;  i < n; i ++){
            cin >> arr[i];
        }
        sort(arr, arr + n);

        //输出最大值
        printf("%d\n",arr[n - 1]);

        //输出其他值
        if (n == 1){
            printf("%d ", -1);
        }else{
            for(int i = 0; i < n -1 ; i++){
                printf("%d ", arr[i]);
            }
        }

        cout <<endl;
    }

    return 0;
}