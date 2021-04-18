/*
* Copyright(c) 2021-2021 Geluuuu029 C++ programing pratice
* Author: Geluuuu029
* Date: 2021-03-14
* Description: 1047. 删除字符串中的所有相邻重复项
*  给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
*  在 S 上反复执行重复项删除操作，直到无法继续删除。
*  在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
*
*  Sample:
*    输入："abbaca"
*    输出："ca"
*    解释：例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。
*          之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
*
*  Tips:
*   1 <= S.length <= 20000
*   S 仅由小写英文字母组成
*
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RmvDuplicateString {
public:
    RmvDuplicateString() {};
    ~RmvDuplicateString() {};

    string RmvDuplicates(const string& str);
    string RmvDuplicatesUsingStack(const string&str);
    
};


string RmvDuplicateString::RmvDuplicates(const string& str) {
    string resultStr = str;

    bool noDuplicates = false;
    while (noDuplicates == false) {
        if (resultStr.empty()) {
            return resultStr;
        }

        for ( int i = 0; i < resultStr.size(); ++i) {
            if ((i + 1) == resultStr.size()) {
                noDuplicates = true;

                break; 
            }

            char tmpChi= resultStr[i];
            char tmpChj= resultStr[i+1];

            if (tmpChi == tmpChj) {
                resultStr.erase(i, 2);

                break;
            }
        }
    }

    return resultStr;
}

string RmvDuplicateString::RmvDuplicatesUsingStack(const string& str) {
    string resultStr;

    for (char ch : str) {
        if ((! resultStr.empty()) && (resultStr.back() == ch)) {
            resultStr.pop_back();
        }
        else {
            resultStr.push_back(ch);
        }
    }

    return resultStr;
}

int main() {

    vector<string> testStrings = {"abbaca", "a", "", "aaaaaaaa", "abba", "abbc", "abbcddc", "abecddceb",
    "abbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbacaabbaca"};

    for (int i = 0; i < testStrings.size(); ++i) {
        string rmvStr = RmvDuplicateString().RmvDuplicates(testStrings[i]);
        cout << testStrings[i] << " remove duplicate str is " << rmvStr << endl;
    }

    cout << endl << endl << "=====================================================================" << endl << endl;
    
    for (int i = 0; i < testStrings.size(); ++i) {
        string rmvStr = RmvDuplicateString().RmvDuplicatesUsingStack(testStrings[i]);
        cout << testStrings[i] << " remove duplicate str is " << rmvStr << endl;
    }

    cout << "Hello World!" << endl;

    return 0;
}
