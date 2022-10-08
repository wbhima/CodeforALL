//https://leetcode.com/problems/valid-anagram/

class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()) return false;
        
        int chars[]=new int[26];
        for(char c : s.toCharArray())
        {
            chars[c-'a']++;
        }
        
        for(char c : t.toCharArray())
        {
            if(--chars[c-'a']<0)
                return false;
        }
        return true;
    }
}
