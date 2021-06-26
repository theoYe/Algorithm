# 1 基础

## 1.1 输入输出


### 从文件中读取

### 1. 一般的模板
一般来说，模板如下

```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int main(){

    int n, c;

    while(cin >> n>>c){
        for(int i = 0;  i < n; i ++){

        }
    }


    int arr[100];

    for(int i = 0;  i < 100; i ++){
        arr[i] = 0;
    }
    return 0;
}
```

### 2. 读取空格

要求读取空格时 cin会无法使用， 这时可以使用 getline(cin, str) 来达到这个目的
> 注意 str必须是string 类型的
**更多示例看 `4-1-D.cpp`**
```c++

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while(getline(cin ,str))
    {
        sort(str.begin(), str.end());
        cout<< str << endl;
    }

    return 0;
}

```
> cin.getline 有时会读取不到数据

>EOF 应该使用 int类型的数据来进行接收！



### 3. 遇到0终止
遇到0 终止时，我们可以利用 逗号表达式，来简写
>逗号表达式的取值为最后一个表达式的取值， 因此这里的取值为 n
```c++
    while(cin >> n ,n ){
        for(int i = 0;  i < n; i ++){

        }
    }

```

### 4. 复合型的输入

有时输入的数据可能会有些复杂, 但还是通过 `cin>>n ; for(i<n)` 的形式进行读取, 一般来说， 第一个`while(cin>>n)` 只
放一个 cin>>n ,而不要放 cin>>n>>m , 这样便于做判断，如果有其他的输入，可以写到后面

```c++
    while(cin >> n,n){
        cin>> m >> g;
}
```

## 1.2  数据的定义及类型选择

大多数情况下直接定义一个结构体数组, 此时很多操作都可以直接使用到该数组中，如sort等 

- 千级数组的量级 在 1 - 10 KB 左右 
- 百万级数组量级在 1-10 MB 左右
```c++
struct Student{
    int r; //rank
    int score;
}stu[30010];
```



## 应该使用数组还是vector? 有什么区别？

# 2 排序题目

## 2.1 排序模板

**sort 对于数据默认升序排列**

排序一般使用 C++ 的sort 函数, 详情看 模板中的排序部分

> sort 函数默认为升序排序，如果是基础数据类型，可以不填写 cmp变量,
>
> 如果对象实现了 < 运算符， 也可以不填写cmp变量

```c++



//1. 可以全部排序 排序完成之后进行 rank
std::sort(stu, stu + 100010, cmp);  //或者 Student实现 "<"赋值运算符重载
rank(stu , 100010);

//2. 也可以进行部分排序 , 如对 [10, 21) 进行排序, 再rank
std::sort(&stu[10], &stu[21], cmp);
rank(&stu[10], 10);
```

### 也有可能根据选择进行排序

```c++

struct Student{
    int id;
    char name[12];
    int score;
}stu[100010];

//按分数从低到高
bool id_cmp(Student a, Student b){
    return a.id < b.id;
}

//递增字典排序
bool name_cmp(Student a, Student b){
    if (strcmp(a.name , b.name) !=0) return strcmp(a.name, b.name) < 0;
    else return id_cmp(a, b);
}

//递增字典排序
bool score_cmp(Student a, Student b){
    if ( a.score != b.score) return a.score< b.score ;
    else return id_cmp(a,b);
}

bool (*cmp(Student a, Student b));


bool (* stu_cmp(int c))(Student a, Student b){
    switch (c) {
        case 1:
            return id_cmp;
        case 2:
            return name_cmp;
        case 3:
            return score_cmp;
    }
}

```
之后可以这么使用
```c++
sort(stu, stu + n, stu_cmp(c));
```

## 2.2 排名模板



如果需要根据分数进行排序，下面是解决方案

```c++

struct Rank{
    int r; //rank
    int score;
};

struct Student: public Rank{
};

void rank(Rank * rank, int n){
    rank[0].r = 1;
    for(int i = 1; i < n ; i ++){
        if(rank[i].score == rank[i-1].score){
            rank[i].r = rank[i-1].r;
        }else{
            rank[i].r = i + 1;
        }
    }
}

```





# 3 哈希

## 3.1 一般模板

一般直接定义hash函数

```c
 int hashTable[210] = {0};
```



## 3.2 hash函数



有时可能需要自己实现hash函数 (选择合适的 10000值来确保hash函数不会重叠s)

```c
//根据值和分组g来确定哈希值
// 注意哈希值是否有可能重叠！！！！
int hashFunc(int v, int g){
    return v  + (g - 1) * 10000;
}

```



## 3.1 字符串字母哈希

将纯字母的字符串哈希为整数

```c++
/*
 * 将字符串S传唤为整数
 */
int hashFunc(char S[], int len){
    int id =0 ;
    for(int i =0;i < len;i ++){
        if(S[i] > 'A' && S[i] <= 'Z'){
            id = id * 52 + (S[i] - 'A');
        }else if (S[i] > 'a' && S[i] <= 'z'){
            id = id * 52 + (S[i] - 'a') + 26;
        }
    }
    return id;
}
```



## 3.2 字符+数字的哈希

```c
int hashFunc(char S[], int len){
    int id =0 ;
    for(int i =0;i < len;i ++){
        if(S[i] > 'A' && S[i] <= 'Z'){
            id = id * 62 + (S[i] - 'A');
        }else if (S[i] > 'a' && S[i] <= 'z'){
            id = id * 62 + (S[i] - 'a') + 26;
        }else if (S[i] >= 0 && S[i] <= 9){
            // 数字
            id = id * 62 + S[i] + 52;
        }
    }
    return id;
}
```






## 3.3 哈希应用场景

- 去除 A 中含有 B的元素 (4-2-D)
- 计算含有相同元素的个数
- 非A即B的关系 （如LeetCode  两数之和）
- 计算分组



# 4 递归



## 4.1 斐波那契数列



我们可以获得斐波那契数列的值，在计算时加入如下

```c++

int arr[1001] = {0} ;

int Fibonacci(int n){
    if(n==0) { return 0; }
    if(n==1) return 1;
    int n2 = Fibonacci(n- 2);
    int n1 = Fibonacci(n- 1);
    arr[n -2] = n2;
    arr[n-1] = n1;
    return n2 + n1;
}
```





## 4.2 全排列问题





```c++
#include <cstdio>

const int maxn = 11;
// P[maxn] 存放每个排列
// hashTable : 存放该排列中该数字是否已经出现过
int n, P[maxn], hashTable[maxn] = {false};

void generateP(int index){
    if(index == n+1){
        for(int i = 1; i <= n; i ++){
            printf("%d", P[i]);
        }
        printf("\n");
        return ;
    }

    for(int x = 1; x <= n; x++){
        if(hashTable[x] == false){
            P[index] = x;   //p[1] = 1 p[1] =2 , p[3] = 3
            hashTable[x] = true;
            generateP(index  + 1);  //generateP(2) generateP(2) generateP(2)
            hashTable[x] = false;
        }
    }
}

```





## 4.3 生成排列



下面函数生成start - end 之间的排列数, 长度为n=l, (l为迭代变量)



```c
//生成数字 start-end 的 长度为 l 的排列
//l 为当前长度(迭代使用的变量), n为数字长度
void genP(int index,int start, int end, int n, int l){
    //长度满足 (操作排列)
    if(l==0){
        for(int i=1 ;i <=n;i++){
             arr[P[index-i]]; // do something to number
        }
    }

    for(int i= start; i <= end ; i++){
        P[index] = i;
        genP(index+1,  i+1,end,n,l-1);
    }
}
```



## 4.4 n皇后问题



1. 利用全排列解决n皇后问题  (templates/n_queen.cpp)
2. 保存n皇后问题的数据   (4-3-D.cpp)





















# 4 数值类型判断

## 奇偶判断

```c++
//奇数
if( n % 2){
    arr[odd++] = n;
//偶数
}else{
    arr[9 - even++] = n;
}
```

# 调试要点



## 1. 输入输出是否正确



1. 看程序能否按照要求结束

```c++
while(cin >> m, m){
    
}
```

如果没有EOF， 确保有如下形式
```c++
cin >> m;
for (int i =0; i < m; i ++){
    
}
```

