import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class j11650 {
    private static ArrayList<ArrayList<Integer>> map = new ArrayList<>();
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    private static void readMap() throws Exception {
        String[] tmp;
        ArrayList<Integer> row = new ArrayList<>();

        tmp = br.readLine().split(" ");
        for (String s : tmp) {
            row.add(Integer.parseInt(s));
        }
        map.add(row);
    }
    private static void solution() throws Exception {
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++){
            readMap();
        }

        Collections.sort(map, new Comparator<ArrayList<Integer>>() {
            @Override
            public int compare(ArrayList<Integer> a, ArrayList<Integer> b) {
                if (a.get(0).equals(b.get(0))) {
                    return a.get(1).compareTo(b.get(1));
                } else {
                    return a.get(0).compareTo(b.get(0));
                }
            }
        });

        for (ArrayList<Integer> point : map) {
            System.out.println(point.get(0) + " " + point.get(1));
        }
    }
    public static void main(String[] args) throws Exception{
        new j11650().solution();
    }
}

//import java.io.BufferedReader;
//        import java.io.InputStreamReader;
//        import java.util.ArrayList;
//        import java.util.Collections;
//        import java.util.Comparator;
//
//class Point {
//    private int x;
//    private int y;
//
//    public Point(int x, int y) {
//        this.x = x;
//        this.y = y;
//    }
//
//    public int getX() {
//        return x;
//    }
//
//    public int getY() {
//        return y;
//    }
//}
//
//public class Main {
//    private static ArrayList<Point> map = new ArrayList<>();
//    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//
//    private static void readMap() throws Exception {
//        String[] tmp = br.readLine().split(" ");
//        int x = Integer.parseInt(tmp[0]);
//        int y = Integer.parseInt(tmp[1]);
//        map.add(new Point(x, y));
//    }
//
//    private static void solution() throws Exception {
//        int n = Integer.parseInt(br.readLine());
//        for (int i = 0; i < n; i++) {
//            readMap();
//        }
//
//        Collections.sort(map, Comparator.comparing(Point::getX).thenComparing(Point::getY));
//
//        for (Point point : map) {
//            System.out.println(point.getX() + " " + point.getY());
//        }
//    }
//
//    public static void main(String[] args) throws Exception {
//        new Main().solution();
//    }
//}
