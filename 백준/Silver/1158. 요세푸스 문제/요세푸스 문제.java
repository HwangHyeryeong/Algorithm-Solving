import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 입력 받기
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        // 요세푸스 순열 계산
        List<Integer> result = getJosephusPermutation(N, K);

        // 결과 출력
        StringBuilder sb = new StringBuilder();
        sb.append("<");
        for (int i = 0; i < result.size(); i++) {
            sb.append(result.get(i));
            if (i < result.size() - 1) {
                sb.append(", ");
            }
        }
        sb.append(">");
        System.out.println(sb);
    }

    public static List<Integer> getJosephusPermutation(int N, int K) {
        List<Integer> people = new ArrayList<>();
        List<Integer> result = new ArrayList<>();

        // 1부터 N까지 사람 추가
        for (int i = 1; i <= N; i++) {
            people.add(i);
        }

        int index = 0;

        // 사람들이 모두 제거될 때까지 반복
        while (!people.isEmpty()) {
            index = (index + K - 1) % people.size(); // K번째 사람의 인덱스 계산
            result.add(people.remove(index)); // 해당 사람 제거 및 결과에 추가
        }

        return result;
    }
}