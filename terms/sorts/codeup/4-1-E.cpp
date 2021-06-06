//
// Created by dell on 2021/6/6.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(long a, long b){
    return a>b;
}
int main(){

    int n;
    int a[10][10];

    while(cin >> n){
        long res[21] = {0};
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j ++){
                cin >> a[i][j];
            }
        }


        for(int i = 0 ; i < n ; i ++){
            res[0] += a[i][i];
            res[1] += a[i][n-i -1];
            for(int j = 0 ; j < n ; j ++){
                res[i + 2] += a[i][j];
                res[j+2+n] += a[i][j];
            }
        }

        sort(res, res+2*n + 2, cmp);

        for(int i= 0; i < 2*n+2; i++){
            printf("%d ", res[i]);
        }
        cout << endl;
    }



    return 0;
}
