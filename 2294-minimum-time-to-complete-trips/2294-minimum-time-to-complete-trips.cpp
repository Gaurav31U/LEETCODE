class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=0,r=1e15;
        while(l<=r){
            long long mid=(l+r)/2;
            long long t=0;
            for(auto it:time){
                t+=mid/it;
                if(t>totalTrips)break;
            }
            if(t>=totalTrips){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};