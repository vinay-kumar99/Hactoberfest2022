import java.util.*;
public class KlargestElements {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int[] a = new int[n];
		for(int i = 0; i < n; i++) {
			a[i] = scn.nextInt();
		}
		int k = scn.nextInt();
		PriorityQueue<Integer>	pq = new PriorityQueue<>();
		for(int i = 0; i < n; i++) {
			if(i < k) {
				pq.add(a[i]);
			}else {
				if(pq.peek() < a[i]) {
					pq.remove();
					pq.add(a[i]);
				}
			}
		}
		
		while (pq.size() > 0) {
			System.out.println(pq.remove());
		}
	}

}
