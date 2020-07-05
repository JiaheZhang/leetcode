public class s0058 {
    public int lengthOfLastWord(String s) {
        String[] strs = s.split(" ");
        if(strs.length == 0) return 0;

        return strs[strs.length-1].length();
    }
}