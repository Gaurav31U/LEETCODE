class Solution {
public:
    long long makeSimilar(vector<int>& v, vector<int>& t) {
    long long ans=0;
    vector<int> vv[2], tt[2];
    for (int d: v) 
        vv[d%2].push_back(d);
    for (int d: t) 
        tt[d%2].push_back(d);
    for (int i=0; i<2; ++i) {            
        sort(vv[i].begin(), vv[i].end());
        sort(tt[i].begin(), tt[i].end());
    }
    long long  sum=0;
    for (int i=0; i<2; ++i)
        for (int j=0; j<vv[i].size(); j++)
            sum+=abs(tt[i][j]-vv[i][j]);
    return sum/4;
    }
};