public class Entity {
    class Coordinate {
        int x, y;
        Coordinate() {
            x = y = 0;
        }
        Coordinate(int _x, int _y) {
            x = _x;
            y = _y;
        }
    }

    Coordinate position;
    float velocity;
    float mass;
    int width;
    int height;

    Entity() {
        position = new Coordinate();
        velocity = 0;
        mass = 0;
        width = height = 0;
    }
    Entity(int _x, int _y, int w, int h, int _mass, int _velocity) {
        position = new Coordinate(_x, _y);
        velocity = _velocity;
        mass = _mass;
        width = w;
        height = h;
    }
}