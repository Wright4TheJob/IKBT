#!/usr/bin/python
#  Python inverse kinematic equations for ProbeArm

import numpy as np
from math import sqrt
from math import atan2
from math import cos
from math import sin

pi = np.pi



#  Declare the parameters

a_1 = 85
l_1 = 40
l_2 = 178
l_3 = 147


# Code to solve the unknowns 
def ikin_ProbeArm(T):
    if(T.shape != (4,4)):
        print "bad input to "+funcname
        quit()
#define the input vars
    r_11 = T[0,0]
    r_12 = T[0,1]
    r_13 = T[0,2]
    r_21 = T[1,0]
    r_22 = T[1,1]
    r_23 = T[1,2]
    r_31 = T[2,0]
    r_32 = T[2,1]
    r_33 = T[2,2]
    Px = T[0,3]
    Py = T[1,3]
    Pz = T[2,3]

#
# Caution:    Generated code is not yet validated
#

    
    solvable_pose = True


    #Variable:  th_1
    th_1 = atan2(-r_13, r_23)


    #Variable:  th_2
    if (solvable_pose and abs ((Pz - a_1 - l_3*r_31)/l_2)  > 1):
        solvable_pose = False
    else:
    th_2s2 = -acos((Pz - a_1 - l_3*r_31)/l_2)
    if (solvable_pose and abs ((Pz - a_1 - l_3*r_31)/l_2)  > 1):
        solvable_pose = False
    else:
    th_2s1 = acos((Pz - a_1 - l_3*r_31)/l_2)


    #Variable:  th_3
    th_3s2 = atan2(-r_11*sin(th_2s1)*cos(th_1) - r_21*sin(th_1)*sin(th_2s1) - r_31*cos(th_2s1), r_11*cos(th_1)*cos(th_2s1) + r_21*sin(th_1)*cos(th_2s1) - r_31*sin(th_2s1))
    th_3s1 = atan2(-r_11*sin(th_2s2)*cos(th_1) - r_21*sin(th_1)*sin(th_2s2) - r_31*cos(th_2s2), r_11*cos(th_1)*cos(th_2s2) + r_21*sin(th_1)*cos(th_2s2) - r_31*sin(th_2s2))


    #Variable:  th_23
    th_23s2 = th_2s2 + th_3s1
    th_23s1 = th_2s1 + th_3s2

##################################
#
#package the solutions into a list for each set
#
###################################

    solution_list = []
    #(note trailing commas allowed in python
    solution_list.append( [  th_1,  th_23s1,  th_2s1,  th_3s2,  ] )
    #(note trailing commas allowed in python
    solution_list.append( [  th_1,  th_23s2,  th_2s2,  th_3s1,  ] )
    if(solvable_pose):
        return(solution_list)
    else: 
        return(False)


#
#    TEST CODE
#
if __name__ == "__main__":

#  4x4 transforms which are pure rotations

    def RotX4_N(t):
      return(np.matrix([
        [1,         0,           0,      0],
        [0, np.cos(t),  -np.sin(t),      0],
        [0, np.sin(t),   np.cos(t),      0],
        [0,0,0,1.0]
        ]))

    def RotY4_N(t):
      return(np.matrix([
        [ np.cos(t),   0,      np.sin(t),    0],
        [0,            1,          0    ,    0],
        [-np.sin(t),   0,      np.cos(t),    0],
        [0,0,0,1]
        ]))

    def RotZ4_N(t):
      return(np.matrix([
        [ np.cos(t),  -np.sin(t),       0,    0],
        [ np.sin(t),   np.cos(t),       0,    0],
        [ 0,              0,            1,    0],
        [0,0,0,1]
        ]))

    px = 0.2   # desired EE position
    py = 0.3
    pz = 0.6
    th = np.pi/7  # just a random angle

    # generate a 4x4 pose to test IK

    T1 = RotX4_N(th) * RotY4_N(2*th)  # combine two rotations
    T1[0,3] = px
    T1[1,3] = py
    T1[2,3] = pz

    # try the Puma IK

    list = ikin_ProbeArm(T1)

    i = 0
    for sol in list:
        print ''
        print 'Solution ', i
        i+=1
        print sol


    
