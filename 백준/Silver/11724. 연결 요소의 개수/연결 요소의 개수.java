import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static int n, m;
	static ArrayList<Integer>[] graph;
	static boolean[] visited;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		graph = new ArrayList[n + 1];
		for(int i = 1; i <= n; i++)
			graph[i] = new ArrayList<>();
		visited = new boolean[n + 1];
		
		for(int i = 0; i <m; i++){
		    st = new StringTokenizer(br.readLine());
		    int n1 = Integer.parseInt(st.nextToken());
		    int n2 = Integer.parseInt(st.nextToken());
		    
		    graph[n1].add(n2);
		    graph[n2].add(n1);
		}
		
		int count = 0;
		for(int i = 1; i <= n; i++) {
			if(!visited[i]) {
				dfs(i);
				count++;
			}
		}
		
		System.out.println(count);
	}
	
	static void dfs(int cur) {
		visited[cur] = true;
		
		for(int next : graph[cur]) {
			if(!visited[next])
				dfs(next);
		}
	}
}
