#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.1415926591

int main()
{

    float X,Y,phi;
    float Link1,Link2,Link3;


    printf("Enter Link Lengths:\n");
    printf("LINK LENGTH 1:");
    scanf("%f",&Link1);
    printf("LINK LENGTH 2:");
    scanf("%f",&Link2);
    printf("LINK LENGTH 3:");
    scanf("%f",&Link3);

    printf("Enter End Effector position->\n");
    printf("X = ");
    scanf("%f",&X);
    printf("Y = ");
    scanf("%f",&Y);
    printf("Orientation angle = ");
    scanf("%f",&phi);


    float Wx = X - Link3*cosf(phi*pi/180.0);
    float Wy = Y - Link3*sinf(phi*pi/180.0);

    float s1,c1,c2,s2,Theta1,Theta2,Theta3;

    c2 = (Wx*Wx + Wy*Wy - Link1*Link1 -Link2*Link2)/(2*Link1*Link2);
    Theta2 = (180.0/pi)*acosf(c2);
    s2 = sqrt(1-c2*c2);

    c1 = ((Link1 + Link2*c2)*Wx + Link2*s2*Wy)/(Wx*Wx + Wy*Wy);
    Theta1 = (180.0/pi)*acos(c1);

    Theta3 = phi - Theta1 - Theta2;

    printf("\nFirst set of solution:\n");

    printf("Joint angle 1 = %f\n",Theta1);
    printf("Joint angle 2 = %f\n",Theta2);
    printf("Joint angle 3 = %f\n",Theta3);


    Theta1 = atan2f(Y,X) + Theta1;

    Theta2 = (180.0/pi)*(-acosf(c2));

    Theta3 = phi - Theta1 - Theta2;

    printf("\nSecond set of solution:\n");

    printf("Joint angle 1 = %f\n",Theta1);
    printf("Joint angle 2 = %f\n",Theta2);
    printf("Joint angle 3 = %f\n",Theta3);


}

/* Exploited the geometric aspect of a 3R robot arm. As per the workspace of the arm it can either have 0,1 or 2 solutions
   (elbow up and elbow down). Used trigonometric equations to find possible joint angles.
   Taken link lengths and end effector coordinates as input(X,Y,phi)
   phi = angle of the end effector with respect to X axis.                                                               */
