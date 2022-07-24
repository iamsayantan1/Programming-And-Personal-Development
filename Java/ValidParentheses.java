import java.util.Scanner;

public class ValidParentheses {
    public static void main(String[] args) {
        // Taking input from the user.
        var sc = new Scanner(System.in);
        System.out.print("Take Parentheses Input: ");
        String parentheses = sc.nextLine();
        
        // Printing the answer.
        if(Solution.isValid(parentheses))
            System.out.println("Parentheses is valid.");
        else
            System.out.println("Parentheses is invalid.");
    }
}

class Solution {
    public static boolean isValid(String s) {
        var sb = new StringBuilder();
        while(sb.length()>0 && sb.length()%2 == 0)  {
            switch(sb.charAt(0))    {
                case '(':  {
                    sb.delete(0,1);
                    if(sb.charAt(0) == ')') {
                        sb.delete(0,1);
                        break;
                    }
                    else if(sb.charAt(sb.length()-1) == ')')    {
                        sb.delete(sb.length()-1, sb.length());
                        break;
                    }
                    else return false;
                }
                case '{':   {
                                        sb.delete(0,1);
                    if(sb.charAt(0) == '}') {
                        sb.delete(0,1);
                        break;
                    }
                    else if(sb.charAt(sb.length()-1) == '}')    {
                        sb.delete(sb.length()-1, sb.length());
                        break;
                    }
                    else return false;
                }
                case '[':   {
                    sb.delete(0,1);
                    if(sb.charAt(0) == ']') {
                        sb.delete(0,1);
                        break;
                    }
                    else if(sb.charAt(sb.length()-1) == ']')    {
                        sb.delete(sb.length()-1, sb.length());
                        break;
                    }
                    else return false;
                }
                default:    {
                    return false;
                }
            }
        }
        return true;
    }
}