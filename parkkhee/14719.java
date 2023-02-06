
import java.io.*;
import java.nio.Buffer;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int h,w;
    static int[][] map;
    static int[] x;
    static int[][] idx;


    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        h = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());

        map = new int[h][w];

        x = new int[w];
        idx = new int[h][2];


        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < w; i++) {

            x[i] = Integer.parseInt(st.nextToken());
            for (int j = h - 1; j > (h - 1 - x[i]); j--) {
                map[i][j] = 1;
            }

            if (idx[i][0] == 0) {
                idx[i][0] = i;
            }

        }


    }

}



