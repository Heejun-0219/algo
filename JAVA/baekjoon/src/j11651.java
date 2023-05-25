import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Point {
    private int x;
    private int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}

public class j11651 {
    private static ArrayList<Point> map = new ArrayList<>();
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    private static void readMap() throws Exception {
        String[] tmp = br.readLine().split(" ");
        int x = Integer.parseInt(tmp[0]);
        int y = Integer.parseInt(tmp[1]);
        map.add(new Point(x, y));
    }

    private static void solution() throws Exception {
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            readMap();
        }

        Collections.sort(map, Comparator.comparing(Point::getY).thenComparing(Point::getX));

        for (Point point : map) {
            System.out.println(point.getX() + " " + point.getY());
        }
    }

    public static void main(String[] args) throws Exception {
        new j11651().solution();
    }
}
