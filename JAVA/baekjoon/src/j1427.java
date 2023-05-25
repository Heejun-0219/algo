import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class j1427 {
    private static void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String N = br.readLine();
        List<Integer> sortedDigits = new ArrayList<>();
        for (char c : N.toCharArray()) {
            sortedDigits.add(Character.getNumericValue(c));
        }

        Collections.sort(sortedDigits, Collections.reverseOrder());

        for (int digit : sortedDigits) {
            System.out.print(digit);
        }
    }
    public static void main(String[] args) throws Exception{
        j1427.solution();
    }
}

//
//public class j1427 {
//    public static void main(String[] args) throws Exception{
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        String input = br.readLine();
//        char[] digits = input.toCharArray(); // 문자열을 문자 배열로 변환
//
//        Arrays.sort(digits); // 문자 배열을 오름차순으로 정렬
//        StringBuilder sb = new StringBuilder(new String(digits)); // 정렬된 문자 배열을 문자열로 변환
//
//        String output = sb.reverse().toString(); // 문자열을 뒤집어서 내림차순으로 변환
//        System.out.println(output); // 결과 출력
//    }
//}
