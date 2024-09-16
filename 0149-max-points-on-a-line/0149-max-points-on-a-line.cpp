class Solution {
public:
    double slope(double x1,double y1,double x2,double y2){
        if(x2==x1)return INT_MAX;
        double m=(y2-y1)/(x2-x1);
        return m;
    }
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1)return 1;
        int ans=0;
        int n=points.size();
        for(int i=0;i<n;i++){
            map<double,int> mp;
            for(auto it:points){
                if(it==points[i])continue;
                mp[slope(points[i][0],points[i][1],it[0],it[1])]++;
            }
            for(auto it:mp)
                ans=max(ans,it.second+1);
        }
        return ans;
    }
};