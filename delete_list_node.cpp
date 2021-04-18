/*
* Copyright(c) 2021-2021 Geluuuu029 C++ program practice
* Author: Geluuuu029
* Date: 2021-03-21
* Description: 面试题 02.03. 删除中间节点
*    实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。
*
*    示例：
*    输入：单向链表a->b->c->d->e->f中的节点c
*    结果：不返回任何数据，但该链表变为a->b->d->e->f
*
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curNode = node; //c
        ListNode* nextNode = curNode->next; //d

        if (nextNode == NULL) {
            return;
        }

        curNode->val = nextNode->val; // c.val change to d.val
        curNode->next = nextNode->next; // c next change to e
        delete (nextNode);
    }
};

void printListNodes(vector<ListNode*>& myListNodes) {
    ListNode* headNode = myListNodes[0];
    while (headNode != NULL) {
        cout << headNode->val << " , ";
        headNode = headNode->next;
    }
}

int main() {
    vector<ListNode*> myListNodes;

    vector<int> nodeVals = {1,2,3,4,5};
    for (int i = 0; i < nodeVals.size(); ++i) {
        int val = nodeVals[i];

        ListNode* curNode = new ListNode(val);
        myListNodes.push_back(curNode);
    }

    for (int j = 0; j < myListNodes.size(); ++j) {
        ListNode* curNode = myListNodes[j];

        if ( (j + 1) < myListNodes.size()) {
            ListNode* nextNode = myListNodes[j+1];
            curNode->next = nextNode;
        }
    }

    printListNodes(myListNodes);
    
    ListNode* rmvNode = myListNodes[3]; // last ele how to dele
    cout << "Ready remove " << rmvNode->val << endl;
    Solution().deleteNode(rmvNode);

    printListNodes(myListNodes);
    
    cout << "Hello World!" << endl;

    return 0;
}
