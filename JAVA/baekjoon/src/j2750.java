import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class j2750 {
    private static void quick(ArrayList<Integer> arrayList, int left, int right) throws Exception{
        if (left < right){
            int pivotIndex = getPivotIndex(arrayList, left, right);
            int newPivotIndex = partition(arrayList, left, right, pivotIndex);
            quick(arrayList, left, newPivotIndex - 1);
            quick(arrayList, newPivotIndex + 1, right);
        }
    }
    private static int partition(ArrayList<Integer> arrayList, int left, int right, int pivotIndex){
        int pivot = arrayList.get(pivotIndex);
        swap(arrayList, pivotIndex, right);
        int i = left;

        for (int j = left; j < right; j++){
            if (arrayList.get(j) < pivot){
                swap(arrayList, i, j);
                i++;
            }
        }

        swap(arrayList, i, right);
        return i;
    }
    private static int getPivotIndex(ArrayList<Integer> arrayList, int left, int right) {
        int mid = (left + right) / 2;
        int a = arrayList.get(left);
        int b = arrayList.get(mid);
        int c = arrayList.get(right);

        if ((a <= b && b <= c) || (c <= b && b <= a)) {
            return mid;
        } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
            return left;
        } else {
            return right;
        }
    }

    private static void swap(ArrayList<Integer> arrayList, int a, int b){
        int tmp = arrayList.get(a);
        arrayList.set(a, arrayList.get(b));
        arrayList.set(b, tmp);
    }
    private static void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i = 0; i < N; i++){
            arrayList.add(Integer.parseInt(br.readLine()));
        }

        j2750.quick(arrayList, 0, N - 1);

        for (int i = 0; i < N; i++){
            System.out.println(arrayList.get(i));
        }
    }
    public static void main(String[] args) throws Exception{
        new j2750().solution();
    }
}

//import java.io.BufferedReader;
//        import java.io.InputStreamReader;
//        import java.util.ArrayList;
//
//public class Main {
//    private static void quickSort(ArrayList<Integer> arr, int left, int right) {
//        if (left >= right) return;
//
//        int pivot = arr.get((left + right) / 2);
//        int index = partition(arr, left, right, pivot);
//
//        quickSort(arr, left, index - 1);
//        quickSort(arr, index, right);
//    }
//
//    private static int partition(ArrayList<Integer> arr, int left, int right, int pivot) {
//        while (left <= right) {
//            while (arr.get(left) < pivot) left++;
//            while (arr.get(right) > pivot) right--;
//
//            if (left <= right) {
//                int temp = arr.get(left);
//                arr.set(left, arr.get(right));
//                arr.set(right, temp);
//                left++;
//                right--;
//            }
//        }
//
//        return left;
//    }
//
//    public static void main(String[] args) throws Exception {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        int N = Integer.parseInt(br.readLine());
//
//        ArrayList<Integer> arr = new ArrayList<>();
//        for (int i = 0; i < N; i++) {
//            arr.add(Integer.parseInt(br.readLine()));
//        }
//
//        quickSort(arr, 0, N - 1);
//
//        for (int num : arr) {
//            System.out.println(num);
//        }
//    }
//}
