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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> ans(n,vector<int>(m,-1));
        int i=0,j=0,tp=0,u=0,d=n,l=0,r=m;
        while(head!=NULL){
            ans[i][j]=head->val;
            if(tp==0){
                j++;
                if(j==r){
                    i++;j--;tp=1;u++;
                }
            }else if(tp==1){
                i++;
                if(i==d){
                    i--;tp=2;r--;j--;
                }
            }else if(tp==2){
                j--;
                if(j<l){
                    j++;tp=3;d--;i--;
                }
            }else if(tp==3){
                i--;
                if(i<u){
                    i++,j++;tp=0;l++;
                }
            }
            head=head->next;
        }
        return ans;
    }
};