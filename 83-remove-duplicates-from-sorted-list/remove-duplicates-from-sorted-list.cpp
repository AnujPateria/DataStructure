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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* ans = curr;
        // cout<<curr->val<<" ";
        while(temp->next!=nullptr){
            if(curr->val == temp->next->val){
                temp = temp->next;
                continue;
            }
            curr->next->val = temp->next->val;
            // cout<<curr->next->val<<" ";
            curr=curr->next;

            temp = temp->next;
        }
        curr->next = nullptr;
        // while(curr!= nullptr){
        //     cout<<curr->val<<" ";
        //     curr=curr->next;
            
        // }

        return ans;
    }
};