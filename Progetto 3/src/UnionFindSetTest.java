import org.junit.AfterClass;
import org.junit.Test;
import java.util.ArrayList;
import java.util.List;
import static org.junit.Assert.*;
public class UnionFindSetTest {
    @Test
    public  void find_empty_set(){
        UnionFindSet set = new UnionFindSet();
        assertEquals(set.find(0), null);
    }

    @Test
    public  void makeSet_test(){
        UnionFindSet set = new UnionFindSet();
        set.makeSet(new Integer(1)); set.makeSet(new Integer(2));
        Integer test = new Integer(3);
        set.makeSet(test); set.makeSet(test);
        //makeSet depends on findSet, findSet depends on makeSet in most of the cases
        assertEquals("{{1}, {2}, {3}}", set.toString());
    }

    @Test
    public void find_set(){
        List<Object> objects = new ArrayList<>();
        UnionFindSet set = new UnionFindSet(); int i;
        for(i = 0; i<10; i++){
            objects.add(new Integer(i));
            set.makeSet(objects.get(i));
            assertEquals(objects.get(i), set.find(objects.get(i)));
        }
        assertNull(set.find(new Integer(i)));
    }

    @AfterClass
    public static void  union_test(){
        List<Object> objects = new ArrayList<>();
        UnionFindSet set = new UnionFindSet();
        for(int i = 0; i<5; i++){
            objects.add(new Integer(i));
            set.makeSet(objects.get(i));
        }
        set.union(objects.get(0), objects.get(4));
        assertEquals("{{0, 4}, {1}, {2}, {3}}", set.toString());
        set.union(objects.get(4), objects.get(4));
        assertEquals("{{0, 4}, {1}, {2}, {3}}", set.toString());
        set.union(objects.get(4), objects.get(1));
        assertEquals("{{0, 1, 4}, {2}, {3}}", set.toString());
        set.union(objects.get(0), objects.get(2));
        assertEquals("{{0, 2, 1, 4}, {3}}", set.toString());
        set.union(objects.get(2), objects.get(3));
        assertEquals("{{0, 3, 2, 1, 4}}", set.toString());
    }

}
