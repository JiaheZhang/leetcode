// 0079 回溯
class Solution {
	private int [][] isVisit;
	private int [][] directions = {{1,0},{0,1},{-1,0},{0,-1}};
	private int m;
	private int n;
    public boolean exist(char[][] board, String word) {
    	m = board.length;
    	if(m == 0) return false;
    	n = board[0].length;

    	isVisit = new int[m][n];

    	for (int i = 0; i < m; i++) {
    		for (int j = 0;j < n;j++) {
    			if (traceBack(board,word,0,i,j)) {
    				return true;
    			}
    		}
    	}

    	return false;
    }

    private boolean inBoard(int i, int j){
    	return i < m && i >= 0 && j >= 0 && j < n && isVisit[i][j] == 0;
    }

    private boolean traceBack(char[][] board, String word, int index, int i, int j) {
    	if (index >= word.length()) {
    		return true;
    	}

    	if (!inBoard(i,j)) {
    		return false;
    	}

    	if (board[i][j] != word.charAt(index)) {
    		return false;
    	}

    	isVisit[i][j] = 1;

    	for(int p = 0;p < 4;p++){
    		int ii = i + directions[p][0];
    		int jj = j + directions[p][1];
			if (traceBack(board,word,index+1,ii,jj)) {
				return true;
    		}
    	}
    	isVisit[i][j] = 0;
    	return false;
    }
}