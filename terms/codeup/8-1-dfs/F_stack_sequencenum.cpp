//
// Created by dell on 2021/9/10.
//



#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn = 15;
//stack<int> inStack;
//stack<int> outStack;
int n;
int ncount = 0;

// 递归状态保存： 当前数值 ， 当前 in 栈， 当前 out 栈
void dfs(int num ,stack<int> in, stack<int> out){
    if(out.size() == n){
        ::ncount ++;
        return;
    }

    // 岔道口
    //选择从队列 push
    if(num <= n)
    {
        in.push(num);
        dfs(num + 1, in , out);
        in.pop();
    }
    //选择从 inStack pop
    if(!in.empty())
    {
        out.push(in.top());
        in.pop();
        dfs(num , in ,out);
    }
}

int arr[maxn];
int main(){
    cin >> n;
    stack<int> in;
    stack<int> out;
    dfs(1 , in , out);

    printf("%d" , ncount);
    return 0;
}

