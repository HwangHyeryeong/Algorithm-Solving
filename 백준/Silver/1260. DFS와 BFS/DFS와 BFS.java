import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int n, m, v;
	static ArrayList<Integer>[] graph;
	static boolean[] visited;
	static StringBuilder ans;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		v = sc.nextInt();
		graph = new ArrayList[n + 1];
		
		for(int i = 1; i <= n; i++)
			graph[i] = new ArrayList<>();
		
		for(int i = 0; i < m; i++) {
			int v1 = sc.nextInt(), 
				v2 = sc.nextInt();
			graph[v1].add(v2);
			graph[v2].add(v1);
		}
		
		for(int i = 1; i <= n; i++)
			Collections.sort(graph[i]);
		
		visited = new boolean[n + 1];
		ans = new StringBuilder();
		dfs(v);
		System.out.println(ans);
		
		visited = new boolean[n + 1];
		ans = new StringBuilder();
		bfs(v);
		System.out.println(ans);
	}
	
	static void dfs(int cur) {
		visited[cur] = true;
		ans.append(cur + " ");
		for(int next : graph[cur]) {
			if(!visited[next]) {
				dfs(next);
			}
		}
	}
	
	static void bfs(int cur) {
		Queue<Integer> q = new LinkedList<Integer>();
		
		visited[cur] = true;
		q.add(cur);
		while(!q.isEmpty()) {
			int now = q.poll();
			ans.append(now + " ");
			for(int next : graph[now]) {
				if(!visited[next]) {
					visited[next] = true;
					q.add(next);
				}
			}
		}
	}
}
