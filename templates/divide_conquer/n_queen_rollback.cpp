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
void generateP(int index){
    if(index == n+1){
        count++;
        return ;
    }

    for(int x = 1; x <= n; x++){
        if(hashTable[x] == false){

            bool flag = true;
            for(int pre=1; pre < index; pre++){

                if(abs(index - pre) == abs(x - P[pre])){
                    flag = false;
                    break;
                }
            }

            if(flag){
                P[index] = x;   //p[1] = 1 p[1] =2 , p[3] = 3
                hashTable[x] = true;
                generateP(index  + 1);  //generateP(2) generateP(2) generateP(2)
                hashTable[x] = false;
            }


        }
    }
}

int main(){
    n = 3;
    generateP(1);
    return 0;
}
