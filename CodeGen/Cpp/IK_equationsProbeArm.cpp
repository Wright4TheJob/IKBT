//
//  C++ inverse kinematic equations for ProbeArm
    

#include <math.h>
#include <stdio.h>
#include <iostream>

double pi = 3.1415926;

// ikin_Wrists modifies solution_list in-place and 
// returns 1 for valid solutions and 0 for no solutions
int ikin(double T[4][4], double solution_list[64][6]);


int main()
    {
    double T[4][4] = { {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}, };
    double sol_list[64][6] = {0};  // list of solutions
    if(ikin(T, sol_list))
        {
        std::cout << sol_list;
        }
    else
        {
        std::cout <<  "No valid solution" ;
        }
    }

// Code to solve the unknowns 


// Declarations
int ikin(double T[4][4], double solution_list[64][6] )
    {
    
    //define the input vars
    double r_11 = T[0][0];
    double r_12 = T[0][1];
    double r_13 = T[0][2];
    double r_21 = T[1][0];
    double r_22 = T[1][1];
    double r_23 = T[1][2];
    double r_31 = T[2][0];
    double r_32 = T[2][1];
    double r_33 = T[2][2];
    double Px = T[0][3];
    double Py = T[1][3];
    double Pz = T[2][3];
    
    double argument;
    
    //
    // Caution:    Generated code is not yet validated
    //
    
    int True = 1;
    int False = 0;
    
    int solvable_pose = True;
    // declare variables in solutions
    double th_23s2, th_1, th_23s1, th_3s1, th_2s2, th_2s1, th_3s2;
    
    // declare constant parameters (note they will need values!)
    
    double a_1 = XXXXX ; \ deliberate undeclared error!  USER needs to give numerical value
    double l_1 = XXXXX ; \ deliberate undeclared error!  USER needs to give numerical value
    double l_2 = XXXXX ; \ deliberate undeclared error!  USER needs to give numerical value
    double l_3 = XXXXX ; \ deliberate undeclared error!  USER needs to give numerical value
    
    
    
    
    //Variable: th_1
    
    // solution 0
    // solvemethod: atan2(y,x)
    //    argument: r_13
    // Atan2(y,x) based solution:
    th_1 = atan2(r_13, r_11/r_32);
    
    
    
    //Variable: th_2
    
    // solution 0
    // solvemethod: sinANDcos
    //    argument: a*b
    
    // solution 1
    // solvemethod: sinANDcos
    //    argument: a*b
    
    
    
    //Variable: th_3
    
    // solution 0
    // solvemethod: atan2(y,x)
    //    argument: r_11*cos(th_1)*cos(th_2) + r_21*sin(th_1)*cos(th_2) + r_31*sin(th_2)
    // Atan2(y,x) based solution:
    th_3s2 = atan2(-r_11*sin(th_2s1)*cos(th_1) - r_21*sin(th_1)*sin(th_2s1) + r_31*cos(th_2s1), r_11*cos(th_1)*cos(th_2s1) + r_21*sin(th_1)*cos(th_2s1) + r_31*sin(th_2s1));
    
    // solution 1
    // solvemethod: atan2(y,x)
    //    argument: r_11*cos(th_1)*cos(th_2) + r_21*sin(th_1)*cos(th_2) + r_31*sin(th_2)
    // Atan2(y,x) based solution:
    th_3s1 = atan2(-r_11*sin(th_2s2)*cos(th_1) - r_21*sin(th_1)*sin(th_2s2) + r_31*cos(th_2s2), r_11*cos(th_1)*cos(th_2s2) + r_21*sin(th_1)*cos(th_2s2) + r_31*sin(th_2s2));
    
    
    
    //Variable: th_23
    
    // solution 0
    // solvemethod: algebra
    //    argument: a*b
    // Algebra based solution:
    th_23s2 = th_2s2 + th_3s1;
    
    // solution 1
    // solvemethod: algebra
    //    argument: a*b
    // Algebra based solution:
    th_23s1 = th_2s1 + th_3s2;
    
    //##################################
    //#
    //#package the solutions into a list for each set
    //#
    //###################################
    
    //(note trailing commas allowed in C++
    
    solution_list[0][0] = th_1;
    solution_list[0][1] = th_23s1;
    solution_list[0][2] = th_2s1;
    solution_list[0][3] = th_3s2;
    solution_list[1][0] = th_1;
    solution_list[1][1] = th_23s2;
    solution_list[1][2] = th_2s2;
    solution_list[1][3] = th_3s1;
    
    
    
    // return 1 for solved, 0 for no solution
    return(solvable_pose);
    }
