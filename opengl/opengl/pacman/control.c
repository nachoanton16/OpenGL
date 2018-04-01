#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "pacman.h"

void specialKeyPressed(int key) 
{
if(game_routine_running == 1)
{


if(suunta == 0)
{
if(kulma == 1)
{
    if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
}

if(kulma == 2)
{
    if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 3)
{
    if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 4)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 5)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_UP) suunta = 1;
}

if(kulma == 6)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 7)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
}

if(kulma == 8)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 9)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_UP) suunta = 1;
}

if(kulma == 10)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 11)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
}

if(kulma == 12)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 13)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
}

if(kulma == 14)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 15)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
}

if(kulma == 16)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 17)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 18)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 19)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 20)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 21)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
}

if(kulma == 22)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 23)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
	if(key == GLUT_KEY_UP) suunta = 1;
}

if(kulma == 24)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 25)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	
}

if(kulma == 26)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 27)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 28)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 29)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
}
if(kulma == 30)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 31)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_RIGHT) suunta = 2;

}

if(kulma == 32)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 33)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_UP) suunta = 1;
}

if(kulma == 34)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 35)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 36)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 37)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
}

if(kulma == 38)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
}

if(kulma == 39)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
}

if(kulma == 40)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 41)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;

}

if(kulma == 42)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 43)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
}

if(kulma == 44)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 45)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
}

if(kulma == 46)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 47)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_DOWN) suunta = 3;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
}

if(kulma == 48)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_DOWN) suunta = 3;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
}

if(kulma == 49)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 50)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 51)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;

}

if(kulma == 52)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 53)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 54)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
}

if(kulma == 55)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 56)
{
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 57)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 58)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 59)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
}

if(kulma == 60)
{
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 61)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 62)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 63)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

if(kulma == 64)
{
	if(key == GLUT_KEY_UP) suunta = 1;
	if(key == GLUT_KEY_LEFT) suunta = 4;
	if(key == GLUT_KEY_RIGHT) suunta = 2;
	if(key == GLUT_KEY_DOWN) suunta = 3;
}

}

}

}
