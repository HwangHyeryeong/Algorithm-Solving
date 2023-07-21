import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	static int v, e;
	static int[] parent;
	static ArrayList<Node> nodes = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		v = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		parent = new int[v + 1];

		for(int i = 0; i <= v; i++)
			parent[i] = i;
		
		for(int i = 0; i < e; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			
			nodes.add(new Node(a, b, c));
		}
		Collections.sort(nodes, (a, b) -> (a.w - b.w));
		
		int weight = 0;
		for(int i = 0; i < e; i++) {
			if(find(nodes.get(i).u) != find(nodes.get(i).v)) {
				union(find(nodes.get(i).u), find(nodes.get(i).v));
				weight += nodes.get(i).w;
			}
		}
		System.out.println(weight);
	}

	static int find(int x) {
		if(x == parent[x]) return x;

		return parent[x] = find(parent[x]);
	}

	static void union(int x, int y) {
		x = find(x);
		y = find(y);

		if(x != y) {
			if(x < y)
				parent[y] = x;
			else
				parent[x] = y;
		}
	}
}

class Node{
	int u;
	int v;
	int w;
	
	Node(int u, int v, int w){
		this.u = u;
		this.v = v;
		this.w = w;
	}
}