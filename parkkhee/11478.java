
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String str;
    static Set<String> set= new HashSet<>(); //*

    public static void main(String[] args) throws IOException {

        str = br.readLine();

        for (int i = 0; i < str.length(); i++) {

            for (int j = i + 1; j <= str.length(); j++) {
                set.add(str.substring(i, j)); //내장함수 사용
            }

        }

        System.out.println(set.size());
    }



}



