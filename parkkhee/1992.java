
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[][] video;
    static int n;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        video = new int[n][n];

        for (int i = 0; i < n; i++) {
            String str = "";
            str += br.readLine();
            for (int j = 0; j < n; j++) {

                video[i][j] = str.charAt(j) - '0';  // 변수 위치 신경쓰자,,


            }


        }



        re(0, 0, n);

        System.out.println(sb);


    }

    public static void re(int x, int y, int size) {

        if (scheck(x, y, size)) {
            numcheck(x, y);
        } else {
            sb.append("(");
            re(x,y,size/2);
            re(x,y+size/2,size/2);
            re(x+size/2, y, size/2);
            re(x+size/2,y+size/2,size/2);
            sb.append(")");
        }


    }

    public static void numcheck(int x, int y) {

        if (video[x][y] == 0) {
            sb.append(0);
        } else {
            sb.append(1);
        }

    }

    public static boolean scheck(int x , int y, int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {

                if(video[x][y] != video[i+x][j+y]){
                    return false;

                }
            }
        }
        return true;
    }

}



