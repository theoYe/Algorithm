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
    for(int i =1;  i <= n; i ++){
        arr[i] = i;
    }

    int count = 0;
    do{


        int flag = true;
        for(int i = 1;  i<=  n ; i ++){
            for(int j = i + 1;  j <= n ; j ++){
                //斜线 ， 行列相减相等
                if( abs( i - j) ==  abs(arr[i] -arr[j]))
                    flag = false;
            }
        }

        if(flag){
            for(int i =1 ; i <= n ; i ++){
                printf("%d " , arr[i]  );
            }
            printf("\n");

            count ++;
        }


    }while (next_permutation(arr + 1  , arr + n + 1));

    if(!count) {
        printf("no solute!\n");
    }

    return 0;
}

