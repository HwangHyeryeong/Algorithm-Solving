import java.util.Scanner;

public class Main {
	static int n, m;
	static int[] select;
	static boolean[] isSelected;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		
		select = new int[n + 1];
		isSelected = new boolean[n + 1];
		
		isSelected[0] = true;
		combination(0, 0);
	}
	
	public static void combination(int cnt, int idx) {
		if(cnt == m) {
			StringBuilder tmp = new StringBuilder();
			for(int i = 0; i < m; i++) { 
				tmp.append(select[i]);
				tmp.append(" ");
			}				
			System.out.println(tmp);
			return;
		}
		
		for(int i = idx; i <= n; i++) {
			if(isSelected[i]) continue;
			
			isSelected[i] = true;
			select[cnt] = i;
			combination(cnt + 1, i);
			isSelected[i] = false;
		}
	}
}
