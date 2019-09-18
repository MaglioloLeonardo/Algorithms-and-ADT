import org.junit.AfterClass;
import org.junit.Test;
import java.util.ArrayList;
import java.util.List;
import static org.junit.Assert.*;
public class TreeTest {
    @Test
    public void add_elem_cardinality() {
        List<Object> objects = new ArrayList<>();
        Tree tree = new Tree();
        for(int i = 1; i<=10; i++){
            objects.add(new Integer(i));
            tree.add(objects.get(i-1));
            assertEquals(i, tree.getCardinality());
        }
    }

    @Test
    public void add_tree_cardinality() {
        List<Object> objects = new ArrayList<>();
        Tree temp = new Tree(); int i;
        for(i = 1; i<=10; i++){
            objects.add(new Integer(i));
            temp.add(objects.get(i-1));
        }
        Tree tree = new Tree(); tree.add(new Integer(11));
        tree.add(temp);
        assertEquals(i, tree.getCardinality());
    }

    @AfterClass
    public static void search_test() {
        List<Object> objects = new ArrayList<>();
        Tree temp = new Tree(); int i;
        for(i = 0; i<10; i++){
            objects.add(new Integer(i));
            temp.add(objects.get(i));
        }
        objects.add(new Integer(10));
        Tree tree = new Tree(); tree.add(objects.get(i));
        tree.add(temp);
        for(i = 0; i<objects.size(); i++){
            assertEquals(objects.get(i), tree.search(objects.get(i)).getKey());
        }
    }
}
