class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> pre,suf;
        pre.push_back(height[0]);
        for(int i=1;i<height.size();i++){
            pre.push_back(max(pre.back(),height[i]));
        }
        suf.push_back(height.back());
        int ans=0;
        for(int i=height.size()-1;i>=0;i--){
            suf.push_back(max(suf.back(),height[i]));
        }
        reverse(suf.begin(),suf.end());
        for(int i=0;i<height.size();i++){
            ans+=(min(pre[i],suf[i])-height[i]);
        }
        return ans;
    }
};