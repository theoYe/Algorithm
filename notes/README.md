# 1 基础

## 1.1 输入输出

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


# 3 哈希
## 3.1 字符串哈希


## 3.2 字符+数字的哈希



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