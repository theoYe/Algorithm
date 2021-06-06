

# 1 简介

Sorts 函数第三个参数可以传递， 可以不传， 如果不传，必须对类编写"<"赋值运算符重载
## 数值范围

仍然是一个 前闭合后开的区间：  [first,last)
如果是数组， 那么就是 [start, start+ 数组长度)

## 1.1 写

## 1.2 不写



## 比较函数示例

1. 数字的比较
如果要排序后从大到到小排列：

```c++
    cmp(const Testee&  t1,const  Testee& t2){
        return t1.score > t2.score;  //按准考证号从小到大排序
    }
```

2. 如果要排序后按照字母顺序升序排列
```c++
    cmp(const Testee&  t1,const  Testee& t2){
        return strcmp(t1.reg_number, t2.reg_number) < 0;  //按准考证号从小到大排序
    }
```

3. 综合：
如果分数一样按照分数从高到底排序（降序）， 如果分数一样，按照准考证号从小到大(升序)排序

```c++
    testee_cmp(const Testee&  t1,const  Testee& t2){
        if (t1.score != t2.score) return t1.score > t2.score;  //按分数从高到低排序
        else return strcmp(t1.reg_number, t2.reg_number) < 0;  //按准考证号从小到大排序
    }
```