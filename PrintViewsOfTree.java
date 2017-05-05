

import java.util.HashMap;
import java.util.LinkedList;

/**
 * Created by nikeshjoshi on 5/5/17.
 */
class Node{
    int item;
    Node left;
    Node right;
}
class Tree{
    private Node root;
    Tree(){
        root = null;
    }
    void insert(int item){
        root = insertUtil(root,item);
    }
    private Node insertUtil(Node root,int item){
        if(root == null){
            Node temp = new Node();
            temp.item = item;
            temp.left = null;
            temp.right = null;
            return  temp;
        }
        if(item  > root.item){
            root.right = insertUtil(root.right,item);
        }
        else {
            root.left = insertUtil(root.left,item);
        }
        return root;
    }
    Node getRoot(){
        return root;
    }
    void printLevelOrder(Node root){
        LinkedList<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()){
            Node temp = queue.pop();
            System.out.println(temp.item);
            if(temp.left !=null){
                queue.add(temp.left);
            }
            if(temp.right!=null){
                queue.add(temp.right);
            }
        }
    }
    void printTopView(){
        LinkedList<Node> queue = new LinkedList<>();
        queue.add(root);
        HashMap<Integer,Boolean> map = new HashMap<>();
        HashMap<Node,Integer> map1 = new HashMap<>();
        map1.put(root,0);
        while (!queue.isEmpty()){
            Node temp = queue.pop();
            int nodeLevel = map1.get(temp);
           // System.out.println(nodeLevel + " " + temp.item);
            if(map.get(nodeLevel)==null){
                System.out.println(temp.item);
                map.put(nodeLevel,true);
            }

            if(temp.left !=null){
                map1.put(temp.left,nodeLevel-1);
                queue.add(temp.left);
            }
            if(temp.right!=null){
                map1.put(temp.right,nodeLevel+1);
                queue.add(temp.right);
            }
        }
    }
}
public class PrintViewsOfTree {
    public static void main(String args[]){
        Tree tree = new Tree();
        tree.insert(10);
        tree.insert(8);
        tree.insert(9);
        tree.insert(12);
        tree.insert(11);

        //tree.printLevelOrder(tree.getRoot());
        tree.printTopView();
    }
}
