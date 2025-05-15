class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans1,ans2;
        int turn=0,last=-1;
        for(int i=0;i<words.size();i++){
            if(turn==groups[i] && (last==-1 || last!=groups[i])){
                ans1.push_back(words[i]);
                last=turn;
                turn^=1;
            }
        }
        turn=1,last=-1;
        for(int i=0;i<words.size();i++){
            if(turn==groups[i] && (last==-1 || last!=groups[i])){
                ans2.push_back(words[i]);
                last=turn;
                turn^=1;
            }
        }
        if(ans1.size()>ans2.size())return ans1;
        return ans2;
    }

};