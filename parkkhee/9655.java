package test;
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main { //쉬운 dp문제라했는데,, 뭔가 dp로 풀지 못한 느낌,,
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(br.readLine());

        if (n % 2 == 0) {
            System.out.println("CY");
        } else {
            System.out.println("SK");
        }


    }


}

