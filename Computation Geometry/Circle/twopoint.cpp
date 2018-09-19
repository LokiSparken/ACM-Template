struct Circle
{
    Point c;
    double r;
    Circle(Point c, double r) : c(c), r(r) {}
    Point point(double a)
    {
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
};

// 两圆交点个数及坐标
int getCircleIntersection(Circle C1, Circle C2, vector<Point> &sol)
{
    double d = Length(C1.c - C2.c);
    if (dcmp(d) == 0) // 首先圆心重合
    {
        if (dcmp(C1.r - C2.r) == 0)
            return -1; // 其次半径相同，然后就可以推出两圆重合
        return 0;
    }
    if (dcmp(C1.r + C2.r - d) < 0)
        return 0; // 相离没交点
    if (dcmp(fabs(C1.r - C2.r) - d) > 0)
        return 0; // 内含，没有交点

    double a = angle(C2.c - C1.c);                                          //向量C1C2的极角
    double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d)); //C1C2到C1P1的角
    Point p1 = C1.point(a - da), p2 = C1.point(a + da);

    sol.push_back(p1);
    if (p1 == p2) return 1; // 相切
    sol.push_back(p2);
    return 2; // 相交
}