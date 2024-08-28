class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        int i=0,j=0, cur=0;
        int n = arr.size();

        vector<int> lens(n, INT_MAX);

        while(i<n) {
            if(cur<target && j<n) {
                cur+=arr[j];
                j++;
            } else if (cur> target) {
                cur-=arr[i];
                i++;
            } else if(cur == target) {
                lens[i]=j-i;
                cur-=arr[i];
                i++;
            } else {
                break;
            }
        }

        vector<int> sums = lens;
        for(int i=n-2;i>=0;i--) {
            sums[i] = min(sums[i], sums[i+1]);
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++) {
            if(lens[i]!=INT_MAX && i+lens[i]<n) {
                if(sums[i+lens[i]]!=INT_MAX) {
                    ans = min(ans, lens[i]+sums[i+lens[i]]);
                }
            }
        }
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;

    }
};