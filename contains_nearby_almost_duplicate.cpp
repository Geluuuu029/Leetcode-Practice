/*
*   Copyright(c) 2021-2021 Geluuuu029 C++ program practice 
*   Author: Geluuuu029
*   Date: 2021-04-18
*   Description: 220. 存在重复元素 III
*      给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，
*      使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。
*      如果存在则返回 true，不存在返回 false。
*
*      示例 1：
*       输入：nums = [1,2,3,1], k = 3, t = 0
*       输出：true
*      示例 2：
*       输入：nums = [1,0,1,1], k = 1, t = 2
*       输出：true
*      示例 3：
*       输入：nums = [1,5,9,1,5,9], k = 2, t = 3
*       输出：false
*
*      提示：
*        0 <= nums.length <= 2 * 10^4
*        -2^31 <= nums[i] <= 2^31 - 1
*        0 <= k <= 10^4
*        0 <= t <= 2^31 - 1
*
*/


#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {};
    ~Solution() {};

    bool ContainsNearbyAlmostDuplicateNormal(const vector<int>& nums, int k, int t);
    bool ContainsNearbyAlmostDuplicate(const vector<int>& nums, int k, int t);
};

/*
Normal algorighm: 
1. traverse vector, compare prev pos value and current pos value
2. if equal then remove current pos
3. move prev and current pos to next pos
*/
bool Solution::ContainsNearbyAlmostDuplicateNormal(const vector<int>& nums, int k, int t) {


    return true;
}

/*
Fast algorighm: only assign value, not delete pos.
1. traverse vector, compare prev pos value and current pos value
2. if equal then move current pos to next pos
3. if not equal then set current pos value to prev + 1 pos 
4. move prev and current pos to next pos
*/
bool Solution::ContainsNearbyAlmostDuplicate(const vector<int>& nums, int k, int t) {

    return true;
}

int main() {

    vector<vector<int>> testNums = {
        {3,0,   1,2,3,1},
        {1,2,   1,0,1,1},
        {2,3,   1,5,9,1,5,9},
        {0,0}
    };

    for(int x = 0; x < testNums.size(); ++x) {
        int k = testNums[x][0];
        int t = testNums[x][1];

        vector<int> nums(testNums[x].begin() + 2, testNums[x].end());

        bool contained = Solution().ContainsNearbyAlmostDuplicateNormal(nums, k, t);
        cout << "result is : " << contained << endl;
    }

    return 0;
}
