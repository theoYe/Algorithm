//
// Created by lenovo on 2021/6/6.
//
#include <iostream>

struct Rank{
    int r; //rank
    int score;
};

struct Student: public Rank{
};

void rank(Rank * rank, int n){
    rank[0].r = 1;
    for(int i = 1; i < n ; i ++){
        if(rank[i].score == rank[i-1].score){
            rank[i].r = rank[i-1].r;
        }else{
            rank[i].r = i + 1;
        }
    }
}

void test_rank(){

    // init some data
    Student stu[100];
    for(int i =0 ; i < 100; i++){
        stu[i].score = 0;
    }
    stu[0].score = 3;
    stu[1].score = 1;
    stu[2].score =0;
    stu[3].score =1;

    // rank
    rank(stu , 100);

    // output results
    for(int i = 0; i<100; i++ ){
        printf("%d ", stu[i].r);
    }

}

int main(){


    return 0;
}