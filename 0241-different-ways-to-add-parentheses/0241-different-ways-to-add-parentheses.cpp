class Solution {
public:
    vector<int> diffWaysToCompute(string ex) {
        set<int> val;
        vector<int> temp;
        for(int i=0;i<ex.size();){
            int j=i;
            while(i<ex.size() && ex[i]>='0' && ex[i]<='9'){
                i++;
            }
            temp.push_back(stoi(ex.substr(j,i-j)));
            if(i<ex.size() && (ex[i]=='+' || ex[i]=='-' || ex[i]=='*')){
                temp.push_back(ex[i]);
                i++;
            }
        }
        int i=temp.size();
        auto getans=[&](auto && getans,int i,int j)->vector<int>{
            if(i>j)return {};
            if(i==j)return {temp[i]};
            vector<int> values;
            for(int k=i+1;k<j;k+=2){
                auto a=getans(getans,i,k-1);
                auto b=getans(getans,k+1,j);
                if(temp[k]=='-'){
                    for(auto x:a){
                        for(auto y:b){
                            values.push_back(x-y);
                        }
                    }
                }
                if(temp[k]=='+'){
                    for(auto x:a){
                        for(auto y:b){
                            values.push_back(x+y);
                        }
                    }
                }
                if(temp[k]=='*'){
                    for(auto x:a){
                        for(auto y:b){
                            values.push_back(x*y);
                        }
                    }
                }
            }
            return values;
        };
        return getans(getans,0,temp.size()-1);
    }
};