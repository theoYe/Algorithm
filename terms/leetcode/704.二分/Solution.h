//
// Created by dell on 2021/9/9.
//

#ifndef RECUR_SOLUTION_H
#define RECUR_SOLUTION_H

#include <vector>

using namespace std;
class Solution {
public:

    int binarySearch(vector<int> & nums , int left ,int right, int target){

        //二分这里是 left <= right
        while(left <= right){
            int mid = (left + right)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums , 0 , nums.size() - 1 , target);
    }
};


#endif //RECUR_SOLUTION_H
