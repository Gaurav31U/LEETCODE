#define ll long long
class Solution {
private:
    multiset<int> m1, m2;
    ll sum; 
    void add(int num, int n){
        if((int)m1.size() >= n && num >= *(m1.rbegin())){
            m2.insert(num);
        }else{
            m1.insert(num);
            sum += (ll)num;
            if((int)m1.size() > n){
                int val = *(m1.rbegin());
                m2.insert(val);
                m1.erase(m1.find(val));
                sum -= (ll)val;
            }
        }
    }
    void remove(int num, int n){
        if(num > *(m1.rbegin())){
            m2.erase(m2.find(num));
        }else{
            m1.erase(m1.find(num));
            sum -= (ll)num;
            if(!m2.empty()){
                int val = *(m2.begin());
                m1.insert(val);
                m2.erase(m2.find(val));
                sum += (ll)val;
            }
        }
    }

public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        m1.clear();
        m2.clear();
        sum = 0;
        ll ans = 1e18;
        for(int i=1; i<n; i++){
            add(nums[i], k-1);
            if(i-dist-1>0){
                remove(nums[i-dist-1], k-1);
            }
            if(i>=k-1) ans = min(ans, sum);
        }
        ans += (ll)nums[0];
        return ans;
        
    }
};