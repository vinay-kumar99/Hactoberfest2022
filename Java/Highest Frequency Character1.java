/// Basic use of HashMap
]
import java.util.*;
public class HighestFrequencyCharacter {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String s = scn.nextLine();
		HashMap<Character, Integer> hm = new HashMap<>();
		for(int i = 0; i < s.length(); i++) {
			if(hm.containsKey(s.charAt(i))) {
				int of = hm.get(s.charAt(i));
				int nf = of+1;
				hm.put(s.charAt(i),nf);
				
			}else {
				hm.put(s.charAt(i),1);
			}
		}
		
		char mfc = s.charAt(0);
		for(Character key : hm.keySet()) {
			if(hm.get(key) > hm.get(mfc)) {
				mfc = key;
			}
		}
		System.out.println(mfc);
				
	}

}
