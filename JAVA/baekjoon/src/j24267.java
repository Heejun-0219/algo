import java.io.BufferedReader;
import java.io.InputStreamReader;

public class j24267 {
    public static void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Integer.parseInt(br.readLine());
        System.out.println(n*(n-1)*(n-2)/6);
        System.out.println(3);

        br.close();
    }
    public static void main(String[] args)  throws Exception {
        new j24267().solution();
    }
}
