import java.io.BufferedReader;
import java.io.InputStreamReader;

public class j24265 {
    private static void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        System.out.println(1l*n*(n-1)/2);
        System.out.println(2);
    }
    public static void main(String[] args) throws Exception {
        new j24265().solution();
    }
}