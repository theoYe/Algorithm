//
// Created by dell on 2021/9/10.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20;
int n;
int maxValue , maxCapacity;


void DFS(int index, int sumValue , int sumCapacity){
    if(index == n){
      //达到最多件数
      if(sumValue >= maxValue && sumCapacity >= maxCapacity )
          maxValue = sumValue;
    }



}

int main(){




}