public class Edge implements Comparable<Edge>{
    private Object u;
    private Object v;
    private float weight;

    public Edge(Object u, Object v, float weight){
        this.u = u;
        this.v = v;
        this.weight = weight;
    }

    public Object getU(){return u;}

    public Object getV(){return v;}

    public float getWeight() {
        return weight;
    }

    public String toString() {
        return "("  + u + ", " + v + "|" +  weight + ")";
    }

    public int compareTo(Edge edge){
        if(this.weight > edge.getWeight()){
            return 1;
        }else{
            return -1;
        }
    }
}
