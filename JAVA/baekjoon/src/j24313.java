import java.io.BufferedReader;
import java.io.InputStreamReader;

public class j24313 {
    public static void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a1, a0, c, n0;

        String[] arr = br.readLine().split(" ");
        a1 = Integer.parseInt(arr[0]);
        a0 = Integer.parseInt(arr[1]);
        c = Integer.parseInt(br.readLine());
        n0 = Integer.parseInt(br.readLine());

        int answer = 0;
        if ((a1 * n0 + a0) <= (c * n0)) {
            if (a1 <= c) answer = 1;
            else answer = 0;
        }

        System.out.println(answer);
        br.close();
    }
    public static void main(String[] args) throws Exception{
        new j24313().solution();
    }
}
