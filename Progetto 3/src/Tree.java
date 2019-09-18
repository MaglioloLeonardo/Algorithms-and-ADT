public class Tree{
    private int cardinality = 0;
    private Node root = null;

    public  Tree(Node root){
        this.root = root;
    }

    public Tree(){
        this(new Node(null, null, null, null));
    }

    public int getCardinality() {
        return cardinality;
    }

    public Node getRoot() {
        return root;
    }

    public void add(Tree tree){
        if(tree != null && tree.cardinality > 0) {
            Node node = tree.getRoot();
            if (root.getKey() == null) {
                root.setKey(node.getKey());
            } else {
                Node temp = root.getChild();
                root.setChild(node);
                node.setSibling(temp);
                node.setFather(root);
            }
        }
        cardinality += tree.cardinality;
    }

    public void add(Object key){
        if(key != null) {
            if(key instanceof Node) throw new Error("Key == Node, this could break cardinality invariant");
            if (root.getKey() == null) {
                root.setKey(key);
            } else {
                Node node = new Node(null, null, null, key);
                Node temp = root.getChild();
                root.setChild(node);
                node.setSibling(temp);
                node.setFather(root);
            }
            cardinality++;
        }
    }

    //Recursive method searching keys in generic trees
    public Node search(Object key){
        if(root.getKey() == key){
            return root;
        }else if(root.getChild() != null){
            return searchHelper(key, root.getChild());
        }else return null;
    }

    public Node searchHelper(Object key, Node next){
        if(next.getKey() == key) return next;
        if(next.getChild() != null) {
            Node temp = searchHelper(key, next.getChild());
            if (temp != null) return temp;
        }
        Node sibling = next.getSibling();
        if(sibling == null)return null;
        else return searchHelper(key, sibling);
    }
    //____________________________________________________

    //____________________________________________________
    public String toString(){
        String s = "";
        if(root.getKey() != null)s = root.getKey().toString();
        if(root.getChild() != null)s += ", " + toStringHelper(root.getChild());
        return s;
    }

    public String toStringHelper(Node next){
        String s = "";
        if(next.getKey() != null)s = next.getKey().toString();
        if(next.getChild() != null) {
            String temp = toStringHelper(next.getChild());
            if(temp != "")s += ", " + temp;
        }
        Node sibling = next.getSibling();
        if(sibling == null)return s;
        String temp = toStringHelper(sibling);
        if(temp == "")return s;
        else return  s += ", " + temp;
    }
    //__________________________________________________

}