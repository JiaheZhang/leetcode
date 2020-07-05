import java.util.Arrays;

public class s0057 {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if(newInterval.length == 0) return intervals;
        if(intervals.length == 0){
            return new int[][] {{newInterval[0],newInterval[1]}};
        }

        int[][] resTmp = Arrays.copyOf(intervals, intervals.length+1);
        // 浅拷贝
        resTmp[intervals.length] = newInterval;

        Arrays.sort(resTmp,(a,b) -> a[0]-b[0]);

        int[][] res = new int[resTmp.length][2];
        int index = 0;

        res[0][0] = resTmp[0][0];
        res[0][1] = resTmp[0][1];
        

        for(int i = 1;i < resTmp.length;i++){
            if(resTmp[i][0] <= res[index][1]){
                res[index][1] = Math.max(res[index][1], resTmp[i][1]);
            }
            else{
                index++;
                res[index][0] = resTmp[i][0];
                res[index][1] = resTmp[i][1];
            }
        }
        return Arrays.copyOf(res, index+1);

    }

    public static void main(String[] args) {
        s0057 s = new s0057();
        int[][] intervals = new int[][]{{1,3},{6,9}};
        int [] newInterval = new int[]{2,5};
        s.insert(intervals, newInterval);
    }
}