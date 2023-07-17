import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    	static int n, remove, ans = 0;
	static ArrayList<Integer>[] tree;
	static boolean[] visited;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		tree = new ArrayList[n];
		visited = new boolean[n];
		for(int i = 0; i < n; i++)
			tree[i] = new ArrayList<>();
		
		int root = -1;
		for(int i = 0; i < n; i++) {
			int parent = sc.nextInt();
			if(parent == -1) {
				root = i;
				continue;
			}
			tree[parent].add(i);
		}
		remove = sc.nextInt();
		
		dfs(root);
		
		System.out.println(ans);
	}
	
	static void dfs(int cur) {
		if(cur == remove) return;
		
		if(tree[cur].size() == 0) {
			ans++;
			return;
		}
		
		for(int next : tree[cur]) {
			if(!visited[next]) {
				visited[next] = true;
				if(next == remove ) {
					if(tree[cur].size() == 1) ans++;
					continue;
				}
				else 
					dfs(next);
			}
		}
	}
}