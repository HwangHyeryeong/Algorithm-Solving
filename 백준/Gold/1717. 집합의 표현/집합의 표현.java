import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, m;
	static int[] graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		graph = new int[n + 1];

		for(int i = 1; i <= n; i++)
			graph[i] = i;

		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int command = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			if(command == 0) {
				union(a, b);
			}
			else {
				System.out.println((find(a) == find(b))? "yes" : "no");
			}
		}
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
