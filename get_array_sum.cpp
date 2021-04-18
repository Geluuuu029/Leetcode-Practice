/*
* Copyright(c) 2021-2021 zhangdong C++ program practice
* Author: zhangdong
* Date: 2021-03-21
* Description: 1480. 一维数组的动态和
*   给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。
*   请返回 nums 的动态和。
*
    示例 1：
    输入：nums = [1,2,3,4]
    输出：[1,3,6,10]
    解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
    
    示例 2：
    输入：nums = [1,1,1,1,1]
    输出：[1,2,3,4,5]
    解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。
    
    示例 3：
    输入：nums = [3,1,2,10,1]
    输出：[3,4,6,16,17]
     

    提示：
    1 <= nums.length <= 1000
    -10^6 <= nums[i] <= 10^6

*
*/

#include <iostream>
#include <vector>


using namespace std;

class GetArraySum {
public:
    GetArraySum() {};
    ~GetArraySum() {};

    vector<int> GetRunningSum(const vector<int>& nums);
};

vector<int> GetArraySum::GetRunningSum(const vector<int>& nums) {
    vector<int> runningSums(nums.size(), 0);

    if (nums.empty()) {
        return runningSums;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (i ==0) {
            runningSums[i] = nums[i];
        } else {
            runningSums[i] += runningSums[i-1] + nums[i];
        }
    }

    return runningSums;
}

int main() {

    vector<vector<int>> testNums = {{1,2,3,4}, {1,1,1,1,1}, {3,1,2,10,1}, {-99999,-99999,-99999,-99999,-99999}};
    
    for(int x = 0; x < testNums.size(); ++x) {
        vector<int> nums = testNums[x];
        vector<int> runningSums = GetArraySum().GetRunningSum(nums);

        
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << " , ";
        }
        cout << endl << "Running Sum is " << endl;

        for (int i = 0; i < runningSums.size(); ++i) {
            cout << runningSums[i] << " , ";
        }

        cout << endl << endl;        
    }

    cout << "Hello World!" << endl;

    return 0;
}

