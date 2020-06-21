// O(N^2)
class Solution {
    public int largestRectangleArea(int[] heights) {
    	int len = heights.length;
    	if (len == 0) {
    		return 0;
    	}
    	int maxArea = Integer.MIN_VALUE;
    	for (int i = 0; i < len; i++) {
    		int left = i,right = i;
    		while (left >= 0 && heights[left] >= heights[i]) {
    			left--;
    		}
    		while (right < len  && heights[right] >= heights[i]) {
    			right++;
    		}
    		int area = (right - left - 1) * heights[i];
    		if (area > maxArea) {
    			maxArea = area;
    		}
    	}
    	return maxArea;
    }
}

//stack
class Solution {
    public int largestRectangleArea(int[] heights) {
    	if (heights.length == 0) {
    		return 0;
    	}
    	if (heights.length == 1) {
    		return heights[0];
    	}

    	Deque<Integer> stack = new ArrayDeque<>();
    	int maxArea = Integer.MIN_VALUE;

    	for (int i = 0;i <= heights.length;i++) {
    		while (!stack.isEmpty() && (i == heights.length || heights[i] < heights[stack.peekLast()])) {
    			int hIdx = stack.pollLast();
    			int area = 0;
    			// 相等的过滤
    			while (!stack.isEmpty() && heights[stack.peekLast()] == heights[hIdx]) {
    				stack.pollLast();
    			}
    			if (stack.isEmpty()) {
    				area = i * heights[hIdx];
    			} else {
    				area = (i - stack.peekLast()-1) * heights[hIdx];
    				// area = (hIdx - stack.peekLast()) * heights[hIdx];
    			}
    			if (area > maxArea) {
    				maxArea = area;
    			}
    		}
    		stack.addLast(i);
    	}
    	return maxArea;
    }
}








