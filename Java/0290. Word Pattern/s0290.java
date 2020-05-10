import java.util.*;

public class s0290{
    public boolean wordPattern(String pattern, String str) {
        String[] strSet = str.split(" ");
        if(strSet.length != pattern.length()) return false;
        
        HashMap<Character,Integer> charMap = new HashMap<Character, Integer>();
        HashMap<String,Integer> stringMap = new HashMap<String, Integer>();
        Integer id = 0;


        for(int i = 0;i < pattern.length();i++){
            Integer chVal = charMap.get(pattern.charAt(i));
            Integer strVal = stringMap.get(strSet[i]);
            
//            both are null
            if(chVal == null && strVal == null) {
            	charMap.put(pattern.charAt(i),id);
                stringMap.put(strSet[i],id);
                id++;
            }
            else if(chVal != null && strVal != null) {
//            	valid
            	if(chVal.equals(strVal)){
            		continue;
            	}
//            	invalid
            	else {
            		return false;
            	}
            }
//            one is null, another is not null;
            else {
            	return false;
            }
        }

        return true;



    }
    public static void main(String[] args){

    }
}
