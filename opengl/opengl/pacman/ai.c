#include "pacman.h"
#include <time.h>
#include <stdlib.h>

int randomizer(int a, int b, int c, int d, int painotus)
{
	
	int suunta[3];
	int i;
	int suurin;
	suurin = 0;
	i = 0;
	
	srand( (unsigned int)time( NULL ) );
	
	
	for (i = 0; i < 4; i++)
	{
		suunta[i] = rand() % 100; 	
	}
	
	i = 0;

	
	if (painotus == 1) suunta[2] = -1;
	if (painotus == 2) suunta[3] = -1;
	if (painotus == 3) suunta[0] = -1;
	if (painotus == 4) suunta[1] = -1;
	 		
	
	if (a == 0) suunta[0] = -1;
	if (b == 0) suunta[1] = -1;
	if (c == 0) suunta[2] = -1;
	if (d == 0) suunta[3] = -1;

	
	for (i = 0; i < 4; i++) 
	{
		if (suunta[i] > suunta[suurin]) suurin = i;
	}

	return suurin+1;
}


void AI(void)
{

cpu_loop = 0;

/*Otusten lähetys*/
/*1*/	
if(cpu_valmis[0] == 0)
{		
if(cpuposz[0] <3-0.01)
{
	 cpuposz[0] +=0.01;
}
else
{
cpu_valmis[0] = 1;
cpusuunta[0] = 1;
}
}


/*2*/	
if(cpu_valmis[1] == 0 && cpu_valmis[0] == 1)
{		
if(cpuposz[1] <3-0.01)
{
	 cpuposz[1] +=0.01;
}
else
{
cpu_valmis[1] = 1;
cpusuunta[1] = 3;
}
}

/*3*/	
if(cpu_valmis[2] == 0 && cpu_valmis[1] == 1)
{		
if(cpuposz[2] <3-0.01)
{
	 cpuposz[2] +=0.01;
}
else
{
cpu_valmis[2] = 1;
cpusuunta[2] = 1;
}
}

/*4*/	
if(cpu_valmis[3] == 0 && cpu_valmis[2] == 1)
{		
if(cpuposz[3] <3-0.01)
{
	 cpuposz[3] +=0.01;
}
else
{
cpu_valmis[3] = 1;
cpusuunta[3] = 3;
}
}
	
	

for (cpu_loop = 0; cpu_loop <= 4; cpu_loop++)
	{
/*1
*/ if(cpuposx[cpu_loop] <= -12+0.05 * cpuspeed && cpuposz[cpu_loop] <= -15+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 0, 0, cpusuunta[cpu_loop]);	
}

/*2
*/ if(cpuposx[cpu_loop] >= -1-0.05 * cpuspeed && cpuposx[cpu_loop] <= -1+0.05 * cpuspeed && cpuposz[cpu_loop] >= -15-0.05 * cpuspeed && cpuposz[cpu_loop] <= -15+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 0, cpusuunta[cpu_loop]);	
}
 
/*3
*/ if(cpuposx[cpu_loop] >= 2-0.05 * cpuspeed && cpuposx[cpu_loop] <= 2+0.05 * cpuspeed && cpuposz[cpu_loop] >= -15-0.05 * cpuspeed && cpuposz[cpu_loop] <= -15+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 0, cpusuunta[cpu_loop]);	
}
 
/*4
*/ if(cpuposx[cpu_loop] >= 13-0.05 * cpuspeed && cpuposx[cpu_loop] <= 13+0.05 * cpuspeed && cpuposz[cpu_loop] >= -15-0.05 * cpuspeed && cpuposz[cpu_loop] <= -15+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 2, 3, 0, cpusuunta[cpu_loop]);	
}
 
/*5
*/ if(cpuposx[cpu_loop] >= -12-0.05 * cpuspeed && cpuposx[cpu_loop] <= -12+0.05 * cpuspeed && cpuposz[cpu_loop] >= -12-0.05 * cpuspeed && cpuposz[cpu_loop] <= -12+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 0, 4, cpusuunta[cpu_loop]);	
}
 
/*6
*/ if(cpuposx[cpu_loop] >= -7-0.05 * cpuspeed && cpuposx[cpu_loop] <= -7+0.05 * cpuspeed && cpuposz[cpu_loop] >= -12-0.05 * cpuspeed && cpuposz[cpu_loop] <= -12+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*7
*/ if(cpuposx[cpu_loop] >= -4-0.05 * cpuspeed && cpuposx[cpu_loop] <= -4+0.05 * cpuspeed && cpuposz[cpu_loop] >= -12-0.05 * cpuspeed && cpuposz[cpu_loop] <= -12+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 0, 0, cpusuunta[cpu_loop]);	
}

/*8
*/ if(cpuposx[cpu_loop] >= -1-0.05 * cpuspeed && cpuposx[cpu_loop] <= -1+0.05 * cpuspeed && cpuposz[cpu_loop] >= -12-0.05 * cpuspeed && cpuposz[cpu_loop] <= -12+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 0, 3, 4, cpusuunta[cpu_loop]);	
}

/*9
*/ if(cpuposx[cpu_loop] >= 2-0.05 * cpuspeed && cpuposx[cpu_loop] <= 2+0.05 * cpuspeed && cpuposz[cpu_loop] >= -12-0.05 * cpuspeed && cpuposz[cpu_loop] <= -12+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 0, 4, cpusuunta[cpu_loop]);	
}

/*10
*/ if(cpuposx[cpu_loop] >= 5-0.05 * cpuspeed && cpuposx[cpu_loop] <= 5+0.05 * cpuspeed && cpuposz[cpu_loop] >= -12-0.05 * cpuspeed && cpuposz[cpu_loop] <= -12+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*11
*/ if(cpuposx[cpu_loop] >= 8-0.05 * cpuspeed && cpuposx[cpu_loop] <= 8+0.05 * cpuspeed && cpuposz[cpu_loop] >= -12-0.05 * cpuspeed && cpuposz[cpu_loop] <= -12+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 0, 0, cpusuunta[cpu_loop]);	
}

/*12
*/ if(cpuposx[cpu_loop] >= 13-0.05 * cpuspeed && cpuposx[cpu_loop] <= 13+0.05 * cpuspeed && cpuposz[cpu_loop] >= -12-0.05 * cpuspeed && cpuposz[cpu_loop] <= -12+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 0, 3, 4, cpusuunta[cpu_loop]);	
}

/*13
*/ if(cpuposx[cpu_loop] >= -12-0.05 * cpuspeed && cpuposx[cpu_loop] <= -12+0.05 * cpuspeed && cpuposz[cpu_loop] >= -9-0.05 * cpuspeed && cpuposz[cpu_loop] <= -9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 0, 0, cpusuunta[cpu_loop]);	
}

/*14
*/ if(cpuposx[cpu_loop] >= -10-0.05 * cpuspeed && cpuposx[cpu_loop] <= -10+0.05 * cpuspeed && cpuposz[cpu_loop] >= -9-0.05 * cpuspeed && cpuposz[cpu_loop] <= -9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 0, 3, 4, cpusuunta[cpu_loop]);	
}

/*15
*/ if(cpuposx[cpu_loop] >= -7-0.05 * cpuspeed && cpuposx[cpu_loop] <= -7+0.05 * cpuspeed && cpuposz[cpu_loop] >= -9-0.05 * cpuspeed && cpuposz[cpu_loop] <= -9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 0, 4, cpusuunta[cpu_loop]);	
}

/*16
*/ if(cpuposx[cpu_loop] >= -4-0.05 * cpuspeed && cpuposx[cpu_loop] <= -4+0.05 * cpuspeed && cpuposz[cpu_loop] >= -9-0.05 * cpuspeed && cpuposz[cpu_loop] <= -9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 3, 4, cpusuunta[cpu_loop]);	
}

/*17
*/ if(cpuposx[cpu_loop] >= -1-0.05 * cpuspeed && cpuposx[cpu_loop] <= -1+0.05 * cpuspeed && cpuposz[cpu_loop] >= -9-0.05 * cpuspeed && cpuposz[cpu_loop] <= -9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*18
*/ if(cpuposx[cpu_loop] >= 2-0.05 * cpuspeed && cpuposx[cpu_loop] <= 2+0.05 * cpuspeed && cpuposz[cpu_loop] >= -9-0.05 * cpuspeed && cpuposz[cpu_loop] <= -9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*19
*/ if(cpuposx[cpu_loop] >= 5-0.05 * cpuspeed && cpuposx[cpu_loop] <= 5+0.05 * cpuspeed && cpuposz[cpu_loop] >= -9-0.05 * cpuspeed && cpuposz[cpu_loop] <= -9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 3, 4, cpusuunta[cpu_loop]);	
}

/*20
*/ if(cpuposx[cpu_loop] >= 8-0.05 * cpuspeed && cpuposx[cpu_loop] <= 8+0.05 * cpuspeed && cpuposz[cpu_loop] >= -9-0.05 * cpuspeed && cpuposz[cpu_loop] <= -9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 2, 3, 4, cpusuunta[cpu_loop]);	
}

/*21
*/ if(cpuposx[cpu_loop] >= 11-0.05 * cpuspeed && cpuposx[cpu_loop] <= 11+0.05 * cpuspeed && cpuposz[cpu_loop] >= -9-0.05 * cpuspeed && cpuposz[cpu_loop] <= -9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 0, 4, cpusuunta[cpu_loop]);	
}

/*22
*/ if(cpuposx[cpu_loop] >= 13-0.05 * cpuspeed && cpuposx[cpu_loop] <= 13+0.05 * cpuspeed && cpuposz[cpu_loop] >= -9-0.05 * cpuspeed && cpuposz[cpu_loop] <= -9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*23
*/ if(cpuposx[cpu_loop] >= -10-0.05 * cpuspeed && cpuposx[cpu_loop] <= -10+0.05 * cpuspeed && cpuposz[cpu_loop] >= -12-0.05 * cpuspeed && cpuposz[cpu_loop] <= -12+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*24
*/ if(cpuposx[cpu_loop] >= 11-0.05 * cpuspeed && cpuposx[cpu_loop] <= 11+0.05 * cpuspeed && cpuposz[cpu_loop] >= -12-0.05 * cpuspeed && cpuposz[cpu_loop] <= -12+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*25
*/ if(cpuposx[cpu_loop] >= -12-0.05 * cpuspeed && cpuposx[cpu_loop] <= -12+0.05 * cpuspeed && cpuposz[cpu_loop] >= -6-0.05 * cpuspeed && cpuposz[cpu_loop] <= -6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 0, 4, cpusuunta[cpu_loop]);	
}

/*26
*/ if(cpuposx[cpu_loop] >= -4-0.05 * cpuspeed && cpuposx[cpu_loop] <= -4+0.05 * cpuspeed && cpuposz[cpu_loop] >= 0-0.05 * cpuspeed && cpuposz[cpu_loop] <= 0+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 2, 3, 4, cpusuunta[cpu_loop]);	
}

/*27
*/ if(cpuposx[cpu_loop] >= -4-0.05 * cpuspeed && cpuposx[cpu_loop] <= -4+0.05 * cpuspeed && cpuposz[cpu_loop] >= -6-0.05 * cpuspeed && cpuposz[cpu_loop] <= -6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*28
*/ if(cpuposx[cpu_loop] >= -1-0.05 * cpuspeed && cpuposx[cpu_loop] <= -1+0.05 * cpuspeed && cpuposz[cpu_loop] >= -6-0.05 * cpuspeed && cpuposz[cpu_loop] <= -6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 0, 3, 4, cpusuunta[cpu_loop]);	
}

/*29
*/ if(cpuposx[cpu_loop] >= 2-0.05 * cpuspeed && cpuposx[cpu_loop] <= 2+0.05 * cpuspeed && cpuposz[cpu_loop] >= -6-0.05 * cpuspeed && cpuposz[cpu_loop] <= -6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 0, 4, cpusuunta[cpu_loop]);	
}

/*30
*/ if(cpuposx[cpu_loop] >= 5-0.05 * cpuspeed && cpuposx[cpu_loop] <= 5+0.05 * cpuspeed && cpuposz[cpu_loop] >= -6-0.05 * cpuspeed && cpuposz[cpu_loop] <= -6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*31
*/ if(cpuposx[cpu_loop] >= 5-0.05 * cpuspeed && cpuposx[cpu_loop] <= 5+0.05 * cpuspeed && cpuposz[cpu_loop] >= 0-0.05 * cpuspeed && cpuposz[cpu_loop] <= 0+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 0, 4, cpusuunta[cpu_loop]);	
}

/*32
*/ if(cpuposx[cpu_loop] >= 13-0.05 * cpuspeed && cpuposx[cpu_loop] <= 13+0.05 * cpuspeed && cpuposz[cpu_loop] >= -6-0.05 * cpuspeed && cpuposz[cpu_loop] <= -6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 0, 3, 4, cpusuunta[cpu_loop]);	
}

/*33
*/ if(cpuposx[cpu_loop] >= -4-0.05 * cpuspeed && cpuposx[cpu_loop] <= -4+0.05 * cpuspeed && cpuposz[cpu_loop] >= 3-0.05 * cpuspeed && cpuposz[cpu_loop] <= 3+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 0, 4, cpusuunta[cpu_loop]);	
}

/*34
*/ if(cpuposx[cpu_loop] >= -1-0.05 * cpuspeed && cpuposx[cpu_loop] <= -1+0.05 * cpuspeed && cpuposz[cpu_loop] >= 3-0.05 * cpuspeed && cpuposz[cpu_loop] <= 3+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*35
*/ if(cpuposx[cpu_loop] >= 2-0.05 * cpuspeed && cpuposx[cpu_loop] <= 2+0.05 * cpuspeed && cpuposz[cpu_loop] >= 3-0.05 * cpuspeed && cpuposz[cpu_loop] <= 3+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*36
*/ if(cpuposx[cpu_loop] >= 5-0.05 * cpuspeed && cpuposx[cpu_loop] <= 5+0.05 * cpuspeed && cpuposz[cpu_loop] >= 3-0.05 * cpuspeed && cpuposz[cpu_loop] <= 3+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 0, 3, 4, cpusuunta[cpu_loop]);	
}

/*37
*/ if(cpuposx[cpu_loop] >= -12-0.05 * cpuspeed && cpuposx[cpu_loop] <= -12+0.05 * cpuspeed && cpuposz[cpu_loop] >= 6-0.05 * cpuspeed && cpuposz[cpu_loop] <= 6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 0, 0, cpusuunta[cpu_loop]);	
}

/*38
*/ if(cpuposx[cpu_loop] >= -7-0.05 * cpuspeed && cpuposx[cpu_loop] <= -7+0.05 * cpuspeed && cpuposz[cpu_loop] >= 6-0.05 * cpuspeed && cpuposz[cpu_loop] <= 6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 2, 3, 4, cpusuunta[cpu_loop]);	
}

/*39
*/ if(cpuposx[cpu_loop] >= -4-0.05 * cpuspeed && cpuposx[cpu_loop] <= -4+0.05 * cpuspeed && cpuposz[cpu_loop] >= 6-0.05 * cpuspeed && cpuposz[cpu_loop] <= 6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 0, 0, cpusuunta[cpu_loop]);	
}

/*40
*/ if(cpuposx[cpu_loop] >= -1-0.05 * cpuspeed && cpuposx[cpu_loop] <= -1+0.05 * cpuspeed && cpuposz[cpu_loop] >= 6-0.05 * cpuspeed && cpuposz[cpu_loop] <= 6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 0, 3, 4, cpusuunta[cpu_loop]);	
}

/*41
*/ if(cpuposx[cpu_loop] >= 2-0.05 * cpuspeed && cpuposx[cpu_loop] <= 2+0.05 * cpuspeed && cpuposz[cpu_loop] >= 6-0.05 * cpuspeed && cpuposz[cpu_loop] <= 6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 0, 4, cpusuunta[cpu_loop]);	
}

/*42
*/ if(cpuposx[cpu_loop] >= 5-0.05 * cpuspeed && cpuposx[cpu_loop] <= 5+0.05 * cpuspeed && cpuposz[cpu_loop] >= 6-0.05 * cpuspeed && cpuposz[cpu_loop] <= 6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*43
*/ if(cpuposx[cpu_loop] >= 8-0.05 * cpuspeed && cpuposx[cpu_loop] <= 8+0.05 * cpuspeed && cpuposz[cpu_loop] >= 6-0.05 * cpuspeed && cpuposz[cpu_loop] <= 6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 0, 4, cpusuunta[cpu_loop]);	
}

/*44
*/ if(cpuposx[cpu_loop] >= 13-0.05 * cpuspeed && cpuposx[cpu_loop] <= 13+0.05 * cpuspeed && cpuposz[cpu_loop] >= 6-0.05 * cpuspeed && cpuposz[cpu_loop] <= 6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*45
*/ if(cpuposx[cpu_loop] >= -12-0.05 * cpuspeed && cpuposx[cpu_loop] <= -12+0.05 * cpuspeed && cpuposz[cpu_loop] >= 9-0.05 * cpuspeed && cpuposz[cpu_loop] <= 9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 0, 4, cpusuunta[cpu_loop]);	
}

/*46
*/ if(cpuposx[cpu_loop] >= -4-0.05 * cpuspeed && cpuposx[cpu_loop] <= -4+0.05 * cpuspeed && cpuposz[cpu_loop] >= 9-0.05 * cpuspeed && cpuposz[cpu_loop] <= 9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 3, 4, cpusuunta[cpu_loop]);	
}

/*47
*/ if(cpuposx[cpu_loop] >= -1-0.05 * cpuspeed && cpuposx[cpu_loop] <= -1+0.05 * cpuspeed && cpuposz[cpu_loop] >= 9-0.05 * cpuspeed && cpuposz[cpu_loop] <= 9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*48
*/ if(cpuposx[cpu_loop] >= 2-0.05 * cpuspeed && cpuposx[cpu_loop] <= 2+0.05 * cpuspeed && cpuposz[cpu_loop] >= 9-0.05 * cpuspeed && cpuposz[cpu_loop] <= 9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 0, cpusuunta[cpu_loop]);	
}

/*49
*/ if(cpuposx[cpu_loop] >= 5-0.05 * cpuspeed && cpuposx[cpu_loop] <= 5+0.05 * cpuspeed && cpuposz[cpu_loop] >= 9-0.05 * cpuspeed && cpuposz[cpu_loop] <= 9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 3, 4, cpusuunta[cpu_loop]);	
}

/*50
*/ if(cpuposx[cpu_loop] >= 13-0.05 * cpuspeed && cpuposx[cpu_loop] <= 13+0.05 * cpuspeed && cpuposz[cpu_loop] >= 9-0.05 * cpuspeed && cpuposz[cpu_loop] <= 9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 2, 3, 4, cpusuunta[cpu_loop]);	
}

/*51
*/ if(cpuposx[cpu_loop] >= -12-0.05 * cpuspeed && cpuposx[cpu_loop] <= -12+0.05 * cpuspeed && cpuposz[cpu_loop] >= 13-0.05 * cpuspeed && cpuposz[cpu_loop] <= 13+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 0, 4, cpusuunta[cpu_loop]);
}

/*52
*/ if(cpuposx[cpu_loop] >= -7-0.05 * cpuspeed && cpuposx[cpu_loop] <= -7+0.05 * cpuspeed && cpuposz[cpu_loop] >= 13-0.05 * cpuspeed && cpuposz[cpu_loop] <= 13+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 3, 4, cpusuunta[cpu_loop]);
}

/*53
*/ if(cpuposx[cpu_loop] >= -1-0.05 * cpuspeed && cpuposx[cpu_loop] <= -1+0.05 * cpuspeed && cpuposz[cpu_loop] >= 13-0.05 * cpuspeed && cpuposz[cpu_loop] <= 13+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 0, 3, 4, cpusuunta[cpu_loop]);
}

/*54
*/ if(cpuposx[cpu_loop] >= 2-0.05 * cpuspeed && cpuposx[cpu_loop] <= 2+0.05 * cpuspeed && cpuposz[cpu_loop] >= 13-0.05 * cpuspeed && cpuposz[cpu_loop] <= 13+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 0, 4, cpusuunta[cpu_loop]);
}

/*55
*/ if(cpuposx[cpu_loop] >= 8-0.05 * cpuspeed && cpuposx[cpu_loop] <= 8+0.05 * cpuspeed && cpuposz[cpu_loop] >= 13-0.05 * cpuspeed && cpuposz[cpu_loop] <= 13+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 0, 3, 4, cpusuunta[cpu_loop]);
}

/*56
*/ if(cpuposx[cpu_loop] >= 13-0.05 * cpuspeed && cpuposx[cpu_loop] <= 13+0.05 * cpuspeed && cpuposz[cpu_loop] >= 13-0.05 * cpuspeed && cpuposz[cpu_loop] <= 13+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 0, 3, 4, cpusuunta[cpu_loop]);
}

/*57
*/ if(cpuposx[cpu_loop] >= -7-0.05 * cpuspeed && cpuposx[cpu_loop] <= -7+0.05 * cpuspeed && cpuposz[cpu_loop] >= -6-0.05 * cpuspeed && cpuposz[cpu_loop] <= -6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 4, cpusuunta[cpu_loop]);
}

/*58
*/ if(cpuposx[cpu_loop] >= 8-0.05 * cpuspeed && cpuposx[cpu_loop] <= 8+0.05 * cpuspeed && cpuposz[cpu_loop] >= -6-0.05 * cpuspeed && cpuposz[cpu_loop] <= -6+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 4, cpusuunta[cpu_loop]);
}

/*59
*/ if(cpuposx[cpu_loop] >= -4-0.05 * cpuspeed && cpuposx[cpu_loop] <= -4+0.05 * cpuspeed && cpuposz[cpu_loop] >= -3-0.05 * cpuspeed && cpuposz[cpu_loop] <= -3+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 0, 4, cpusuunta[cpu_loop]);
}


/*60
*/ if(cpuposx[cpu_loop] >= 5-0.05 * cpuspeed && cpuposx[cpu_loop] <= 5+0.05 * cpuspeed && cpuposz[cpu_loop] >= -3-0.05 * cpuspeed && cpuposz[cpu_loop] <= -3+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 2, 3, 4, cpusuunta[cpu_loop]);
}

/*61
*/ if(cpuposx[cpu_loop] >= -7-0.05 * cpuspeed && cpuposx[cpu_loop] <= -7+0.05 * cpuspeed && cpuposz[cpu_loop] >= 0-0.05 * cpuspeed && cpuposz[cpu_loop] <= 0+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 0, 4, cpusuunta[cpu_loop]);
}

/*62
*/ if(cpuposx[cpu_loop] >= 8-0.05 * cpuspeed && cpuposx[cpu_loop] <= 8+0.05 * cpuspeed && cpuposz[cpu_loop] >= 0-0.05 * cpuspeed && cpuposz[cpu_loop] <= 0+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(0, 2, 3, 4, cpusuunta[cpu_loop]);
}

/*63
*/ if(cpuposx[cpu_loop] >= -7-0.05 * cpuspeed && cpuposx[cpu_loop] <= -7+0.05 * cpuspeed && cpuposz[cpu_loop] >= 9-0.05 * cpuspeed && cpuposz[cpu_loop] <= 9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 4, cpusuunta[cpu_loop]);
}

/*64
*/ if(cpuposx[cpu_loop] >= 8-0.05 * cpuspeed && cpuposx[cpu_loop] <= 8+0.05 * cpuspeed && cpuposz[cpu_loop] >= 9-0.05 * cpuspeed && cpuposz[cpu_loop] <= 9+0.05 * cpuspeed)
{
cpusuunta[cpu_loop] = randomizer(1, 2, 3, 4, cpusuunta[cpu_loop]);
}

}

cpu_loop = 0;




}



