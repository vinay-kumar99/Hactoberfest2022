
public class Abc {
	public static void main(String args[]) {
	String arr[]= {"A","B","C","S","Y"};
	String temp="";
	for(int i=0;i<4;i++)
		for(int j=0;j<4-i;j++)
		
			if(arr[j].compareTo(arr[j+1])>0) {
				temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	
String search="S";
int mid,first,last;
first=0;
last=4;
mid=(first+last)/2;
while(first<last) {
mid=(first+last)/2;
if(search.equals(arr[mid]))
{System.out.println("found");
break;
	
}
else
	if(search.compareTo(arr[mid])<0) {
		last=mid-1;
	}
	else
		first=mid+1;
}
if(!search.equals(arr[mid]))
	System.out.println(" not found");


}}
