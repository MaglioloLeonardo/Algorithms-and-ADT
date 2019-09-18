import java.io.*;
import java.util.*;

public class MSTDataset {
    public static List<Edge> MST(String path_dataset){
        try {
            Scanner dataset = new Scanner(new File(path_dataset));
            Graph G = new Graph(false);
            int row = 0;
            while (dataset.hasNext()){
                String line = dataset.nextLine(); row++; //dataset line update
                String[] separated = line.split(",");
                if(separated.length != 3)throw new Error("Dataset is not consistent at line: " + row);
                G.Add_edge(separated[0], separated[1], Float.valueOf(separated[2]));
            }
            return Kruskal.Mst(G);
            //return G.Get_edges();
        }catch (IOException e){
            e.printStackTrace();
            return null;
        }
    }

}
