import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	    
	    StringTokenizer token = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(token.nextToken());
        int m = Integer.parseInt(token.nextToken());
        
        Map<String, String> pocketmons = new HashMap<>();
        
		for(int i = 1; i <= n; i++){
		     String name = reader.readLine().trim();
		     pocketmons.put(String.valueOf(i), name);
		     pocketmons.put(name, String.valueOf(i));
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < m; i++){
		    String target = reader.readLine().trim();
		    sb.append(pocketmons.get(target)).append('\n');
		}
		
		System.out.println(sb);
	}
}
