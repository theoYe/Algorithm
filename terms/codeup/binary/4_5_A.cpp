//
// Created by dell on 2021/9/8.
//

#include <iostream>
#include <algorithm>

using namespace  std;

struct Item{
    int value;
    int index;
}items[1000];

int sortItems(Item a, Item b){
    if (a.value != b.value) return  a.value < b.value;
    else return a.index < b.index;
}


int binarySearch(Item i[]  , int left, int right , int value){

    while(left <= right){
        int mid = (left + right ) / 2;
        if (i[mid].value == value ){
            return i[mid].index;
        } else if (i[mid].value > value){
            right = mid -1;
        }else if (i[mid].value < value){
            left = mid + 1;
        }
    }
    return  -1;
}

int main(){

    //输入 n 个区间
    int n;
    int find;
    while(cin >> n){
        for (int i = 0 ; i < n ; i ++){
            cin >> items[i].value ;
            items[i].index = i;
        }
        cin >> find;

        // 按照值进行排序
        sort(items, items + n , sortItems);


        int res = binarySearch(items,  0 , n - 1, find);
        cout << res << endl;
    }

    return 0;
}