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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        ListNode* tmp=head;
        int sz=0;
        while(tmp!=NULL){
            tmp=tmp->next;
            sz++;
        }
        int n=sz/k;
        int p=sz%k;
        tmp=head;
        int cnt=0;
        int i=0;
        while(tmp!=NULL){
            cnt++;
            if(cnt==(n+1)){
                ListNode* t=tmp->next;
                tmp->next=NULL;
                ans[i++]=head;
                head=t;
                tmp=t;
                cnt=0;
                p--;
            }else if(p==0 && cnt==n){
                ListNode* t=tmp->next;
                tmp->next=NULL;
                ans[i++]=head;
                head=t;
                tmp=t;
                cnt=0;
                cnt=0;
            }else tmp=tmp->next;
        }
        return ans;
    }
};