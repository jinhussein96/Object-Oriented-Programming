JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
ignore.java\
Collection.java\
List.java\
Array_List.java\
Vector.java\
Set.java\
HashSet.java\
Main.java\
LinkedHashSet.java\
Queue.java\
SortedSet.java\
PriorityQueue.java\
LinkedList.java\
TreeSet.java
default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class

