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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        int cnt=0;
        for(auto it:lists){
            if(it)
            pq.push({it->val,it});
        }
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        while(!pq.empty()){
            temp->next=pq.top().second;
            temp=temp->next;
            auto t=pq.top();
            pq.pop();
            if(t.second->next){
                pq.push({t.second->next->val,t.second->next});
            }
        }
        return ans->next;

    }
};