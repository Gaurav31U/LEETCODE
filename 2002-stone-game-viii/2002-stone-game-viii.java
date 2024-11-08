class Solution {
    public int stoneGameVIII(int[] stones) {
        int N=stones.length;
        for(int i=1;i<N;i++)stones[i]+=stones[i-1];
        int dp=stones[N-1];
        for(int i=N-2;i>0;i--)dp=Math.max(dp,stones[i]-dp);
        return dp;
    }
}