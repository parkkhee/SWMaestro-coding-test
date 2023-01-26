package test;

import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static char[] chr;
    static ArrayList<Character> arrs = new ArrayList<>();
    static ArrayList<Character> arre = new ArrayList<>();

    public static void main(String[] args) throws IOException {

        String str = br.readLine();

        chr = new char[str.length()];

        for (int i = 0; i < str.length(); i++) {

            chr[i] = str.charAt(i);

        }

        Arrays.sort(chr);

        for (int i = 0; i < chr.length; i++) {

            if (i == chr.length - 1) {
                break;
            }

            if (chr[i] == chr[i + 1]) {

                arrs.add(chr[i]);
                arre.add(chr[i + 1]);

            }

            if (chr[i] != chr[i + 1] && i < chr.length) {
                System.out.println("I'm Sorry Hansoo");
                System.exit(0);
            }
            i++;

        }

        String answer="";

        for (int i = 0; i < arrs.size(); i++) {

            answer += arrs.get(i);

        }
        for (int i = arre.size()-1; i >= 0; i--) {
            answer += arrs.get(i);
        }

        System.out.println(answer);

    }

}



