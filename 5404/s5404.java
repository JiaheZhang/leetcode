import java.util.ArrayList;
import java.util.List;

public class s5404 {
    public List<String> buildArray(int[] target, int n) {
        int i = 1;
        List<String> res = new ArrayList<>();
        int j = 0;
        while(j < target.length){
            if(target[j] != i){
                res.add("Push");
                res.add("Pop");
                i++;
            }
            else{
                res.add("Push");
                j++;
            }
        }
        return res;

    }
}