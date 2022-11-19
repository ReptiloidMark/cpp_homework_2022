#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;
class Point {
double coord[2];
public:
    Point() {
        coord[0] = 0;
        coord[1] = 0;
    }
    void setPoint(double x, double y) {
        coord[0] = x;
        coord[1] = y;
    }
    float getPoint(int xy) {
        switch (xy) {
        case 0:
            return coord[0];
            break;
        case 1:
            return coord[1];
            break;
        }
    }
    /*void printPoint() {
        cout << "Текущая позиция мяча: х = " << coord[0] << ", y = " << coord[1];
    }*/
};
class Velocity {
    double speed[2];
public:
    Velocity() {
        speed[0] = 0;
        speed[1] = 0;
    }
    void push(double alpha, double v) {
        speed[0] += v * cos(alpha);
        speed[1] += v * sin(alpha);
    }
    void setVelocity(double vx, double vy) {
        speed[0] = vx;
        speed[1] = vy;
    }
    double getVelocity(int xy) {
        switch (xy) {
        case 0:
            return speed[0];
            break;
        case 1:
            return speed[1];
            break;
        }
    }
    /*void printVelocity() {
        cout << "Текущая скорость мяча: v_х = " << speed[0] << ", v_y = " << speed[1];
    }*/
};
class Stats {
    Point point;
    Velocity velocity;
    double t;
public:
    void setStats(Point pointi, Velocity velocityi, double ti) {
        point = pointi;
        velocity = velocityi;
        t = ti;
    }
    /*void printStats() {
        point.printPoint();
        velocity.printVelocity();
        cout << "Текущее время полёта: " << t;
    }*/
};
class Ball {
    Point point;
    Velocity velocity;
    double time;
    Stats stats;
    const float g = 9.81;
    
public:
    void push(double alpha, double v) {
        velocity.push(alpha, v);
    }
    void fly(double t) {
        double x_new, y_new;
        x_new = point.getPoint(0) + velocity.getVelocity(0) * t;
        y_new = point.getPoint(1) + velocity.getVelocity(1) * t - 0.5*g*t*t;
        point.setPoint(x_new, y_new);
    }
    Point getPosition() {
        return point;
    }
    Velocity getVelocity() {
        return velocity;
    }
    Stats getStats() {
        stats.setStats(point, velocity, time);
        return stats;
    }
    /*void printStats() {
        stats.printStats();
    }*/
};

int main()
{


}

