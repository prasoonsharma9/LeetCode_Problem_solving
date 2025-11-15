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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        while(head && st.count(head->val)) head = head->next;

        ListNode* current = head;
        while(current && current->next){
            while(current->next && st.count(current->next->val)){
                current->next = current->next->next;
            }
            current = current->next;
        }
        return head;
    }
};