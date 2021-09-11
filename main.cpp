#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int findSubStringWindow(string s, int start){

    int hashStr[256] = {-1};
    for (int i = 0; i < 256; i++)
        hashStr[i] = -1;

    int    n = s.size() , ans= 0 ;
    for(int start =0 ,end = 0 ;  end < n ; end++){

        //如果存在就更新 start 位置
        if(hashStr[s[end]] != -1){
            //这句之后无需 remove
            start = max( hashStr[s[end]] + 1, start);
        }

        ans = max(ans, end - start + 1);
        hashStr[s[end]] = end;
    }

    return ans;
}


bool isPermulation( string s1, string s2){
    if(s1.size() >= s2.size( )) return false;

    int hashVal1[128] = {0};
    int hashVal2[128] = {0};


    for(int i = 0;i < s1.size(); i ++){
        hashVal1[s1[i]] ++;
    }

    for(int i = 0;i < s2.size(); i ++){
        hashVal2[s2[i]] ++;
    }

    for(int i =0 ; i< 128; i++){
        if(hashVal1[i] != hashVal2[i] ) return false;
    }
    return true;

}

bool checkInclusion(string s1, string s2) {

//    for(int i =0 ; i< s2.size() - s1.size() + 1 ; i ++){
//        if(isPermulation(s1 , s2.substr(i, s1.size())))
//            return true;
//    }

    return false;

}


int changeVector(vector<int> a){
    a[0] = 0;
    return 1;
}

int main(){
    vector<int> aa;

    aa.push_back(3);
    aa.push_back(4);
    aa.push_back(5);
    for(int i= 0 ; i < 3 ; i ++){
        printf("%d ", aa[i]);
    }

    changeVector(aa);

    for(int i= 0 ; i < 3 ; i ++){
        printf("%d ", aa[i]);
    }


//    checkInclusion("ba", "aaab");
}