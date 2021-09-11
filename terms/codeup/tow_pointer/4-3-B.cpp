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

int arr[1001] = {0} ;

int Fibonacci(int n){
    if(n==0) { return 0; }
    if(n==1) return 1;
    int n2 = Fibonacci(n- 2);
    int n1 = Fibonacci(n- 1);
    arr[n -2] = n2;
    arr[n-1] = n1;
    return n2 + n1;
}


using namespace std;


int main(){

    int n ,m;
    cin>>m;
    for(int i= 0; i< m; i++){

        cin >> n;
        //获得斐波那契数列
        arr[2*n-1] = Fibonacci(2*n-1);
        for(int j = 1; j <= n;j++){
            //打印空格
            for(int k=0;k< n-j;k++){
                printf("  "); //空格个数为 n-j
            }

            //第一行打印1个， 第二行打印3个... 第n行打印n-1个
            for(int b=0;b<2*j-2;b++){
                printf("%d ",arr[b]);
            }
            printf("%d\n", arr[2*j-2]);
        }

    }



    return 0;
}