
#include <vector>
#include <iostream>
#include <stack>

#include "PerfTools.h"

using namespace std;

class Solution {
public:
    Solution() {};
    ~Solution() {};

    vector<int> nextGreaterElements(vector<int>& nums) {
        int numsLen = nums.size();
        vector<int> nextGreaterNums(numsLen);
        
        for (int i = 0; i < numsLen; ++i) {
            int j = i + 1;
            bool notEnd = true;
            while (notEnd) {
                if (j == numsLen) {
                    j = 0;
                }

                if (j == i) {
                    nextGreaterNums[i] = -1;
                    notEnd = false;
                } else if (nums[j] > nums[i]) {
                    nextGreaterNums[i] = nums[j];
                    notEnd = false;
                } else {
                    j++;
                }
            }
        }

        return nextGreaterNums;
    }

    vector<int> nextGreaterEleUsingMonotoneStack(vector<int>& nums) {

        int numsLen = nums.size();
        if (numsLen == 0) {
            return {};
        }

        int loopVectorLenth = numsLen*2 -1;
        vector<int> nextGreaterNums(numsLen, -1);

        stack<int> monotoneStack;

        for (int i = 0; i < loopVectorLenth; ++i) {
            while ((!monotoneStack.empty()) && (nums[monotoneStack.top()] < nums[i % numsLen]) ) {
                nextGreaterNums[monotoneStack.top()] = nums[i % numsLen];
                monotoneStack.pop();
            }

            monotoneStack.push(i % numsLen);
        }

        return nextGreaterNums;
    }
};


int main()
{
    PerfTool perfCounter;
    perfCounter.StartPerfTool();

    vector<int> nums = {1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,
    1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,
    1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,
    1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95,1, 2, 5, 96, 100, 98, 97, 96, 95};
    // vector<int> nextGreaterNums = Solution().nextGreaterElements(nums);

    vector<int> nextGreaterNums = Solution().nextGreaterEleUsingMonotoneStack(nums);

    perfCounter.EndPerfTool();
    perfCounter.PrintPerfInfo();

    for (int i = 0; i < nextGreaterNums.size(); ++i) {
        cout << nextGreaterNums[i] << " ";
    }

    cout << endl <<  "Hello world!" << endl;
}
