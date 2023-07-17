import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static int n;
	static ArrayList<Integer>[] tree;
	static int[] parent;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		tree = new ArrayList [n + 1];

		for(int i = 0; i <= n; i++)
			tree[i] = new ArrayList<>();

		for(int i = 1; i < n; i++) {
			int tmp1 = sc.nextInt();
			int tmp2 = sc.nextInt();
			tree[tmp1].add(tmp2);
			tree[tmp2].add(tmp1);
		}

		parent = new int[n + 1];

		dfs(1);

		StringBuilder sb = new StringBuilder();
		for(int i = 2; i <= n; i++)
			sb.append(parent[i] + "\n");
		System.out.println(sb);
	}

	static void dfs(int cur) {
		for(int i : tree[cur]) {
			if(parent[i] == 0) {
				parent[i] = cur;
				dfs(i);
			}
		}
	}
}