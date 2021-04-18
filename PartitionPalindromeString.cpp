
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "PerfTools.h"

using namespace std;

class Solution {
public:
    Solution() : strLen_(0) {};
    ~Solution() {};

    /* Partition the strA as some Palindromic string, and return all the possible results.*/
    vector<vector<string>> PartitionString(string str);

private:
    void PreProcessPalindromicRel(const string& str);
    void RecursePartitionString(const string& str, int iterNum);

private:
    vector<vector<int>> palindromicRel_;
    vector<string> matchRets_;
    vector<vector<string>> palindromicStrings_;
    int strLen_;
};


bool PalindromicStringCheck(string& strChk)
{
    string strReverse = strChk;
    reverse(strReverse.begin(), strReverse.end());

    int rel = strReverse.compare(strChk);

    return (rel == 0);
}

vector<vector<string>> RecursePartitionString(string strA)
{
    vector<vector<string>> palindromicStrings;

    string strTemp = strA;
    int strNum = strTemp.size();

    int partitionLen = 1;
    while (partitionLen <= strNum) {
        string curStr = strTemp.substr(0, partitionLen);
        if (PalindromicStringCheck(curStr)) {
            if (partitionLen == strNum) {
                vector<string> tmpStrings;
                tmpStrings.push_back(curStr);
                palindromicStrings.push_back(tmpStrings);

                break;
            }

            string leftStr = strTemp.substr(partitionLen, strNum - partitionLen);
            vector<vector<string>> retPalindromicStrs = RecursePartitionString(leftStr);

            for (int i = 0; i < retPalindromicStrs.size(); ++i) {
                vector<string> leftPartitionStrings = retPalindromicStrs[i];
                leftPartitionStrings.insert(leftPartitionStrings.begin(), curStr);

                palindromicStrings.push_back(leftPartitionStrings);
            }
        }

        partitionLen++;
    }

    return palindromicStrings;
}

vector<vector<string>> Solution::PartitionString(string str)
{
    PreProcessPalindromicRel(str);

    RecursePartitionString(str, 0);

    return palindromicStrings_;
}

void Solution::PreProcessPalindromicRel(const string& str)
{
    strLen_ = str.size();
    palindromicRel_.assign(strLen_, vector<int>(strLen_, true));

    for (int i = strLen_ - 1; i >= 0; --i) {
        for (int j = i + 1; j < strLen_; ++j) {
            palindromicRel_[i][j] = palindromicRel_[i + 1][j - 1] && (str[i] == str[j]);
        }
    }
}

void Solution::RecursePartitionString(const string& str, int i)
{
    if (i == strLen_) {
        palindromicStrings_.push_back(matchRets_);

        return;
    }

    for (int j = i; j < strLen_; ++j) {
        if (palindromicRel_[i][j]) {
            matchRets_.push_back(str.substr(i, j - i + 1));
            RecursePartitionString(str, j + 1);
            matchRets_.pop_back();
        }
    }
}


void TestPartitionStrings(string& str)
{
    PerfTool perfCounter;
    perfCounter.StartPerfTool();

    vector<vector<string>> palindRomicStrings = Solution().PartitionString(str);

    perfCounter.EndPerfTool();
    perfCounter.PrintPerfInfo();

    for (int i = 0; i < palindRomicStrings.size(); ++i) {
        vector<string> subStrings = palindRomicStrings[i];
        cout << "Result " << i << " : ";
        for (int j = 0; j < subStrings.size(); ++j) {
            cout << subStrings[j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string strA = "aab"; // result [aa, b], [a,a,b]
    string strB = "aabbcccnoonlevel"; // result [aa, bb, ccc, noon, level], [a,a,b,b,c,c,c,n,o,o,n,l,e,v,e,l]

    cout << "<<<<< Test Start >>>>>>" << endl;

    TestPartitionStrings(strA);
    
    cout << "----------------------------" << endl;
    cout << "----------------------------" << endl;

    TestPartitionStrings(strB);

    cout << "<<<<< Test End >>>>>>" << endl;

    cout << "Hello World" << endl;

    return 0;
}

