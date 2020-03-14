//
// Created by 雷京颢 on 2020/3/14.
//
#include <iostream>


using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* a = nullptr;
        ListNode* b = head;

        while(b->next){
            auto tmp = a;
            a = b;
            b = b->next;
            a->next = tmp;
        }

        b->next = a;
        return b;
    }
};

int main(){
    cout << "" << endl;
}