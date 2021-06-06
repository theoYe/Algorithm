//
// Created by dell on 2021/6/6.
//


//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//    string str;
//    while(getline(cin ,str))
//    {
//        sort(str.begin(), str.end());
//        cout<< str << endl;
//    }
//
//    return 0;
//}



#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(char a, char b){
    return a<b;
}

int main(){
    char arr[200];
    char c;
    int len =0 ;
    while(cin.getline(arr, 200)){

    len = strlen(arr);
    sort(arr, arr + len);
    cout << arr <<endl;
    len = 0;

//        if (c == '\n'){
//            arr[len] = '\0';
//            sort(arr, arr + len, cmp);
//            printf("%s\n", arr);
//            len = 0;
//        }else{
//            arr[len++] = c;
//        }
    }
    return 0;
}
