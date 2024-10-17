 static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maximumSwap(int num) {
        string ans="";
        int val=num;
        while(num>0){
            ans+=char('0'+num%10);
            num/=10;
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            for(int j=i+1;j<ans.size();j++){
                swap(ans[i],ans[j]);
                val=max(val,stoi(ans));
                swap(ans[i],ans[j]);
            }
        }
        return val;
    }
};