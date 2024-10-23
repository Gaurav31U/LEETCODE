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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*,TreeNode*> par;
        map<TreeNode*,int> val;
        vector<TreeNode*> temp;
        par[root]=NULL;
        while(!q.empty()){
            temp.clear(); 
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                auto tp=q.front();
                q.pop();
                sum+=tp->val;
                val[tp]=tp->val;
                temp.push_back(tp);
                if(tp->left){
                    par[tp->left]=tp;
                    q.push(tp->left);
                }
                if(tp->right){
                    par[tp->right]=tp;
                    q.push(tp->right);
                }
            }
            for(int i=0;i<temp.size();i++){

                int p=sum;
                p-=temp[i]->val;
                if(i+1<temp.size()){
                    if(par[temp[i]]==par[temp[i+1]])p-=val[temp[i+1]];
                }
                if(i>0){
                    if(par[temp[i]]==par[temp[i-1]])p-=val[temp[i-1]];
                }
                temp[i]->val=p;
            }
            cout<<"\n";
        }
        return root;
    }
};