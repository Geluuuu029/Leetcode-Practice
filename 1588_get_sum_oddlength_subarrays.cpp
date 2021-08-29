/*
* Copyright(c) 2021-2021 Geluuuu029 Leetcode Practice
* Author: Geluuuu029
* Date: 2021-08-29
* Description: Leetcode 1588 get sum odd length of sub arrays.
* 给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。
* 子数组 定义为原数组中的一个连续子序列。
* 请你返回 arr 中 所有奇数长度子数组的和 。

    示例 1：

    输入：arr = [1,4,2,5,3]
    输出：58
    解释：所有奇数长度子数组和它们的和为：
    [1] = 1
    [4] = 4
    [2] = 2
    [5] = 5
    [3] = 3
    [1,4,2] = 7
    [4,2,5] = 11
    [2,5,3] = 10
    [1,4,2,5,3] = 15
    我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
    
    示例 2：

    输入：arr = [1,2]
    输出：3
    解释：总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。
    
    示例 3：

    输入：arr = [10,11,12]
    输出：66
     

    提示：

    1 <= arr.length <= 100
    1 <= arr[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays

*/

#include <vector>
#include <numeric>
#include <iostream>
#include <windows.h>

using namespace std;

class GetSumOddLengthSubarrays {
public:
    GetSumOddLengthSubarrays() {};
    ~ GetSumOddLengthSubarrays() {};

    int sumOddLengthSubarrays_bruteForce(vector<int>& arr);
    int sumOddLengthSubarrays_prefixSum(vector<int>& arr);
    int sumOddLengthSubarrays_mathematics(vector<int>& arr);

    void ExecuteBatchCases();
};

/*
* 暴力求解法:  空间复杂度最优O(1), 时间复杂度最差O(n^3)
*/
int GetSumOddLengthSubarrays::sumOddLengthSubarrays_bruteForce(vector<int>& arr) {
    int arrLength = arr.size();

    int sumValue = 0;

    for (int startPos = 0; startPos < arrLength; startPos++) {
        for (int oddLen = 1; (startPos + oddLen) <= arrLength; oddLen += 2) {
            int endPos = startPos + oddLen - 1;

            for (int i = startPos; i <= endPos; ++i) {
                sumValue += arr[i];    
            }
        }
    }
    
    return sumValue;
}

/*
* 前缀和法:  空间复杂度次O(n), 时间复杂度次差O(n^2)
*/
int GetSumOddLengthSubarrays::sumOddLengthSubarrays_prefixSum(vector<int>& arr) {
    int arrLength = arr.size();

    vector<int> prefixSums; // 数组前缀和
    prefixSums.resize(arrLength + 1);

    for(int i = 0; i < arrLength; ++i) {
        prefixSums[i + 1] = prefixSums[i] + arr[i];
    }

    int sumValue = 0;

    for (int startPos = 0; startPos < arrLength; startPos++) {
        for (int oddLen = 1; (startPos + oddLen) <= arrLength; oddLen += 2) {
            int endPos = startPos + oddLen - 1;
            sumValue += prefixSums[endPos + 1] - prefixSums[startPos];    
        }
    }
    
    return sumValue;
}

/*
* 数学法:  空间复杂度最优O(1), 时间复杂度最优O(n)
*/
int GetSumOddLengthSubarrays::sumOddLengthSubarrays_mathematics(vector<int>& arr) {
    int arrLength = arr.size();
    int sumValue = 0;
    
    // 通过数学方法计算每个元素i 在奇数子数组中出现的次数
    for(int i = 0; i < arrLength; ++i) {
        int leftCount = i;
        int rightCount = arrLength - i - 1;

        // 元素i 左边和右边的元素个数都是奇数
        int leftOddNumber = (leftCount + 1)/2;
        int rightOddNumber = (rightCount + 1)/2;

        // 元素i 左边和右边的元素个数都是偶数
        int leftEvenNumber = leftCount/2 + 1;
        int rightEvenNumber = rightCount/2 + 1;

        // 元素i 出现在奇数子数组的次数可以计算出来，然后直接求和
        sumValue += arr[i] * (leftOddNumber * rightOddNumber + leftEvenNumber * rightEvenNumber);
    }
    
    return sumValue;
}

struct RowsTestCase {
    vector<int> arr;
    int sumVal;
};

void GetSumOddLengthSubarrays::ExecuteBatchCases() {

    vector<RowsTestCase> testCases = {
        {{1,4,2,5,3}, 58},
        {{1,2}, 3},
        {{10,11,12}, 66},
        {{1}, 1},
        {{}, 0},
        {{11,12,24,37,49,87,83,703,999}, 14072}

    };

    for(auto& testCase : testCases) {
        int sumValOddSubarrays = sumOddLengthSubarrays_mathematics(testCase.arr);
        if (sumValOddSubarrays == testCase.sumVal) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout << "Test Case succ!! ---> " << testCase.sumVal << ", " << sumValOddSubarrays << endl;
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << "Test Case failed ---> " << testCase.sumVal << ", " << sumValOddSubarrays << endl;
        }
   }

   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 
                                                            FOREGROUND_RED | 
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_BLUE);
}

int main() {

    GetSumOddLengthSubarrays().ExecuteBatchCases();

    return 0;
}



