import java.util.*;

public class Solution {
    public int componentValue(int[] nums, int[][] edges) {
        int sum = 0;
        for (int num : nums) sum += num;

        List<Integer> factors = new ArrayList<>();
        for (int i = 1; i <= Math.sqrt(sum); i++) {
            if (sum % i == 0) {
                factors.add(sum / i);
                factors.add(i);
                if (i * i == sum) factors.remove(factors.size() - 1);
            }
        }
        Collections.sort(factors);

        List<Integer>[] adj = new ArrayList[20001];
        for (int i = 0; i < 20001; i++) adj[i] = new ArrayList<>();
        for (int[] edge : edges) {
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
        }

        int[] vis = new int[20001];
        int ans = 0;

        for (int factor : factors) {
            Arrays.fill(vis, 0);
            boolean possible = true;
            if (dfs(0, factor, vis, adj, nums) == -1) possible = false;

            if (possible) {
                ans = Math.max(ans, sum / factor - 1);
            }
        }

        return ans;
    }

    private int dfs(int node, int targetSum, int[] vis, List<Integer>[] adj, int[] nums) {
        vis[node] = 1;
        int val = nums[node];

        for (int neighbor : adj[node]) {
            if (vis[neighbor] == 0) {
                int subTreeSum = dfs(neighbor, targetSum, vis, adj, nums);
                if (subTreeSum == -1) return -1;
                val += subTreeSum;
            }
        }

        if (val > targetSum) return -1;
        return (val == targetSum) ? 0 : val;
    }
}
