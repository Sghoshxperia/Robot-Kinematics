#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.1415926591

int main()
{
    float X,Y,Z = 0.0;

    float Link1,Link2,Link3;


    printf("Enter Link Lengths:\n");
    printf("LINK LENGTH 1:");
    scanf("%f",&Link1);
    printf("LINK LENGTH 2:");
    scanf("%f",&Link2);
    printf("LINK LENGTH 3:");
    scanf("%f",&Link3);

    printf("Enter the co-ordinates of the end effector:\n");
    printf("X: ");
    scanf("%f",&X);
    printf("Y: ");
    scanf("%f",&Y);
    printf("Z: ");
    scanf("%f",&Z);

    float Theta1,Theta2,Theta3;
    float r1,r2,r3;
    float phi1,phi2,phi3,c1,s1,c3,s3;


    r1 = sqrt(X*X+Y*Y);
    r2 = Z - Link1;
    r3 = sqrt(r1*r1+r2*r2);


    c1 = ((Link2*Link2 + r3*r3 - Link3*Link3)/(2*Link2*r3));
    s1 = sqrt(1-c1*c1);
    phi1 = atan2f(s1,c1);
    phi2 = atan2f(r2,r1);
    c3 = ((Link2*Link2 + Link3*Link3 - r3*r3)/(2*Link2*Link3));
    s3 = sqrt(1-c3*c3);
    phi3 = atan2f(s3,c3);

    Theta1 = atan2f(Y,X);
    Theta2 = phi2 - phi1;
    Theta3 = pi - phi3;


    printf("Joint 1 angle: %f\n",Theta1*180/pi);
    printf("Joint 2 angle: %f\n",Theta2*180/pi);
    printf("Joint 3 angle: %f\n",Theta3*180/pi);


}
