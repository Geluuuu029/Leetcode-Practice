/*
* Copyright(c) 2021-2021 Geluuuu029 Leetcode Practice
* Author: Geluuuu029
* Date: 2021-07-30
* Description: Leetcode 171. Excel 表列序号 Get excel column name number.

示例 1:

输入: columnTitle = "A"
输出: 1
示例 2:

输入: columnTitle = "AB"
输出: 28
示例 3:

输入: columnTitle = "ZY"
输出: 701
示例 4:

输入: columnTitle = "FXSHRXW"
输出: 2147483647
 

提示：

1 <= columnTitle.length <= 7
columnTitle 仅由大写英文组成
columnTitle 在范围 ["A", "FXSHRXW"] 内

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/excel-sheet-column-number

*/

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    Solution() {};
    ~Solution() {};

    int titleToNumber(string columnTitle);

    void ExecuteBatchCases();

private:
    bool CheckValidCase(string& columnTitle);

    const int kMaxColumnTitleLength = 7; // 最大列名称长度
    const int kCapitalLetterScale = 26; // 大写英文字母进制
    const string kMaxColumnTitle = "FXSHRXW";

};

int Solution::titleToNumber(string columnTitle) {
    int32_t columnNumber = 0;

    int columnTitleLength = columnTitle.length();

    for (int i = 0; i < columnTitleLength; ++i) {
        int singleVal = columnTitle[i] - 'A' + 1;

        columnNumber += singleVal * pow(kCapitalLetterScale, columnTitleLength - i - 1);
    }

    return columnNumber;
}

bool Solution::CheckValidCase(string& columnTitle) {
    int columnTitleLength = columnTitle.length();

    if ((columnTitleLength > kMaxColumnTitleLength) || (columnTitleLength == 0)) {
        return false;
    }

    if (columnTitleLength < kMaxColumnTitleLength) {
        for (auto& singleChar : columnTitle) {
            if (!((singleChar >= 'A') && (singleChar <= 'Z'))) {
                return false;
            }
        }

        return true;
    }

    // check max column number "FXSHRXW"
    for (int i = 0; i < columnTitleLength; ++i) {
        if (columnTitle[i] < kMaxColumnTitle[i]) {
            return true;
        }

        if (columnTitle[i] > kMaxColumnTitle[i]) {
            return false;
        }
    }

    /*

    if (columnTitle[0] < 'F') {
        return true;
    }

    if (columnTitle[0] > 'F') {
        return false;
    }

    if (columnTitle[1] < 'X') {
        return true;
    }

    if (columnTitle[1] > 'X') {
        return false;
    }

    if (columnTitle[2] < 'S') {
        return true;
    }

    if (columnTitle[2] > 'S') {
        return false;
    }

    if (columnTitle[3] < 'H') {
        return true;
    }

    if (columnTitle[3] > 'H') {
        return false;
    }

    if (columnTitle[4] < 'R') {
        return true;
    }

    if (columnTitle[4] > 'R') {
        return false;
    }

    if (columnTitle[5] < 'X') {
        return true;
    }

    if (columnTitle[5] > 'X') {
        return false;
    }

    if (columnTitle[6] < 'W') {
        return true;
    }

    if (columnTitle[6] > 'W') {
        return false;
    }
    */

    return true;
}

void Solution::ExecuteBatchCases() {

    vector<pair<string, int32_t>> testCases = {
        make_pair("a", 1),
        make_pair("909", 1),
        make_pair("A", 1),
        make_pair("Z", 26),
        make_pair("AB", 28),
        make_pair("YZ", 676),
        make_pair("ZY", 701),
        make_pair("ABC", 731),
        make_pair("ABCD", 19010),
        make_pair("ABCDE", 494265),
        make_pair("ABCDEF", 12850896),
        make_pair("ABCDEFG", 334123303),
        make_pair("FFFFFFF", 1927634442),
        make_pair("FXSHRXV", 2147483646),
        make_pair("FXSHRXW", 2147483647),
        make_pair("FXSHRXX", 2147483648)
    };

    for(auto& oneCase : testCases) {
        if (!CheckValidCase(oneCase.first)) {
            cout << "Invalid Test Case ---> " << oneCase.first << ", " << oneCase.second << endl;

            continue;
        }

        int32_t columnNumber = titleToNumber(oneCase.first);

        cout << "Test Case " << ((columnNumber == oneCase.second) ? "Succ" : "Failed")
             << " ---> " << oneCase.first << ", " << oneCase.second 
             << " <--- number is " << columnNumber << endl;

    }
}
    

int main() {

    Solution().ExecuteBatchCases();

    return 0;
}

