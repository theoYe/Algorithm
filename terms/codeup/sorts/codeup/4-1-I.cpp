//
// Created by dell on 2021/6/6.
//


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student{
    char id[24];
    int m; //解决的题目总数
    int solved_list[10]; //解决的题号
    int score;  //分值
}stu[1010];

bool cmp(Student a, Student b){
    if(a.score != b.score) return a.score>b.score;
    else return  strcmp(a.id, b.id) < 0;
}

int main(){

    int n, m,g;
    int up_g = 0; //高于分数线的学生数
    int ms[10] = {0};

    //考生输入为0时输入结束
    while(cin >> n,n){
        cin>> m >> g;
            //题目分值
            for(int i = 0;  i < m; i ++){
                cin >> ms[i];
            }

            //考生信息
            for(int i =0; i < n;i ++){
                stu[i].score = 0;
                cin >> stu[i].id >> stu[i].m;
                //题号
                for(int j =0; j < stu[i].m; j++){
                    cin >> stu[i].solved_list[j];
                    stu[i].score += ms[stu[i].solved_list[j] - 1];
                }
                if(stu[i].score >= g){
                    up_g++;
                }
            }

            sort(stu , stu +n , cmp);
            printf("%d\n", up_g);
            for(int i =0 ; i<n;i++){
                if(stu[i].score >= g){
                    printf("%s %d\n", stu[i].id, stu[i].score);
                }
            }

            up_g =0 ;
    }


    return 0;
}

