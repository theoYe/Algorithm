//
// Created by lenovo on 2021/6/6.
//

//注意变量的初始化！！！
// 多次尝试看结果是否相同

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Reader{
    int like_bn;
    int id;
}r[100010];
int main(){

    int n, m;

    int bn;  //图书编号
    while(cin >> n){
        cin >> m;
        int hashTable[210] = {0};
        for(int i = 0;  i < n; i ++){
            cin >> bn;
            r[i].id = i;
            r[i].like_bn = bn;
            hashTable[bn] ++;
        }

        for(int i = 0;  i < n; i ++){
            // = 0 说明没有好友
            if( hashTable[r[i].like_bn] - 1  ){
                printf("%d\n", hashTable[r[i].like_bn] -1);
            }else{
                printf("BeiJu\n");
            }
        }
    }
    return 0;
}

