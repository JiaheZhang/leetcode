import java.lang.Math;
import java.util.Arrays;
// import java.util.Comparator;

// class CMP implements Comparator<int[]>{

//     public int compare(int[] a,int[] b){

//         if(a[0] < b[0]){
//             return -1;
//         }
//         else if(a[0] > b[0]){
//             return 1;
//         }
//         else{
//             return 0;
//         }

//     }
// }

public class s0056 {

    public int[][] merge(int[][] intervals) {
        if(intervals.length == 1 || intervals.length == 0) return intervals;

        Arrays.sort(intervals, (a,b) -> a[0]-b[0]);;

        int[][] res = new int[intervals.length][2];
        int index = 0;
        res[0][0] = intervals[0][0];
        res[0][1] = intervals[0][1];

        for(int i = 1;i < intervals.length;i++){
            if(intervals[i][0] <= res[index][1]){
                res[index][1] = Math.max(intervals[i][1],res[index][1]);
            }
            else{
                index++;
                res[index][0] = intervals[i][0];
                res[index][1] = intervals[i][1];
            }

        }

        return Arrays.copyOf(res, index+1);
    }
}