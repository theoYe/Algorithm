//
// Created by lenovo on 2021/6/5.
//
#include <iostream>
#include <cstring>
#include <algorithm>
struct Student {
    char name[10]; //姓名
    char id[10]; //准考证号
    int score;
    int r;  //排名
}stu[100010];

// a > b return true
// a < b return false
// 这里分数大到小，分数一样， 字典序小的排在前面
bool cmp(Student a , Student b ){
    if(a.score != b.score ) return a.score > b.score;
    else return strcmp(a.name, b.name);
}

// 排序完成之后 按照 score 进行 r 的排名
void rank(Student * stus, int len){
    stus[0].r = 1;
    for(int i = 1; i < len  ; i ++){
        if(stus[i].score == stus[i-1].score){
            stus[i].r = stus[i-1].r;
        }else{
            stus[i].r = i + 1;
        }
    }
}

// 测试排序
void test_sort(){
    //1. 可以全部排序 排序完成之后进行 rank
    std::sort(stu, stu + 100010, cmp);  //或者 Student实现 "<"赋值运算符重载
    rank(stu , 100010);

    //2. 也可以进行部分排序 , 如对 [10, 21) 进行排序, 再rank
    std::sort(&stu[10], &stu[21], cmp);
    rank(&stu[10], 10);
}