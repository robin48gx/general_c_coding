/*
Calculator for Bridge voltages given four resistance values

     A
   /   \
  R1   R2
 /       \
 B        C
  \      /
   R3  R4
     \ /
      D

5V on A
0V on D
voltage diff between B and C calculated
      */



#include <stdio.h>
#include <stdlib.h>


// compile on linux as
// gcc -o br bridge_v.c
//
// run as
// ./br 10 10 10 10.1
//
int main(int argc, char **argv)
{

    double r1, r2, r3, r4;
    double v = 5.0;

    if (argc != 5) {
        printf(" usage: %s R1 R2 R3 R4 \n", argv[0]);
        printf(" usage: resistances in k Ohm\n"    );
    } else {

        r1 = atof(argv[1])*1000.0;
        r2 = atof(argv[2])*1000.0;
        r3 = atof(argv[3])*1000.0;
        r4 = atof(argv[4])*1000.0;

        printf(" Voltage diff == %f\n", v * (r2 * r3 - r1 * r4) / ((r1 + r3) * (r2 + r4)));
    }

}
