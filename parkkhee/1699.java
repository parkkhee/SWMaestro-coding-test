package test;

import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int num;
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {

        num = Integer.parseInt(br.readLine());

        re(num);

    }

    public static int re(int n) {

        for (int i = 1; i <= n; i++) {

            if (n < i * i) {
                break;
            } else if (n == i * i) {
                System.out.println(1);
                System.exit(0);
            } else {
                min = Math.min(min, re());
            }


        }


    }



}



