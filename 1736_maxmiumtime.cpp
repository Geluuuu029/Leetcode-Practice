/*
* Copyright(c) 2021-2021 Geuuuu029 Leetcode Practice
* Author: Geluuuu029
* Date: 2021-07-24
* Description: Leetcode 1736. 替换隐藏数字得到的最晚时间
*
* 
    示例 1：
    输入：time = "2?:?0"
    输出："23:50"
    解释：以数字 '2' 开头的最晚一小时是 23 ，以 '0' 结尾的最晚一分钟是 50 。
    
    示例 2：
    输入：time = "0?:3?"
    输出："09:39"
    
    示例 3：
    输入：time = "1?:22"
    输出："19:22"
     

    提示：
        time 的格式为 hh:mm
        题目数据保证你可以由输入的字符串生成有效的时间

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits

*
*/


#include <string>

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {};
    ~Solution() {};

    string maximumTime(string time);

    bool CheckTimeStringValid(const string& strTime);

    void TestBatchCases();
};

void Solution::TestBatchCases() {
    vector<string> testCases = {"2?:?0", "1?:22", "?1:22", "0?:3?", "01?:31?", "5?:6?", "24:3?", "31:3?", "313?", "31", "??:??"};

    for (auto it = testCases.begin(); it != testCases.end(); ++it) {
        string testTimeString = *it;

        if (!CheckTimeStringValid(testTimeString)) {
            cout << "Invalid time string input --> " << testTimeString << endl;

            continue;
        }

        string maxTimestring = maximumTime(testTimeString);
        cout << "Time string " << testTimeString << " --> max time string is " << maxTimestring << endl;
    }

}

// strTime format is hh:mm.
bool Solution::CheckTimeStringValid(const string& strTime) {
    int timeStrLen = 5; // "hh:mm"
    const char chColon = ':';
    const char chQuestionMark = '?';
    const char chZero = '0';
    const char chOne = '1';
    const char chTwo = '2';
    const char chThree = '3';
    const char chFive = '5';
    const char chNine = '9';

    int lenStrTime = strTime.length();
    if (lenStrTime != timeStrLen) {
        return false;
    }

    if (strTime[2] != chColon) {
        return false;
    }

    int hourH = (int)strTime[0];
    int hourL = (int)strTime[1];
    if ((hourH == (int)chQuestionMark) || (hourH == (int)chZero) || (hourH == (int)chOne)) {
        if ((hourL != (int)chQuestionMark) && ((hourL < (int)chZero) || (hourL > (int)chNine))) {
            return false; // hourL != ?, not in [0,9]
        }
    } else if (hourH == (int)chTwo) {
        if ((hourL != (int)chQuestionMark) && ((hourL < (int)chZero) || (hourL > (int)chThree))) {
            return false;   // hourL != ?, not in [0,3]
        }
    } else {
        return false; // hourH not in [0, 1, 2, ?]
    }  


    int minuteH = (int)strTime[3];
    int minuteL = (int)strTime[4];

    if ((minuteH == (int)chQuestionMark) || ((minuteH >= (int)chZero) && (minuteH <= (int)chFive))) {
        if ((minuteL != (int)chQuestionMark) && ((minuteL < (int)chZero) || (minuteL > (int)chNine))) {
            return false;   // minuteL != ?, not in [0,9]
        }
    } else {
        return false;   // minuteH not in [0,5]
    }

    return true;
}

string Solution::maximumTime(string time) {
    string maxTime = time;

    if (maxTime[0] == '?') {
        maxTime[0] = (('4' <= maxTime[1]) && (maxTime[1] <= '9' )) ? '1' : '2';
    }
    
    if (maxTime[1] == '?') {
        maxTime[1] = (maxTime[0] == '2' ) ? '3' : '9';
    }

    if (maxTime[3] == '?') {
        maxTime[3] = '5';
    }

    if (maxTime[4] == '?') {
        maxTime[4] = '9';
    }

    return maxTime;
}

int main() {

    Solution().TestBatchCases();

    return 0;
}

