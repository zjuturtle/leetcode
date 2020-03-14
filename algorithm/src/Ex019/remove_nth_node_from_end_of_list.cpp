//
// Created by 雷京颢 on 2020/3/14.
//
#include <iostream>
#include <deque>

using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            auto originHead = head;
            deque<ListNode*> queue;
            int count = 0;
            while(head->next) {
                queue.emplace_back(head);
                if (queue.size() > n) {
                    queue.pop_front();
                }
                head = head->next;
            }

            queue.emplace_back(head);
            if (queue.size() == n+1) {
                if (n == 1) {
                    queue[0]->next = nullptr;
                } else {
                    queue[0]->next = queue[2];
                }
                return originHead;
            } else {
                return originHead->next;
            }
        }
    };

int main(){
    cout << "" << endl;
}