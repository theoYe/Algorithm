//
// Created by dell on 2021/6/7.
//

#include <iostream>
#include <cstring>
#include <algorithm>

//int Fibo(int n){
//    if(n==1) return 1;
//    if(n==0) return 0;
//
//    return Fibo(n - 1) + Fibo(n - 2);
//}


// 偶数次输出
int Fibo(int n){
    if(n==1) { printf("%d ", 1); return 1 ;}
    if(n==0) { printf("%d ", 0); return 0; }


    else {    printf("  ");}

    int n2 = Fibo(n-2);
    int n1 = Fibo(n - 1);

    return Fibo(n - 2) + Fibo(n - 1);
}


using namespace std;


int main(){
    printf("%d\n", Fibo(2));
    printf("%d\n", Fibo(4));
    printf("%d\n", Fibo(6));
    return 0;
}