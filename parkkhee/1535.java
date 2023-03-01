package test;

import java.io.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static int[] HealthArr, HappyArr;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        
        N = Integer.parseInt(br.readLine());
        HealthArr = new int[N+1];
        HappyArr = new int[N+1];
        dp = new int[N+1][100];

        StringTokenizer Healthst = new StringTokenizer(br.readLine());
        StringTokenizer Happyst = new StringTokenizer(br.readLine());
        for (int i = 1; i < N+1; i++) {
            HealthArr[i] = Integer.parseInt(Healthst.nextToken());
            HappyArr[i] = Integer.parseInt(Happyst.nextToken());
        }

    }



}


