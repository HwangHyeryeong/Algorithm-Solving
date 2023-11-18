import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int max = -9999, num = -1000;
        for(int i = 0; i < n; i++){
            int tmp = Integer.parseInt(st.nextToken());
            
            num = Math.max(tmp, num + tmp);
            max = Math.max(max, num);
        }
        
        System.out.println(max);
	}
}
