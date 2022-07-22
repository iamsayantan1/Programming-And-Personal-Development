import java.util.Scanner;

public class RomanNumber {
    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        System.out.print("Take Input: ");
        String roman = sc.nextLine();
        int numerical = Solution.romanToInt(roman);
        System.out.println("Ans: "+numerical+" .");
    }
}

class Solution {
    public static int romanToInt(String s) {
        int num = 0;
        int l = s.length();


        for(int i = l-1 ; i>=0 ; i--) {
            char ea = s.charAt(i);
            switch(ea)
            {
                case 'I':
                {
                    if((i+1 != l) && (s.charAt(i+1) == 'V' || s.charAt(i+1) == 'X'))
                        num --;
                    else
                        num ++;
                    break;
                }
                case 'V': num += 5;
                    break;
                case 'X':
                {
                    if((i+1 != l) && (s.charAt(i+1) == 'L' || s.charAt(i+1) == 'C'))
                        num -= 10;
                    else
                        num += 10;
                    break;
                }
                case 'L': num += 50;
                    break;
                case 'C':
                {
                    if((i+1 != l) && (s.charAt(i+1) == 'D' || s.charAt(i+1) == 'M'))
                        num -= 100;
                    else
                        num += 100;
                    break;
                }
                case 'D': num += 500;
                    break;
                case 'M': num += 1000;
                    break;
            }
        }
        return num;
    }
}