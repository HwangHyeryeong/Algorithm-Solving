import java.util.*;

class Solution {
    boolean[] visit;
    List<Integer>[] graph;
    
    void DFS(int n){
        if(visit[n]) return;
        
        visit[n] = true;
        
        for(int i = 0; i < graph[n].size(); i++){
            int next = graph[n].get(i);
            if(visit[next]) continue;
            DFS(next);
        }
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        graph = new ArrayList[n];
        visit = new boolean[n];
        
        // 그래프 초기화
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(computers[i][j] == 1){
                    graph[i].add(j);
                    graph[j].add(i);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(visit[i]) continue;
            
            DFS(i);
            answer++;
        }
        
        return answer;
    }
}