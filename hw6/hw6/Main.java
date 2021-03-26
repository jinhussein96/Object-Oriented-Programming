

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.*;
@SuppressWarnings("unchecked")


public class Main{
	public static void main(String[] args){
		System.out.println("**************** ArrayList ****************");
		Integer[] ad = {1,56,88};
		Integer[] ad1 = {1,2,3,6,5,7,5,3,8,0,7};
		ignore<Integer> a = new ignore<Integer>();
		Array_List<Integer> a1= new Array_List<Integer>(ad);
		Array_List<Integer> a11= new Array_List<Integer>(ad1);
		System.out.println("array a11 size = "+a11.size());
		System.out.println("if array a11 contains 11 "+a11.contains(11));
		System.out.println(("if array a11 is empty "+a11.isEmpty()));
		a11.add(15);
		a11.removeAll(a1);
		System.out.println("if a11 contains a1 = "+a11.containsAll(a1));
		System.out.println("a11 hashCode = "+a11.hashCode());
		ignore<Integer> i = a11.iterator(); 
		while (i.hasNext()) 
            System.out.println("array elements "+i.next()); 

	System.out.println("**************** LinkedHashSet ****************");

		LinkedHashSet<String> e = new LinkedHashSet<String>();
		LinkedHashSet<String> e1 = new LinkedHashSet<String>();
		e.add("gtu");
		e.add("test");
		e.add("homwork");
		e.add("homwork");
		e.add("!");
		e1.add("!");
		e.removeAll(e1);
		e.remove("gtu");
		 System.out.println("List contains India or not:" + 
                           e.contains("!")); 
		ignore<String> i1 = e.iterator(); 
        while (i1.hasNext()) 
            System.out.println(i1.next()); 
        System.out.println("**************** vector ****************");
        Vector<String> vec = new Vector<String>();
        vec.add("my");
        vec.add("name");
        vec.add("is");
        vec.add("jin");
         System.out.println("vector contains elemnt elements "+vec.contains("jin")); 
        ignore<String> it = vec.iterator();
         System.out.println("vector elements "); 
		while (it.hasNext()) 
            System.out.println(it.next()); 
        System.out.println("**************** PriorityQueue ****************");
        PriorityQueue<Integer> b = new PriorityQueue<Integer>(6);
		b.add(1);
		b.add(2);
		b.add(3);
		b.add(4);
		b.addAll(b);
		ignore<Integer> s = b.iterator(); 
        while (s.hasNext()) 
            System.out.println(s.next());
	}
}
