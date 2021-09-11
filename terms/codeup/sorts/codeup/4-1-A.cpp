//
// Created by dell on 2021/6/6.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 排序
// @link http://codeup.hustoj.com/problem.php?cid=100000581&pid=0

int main(){

    int n;
    int a[100];

    while (cin>>n){
        for(int i= 0 ; i < n; i ++){
            cin >> a[i];
        }

        sort(a , a +n );

        for(int i = 0;  i < n; i ++){
            printf("%d ",a[i]);
        }
        cout << endl;
    }




    return 0;
}

