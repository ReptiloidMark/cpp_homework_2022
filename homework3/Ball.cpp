#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

struct Point {
    float x, y;
};
struct Velocity {
    float vx, vy;
};
struct Stats {
    Point point;
    Velocity velocity;
    double time;
};

class Ball {
    Point point;
    Velocity velocity;
    double time;
    Stats stats;
    const float g = 9.81;
    
public:
    void push(double alpha, double v) {
        velocity.vx += v * cos(alpha);
        velocity.vy += v * sin(alpha);
    }
    void fly(double t) {
        double x_new, y_new;
        x_new = point.x + velocity.vx * t;
        y_new = point.y + velocity.vy * t - 0.5*g*t*t;
        point.x = x_new;
        point.y = y_new;
    }
    Point getPosition() {
        return point;
    }
    Velocity getVelocity() {
        return velocity;
    }
    Stats getStats() {
        stats.point = point;
        stats.velocity = velocity;
        stats.time = time;
        return stats;
    }
   
};

int main()
{


}

