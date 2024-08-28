static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
       auto temp=mat[0];
       for(int i=1;i<mat.size();i++){
           vector<int> vi;
           for(int j=0;j<mat[i].size();j++){
               for(auto it:temp){
                   vi.push_back(it+mat[i][j]);
               }
           }
           sort(vi.begin(),vi.end());
           temp.resize(min(k,int(vi.size())));
           for(int j=0;j<min(k,int(vi.size()));j++){
               temp[j]=vi[j];
           }
       }
       return temp[k-1];
    }
};