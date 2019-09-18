import java.util.Map;
import  java.util.HashMap;
import java.util.ArrayList;
import  java.util.List;

public class Graph { //Graph G
    private boolean is_direct;
    HashMap<Object, List<Adjacency>> hashMap = new HashMap<>();

    public Graph(Boolean is_direct){
        this.is_direct = is_direct;
    }

    public void Add_node(Object node){
        if(!hashMap.containsKey(node)){
            hashMap.put(node, new ArrayList<Adjacency>());
        }
    }

    public void Add_edge(Object node_u, Object node_v, float weight){
        List<Adjacency> list_u = hashMap.get(node_u);
        if(list_u == null){
            Add_node(node_u); //if u doesn't exist add it on the hashmap
            list_u = hashMap.get(node_u);
        }

        List<Adjacency> list_v = hashMap.get(node_v);
        if(list_v == null){
            Add_node(node_v); //if v doesn't exist add it on the hashmap
            list_v = hashMap.get(node_v);
        }

        if(!List_constains(list_u, node_v)){
            list_u.add(new Adjacency(node_v, weight));//add (u,v)
        }

        if(!is_direct){ //if G is not direct then add also (v,u)
            if(!List_constains(list_v, node_u)){
                list_v.add(new Adjacency(node_u, weight));
            }
        }
    }

    public boolean Is_direct() {
        return is_direct;
    }

    public boolean Contains_node(Object v){
        return hashMap.containsKey(v);
    }

    public boolean Contains_edge(Object node_u, Object node_v){
        List<Adjacency> list_u = hashMap.get(node_u);
        if(list_u == null || !List_constains(list_u, node_v)){
            return  false;
        }else{
            return true;
        }
    }

    public void Delete_node(Object node){
        hashMap.remove(node);
        Map<Object, List<Adjacency>> map = hashMap;
        //for each vertex u on G
        for (Map.Entry<Object, List<Adjacency>> entry : map.entrySet()) {
            List<Adjacency> list_vertex = entry.getValue();//list adj[u]
            Adjacency toRemove = List_find(list_vertex, node);
            //if(u, node) exists then it delete it
            if(toRemove != null)list_vertex.remove(toRemove);
        }
    }

    public void Delete_edge(Object node_u, Object node_v){
        List<Adjacency> list_u = hashMap.get(node_u);
        List<Adjacency> list_v = hashMap.get(node_v);
        if(list_u != null && list_v != null){
            Adjacency toRemove = List_find(list_u, node_v);
            if(toRemove != null)list_u.remove(toRemove); //remove (u,v) if exists
            if(!is_direct){
                toRemove = List_find(list_v, node_u);
                //remove (v,u) if exists and G is not direct
                if(toRemove != null)list_v.remove(toRemove); 
            }
        }
    }

    public int Nodes_number(){
        return hashMap.size();
    }

    public int Edge_number(){
        int edges = 0;
        Map<Object, List<Adjacency>> map = hashMap;
        //for each vertex u on G
        for (Map.Entry<Object, List<Adjacency>> entry : map.entrySet()) {
            List<Adjacency> list_vertex = entry.getValue();//adj v list of u
            edges += list_vertex.size();
        }
        return edges;
    }

    //returns the list of nodes contained in Hashmap 'keys' 
    public List<Object> Get_nodes(){
        List<Object> nodes = new ArrayList<>();
        Map<Object, List<Adjacency>> map = hashMap;
        //for each vertex u on G
        for (Map.Entry<Object, List<Adjacency>> entry : map.entrySet()) {
            nodes.add(entry.getKey());
        }
        return  nodes;
    }

    //returns the list of edges cointained on hashMap
    public List<Edge> Get_edges(){
        List<Edge> toReturn = new ArrayList<>();
        Map<Object, List<Adjacency>> map = hashMap;
        //foreach vertex u on G
        for (Map.Entry<Object, List<Adjacency>> entry : map.entrySet()) {
            List<Adjacency> temp = entry.getValue();
            //foreach adj v on vertex u
            for (Adjacency adj: temp) {
                //add to the list (u,v)
                toReturn.add(new Edge(entry.getKey(), adj.getObject(), adj.getWeight()));
            }
        }
        return toReturn;
    }

    //given vertex returns the list of adj nodes
    public List<Object> Adj_nodes(Object vertex){
        List<Object> result = new ArrayList<>();
        List<Adjacency> temp = hashMap.get(vertex); //list of Adjacency to vertex u
        if(temp != null) {
            for (Adjacency adj : temp) {
                result.add(adj.getObject()); //add (u,v)
            }
        }
        return result;
    }

    private boolean List_constains(List<Adjacency> list, Object vertex){
        for (Adjacency adj: list) {
            if(adj.getObject() == vertex)return true;
        }
        return false;
    }

    private Adjacency List_find(List<Adjacency> list, Object vertex){
        for (Adjacency adj: list) {
            if(adj.getObject() == vertex)return adj;
        }
        return null;
    }














}
