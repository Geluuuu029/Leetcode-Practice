/*
* Copyright(c) 2021-2021 zhangdong C++ program practice
* Author: zhangdong
* Date: 2021-03-21
* Description: 剑指 Offer 58 - II. 左旋转字符串
*    字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
*    请定义一个函数实现字符串左旋转操作的功能。
*    比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
*
*    示例 1：
*    输入: s = "abcdefg", k = 2
*    输出: "cdefgab"
*
*    示例 2：
*    输入: s = "lrloseumgh", k = 6
*    输出: "umghlrlose"

*    限制：
*    1 <= k < s.length <= 10000
*
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

class ReverseStr {
public:
    ReverseStr() {};
    ~ReverseStr() {};

    string ReverseLeftStr(const string& str, int leftNum);
    string ReverseLeftStrLessMem(const string& str, int leftNum);
    string RotateLeftStr(const string& str, int leftNum);

};

string ReverseStr::ReverseLeftStr(const string& str, int leftNum) {
    if ((leftNum <= 0) || (leftNum > str.size())) {
        return str;
    }

    string leftStr = str.substr(0, leftNum);
    string rightStr = str.substr(leftNum, str.size() - leftNum + 1);
    string reverseLeftStr = rightStr + leftStr;

    return reverseLeftStr;
}

string ReverseStr::ReverseLeftStrLessMem(const string& str, int leftNum) {
    if ((leftNum <= 0) || (leftNum > str.size())) {
        return str;
    }

    string reverseLeftStr = str;
    std::reverse(reverseLeftStr.begin(), reverseLeftStr.begin() + leftNum);
    std::reverse(reverseLeftStr.begin() + leftNum, reverseLeftStr.begin() + reverseLeftStr.size());
    std::reverse(reverseLeftStr.begin(), reverseLeftStr.end());

    return reverseLeftStr;
}

string ReverseStr::RotateLeftStr(const string& str, int leftNum) {
    if ((leftNum <= 0) || (leftNum > str.size())) {
        return str;
    }

    string reverseLeftStr = str;
    std::rotate(reverseLeftStr.begin(), reverseLeftStr.begin() + leftNum, reverseLeftStr.end());

    return reverseLeftStr;
}


int main() {
    vector<pair<string, int>> testStrings = {
            make_pair("abbaca", 2), 
            make_pair("a", 1),  
            make_pair("", 1), 
            make_pair("aaaaaaaa", 3), 
            make_pair("abcdefg",  2), 
            make_pair("lrloseumgh",  6), 
            make_pair("abbcddc",  4), 
            make_pair("abecddceb", 5),
            make_pair("abbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbaca", 20)
    };

    for (int i = 0; i < testStrings.size(); ++i) {
        string newStr = ReverseStr().RotateLeftStr(testStrings[i].first, testStrings[i].second);
        cout << testStrings[i].first << " Reverse left " << testStrings[i].second << " string is " << newStr << endl;
    }

    cout << "Hello World!" << endl;

    return 0;
}

