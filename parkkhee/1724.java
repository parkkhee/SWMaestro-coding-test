
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;
    static int[][] num = new int[1001][1001];
    static boolean[] visited;
    static int cnt=0;

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        visited = new boolean[n+1];

        for (int i = 0; i < m; i++) {

            st = new StringTokenizer(br.readLine());
            int dot1 = Integer.parseInt(st.nextToken());
            int dot2 = Integer.parseInt(st.nextToken());

            num[dot1][dot2] = 1;
            num[dot2][dot1] = 1;


        }


        for (int i = 1; i < n+1; i++) {

            if (!visited[i]) {

                cnt++;
                dfs(i);

            }


        }

        System.out.println(cnt);



    }


    public static void dfs(int a) {

        visited[a] = true;

        for (int i = 1; i < n+1; i++) {

            if (num[a][i] == 1 && !visited[i]) {
                dfs(i);
            }

        }



    }



}

