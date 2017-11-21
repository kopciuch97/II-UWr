
package algorithms;

/**
 *
 * @author SzymonKopa
 * 
 */
public class BST<T extends Comparable<T>> implements Dict<T> {
   /**
    * Klasa węzeł posiadająca wskaźnik na prawe oraz lewe poddrzewo,
    * na rodzica oraz wartość
    * @param <T> 
    */
    private class Node <T extends Comparable<T>> {
        Node <T> left;
        Node <T> right;
        Node <T> parent;
        T data;
        
        public Node(){
           right = null;
           left = null;
           parent = null;
           data = null;
                   
        }
        /**
         * Funkcja zmieniająca węzeł na ten podany jako parametr
         * @param toChange Węzeł który ma zostać podstawiony w dane miejsce 
         */
        public void repleace(Node toChange){
            if (this == this.parent.left){
                this.parent.left = toChange;
            }
            else{
                this.parent.right = toChange;
            }

            if (toChange != null){
                toChange.parent = this.parent;
                if(this.parent == null){
                    root = toChange;
                }
            }
        
        }
    }
    
    public Node<T> root;

    int size;
    public BST(){
        root = new Node<T>();
        size = 0;
        root.parent = root;
    }
    
    @Override
    public void insert(T elem) throws NullPointerException{
        if (elem == null){
            throw new NullPointerException("parametr ma wartość null");
        }
        
        Node InsertNode = new Node<T>();
        InsertNode.data = elem;
        
        if (size() == 0){
            root = InsertNode;
        }
        else{
        
        Node temp = root;
        Node parenttemp = null;
        
        while(temp != null){
            parenttemp = temp;
            if(InsertNode.data.compareTo(temp.data) < 0){
                temp = temp.left;
            }
            else{
                temp = temp.right;
            }
        }
        InsertNode.parent = parenttemp;
        if (InsertNode.data.compareTo(parenttemp.data) < 0){
            parenttemp.left = InsertNode;
        }
        else{
            parenttemp.right = InsertNode;
        }
        }
        size += 1;
    }
    
    
    /**
     * Zwraca Węzeł posiadający wartość podaną w parametrze
     * @param elem wartość węzła który mamy zwrócić
     * @return Wezeł któremu odpowiada wartosc elem 
     */
    public Node getNode(T elem) {
        if (size() == 0){
            return null;
        }
        Node temp = root;
        Node x = new Node<T>();
        x.data = elem;
        while (temp != null){
            if (x.data.compareTo(temp.data) == 0){
                return temp;
            }
            if (x.data.compareTo(temp.data) < 0){
                temp = temp.left;
            }
            else{
                temp = temp.right;
            }
        }
        return null;
    }
    
    @Override
    public boolean search(T elem) {
        if (getNode(elem) == null){
            return false;
        }
        return true;
    }

    @Override
    public void remove(T elem) {
        if (getNode(elem) != null){
            Node x = getNode(elem);
            if (x.left == null && x.right == null){
                x.repleace(null);
            }
            else if (x.left == null && x.right != null) {
                x.repleace(x.right);
            }
            else if (x.left != null && x.right == null) {
                x.repleace(x.left);
            }
            else if (x.left != null && x.right != null) {
                Node repl = minimumNode(x.right);
                remove((T) repl.data);
                x.data = repl.data;
            }

            
            
            
            
        }
    }

    @Override
    public T min() {
        return minimumNode(root).data;
    }

    @Override
    public T max() {
        return maximumNode(root).data;
    }
    
    public Node<T> minimumNode(Node<T> node){
        Node temp = node;
        while (temp.left != null){
            temp = temp.left;
        }
        return temp;
    }
    
    public Node<T> maximumNode(Node<T> node){
        Node temp = node;
        while (temp.right != null){
            temp = temp.right;
        }
        return temp;
    }
    
    public int size(){
        return size;
    }
    
    public void clear(){
        root = null;
        size = 0;
    }

    
}
