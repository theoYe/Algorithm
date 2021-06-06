//
// Created by lenovo on 2021/6/7.
//


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int main(){

    int n;

    while(cin >> n){
        int hashTable[10010] = {0}; //数字从 1-10000 中选取
        int num[100010]; //n < 10 0000
        for(int i = 0;  i < n; i ++){
            cin >> num[i];
            hashTable[num[i]]++;
        }

        bool flag = false;
        for(int i =0; i < n;i++){
            if(hashTable[num[i]] == 1){
                printf("%d\n", num[i]);
                flag = true;
                break;
            }
        }
        if (!flag) printf("None\n");
    }

    return 0;
}
