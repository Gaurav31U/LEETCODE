vector<string> val[10];
class Solution {
public:
    constexpr void fun(){
        for(int j=1;j<=9;j++){
            string s = "";
            for(int i=1; i<=j; i++){
                s += char(i + '0');  
            }
            val[j].push_back(s);    
            while(next_permutation(s.begin(), s.end())) {
                val[j].push_back(s); 
            }
        }
    }

    string getPermutation(int n, int k) {
        if(val[1].empty())fun();
        return val[n][k-1];  // Return the k-th permutation (1-based index)
    }
};