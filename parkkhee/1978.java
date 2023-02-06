
import java.io.*;
import java.nio.Buffer;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[] num;
    static int cnt=0;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());

        num = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {

            num[i] = Integer.parseInt(st.nextToken());

        }

        for (int i = 0; i < n; i++) {

            for (int j = 2; j <= num[i]; j++) {

                if (j == num[i]) {
                    cnt++;
                }
                if(num[i]%j == 0) break;


            }

        }

        System.out.println(cnt);


    }




}



