class Solution {
public:
    vector<int> solve(vector<vector<int>> &points,int idx){
        vector<int> res(3,-1);
        pair<int,int> minsum={-1,INT_MAX},maxsum={-1,INT_MIN};
        pair<int,int> mindiff={-1,INT_MAX},maxdiff={-1,INT_MIN};
        for(int i=0;i<points.size();i++){
            if(i==idx)continue;
            int s=points[i][0]+points[i][1];
            int d=points[i][0]-points[i][1];
            if(s>maxsum.second)maxsum.first=i,maxsum.second=s;
            if(s<minsum.second)minsum.first=i,minsum.second=s;
            if(d>maxdiff.second)maxdiff.first=i,maxdiff.second=d;
            if(d<mindiff.second)mindiff.first=i,mindiff.second=d;
        }
        if(maxsum.second-minsum.second>maxdiff.second-mindiff.second){
            res[0]=maxsum.second-minsum.second;
            res[1]=minsum.first,res[2]=maxsum.first;
        }else{
            res[0]=maxdiff.second-mindiff.second;
            res[1]=mindiff.first,res[2]=maxdiff.first;
        }
        return res;
    }
    int minimumDistance(vector<vector<int>>& points) {
        auto res=solve(points,-1);
        return min(solve(points,res[1])[0],solve(points,res[2])[0]);
    }
};