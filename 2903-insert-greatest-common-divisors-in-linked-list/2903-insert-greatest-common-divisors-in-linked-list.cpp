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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL)return head;
        ListNode* ans=new ListNode(head->val);
        auto temp1=ans;
        auto temp=head;
        temp=temp->next;
        while(temp!=NULL){
            ListNode* node=new ListNode(__gcd(temp->val,temp1->val));
            temp1->next=node;
            temp1=temp1->next;
            temp1->next=new ListNode(temp->val);
            temp1=temp1->next;
            temp=temp->next;
        }
        return ans;
    }
};