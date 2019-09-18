import java.util.Collections;
import java.util.ArrayList;
import java.util.List;

public class Kruskal {

    public static List<Edge> Mst(Graph G){
        List<Object> vertices = G.Get_nodes();
        List<Edge> edges = G.Get_edges(), toReturn = new ArrayList<>();
        Collections.sort(edges);
        UnionFindSet P = new UnionFindSet();
        List<Node> nodes = P.makeSet(vertices);
        for (Edge edge: edges){
            Node nodeU = Search_node(nodes, edge.getU());
            Node nodeV = Search_node(nodes, edge.getV());
            if(nodeU == null || nodeV == null)throw new Error("Internal error MAKESET");
            if(P.findPartition(nodeU) != P.findPartition(nodeV)){
                toReturn.add(edge);
                P.union(nodeU, nodeV);
            }
        }
        return toReturn;
    }

    private static Node Search_node(List<Node> list, Object obj){
        for(Node node: list){
            if(node.getKey().equals(obj))return node;
        }
        return null;
    }

}
