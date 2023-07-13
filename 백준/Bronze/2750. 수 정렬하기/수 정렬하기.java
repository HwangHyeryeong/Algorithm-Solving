import java.util.Scanner;

public class Main {
	
		public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];

		for(int i = 0; i < n; i++)
			arr[i] = sc.nextInt();

		quickSort(arr, 0, n - 1);
		
		for(int i : arr)
			System.out.println(i);
	}

	static void swap(int[] arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	
	static void quickSort(int[] arr, int left, int right) {
		if(left >= right) return;
		
		int pivot = partition(arr, left, right);
		
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);		
	}
	
	static int partition(int[] arr, int pivot, int high) {
		int left = pivot + 1;
		int right = high;
		
		while(true) {
			while(left < high && arr[left] < arr[pivot])
				left++;
			while(right > pivot && arr[right] > arr[pivot])
				right--;
			
			if(left >= right) break;
			
			swap(arr, left++, right--);
		}
		swap(arr, pivot, right);
		
		return right;
	}
}