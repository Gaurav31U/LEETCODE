class Solution {
public:
    string countOfAtoms(string formula) {
        // map<string,int> mp;
        int n=formula.size();
        stack<pair<string,int>> st;


        auto get=[&](auto&& get,string s)->map<string,int>{
            if(s.empty())return {};
            map<string,int> mp;
            for(int i=0;i<s.size();){
                string temp="";
                if(i<n && (s[i]>='A' && s[i]<='Z')){
                    temp+=s[i];
                    i++;
                    while(i<n && s[i]>='a' && s[i]<='z'){
                        temp+=s[i];
                        i++;
                    }
                }
                map<string,int> val;
                if(s[i]=='('){
                    int cnt=0;
                    int from=i+1;
                    while(i<s.size()){
                        if(s[i]=='(')cnt++;
                        if(s[i]==')'){
                            cnt--;
                            if(cnt==0)break;
                        }
                        i++;
                    }
                    int to=i-1;
                    i++;
                    val=get(get,s.substr(from,to-from+1));
                }
                string num="";
                while(i<s.size() && s[i]>='0' && s[i]<='9'){
                    num+=s[i];
                    i++;
                }
                if(num.empty()){
                    if(!temp.empty())
                    mp[temp]++;
                    if(!val.empty())
                    for(auto it:val)mp[it.first]+=it.second;
                }else{
                    auto t=stoi(num);
                    if(val.empty()){
                        if(!temp.empty())mp[temp]+=t;
                    }else if(!temp.empty())mp[temp]++;
                    if(!val.empty())
                    for(auto it:val)mp[it.first]+=(it.second*t);
                }
            }
            return mp;
        };

        string ans="";
        auto mp=get(get,formula);
        for(auto it:mp){
            ans+=it.first;
            if(it.second>1)ans+=to_string(it.second);
        }
        return ans;
    }
};