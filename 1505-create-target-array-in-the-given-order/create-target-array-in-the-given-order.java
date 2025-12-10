class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        ArrayList<Integer> p  = new ArrayList<Integer>();

        for(int i=0;i<index.length;i++){
                p.add(index[i],nums[i]);
        }
        
        int [] ans = new int[index.length];
        for(int i=0;i<index.length;i++ ){
             ans[i] = p.get(i);
        }
        return ans;

    }
}