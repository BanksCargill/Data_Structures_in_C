/***********************************************************
Author:                 Banks Cargill
Date Created:           10.4.19
Last Modification Date: 10.4.19
File name:              Assignment 0
Overview:               This program will calculate the area of a triangle
                        using Heron's Formula
Input:                  The input is the length of each side of the
                        triangle and it is hard coded
Output:                 Area of the triangle as a double
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{

    printf("This program will calculate the area of a triangle using Heron's formula\n\n");

    double a = 4;
    double b = 4;
    double c = 5;

    printf("The length of the sides are: %.2f, %.2f, %.2f \n\n", a, b, c);

    double semiPerimeter = (a+b+c)/2;
    double area = sqrt(semiPerimeter*(semiPerimeter-a)*(semiPerimeter-b)*(semiPerimeter-c));


    printf("The area of the triangle is %f \n\n", area);

    printf("That completes this program...\n");


    return 0;
}


