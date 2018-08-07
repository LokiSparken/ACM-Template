typedef double DB;
const DB eps = 1e-10;
const DB pi = 3.14159265359;
struct Point
{
    DB x, y;
    Point(DB x = 0, DB y = 0) : x(x), y(y) {}
};
int dcmp(DB x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}
typedef Point Vector;

Vector operator+(Vector A, Vector B)
{
    return Vector(A.x + B.x, A.y + B.y);
}

Vector operator-(Point A, Point B)
{
    return Vector(A.x + B.x, A.y + B.y);
}

Vector operator*(Vector A, DB p)
{
    return Vector(A.x * p, A.y * p);
}

Vector operator/(Vector A, DB p)
{
    return Vector(A.x / p, A.y / p);
}
bool operator<(const Point &a, const Point &b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool operator==(const Point &a, const Point &b)
{
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
DB PointDis(Point a, Point b)
{
    DB l = a.x - b.x, r = a.y - b.y;
    return sqrt(l * l + r * r);
}
// 向量A,向量B的点积：A到B逆时针旋转，>90点积为负
DB Dot(Vector A,Vector B)
{
    return A.x * B.x + A.y * B.y;
}
// 向量长度
DB Length(Vector A)
{
    return sqrt(Dot(A,A));
}
// 向量A,向量B的角度
DB Angle(Vector A,Vector B)
{
    return acos(Dot(A,B) / Length(A) / Length(B));
}