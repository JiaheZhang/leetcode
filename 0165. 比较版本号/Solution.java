class Solution {
    public int compareVersion(String version1, String version2) {
    	String[] version1s = version1.split("\\.");
    	String[] version2s = version2.split("\\.");
    	long[] v1 = new long[version1s.length];
    	long[] v2 = new long[version2s.length];
    	for (int i = 0; i < version1s.length; ++i) {
    		v1[i] = Long.parseLong(version1s[i]);
    	}
    	for (int i = 0; i < version2s.length; ++i) {
    		v2[i] = Long.parseLong(version2s[i]);
    	}
    	int i = 0;
    	int j = 0;
    	int res = 0;
    	while(i < v1.length && j < v2.length) {
            if (v1[i] < v2[j]) {
    			return -1;
    		} else if (v1[i] > v2[j]) {
    			return 1;
    		}
            i++;
            j++;
    	}
        while(i < v1.length) {
            if (v1[i] > 0) {
                return 1;
            }
            i++;
        }
        while(j < v2.length) {
            if (v2[j] > 0) {
                return 1;
            }
            j++;
        }

    	return 0;
	}
}