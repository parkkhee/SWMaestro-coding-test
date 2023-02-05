
import java.io.*;
import java.nio.Buffer;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[] card;
    static int max = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        card = new int[n+1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i < n+1; i++) {
            card[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i < n + 1; i++) {
            f(i,card[i]);
        }

        System.out.println(max);

    }

    public static void f(int cnt, int money) {

        if (cnt == n) {
            max = Math.max(max, money);
//            System.out.println(max);
            return;
        }

        for (int i = 1; i < n + 1; i++) {
            if(cnt+i > n) break;
//            System.out.println("i: "+i+" "+(money+card[i]));
            f(cnt+i,money+card[i]);

        }

    }


}



