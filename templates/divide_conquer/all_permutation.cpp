//
// Created by dell on 2021/6/7.
//

/**
 * 全排列模板
 */



#include <cstdio>

const int maxn = 11;
// P[maxn] 存放每个排列
// hashTable : 存放该排列中该数字是否已经出现过
int n, P[maxn], hashTable[maxn] = {false};

void generateP(int index){
    if(index == n+1){
        for(int i = 1; i <= n; i ++){
            printf("%d", P[i]);
        }
        printf("\n");
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
    n = 3;
    generateP(1);
    return 0;
}
