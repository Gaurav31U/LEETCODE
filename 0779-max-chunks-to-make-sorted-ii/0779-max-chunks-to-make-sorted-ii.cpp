class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        auto temp=arr;
        sort(temp.begin(),temp.end());
        int ans=0;
        unordered_map<int,int> s1,s2;
        for(int i=0;i<arr.size();i++){
            s1[arr[i]]++;
            s2[temp[i]]++;
            if(s1==s2){
                ans++;
                s1.clear();
                s2.clear();
            }
        }
        return ans;
    }
};