//
// Created by dell on 2021/6/7.
//

/**
 * 全排列模板
 */



#include <cstdio>

const int maxn = 11;
// P[maxn] 存放每个排列
// hashTable : 存放该排列中该数字是否已经出现过
int end_num, P[maxn], hashTable[maxn] = {false};

//生成数字 start-end 的 长度为 l 的排列
//l 为当前长度(迭代使用的变量), n为数字长度
void genP(int index,int start, int end, int length, int _length){
    //长度满足
    if(_length==0){
        for(int i=1 ;i <=length;i++){
            printf("%d", P[index-i]);
        }
        printf("\n");
    }
    for(int i= start; i <= end ; i++){
        P[index] = i;
        genP(index+1,  i+1,end,length,_length-1);
    }
}




// index 表示从 P[] 的哪个index开始存
void generateP(int index){
    if(index == end_num+1){
        //满足条件
        for(int i = 1; i <= end_num; i ++){
            printf("%d", P[i]);
        }
        printf("\n");
        return ;
    }

    for(int x = 1; x <= end_num; x++){
        if(hashTable[x] == false){
            P[index] = x;   //p[1] = 1 p[1] =2 , p[3] = 3
            hashTable[x] = true;
            generateP(index  + 1);  //generateP(2) generateP(2) generateP(2)
            hashTable[x] = false;
        }
    }
}

int main(){
//    end_num = 3;
//    generateP(1);   // index表示要存放到 P的那个位置

    genP(1,1,3,3,3);
    return 0;
}
