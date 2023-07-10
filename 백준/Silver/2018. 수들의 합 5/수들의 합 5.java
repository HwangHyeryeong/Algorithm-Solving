import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int[] sum = new int[n + 1];
		for(int i = 1; i <= n; i++) {
			sum[i] = sum[i-1] + i;
		}
		
		int cnt = 0, s = 1, e = 1;
		while(e >= s && e <= n) {
			int curSum = sum[e] - sum[s - 1];
			
			if(curSum == n) cnt++;
			if(curSum < n) e++;
			else s++;
		}

		System.out.println(cnt);
	}
}