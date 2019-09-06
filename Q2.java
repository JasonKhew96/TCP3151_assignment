import java.util.Scanner;

class Q2 {
    // native method
    public native int[] randomArr(int size);
    public native int calcDiff(int[] arr);

    // load library
    static {
        System.loadLibrary("CQ2");
    }

    public static void main(String[] args) {
        // initiate Q2 instance
        Q2 q2 = new Q2();
        // initiate Scanner instance
        Scanner scanner = new Scanner(System.in);
        System.out.printf("Please input size of the array: ");
        // pass array size into native method
        int[] arr = q2.randomArr(scanner.nextInt());
        // pass returned array into native method
        int diff = q2.calcDiff(arr);
        // print return difference from native method
        System.out.printf("Diff: %d", diff);
    }
}