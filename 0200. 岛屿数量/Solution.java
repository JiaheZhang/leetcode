class Solution {
	private int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	private Set<Integer> set = new HashSet<>();

    public int numIslands(char[][] grid) {
    	int n = grid.length;
    	if (n == 0) {
    		return 0;
    	}
    	int m = grid[0].length;
    	int[][] islands = new int[n][m];
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			DFS(grid, islands, i, j, set.size() + 1);
    		}
    	}
    	return set.size();
    }

    private void DFS(char[][] grid, int[][] islands, int x, int y, int islandId) {
    	if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length) {
    		return;
    	}
    	if (islands[x][y] > 0 || grid[x][y] == '0') {
    		return;
    	}
    	islands[x][y] = islandId;
    	set.add(islandId);
    	for (int i = 0; i < directions.length; ++i) {
    		DFS(grid, islands, x + directions[i][0], y + directions[i][1], islandId);
    	}
    }
}