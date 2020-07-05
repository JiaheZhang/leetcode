import java.lang.reflect.Array;
import java.util.*;

public class s5406 {
    static int num;
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        num = n;
        int[][] edgeMtx = new int[n][n];
        for(int[] i : edges){
            edgeMtx[i[0]][i[1]] = 1;
        }
        int time = nodetime(0,edgeMtx,hasApple);
        if(time == -1) return 0;
        else return time;
    }
    static int nodetime(int node, int[][] edgeMtx, List<Boolean> hasApple){
        int leftNode = -1,rightNode=-1;
        int has = -1;
        if(hasApple.get(node)){
            has = 0;
        } 
        int timeAll = 0;
        for(int i = 0;i < num;i++){
            if(edgeMtx[node][i] == 1){
                int time = nodetime(i,edgeMtx,hasApple);
                if(time == -1) continue;
                else{
                    timeAll += (time+2);
                }
            }
        }
        if(timeAll == 0){
            return has;
        }
        else{
            return timeAll;
        }
    }


    public static void main(String[] args) {
        s5406 s = new s5406();
        // int[][] edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
        // List<Boolean> hasApple = Arrays.asList(false,false,true,false,true,true,false);
        // int n = 7;
        int[][] edges = {{0,1},{1,2},{2,3},{1,4},{2,5},{2,6},{4,7}};
        List<Boolean> hasApple = Arrays.asList(true,true,false,true,false,true,true,false);
        int n = 8;
        int t = s.minTime(n, edges, hasApple);
        System.out.println(t);
    }
}