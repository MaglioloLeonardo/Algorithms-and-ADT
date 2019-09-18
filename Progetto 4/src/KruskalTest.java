import org.junit.Test;
import static org.junit.Assert.*;
public class KruskalTest {
    @Test
    public void MST_test_1(){
        Graph G = new Graph(false);
        G.Add_edge("a", "b", 4);
        G.Add_edge("a", "h", 8);

        G.Add_edge("b", "h", 11);
        G.Add_edge("b", "c", 8);

        G.Add_edge("c", "i", 2);
        G.Add_edge("c", "d", 7);
        G.Add_edge("c", "f", 4);

        G.Add_edge("d", "f", 14);
        G.Add_edge("d", "e", 9);

        G.Add_edge("e", "f", 10);

        G.Add_edge("g", "f", 2);
        G.Add_edge("g", "i", 6);

        G.Add_edge("h", "g", 1);
        G.Add_edge("h", "i", 7);

        String result = "[(h, g|1.0), (i, c|2.0), (g, f|2.0), (f, c|4.0), (b, a|4.0), (d, c|7.0), (h, a|8.0), (e, d|9.0)]";
        assertEquals(Kruskal.Mst(G).toString(),result);
    }
}
