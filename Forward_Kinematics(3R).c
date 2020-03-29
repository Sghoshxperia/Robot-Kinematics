#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.1415926591

int main()
{
    float Theta1,Theta2,Theta3;
    float Link1,Link2,Link3;

    printf("Enter Link Lengths:\n");
    printf("LINK LENGTH 1:");
    scanf("%f",&Link1);
    printf("LINK LENGTH 2:");
    scanf("%f",&Link2);
    printf("LINK LENGTH 3:");
    scanf("%f",&Link3);

    printf("Enter joint angles:\n");
    printf("JOINT ANGLE 1:");
    scanf("%f",&Theta1);
    printf("JOINT ANGLE 2:");
    scanf("%f",&Theta2);
    printf("JOINT ANGLE 3:");
    scanf("%f",&Theta3);


    float X,Y,phi;

    phi = Theta1+Theta2+Theta3;


    X  = Link1*cosf(Theta1*pi/180.0) + Link2*cosf((Theta1+Theta2)*pi/180.0) + Link3*cosf((Theta1+Theta2+Theta3)*pi/180.0);
    Y  = Link1*sinf(Theta1*pi/180.0) + Link2*sinf((Theta1+Theta2)*pi/180.0) + Link3*sinf((Theta1+Theta2+Theta3)*pi/180.0);


    printf("End Effector X = %f\t",X);
    printf("End Effector Y = %f\n",Y);
    printf("End Effector Orientation = %f",phi);


}

/* Exploit the geometrical aspect of a 3R robot arm to get X ,Y coordinates of the end effector and the orientation
   Taken joint angles and link lengths as input                                                                     */
