public class Main {

    public static void main(String[] args) {
        String dictionary = "../../Dataset/dictionary.txt";
        String correctme = "../../Dataset/correctme.txt";
        String stats = "../Data/stats.txt";
        long startTime = System.currentTimeMillis();
        Distance_func.distance_func(correctme, dictionary,stats);
        System.out.println("Finished in:" + (int)((System.currentTimeMillis() - startTime)/1000) + " seconds");
    }
}
