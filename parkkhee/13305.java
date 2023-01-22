
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] dis;
    static int[] money;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(br.readLine());

        dis = new int[n-1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n - 1; i++) {
            dis[i] = Integer.parseInt(st.nextToken());
        }

        money = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            money[i] = Integer.parseInt(st.nextToken());
        }

        long result = 0;  //long형으로
        long min = money[0];

        for (int i = 0; i < n-1; i++) {
            if (min > money[i]) {   //계속 비교해가면서
                min = money[i];
            }

            result += min * dis[i];

        }


        System.out.println(result);


    }

}



