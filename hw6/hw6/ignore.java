

import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.*;

import java.util.Iterator;
@SuppressWarnings("unchecked")
///////////////////////////////////////////////////this is my iterator class/////////////////////////////////////////////////////
public class ignore<Type> {

    private Type[] array;
    private int currentSize;
    private int currentIndex;
    public ignore(){}

    public ignore(Type[] newArray) {
        this.array = newArray;
        this.currentSize = newArray.length;
        for(int i = 0 ; i < array.length ; i++){
            array[i] = newArray[i];
        }
        currentIndex =0;
    }
    
    public boolean hasNext() {
                return currentIndex < currentSize && array[currentIndex] != null;
            }
    public Type next() {
                return array[currentIndex++];
            }
    public void remove(){
        Type[] arr =(Type[]) new Object[currentSize];//copied the original array to a temp array
        for(int i = 0;i<currentSize;i++){
            arr[i] = array[i];
        }
        int j=0;
        array = (Type[])new Object[currentSize];
        for(int i = 0 ; i < currentSize-1 ;i++){
            
                array[j++] = arr[i];
            
        }
       
    }
        
}

    
