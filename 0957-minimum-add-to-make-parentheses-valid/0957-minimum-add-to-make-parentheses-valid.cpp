class Solution {
public:
    int minAddToMakeValid(string s) {
        int l=0,r=0;
        for(auto it:s){
            if(it=='('){
                l++;
            }else{
                if(l>0){
                    l--;
                }else{
                    r++;
                }
            }
        } 
        return l+r;
    }

};