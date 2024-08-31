class Solution {
public:
    vector<int> alt,ct,seg;
    set<pair<int,int>> st;
    int n;
    
    pair<int,int> findGroup(int index){
        auto it=st.upper_bound({index,100000});
        if(it==st.begin()) return {-1,-1};
        it--;
        if(it->first>index || it->first+it->second-1<index) return {-1,-1};
        return *it;
    }
    
    void update(int index, int val){
        for(seg[index+n+1]+=val*(index+2),ct[index+n+1]+=val,index+=n+1;index>1;index>>=1){
            seg[index>>1]=seg[index]+seg[index^1];
            ct[index>>1]=ct[index]+ct[index^1];
        }
    }

    pair<int,int> query(int l, int r){
        r++;
        int x=0,y=0;
        for(l+=n+1,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1){
                x+=seg[l];
                y+=ct[l++];
            }
            if(r&1){
                x+=seg[r-1];
                y+=ct[--r];
            }
        }
        return {x,y};
    }
    
    void flip(int index){
        alt[index]=1-alt[index];
        if(alt[index]==1){
            pair<int,int> g1=findGroup(index-1),g2=findGroup(index+1),x={-1,-1};
            if(g1==x){
                if(g2==x){
                    st.insert({index,1});
                    update(1,-1);
                }
                else{
                    st.erase(g2);
                    update(g2.second,-1);
                    st.insert({index,g2.second+1});
                    update(g2.second+1,1);
                }
            }
            else{
                if(g2==x){
                    st.erase(g1);
                    update(g1.second,-1);
                    st.insert({g1.first,g1.second+1});
                    update(g1.second+1,1);
                }
                else{
                    st.erase(g1);
                    st.erase(g2);
                    update(g1.second,-1);
                    update(g2.second,-1);
                    st.insert({g1.first,g1.second+g2.second+1});
                    update(g1.second+g2.second+1,1);
                }
            }
        }
        else{
            pair<int,int> g=findGroup(index);
            st.erase(g);
            update(g.second,-1);
            if(g.second!=1){
                if(g.first<index){
                    st.insert({g.first,index-g.first});
                    update(index-g.first,1);
                }
                if(g.first+g.second-1>index){
                    st.insert({index+1,g.first+g.second-(index+1)});
                    update(g.first+g.second-(index+1),1);
                }
            }
        }
    }
    
    int altGroups(int val){
        if(st.size()==1 && st.begin()->second==n) return n;
        pair<int,int> ret=query(val-1,n);
        int ans=ret.first-(ret.second*val);

        if(st.size()>=2 && alt[0]==1 && alt[n-1]==1){
            pair<int,int> g1=*st.begin(),g2=*(--st.end());
            if(g1.second>=val-1) ans-=g1.second-val+2;
            if(g2.second>=val-1) ans-=g2.second-val+2;
            if(g1.second+g2.second>=val-1) ans+=g1.second+g2.second-val+2;
        }
        return ans;
    }
    
    vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
        n=colors.size();
        ct.resize(2*(n+1));
        seg.resize(2*(n+1));
        for(int i=0;i<n;++i){
            alt.push_back(colors[i]!=colors[(i+1)%n]);
        }
        for(int i=0;i<n;++i){
            if(alt[i]==0) continue;
            int j=i;
            while(j<n && alt[j]==1){
                j++;
            }
            st.insert({i,j-i});
            update(j-i,1);
            i=j;
        }
        vector<int> ans;
        for(auto& q:queries){
            if(q.size()==2){
                ans.push_back(altGroups(q[1]));
            }
            else{
                if(colors[q[1]]==q[2]) continue;
                colors[q[1]]=q[2];
                flip(q[1]);
                flip((q[1]-1+n)%n);
            }
        }
        return ans;
    }
};