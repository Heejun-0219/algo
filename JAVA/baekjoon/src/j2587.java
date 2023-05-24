import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class j2587 {
    private static void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList N = new ArrayList<>();
        int sum = 0;
        int mid;

        for (int i = 0; i < 5; i++){
            N.add(Integer.parseInt(br.readLine()));
            sum += Integer.parseInt(N.get(i).toString());
        }
        sum /= 5;
        Collections.sort(N);
        System.out.println(sum);
        System.out.println(N.get(2));
    }
    public static void main(String[] args) throws Exception {
        new j2587().solution();
    }
}

//import java.io.BufferedReader;
//        import java.io.IOException;
//        import java.io.InputStreamReader;
//        import java.util.Arrays;
//
//public class Main {
//    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        int[] numbers = new int[5];
//
//        // 다섯 개의 자연수 입력받기
//        for (int i = 0; i < 5; i++) {
//            numbers[i] = Integer.parseInt(br.readLine());
//        }
//
//        int average = calculateAverage(numbers);
//        int median = calculateMedian(numbers);
//
//        printResult(average, median);
//    }
//
//    // 평균 계산 함수
//    private static int calculateAverage(int[] numbers) {
//        int sum = 0;
//        for (int number : numbers) {
//            sum += number;
//        }
//        return sum / numbers.length;
//    }
//
//    // 중앙값 계산 함수
//    private static int calculateMedian(int[] numbers) {
//        Arrays.sort(numbers);
//        int mid = numbers.length / 2;
//
//        if (numbers.length % 2 == 1) {
//            return numbers[mid];
//        } else {
//            return (numbers[mid - 1] + numbers[mid]) / 2;
//        }
//    }
//
//    // 결과 출력 함수
//    private static void printResult(int average, int median) {
//        System.out.println(average);
//        System.out.println(median);
//    }
//}

