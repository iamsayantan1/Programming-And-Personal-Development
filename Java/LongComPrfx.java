import java.util.Scanner;
public class LongComPrfx {
    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        System.out.println("Enter how many words you want to compare: ");
        int num = sc.nextInt();
        String[] words = new String[num];
        for (int i = 0; i < num; i++)   {
            words[i] = sc.nextLine();
        }
        String result = Solution.longestCommonPrefix(words);
        System.out.println(result);
    }
}

class Solution {
    public static String longestCommonPrefix(String[] strs) {
        int len=Integer.MAX_VALUE;
        Boolean flag = false;
        String lcp = "";
        for(String item : strs) {
            if(item.length() < len)
                len = item.length();
        }
        
        for(int i=0;i<len;i++)  {
            char f_item = strs[0].charAt(i);
            for(String item : strs) {
                if(item.charAt(i) != f_item)    {
                    flag = true;
                    break;   
                }
            }
            if(flag)    break;
            lcp = lcp+f_item;
        }
        return lcp;
    }
}