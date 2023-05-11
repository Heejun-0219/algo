import java.io.BufferedReader;
import java.io.InputStreamReader;

public class j24266 {
    public static void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Integer.parseInt(br.readLine());
        System.out.println(n*n*n);
        System.out.println(3);
    }
    public static void main(String[] args)  throws Exception {
        new j24266().solution();
    }
}
