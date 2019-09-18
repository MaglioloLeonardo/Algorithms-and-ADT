import java.util.List;

public class Main {
    public static void main(String[] args) {
        String path_dataset = "../../../../Datasets/italian_dist_graph.csv";
        long start = System.currentTimeMillis();
        List<Edge>MST = MSTDataset.MST(path_dataset);
        float weight = 0;
        if(MST != null) {
            for (Edge edge : MST) {
                weight += edge.getWeight();
            }
            System.out.println("N Edges: " + MST.size() +  "\nWeight MST: " + (int)weight + " in KM:" + weight/1000);
        }
        System.out.println("Runtime(Seconds): " + (System.currentTimeMillis() - start)/1000);
    }
}
