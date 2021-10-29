
package Collection;

public class TestArrayCollection {
   public static void main(String args[]){
       ArrayCollection bag= new ArrayCollection();
       bag.add("a");
       bag.add("b");
       bag.add("c");
       System.out.println(bag.size());
       System.out.println(bag);
       bag.add("d");
       bag.add("e");
       Iterator it=bag.iterator();
       it.next();
       it.remove();
     
       System.out.println(bag);
      
       }         
}
