//
// Created by dell on 2021/6/6.
//
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student{
    int id;
    char name[12];
    int score;
}stu[100010];

//按分数从低到高
bool id_cmp(Student a, Student b){
    return a.id < b.id;
}

//递增字典排序
bool name_cmp(Student a, Student b){
    if (strcmp(a.name , b.name) !=0) return strcmp(a.name, b.name) < 0;
    else return id_cmp(a, b);
}

//递增字典排序
bool score_cmp(Student a, Student b){
    if ( a.score != b.score) return a.score< b.score ;
    else return id_cmp(a,b);
}

bool (*cmp(Student a, Student b));


bool (* stu_cmp(int c))(Student a, Student b){
    switch (c) {
        case 1:
            return id_cmp;
        case 2:
            return name_cmp;
        case 3:
            return score_cmp;
    }
}



int main(){

    int n, c;
    int cn = 0;
    while(cin >>n >>c, n){

        cn++;
        for(int i= 0 ; i < n ; i ++){
            cin >> stu[i].id>>stu[i].name>>stu[i].score;
        }
        sort(stu, stu + n, stu_cmp(c));
        printf("Case %d:\n",cn);
        for(int i = 0;  i < n; i ++){
            printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
        }

    }

    return 0;
}