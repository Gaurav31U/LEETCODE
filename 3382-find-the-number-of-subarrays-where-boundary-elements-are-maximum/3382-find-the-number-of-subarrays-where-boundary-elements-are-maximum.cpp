const int N=4e5+1;
const int N1=1e5+1;
class Solution {
public:
    int seg[N],arr[N1];
    void build(int s,int i,int j){
        if(i==j){
            seg[s]=arr[i];
            return;
        }
        int mid=(i+j)/2;
        build(2*s,i,mid);
        build(2*s+1,mid+1,j);
        seg[s]=max(seg[2*s],seg[2*s+1]);
    }
    int query(int s,int i,int j,int qi,int qj){
        if(i>=qi && j<=qj){
            return seg[s];
        }
        if(j<qi || i>qj){
            return INT_MIN/2;
        }
        int mid=(i+j)/2;
        int l=query(2*s,i,mid,qi,qj);
        int r=query(2*s+1,mid+1,j,qi,qj);
        return max(l,r);
    }
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans=0;
        map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=1;i<=n;i++)arr[i]=nums[i-1];
        build(1,1,n);
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size()==1){
                ans++;
            }else{
                auto &vi=mp[nums[i]];
                int l=vi[0],r=i;
                while(l<r){
                    int mid=(l+r)/2;
                    int t=query(1,1,n,mid+1,i+1);
                    if(t==nums[i]){
                        r=mid-1;
                    }else{
                        l=mid+1;
                    }
                }
                auto tp=vi.end()-lower_bound(vi.begin(),vi.end(),l);
                ans+=(tp);
            }
        }
        return ans;
    }
};