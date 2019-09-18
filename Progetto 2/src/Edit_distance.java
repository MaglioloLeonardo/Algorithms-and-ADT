public class Edit_distance {

//______________________________________________________________________
    public static int edit_distance(String s1, String s2) {
        if(s1.equals(s2)){
            return 0;
        }else if (s1.length() == 0) {
            return s2.length();
        } else if (s2.length() == 0) {
            return s1.length();
        } else {
            return distance_helper(s1, s2);
        }
    }

    private static int distance_helper(String s1, String s2){
        int dno_op, dcanc, dins, dreplace;
        if(s1.substring(0,1).equals(s2.substring(0,1)))
            dno_op = edit_distance(rest(s1), rest(s2));
        else dno_op = Integer.MAX_VALUE;

        dcanc = 1 + edit_distance(s1, rest(s2));
        dins = 1 + edit_distance(rest(s1), s2);
        dreplace = 1 + edit_distance(rest(s1), rest(s2));

        return Math.min(Math.min(dno_op,dcanc), Math.min(dins, dreplace));
    }
//______________________________________________________________________

//______________________________________________________________________
    public static int edit_distance_dyn(String s1, String s2){
        int [][] matrix = new int[s1.length()+1][s2.length()+1];//Matrix used for memoization
        for(int i=0; i<=s1.length(); i++){
            for(int j=0; j<=s2.length(); j++){
                matrix[i][j] = -1;//Matrix inizializer
            }
        }
        return  distance_dyn_helper(s1, s2, matrix);
    }

    private  static int distance_dyn_helper(String s1, String s2, int[][] matrix){
        int to_check = matrix[s1.length()][s2.length()];
        if(to_check != -1){ //check if the value was previous memoized
           return to_check;
        }else{
           if(s1.equals(s2)){
               matrix[s1.length()][s2.length()] = 0;
               return 0;
           }else if (s1.length() == 0) {
               matrix[s1.length()][s2.length()] = s2.length();
               return s2.length();
           } else if (s2.length() == 0) {
               matrix[s1.length()][s2.length()] = s1.length();
               return s1.length();
           } else {
               return distance_dyn_recursive(s1, s2, matrix);
           }
       }
    }

    private static int distance_dyn_recursive(String s1, String s2, int[][] matrix){
        int dno_op, dcanc, dins, dreplace;
        if(s1.substring(0,1).equals(s2.substring(0,1)))
            dno_op = distance_dyn_helper(rest(s1), rest(s2), matrix);
        else dno_op = Integer.MAX_VALUE;

        dcanc = 1 + distance_dyn_helper(s1, rest(s2), matrix);
        dins = 1 + distance_dyn_helper(rest(s1), s2, matrix);
        dreplace = 1 + distance_dyn_helper(rest(s1), rest(s2), matrix);

        int to_return = Math.min(Math.min(dno_op,dcanc), Math.min(dins, dreplace));
        matrix[s1.length()][s2.length()] = to_return;
        return to_return;
    }
//______________________________________________________________________

    private static String rest(String S){
        if(S != null)
            return S.substring(1);
        else return "";
    }

}
