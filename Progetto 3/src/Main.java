import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Object> objects = new ArrayList<>();
        UnionFindSet set = new UnionFindSet();
        for(int i = 0; i<5; i++){
            objects.add(new Integer(i));
            set.makeSet(objects.get(i));
        }
        System.out.println("Set: " + set);
        set.union(objects.get(0), objects.get(4));
        System.out.println("Set: " + set);
        set.union(objects.get(4), objects.get(4));
        System.out.println("Set: " + set);
        set.union(objects.get(4), objects.get(1));
        System.out.println("Set: " + set);
        set.union(objects.get(0), objects.get(2));
        System.out.println("Set: " + set);
        set.union(objects.get(2), objects.get(3));
        System.out.println("Set: " + set);
    }
}
