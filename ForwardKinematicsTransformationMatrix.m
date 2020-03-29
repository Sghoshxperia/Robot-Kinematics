L = [2 2 2 2];

A = [0 0 0];

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
        
Tee = [1    0    0    0;
       0    1    0  L(4); 
       0    0    1    0;
       0    0    0    1];
       
       
Goal = T01*T12*T23*Tee;

#Calculated 3D 3R robot arm end effector orientation
#by homogeneous transformation matrix methods
#T consists of rotation matrix and translated distance between links
#Multiplying all the T matrix together gives us end effector position and 
#and orientation in 3 dimensions.
#change elements of L for link length change
#change elements of A for different set of joint angles

