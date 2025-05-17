import java.util.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        Queue<int[]> q = new LinkedList<>();
        int answer = 0;
        int servers = 0;
        
        for(int i = 0; i < 24; i++){
            while(!q.isEmpty() && q.peek()[0] == i){
                servers -= q.poll()[1];
            }
            
            int need = players[i] / m;
            int add = need - servers;
            if(add > 0){
                servers += add;
                answer += add;
                q.add(new int[]{i + k, add});
            }
        }
        
        return answer;
    }
}