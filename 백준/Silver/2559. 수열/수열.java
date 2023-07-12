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
		
		int[] temp = new int[n];
		int sum = 0;
		for(int i = 0; i < k; i++) {
			temp[i] = Integer.parseInt(st.nextToken());
			sum += temp[i];
		}
		
		int max = sum;
		for(int i = 0, j = k; j < n; i++, j++) {
			temp[j] = Integer.parseInt(st.nextToken());
			sum = sum - temp[i] + temp[j];
			max = (max > sum)? max : sum;
		}
		System.out.println(max);
	}
}
