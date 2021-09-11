//
// Created by lenovo on 2021/6/6.
//

/**
 *
 *
 *

3
7
3 2 3 8 8 2 3
1 2 3 2 1 3 1
2
 3 4
 1 2
 2
 3 4
 1 2

 3
1
 2
 1
1
 1
1
 1
 3
 1
 */


//#include <bits/stdc++.h>
//using namespace std;
//const int MAXN = 1005;
//int hashTable[MAXN][MAXN];
//int main() {
//    int m, n, a[110], t;
//    scanf("%d", &m);
//    while (m--) {
//        scanf("%d", &n);
//        for (int i = 0; i < n; i++) {
//            scanf("%d ", &a[i]);
//            hashTable[0][a[i]] = 1;//表示这一列数据需要输出
//        }
//        for (int i = 0; i < n; i++) {
//            scanf("%d", &t);
//            hashTable[t][a[i]]++;
//            if (hashTable[t][0] == 0) hashTable[t][0] = 1;//表示这一列(组)需要输出
//        }
//        for (int i = 1; i < MAXN; i++) {
//            if (hashTable[i][0] == 1) { //说明存在第i组
//                printf("%d={", i);
//                bool flag = false; //控制逗号
//                for (int j = 1; j < MAXN; j++) {
//                    if (hashTable[0][j] == 1) {//说明这一列需要输出
//                        if (flag) printf(",");//控制逗号
//                        else flag = true;
//                        printf("%d=%d", j, hashTable[i][j]);
//                    }
//                }
//                printf("}\n");
//            }
//        }
//        //重置哈希表
//        memset(hashTable, 0, sizeof(hashTable));
//    }
//    return 0;
//}


#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

//根据值和分组g来确定哈希值
// 注意哈希值是否有可能重叠！！！！
int hashFunc(int v, int g){
    return v  + (g - 1) * 10000;
}


int main(){

    int n, m;




    int gn;
    cin >> m;
    for(int i =0 ; i < m;i++){
        int num[110] = {0};
        int gr[10010] ={0};
        int hashTable[1000100] = {0};

        set<int> num_show;
        set<int> group_show;

        cin >> n;
        for(int i = 0;  i < n; i ++){
            cin>>num[i];
            num_show.insert(num[i]);
        }
        for(int i = 0;  i < n; i ++){
            cin>>gn;
            group_show.insert(gn); //存在该分组
            hashTable[hashFunc(num[i], gn)]++;
        }

        // set 不能sort ，不过默认就是升序！
//            sort(group_show.begin(), group_show.end());
//            sort(num_show.begin(), num_show.end());

        for(auto it=group_show.begin(); it!=group_show.end();it++){
            printf("%d={", *it);
            for(auto j=num_show.begin(); j!=num_show.end();j++){
                if(j  != (--num_show.end()))
                    printf("%d=%d,", *j, hashTable[hashFunc(*j , *it)]);
                else
                    printf("%d=%d}\n", *j, hashTable[hashFunc(*j , *it)]);
            }
        }
    }



    return 0;
}
