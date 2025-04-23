class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> temp[37];
        for(int i=1;i<=n;i++){
            int t=i;
            int sum=0;
            while(t>0){
                sum+=(t%10);
                t/=10;
            }
            temp[sum].push_back(i);
        }
        map<int,int> mp;
        for(int i=0;i<37;i++)mp[(int)temp[i].size()]++;
        return (--mp.end())->second;
    }
};