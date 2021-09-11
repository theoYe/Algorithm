//
// Created by lenovo on 2021/6/6.
//

// @see https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872
// A 对应 甲级
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Rank{
    int r; //rank
    int score;
};


struct Testee: public Rank{
    char reg_number[14]; //registration number
    int local_number;
    int local_rank;
    static bool testee_cmp(const Testee&  t1,const  Testee& t2){
        if (t1.score != t2.score) return t1.score > t2.score;  //按分数从高到低排序
        else return strcmp(t1.reg_number, t2.reg_number) < 0;  //按准考证号从小到大排序
    }
}testees[30010];

// 指针记得改成对应类型， 否则使用 [i] 访问后可能由于类型大小不一致出错
void mRank(Testee * rank, int n){
    rank[0].r = 1;
    for(int i = 1; i < n ; i ++){
        if(rank[i].score == rank[i-1].score){
            rank[i].r = rank[i-1].r;
        }else{
            rank[i].r = i + 1;
        }
    }
}

void localRank(Testee * rank, int n){
    rank[0].local_rank = 1;
    for(int i = 1; i < n ; i ++){
        if(rank[i].score == rank[i-1].score){
            rank[i].local_rank = rank[i-1].local_rank;
        }else{
            rank[i].local_rank = i + 1;
        }
    }
}

int main(){
    int n; // number of test location

    int total = 0;
    int local = 1;
    // read
    while(cin >> n){
        int k; //ranlists
        while(n--){
            cin >> k;
            for (int i = 0; i < k ; i++){

                testees[total].local_number =  local;
                cin>>testees[total].reg_number >> testees[total].score ;
                total++;//总人数加一
            }
            //本考场进行排序
            sort(&testees[total-k], &testees[total], Testee::testee_cmp);
            localRank(&testees[total - k], k);
            local ++; //考场号加以一
        }
    }

    //所有考生排序
    sort(testees, testees+total, Testee::testee_cmp);
    mRank(testees, total);

    cout << total <<endl;
    for(int i = 0 ; i < total;i ++){
        printf("%s %d %d %d\n", testees[i].reg_number, testees[i].r, testees[i].local_number, testees[i].local_rank);
    }

    return 0;
}

