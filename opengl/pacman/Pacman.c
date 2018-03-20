#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "pacman.h"


/*ASCII-koodit näppäimille*/
#define ESCAPE 27
#define PAGE_UP 73
#define PAGE_DOWN 81
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define SPACE 57
#define PI 3.14159265358979323846

/* Glut-ikkunan numero */
int window; 
float rotate;

char teksti[20];
char itoa_buffer[20];

int i, r1, r2, kita1, kita2;
float xpos, ypos, zpos;
int kuvakulma;
float angle, anim_x, anim_y;

GLfloat z=0.0f;
GLfloat yrot;
GLfloat kita = 0;
GLfloat kita_angle = 0;
GLfloat otus_hyppy;
GLfloat foodrotate;
GLfloat lookupdown = 0.0;
const float piover180 = 0.00874532925f; /*RAD PI/2?*/
int repeat;
float rotate_view;
float yslew;
float teksti_x, teksti_z;
signed int level_complete;

GLfloat ambient[] = { 4.0, 1.0, 0.0, 1.0 };
GLfloat diffuse[] = { 1.0, 0.0, 1.0, 1.0 };
GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat position[] = { 0.0, 3.0, 2.0, 0.0 };
GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat local_view[] = { 0.0 };
GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 0.0, 0.7, 0.0, 1.0 };
GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat no_shininess[] = { 0.0 };
GLfloat low_shininess[] = { 5.0 };
GLfloat high_shininess[] = { 50.0 };
GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};
GLfloat mat_red_pill[] = { 255.0, 0.0, 0.0, 0.0 };
GLfloat mat_green[] = { 0.0, 255.0, 0.0, 1.0 };
GLfloat mat_red[] = { 255.0, 0.0, 0.0, 1.0 };      
GLfloat mat_yellow[] = { 255.0, 255.0, 0.0, 1.0 };      
GLfloat mat_blue[] = { 0.0, 0.0, 1.0, 1.0 };


static char *circles[] = {
  "xx..............",
  "xx..............",
  "xx..............",
  "xx..............",
  "xx..............",
  "xx..............",
  "xx..............",
  "xx..............",
  "xx..............",
  "xx..............",
  "xx..............",
  "xx..............",
  "xx..............",
  "xx..............",
  "xxxxxxxxxxxxxxxx",
  "xxxxxxxxxxxxxxxx",
};


/*Tekstuurikoodi perustuu harjoitustyöhön*/

void maketexture(void)
{
  GLubyte texture[16][16][3];
  GLubyte *loc;
  int s, t;

  loc = (GLubyte*) texture;
  for (t = 0; t < 16; t++) {
    for (s = 0; s < 16; s++) {
      if (circles[t][s] == '.') {

        loc[0] = 0x00;
        loc[1] = 0x00;
        loc[2] = 0x00;
      } else {
        loc[0] = 0xff;
        loc[1] = 0xff;
        loc[2] = 0xff;
      }
      loc += 3;
    }
  }

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);   
  glTexImage2D(GL_TEXTURE_2D, 0, 3, 16, 16, 0,
      GL_RGB, GL_UNSIGNED_BYTE, texture);

}






void renderBitmapString(float x, float y, char *string)
{

char *c;
glRasterPos2f(x, y);
for (c=string; *c != '\0'; c++)
	{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

void processMenuEvents(int option) {
		switch(option) {
			case 2: stop_game(); start_game(); break;
			case 3: stop_game(); break;
			case 4: kuvakulma = 0; break;
			case 5: kuvakulma = 1; break;
			case 6: kuvakulma = 2; break;
			case 7: kuvakulma = 3; break;
			case 100: glutDestroyWindow(window), exit(0);     
		}
}


void save_highscore(int new_score)
{
FILE *highscore;

highscore = fopen("highscore.txt", "w");

if (highscore)
	{
	fprintf(highscore, "%d", new_score);
	fclose(highscore);
	}
	
update_highscore = 0;
}


void createMenus() {
	
	glutCreateMenu(processMenuEvents);
	
	glutAddMenuEntry("",-1);

	glutAddMenuEntry("Start Game", 2);
	glutAddMenuEntry("Reset Game", 3);
	glutAddMenuEntry("",-1);

	glutAddMenuEntry("Top camera", 4);
	glutAddMenuEntry("Tracking camera", 5);

	glutAddMenuEntry("",-1);
	glutAddMenuEntry("Quit", 100);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAttachMenu(GLUT_LEFT_BUTTON);
}


/*Kuvakulmat ja kamerat*/
void viewpoint(void)
{
/*Normaali pelitilanne*/
if(kuvakulma == 0)
	{
	glLoadIdentity();
	gluLookAt(-20, 30, 0, 0, 0, 0, 1.0, 0.0, 0.0);
	}

if(kuvakulma == 1)
	{
	glLoadIdentity();
	gluLookAt(-10, 20, pacposz, pacposx, 0, pacposz, 1.0, 0.0, 0.0);
	}

if(kuvakulma == 2)
	{
	glLoadIdentity();
	gluLookAt(-10, 20, pacposz, pacposx, 0, pacposz, 1.0, 0.0, 0.0);
	}

if(kuvakulma == 3)
	{
	glLoadIdentity();
	gluLookAt(-10, 20, pacposz, pacposx, 0, pacposz, 1.0, 0.0, 0.0);
	}

/*Peli ei ole käynnissä, pyöritetään kenttää.*/

if(game_routine_running == 0)
	{
	if(demo_mode == 0)
		{	
		glLoadIdentity();			
		gluLookAt(-30, 110-yslew, -30, 0, 0, 0, 0.0, 1.0, 0.0);

		if(yslew < 90) yslew+=0.1; /*Pysäyttää, kun tarpeeksi matalalla*/
		glRotatef(rotate_view*10, -0.0f, 10, 0); /*Kääntää vaakatasossa koko ruutua*/
		rotate_view+=0.001;
		}

		if(demo_mode == 1)
		{	
		glLoadIdentity();			
		gluLookAt(0,8, 0, pacposx, 0, pacposz, 0.0, 1.0, 0.0);
		}

		if(demo_mode == 3)
		{	
		glLoadIdentity();			
		gluLookAt(pacposx-8,8, pacposz-8, 0, 0, 0, 0.0, 1.0, 0.0);
		}

		if(demo_mode == 2)
		{	
		glLoadIdentity();
		gluLookAt(-10, 20, pacposz, pacposx, 0, pacposz, 1.0, 0.0, 0.0);
		}

		if(demo_mode == 4)
		{	
		glLoadIdentity();
		gluLookAt(-20, 30, 0, 0, 0, 0, 1.0, 0.0, 0.0);
		}
	}
}

/*Pelin lopetus*/
void stop_game()
{
	reset_game();
	game_routine_running = 0;
	lives = 3;
	kuvakulma = 0;

	/*Animaatio*/
	yslew = 0;
	rotate = 0;
	rotate_view = 0;
	level_complete = 0;
	pacspeed = 1;
	cpuspeed = 1;
	level = 1;
	score = 0;
}

/*Pelin käynnistys, resetointi*/
void start_game()
{
	reset_game();
	reset_food();
	kuvakulma = 0;
	food_remaining = 0;
	game_routine_running = 1;
	level_complete = 0;
}

void resurrect(void)
{
	reset_game();
	if (game_routine_running == 1)
		{
		if(lives == 0) stop_game();
		lives--;	
		}
		
	if (game_routine_running == 0)
		{
		if(lives == 0)
		{
		lives = 3;
		if(demo_mode <= 3) demo_mode++;
		else demo_mode = 0;
		}
	lives--;
		
		}
}

void success()
{
	reset_game();
	reset_food();
	kuvakulma = 0;
	food_remaining = 0;
	level_complete = 1;
	game_routine_running = 0;
}

void reset_game()
{
	pacposx = 0, pacposz = -9, suunta = 3;
	cpusuunta[0] = 0, cpusuunta[1] = 0, cpusuunta[2] = 0, cpusuunta[3] = 0, cpusuunta[4] = 3;
	cpuposx[0] = 0, cpuposz[0]= 0, cpu_valmis[0] = 0;
	cpuposx[1] = 0, cpuposz[1]= 0, cpu_valmis[1] = 0;
	cpuposx[2] = 0, cpuposz[2]= 0, cpu_valmis[2] = 0;
	cpuposx[3] = 0, cpuposz[3]= 0, cpu_valmis[3] = 0;
	cpuposx[4] = 0, cpuposz[4]= -9, cpu_valmis[4] = 0;
	if (update_highscore == 1) save_highscore(highscore_int);
}

void reset_food()
{
	for(foodloop = 0; foodloop < 320; foodloop++)
	{
	food_eaten[foodloop] = 0;	
	}
}


void InitGL()
{
	
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glClearDepth(1.0);

glDepthFunc(GL_LESS);
glEnable(GL_DEPTH_TEST);
glShadeModel(GL_SMOOTH);
glLoadIdentity();

glMatrixMode(GL_MODELVIEW);

/*Alpha-blendaus*/
glColor4f(0.1f,0.1f,0.5f,0.01f);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);

glEnable(GL_BLEND);

glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
glLightfv(GL_LIGHT0, GL_POSITION, position);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);



    glEnable(GL_FOG);
   {
      GLfloat fogColor[4] = {0.0, 0.0, 1.0, 1.0};

      fogMode = GL_LINEAR;
      glFogi (GL_FOG_MODE, fogMode);
      glFogfv (GL_FOG_COLOR, fogColor);
      glFogf (GL_FOG_DENSITY, 0.05);
      glHint (GL_FOG_HINT, GL_DONT_CARE);
      glFogf (GL_FOG_START, 50.0);
      glFogf (GL_FOG_END, 100.0);
   }
   
maketexture();
   
   
        
}

void ReSizeGLScene(int Width, int Height)
{
if (Height == 0)	Height = 1;
glViewport(0, 0, Width, Height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();

gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
glMatrixMode(GL_MODELVIEW);
}

void DrawGLScene() 
{
	
/*Tyhjentää ruudun*/
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
/*Nollaa näkymän*/
glLoadIdentity();

/*Asettaa kameran*/
viewpoint();

glDisable(GL_LIGHTING);
   /*glDisable(GL_LIGHT0);
   

glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, no_mat);
glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
glMaterialfv(GL_FRONT, GL_SHININESS, no_mat);
glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
*/

		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_red_pill);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);		


		glEnable(GL_BLEND);
		
		
		
		
		
		
		
		
		
		
		
/*Piirretään sokkelo*/
while (repeat < 50) 
	{
	glBegin(GL_QUADS);
	
	glColor3f(0.0f,0.0f,1.0f);			
  	glVertex3f(polygonx1[repeat], 1.0f, polygony1[repeat]);
  	
  	glColor3f(0.0f,1.0f,0.5f);
  	glVertex3f(polygonx2[repeat],  1.0f, polygony2[repeat]);

  	glColor3f(0.0f,0.1f,0.5f);
  	glVertex3f(polygonx2[repeat], -1.0f, polygony2[repeat]);	
 
  	glColor3f(2.0f,0.0f,2.5f);
  	glVertex3f(polygonx1[repeat], -1.0f, polygony1[repeat]);	

  	
  	
  	glColor3f(0.0f,0.0f,1.0f);
  	glVertex3f(polygonx3[repeat], 1.0f, polygony3[repeat]);

	glColor3f(0.0f,0.0f,0.1f);
	glVertex3f(polygonx4[repeat],  1.0f, polygony4[repeat]);

	glColor3f(0.0f,1.0f,1.0f);
	glVertex3f(polygonx4[repeat], -1.0f, polygony4[repeat]);	

	glColor3f(2.0f,0.0f,1.0f);
	glVertex3f(polygonx3[repeat], -1.0f, polygony3[repeat]);	

	    
	
	glColor3f(0.0f,0.0f,0.1f);
	glVertex3f(polygonx1[repeat], 1.0f, polygony1[repeat]);

	glColor3f(0.0f,0.0f,0.1f);
	glVertex3f(polygonx1[repeat],  1.0f, polygony4[repeat]);

	glColor3f(0.0f,1.0f,1.0f);
	glVertex3f(polygonx1[repeat], -1.0f, polygony4[repeat]);	

	glColor3f(2.0f,0.0f,1.0f);
	glVertex3f(polygonx1[repeat], -1.0f, polygony1[repeat]);	

	
	
	glColor3f(0.0f,0.0f,0.1f);
	glVertex3f(polygonx2[repeat], 1.0f, polygony2[repeat]);

	glColor3f(0.0f,0.0f,0.1f);
	glVertex3f(polygonx2[repeat],  1.0f, polygony3[repeat]);

	glColor3f(0.0f,1.0f,1.0f);
	glVertex3f(polygonx2[repeat], -1.0f, polygony3[repeat]);	

	glColor3f(2.0f,0.0f,1.0f);
	glVertex3f(polygonx2[repeat], -1.0f, polygony2[repeat]);	

	
	
	glColor3f(0.0f,0.0f,0.1f);
	glVertex3f(polygonx1[repeat], 1.0f, polygony1[repeat]);

	glColor3f(0.0f,0.0f,0.1f);
	glVertex3f(polygonx2[repeat], 1.0f, polygony2[repeat]);

	glColor3f(0.0f,1.0f,1.0f);
	glVertex3f(polygonx3[repeat], 1.0f, polygony3[repeat]);	

	glColor3f(2.0f,0.0f,1.0f);
	glVertex3f(polygonx4[repeat], 1.0f, polygony4[repeat]);	

	glEnd();
	repeat++;
	}
repeat = 0;


/*Piirretään teksturoitu lattia*/





glDisable(GL_BLEND);


glEnable(GL_TEXTURE_2D);
glBegin(GL_QUADS);		
glTexCoord2f(0.0f, 80.0f); glVertex3f(-14.0f,  -1.1f, -17.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f(-14.0f,  -1.1f,  15.0f);
glTexCoord2f(80.0f, 0.0f); glVertex3f( 15.0f,  -1.1f,  15.0f);
glTexCoord2f(80.0f, 80.0f); glVertex3f( 15.0f,  -1.1f, -17.0f);
glEnd();



	//lEnable(GL_BLEND);
		
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);

if(game_routine_running == 1)
	{

/*Testataan, onko pelaaja ruoan päällä*/
	while(foodloop < 320)
		{
	 
		if(pacposx >= foodx[foodloop]-0.01 && pacposx <= foodx[foodloop]+0.01 && pacposz >= foodz[foodloop]-0.01 && pacposz <= foodz[foodloop]+0.01 && food_eaten[foodloop] == 0)
			{
			food_remaining++;
			food_eaten[foodloop] = 1;
			score+=level;
			}

		foodloop++;
		}
	foodloop = 0;
/*Pallojen määrä: 288*/
	if(food_remaining == 288) success();
	}

	
/*Piirretään ruokapallot*/
while (foodloop < 311)
	{

	/*Pyöritä palloja kun peli ei ole käynnissä*/
	if(game_routine_running == 0)
		{
		glRotatef(rotate,1.0f,1.0f,1.0f);
		rotate+=0.00001;		
		food_eaten[foodloop] = 0;
		}

	/*Pallo piirretään, jos sitä ei ole syöty*/
	if (food_eaten[foodloop] == 0)
		{
		glPushMatrix();

			if (game_routine_running == 1)
			{
   			viewpoint();
    		glTranslatef (foodx[foodloop], 0.5f, foodz[foodloop]-0.25);
			}
      
			if (game_routine_running == 0)
			{
			glTranslatef (-25, 0, 25);
			glTranslatef (foodx[foodloop]*5, 0.5f, foodz[foodloop]*5);
			}
      

		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_red_pill);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
			
		glutSolidSphere(0.25, 10, 10);
		glPopMatrix();
		}
 	foodloop++;
	}
foodrotate+=0.1;
foodloop = 0;

/*Piirretään otukset*/
/*if(game_routine_running == 1)*/
{
/*Pelaaja*/
viewpoint();
glTranslatef(pacposx,kita*0.01,pacposz);

glMaterialfv(GL_FRONT, GL_AMBIENT, mat_yellow);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

glutSolidSphere(1+kita*0.001, 20, 20);

/*Hyppyytä otusta ja muuta sen kokoa*/
kita_angle+=14.0f;
kita = (float)sin(kita_angle * piover180)*90.0f;

/*Demo mode*/
if(game_routine_running == 0) suunta = cpusuunta[4];

/*Otusten liikkeet: Ylös=1, Oikea=2, Alas=3, Vasen=4*/
if(suunta == 1) pacposx+=0.1f * pacspeed;
if(suunta == 3) pacposx-=0.1f * pacspeed;

if(suunta == 2) pacposz+=0.1f * pacspeed;
if(suunta == 4) pacposz-=0.1f * pacspeed;

/*Demo mode*/	
if(game_routine_running ==0)
	{
	cpuposx[4] = pacposx;
	cpuposz[4] = pacposz;
	}


/*Tietokoneet*/

for (cpu_loop = 0; cpu_loop <4; cpu_loop++)
	{
	if (cpu_loop == 0) glMaterialfv(GL_FRONT, GL_AMBIENT, mat_green);
	if (cpu_loop == 1) glMaterialfv(GL_FRONT, GL_AMBIENT, mat_red);
	if (cpu_loop == 2) glMaterialfv(GL_FRONT, GL_AMBIENT, mat_blue);
	if (cpu_loop == 3) glMaterialfv(GL_FRONT, GL_AMBIENT, mat_green);
	if (cpu_loop == 4) glMaterialfv(GL_FRONT, GL_AMBIENT, mat_green);
	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		
	viewpoint();
	/*Otuksen liikuttaminen*/
	glTranslatef(cpuposx[cpu_loop],cpuposy*0.01,cpuposz[cpu_loop]);
	
	
	glScalef( 1,1-cpuposy*0.001,1 );
	glutSolidSphere(0.75+kita*0.0001, 20, 20);

	otus_hyppy+=3.0f;
	cpuposy = (float)sin(otus_hyppy * piover180)*90.0f;
	
	/*Otusten liikuttelu*/
	if(cpusuunta[cpu_loop] == 1) cpuposx[cpu_loop]+=0.05f * cpuspeed;
	if(cpusuunta[cpu_loop] == 3) cpuposx[cpu_loop]-=0.05f * cpuspeed;

	if(cpusuunta[cpu_loop] == 2) cpuposz[cpu_loop]+=0.05f * cpuspeed;
	if(cpusuunta[cpu_loop] == 4) cpuposz[cpu_loop]-=0.05f * cpuspeed;
	
	/*Tarkistetaan törmäykset pelaajan kanssa*/	
	if(pacposx > cpuposx[cpu_loop]-0.5 && pacposx < cpuposx[cpu_loop]+0.5 && pacposz > cpuposz[cpu_loop]-0.5 && pacposz < cpuposz[cpu_loop]+0.5) resurrect();
		
	}
	
cpu_loop = 0;

/*Pelaajan törmäykset seiniin*/
tormaysmallinnus();

/*Tietokoneen otusten ohjaus*/
AI();

}

if (score >= highscore_int) update_highscore = 1;
if (update_highscore == 1) highscore_int = score;


/*Tekstit*/

glDisable(GL_LIGHTING);

glMatrixMode(GL_PROJECTION);
glPushMatrix();
glLoadIdentity();
   
glOrtho(0, 0, 1024, 768, 0, 1);
   
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

glDisable(GL_DEPTH_TEST);
glRasterPos2f(-5, 1);
	
glBegin(GL_TRIANGLE_FAN);
glColor3f(1.0, 1.0, 1.0);
glVertex2f(0.0+20, 0.5 + kita2*0.001);
glColor3f(1.0, 1.0, 0.0);
for (i = kita1; i <= 360-kita1; i += 6) 
	{
	angle = i / 180.0 * PI;
	anim_y = sin(angle) + 0.5;
	anim_x = cos(angle);
	glVertex2f(anim_x+20, anim_y + kita2*0.001);
	}
glEnd();
	
r1++;
kita1 = (float)sin(r1 * piover180)*90.0f;

r2+=3;
kita2 = (float)sin(r2 * piover180)*90.0f;

teksti_x = -0.2, teksti_z = 0.8;

strcpy(teksti, "Level: ");
itoa(level, itoa_buffer, 10);
strcat(teksti, itoa_buffer);

strcat(teksti, " Lives: ");	
itoa(lives, itoa_buffer, 10);
strcat(teksti, itoa_buffer);

strcat(teksti, " Score: ");	
itoa(score, itoa_buffer, 10);
strcat(teksti, itoa_buffer);

strcat(teksti, " Highscore: ");	
itoa(highscore_int, itoa_buffer, 10);
strcat(teksti, itoa_buffer);

if(game_routine_running == 1) renderBitmapString(teksti_x-0.1,teksti_z, teksti);

if(level_complete == 1) 	
	{
	strcpy(teksti, "Level complete! Press [ESC] to proceed.");	
	renderBitmapString(teksti_x-0.1,teksti_z, teksti);
	}

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
  	glPopMatrix();											

	glMatrixMode(GL_MODELVIEW);

glutSwapBuffers();
}

void keyPressed(unsigned char key) 
{

    if (key == ESCAPE && level_complete == 1) 
    { 
	level++;
	cpuspeed +=0.2;
    start_game();
	}

}

int main(int argc, char **argv) 
{  
	
/*High-scoren luku tiedostosta*/
FILE *highscore;

highscore = fopen("highscore.txt", "r");

if (highscore)
	{
	fscanf(highscore, "%d", &highscore_int);
	printf("%d", highscore_int);
	fclose(highscore);
	}
	else
	{
		printf("FAIL");
	highscore_int = 0;
	}    
	
pacspeed = 1;
cpuspeed = 1;
lives = 3;

glutInit(&argc, argv);  
glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  
glutInitWindowSize(1024, 768);  
glutInitWindowPosition(0, 0);  
window = glutCreateWindow("Pacman");  
glutDisplayFunc(&DrawGLScene);  


/*Päivitä ruutu vaikka ei olisi muutoksia*/
glutIdleFunc(&DrawGLScene);

/*Ikkunan koon muutos*/
glutReshapeFunc(&ReSizeGLScene);

/*Näppäimistön luku*/
glutKeyboardFunc(&keyPressed);
glutSpecialFunc(&specialKeyPressed);

/*Tekee sokkelon ja muut 3d mallit*/
init_3d_objects();

/* Alusta ikkuna */
InitGL(640, 480);

createMenus();
glutMainLoop();  

return 1;
}
