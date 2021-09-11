//
// Created by dell on 2021/9/8.
//

#include <iostream>
#include <algorithm>

using namespace  std;
typedef  long long LL

// binaryPow 求 a^b % m
// 基于以下事实
// b % 2 = 1 : a^b = a * a ^(b-1)
// b % 2 = 0 : a^b = a^(b/2) * a^(b/2)
LL binaryPowRecursive( LL a, LL b , LL m ){
    if (b ==0 ) return  1;
    if ( b %2 ) return  a * binaryPowRecursive(a , b-1 , m) % m;
    else{
        LL mul = binaryPowRecursive(a , b/2 , m );
        return  mul * mul % m;
    }
}

// binaryPowIter 求 a^b % m
// 基于以下事实
// b % 2 = 1 : a^b = a * a ^(b-1)
// b % 2 = 0 : a^b = a^(b/2) * a^(b/2)
LL binaryPowIter( LL a, LL b , LL m ){

    LL ans = 1;
    while(b > 0){

        if (b&1){
            ans  = ans * a %m;
        }

        a = a * a %m;
        b >>= 1;
    }
    return ans;
}


int main(){
    int A[10] = {1,2,3,4,5,6,7,7,9,10};

    return 0;
}