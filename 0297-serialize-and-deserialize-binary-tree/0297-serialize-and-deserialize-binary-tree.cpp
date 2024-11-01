/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        auto getans=[&](auto&& getans,TreeNode* root)->void{
            if(root==NULL){
                ans+='N';
                ans+=',';
                return;
            }
            ans+=to_string(root->val);
            ans+=',';
            getans(getans,root->left);
            getans(getans,root->right);
        };
        getans(getans,root);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx=0;
        auto getans=[&](auto&& getans,string& s)->TreeNode*{
            if(idx>=s.size())return NULL;
            if(s[idx]=='N'){
                idx+=2;
                return NULL;
            }
            int j=idx;
            while(s[j]!=',')j++;
            int val=stoi(s.substr(idx,j-idx));
            idx=j+1;       
            TreeNode* root=new TreeNode(val);
            root->left=getans(getans,s);
            root->right=getans(getans,s);
            return root;
        };
        return getans(getans,data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));