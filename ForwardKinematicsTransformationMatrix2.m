L = [2 2 2 2 2 2 2];

A = [0 0 0 0 0 0];

T01 = [ cos(A(1)) -sin(A(1)) 0   0;
        sin(A(1))  cos(A(1)) 0   0;
        0              0     1 L(1);
        0              0     0   1];
        
T12 = [ 1     0          0          0;
        0  cos(A(2))  -sin(A(2))    0;
        0  sin(A(2))  cos(A(2))  L(2);
        0       0         0        1];
        
T23 = [ 1     0          0          0;
        0  cos(A(3))  -sin(A(3)) L(3);
        0  sin(A(3))  cos(A(3))     0;
        0       0         0        1];
        
T34 = [ cos(A(4)) -sin(A(4)) 0   0;
        sin(A(4))  cos(A(4)) 0  L(4);
        0              0     1   0;
        0              0     0   1];
        
T45 = [ cos(A(5))   0   -sin(A(5))   0;
        0           1       0        L(5);
        sin(A(5))   0    cos(A(5))   0;
        0           0         0      1];
        
T56 = [ 1     0          0          0;
        0  cos(A(6))  -sin(A(6))    L(6);
        0  sin(A(6))   cos(A(6))    0;
        0       0         0         1]; 
   
T6e = [1   0    0     0;
       0   1    0   L(7);
       0   0    1     0;
       0   0    0     1];   
       
Goal = T01*T12*T23*T34*T45*T56*T6e;
        
# Calculated Forward Kinematics for a 6DOF 6R robot arm via homogenous transformation matrix
# It gives us the end effector position and orientation with respect to X, Y, Z axes.    