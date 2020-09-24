class Solution {
	private Set<Integer> set;
	private List<List<Integer>> edges;
	private boolean res = true;
    public boolean canFinish(int numCourses, int[][] prerequisites) {
    	edges = new ArrayList<>();
    	set = new HashSet<>();
    	for (int i = 0; i < numCourses; ++i) {
    		edges.add(new ArrayList<>());
    	}
    	for (int[] prerequisite : prerequisites) {
    		edges.get(prerequisite[0]).add(prerequisite[1]);
    	}
    	for (int i = 0; i < numCourses; ++i) {
    		DFS(i, new HashSet<>());
    	}

    	return res;
    }

    private void DFS(int node, Set<Integer> path) {
    	if (res = false) {
    		return;
    	}
    	if (set.contains(node)) {
    		return;
    	}
    	path.add(node);
    	for (int i : edges.get(node)) {
    		if (path.contains(i)) {
    			res = false;
    			return;
    		}
    		DFS(i, path);
    	}
    	set.add(node);
    	path.remove(node);
    }
}