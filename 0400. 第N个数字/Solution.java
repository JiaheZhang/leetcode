class Solution {
    public int findNthDigit(int n) {
    	int num = 1;
    	int len = 0;
    	while (len < n) {
            int numLen = getLen(num);
    		if (numLen + len < n) {
    			len += numLen;
    			num++;
    		} else {
                return getNum(num, n - len - 1);
    		}
    	}
        return -1;
    }

    private int getLen(int i) {
        if (i == 0) {
            return 1;
        }
        int len = 0;
        while(i > 0) {
            len++;
            i/=10;
        }
        return len;
    }

    private int getNum(int i, int lastIndex) {
        while(lastIndex > 0) {
            i /= 10;
            lastIndex--;
        }
        return i % 10;
    }
}