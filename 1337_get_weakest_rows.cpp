/*
* Copyright(c) 2021-2021 Geluuuu029 Leetcode Practice
* Author: Geluuuu029
* Date: 2021-08-01
* Description: Leetcode 137. 矩阵中战斗力最弱的 K 行.

    给你一个大小为 m * n 的矩阵 mat，矩阵由若干军人和平民组成，分别用 1 和 0 表示。

    请你返回矩阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。

    如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。

    军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。


    示例 1：
        输入：mat = 
        [[1,1,0,0,0],
        [1,1,1,1,0],
        [1,0,0,0,0],
        [1,1,0,0,0],
        [1,1,1,1,1]], 
        k = 3
        输出：[2,0,3]
        解释：
        每行中的军人数目：
        行 0 -> 2 
        行 1 -> 4 
        行 2 -> 1 
        行 3 -> 2 
        行 4 -> 5 
        从最弱到最强对这些行排序后得到 [2,0,3,1,4]
    
    示例 2：
        输入：mat = 
        [[1,0,0,0],
         [1,1,1,1],
         [1,0,0,0],
         [1,0,0,0]], 
        k = 2
        输出：[0,2]
        解释： 
        每行中的军人数目：
        行 0 -> 1 
        行 1 -> 4 
        行 2 -> 1 
        行 3 -> 1 
        从最弱到最强对这些行排序后得到 [0,2,3,1]
     

    提示：
        m == mat.length
        n == mat[i].length
        2 <= n, m <= 100
        1 <= k <= m
        matrix[i][j] 不是 0 就是 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-k-weakest-rows-in-a-matrix

*/


#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>
#include <iostream>
#include <cmath>

using namespace std;


class Solution {
public:
    Solution() {};
    ~Solution() {};

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k);

    void ExecuteBatchCases();

private:
    bool CheckTestResult(int k, vector<int>& testResult, vector<int>& expectedTestRst);
    static bool CompareRowForce(pair<int, int> rowForce1, pair<int, int> rowForce2);

};

bool Solution::CompareRowForce(pair<int, int> rowForce1, pair<int, int> rowForce2) {
    return (rowForce1.second < rowForce2.second);
}

vector<int> Solution::kWeakestRows(vector<vector<int>>& mat, int k) {

    vector<pair<int, int>> matRowForces;
    for(int i = 0; i < mat.size(); ++i) {
        matRowForces.push_back(make_pair(i, accumulate(mat[i].begin(), mat[i].end(), 0)));
    }

    //sort(matRowForces.begin(), matRowForces.end(), CompareRowForce);
    sort(matRowForces.begin(), matRowForces.end(), [](pair<int, int> rowForce1, pair<int, int> rowForce2)->bool{
        return ((rowForce1.second < rowForce2.second) || 
               ((rowForce1.second == rowForce2.second) && (rowForce1.first < rowForce2.first)));
    });

    vector<int> weakestRowNumbers;

    for (int j = 0; j < k; ++j) {
        weakestRowNumbers.push_back(matRowForces[j].first);
    }

    return weakestRowNumbers;
}

struct WeakestRowsTestCase {
    vector<vector<int>> mat;
    int k;
    vector<int> kWeakestRowNumbers;
};


void Solution::ExecuteBatchCases() {

    vector<WeakestRowsTestCase> testCases = {
       { {{1,1,0,0,0},
          {1,1,1,1,0},
          {1,0,0,0,0},
          {1,1,0,0,0},
          {1,1,1,1,1}}, 3, {2, 0, 3}}, 

       { {{1,0,0,0},
          {1,1,1,1},
          {1,0,0,0},
          {1,0,0,0}}, 2, {0, 2}}, 
        
       { {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
          {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
          {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
          {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
          {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
          {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
          {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
          {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0}}, 7, {17,21,3,7,12,25,1}},
    };

    for(auto& testCase : testCases) {
        vector<int> weakestRowNumbers = kWeakestRows(testCase.mat, testCase.k);

        if (CheckTestResult(testCase.k, weakestRowNumbers, testCase.kWeakestRowNumbers)) {
            cout << "Test Case succ ---> {";
        }
        else {
            cout << "Test Case failed ---> }";
        }

        for (auto i : weakestRowNumbers) {
            cout << i << ", ";
        }
        cout << "} " << endl;
    }
}

bool Solution::CheckTestResult(int k, vector<int>& testResult, 
                               vector<int>& expectedTestRst) {
    if ((testResult.size() != expectedTestRst.size()) || (testResult.size() != k)) {
        return false;
    }

    for (int i = 0; i < testResult.size(); ++i) {
        if (testResult[i] != expectedTestRst[i]) {
            return false;
        }
    }

    return true;
}




int main() {

    Solution().ExecuteBatchCases();

    return 0;
}
