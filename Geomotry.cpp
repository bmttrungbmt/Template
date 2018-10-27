const double EPS = 1e-7;

struct Point{
    double X, Y;
    Point () {}
    Point (double X, double Y):
        X(X), Y(Y) {}
    Point operator - (const Point &a) {
        return Point(X - a.X, Y - a.Y);
    }
    Point operator + (const Point &a) {
        return Point(X + a.X, Y + a.Y);
    }
    double abs() {
        return sqrt(X*X + Y*Y);
    }
};
struct Line{
    double A, B, C; //Ax + By = C
    Line () {}
    Line (double A, double B, double C):
        A(A), B(B), C(C) {}
    Line (Point a, Point b) {
        A = b.Y - a.Y;
        B = a.X - b.X;
        C = a.X*b.Y - a.Y*b.X;
    }
    int intersect(const Line &line, Point &point) {
        double Do, Dx, Dy;
        Do = A*line.B - line.A*B;
        Dx = C*line.B - line.C*B;
        Dy = line.C*A - C*line.A;
        if(Do == 0) {
            if(Dx != 0 || Dy != 0) return 0;
            else return 2;
        }
        point.X = Dx / Do;
        point.Y = Dy / Do;
        return 1;
    }
    int intersect(const Line &b) {
        Point p;
        return intersect(b, p);
    }
};
