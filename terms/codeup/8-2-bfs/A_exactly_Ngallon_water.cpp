//
// Created by dell on 2021/9/10.
//


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n , m;
int Ca , Cb , N;

int answer[10000];

enum {
    FILL_A,
    FILL_B,
    EMPTY_A,
    EMPTY_B,
    POUR_AB,
    POUR_BA
};


void DFS( int ca ,int cb, int index){
    if(cb == N){
        //条件
        for(int i= 0 ; i < index; i++){
            switch (answer[i]) {
                case FILL_A:
                    printf("fill A\n");
                    break;
                case FILL_B:
                    printf("fill B\n");
                    break;
                case EMPTY_A:
                    printf("empty A\n");
                    break;
                case EMPTY_B:
                    printf("empty B\n");
                    break;
                case POUR_AB:
                    printf("pour A B\n");
                    break;
                case POUR_BA:
                    printf("pour B A\n");
                    break;
            }
        }
        printf("success\n");
        return ;
    }


    //分岔口

    // B 是空的 就 fill B
    //fill B
    if(cb == 0 && ca!= Ca){
        answer[index] = FILL_B;
        DFS(ca, Cb, index+1);
    }
    // B 不是空的就 pour B A
    //pour B A
    if( cb != 0 && ca!=Ca){
        answer[index] = POUR_BA;
        if( ca + cb >= Ca)
            DFS( Ca , cb - (Ca - ca), index+1);
        else
            DFS(ca + cb , 0, index+1);
    }
    // 如果 A 满了 就倒掉empty A
    //empty a
    if(ca == Ca ){
        answer[index] = EMPTY_A;
        DFS(0, cb, index+1);
    }

//
//    //fill a
//    if(ca != Ca && cb != Cb){
//        answer[index] = FILL_A;
//        DFS(Ca, cb, index+1);
//    }
//    //pour A B
//    if( ca!= 0 && cb != Cb){
//        answer[index] = POUR_AB;
//        if( ca + cb >= Cb)
//            DFS( ca - (Cb - cb), Cb, index+1);
//        else
//            DFS(0 , ca + cb, index+1);
//    }
//    //fill B
//    if(cb!= Cb && ca != Ca){
//        answer[index] = FILL_B;
//        DFS(ca, Cb, index+1);
//    }
//    //pour B A
//    if( cb!= 0 && ca != Ca){
//        answer[index] = POUR_BA;
//        if( ca + cb >= Ca)
//            DFS( Ca , cb - (Ca - ca), index+1);
//        else
//            DFS(ca + cb , 0, index+1);
//    }
//
//    //empty a
//    if(ca!= 0 ){
//        answer[index] = EMPTY_A;
//        DFS(0, cb, index+1);
//    }
//    //empty B
//    if(cb!= 0 ){
//        answer[index] = EMPTY_B;
//        DFS(ca, 0, index+1);
//    }


}

int main(){


   while(cin >>Ca >> Cb >>N){
        DFS(0 , 0 , 0);
   }

    //assign
//    for(int i =0;  i < n; i ++){
//        arr[i] = i +1;
//    }
//
//
//    do{
//        for(int i = 0;  i<  n ; i ++){
//            printf("%d ", arr[i]);
//        }
//        printf("\n");
//    }while (next_permutation(arr  , arr + n));
//

    return 0;
}

