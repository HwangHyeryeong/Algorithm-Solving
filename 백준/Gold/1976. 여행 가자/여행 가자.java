import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
		static int n, m;
	static int[] graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());
		graph = new int[n + 1];
		for(int i = 0; i <= n; i++)
			graph[i] = i;
		
		for(int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 1; j <= n; j++) {
				int a = Integer.parseInt(st.nextToken());
				if(a == 1)
					union(i, j);
			}
		}
		
		st = new StringTokenizer(br.readLine());
		int firstCity = Integer.parseInt(st.nextToken());
		String ans = "YES";
		for(int i = 1; i < m; i++) {
			int city = Integer.parseInt(st.nextToken());
			if(find(city) != find(firstCity)) 
				ans = "NO";
		}
		
		System.out.println(ans);
	}

	static int find(int x) {
		if(x == graph[x]) return x;

		return graph[x] = find(graph[x]);
	}

	static void union(int x, int y) {
		x = find(x);
		y = find(y);

		if(x != y) {
			if(x < y)
				graph[y] = x;
			else
				graph[x] = y;
		}
	}
}