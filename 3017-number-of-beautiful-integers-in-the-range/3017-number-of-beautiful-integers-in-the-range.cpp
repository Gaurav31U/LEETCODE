vector<int> temp;
class Solution {
public:
    bool chk(int n){
        int c=0;
        while(n>0){
            if(n&1)c++;
            else c--;
            n/=10;
        }
        return c==0;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        //2 4 6 8
        if(temp.empty()){
            for(int i=10;i<=99;i++)
                if(chk(i))temp.push_back(i);
            for(int i=1000;i<=9999;i++)
                if(chk(i))temp.push_back(i);
            for(int i=100000;i<=999999;i++)
                if(chk(i))temp.push_back(i);
            for(int i=10000000;i<=99999999;i++)
                if(chk(i))temp.push_back(i);
        }
        int ans=0;
        auto it=lower_bound(temp.begin(),temp.end(),low);
        for(;it!=temp.end() && *it<=high;it++){
            if((*it)%k==0)ans++;
        }
        return ans;
    }
};