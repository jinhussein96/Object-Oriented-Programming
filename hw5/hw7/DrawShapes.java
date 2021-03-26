import java.awt.BorderLayout;
import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class DrawShapes extends JFrame {
    public ArrayList<shape> shapeList = new ArrayList<shape>();

    public DrawShapes(String title) {
        super(title);

        this.setLayout(new BorderLayout());
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setSize(500, 700);
        this.setLocationRelativeTo(null);

        this.initComponents();
    }

    private void initComponents() {
        shapeList.add(new Rectangle(20, 20, 60, 60));
        shapeList.add(new Rectangle(130, 30, 80, 11));
        shapeList.add(new Rectangle(200, 30, 20, 140));
    }

    @Override
    public void paint(Graphics g) {
        for (shape s : shapeList) {
            s.draw(g);
        }
    }

    
}