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
private:
    static const int N = 1e5 + 5;
public:
    int dfs(TreeNode* root, int currLvl, vector<int>& lvl, vector<int>& mxPath, vector<vector<int>>& adj) {
        if(!root) return currLvl - 1;
        lvl[root->val] = currLvl;
        int l = dfs(root->left, currLvl + 1, lvl, mxPath, adj);
        int r = dfs(root->right, currLvl + 1, lvl, mxPath, adj);
        mxPath[root->val] = max(l, r);
        if(mxPath[root->val] >= adj[currLvl][1]) {
            adj[currLvl][0] = adj[currLvl][1];
            adj[currLvl][1] = mxPath[root->val];
        }
        else if(mxPath[root->val] > adj[currLvl][0])
            adj[currLvl][0] = mxPath[root->val];
        return mxPath[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> lvl(N, -1), mxPath(N, -1);
        vector<vector<int>> adj(N, vector<int>(2, -1));
        int height = dfs(root, 0, lvl, mxPath, adj);
        vector<int> res;
        for(int &query:queries) {
            if(mxPath[query] != height) res.push_back(height);
            else {
                if(adj[lvl[query]][0] != -1) res.push_back(adj[lvl[query]][0]);
                else res.push_back(lvl[query] - 1);
            }
        }
        return res;
    }
};