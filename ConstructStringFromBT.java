class Solution {
    
    public String tree2str(TreeNode root) 
    {
        String ans = "";
         if(root == null)
         {
            return ans;
         }
         ans += Integer.toString(root.val);
         ans += '(';
         ans += tree2str(root.left);
         ans += ')';
         ans += '(';
         ans += tree2str(root.right);
         if(ans.charAt(ans.length()-1) == '(')
         {
            if(ans.length()>=3 && ans.charAt(ans.length()-2) == ')' && ans.charAt(ans.length()-3) == '(')
            ans = ans.substring(0,ans.length()-3);
            else
            ans = ans.substring(0,ans.length()-1);
         }
         else
         ans += ')';
         return ans;
    }
}
