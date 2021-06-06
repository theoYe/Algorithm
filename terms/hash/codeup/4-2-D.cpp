//
// Created by lenovo on 2021/6/7.
//


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
 * 将字符串S传唤为整数
 */
int hashFunc(char S[], int len){
    int id =0 ;
    for(int i =0;i < len;i ++){
        if(S[i] > 'A' && S[i] <= 'Z'){
            id = id * 52 + (S[i] - 'A');
        }else if (S[i] > 'a' && S[i] <= 'z'){
            id = id * 52 + (S[i] - 'a') + 26;
        }
    }
    return id;
}




int main(){

//    char str1[10000];
//    char str2[10000];

    int hashTable[500] = {0};
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);



    for(int i = 0;  i < s2.size() ; i ++){
        hashTable[s2[i]] = 1;
    }

    for(int i =0;i < s1.size(); i++){
        if(hashTable[s1[i]] ==0){
            printf("%c", s1[i]);
        }
    }
    return 0;
}
