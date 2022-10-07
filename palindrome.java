// Java program to illustrate checking of a string
// if its palindrome or not using reverse function
class Palindrome
{
public static void checkPalindrome(String s)
{
	// reverse the given String
	String reverse = new StringBuffer(s).reverse().toString();

	// check whether the string is palindrome or not
	if (s.equals(reverse))
	System.out.println("Yes");

	else
	System.out.println("No");
}

public static void main (String[] args)
			throws java.lang.Exception
{
	checkPalindrome("malayalam");
	checkPalindrome("GeeksforGeeks");
}
}
