/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val <= temp2->val){
                ListNode* newNode = temp1;
                curr->next = newNode;
                curr = curr->next;
                temp1 = temp1->next;
            }
            else{
                ListNode* newNode = temp2;
                curr->next = newNode;
                curr = curr->next;
                temp2 = temp2->next;
            }
        }

        while(temp1 != NULL){
            ListNode* newNode = temp1;
            curr->next = newNode;
            curr = curr->next;
            temp1 = temp1->next;
        }

        while(temp2 != NULL){
            ListNode* newNode = temp2;
            curr->next = newNode;
            curr = curr->next;
            temp2 = temp2->next;
        }

        return dummy->next;

    }
};