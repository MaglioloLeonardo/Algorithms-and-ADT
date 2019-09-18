public class Adjacency {
    private Object object;
    private float weight;

    public Adjacency(Object object, float weight){
        this.object = object;
        this.weight = weight;
    }

    public Object getObject() {
        return object;
    }

    public float getWeight() {
        return weight;
    }

    @Override
    public String toString() {
        return "|"  + object + ", " + weight + "|";
    }
}
