
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[] coin;
    static int cnt=0;

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        coin = new int[n];

        for (int i = 0; i < n; i++) {
            coin[i] = Integer.parseInt(br.readLine());
        }


        for (int i = n-1; i >= 0; i--) {

            if (k == 0) {
                break;
            }

            while (coin[i] <= k) {
                cnt += k / coin[i];
                k = k % coin[i];
            }


        }

        System.out.println(cnt);


    }




}

