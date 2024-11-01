class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int l=1,r=buckets;
        int k=minutesToTest/minutesToDie;
        return ceil(log2(r)/log2(k+1));
    }
};