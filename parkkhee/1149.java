
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[][] house_color;
    static int[][] dp;
    static int min = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());

        house_color = new int[n][3];
        dp = new int[n][3];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < 3; j++) {
                house_color[i][j] = Integer.parseInt(st.nextToken());
            }


        }

        dp[0][0] = house_color[0][0];
        dp[0][1] = house_color[0][1];
        dp[0][2] = house_color[0][2];


        System.out.println(Math.min(re(n-1,0), Math.min(re(n-1,1),re(n-1,2))));


    }


    public static int re(int row, int col) {

        if (dp[row][col] == 0) {

            if (col == 0) {
                dp[row][col] = Math.min(re(row-1, col +1), re(row-1,col+2)) + house_color[row][col];
            }

            else if (col == 1) {
                dp[row][col] = Math.min(re(row-1, col +1), re(row-1,col-1)) + house_color[row][col];
            }

            else{
                dp[row][col] = Math.min(re(row-1, col -1), re(row-1,col-2)) + house_color[row][col];
            }

        }

        return dp[row][col];


    }




}



