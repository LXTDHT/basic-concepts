public class Fibonacci {
    public static int n = 10; // Set the number of iterations here.

    public static void main(String[] args) {
        int[] f = new int[n]; f[0] = 0; f[1] = 1; f[2] = 1;

        for (int i = 3; i < n; ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }

        for (int i = 0; i < n; ++i) {
            System.out.println(f[i]);
        }
    }
}