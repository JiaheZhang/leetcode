class Solution {
	private List<String> res = new ArrayList<>();
    public List<String> restoreIpAddresses(String s) {
        traceBack(new ArrayList(),s,0);
        return res;
    }

    private void traceBack(List<String> sb, String s, int index) {
		
    	if (index > s.length()) {
    		return;
		}
		if (sb.size() > 4) {
			return;
		}
		
		if (sb.size() == 4){
			if(index == s.length()) {
				StringBuffer fuck = new StringBuffer();
				for(String _sb:sb){
					fuck.append(_sb).append(".");
				}
                fuck.deleteCharAt(fuck.length()-1);
				res.add(fuck.toString());
				return;
			}
		}
    	
    	for (int i = index+1;i <= Math.min(s.length(),index+4) ;i++ ) {
    		//todo 剪枝
			String substr = s.substring(index,i);
			int n = Integer.parseInt(substr);
			if (n > 255){
				break;
			}
			sb.add(substr);
			
			traceBack(sb,s,i);
			sb.remove(sb.size()-1);
			if (n == 0) {
				break;
			}
		}
    }
}