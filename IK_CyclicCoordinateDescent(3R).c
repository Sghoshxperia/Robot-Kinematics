#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define pi 3.1415926591

float A1,A2,A3;
float FK_Xval,FK_Yval;
float Joint2_X,Joint2_Y,Joint3_X,Joint3_Y;


void FK(float Link1,float Link2,float Link3)
{
     FK_Xval  = Link1*cosf(A1*pi/180.0) + Link2*cosf((A1+A2)*pi/180.0) + Link3*cosf((A1+A2+A3)*pi/180.0);
     FK_Yval  = Link1*sinf(A1*pi/180.0) + Link2*sinf((A1+A2)*pi/180.0) + Link3*sinf((A1+A2+A3)*pi/180.0);
     Joint2_X = Link1*cosf(A1*pi/180.0);
     Joint2_Y = Link1*sinf(A1*pi/180.0);
     Joint3_X = Link1*cosf(A1*pi/180.0) + Link2*cosf((A1+A2)*pi/180.0);
     Joint3_Y = Link1*sinf(A1*pi/180.0) + Link2*sinf((A1+A2)*pi/180.0);
}

float RotatedAngle(float Ax,float Ay,float Bx,float By)
{
    float angle = ((Ax-By)-(Bx-Ay))/(sqrt(Ax*Ax+Ay*Ay)*sqrt(Bx*Bx+By*By));
    return (180.0/pi)*asinf(angle);
}

void RandomInit(float Link1,float Link2,float Link3)
{
    A1 = (rand()%(180-0+1))+0;       //Set your own starting point or randomize them
    A2 = (rand()%(180-0+1))+0;
    A3 = (rand()%(180-0+1))+0;

    FK(Link1,Link2,Link3);

}



void CyclicCoordinateDescent(float Link1,float Link2,float Link3,float X_val,float Y_val)
{
    int i=0;
    float errorAngle;
    RandomInit(Link1,Link2,Link3);

    for(i=1;i<=10;i++)
    {

        errorAngle = (180.0/pi)*(atan2f(Y_val,X_val) - atan2f(FK_Yval,FK_Xval));
        A1+=errorAngle;
        printf("%f\t",errorAngle);

        FK(Link1,Link2,Link3);
        errorAngle = RotatedAngle(FK_Xval-Joint2_X,FK_Yval-Joint2_Y,X_val-Joint2_X,Y_val-Joint2_Y);
        A2+=errorAngle;
        printf("%f\t",errorAngle);


        FK(Link1,Link2,Link3);
        errorAngle = RotatedAngle(FK_Xval-Joint3_X,FK_Yval-Joint3_Y,X_val-Joint3_X,Y_val-Joint3_Y);
        A3+=errorAngle;
        printf("%f\t\n",errorAngle);



    }
    //printf("%f\t%f\t%f\n",A1,A2,A3);
}


int main()
{
    srand(time(0));
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

    CyclicCoordinateDescent(Link1,Link2,Link3,X,Y);

    FK(Link1,Link2,Link3);
    printf("End Effector X: %f\n",FK_Xval);
    printf("End Effector Y: %f\n",FK_Yval);

    //printf("Joint angle 1 = %f\n",A1);
    //printf("Joint angle 2 = %f\n",A2);
    //printf("Joint angle 3 = %f\n",A3);

}

/* Calculated Inverse Kinematics for a 3R robot arm by a iterative method called Cyclic Co-ordinate Descent
   We have to provide a initial set of joint angles close to the solution for the program to work. For now they have been randomly initialized in
   function called RandomInit(). This may not work every time. It is safe to initialize joint angles (A1, A2, A3) on your own which are closer to the
   solution.
   Taking Link length and End effector position as Input
   We calculate relative difference in link and joint orientation with respect to target and make it our error term which we minimize over time to attain
   solution.                                                                                                                                             */


