import javax.swing.JFrame;
import javax.swing.JPanel;

import java.awt.*;

class Surface extends JPanel {
    private void draw(Graphics g, Entity e) {
        g.setColor(Color.red);
        g.fillOval(e.position.x, e.position.y, e.width, e.height);
    }
    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        Entity e = new Entity(100, 100, 100, 100, 20, 0);
        draw(g, e);
    }
}

public class App extends JFrame{
    App() {
        add(new Surface());
        setVisible(true);
        setTitle("Gravity");
        setSize(600, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    public static void main(String[] args) throws Exception {
        new App();
    }
}
