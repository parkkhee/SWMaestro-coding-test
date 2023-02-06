
import java.io.*;
import java.nio.Buffer;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n,x;
    static int[] num;
    static int cnt = 0;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());

        num = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {

            num[i] = Integer.parseInt(st.nextToken());

        }

        x = Integer.parseInt(br.readLine());

        Arrays.sort(num);

        for (int i = 0; i < n; i++) {

            for (int j = n - 1; j >= 0; j--) {

                if(i == j) continue;

                if (num[i] + num[j] < 13) {
                    break;
                }
                if (num[i] + num[j] == x) {
                    cnt++;
                }


            }

        }

        System.out.println(cnt/2);

    }

}



