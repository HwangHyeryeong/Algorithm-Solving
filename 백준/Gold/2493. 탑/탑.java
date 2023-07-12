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
		
		for(int i = 1; i <= n; i++) {
			int tmp = Integer.parseInt(st.nextToken());
			
			while(!s.isEmpty()) {
				if(tmp <= s.peek().hieght) {
					System.out.print(s.peek().num + " ");
					break;
				}
				s.pop();				
			}
			if(s.isEmpty())
				System.out.print("0 ");
				
			s.add(new Pair(i, tmp));
		}
	}
}

class Pair{
	int num;
	int hieght;

	Pair(int num, int hieght){
		this.num = num;
		this.hieght = hieght;
	}
}