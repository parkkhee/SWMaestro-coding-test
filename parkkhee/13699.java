import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static Long[] t = new Long[36];

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());

        t[0] = 1L;
        t[1] = 1L;
        t[2] = 2L;

        System.out.println(f(n));


    }

    public static Long f(int num) {

        if (num == 0) {
            return t[num];
        } else if (num == 1) {
            return t[num];
        } else if (num == 2) {
            return t[num];
        }

        for (int i = 0; i < num; i++) {
            t[num] += t[i] * f(num - (i+1));
        }

        return t[num];


    }

}
