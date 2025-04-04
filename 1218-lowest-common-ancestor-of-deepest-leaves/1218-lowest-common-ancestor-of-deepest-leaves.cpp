/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*,TreeNode*> par;
        par[root]=NULL;
        vector<TreeNode*> ans,temp;
        while(!q.empty()){
            temp.clear();
            int n=q.size();
            for(int i=0;i<n;i++){
                auto it=q.front();
                temp.push_back(it);
                q.pop();
                if(it->left){
                    par[it->left]=it;
                    q.push(it->left);
                }
                if(it->right){
                    par[it->right]=it;
                    q.push(it->right);
                }
            }
        }
        if(temp.size()<=1)return temp[0];
        map<TreeNode*,int> cnt;
        int m=temp.size();
        for(int i=0;i<m;i++){
            auto a=temp[i];
            while(a!=NULL){
                cnt[par[a]]++;
                a=par[a];
                if(cnt[a]==m)return a;
            }
        }
        return temp[0];

    }
};