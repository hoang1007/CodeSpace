import javax.swing.JFrame;
import javax.swing.JPanel;

import java.awt.*;

class Surface extends JPanel {
    private void draw(Graphics g) {
        g.setColor(Color.BLUE);
        g.draw3DRect(100, 100, 200, 200, false);
    }
    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        draw(g);
    }
}

class Ex extends JFrame {
    public Ex() {
        setVisible(true);
        add(new Surface());
        setSize(600, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        new Ex();
    }
    
}