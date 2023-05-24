import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class j25305 {
    private static void solution() throws Exception {
        ArrayList<Integer> student = new ArrayList<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N;
        int cutline;
        String[] line = br.readLine().split(" ");

        N = Integer.parseInt(line[0]);
        cutline = Integer.parseInt(line[1]);

        line = br.readLine().split(" ");
        for (int i = 0; i < N; i++){
            student.add(Integer.parseInt(line[i]));
        }
        Collections.sort(student);
        Collections.reverse(student);

        System.out.println(student.get(cutline - 1));
    }
    public static void main(String[] args) throws Exception {
        new j25305().solution();
    }
}

//import java.util.ArrayList;
//        import java.util.Collections;
//        import java.util.Comparator;
//        import java.util.List;
//
//public class Main {
//    public static void main(String[] args) {
//        List<Integer> numbers = new ArrayList<>();
//        numbers.add(10);
//        numbers.add(40);
//        numbers.add(30);
//        numbers.add(60);
//        numbers.add(30);
//
//        // 내림차순으로 정렬
//        Collections.sort(numbers, new Comparator<Integer>() {
//            @Override
//            public int compare(Integer o1, Integer o2) {
//                return o2.compareTo(o1);
//            }
//        });
//
//        // 정렬된 결과 출력
//        for (int number : numbers) {
//            System.out.println(number);
//        }
//    }
//}
