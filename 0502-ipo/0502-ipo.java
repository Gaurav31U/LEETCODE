import java.util.*;

public class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        List<int[]> temp = new ArrayList<>();
        
        for (int i = 0; i < profits.length; i++) {
            temp.add(new int[]{capital[i], profits[i]});
        }
        
        temp.sort(Comparator.comparingInt(a -> a[0]));
        
        for (int i = 0; i < temp.size(); i++) {
            if (temp.get(i)[0] <= w) {
                pq.add(temp.get(i)[1]);
            } else {
                if (pq.isEmpty()) return w;
                w += pq.poll();
                k--;
                
                while (!pq.isEmpty() && w < temp.get(i)[0] && k > 0) {
                    w += pq.poll();
                    k--;
                }
                
                if (k == 0) return w;
                
                if (w >= temp.get(i)[0]) {
                    pq.add(temp.get(i)[1]);
                }
            }
            if (k == 0) break;
        }
        
        while (!pq.isEmpty() && k > 0) {
            w += pq.poll();
            k--;
        }
        
        return w;
    }
}
