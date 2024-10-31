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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto getans=[&](auto getans,ListNode* temp)->ListNode*{
            if(temp==NULL)return NULL;
            int c=k;
            vector<ListNode*> ans;
            ListNode* temp1=temp;
            while(temp1 && c>0){
                ans.push_back(temp1);
                temp1=temp1->next;
                c--;
            }
            reverse(ans.begin(),ans.end());
            if(c==0){
                for(int i=0;i<ans.size()-1;i++){
                    ans[i]->next=ans[i+1];
                }
                ans.back()->next=getans(getans,temp1);
                return ans[0];
            }
            return temp;
        };
        return getans(getans,head);
    }
};