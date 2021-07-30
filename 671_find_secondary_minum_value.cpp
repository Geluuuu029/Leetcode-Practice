/*
* Copyright(c) 2021-2021 Geluuuu029 Leetcode Practice
* Author: Geluuuu029
* Date: 2021-07-27
* Description: Leetcode 671  二叉树中第二小的节点

  示例1：
  输入：root = [2,2,5,null,null,5,7]
  输出：5
  解释：最小的值是 2 ，第二小的值是 5 。

  示例1：
  输入：root = [2,2,2]
  输出：-1
  解释：最小的值是 2, 但是不存在第二小的值。

  提示：
    树中节点数目在范围 [1, 25] 内
    1 <= Node.val <= 2^31 - 1
    对于树中每个节点 root.val == min(root.left.val, root.right.val)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree

*/

#include <vector>
#include <functional>
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};


class Solution {
public:
    Solution() : rootTreeNode_(nullptr), treeNodes_(25, nullptr) {};
    ~Solution() { TestTearDown(); };

    int findSecondMinimumValue(TreeNode* root);

    void TestBatchCases();

private:
    void TestSetup(vector<int>& testCase);
    void TestTearDown();
    void PrintTestCase(vector<int>& testCase);
    void PrintTreeNode(TreeNode* rootNode);

private:
    TreeNode* rootTreeNode_;
    vector<TreeNode*> treeNodes_;
};

int Solution::findSecondMinimumValue(TreeNode* root) {
    int secondMinimumVal = -1;
    int rootValue = root->val;

    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) {
            return;
        }

        if ((secondMinimumVal != -1) && (node->val > secondMinimumVal)) {
            return;
        }

        if (node->val > rootValue) {
            secondMinimumVal = node->val;
        }

        dfs(node->left);
        dfs(node->right);
    };

    dfs(root);

    return secondMinimumVal;
}

void Solution::TestBatchCases() {
    vector<vector<int>> testCases = { 
        {2,2,5,0,0,5,7}, {2,2,2}, {3,3,4,0,0,4,5},
        
        {1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1}
        
    }; //广度优先BFS(Breadth First Search)

    for (auto& testCase : testCases) {
        PrintTestCase(testCase);
        TestSetup(testCase);
        
        cout << "The tree nodes are  ---> {";
        PrintTreeNode(rootTreeNode_);

        int secondMinimumVal = findSecondMinimumValue(rootTreeNode_);

        cout << "find second minimum value ---> " << secondMinimumVal << endl << endl;

        TestTearDown();
    }
}

void Solution::TestSetup(vector<int>& testCase) {
    for (int i = 0; i < testCase.size(); ++i) {
        TreeNode* subNode = nullptr;
        if (testCase[i] != 0) {
            subNode = new TreeNode(testCase[i]);
        }
 
        if (i == 0) {  // root
            rootTreeNode_ = subNode;
            treeNodes_[i] = subNode;

            continue;
        }

        int parentNodeIdx = (i - 1)/2;
        TreeNode* parentNode = treeNodes_[parentNodeIdx];
        if (parentNode == nullptr) {
            cout << "invalid parent node ---> " << i << endl;

            return;
        }

        if (((i - 1) % 2) == 0) {
            parentNode->left = subNode;
        } else {
            parentNode->right = subNode;
        }

        treeNodes_[i] = subNode;
    }
}

void Solution::TestTearDown() {

    for (auto& treeNode : treeNodes_) {
        delete treeNode;
    }

    treeNodes_.clear();

    rootTreeNode_ = nullptr;
}

void Solution::PrintTestCase(vector<int>& testCase) {
    cout << "The testcase is  ---> {";
    for (auto& val : testCase) {
        cout << val << ",";
    }
    cout << "}" << endl << endl; 
}


void Solution::PrintTreeNode(TreeNode* treeNode) {
    if (treeNode == nullptr) {
        cout << "null" << ", ";

        return;
    }

    cout << treeNode->val << ", ";

    PrintTreeNode(treeNode->left);
    PrintTreeNode(treeNode->right);
}


int main() {

    Solution().TestBatchCases();

    return 0;
}