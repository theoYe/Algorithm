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







## 1.2 Cout 输出延迟





**cout 具有极大的输出延迟，能不用就不要用，使用printf进行输出！**



# 2 排序题目

## 2.1 排序模板

**sort 对于数据默认升序排列** ,在 `algorithm` 命名空间中



```
sort的参数： (first, last, function)
仍然是一个 前闭合后开的区间：  [first,last)
如果是数组， 那么就是 [start, start+ 数组长度)
```



```c++
#include <algorithm>
```



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



如果需要根据排序好的结果给出具体的排名，相同分数的排名相同，下面是解决方案

```c++

struct Rank{
    int r; //rank
    int score;
};

struct Student: public Rank{
};

void rank(Rank * rank, int n){
    //0为排名第1
    rank[0].r = 1;
    for(int i = 1; i < n ; i ++){
        //从1开始，分数一样则排名相同
        //否则排名为i+1
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



## 3.2 普通hash函数



有时可能需要自己实现hash函数 (选择合适的 10000 值来确保hash函数不会重叠s)

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







递归要考虑的条件是：

1. 递归出口
2. 要保存的条件
3. 岔道口及各个岔道口前进的条件





## 4.2 全排列问题



全排列指 1~n 这些自然数 所能形成的所有排列如



从递归的角度考虑，输出 1~n 这些数字的全排列，可以被分解为如下子问题：

1. 输出1开头的全排列
2. 输出2开头的全排列
3. ...
4. 输出n开头的全排列

在输出x开头的全排列时，问题可以被分解为：

1. 填入x
2. 生成除x以外的数字的全排列



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



如果要保证 输出排列严格按照字典序进行排列， x 应该 从 P[ index - 1] + 1 开始

```c
    for(int x =  P[ index - 1] + 1 ; x <= n; x++){
        if(hashTable[x] == false){
            P[index] = x;   //p[1] = 1 p[1] =2 , p[3] = 3
            hashTable[x] = true;
            generateP(index  + 1);  //generateP(2) generateP(2) generateP(2)
            hashTable[x] = false;
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



下面判断，全排列 `P[1...maxn] `是否为合法的n皇后问题的解

```c
for(int j = i + 1; j <=n;j++){
//判断 (行 - 列) 是否等于 (列 - 行)
if(abs(i - j) == abs(P[i] - P[j])){
flag = false;  //不合法
}
}
```











# 5 贪心

贪心即通过局部最优解来找到全局最优解



## 5.1 一般贪心



## 5.2 区间贪心



区间贪心的一般问题是： 给出 N 个 (x,y) 开区间，选择尽可能多个区间数，使得这几个区间两两不相交。



```
struct interval{
	float x;
	float y
}
```



**总是从左端点最大的区间开始选择，是最优选择，考虑区间相交和区间包含两种情况，无论是(a) 还是 (b) 都应该选择左端点大的那个区间**



[![h7aC8K.png](https://z3.ax1x.com/2021/09/08/h7aC8K.png)](https://imgtu.com/i/h7aC8K)





# 6 二分法





## 6.1 基础





```c
int binarySearch(int A[] , int left , int right, int x){
    while(left <= right){
        int mid = left + ( right - left  /2;
        if (A[mid] == x) return mid;
                          
        if ()

        
        
        
    }
    
}


```

## 6.2 返回第一个比 x大的元素

1. 如果 A[mid] > x ,那么说明 位置在 mid处或者是mid 的左侧
   1. right = mid
2. 如果 A[mid] <= x ，那么说明位置在 mid 右侧
   1. left = mid +1
3. 如果 x 并不存在
   1. 那么就让 left 一直加 1 直到超出区间返回结果





## 6.3 二分应用



二分法应用的条件是： **函数 存在 递增或者递减的关系，需要找到一个至少关系或者一个相等关系**







# 7 two-pointer



## 7.1 归并排序



归并排序基于一个重要的操作： merge ， 将 两个有序的数组合并并且仍然保持有序



```c
const int maxn = 100000;

void merge(int A[], int L1 , int R1 , int L2 , int R2){
    int temp[maxn];
    int i = L1 , j = L2, index= 0 ;
    //当 i < R1, j < R2
    while(i <= R1 && j<=R2){
        //如果 A[i] <= A[j] , index ++  A[i] 放入 temp [index]
        if (A[i] <= A[j]) {temp[index++] = A[i++]; }
        //如果 A[i] > A[j] , index ++ A[j] 放入 temp [index]
        else {temp[index++] = A[j++]; }
    }

    while(i <= R1) {temp[index++] = A[i++]; }
    while(j <= R2) {temp[index++] = A[j++]; }

    for (int k = 0 ; k < index ; k ++){
        A[L1+k] = temp[k];
    }
}
```





在拥有有序操作之后，归并排序的逻辑就很清晰了：

1. 使得数组的 左半边有序
2. 使得数组 右半边有序
3. 再把左右两边合并起来

```c
void merge_sort(int A[] , int left ,int right){
    if(left <  right){
        int mid = (left + right) / 2;
        merge_sort(A , left, mid );
        merge_sort(A ,mid+1, right);
        merge(A , left , mid , mid + 1,right );
    }
}
```





## 7.2 快速排序



快速排序基于一个重要操作： 











# 5 数学问题





## 5.1 







# 6 STL 常用函数



## 6.1 容器





### 注意事项



1. 容器进行函数参数传递时，执行的是深拷贝



### 1. vector



1. vector 定义
2. vector添加元素
   1. push_back(value)
   2. pop_back
   3. insert( it , value)
   4. erase(it) , erase(it1, it2 ) : 删除 [it1 , it2) 间的元素
   5. clear(): 清空元素



### 2. set





set 内部自动递增排序 **只能通过 set<int>::iterator 访问**



1. insert(value): 插入元素
2. find(value): 返回迭代器 , 若不存在返回：  [set::end](https://www.cplusplus.com/set::end)
3. erase(it) , erase(value) , erase( [ it1 ,it2 ) ) 
4. clear(): 清空元素







### 3. 	★string





1. 字典序比较 ： == , != , >= , <=
2. insert : 插入字符
3. erase( ) , erase( pos , length)





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

//奇数
if( n & 1){
//偶数
}else{
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





## 2. 输出注意 添加 endl





在多组数据输入时，大多数情况下，我们输出要添加 `endl `



```c++
cout << res << endl;
```

