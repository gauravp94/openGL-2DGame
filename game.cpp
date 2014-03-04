//thigs left ot do
/*
	
    Make the bullets as a array
      Make the bullets reflect
      Make the limits for the respective boxes
      Work on the score of the game
      Make a better canon
      Make the spider work
      Make the initial introduction of the game
      Make the recharge of the bullet
      Start adding sound in the game
      Make difficulty level in the game
      Take things as input from a file
  11. Beautify the code
      Add Controls to the main screen

*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <GL/glut.h>
using namespace std;
//make the box stick in the bottom
//game over and pause of the game
//detect collision and then remove the box and the bullet
#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)

// Function Declarations
void drawScene();
void update(int value);
void generateSpider(int value);
void drawBox(float len, int l);
void drawB(float thick,float len, int l);
void drawRect(float len);
void drawBall(float rad);
void drawTriangle();
void lineDraw();
void getmousepos(int x, int y);
void initRendering();
void handleResize(int w, int h);
void handleKeypress1(unsigned char key, int x, int y);
void handleKeypress2(int key, int x, int y);
void move_red_box(int key, int x, int y);
void move_blue_box(int key, int x, int y);
void move_canon(int key, int x, int y);
void handleMouseclick(int button, int state, int x, int y);
void DrawEllipse(float radiusX, float radiusY);
void drawleg1(float x1,float y1,float len,float ele);
void handlemouse_drag(int x,int y);
void drawLS();
//
int sd;
int max_box=15;
int score=0;
// Global Variables
float ball_x = 1.0f;
float ball_y = 0.0f;
float ball_velx = 0.01f;
float ball_vely = 0.02f;
float ball_rad = 0.2f;
float box_len = 4.0f;
float tri_x = 0.0f;
float tri_y = 0.0f;
float theta = 0.0f; 
int flag=20;

//basket variables
float redb_x= -box_len/2 + box_len/20;
float redb_y = -box_len/2 + box_len/20;
float blueb_x= box_len/2 - box_len/20;
float blueb_y = -box_len/2 + box_len/20;
float canon_x = 0;
float canon_y = -box_len/2 ;
float lower_limit=-box_len/2;
float upper_limit=box_len/2;
float r_ul=box_len/2;
float r_ll=-box_len/2;
float b_ul = box_len/2;
float b_ll = -box_len/2;
float canon_refil = box_len/15;
//
int pflag=0;
//
float mouseposx,mouseposy,mouseposz;
int click;
int turn=1;
//box variables
float box_x[1000];
float box_y[1000];
float box_speed[1000];
float bc[1000];
int flags[1000];
int box_ctr=0;

int count=0;
int min_speed=0.25;
int max_speed=0.75;
//
int ref_flag=1;
int bullet_flag=0;
float bul_x;
float bul_y;
float bul_angle;
//spidy variables
float rad_x=0.05*box_len/4;
float rad_y=0.07*box_len/4; 
float l11=-1*0.05*box_len/4; 
float l12=0.0f; 
float l13=0.1*box_len/4; 
float l14=0.01*box_len/4; 
float l21=-0.15*box_len/4; 
float l22=0.01*box_len/4; 
float l23=0.1*box_len/4; 
float l24=0.05*box_len/4; 
float l31=-0.15*box_len/4; 
float l32=-0.03*box_len/4; 
float l33=0.1*box_len/4; 
float l34=-0.05*box_len/4; 
float l41=0.05*box_len/4; 
float l42=0.0; 
float l43=-0.1*box_len/4; 
float l44=0.01*box_len/4; 
float l51=0.15*box_len/4; 
float l52=0.01*box_len/4; 
float l53=-0.1*box_len/4; 
float l54=0.05*box_len/4; 
float l61=-0.05*box_len/4; 
float l62=-0.03*box_len/4; 
float l63=0.1*box_len/4; 
float l64=-0.01*box_len/4;
float l71=0.05*box_len/4; 
float l72=-0.03*box_len/4; 
float l73=-0.1*box_len/4; 
float l74=-0.01*box_len/4; 
float l81=0.15*box_len/4; 
float l82=-0.03*box_len/4; 
float l83=-0.1*box_len/4; 
float l84=-0.05*box_len/4; 
float l91=-0.05*box_len/4; 
float l92=0.13*box_len/4; 
float l93=-0.05*box_len/4;
float l94=-0.1*box_len/4;
float l101=-0.15*box_len/4; 
float l102=0.18*box_len/4; 
float l103=-0.1*box_len/4;
float l104=-0.05*box_len/4;
float l111=0.03*box_len/4; 
float l112=0.05*box_len/4; 
float l113=-0.05*box_len/4; 
float l114=0.1*box_len/4; 
float l121=0.08*box_len/4; 
float l122=0.15*box_len/4; 
float l123=-0.1*box_len/4; 
float l124=0.05*box_len/4; 
float l131=-0.02*box_len/4; 
float l132=-0.06*box_len/4; 
float l133=0.05*box_len/4; 
float l134=-0.1*box_len/4; 
float l141=-0.07*box_len/4; 
float l142=-0.15*box_len/4; 
float l143=0.1*box_len/4; 
float l144=-0.05*box_len/4; 
float l151=0.02*box_len/4; 
float l152=-0.05*box_len/4;
float l153=-0.05*box_len/4;
float l154=-0.1*box_len/4; 
float l161=0.06*box_len/4; 
float l162=-0.14*box_len/4; 
float l163=-0.1*box_len/4; 
float l164=-0.05*box_len/4;
int tsk_w;
int tsk_h;
int main(int argc, char **argv) {

	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	int w = glutGet(GLUT_SCREEN_WIDTH);
	int h = glutGet(GLUT_SCREEN_HEIGHT);
	int windowWidth = w;
	int windowHeight = h;
	tsk_w=w;
	tsk_h=h;
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(w ,h );

	glutCreateWindow("My Game - by pseudonym");  // Setup the window
	initRendering();

	// Register callbacks
	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	glutKeyboardFunc(handleKeypress1);
	//glutSpecialFunc(handleKeypress2);
	glutMouseFunc(handleMouseclick);
	glutReshapeFunc(handleResize);
	glutMotionFunc(handlemouse_drag);
	glutTimerFunc(100, generateSpider, 0);
	
	glutTimerFunc(10, update, 0);
	//glutTimerFunc(10, generateSpider, 0);
	glutMainLoop();
	return 0;
}

// Function to draw objects on the screen
void drawScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	// Draw Box
	//basic layout done*******************
	glTranslatef(0.0f, 0.0f, -5.0f);
	if(flag==20)//show introduction
	{
		system("aplay game_over.wav&");
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 0.0f);
		glTranslatef(0.0f,0.0f, 0.0f);
		drawB(6.0,6.0,1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		DrawEllipse(rad_x,rad_y); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l11,l12,l13,l14);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l21,l22,l23,l24); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l61,l62,l63,l64); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l31,l32,l33,l34);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l41,l42,l43,l44);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l51,l52,l53,l54); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l71,l72,l73,l74); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l81,l82,l83,l84); 
		glPopMatrix();


		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l91,l92,l93,l94);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l101,l102,l103,l104); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l111,l112,l113,l114);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l121,l122,l123,l124); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l131,l132,l133,l134); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l141,l142,l143,l144);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l151,l152,l153,l154);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l161,l162,l163,l164); 
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 1.0f, 0.0f);
		DrawEllipse(rad_x,rad_y); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l11,l12,l13,l14);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l21,l22,l23,l24); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l61,l62,l63,l64); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l31,l32,l33,l34);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l41,l42,l43,l44);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l51,l52,l53,l54); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l71,l72,l73,l74); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l81,l82,l83,l84); 
		glPopMatrix();


		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l91,l92,l93,l94);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l101,l102,l103,l104); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l111,l112,l113,l114);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l121,l122,l123,l124); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l131,l132,l133,l134); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l141,l142,l143,l144);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l151,l152,l153,l154);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l161,l162,l163,l164); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 1.0f);
		DrawEllipse(rad_x,rad_y); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l11,l12,l13,l14);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l21,l22,l23,l24); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l61,l62,l63,l64); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l31,l32,l33,l34);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l41,l42,l43,l44);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l51,l52,l53,l54); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l71,l72,l73,l74); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l81,l82,l83,l84); 
		glPopMatrix();


		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l91,l92,l93,l94);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l101,l102,l103,l104); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l111,l112,l113,l114);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l121,l122,l123,l124); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l131,l132,l133,l134); 
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l141,l142,l143,l144);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l151,l152,l153,l154);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.1f, box_len/4, 0.0f); 
		glColor3f(0.0f, 0.0f, 0.0f);
		drawleg1(l161,l162,l163,l164); 
		glPopMatrix();

		glPushMatrix();
		
		glTranslatef(0.0f,0.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glRasterPos2f(-0.25f,-0.0f);
		char string[100]="ArachNOphobia!";
		int i;
		for(i=0;i<(int)(strlen(string));i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
		char str[180]="Enter the world of arachnids, where you have a canon-blaster to squish the disguisting creatures and collect the unique ones in the baskets, to take them to EARTH!";
		//sprintf(str,"%d",score);
		glColor3f(0.0f, 0.0f, 1.0f);
		
		glRasterPos2f(-2.5f,-0.5f);		
		for(i=0;i<(int)(strlen(str));i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
			
		char str7[180]="Collect the Red and the Blue Spiders in their respective boxes and kill the black ones to get maximum points!";
		//sprintf(str,"%d",score);
		glColor3f(0.0f, 0.0f, 1.0f);
		
		glRasterPos2f(-1.5f,-0.6f);		
		for(i=0;i<(int)(strlen(str7));i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str7[i]);
		
		char str1[100]="Press '1' to choose a easy level";
		//sprintf(str,"%d",score);
		glColor3f(0.0f, 1.0f, 0.9f);
		glRasterPos2f(-0.4f,-0.75f);		
		for(i=0;i<(int)(strlen(str1));i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str1[i]);
		char str2[100]="Press '2' to choose a moderate level";
		//sprintf(str,"%d",score;
		glColor3f(0.0f, 1.0f, 0.9f);
		glRasterPos2f(-0.48f,-0.85f);		
		for(i=0;i<(int)(strlen(str2));i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str2[i]);
		

		char str3[100]="Press '3' to choose a hard level";
		//sprintf(str,"%d",score);
		glColor3f(0.0f, 1.0f, 0.9f);
		glRasterPos2f(-0.4f,-0.95f);		
		for(i=0;i<(int)(strlen(str3));i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str3[i]);
		
		char str4[100]="Press '4' to take custom input from a FILE";
		//sprintf(str,"%d",score);
		glColor3f(0.0f, 1.0f, 0.9f);
		glRasterPos2f(-0.53f,-1.05f);		
		for(i=0;i<(int)(strlen(str4));i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str4[i]);
		
				
		glPopMatrix();	
	}
	else
	{

	if(flag!=10)
	{//w that all teams are working really hard. Now its the last step towar
		glColor3f(1.0f, 0.0f, 0.0f);
		drawBox(box_len,0);
		glRasterPos2f(box_len/2 + 0.05,box_len/3);
		char string[10]="SCORE : ";
		int i;
		for(i=0;i<(int)(strlen(string));i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
		char str[80];
		sprintf(str,"%d",score);
		for(i=0;i<(int)(strlen(str));i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos2f(box_len/2 + 0.05,box_len/3-0.10);
		if(sd==1)
		{
		char string[100]="Difficulty : Easy";
		int i;
		for(i=0;i<(int)(strlen(string));i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
		glPopMatrix();
		}
		else if(sd==2)
		{
		char string[100]="Difficulty : Medium";
		int i;
		for(i=0;i<(int)(strlen(string));i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
		glPopMatrix();
		}
		else if(sd==3)
		{
char string[100]="Difficulty : Hard";
		int i;
		for(i=0;i<(int)(strlen(string));i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
		glPopMatrix();
		}
		else if(sd==4)
		{char string[100]="Difficulty :Custom";
		int i;
		for(i=0;i<(int)(strlen(string));i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
		glPopMatrix();
		}
		
	}
	
	if(pflag)
	{
		glRasterPos2f(-0.25f,0.0f);
		char string[100]="GAME PAUSED";
		int i;
		for(i=0;i<(int)(strlen(string));i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
		
	}
	//small box
	if(flag!=10)
	{
		glPushMatrix();
		glTranslatef(0.0f,(-box_len/2) + (box_len/20), 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		drawRect(box_len/10);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(box_len/2 + (tsk_w - box_len/2)/2, 0.0f,-3.0f);
		glColor3f(1.0f, 1.0f, 0.0f);
		drawB(tsk_w-box_len/2,box_len,1);
		glPopMatrix();
	
		glPushMatrix();
			//int i;
			char str1[100]="<ESC> End game";
			//sprintf(str,"%d",score);
			glColor3f(0.0f, 1.0f, 0.9f);
			glRasterPos2f(-2.0f, 2.0f-0.07f);		
			for(int j=0;j<(int)(strlen(str1));j++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str1[j]);
			char str2[100]="<P> Pause Game";
			//sprintf(str,"%d",score;
			glColor3f(0.0f, 1.0f, 0.9f);
			glRasterPos2f(-2.0f,2.0f-0.15f);		
			for(int j=0;j<(int)(strlen(str2));j++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str2[j]);
		

			char str3[100]="<R>--Red Basket <G>--Green Basket <B>--Canon";
			//sprintf(str,"%d",score);
			glColor3f(0.0f, 1.0f, 0.9f);
			glRasterPos2f(-2.0f,2.0f-0.25f);		
			for(int j=0;j<(int)(strlen(str3));j++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str3[j]);
		
			char str4[100]="Use Arrow Keys to move and rotate";
			//sprintf(str,"%d",score);
			glColor3f(0.0f, 1.0f, 0.9f);
			glRasterPos2f(-2.0f,2.0f-0.35f);		
			for(int j=0;j<(int)(strlen(str4));j++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str4[j]);
		
				
			glPopMatrix();	
		if(flag==0)
		{	
			//red box
			glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);
			glTranslatef(redb_x,redb_y, 0.0f);
			drawBox(box_len/10,0);
			glPopMatrix();
			//blue box	
			glPushMatrix();
			glTranslatef(blueb_x,blueb_y, 0.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			drawBox(box_len/10,0);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x, canon_y+box_len/40, 0.0f);
			glRotatef(45.0, 0.0f, 0.0f, -1.0f);
			glColor3f(0.3f, 0.3f, 0.3f);
			drawBox(box_len/20,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x, canon_y+box_len/40, 0.0f);
			glColor3f(0.3f, 0.3f, 0.3f);
			drawB(box_len/100,box_len/10,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x - box_len/20, canon_y+box_len/30, 0.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
			drawB(canon_refil,box_len/40,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x + box_len/20, canon_y+box_len/30, 0.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
			drawB(canon_refil,box_len/40,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x, canon_y+box_len/20, 0.0f);
			glRotatef(theta, 0.0f, 0.0f, -1.0f);
			glColor3f(0.3f, 0.3f, 0.3f);
			drawB(box_len/15,box_len/60,1);
			glPopMatrix();
		}
		else if(flag==1)//red box is activated
		{
			glPushMatrix();
			glTranslatef(redb_x,redb_y, 0.0f);
			glColor3f(1.0f, 0.0f, 0.0f);
			drawBox(box_len/10,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(blueb_x,blueb_y, 0.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			drawBox(box_len/10,0);
			glPopMatrix();


			glPushMatrix();
			glTranslatef(canon_x, canon_y+box_len/40, 0.0f);
			glRotatef(45.0, 0.0f, 0.0f, -1.0f);
			glColor3f(0.3f, 0.3f, 0.3f);
			drawBox(box_len/20,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x, canon_y+box_len/40, 0.0f);
			glColor3f(0.3f, 0.3f, 0.3f);
			drawB(box_len/100,box_len/10,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x - box_len/20, canon_y+box_len/30, 0.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
			drawB(canon_refil,box_len/40,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x + box_len/20, canon_y+box_len/30, 0.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
			drawB(canon_refil,box_len/40,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x, canon_y+box_len/20, 0.0f);
			glRotatef(theta, 0.0f, 0.0f, -1.0f);
			glColor3f(0.3f, 0.3f, 0.3f);
			drawB(box_len/15,box_len/60,1);
			glPopMatrix();

		}
		else if(flag == 2)//blue box activated
		{

			glPushMatrix();
			glTranslatef(redb_x,redb_y, 0.0f);
			glColor3f(1.0f, 0.0f, 0.0f);
			drawBox(box_len/10,0);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(blueb_x,blueb_y, 0.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			drawBox(box_len/10,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x, canon_y+box_len/40, 0.0f);
			glRotatef(45.0, 0.0f, 0.0f, -1.0f);
			glColor3f(0.3f, 0.3f, 0.3f);
			drawBox(box_len/20,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x, canon_y+box_len/40, 0.0f);
			glColor3f(0.3f, 0.3f, 0.3f);
			drawB(box_len/100,box_len/10,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x - box_len/20, canon_y+box_len/30, 0.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
			drawB(canon_refil,box_len/40,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x + box_len/20, canon_y+box_len/30, 0.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
			drawB(canon_refil,box_len/40,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x, canon_y+box_len/20, 0.0f);
			glRotatef(theta, 0.0f, 0.0f, -1.0f);
			glColor3f(0.3f, 0.3f, 0.3f);
			drawB(box_len/15,box_len/60,1);
			glPopMatrix();
		}
		else if(flag == 3)//canon activated
		{

			glPushMatrix();
			glTranslatef(redb_x,redb_y, 0.0f);
			glColor3f(1.0f, 0.0f, 0.0f);
			drawBox(box_len/10,0);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(blueb_x,blueb_y, 0.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			drawBox(box_len/10,0);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x, canon_y+box_len/40, 0.0f);
			glRotatef(45.0, 0.0f, 0.0f, -1.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
			drawBox(box_len/20,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x, canon_y+box_len/40, 0.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
			drawB(box_len/100,box_len/10,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x - box_len/20, canon_y+box_len/30, 0.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			drawB(canon_refil,box_len/40,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x + box_len/20, canon_y+box_len/30, 0.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			drawB(canon_refil,box_len/40,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(canon_x, canon_y+box_len/20, 0.0f);
			glRotatef(theta, 0.0f, 0.0f, -1.0f);
			glColor3f(0.0f, 0.0f, 0.0f);
			drawB(box_len/15,box_len/60,1);
			glPopMatrix();
		}
		//generation of the incoming boxes
		while(box_ctr<max_box)
		{

			box_x[box_ctr]=rand()%700;
			box_x[box_ctr]=box_x[box_ctr]-350;

			box_x[box_ctr]=box_x[box_ctr]/200.00;
			flags[box_ctr]=0;
			if(box_x[box_ctr]-box_len/2 < box_len/2 && box_x[box_ctr]-box_len/2 >=0)
			{
				box_x[box_ctr]+=box_len/2;
			}
			if(-box_x[box_ctr]+box_len/2 < box_len/2 && -box_x[box_ctr]+box_len/2 >=0)
			{
				box_y[box_ctr]+=box_len/2;

			}
			box_y[box_ctr]=box_len/2 + (rand()%(int)(max_box+5));
			int  speedi= rand()%10;
			float speed = speedi/100.0;
			speed += min_speed+0.01;	
			box_speed[box_ctr]=speed;
			int col = rand()%3;
			if(col==1)//red spider
			{

				bc[box_ctr]=1;//red spider
				glPushMatrix();
				glTranslatef(box_x[box_ctr],box_y[box_ctr], 0.0f);
				glColor3f(1.0f, 0.0f, 0.0f);
				drawBox(box_len/15,1);
				glPopMatrix();
			}
			else if(col==2)//gree spider
			{

				bc[box_ctr]=2;//green
				glPushMatrix();
				glTranslatef(box_x[box_ctr],box_y[box_ctr], 0.0f);
				glColor3f(0.0f, 1.0f, 0.0f);
				drawBox(box_len/15,1);
				glPopMatrix();
			}
			else//black spider
			{	

				bc[box_ctr]=0;		//black spider	
				glPushMatrix();
				glTranslatef(box_x[box_ctr],box_y[box_ctr], 0.0f);
				glColor3f(0.0f, 0.0f, 0.0f);	
				drawBox(box_len/15,1);
				glPopMatrix();

			}
			box_ctr++;

		}
		//red-> 1 green ->2 black->0
		int i;
		for(i=0;i<box_ctr;i++)
		{
			if(flags[i]==0 || flags[i]==2)//0 are the ones that are falling now and 2 are the ones that have stuck till now
			{
				if(bc[i]==1)
				{
					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(1.0f, 0.0f, 0.0f);
					DrawEllipse(rad_x,rad_y); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l11,l12,l13,l14);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l21,l22,l23,l24); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l61,l62,l63,l64); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l31,l32,l33,l34);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l41,l42,l43,l44);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l51,l52,l53,l54); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(1.0f, 0.0f, 0.0f); 
					drawleg1(l71,l72,l73,l74); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l81,l82,l83,l84); 
					glPopMatrix();


					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l91,l92,l93,l94);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l101,l102,l103,l104); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(1.0f, 0.0f, 0.0f); 
					drawleg1(l111,l112,l113,l114);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(1.0f, 0.0f, 0.0f); 
					drawleg1(l121,l122,l123,l124); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l131,l132,l133,l134); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l141,l142,l143,l144);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l151,l152,l153,l154);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(1.0f, 0.0f, 0.0f);
					drawleg1(l161,l162,l163,l164); 
					glPopMatrix();
					/*glPushMatrix();
					  glTranslatef(box_x[i],box_y[i], 0.0f);
					  glColor3f(1.0f, 0.0f, 0.0f);
					  drawBox(box_len/15,1);
					  glPopMatrix();*/
				}
				else if(bc[i]==2)
				{
					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 1.0f, 0.0f);
					DrawEllipse(rad_x,rad_y); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l11,l12,l13,l14);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l21,l22,l23,l24); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l61,l62,l63,l64); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l31,l32,l33,l34);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l41,l42,l43,l44);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l51,l52,l53,l54); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l71,l72,l73,l74); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l81,l82,l83,l84); 
					glPopMatrix();


					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l91,l92,l93,l94);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l101,l102,l103,l104); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l111,l112,l113,l114);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l121,l122,l123,l124); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l131,l132,l133,l134); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l141,l142,l143,l144);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l151,l152,l153,l154);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 1.0f, 0.0f);
					drawleg1(l161,l162,l163,l164); 
					glPopMatrix();

					/*glPushMatrix();
					  glTranslatef(box_x[i],box_y[i], 0.0f);
					  glColor3f(0.0f, 1.0f, 0.0f);
					  drawBox(box_len/15,1);
					  glPopMatrix();*/
				}
				else
				{	
					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 0.0f, 0.0f);
					DrawEllipse(rad_x,rad_y); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l11,l12,l13,l14);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l21,l22,l23,l24); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l61,l62,l63,l64); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l31,l32,l33,l34);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l41,l42,l43,l44);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l51,l52,l53,l54); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l71,l72,l73,l74); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l81,l82,l83,l84); 
					glPopMatrix();


					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l91,l92,l93,l94);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l101,l102,l103,l104); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l111,l112,l113,l114);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l121,l122,l123,l124); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l131,l132,l133,l134); 
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l141,l142,l143,l144);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f);
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l151,l152,l153,l154);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(box_x[i], box_y[i], 0.0f); 
					glColor3f(0.0f, 0.0f, 0.0f);
					drawleg1(l161,l162,l163,l164); 
					glPopMatrix();
					/*glPushMatrix();
					  glTranslatef(box_x[i],box_y[i], 0.0f);
					  glColor3f(0.0f, 0.0f, 0.0f);
					  drawBox(box_len/15,1);
					  glPopMatrix();*/
				}	
			}
		}
		//draw below box**********************


		// Draw Ball
		/*glPushMatrix();
		  glTranslatef(ball_x, ball_y, 0.0f);
		  glColor3f(0.0f, 1.0f, 0.0f);
		  drawBall(ball_rad);
		  glPopMatrix();
		  */
		// Draw Triangle
		if(bullet_flag==1)
		{
			glPushMatrix();
			glTranslatef(bul_x,bul_y,0.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			lineDraw();
			glPopMatrix();
			//cout<<bul_x<<" "<<sin(DEG2RAD(theta))<<" "<<theta<<" "<<90-theta<<bul_y<<endl;
		}



	}
	else
	{
	/*		glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
		//I like to use glm because glu is deprecated
		//glm::mat4 orth= glm::ortho(0.0f, (float)win_width, 0.0f, (float)win_height);
		//glMultMatrixf(&(orth[0][0]));
		gluOrtho2D(0.0,4, 0.0,4);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glColor3f(1.0f, 0.0f, 0.0f);//needs to be called before RasterPos
		glRasterPos2f(2.0,2.5);
		std::string s = "Game Over";
		void * font = GLUT_BITMAP_9_BY_15;

		for (std::string::iterator i = s.begin(); i != s.end(); ++i)
		{
		char c = *i;
		//this does nothing, color is fixed for Bitmaps when calling glRasterPos
		//glColor3f(1.0, 0.0, 1.0);
		glutBitmapCharacter(font, c);
		}
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
		glPushMatrix();
		glLoadIdentity();
		glColor3f(1.0f, 0.0f, 0.0f);//needs to be called before RasterPos
		glRasterPos2f(2.0,1.8);
		ostringstream convert;
		convert << score;
		string res=convert.str();

		std::string s1 = "Your Score is: "+res;
		//std::string s1 = "Your Score is:"+res;
		for (std::string::iterator i = s1.begin(); i != s1.end(); ++i)
		{
		char c = *i;
		//this does nothing, color is fixed for Bitmaps when calling glRasterPos
		//glColor3f(1.0, 0.0, 1.0);
		glutBitmapCharacter(font, c);
		}
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glEnable(GL_TEXTURE_2D);
	*/	
		
		system("aplay game_over.wav&");
		glRasterPos2f(0.0f,0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		char string[100]="GAME OVER!";
		int i;
		for(i=0;i<(int)(strlen(string));i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	
		glRasterPos2f(0.0f,-0.25f);
		char strin[10]="SCORE : ";
		for(i=0;i<(int)(strlen(strin));i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,strin[i]);
		char str[80];
		sprintf(str,"%d",score);
		for(i=0;i<(int)(strlen(str));i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);

	}
	}
	glPopMatrix();
	glutSwapBuffers();
}

// Function to handle all calculations in the scene
// updated evry 10 milliseconds
void update(int value) {
	if(!pflag && flag!=10)
	{
		int i;
		for(i=0;i<box_ctr;i++)
		{
			if(flags[i]==0)//the balls that are now falling
			{
				//condition to get stuck to the base
				if(box_y[i]+box_len/2 < box_len/15)
				{	
					box_y[i]=-box_len/2 + box_len/30;
					cout<<"getting stuck"<<endl;
					max_box++;
					flags[i]=2;
					if(box_x[i] > lower_limit && box_x[i] <= canon_x)
					{
						lower_limit = box_x[i];
					}
					if(box_x[i] < upper_limit && box_x[i] >= canon_x)
					{
						upper_limit = box_x[i];
					}
					if(box_x[i] > r_ll && box_x[i] <= redb_x)
					{
						r_ll = box_x[i];
					}
					if(box_x[i] < r_ul && box_x[i] >= redb_x)
					{
						r_ul = box_x[i];
					}
					if(box_x[i] > b_ll && box_x[i] <= blueb_x)
					{
						b_ll = box_x[i];
					}
					if(box_x[i] < b_ul && box_x[i] >= blueb_x)
					{
						b_ul = box_x[i];
					}
					score -=5;
				}
				//condition to eat any type of box only for red till nw
				if(abs(sqrt((redb_x-box_x[i])*(redb_x-box_x[i]) + (redb_y-box_y[i])*(redb_y-box_y[i]) ))<box_len/30 /*&& (flag==1)*/)
				{
					if(bc[i]==1)
					{
						flags[i]=2;
						box_y[i]=-2*box_len;
						max_box++;
						cout<<"score incremented"<<endl;	
						score++;
					}
					else
					{
						box_y[i]=-2*box_len;
						flags[i]=2;
						max_box++;	
						cout<<"score decremented"<<endl;	
						score--;
					}
				}
				if(abs(sqrt((blueb_x-box_x[i])*(blueb_x-box_x[i]) + (blueb_y-box_y[i])*(blueb_y-box_y[i]) ))<box_len/30 /*&& (flag==2)*/)
				{
					if(bc[i]==2)
					{
						flags[i]=2;
						box_y[i]=-2*box_len;
						max_box++;
						cout<<"score blue incremented"<<endl;	
						score++;
					}
					else
					{
						box_y[i]=-2*box_len;
						flags[i]=2;
						max_box++;	
						cout<<"score blue decremented"<<endl;	
						score--;
					}
				}
				//collision detection between bullet and the box
				if(abs(sqrt((bul_x-box_x[i])*(bul_x-box_x[i]) + (bul_y-box_y[i])*(bul_y-box_y[i]) ))<box_len/15 && bullet_flag==1/*&& (flag==4 || flag==3)*/)
				{
					system("aplay kill.wav&");
					if(bc[i]==0)
					{
						system("aplay kill.wav&");
						//flag=3;
						bullet_flag=0;
						box_y[i]=-2*box_len;
						max_box++;
						flags[i]=1;
						cout<<"good collision"<<endl;
						score++;

					}
					else
					{	
						system("aplay kill.wav&");//flag=3;
						bullet_flag=0;
						count=0;
						box_y[i]=-2*box_len;
						max_box++;
						flags[i]=1;
						cout<<"bad collision"<<endl;
					}
				}
				//update fuciton to check if the game has come to end or nor
				if(abs(sqrt((canon_x-box_x[i])*(canon_x-box_x[i]) + (canon_y-box_y[i])*(canon_y-box_y[i]) ))<box_len/15 )
				{
					cout<<"game exiting"<<endl;
					flag=10;
				}
			}

		}
		if(bullet_flag==1)
		{
			count+=1;
			if(count%100==0)
			{
				cout<<"reset to fire"<<endl;
				bullet_flag=0;
				system("aplay reload.wav&");
			}
		}
		bul_x += 0.05*sin(DEG2RAD(bul_angle));
		bul_y += 0.05*cos(DEG2RAD(bul_angle));
		if(bul_x<-box_len/2 )
		{
			bul_angle = 90+theta;

		}
		if(bul_x>box_len/2 )
		{
			bul_angle = 270 + theta;

		}
	}
	glutTimerFunc(10, update, 0);

}
void generateSpider(int value)
{
	if(!pflag)
	{
		int i=0;

		//cout<<"updating or not"<<box_ctr<<endl;
		for(i=0;i<box_ctr;i++)
		{
			if(flags[i]==0)
				box_y[i]-=box_speed[i];

		}
		i=0;
	}
	if(canon_refil<box_len/15)
	{
		canon_refil += box_len/150;
	}
	glutTimerFunc(100, generateSpider, 0);
}

	



void getmousepos(int x, int y)
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
	glGetDoublev( GL_PROJECTION_MATRIX, projection );
	glGetIntegerv( GL_VIEWPORT, viewport );

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

	gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
	    mouseposx=posX*100/2;
	    mouseposy=(posY*100)/2;
	    mouseposz=posZ*100;
}
void handlemouse_drag(int x,int y)
{
	if(flag!=10 && flag!=20 && !pflag)
{
	//cout<<"drag"<<endl;
    getmousepos(x,  y);
    if(click==1)
    {
		cout<<"turn "<<turn<<endl;
             if(turn==1 && mouseposx>lower_limit && mouseposx<upper_limit)
            {
                    canon_x=mouseposx;
            }
            else if(turn==3 && mouseposx>b_ll && mouseposx<b_ul)
             {
                    redb_x=mouseposx;
            }
            else if(turn==2 && mouseposx>r_ll && mouseposx<r_ul)
            {
                   	blueb_x=mouseposx;
            }
    }
    else if (click==2)
    {      
            turn=1;
             float s1=mouseposx-tri_x;
            float s2=mouseposy-tri_y;
            float temp_angle=-atan(float(s1)/s2)*180/PI;
            if(temp_angle>=-40 && temp_angle<=40)
            {
                    theta=-atan(float(s1)/s2)*180/PI;
            }
           
    }
}
}
void handleMouseclick(int button, int state, int x, int y) {

    if(flag!=10 && flag!=20 && !pflag)
	{
		if (state == GLUT_DOWN)
	    {
		
		    if (button == GLUT_LEFT_BUTTON)
		    {   
				cout<<"left_click"<<endl;   
				cout<<mouseposx<<" x"<<mouseposy<<" y"<<endl;
	    //              if(theta<=60)
	    //                      theta += 15;
		             click=1;
		             getmousepos(x,  y);
			
		            /*float c_left=canon_x-box_len/20;
		            float c_right=canon_x+box_len/20;
		            float c_top=canon_y+box_len/10;
		            float c_bottom=canon_y;
			*/
		            if(sqrt(((canon_x-mouseposx)*(canon_x-mouseposx))+((canon_y-mouseposy)*(canon_y-mouseposy)) <= box_len/40) )//1 ->canon
		             {       turn=1;	
				flag=3;
				}	
		          /*  float r_left=redb_x;
		            float r_right=redb_x;      
		            float r_top=redb_y+box_len/20;
		            float r_bottom=redb_y-box_len/20;
		            *///cout << mouseposx << endl;     
		            if(sqrt( ((redb_x-mouseposx)*(redb_x-mouseposx))+((redb_y-mouseposy)*(redb_y-mouseposy)) <= box_len/40) )//3->red
		            {        
				turn=3;
				flag=1;
			    }
		            /*float g_left=blueb_x;
		            float g_right=blueb_x;       
		            float g_top=blueb_y+box_len/20;
		            float g_bottom=blueb_y-box_len/20;*/
		            //cout << mouseposx << endl;     
		            if(sqrt( ((blueb_x-mouseposx)*(blueb_x-mouseposx))+((blueb_y-mouseposy)*(blueb_y-mouseposy)) <= box_len/40) )//2->green
		             {   
				flag=2;			 
				  turn=2;
			}
		            //cout << x << " " <<  y << endl;
		    }
		    else if (button == GLUT_RIGHT_BUTTON)
		    {
	cout<<"lasd_click"<<endl;
		             click=2;flag=3;
		    }
	    }
	    else
	    {
		    turn=4;
			flag=0;
	    }
}
}

void drawLS() { 
	glBegin(GL_LINES); 
	glVertex2f(0.0f, 0.0f);
	glVertex2f(canon_x + box_len*tan(DEG2RAD(theta)) , box_len); 
	glEnd(); 

	/*strct=lser[i]; 
	  val=90-strct.theta; 
	  strct.x1+=shift_it*cos(DEG2RAD(val)); 
	  strct.y1+=shift_it*sin(DEG2RAD(val));
	  strct.x2=laser_len*cos(DEG2RAD(val))+strct.x1; 
	  strct.y2=laser_len*sin(DEG2RAD(val))+strct.y1;
	// glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);*/ 
}


void lineDraw() { 
	glBegin(GL_LINES); 
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.5*sin(DEG2RAD(bul_angle)), 0.5*cos(DEG2RAD(bul_angle))); 
	glEnd(); 

	/*strct=lser[i]; 
	  val=90-strct.theta; 
	  strct.x1+=shift_it*cos(DEG2RAD(val)); 
	  strct.y1+=shift_it*sin(DEG2RAD(val));
	  strct.x2=laser_len*cos(DEG2RAD(val))+strct.x1; 
	  strct.y2=laser_len*sin(DEG2RAD(val))+strct.y1;
	// glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);*/ 
}

void drawBox(float len, int flag) {

	if(!flag){
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	glBegin(GL_QUADS);
	glVertex2f(-len / 2, -len / 2);
	glVertex2f(len / 2, -len / 2);
	glVertex2f(len / 2, len / 2);
	glVertex2f(-len / 2, len / 2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void drawB(float thick, float len,int flag) {

	if(!flag){
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	glBegin(GL_QUADS);
	glVertex2f(-len / 2, -thick / 2);
	glVertex2f(len / 2, -thick / 2);
	glVertex2f(len / 2, thick / 2);
	glVertex2f(-len / 2, thick / 2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void drawRect(float len) {

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
	glVertex2f(-box_len/ 2, -len / 2);
	glVertex2f(box_len / 2, -len / 2);
	glVertex2f(box_len / 2, len / 2);
	glVertex2f(-box_len / 2, len / 2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void drawBall(float rad) {

	glBegin(GL_TRIANGLE_FAN);
	for(int i=0 ; i<360 ; i++) {
		glVertex2f(rad * cos(DEG2RAD(i)), rad * sin(DEG2RAD(i)));
	}
	glEnd();
}

void drawTriangle() {

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
}

// Initializing some openGL 3D rendering options
void initRendering() {

	glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
	glEnable(GL_COLOR_MATERIAL);    // Enable coloring
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   // Setting a background color
}

// Function called when the window is resized
void handleResize(int w, int h) {

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void handleKeypress1(unsigned char key, int x, int y) {

	if(flag!=10 && flag!=20)
	{

	if (key=='P' || key=='p')
	{
		if(pflag==1)
		{
			pflag=0;
		}

		else
		{
			pflag=1;
		}

	}
	if(!pflag){	
		if (key == 27) {
			flag=10;
			//exit(0);     // escape key is pressed
		}

		if (key=='R' || key=='r')
		{
			if(flag==0 ||flag==2 || flag==3)
			{
				flag=1;
				glutSpecialFunc(move_red_box);
			}
			else if(flag==1)
			{
				flag=0;
				return;
			}
		}
		if (key=='g' || key=='G')
		{
			if(flag==0 || flag==1 || flag==3)
			{
				flag=2;
				glutSpecialFunc(move_blue_box);
			}
			else if(flag==2)
			{
				flag=0;
				return;
			}
		}
		if(key=='B' ||  key=='b')
		{
			if(flag==0 || flag==1 || flag==2)
			{
				flag=3;
				glutSpecialFunc(move_canon);
			}
			else if(flag==3)
			{
				flag=0;
				return;

			}
		}
		if(key==' ' && bullet_flag==0)
		{
			canon_refil=0;

			cout<<"fire"<<endl;
			//flag==4;
			bul_x=canon_x;
			bul_y=canon_y  + box_len/22;
			bul_angle=theta;
			bullet_flag=1;
			system("aplay laser.wav&");

		}
	}
	}
	else
	{
		if(flag==20)
		{

		if(key=='1')
		{
			cout<<"Easy"<<endl;
			flag=0;
			sd=1;
		}
		else if(key=='2')
		{
			cout<<"Medium"<<endl;
			max_box*=2;			
flag=0;
			sd=2;
			}
		else if(key =='3')
		{
			cout<<"Hard"<<endl;
			flag=0;
			max_box*=2;
			sd=3;
		}
		else if(key=='4')
		{
			sd=4;
			cout<<"Custom -> Based on file input"<<endl;
			int inpp=0;
			while(!inpp)
			{
				int tptp;
				printf("Select a difficulty level between 1 and 10\n");
				scanf("%d",&tptp);
				max_box *= (tptp/3);
				inpp++;			
			}			
			flag=0;
		}
		}
	}

}
void DrawEllipse(float radiusX, float radiusY) 
{ 
	int i; 
	glBegin(GL_TRIANGLE_FAN);
	for(i=0;i<360;i++) 
	{ 
		glVertex2f(cos(DEG2RAD(i))*radiusX,
				sin(DEG2RAD(i))*radiusY); 
	}
	glEnd(); 
}
void drawleg1(float x1,float y1,float len,float ele) { 
	//glColor3f(1.0, 0.0, 0.0); 
	glBegin(GL_LINES); 
	glVertex3f(x1, y1,0.0f); 
	glVertex3f(x1-len,y1+ele,0.0f); 
	glEnd();

} 
void handleKeypress2(int key, int x, int y) {

	/*if (key == GLUT_KEY_UP)
		tri_y += 0.1;
	if (key == GLUT_KEY_DOWN)
		tri_y -= 0.1;
	//if (key == GLUT_KEY_RIGHT)
	//	tri_x += 0.1;
*/}

void move_red_box(int key, int x, int y) {
	if(flag==1)
	{	
		if (key==GLUT_KEY_LEFT)
		{
			if(redb_x-box_len/20>(r_ll )) //box_len/20 is the move size
				redb_x-=box_len/20;
		}
		if (key == GLUT_KEY_RIGHT)
		{
			if(redb_x+box_len/20<(r_ul))
				redb_x+=box_len/20;
		}
	}
}
void move_blue_box(int key, int x, int y) {
	if(flag==2)
	{	
		if (key==GLUT_KEY_LEFT)
		{
			if(blueb_x-box_len/20>b_ll) //box_len/20 is the move size
				blueb_x-=box_len/20;
		}
		if (key == GLUT_KEY_RIGHT)
		{
			if(blueb_x<=(b_ul-box_len/10))
				blueb_x+=box_len/20;
		}
	}
}
void move_canon(int key, int x, int y) {
	if(flag==3)
	{	
		if (key==GLUT_KEY_LEFT)
		{
			if(canon_x-box_len/9 >= lower_limit) 
				canon_x-=box_len/20;
		}
		if (key == GLUT_KEY_RIGHT)
		{
			if(canon_x + box_len/7.5 <= upper_limit)
				canon_x+=box_len/20;
		}
		if (key == GLUT_KEY_UP && theta<40)
			theta += 10;
		else if (key == GLUT_KEY_DOWN && theta>-40 )
			theta -= 10;
		//cout<<theta<<endl;
	}
}

