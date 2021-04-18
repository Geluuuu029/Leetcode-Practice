#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {};
    ~ Solution() {};

    bool isPalindrome(int x);

};


/* check whether x is a palindrome integer. 
such as 121, 1001, etc*/
bool Solution::isPalindrome(int x)
{
    if ((x < 0) || ((x % 10 == 0) && (x != 0))) {
        return false;
    }

    int revertNum = 0;
    while (x > revertNum) {
        revertNum = revertNum * 10 + x % 10;
        x = x /10;
    }

    return (x == revertNum) || (x == revertNum/10);
}

int main()
{
    vector<int> X = {121, 0, 1, 2112, 10, -121, 10000001, 999998, 989989, INT_MIN, INT_MAX};
    for (int i = 0; i < X.size(); ++i) {
        cout << X[i] << " is " << boolalpha << Solution().isPalindrome(X[i]) << " palindrome integer." << endl;
    }
    
    
    cout << "Hello World!" << endl;
    
    return 0;
}
