/*
* Copyright(c) 2021-2021 Geluuuu029 C++ programing pratice
* Author: Geluuuu029
* Date: 2021-03-14
* Description: 不使用任何内建的哈希表库设计一个哈希映射（HashMap）. according Leetcode programing No.706
*    实现 MyHashMap 类：
*       MyHashMap() 用空映射初始化对象
*       void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
*       int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
*       void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。
*
*       0 <= key, value <= 106
*       最多调用 104 次 put、get 和 remove 方法
*       进阶：你能否不使用内置的 HashMap 库解决此问题？
*/

#include <iostream>
#include <cstdint>
#include <vector>
#include <list>

#include <cstdlib>
#include "PerfTools.h"

using namespace std;

class MyHashMap {
public:
    MyHashMap() : myHashTbl(hashBase) {
    };

    ~MyHashMap() {
        myHashTbl.clear();
    };

    void Put(int32_t key, int32_t value);
    int32_t Get(int32_t key);
    void Remove(int32_t key);

private:
    int32_t HashKey(int32_t key);

private:
    vector<list<pair<int32_t, int32_t>>> myHashTbl;
    static const int32_t hashBase = 973;
};

int32_t MyHashMap::HashKey(int32_t key) {
    return key % hashBase;
}

void MyHashMap::Put(int32_t key, int32_t value) {
    int32_t myHashIdx = HashKey(key);

    for (auto it = myHashTbl[myHashIdx].begin(); it != myHashTbl[myHashIdx].end(); ++it) {
        if ((*it).first == key) {
            (*it).second = value;
            return;
        }
        
    }

    myHashTbl[myHashIdx].push_back(make_pair(key, value));
}

int32_t MyHashMap::Get(int32_t key) {
    int32_t myHashIdx = HashKey(key);

    for (auto it = myHashTbl[myHashIdx].begin(); it != myHashTbl[myHashIdx].end(); ++it) {
        if ((*it).first == key) {
            return (*it).second;
        }
    }

    return -1;
}

void MyHashMap::Remove(int32_t key) {
    int32_t myHashIdx = HashKey(key);

    for (auto it = myHashTbl[myHashIdx].begin(); it != myHashTbl[myHashIdx].end(); ++it) {
        if ((*it).first == key) {
            myHashTbl[myHashIdx].erase(it);
            return;
        }
    }
}

int main()
{
    PerfTool perfCounter;
    perfCounter.StartPerfTool();

    MyHashMap myHashMapInst;

    int32_t  max_my_hash_map_size = 1000000;
    for (int i = 0; i < 10000; ++i) {
        int32_t key = rand() % max_my_hash_map_size;
        int32_t value = rand() % max_my_hash_map_size;

        myHashMapInst.Put(key, value);

        //cout << "key, value is " << key << ", " << myHashMapInst.Get(key) << endl;
    }

    for (int i = 0; i < 10000; ++i) {
        int32_t key = rand() % max_my_hash_map_size;
        int32_t value = myHashMapInst.Get(key);
    }

    perfCounter.EndPerfTool();
    perfCounter.PrintPerfInfo();

    myHashMapInst.Remove(97);
    cout << "key, value is " << 97 << ", " << myHashMapInst.Get(97) << endl;

    cout << "Hello World" << endl;
    
    return 0;
}
