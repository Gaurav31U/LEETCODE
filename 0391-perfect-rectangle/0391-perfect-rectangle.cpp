class Solution {
public:
    void fun(int x,int y,set<pair<int,int>> &st){
        if(st.count({x,y})){
            st.erase(st.find({x,y}));
        }else{
            st.insert({x,y});
        }
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int,int>> st;
        long long area=0;
        for(int i=0;i<rectangles.size();i++){
            int x=rectangles[i][0],y=rectangles[i][1];
            int a=rectangles[i][2],b=rectangles[i][3];
            a-=x;b-=y;
            area+=(a*1ll*b);
            fun(x,y,st);fun(x+a,y,st);
            fun(x,y+b,st);fun(x+a,y+b,st);
        }
        int x=INT_MAX,y=INT_MAX,a=INT_MIN,b=INT_MIN;
        if(st.size()!=4)return false;
        for(auto it=st.begin();it!=st.end();it++){
            x=min(x,it->first);
            y=min(y,it->second);
            a=max(a,it->first);
            b=max(b,it->second);
        }
        if(area!=(a-x)*1ll*(b-y))return false;
        return st.size()==4;
    }
    
};