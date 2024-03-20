#include <iostream>

struct Point3D
{
    int x;
    int y;
    int z;
};

int main()
{
    Point3D* pPoint = NULL;
    int offset = (int)(&(pPoint)->z);
    printf("%d", offset);
    return 0;
}

