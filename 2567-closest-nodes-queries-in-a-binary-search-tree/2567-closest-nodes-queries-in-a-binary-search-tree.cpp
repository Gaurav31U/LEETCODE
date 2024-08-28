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
class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(-1);
        auto dfs=[&](auto&& dfs,TreeNode* node)->void{
            if(node==NULL)return;
            dfs(dfs,node->left);
            temp.push_back(node->val);
            dfs(dfs,node->right);
        };
        dfs(dfs,root);
        for(auto it:queries){
            int mn=*(--lower_bound(temp.begin(),temp.end(),it+1));
            auto tp=lower_bound(temp.begin(),temp.end(),it);
            int mx;
            if(tp==temp.end())mx=-1;
            else mx=*tp;

            ans.push_back({mn,mx});
        }
        return ans;
    }
};