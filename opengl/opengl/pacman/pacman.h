
#ifndef __pacman_h__
#define __pacman_h__
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void start_game();
void stop_game();
void success();
void reset_game();
void reset_food();
void tormaysmallinnus();
void AI();
void init_3d_objects();
void save_highscore(int new_score);

/*Ruoka*/
GLfloat foodx[320], foodz[320];
int food_eaten[320];
int foodloop;

/*Seinien koordinaatit*/
float polygonx1[50];
float polygony1[50];

float polygonx2[50];
float polygony2[50];

float polygonx3[50];
float polygony3[50];

float polygonx4[50];
float polygony4[50];


/*Pelaajan suunta ja kulma*/
int suunta;
int kulma;

/*Pelaajan koordinaatit*/
GLfloat pacposx, pacposz, pacposy;
float pacspeed;

/*Taso ja elämät*/
signed int level;
signed int lives;


/*CPU*/
signed int cpu_loop;
int cpusuunta[5];
GLfloat cpuposx[5], cpuposz[5], cpuposy;
signed int cpu_valmis[4];
float cpuspeed;

int demo_mode;

/*Paljonko ruokaa jäljellä*/
int food_remaining;

void specialKeyPressed(int key);
int score;
float korkeus;
signed int game_routine_running;
int highscore_int;
signed int update_highscore;
static GLint fogMode;

