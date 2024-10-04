 static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0,j=skill.size()-1;
        int s=skill[i]+skill[j];
        long long int ans=0;
        while(i<j){
            if(s==skill[i]+skill[j]){
                ans+=(skill[i]*skill[j]);
            }else return -1;
            i++;
            j--;
        }
        return ans;
    }
};