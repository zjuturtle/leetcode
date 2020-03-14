//
// Created by 雷京颢 on 2020/3/14.
//
#include <iostream>
#include <tuple>


using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    struct reverseRes{
        ListNode *head;
    };

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n) {
            return head;
        }
        int i=0;
        ListNode* headOrigin = head;
        ListNode* headBefore = nullptr;
        for (int i=0;i<m-1;i++) {
            headBefore = head;
            head = head->next;
        }

        auto res = reverseList(head, n-m);

        if (headBefore) {
            headBefore->next = res.head;
            return headOrigin;
        } else {
            return res.head;
        }
    }

    reverseRes reverseList(ListNode* head, int length) {
        ListNode* a = nullptr;
        ListNode* b = head;
        ListNode* originHead = head;

        for(int i=0;i<length;i++){
            auto tmp = a;
            a = b;
            b = b->next;
            a->next = tmp;
        }
        originHead->next = b->next;
        b->next = a;
        return reverseRes{b};
    }
};

int main(){
    cout << "" << endl;
}