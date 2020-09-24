class TreeNode {
    char val;

    List<TreeNode> children;

    public TreeNode(char c) {
        this.val = c;
        children = new ArrayList<>();
    }
}


class Trie {

    private TreeNode root;

    /** Initialize your data structure here. */
    public Trie() {
        root = new TreeNode('/');
    }   
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        word += '/';
        TreeNode p = root;
        for (int i = 0; i < word.length(); ++i) {
            p = findAndInsertNode(p.children, word.charAt(i));
        }

    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        return searchWithStatus(word, false);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        return searchWithStatus(prefix, true);
    }

    private boolean searchWithStatus(String s, boolean isPrefix) {
        int len = s.length();
        if (len == 0) {
            return true;
        }
        TreeNode p = root;
        for (int i = 0; i < len; ++i) {
            p = findNode(p.children, s.charAt(i));
            if (p == null) {
                return false;
            }
        }

        if (isPrefix) {
            return true;
        }

        return findNode(p.children, '/') != null;
    }

    private TreeNode findNode(List<TreeNode> children, char c) {
        for (TreeNode p : children) {
            if (p.val == c) {
                return p; 
            }
        }
        return null;
    }

    private TreeNode findAndInsertNode(List<TreeNode> children, char c) {
        for (TreeNode p : children) {
            if (p.val == c) {
                return p; 
            }
        }
        TreeNode p = new TreeNode(c);
        children.add(p);
        return p;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */