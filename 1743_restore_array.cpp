/*
* Copyright(c) 2021-2021 Geluuuu029 Leetcode Practice
* Author: Geluuuu029
* Date: 2021-07-25
* Description: Leetcode 1743  从相邻元素对还原数组
    
    示例 1：

    输入：adjacentPairs = [[2,1],[3,4],[3,2]]
    输出：[1,2,3,4]
    解释：数组的所有相邻元素对都在 adjacentPairs 中。
    特别要注意的是，adjacentPairs[i] 只表示两个元素相邻，并不保证其 左-右 顺序。
    示例 2：

    输入：adjacentPairs = [[4,-2],[1,4],[-3,1]]
    输出：[-2,4,1,-3]
    解释：数组中可能存在负数。
    另一种解答是 [-3,1,4,-2] ，也会被视作正确答案。
    示例 3：

    输入：adjacentPairs = [[100000,-100000]]
    输出：[100000,-100000]
     

    提示：

    nums.length == n
    adjacentPairs.length == n - 1
    adjacentPairs[i].length == 2
    2 <= n <= 105
    -105 <= nums[i], ui, vi <= 105
    题目数据保证存在一些以 adjacentPairs 作为元素对的数组 nums

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {};
    ~Solution() {};

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs);

    void TestBatchCases();

    void PrintTestResult(vector<vector<int>>& adjacentPairs, vector<int>& restoredArray);

};

vector<int> Solution::restoreArray(vector<vector<int>>& adjacentPairs) {
    unordered_map<int, vector<int>> adjacentMap;
    for (auto& adjacentPair : adjacentPairs) {
        adjacentMap[adjacentPair[0]].push_back(adjacentPair[1]);
        adjacentMap[adjacentPair[1]].push_back(adjacentPair[0]); 
    }
    
    int restoredArrayLen = adjacentPairs.size() + 1;
    vector<int> restoredArray(restoredArrayLen);

    for (auto& pairVal : adjacentMap) {
        if (pairVal.second.size() == 1) {
            restoredArray[0] = pairVal.first;
            break;
        }
    }

    restoredArray[1] = adjacentMap[restoredArray[0]][0];

    for (int i = 2; i < restoredArrayLen; ++i) {
        vector<int>& firstValPairs = adjacentMap[restoredArray[i - 1]];

        restoredArray[i] = (firstValPairs[0] == restoredArray[i - 2]) ? firstValPairs[1] : firstValPairs[0];
    }

    return restoredArray;
}

void Solution::TestBatchCases() {
    vector<vector<vector<int>>> testCases = {
        {{2,1}, {3,4}, {3,2}},
        {{4,-2}, {1,4}, {-3,1}},
        {{100000,-100000}}
    };

    for (auto it = testCases.begin(); it != testCases.end(); ++it) {
        vector<vector<int>> adjacentPairs = *it;

        vector<int> restoredArray = restoreArray(adjacentPairs);
        PrintTestResult(adjacentPairs, restoredArray);
    }
}

void Solution::PrintTestResult(vector<vector<int>>& adjacentPairs, vector<int>& restoredArray) {
    cout << endl << "The adjacent pairs --> {";
    for(auto it = adjacentPairs.begin(); it != adjacentPairs.end(); ++it) {
        cout << "{";
        for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
            cout << *it2 << ",";
        }
        cout << "}";
    }

    cout << "}" << endl;

    cout << "The restored array ---> {";
    for (auto it3 = restoredArray.begin(); it3 != restoredArray.end(); ++it3) {
        cout << *it3 << ",";
    }
    cout << "}" << endl << endl; 
}

int main() {
    Solution().TestBatchCases();

    return 0;
}
