/*
* Copyright(c) 2021-2021 Geluuuu029 C++ program practice
* Author: Geluuuu029
* Date: 2021-04-18
* Description: 26. 删除有序数组中的重复项
*   给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
*   不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*
*  示例1：
*   输入：nums = [1,1,2]
*   输出：2, nums = [1,2]
*
*  示例2：
*   输入：nums = [0,0,1,1,1,2,2,3,3,4]
*   输出：[0,0,1,1,1,2,2,3,3,4]
*
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {};
    ~Solution() {};

    int RmvDuplicats1(vector<int>& nums);
    int RmvDuplicats(vector<int>& nums);
};

/*
Normal algorighm: 
1. traverse vector, compare prev pos value and current pos value
2. if equal then remove current pos
3. move prev and current pos to next pos
*/
int Solution::RmvDuplicats1(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    auto iter = nums.begin();
    auto prevIter = iter;
    iter++;

    while (iter != nums.end()) {
        if ((*prevIter) == (*iter)) {
            iter = nums.erase(iter);
        } else {
            prevIter = iter;
            iter++;
        }
    }

    return nums.size();
}

/*
Fast algorighm: only assign value, not delete pos.
1. traverse vector, compare prev pos value and current pos value
2. if equal then move current pos to next pos
3. if not equal then set current pos value to prev + 1 pos 
4. move prev and current pos to next pos
*/
int Solution::RmvDuplicats(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int lens = nums.size();
    int prevPos = 0;
    int curPos = 1;
    for (; curPos < lens; ++curPos) {
        if (nums[prevPos] != nums[curPos]) {
            nums[prevPos + 1] = nums[curPos];
            prevPos++;
        }
    }

    return (prevPos + 1);
}

int main() {

    vector<vector<int>> testNums = {
        {0,0,1,1,1,2,2,3,3,4},
        {1,1,2},
        {1},
        {},
        {1,2},
        {1,1},
        {1,1,1},
        {0,0,0,0,0,0,4}
    };

    for(int x = 0; x < testNums.size(); ++x) {
        vector<int> nums = testNums[x];

        int lens = Solution().RmvDuplicats(nums);
        cout << endl << "Remove duplicated nums is : " << lens << " ----> ";
        for (int i = 0; i < lens; ++i) {
            cout << nums[i] << "  ";
        }
    }

    return 0;
}
