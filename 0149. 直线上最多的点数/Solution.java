class Solution {
    public int maxPoints(int[][] points) {
        if (points.length <= 1) {
            return points.length;
        }
        int res = 0;
        for (int i = 0; i < points.length; ++i) {
            for (int j = i + 1; j < points.length; ++j) {
                long[] ABC = getABC(points[i], points[j]);
                int nums = 2;
                for (int k = 0; k < points.length; ++k) {
                    if (k != i && k != j) {
                        if (ABC[0] == 0 && ABC[1] == 0 && ABC[2] == 0) {
                            if (points[k][0] == points[i][0] && points[k][1] == points[i][1]) {
                                nums++;
                            }
                        } else if (isOnLine(ABC, points[k])) {
                            nums++;
                        }
                    }
                }
                if (nums > res) {
                    res = nums;
                }
            }
        }
        return res;
    }

    private long[] getABC(int[] p1, int[] p2) {
        long[] ABC = new long[3];
        ABC[0] = p2[1] - p1[1];
        ABC[1] = p2[0] - p1[0];
        ABC[2] = (long)(p2[1] - p1[1]) * p1[0] - (long) (p2[0] - p1[0]) * p1[1];
        return ABC;
    }

    private boolean isOnLine(long[] ABC, int[] point) {
		long a = ABC[0] * (long) point[0];
		long b = ABC[1] * (long) point[1];
        return ABC[2] == a - b;
    }
}