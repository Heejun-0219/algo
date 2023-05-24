import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class j10989 {
    private static void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> arr = new ArrayList<>();
        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++){
            arr.add(Integer.parseInt(br.readLine()));
        }

        Collections.sort(arr);

        for (int i = 0; i < N; i++){
            System.out.println(arr.get(i));
        }
    }
    public static void main(String[] args) throws Exception{
        new j10989().solution();
    }
}

//import java.io.*;
//
//public class Main {
//    public static void main(String[] args) throws Exception {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringBuilder sb = new StringBuilder();
//
//        int N = Integer.parseInt(br.readLine());
//
//        int count[] = new int[10001];
//        for(int i=0; i<N; i++) {
//            count[Integer.parseInt(br.readLine())]++;
//        }
//
//        for(int i=1; i<10001; i++) {
//            while(count[i] > 0) {
//                sb.append(i).append('\n');
//                count[i]--;
//            }
//        }
//
//        System.out.println(sb);
//    }
//}