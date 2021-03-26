JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
Rectangle.java\
Circle.java\
Triangle.java\
shape.java\
Polygon.java\
PolyVec.java\
PolyDyn.java\
ComposedShape.java\
otherMethods.java\
test.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class


