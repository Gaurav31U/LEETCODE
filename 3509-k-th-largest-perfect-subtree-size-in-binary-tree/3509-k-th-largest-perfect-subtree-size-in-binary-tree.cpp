class Solution {
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        auto get=[&](auto get,TreeNode* node)->int{
            int ans=1;
            if(node==NULL)return 0;
            int l=get(get,node->left);
            int r=get(get,node->right);
            if(l>=0 && l==r){
                ans+=l;
                ans+=r;
                pq.push(ans);
                if(pq.size()>k)pq.pop();
                return ans;
            }
            return -1;
        };
        get(get,root);
        if(pq.size()<k)return -1;
        return pq.top();
    }
};