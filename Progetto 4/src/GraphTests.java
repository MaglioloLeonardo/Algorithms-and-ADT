import org.junit.Test;
import java.util.ArrayList;
import java.util.List;
import static org.junit.Assert.*;

public class GraphTests {
    int len = 100;
    //Gen list of size len and put all the elements and put the elements in graph G
    private List<Integer> List_gen(int len, Graph G){
        List<Integer> list = new ArrayList<>();
        for(int i=0; i<len; i++){
            list.add(new Integer(i));
            G.Add_node(list.get(i)); //List_gen depends on Add_node
        }
        return list;
    }

    //Given G and the list of elements in G, then G becomes complete
    private void Complete_graph(List<Integer> elements, Graph G){
        for (Integer i: elements) {
            for (Integer j: elements) {
                G.Add_edge(i, j, i+j);
            }
        }
    }

    @Test
    public void Add_node(){
        Graph G = new Graph(true);
        List<Integer> list = List_gen(len, G);
        for(Integer i: list){
            assertTrue(G.Contains_node(list.get(i))); //Add-test depend on Contains_node
        }
    }

    @Test
    public void Add_Edge(){
        //if Graph is direct
        Graph G = new Graph(true);
        List<Integer> list = List_gen(len, G);
        int index1 = 0, index2 = 1;
        G.Add_edge(list.get(index1), list.get(index2), 3);
        for (Integer i:list) {
            for (Integer j:list) {
                if(i == index1 && j == index2){//(i,j)
                    assertTrue(G.Contains_edge(list.get(i), list.get(j))); //depends on Contains_edge
                }else{
                    assertFalse(G.Contains_edge(list.get(i), list.get(j)));
                }
            }
        }
        //if Graph is not direct
        Graph G1 = new Graph(false);
        G1.Add_edge(list.get(index1), list.get(index2), 3);
        for (Integer i:list) {
            for (Integer j:list) {
                if((i == index1 && j == index2) || (j == index1 && i == index2)){ //(i,j) and (j,i)
                    assertTrue(G1.Contains_edge(list.get(i), list.get(j))); //depends on Contains_edge
                }else{
                    assertFalse(G1.Contains_edge(list.get(i), list.get(j)));
                }
            }
        }
    }

    @Test
    public void Delete_Node(){
        Graph G = new Graph(true);
        List<Integer> list = List_gen(len, G);
        Complete_graph(list, G);//G now is a complete graph
        G.Delete_node(list.get(0));
        for (Integer i:list) {
            for (Integer j:list) {
                if(i == list.get(0) || j == list.get(0)){ //if u is deleted in G there are no (u,v) and (v,u)
                    assertFalse(G.Contains_edge(list.get(i), list.get(j))); //depends on Contains_edge
                }else{
                    assertTrue(G.Contains_edge(list.get(i), list.get(j)));
                }
            }
        }
    }

    @Test
    public void Delete_Edge(){
        //G is direct
        Graph G = new Graph(true);
        List<Integer> list = List_gen(len, G);
        Complete_graph(list, G);//G now is a complete graph
        G.Delete_edge(list.get(0), list.get(1));
        for (Integer i:list) {
            for (Integer j:list) {
                if(i == list.get(0) && j == list.get(1)){ //if (u,v) was deleted (u,v) cannot exist
                    assertFalse(G.Contains_edge(list.get(i), list.get(j))); //depends on Contains_edge
                }else{
                    assertTrue(G.Contains_edge(list.get(i), list.get(j)));
                }
            }
        }
        //G is not direct
        Graph G1 = new Graph(false);
        list = List_gen(len, G1);
        Complete_graph(list, G1);//G1 now is a complete graph
        G1.Delete_edge(list.get(0), list.get(1));
        for (Integer i:list) {
            for (Integer j:list) {
                if((i == list.get(0) && j == list.get(1))||(j == list.get(0) && i == list.get(1))){
                    //if (u,v) was deleted (u,v) and (v,u) cannot exist
                    assertFalse(G1.Contains_edge(list.get(i), list.get(j))); //depends on Contains_edge
                }else{
                    assertTrue(G1.Contains_edge(list.get(i), list.get(j)));
                }
            }
        }
    }

    @Test
    public void Nodes_number(){
        Graph G = new Graph(true);
        List_gen(len, G);
        assertEquals(len, G.Nodes_number());
    }

    @Test
    public void Edges_number(){
        Graph G = new Graph(true);
        List<Integer> list = List_gen(len, G);
        Complete_graph(list, G);
        //if G is completed then it should have len*len edges
        assertEquals(len*len, G.Edge_number());
    }

    @Test
    public void Nodes_list() {
        Graph G = new Graph(true);
        List<Integer> list = List_gen(len, G);
        List<Object> elements = G.Get_nodes();
        assertTrue(list.containsAll(elements) && elements.containsAll(list));
    }

    @Test
    public void Edges_map() {
        Graph G = new Graph(true);
        List<Integer> list = List_gen(len, G);
        Complete_graph(list, G);
        List<Edge> edges = G.Get_edges();
        assertEquals(list.size() * list.size(), edges.size());
        for (Integer i: list){
            for (Integer j: list){
                boolean test = false;
                for (Edge edge: edges) {
                    if(edge.getU() == i && edge.getV() == j){
                        test = true; break;
                    }
                }
                //for each u,v in list G should have the edge (u,v)
                assertTrue(test);
            }
        }
    }

    @Test
    public void Adj_nodes(){
        Graph G = new Graph(true);
        List<Integer> list = List_gen(len, G);
        Complete_graph(list, G);
        for(Integer i:list) {
            List<Object> temp = G.Adj_nodes(i);
            //if G is complete then for all u,v in G: adj[u] contains v
            //u,v are also elements of list 
            assertTrue(list.containsAll(temp) && temp.containsAll(list));
        }
    }

}
