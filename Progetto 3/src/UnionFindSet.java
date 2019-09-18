import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
//Implementation via QuickUnion with union-by-size
//UnionFindSet cannot work with primitive types without pointer references
public class UnionFindSet {
    private List<Tree> sets = new ArrayList<>();

    public UnionFindSet(){}

    //add new sets with key: 'key', if 'key' value is not already associated with other sets
    public boolean makeSet(Object key){
        if(this.find(key) != null) {
            return false;
        }
        Tree temp = new Tree(); temp.add(key);
        sets.add(temp); return true;
    }

    public Object find(Object key){
        Tree to_return = null;
        Iterator i = sets.iterator(); Tree temp = null;
        while(to_return == null && i.hasNext()){
            temp = (Tree)i.next();
            if(temp.search(key) != null)to_return = temp;
        }
        //to_return contains reference to the tree associated with key 'x'
        if(to_return == null)return null;
        return to_return.getRoot().getKey();
    }

    public void union(Object x, Object y){
        Tree tree_x = null, tree_y = null;
        Iterator i = sets.iterator(); Tree temp = null;
        while(!(tree_x != null && tree_y != null) && i.hasNext()){
                temp = (Tree)i.next();
                if(tree_x == null && temp.search(x) != null) tree_x = temp;
                if(tree_y == null && temp.search(y) != null) tree_y = temp;
        }
        assert tree_x != null && tree_y != null;
        //tree_x contains reference to the tree associated with key 'x'
        //same procedure is done for key 'y'
        if(tree_x != tree_y){
            if(tree_x.getCardinality() >= tree_y.getCardinality()){
                tree_x.add(tree_y); //tree union
                sets.remove(tree_y); //delete past set reference
            }else{
                tree_y.add(tree_x);
                sets.remove(tree_x);
            }
        }
    }

    public String toString() {
        String s = "{";
        boolean toogle = false;
        for (Tree tree : sets) {
            if (toogle == true) s += ", ";
            toogle = true;
            s += "{" + tree + "}";
        }
        return s += "}";
    }
}
