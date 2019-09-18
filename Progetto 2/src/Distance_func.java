import java.io.*;
import java.util.*;
public class Distance_func {

    public static void distance_func(String path_list, String path_to_compare, String path_stats ) {
        try {
            Scanner list = new Scanner(new File(path_list));//Scanner list

            File stats = new File(path_stats);
            stats.delete(); stats.createNewFile(); //remove previous values
            BufferedWriter print_stats = new BufferedWriter(new FileWriter(path_stats));

            while (list.hasNext()) {
                String list_word = list.next(); //word from first list
                int min_distance = Integer.MAX_VALUE;
                String min_compared = "";
                if(!word_check(list_word))list_word = list_word.substring(0, list_word.length()-1);
                Scanner to_compare = new Scanner(new File(path_to_compare)); //Scanner list to compare
                while (to_compare.hasNext()) {
                    String to_compare_word = to_compare.next(); //word form list used to compare
                    if(!word_check(to_compare_word))to_compare_word = to_compare_word.substring(0, to_compare_word.length()-1);
                    int distance = Edit_distance.edit_distance_dyn(list_word, to_compare_word);
                    //_________________________STATS__________________________________________
                    if(min_distance >= distance){
                        if(min_distance == distance){
                            if(min_compared.length() != 0)min_compared += ", ";
                            min_compared += to_compare_word;
                        }else{
                            min_compared = to_compare_word;
                            min_distance = distance;
                        }
                    }
                }
                String message =  list_word + "| Min distance:" + min_distance + " words: [" + min_compared + "]\n";
                print_stats.write(message);
                to_compare.close();
            }

            list.close(); print_stats.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static boolean word_check(String word){
        //If last char != alpha returns false
        char last = word.charAt(word.length()-1);
        if((last>='A' && last<='Z') || (last>='a' && last<= 'z')){
            return true;
        }else{
            return false;
        }
    }

}
