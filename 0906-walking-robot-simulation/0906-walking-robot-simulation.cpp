class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0,y=0;
        int dir=0;
        map<int,vector<int>> east,north;
        for(auto it:obstacles){
            east[it[1]].push_back(it[0]);
            north[it[0]].push_back(it[1]);
        }
        int ans=0;
        for(auto &it:east)sort(it.second.begin(),it.second.end());
        for(auto &it:north)sort(it.second.begin(),it.second.end());
        for(auto it:commands){
            if(it>=0){
                if(dir==1){
                    if(east.count(y)){
                        auto tp=upper_bound(east[y].begin(),east[y].end(),x);
                        if(tp==east[y].end()){
                            x+=it;
                        }else{
                            if(x+it>=*tp){
                                x=*tp-1;
                            }else{
                                x+=it;
                            }
                        }
                    }else{
                        x+=it;
                    }
                }else if(dir==0){
                    if(north.count(x)){
                        auto tp=upper_bound(north[x].begin(),north[x].end(),y);
                        if(tp==north[x].end()){
                            y+=it;
                        }else{
                            if(y+it>=*tp){
                                y=*tp-1;
                            }else{
                                y+=it;
                            }
                        }
                    }else{
                        y+=it;
                    }
                }else if(dir==3){
                    if(east.count(y)){
                        auto tp=lower_bound(east[y].begin(),east[y].end(),x);
                        if(tp==east[y].begin()){
                            x-=it;
                        }else{
                            tp--;
                            if(x-it<=*tp){
                                x=*tp+1;
                            }else{
                                x-=it;
                            }
                        }
                    }else{
                        x-=it;
                    }
                }else{
                    if(north.count(x)){
                        auto tp=lower_bound(north[x].begin(),north[x].end(),y);
                        if(tp==north[x].begin()){
                            y-=it;
                        }else{
                            tp--;
                            if(y-it<=*tp){
                                y=*tp+1;
                            }else{
                                y-=it;
                            }
                        }
                    }else{
                        y-=it;
                    }
                }
            }else{
                if(it==-1){
                    dir++;
                }else{
                    dir--;
                }
                dir=(dir+4)%4;
            }
            cout<<x<<" "<<y<<"\n";
            ans=max(ans,x*x+y*y);
        }
        return ans;
    }
};