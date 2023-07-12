import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());

		Stack<Pair> s = new Stack<>();
		int[] nge = new int[n];
		for(int i = 0; i < n; i++) {
			int cur = Integer.parseInt(st.nextToken());
			while(!s.isEmpty() && s.peek().val < cur) {
				nge[s.peek().idx] = cur;
				s.pop();
			}
			s.add(new Pair(i, cur));
		}

		StringBuilder ans = new StringBuilder();
		for(int i = 0; i < n; i++) {
			if(nge[i] == 0)
				ans.append("-1 ");
			else
				ans.append(nge[i] + " ");
		}
		System.out.println(ans);
	}
}

class Pair{
	int idx;
	int val;

	Pair(int idx, int val){
		this.idx = idx;
		this.val = val;
	}
}