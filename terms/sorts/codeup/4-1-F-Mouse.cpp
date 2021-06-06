//
// Created by dell on 2021/6/6.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Mouse{
    int w;
    char c[12];
}m[100];

bool cmp(Mouse a, Mouse b){
    return a.w>b.w;
}

int main(){

    int n;

    while(cin >> n){
        for(int i =0 ; i < n ;i ++){
            cin >> m[i].w >> m[i].c;
        }

        sort(m ,m+ n, cmp);

        for(int i =0 ; i < n ;i ++){
            printf("%s\n", m[i].c);
        }
    }


    return 0;
}

