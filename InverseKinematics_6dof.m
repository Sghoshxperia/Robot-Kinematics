clear

EE = [  1.00000    0.00000    0.00000   16.39000;
        0.00000   -1.00000    0.00000   -6.75000;
        0.00000    0.00000    1.00000   46.03000;
        0.00000    0.00000    0.00000    1.00000];
      
Px = EE(1,4);
Py = EE(2,4);
Pz = EE(3,4);
d3 = -6.75;     # offset distance between joint 2 and joint 3
d1 = 26.45;     # distance from base to first joint (Link 1 length)
a2 = 16.39;     # Link 2 length 
d4 = 19.58;     # Link 3 length


phi = atan2(Py,Px);

#Calculating Theta1

sin_Theta1 = (Py*sqrt(Px*Px+Py*Py-d3*d3) - d3*Px)/(Px*Px + Py*Py);
cos_Theta1 = (Px*sqrt(Px*Px+Py*Py-d3*d3) + d3*Py)/(Px*Px + Py*Py);
Theta1 = atan2(sin_Theta1,cos_Theta1);

#Calculating Theta3

Y = abs(Pz-d1);
#X = sqrt(Px^2+Py^2-d3^2);
X = sqrt(Px*Px+Py*Py)*cos(phi-Theta1);
cos_Theta3 = (X*X+Y*Y - a2*a2 - d4*d4)/(2*a2*d4);
sin_Theta3 = sqrt(1-cos_Theta3*cos_Theta3);
Theta3 = atan2(sin_Theta3,cos_Theta3);
#Theta3 = pi;

#Calculating Theta2

sin_Theta2 = ((a2+d4*cos(Theta3))*Y - (d4*sin(Theta3)*X))/(X*X+Y*Y);
cos_Theta2 = ((a2+d4*cos(Theta3))*X + (d4*sin(Theta3)*Y))/(X*X+Y*Y);
Theta2 = atan2(sin_Theta2,cos_Theta2);


Theta3 = Theta3-pi/2;

#Calculating T_36

T_01 = [cos(Theta1)  -sin(Theta1)  0  0;
        sin(Theta1)   cos(Theta1)  0  0;
            0               0      -1  d1;
            0               0      0  1];
            
T_12 = [cos(Theta2)  -sin(Theta2)  0  0;
            0              0       1  0;
        -sin(Theta2) -cos(Theta2)  0  0;
            0              0       0  1];

T_23 = [cos(Theta3)  -sin(Theta3)  0  a2;
        sin(Theta3)   cos(Theta3)  0  0;
            0               0      1  d3;
            0               0      0  1];
            
T_03 = T_01 * T_12 * T_23;
T_03inv = pinv(T_03);
T_36 = T_03inv*EE;

#Calculating Theta4-Theta6

Theta4s1 = atan2(-T_36(2,3),-T_36(1,3));
Theta5s1 = atan2(sqrt(T_36(1,3)^2 + T_36(2,3)^2),T_36(3,3));
Theta6s1 = atan2(-T_36(3,2),T_36(3,1));

Theta4s2 = atan2(T_36(2,3),T_36(1,3));
Theta5s2 = atan2(-sqrt(T_36(1,3)^2 + T_36(2,3)^2),T_36(3,3));
Theta6s2 = atan2(T_36(3,2),-T_36(3,1));


if (T_36(3,3)<1.0e-10)
  T_36(3,3) = 0;
endif;

if (T_36(1,3)<1.0e-10)
  T_36(1,3) = -0;
endif;

if (T_36(2,2)<1.0e-10)
  T_36(2,2) = 0;
endif;

if (T_36(2,1)<1.0e-10)
  T_36(2,1) = 0;
endif;

  
  

Theta4s3 = atan2(T_36(3,3),-T_36(1,3));
Theta5s3 = atan2(sqrt(T_36(3,3)^2 + T_36(1,3)^2),T_36(2,3));
Theta6s3 = atan2(-T_36(2,2),T_36(2,1));

# Calculating Forward Kinematics to check solution

T_34 = [cos(Theta4s3)    -sin(Theta4s3)  0  0;
            0                 0          1  d4;
        -sin(Theta4s3)   -cos(Theta4s3)  0  0;
            0                 0          0  1];

T_45 = [cos(Theta5s3)  -sin(Theta5s3)  0  0;
            0                0        -1  0;
        sin(Theta5s3)   cos(Theta5s3)  0  0;
            0                 0        0  1];
            
            
T_56 = [cos(Theta6s3)  -sin(Theta6s3)  0  0;
            0                 0        1  0;
       -sin(Theta6s3)  -cos(Theta6s3)  0  0;
            0                 0        0  1];           


T_06 = T_03 * T_34 * T_45 * T_56;


#The required joint angles
theta = [Theta1 Theta2 Theta3 Theta4s3 Theta5s3 Theta6s3]'*(180/pi);


 