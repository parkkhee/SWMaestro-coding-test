import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[][] paper;
    static int white=0, blue=0;

    public static void main(String[] args) throws IOException {

        int num = Integer.parseInt(br.readLine());
        paper = new int[num][num];


        for (int i = 0; i < num; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < num; j++) {

                paper[i][j] = Integer.parseInt(st.nextToken());

            }

        }

        partition(0,0,num);
        System.out.println(white);
        System.out.println(blue);


    }

    public static void partition(int row, int col, int n) {

        if (whatcr(row, col, n)) {
            if (paper[row][col] == 0) {
                white++;
            } else {
                blue++;
            }
            return; //if문을 실행시 끝내줘야한다.
        }

        int nextN = n/2;

        partition(row, col, nextN);
        partition(row, col+nextN, nextN);
        partition(row+nextN, col, nextN);
        partition(row+nextN, col+nextN, nextN);


    }

    public static boolean whatcr(int row, int col, int n) {

        int color = paper[row][col];  //color를 첫번째로. 첫번째와 나머지들 비교

        for (int i = row; i < row + n; i++) {
            for (int j = col; j < col + n; j++) {
                if (paper[i][j] != color) {
                    return false;
                }
            }
        }
        return true;


    }


}
