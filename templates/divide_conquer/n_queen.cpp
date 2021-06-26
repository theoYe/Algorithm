//
// Created by dell on 2021/6/7.
//


#include <cstdio>
#include <cmath>
const int maxn = 11;
// P[maxn] 存放每个排列
// hashTable : 存放该排列中该数字是否已经出现过
int n, P[maxn], hashTable[maxn] = {false};

int count = 0;

//保存八皇后
int queen_table[92][8]={0};



void generateP(int index){
    if(index == n+1){
        bool  flag = true;
        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <=n;j++){
                if(abs(i - j) == abs(P[i] - P[j])){
                    flag = false;  //不合法
                }
            }
//            printf("%d", P[i]);
        }

        //为八皇后正确解
        if(flag){
            for(int i=0 ;i < 8 ;i ++){
                queen_table[count][i] = P[i+1];  //赋值
            }
            count++;
        }
//        printf("\n");
        return ;
    }

    for(int x = 1; x <= n; x++){
        if(hashTable[x] == false){
            P[index] = x;   //p[1] = 1 p[1] =2 , p[3] = 3
            hashTable[x] = true;
            generateP(index  + 1);  //generateP(2) generateP(2) generateP(2)
            hashTable[x] = false;
        }
    }
}

int main(){
    n = 8;
    generateP(1);

    for(auto & i : queen_table){
        for(int j : i){
            printf("%d", j);
        }
        printf("\n");
    }



    printf("%d" , count);
    return 0;
}
