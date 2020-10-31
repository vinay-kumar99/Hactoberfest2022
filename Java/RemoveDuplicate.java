class Solution {
    String removeDuplicates(String str) {
        int le = str.length();                            /*Length of original String*/
        String st="";                                     /*Hold new String*/
        for(int i=0;i<le;i++){
            char c1=str.charAt(i);
            int l =st.length();                           /*Length of new String*/
            int x=0;
            for(int j=0;j<l;j++){
                char c2=st.charAt(j);
                if(c1==c2){
                    x=1;
                    break;
                }
            }
            if(x==1)
            continue;
            else
            st+=c1;
        }
        return st;
    }
}
