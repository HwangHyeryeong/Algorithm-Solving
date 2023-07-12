import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];

		for(int i = 0; i < n; i++)
			arr[i] = sc.nextInt();

		for(int i = 0; i < n - 1; i++)
			for(int j = 0; j < n - i - 1; j++) {
				if(arr[j] > arr[j+1])
					swap(arr, j, j+1);
			}

		for(int i : arr)
			System.out.println(i);
	}

	static void swap(int[] arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}
