//
// Created by dell on 2021/9/10.
//


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 10;

int P[maxn];
bool hashTable[maxn] = {false};
int arr[maxn];
int n , r;


void dfs(int step){

    if (step == r+ 1){

        //输出
        for(int i = 1 ; i <= r; i ++){
            printf("%d " , P[i]);
        }
        printf("\n");
        return ;
    }

    // x = P[step - 1] +1 保证字典序
    for(int x = P[step - 1]+ 1; x <=n; x++){
        if(hashTable[x] == false){
            P[step] = x;
            hashTable[x] = true;
            dfs(step + 1);
            hashTable[x] = false;
        }
    }

}


int main(){

    cin >> n >> r;
    dfs(1);
    return 0;
}

