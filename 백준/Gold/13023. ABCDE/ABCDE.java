import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static int n, m, depth = 0;
	static ArrayList<Integer>[] graph;
	static boolean[] visited;
	static int pos = 0;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		graph = new ArrayList[n];
		for(int i = 0; i < n; i++)
			graph[i] = new ArrayList<>();
		visited = new boolean[n];
		
		for(int i = 0; i < m; i++) {
			int tmp1 = sc.nextInt();
			int tmp2 = sc.nextInt();
			
			graph[tmp1].add(tmp2);
			graph[tmp2].add(tmp1);
		}
		
		for(int i = 0; i < n; i++) {
			dfs(i, 0);
			if(pos == 1) break;			
		}
		
		System.out.println(pos);
	}
	
	static void dfs(int cur, int depth) {
		if(depth == 4) {
			pos = 1;
			return;
		}
		if(visited[cur]) return;
		
		visited[cur] = true;
		for(int friend : graph[cur]) {
			if(!visited[friend] && pos != 1)
				dfs(friend, depth + 1);
		}
		
		visited[cur] = false;
	}
}