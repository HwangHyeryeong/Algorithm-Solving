import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
	static int n;
	static int[] parent;
	static ArrayList<Node> nodes = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		parent = new int[n];

		for(int i = 1; i < n; i++)
			parent[i] = i;


		for(int i = 0; i < n; i++) {
			char[] lan = br.readLine().toCharArray();
			for(int j = 0; j < n; j++) {
				if(lan[j] >= 'a') 
					nodes.add(new Node(i, j, (lan[j] - 'a' + 1)));
				else if(lan[j] >= 'A')
					nodes.add(new Node(i, j, (lan[j] - 'A' + 27)));
			}
		}
		Collections.sort(nodes, (a, b) -> (a.w - b.w));
		
		int donate = 0;
		for(int i = 0; i < nodes.size(); i++) {
			if(find(nodes.get(i).u) != find(nodes.get(i).v)) 
				union(nodes.get(i).u, nodes.get(i).v);
			else
				donate += nodes.get(i).w;
		}
		
		boolean conn = true;
		for(int i = 1; i < n; i++) {
			conn = (find(i - 1) == find(i));
			if(!conn) break;
		}
		
		System.out.println(conn? donate : -1);
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