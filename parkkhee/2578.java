package test;
import java.io.*;
import java.nio.Buffer;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[][] map = new int[10][5];
    static boolean[] visited = new boolean[26];
    static int cnt =0;

    public static void main(String[] args) throws IOException {

        for (int i = 0; i < 10; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) {
                map[i][j] = Integer.parseInt(br.readLine());

            }

        }

        for (int i = 5; i < 10; i++) {
            for (int j = 0; j < 5; j++) {



            }
        }



    }

    public static void bingock(int num) {

        int bingocnt=0;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {

                if (map[i][j] == num) {

                    map[i][j] = 0;

                }

            }
        }

    }




}

