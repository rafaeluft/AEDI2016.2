#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int x,y,z;
}Point3D;

int main(){
Point3D x, *p0, *p1;
p0 = &x;
p1 = (Point3D*)malloc(sizeof(Point3D));
if(p1){
  p1->x = 1;
  p1->y = 2;
  (*p1).z = 4;
}
p0->x = -1;
x.y = -2;
(*p0).z = -3;

printf("P0:(x=%d,y=%d,z=%d)\n",p0->x, p0->y, p0->z);
printf("P1:(x=%d,y=%d,z=%d)\n",p1->x, p1->y, p1->z);

return 0;
}
