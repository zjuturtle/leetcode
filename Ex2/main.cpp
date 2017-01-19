#include<iostream>
#include<vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        return addTwoNumbers(l1, l2, 0);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carryBit) {
        if (NULL == l1 && NULL == l2 && carryBit == 0)
            return NULL;
        
        int val = (l1 == NULL? 0 : l1->val) + (l2 == NULL? 0 : l2->val) + carryBit;
        int carryBitNow = 0;
        if (val >= 10) {
            carryBitNow = val / 10;
            val = val % 10;
        }
        ListNode* res = new ListNode(val);
        res->next = addTwoNumbers((l1==NULL?NULL:l1->next), (l2==NULL?NULL:l2->next), carryBitNow);
        return res;
    }
};

int main() {
	Solution s;
	ListNode* l1 = new ListNode(5);
    //l1->next = new ListNode(4);
    //l1->next->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    //l2->next = new ListNode(6);
    //l2->next->next = new ListNode(4);
    //l2->next->next->next = new ListNode(4);
    
    ListNode* now = s.addTwoNumbers(l1 ,l2);
    while (now != NULL) {
        cout<<now->val<<" ";
        now = now->next;
    }
    
	getchar();
	return 0;
}
