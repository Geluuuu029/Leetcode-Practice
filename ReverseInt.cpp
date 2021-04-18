#include <string>
#include <algorithm>
#include <sstream>

#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

const int MIN_INT32 = -2147483648;
const int MAX_INT32 = 2147483647;
const string STR_MIN_INT32 = "2147483648"; // no need minus sign
const string STR_MAX_INT32 = "2147483647";

class Solution {
public:
    Solution() {};
    ~ Solution() {};

    int reverse(int x) {
        //return ReverseInt(x);
        return ReverseIntUsingMath(x);
    }

    int ReverseInt(int x);
    bool GreaterThanINT32(const string& strInt);

    int ReverseIntUsingMath(int x) {
        int rev = 0;
        int tmpX = x;
        while (tmpX != 0) {
            int pop = tmpX % 10;
            tmpX /= 10;

            if ((rev > INT_MAX/10) || ((rev == INT_MAX/10) && (pop > 7))) {
                return 0;
            }
            if ((rev < INT_MIN/10) || ((rev == INT_MIN/10) && (pop < -8))) {
                return 0;
            }

            rev = rev * 10 + pop;
        }

        return rev;
    }

};


int Solution::ReverseInt(int x)
{
    if ((x < MIN_INT32) || (x > MAX_INT32)) {
        cout << "Invalid x is greater than INT32 range." << endl;

        return 0;
    }

    int startPos = 0;
    if (x < 0) {
        startPos = 1;
    }

    string strX = to_string(x);
    string strReverse = strX.substr(startPos, strX.size() - startPos); // remove minus sign temporary
    std::reverse(strReverse.begin(), strReverse.end());

    if (GreaterThanINT32(strReverse)) {
        return 0;
    }

    if (x < 0) {
        strReverse = "-" + strReverse;
    }

    int reverseInt32 = atoi(strReverse.c_str());

    return reverseInt32;
}

bool Solution::GreaterThanINT32(const string& strInt)
{
    int strIntLen = strInt.size();
    if (strIntLen < STR_MIN_INT32.size()) {
        return false;
    }

    if (strIntLen > STR_MAX_INT32.size()) {
        cout << "Invalid x reverse digit nums." << endl;

        return true;
    }

    bool firstGreater = false;

    for (int i = 0; i < strIntLen; ++i) {
        int y1, y2;
        
        stringstream ss;
        ss << strInt[i];
        ss >> y1;
        ss.clear();
        
        ss << STR_MIN_INT32[i];
        ss >> y2;
        ss.clear();

        if (y1 > y2) {
            return true;
        }

        if (y1 < y2) {
            return false;
        }
    }

    return true;
}

void TestReverseInt()
{
    vector<int> testValues = {1534236469, -2147483412, 123, -123, 120, 0, -2147483648, 2147483647, -214748364, 214748364, 9999999, 2000000000};

    for (int i = 0; i < testValues.size(); ++i)
    {
        cout << "Test Result : " << testValues[i] << " reverse to " << Solution().reverse(testValues[i]) << endl;
    }
}

int main()
{
    TestReverseInt();

    cout << "Hello World!" << endl;

    return 0;
}

