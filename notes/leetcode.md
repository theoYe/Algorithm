# 算法

题表： https://leetcode-cn.com/study-plan/algorithms/?progress=e044syi

## 二分查找



防止溢出： `mid = left + ( right - left  )/ 2`





### 704. 二分查找



题目连接：https://leetcode-cn.com/problems/binary-search/





###  [278. 第一个错误的版本](https://leetcode-cn.com/problems/first-bad-version/)



此题为 找到 第一个比 x 大的元素的变形，差别在于：

1. 第一个比x大的元素会在 右边 的位置， 因此 `left < right` 即



```c
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int left = 1 , right = n;
        while(left < right){
            //放置溢出
            int mid =  left + (  right - left  ) /2;
            if(isBadVersion(mid)) right = mid;
            else left = mid + 1;            
        }
        return left;
    }
};
```









### [35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/)



目的是找到与`target` 相等的元素

或者找到 target 应该插入的位置



```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0 , right = nums.size();

        while(left<right){
            int mid = (left + (right - left) /2);
            if( nums[mid] == target ) return mid;
            else if ( nums[mid] > target  ) right = mid; 
            else left =  mid + 1;
        }
        return left;
    }
};
```







### 总结







#### 1. 一半

#### 2. 找到比x 小的



1. 只要 right 有可能是答案， 就让 right = mid ,然后让 left 去夹

2. 具体到底是 `left < right` 还是 `left <= right` 要具体情况具体分析。

   

   分析依据是: 以下情况必然出现。

   ```
   A    B    C
   ↑         ↑
   left    right
   
   ```

   





```c
while(left<right){
    int mid = (left + (right - left) /2);
    if( nums[mid] == target ) return mid;
    else if (nums[mid] > target) right = mid; 
    else left =  mid + 1;
}
return left;
}
```







## 双指针





### [977. 有序数组的平方](https://leetcode-cn.com/problems/squares-of-a-sorted-array/)



```c
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int i = 0 , j = nums.size() - 1;
        int index = nums.size() - 1;
        vector<int> res(nums.size());
        while( i <= j){
            while(  i <= j  && nums[i] * nums[i] >= nums[j]*nums[j])  res[index--] = nums[i] *  nums[i++];
            while(  i <= j  && nums[j]*nums[j] >= nums[i]*nums[i]) res[index--] = nums[j] * nums[j--];
        }

         return res;
    }
};
```







位置和值是一一对应的





### [189. Rotate Array](https://leetcode-cn.com/problems/rotate-array/)



三种方法：

1. 元素最后所在的位置都是已知的，新开一个数组依次存放即可

   时间复杂度：$ O(n)$ 

   - 空间复杂度 : $O(n)$

2.  方法1 中使用了一个额外的数组来进行存放，造成了空间浪费，实际上我们只需要 一个 `temp` 变量

   1. 但是有可能会回到原来的位置导致使得数组重置。。我们需要判断多少步会回到原来的位置，答案是 $gcd(k , n)$
      1. 时间复杂度：$O(n)$
      2. 空间复杂度：$O(1)$

3. 将旋转问题看出两个三个问题

   1. 旋转整个数组（使用双指针，易解决）
   2. 旋转数组的前半部分
   3. 旋转数组的后半部分



### [167. Two Sum II - Input array is sorted](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)





### [344. Reverse String](https://leetcode-cn.com/problems/reverse-string/)





### [557. Reverse Words in a String III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

1. 1. 

### [876. Middle of the Linked List](https://leetcode-cn.com/problems/middle-of-the-linked-list/)



### [19. Remove Nth Node From End of List](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)





```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //新建哨兵指针解题 ， 可以省去很多步骤
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        //先移动first
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        //双指针共同移动
        while (first) {
            first = first->next;
            second = second->next;
        }

        //由于建立了哨兵指针，因此 second->next 一定不会是null
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
```







总结





1. 判断条件 (i <= j) 要放前面，否则容易出错 ： ` i <= j  && nums[i] * nums[i]`
2. 旋转等题目要注意 去取余 : ( $  k = k \% n $)





双指针模板：

```
int i = 0 , j = nums.size() - 1;
int index = nums.size() - 1;
vector<int> res(nums.size());
    while( i <= j){
    while(  i <= j  && nums[i] * nums[i] >= nums[j]*nums[j])  res[index--] = nums[i] *  nums[i++];
    while(  i <= j  && nums[j]*nums[j] >= nums[i]*nums[i]) res[index--] = nums[j] * nums[j--];
}
```





旋转字符， 数组：

```
    void reverseString( string & s , int left ,int right){
        while(left < right){
            swap(s[left], s[right] );
            left++;
            right--;
        }
    }

```







## 滑动窗口

### [3. Longest Substring Without Repeating Characters](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)









### [567. Permutation in String](https://leetcode-cn.com/problems/permutation-in-string/)







# C++





初始化：

数组初始化 `int hashStr[256] = {-1};` 只有第一个元素是 -1 ， 要让所有元素都是 -1 ， 必须通过循环设置。

```
int hashStr[256] = {-1};
for (int i = 0; i < 256; i++) 
    hashStr[i] = -1;
```





## cout 输出延迟







