import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		
		int[] temp = new int[n + 1];
		int sum = 0, max = -9999;
		for(int i = 1; i <= n; i++) {
			temp[i] = Integer.parseInt(st.nextToken());
			
			if(i >= k) {
				sum = sum - temp[i - k] + temp[i];
				max = (max > sum)? max: sum;
			}
			else {
				sum += temp[i];
			}
			
		}
		System.out.println(max);
	}
}
