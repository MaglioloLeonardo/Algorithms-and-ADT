public class Node {
    private Node child, sibling, father;
    private Object key;
    //_____________________________________________________
    public Node(Node child, Node sibling, Node father, Object key){
            this.child = child;
            this.sibling = sibling;
            this.father = father;
            this.key = key;
    }
    //______________________________________________________
    public Node getChild() {
        return child;
    }

    public void setChild(Node child) {
        this.child = child;
    }

    public Node getSibling() {
        return sibling;
    }

    public void setSibling(Node sibling) {
        this.sibling = sibling;
    }

    public Node getFather() {
        return father;
    }

    public void setFather(Node father) {
        this.father = father;
    }

    public Object getKey() {
        return key;
    }

    public void setKey(Object key) {
        this.key = key;
    }

}




