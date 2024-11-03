class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            bool found=false;
            int cnt=0;
            for(int j=0;j<goal.size();j++){
                if(s[(i+j)%s.size()]==goal[j])
                    cnt++;
            }
            if(cnt==s.size())return true;
        }
        return false;
    }
};