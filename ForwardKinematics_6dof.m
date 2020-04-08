d3 = -6.75;     # offset distance between joint 2 and joint 3
d1 = 26.45;     # distance from base to first joint (Link 1 length)
a2 = 16.39;     # Link 2 length 
d4 = 19.58;     # Link 3 length



Theta1 = 0;
Theta2 = 0;
Theta3 = 0;
Theta4s2=0;
Theta5s2=0;
Theta6s2=0;


T_01 =  [cos(Theta1)  -sin(Theta1)   0  0;
        sin(Theta1)    cos(Theta1)   0  0;
            0               0       -1  d1;
            0               0        0  1];;
            
T_12 = [cos(Theta2)  -sin(Theta2)  0  0;     
            0              0       1  0;
        -sin(Theta2) -cos(Theta2)  0  0;
            0              0       0  1];

T_23 = [cos(Theta3)  -sin(Theta3)  0  a2;
        sin(Theta3)   cos(Theta3)  0  0;
            0               0      1  d3;
            0               0      0  1];
            
T_34 = [cos(Theta4s2)    -sin(Theta4s2)  0  0;    
            0                 0          1  d4;
        -sin(Theta4s2)   -cos(Theta4s2)  0  0;
            0                 0          0  1];

T_45 = [cos(Theta5s2)  -sin(Theta5s2)  0  0;
            0                0        -1  0;
        sin(Theta5s2)   cos(Theta5s2)  0  0;
            0                 0        0  1];
            
            
T_56 = [cos(Theta6s2)  -sin(Theta6s2)  0  0;    
            0                 0        1  0;
       -sin(Theta6s2)  -cos(Theta6s2)  0  0;
            0                 0        0  1];           

            
T_03 = T_01*T_12*T_23;            
            
T_06 = T_01*T_12*T_23*T_34*T_45*T_56;
 