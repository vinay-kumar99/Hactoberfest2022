package Collection;

public class ArrayCollection extends AbstractCollection {
    private final int INITIAL_LENGTH=10;
    private int size;
    private Object a[] = new Object[INITIAL_LENGTH];
    
    public boolean add(Object object){
        if(size==a.length)
            resize();
        a[size++]=object;
        return true;
    }
    public void resize(){
        Object aa[]=a;
        a=new Object[1+a.length];
        System.arraycopy(aa, 0, a, 0, size);
    }
    public int size(){
        return size;
    }
    public Iterator iterator(){
        return new Iterator()
    
    {
        private int i=0;
        private boolean okToRemove =false;
        public boolean hasNext(){
            return (i<size);
        }
        public Object next(){
            if(i==size)
                throw new RuntimeException();
            okToRemove = true;
            return a[i++];
        }
        public void remove(){
            if(!okToRemove)
                throw new IllegalStateException();
            a[--i]=a[--size];
            a[size]=null;
            okToRemove=false;
        }
    };
        }
}
