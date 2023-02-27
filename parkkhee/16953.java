import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int ressut=n;
        int cnt=0;
        int min;

        while (ressut <= m) {

            if (ressut == m) {
                System.out.println(cnt);
                System.exit(0);
            }

            ressut = ressut * 2;
            cnt++;

        }

        min = Math.min(m - ressut, ressut*2 - m);
        cnt += min;

        System.out.println(cnt);

    }




}
