import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static int n;
	static ArrayList<Integer>[] tree = new ArrayList[26];
	static StringBuilder preorder = new StringBuilder();
	static StringBuilder inorder = new StringBuilder();
	static StringBuilder postorder = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		for(int i = 0; i < 26; i++)
			tree[i] = new ArrayList<>();
		
		sc.nextLine();//버퍼 비우기
		for(int i = 0; i < n; i++) {
			
			String input = sc.nextLine();
			char[] tmp = input.toCharArray(); //띄어쓰기 포함
			
			int node = tmp[0] - 'A';
			if(tmp[2] == '.')
				tree[node].add(-1);
			else
				tree[node].add(tmp[2] - 'A');
			if(tmp[4] == '.')
				tree[node].add(-1);
			else
				tree[node].add(tmp[4] - 'A');
		}
		
		dfs(0);
		
		System.out.println(preorder);
		System.out.println(inorder);
		System.out.println(postorder);
	}
	
	static void dfs(int cur) {
		if(cur == -1) return;
		
		preorder.append((char)(cur + 'A'));
		dfs(tree[cur].get(0));//left
		inorder.append((char) (cur + 'A'));
		dfs(tree[cur].get(1));//right
		postorder.append((char) (cur + 'A'));
	}
}
