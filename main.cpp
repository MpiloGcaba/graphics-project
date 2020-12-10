#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include <math.h>
#include <iostream>

// settings
const unsigned int SCR_WIDTH = 1400;
const unsigned int SCR_HEIGHT = 810;

const unsigned int SPEED = 30.0;

bool day = true;

//PromseMethods
int windowErrorHandler( GLFWwindow* window );
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

/** 
 * Draws a circle.
 * @param x - x -coordinates
 * @param y - y -coordinates
 * @param r - r of a circle
 * @param sides - dedines how many triangle should be drawn 
 *                helps with the smoothness of a circle.
 */
void circle(GLfloat x, GLfloat y, GLfloat r, GLint sides){
	
	GLfloat doublePI = 2.0f * M_PI;
	
	glBegin(GL_TRIANGLE_FAN);
		glVertex2i(x, y); // center of circle
		for(int i = 0; i <= sides; i++) { 
			glVertex2i(
		        x + (r * cos(i *  doublePI / sides)), 
			    y + (r * sin(i * doublePI / sides)));
		}
	glEnd();
}

//Sun function
void sun(){
	
	if(day){
		glColor3f(1.0f, 1.0f, 0.0f);
	}
	else{
		glColor3f(0.5f, 0.8f, 0.8f);
	}
	glTranslatef(0.0f, 0.0f, 0.0f);
	circle(100, 700, 65, 180);
}

//Clouds function
void clouds(){
	
		glColor3f(0.80f, 0.80f, 0.80f);
		//Cloud one
		circle(450, 650, 20, 10);
		circle(460, 660, 20, 10);
		circle(460, 650, 20, 10);
		circle(470, 650, 20, 10);
		circle(485, 655, 20, 10);
		circle(490, 645, 20, 10);
		circle(475, 640, 20, 10);
		circle(450, 640, 18, 10);
		circle(459, 645, 20, 10);
		circle(438, 650, 18, 10);
		

		//Second cloud
		circle(650, 750, 20, 10);
		circle(660, 760, 20, 10);
		circle(660, 750, 20, 10);
		circle(670, 750, 20, 10);
		circle(685, 755, 20, 10);
		circle(690, 745, 20, 10);
		circle(675, 740, 20, 10);
		circle(650, 740, 18, 10);
		circle(659, 745, 20, 10);
		circle(638, 750, 18, 10);
		
		//Third cloud
		circle(850, 660, 20, 10);
		circle(850, 650, 20, 10);
		circle(870, 650, 20, 10);
		circle(885, 655, 20, 10);
		circle(890, 645, 20, 10);
		circle(875, 640, 20, 10);
		circle(850, 640, 20, 10);
		circle(859, 645, 20, 10);
		circle(838, 650, 20, 10);
		

		//Forth cloud
		circle(850, 660, 20, 10);
		circle(850, 650, 20, 10);
		circle(870, 650, 20, 10);
		circle(885, 655, 20, 10);
		circle(890, 645, 20, 10);
		circle(875, 640, 18, 10);
		circle(850, 640, 20, 10);
		circle(859, 645, 20, 10);
		circle(838, 650, 18, 10);

		//Forth cloud
		circle(1150, 660, 20, 10);
		circle(1150, 650, 20, 10);
		circle(1170, 650, 20, 10);
		circle(1185, 655, 20, 10);
		circle(1190, 645, 20, 10);
		circle(1175, 640, 18, 10);
		circle(1150, 640, 20, 10);
		circle(1159, 645, 20, 10);
		circle(1138, 650, 18, 10);
	
}

//Road
void road(){
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2i(0,0);
		glVertex2i(0, 110);
		glVertex2i(SCR_WIDTH, 300);
		glVertex2i(SCR_WIDTH, 0);
    glEnd();

	glLineWidth(40);
	glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
		glVertex2i(SCR_WIDTH/4, 0);
		glVertex2i(500, 20);
		glVertex2i(550, 25);
		glVertex2i(700, 40);
		glVertex2i(750, 45);
		glVertex2i(890, 60);
		glVertex2i(940, 65);
		glVertex2i(1080, 80);
		glVertex2i(1130, 85);
		glVertex2i(SCR_WIDTH, 120);
    glEnd();
}

// Ground
void ground(){
	glColor3f(0.419608f, 0.556863f, 0.1372f);
	glBegin(GL_POLYGON);
		glVertex2i(0,110);
		glVertex2i(0,480);
		glVertex2i(SCR_WIDTH,480);
		glVertex2i(SCR_WIDTH,300);
	glEnd();
}

// Fence
void fence(){

	// Left most fance
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_LINES);
		glVertex2i(10, 125);
		glVertex2i(-10, 453);

		glVertex2i(30, 129);
		glVertex2i(10, 453);

		glVertex2i(50, 132);
		glVertex2i(30, 453);

		glVertex2i(70, 135);
		glVertex2i(50, 453);

		glVertex2i(90, 138);
		glVertex2i(70, 453);

		glVertex2i(110, 139);
		glVertex2i(90, 453);

		glVertex2i(130, 142);
		glVertex2i(110, 453);

		glVertex2i(150, 145);
		glVertex2i(130, 453);

		glVertex2i(170, 148);
		glVertex2i(150, 453);

		glVertex2i(190, 151);
		glVertex2i(170, 453);

		glVertex2i(210, 154);
		glVertex2i(190, 453);

		glVertex2i(230, 157);
		glVertex2i(210, 453);

		glVertex2i(250, 160);
		glVertex2i(230, 453);

		glVertex2i(270, 163);
		glVertex2i(250, 453);

		glVertex2i(290, 166);
		glVertex2i(270, 453);

		glVertex2i(310, 169);
		glVertex2i(290, 453);

		glVertex2i(330, 172);
		glVertex2i(310, 453);

		glVertex2i(350, 175);
		glVertex2i(330, 453);

		glVertex2i(370, 178);
		glVertex2i(350, 453);

		glVertex2i(390, 182);
		glVertex2i(370, 453);

		glVertex2i(410, 185);
		glVertex2i(390, 453);

		glVertex2i(430, 188);
		glVertex2i(410, 453);

		glVertex2i(450, 191);
		glVertex2i(430, 453);

		glVertex2i(469, 194);
		glVertex2i(450, 453);

		glVertex2i(487, 197);
		glVertex2i(469, 453);

		glVertex2i(503, 200);
		glVertex2i(487, 453);

		glVertex2i(525, 191);
		glVertex2i(513, 453);
		
		// Horizontal bar
		glVertex2i(0, 150);
		glVertex2i(520,220);

		glVertex2i(0,410);
		glVertex2i(515,420);

	//------ Left small fence ---------------
	glBegin(GL_LINES);
	
		glVertex2i(820, 365);
		glVertex2i(820, 434);

		glVertex2i(835, 362);
		glVertex2i(835, 432);

		glVertex2i(850, 360);
		glVertex2i(850, 430);

		glVertex2i(865, 358);
		glVertex2i(865, 428);
		
		// Horizontal bars left
		glVertex2i(810, 380);
		glVertex2i(880, 370);

		glVertex2i(810, 425);
		glVertex2i(880, 415);

	//------ Right small fence ----------------
		glVertex2i(1085, 370);
		glVertex2i(1085, 435);

		glVertex2i(1095, 375);
		glVertex2i(1095, 438);

		//Horizontal bars left
		glVertex2i(1080, 380);
		glVertex2i(1100, 390);

		glVertex2i(1080,425);
		glVertex2i(1100,430);

	//------ Right most fence -----------------
		glVertex2i(1270, 460);
		glVertex2i(1260, 240);

		glVertex2i(1280, 460);
		glVertex2i(1270, 240);

		glVertex2i(1290, 460);
		glVertex2i(1280, 240);

		glVertex2i(1300, 460);
		glVertex2i(1290, 240);

		glVertex2i(1310, 460);
		glVertex2i(1300, 240);

		glVertex2i(1320, 460);
		glVertex2i(1310, 240);

		glVertex2i(1330, 460);
		glVertex2i(1320, 240);

		glVertex2i(1340, 460);
		glVertex2i(1330, 240);
		
		glVertex2i(1350, 460);
		glVertex2i(1340, 240);
		
		glVertex2i(1360, 460);
		glVertex2i(1350, 240);
		
		glVertex2i(1370, 460);
		glVertex2i(1360, 240);
		
		glVertex2i(1380, 460);
		glVertex2i(1370, 240);
		
		glVertex2i(1390, 460);
		glVertex2i(1380, 240);

		glVertex2i(1400, 460);
		glVertex2i(1390, 240);
		
		//Horizontal bars left
		glVertex2i(1270, 430);
		glVertex2i(SCR_WIDTH, 430);

		glVertex2i(1270,300);
		glVertex2i(SCR_WIDTH,320);

    glEnd();
}

// Cylinders
void cylinder(){

	//------ Left cylinder------------------
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_POLYGON);
		glVertex2i(880, 305);
		glVertex2i(880, 340);
		glVertex2i(910, 335);
		glVertex2i(910, 300);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(880, 350);
		glVertex2i(880, 400);
		glVertex2i(910, 395);
		glVertex2i(910, 345);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(880, 410);
		glVertex2i(880, 435);
		glVertex2i(910, 435);
		glVertex2i(910, 405);
	glEnd();

	// Left cylinder vertical bar
	glBegin(GL_POLYGON);
		glVertex2i(885, 305);
		glVertex2i(885, 435);
		glVertex2i(905, 435);
		glVertex2i(905, 305);
	glEnd();

	//--------- Right cylinder -------------
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_POLYGON);
		glVertex2i(1050, 305);
		glVertex2i(1050, 340);
		glVertex2i(1080, 335);
		glVertex2i(1080, 302);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(1050, 350);
		glVertex2i(1050, 400);
		glVertex2i(1080, 395);
		glVertex2i(1080, 345);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(1050, 410);
		glVertex2i(1050, 435);
		glVertex2i(1080, 435);
		glVertex2i(1080, 405);
	glEnd();

	// Right cylinder vertical bar
	glBegin(GL_POLYGON);
		glVertex2i(1055, 305);
		glVertex2i(1055, 435);
		glVertex2i(1075, 435);
		glVertex2i(1075, 305);
	glEnd();

}

void walls(){
	
	glColor3f(0.36f, 0.25f, 0.20f);
	//Left wall 
	glBegin(GL_POLYGON);
		glVertex2i(530,180);
		glVertex2i(520,420);
		glVertex2i(650,420);
		glVertex2i(655,198);
	glEnd();

	//Left side Wall 
	glBegin(GL_POLYGON);
		glVertex2i(655,198);
		glVertex2i(650,420);
		glVertex2i(810,435);
		glVertex2i(810,320);
	glEnd();

	// Left small wall
	glBegin(GL_POLYGON);
		glVertex2i(810,320);
		glVertex2i(810,360);
		glVertex2i(880,350);
		glVertex2i(880,305);
	glEnd();
	
	glColor3f(0.36f, 0.25f, 0.20f);
	//small wall
	glBegin(GL_POLYGON);
		glVertex2i(1080,310);
		glVertex2i(1080,365);
		glVertex2i(1100,375);
		glVertex2i(1098,320);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2i(1098,320);
		glVertex2i(1100,440);
		glVertex2i(1220,435);
		glVertex2i(1215,273);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2i(1215,273);
		glVertex2i(1220,435);
		glVertex2i(1280,440);
		glVertex2i(1270,280);
	glEnd();
}

void gate(){
	glColor3f(0.32f,0.49f,0.46f);
	if(day){
		
		glBegin(GL_POLYGON);
			glVertex2i(910,305);
			glVertex2i(913,437);
			glVertex2i(940,435);
			glVertex2i(940,315);
		glEnd();
		
		glBegin(GL_POLYGON);
			glVertex2i(982,305);
			glVertex2i(983,437);
			glVertex2i(1050,435);
			glVertex2i(1048,305);
		glEnd();
	}
	else{
		glBegin(GL_POLYGON);
			glVertex2i(910,305);
			glVertex2i(913,437);
			glVertex2i(980,435);
			glVertex2i(975,305);
		glEnd();
		
		glBegin(GL_POLYGON);
			glVertex2i(982,305);
			glVertex2i(983,437);
			glVertex2i(1050,435);
			glVertex2i(1048,305);
		glEnd();
	}
}

/**
 * @param PointX - x coordinates.
 * @param PointY - y coordinates.
 * 
 * T1 - Triangle one
 * T2 - Triangle two
*/
void star( GLint PointOneX, GLint T1PointOneY, GLint PointTwoX, 
		GLint T1PointTwoY, GLint PointThreeX, GLint T2PointOneY,
		GLint T2PointTwoY){

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glVertex2i(PointOneX, T1PointOneY);
		glVertex2i(PointTwoX, T1PointTwoY);
		glVertex2i(PointThreeX, T1PointTwoY);
		glVertex2i(PointOneX, T2PointOneY);
		glVertex2i(PointTwoX, T2PointTwoY);
		glVertex2i(PointThreeX, T2PointTwoY);
	glEnd();
}

// Trees function
// This is just for code cleaness
void stars(){
	star(100,528, 95,520, 105,518, 525);
	star(200,628, 195,620, 205, 618,625);
	star(300,468, 295,460, 305, 458,465);
	star(375,598, 370,590, 380, 587,595);
	star(500,543, 495,535, 505, 532,540);
	star(575,653, 570,645, 580, 642,650);
	star(975,643, 970,635, 980, 632,640);
	star(875,543, 870,535, 880, 532,540);
}


void stickmanPart(GLint xStart, GLint yStart, GLint xEnd, GLint yEnd){
	glBegin(GL_LINES);
	glVertex2i(xStart, yStart);
	glVertex2i(xEnd, yEnd);
}
void stickman(){
	
	glLineWidth(60);
	glColor3f(0.0f, 0.0f, 0.0f);
	//head
	circle(600,350, 15, 50);
		
		//body
		stickmanPart(600, 255, 600, 340);
		
		//left leg
		stickmanPart(600, 260, 570, 180);

		//right leg
		stickmanPart(600, 260, 630, 200);

		//left arm
		stickmanPart(600, 320, 570, 300);

		//left wrist
		stickmanPart(572, 300, 573, 280);

		//right arm
		stickmanPart(600, 320, 620, 290);

		//right wrist
		stickmanPart(617, 290, 640, 290);

	glEnd();
}

//Left most building
void leftBuilding(){

	// Building frame 
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_POLYGON);
		glVertex2i(0,480);
		glVertex2i(0,600);
		glVertex2i(575,530);
		glVertex2i(575,480);
	glEnd();

	glColor3f(0.0f,0.0f,0.0f);
	//Window one
	glBegin(GL_POLYGON);
		glVertex2i(0,480);
		glVertex2i(0,580);
		glVertex2i(125,565);
		glVertex2i(125,480);
	glEnd();
	//Window two
	glBegin(GL_POLYGON);
		glVertex2i(160,480);
		glVertex2i(160,565);
		glVertex2i(265,553);
		glVertex2i(265,480);
	glEnd();
	//Window three
	glBegin(GL_POLYGON);
		glVertex2i(280,480);
		glVertex2i(280,550);
		glVertex2i(350,543);
		glVertex2i(350,480);
	glEnd();
	//Window four
	glBegin(GL_POLYGON);
		glVertex2i(360,480);
		glVertex2i(360,543);
		glVertex2i(404,538);
		glVertex2i(404,480);
	glEnd();
	//Window five
	glBegin(GL_POLYGON);
		glVertex2i(410,480);
		glVertex2i(410,537);
		glVertex2i(459,533);
		glVertex2i(459,480);
	glEnd();
	//Window six
	glBegin(GL_POLYGON);
		glVertex2i(466,480);
		glVertex2i(466,532);
		glVertex2i(505,528);
		glVertex2i(505,480);
	glEnd();
	//Window seven
	glBegin(GL_POLYGON);
		glVertex2i(510,480);
		glVertex2i(510,528);
		glVertex2i(540,525);
		glVertex2i(540,480);
	glEnd();
	//Window eigth
	glBegin(GL_POLYGON);
		glVertex2i(545,480);
		glVertex2i(545,525);
		glVertex2i(570,522);
		glVertex2i(570,480);
	glEnd();

	// Roof
	glColor3f(0.5f, 0.2f, 0.2f);
	glBegin(GL_POLYGON);
		glVertex2i(0,600);
		glVertex2i(0,635);
		glVertex2i(108,650);
		glVertex2i(254,630);
		glVertex2i(533,535);
	glEnd();
	
	// Left roof triangle
	glColor3f(0.7f, 0.1f, 0.1f);
	glBegin(GL_TRIANGLES);
		glVertex2i(0,635);
		glVertex2i(54,680);
		glVertex2i(108,650);
	glEnd();

	// Right roof triangle
	glBegin(GL_TRIANGLES);
		glVertex2i(108,650);
		glVertex2i(181,670);
		glVertex2i(254,630);
	glEnd();
}

void centerBuilding(){

	//roof lines
	glColor3f(1.0f ,1.0f ,1.0f);
	glBegin(GL_LINES);
		glVertex2i(460,560);
		glVertex2i(620,600);

		glVertex2i(620,600);
		glVertex2i(690,600);

		glVertex2i(690,560);
		glVertex2i(685,500);

		glVertex2i(760,600);
		glVertex2i(830,600);

		glVertex2i(830,600);
		glVertex2i(930,580);
		
	glEnd();


	//big center building
	glColor3f(0.36f, 0.25f, 0.20f);

	//left wall
	glBegin(GL_POLYGON);
		glVertex2i(460,480);
		glVertex2i(460,560);
		glVertex2i(620,600);
		glVertex2i(620,480);
	glEnd();

	//front wall
	glBegin(GL_POLYGON);
		glVertex2i(620,480);
		glVertex2i(620,600);
		glVertex2i(830,600);
		glVertex2i(830,480);
	glEnd();

	

	//right wall
	glBegin(GL_POLYGON);
		glVertex2i(830,480);
		glVertex2i(830,600);
		glVertex2i(930,580);
		glVertex2i(930,480);
	glEnd();
	//windows
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex2i(440,538);
		glVertex2i(440,555);
		glVertex2i(620,600);
		glVertex2i(620,580);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(620,580);
		glVertex2i(620,600);
		glVertex2i(830,600);
		glVertex2i(830,580);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(830,580);
		glVertex2i(830,600);
		
		glVertex2i(930,580);
		glVertex2i(930,560);
		
	glEnd();

	//poles
	glColor3f(1.0f, 1.2f, 1.2f);
	glBegin(GL_LINES);
		glVertex2i(680,480);
		glVertex2i(680,610);
		glVertex2i(765,610);
		glVertex2i(765,480);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2i(700,480);
		glVertex2i(700,510);

		glVertex2i(700,510);
		glVertex2i(755,510);

		glVertex2i(755,510);
		glVertex2i(755,480);
	glEnd();

	glColor3f(0.419608f, 0.556863f, 0.1372f);
	glBegin(GL_POLYGON);
		glVertex2i(700,480);
		glVertex2i(700,510);
		glVertex2i(727,510);
		glVertex2i(727,480);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(728,480);
		glVertex2i(728,510);
		glVertex2i(755,510);
		glVertex2i(755,480);
	glEnd();

	//Roof lines
	glColor3f(1.0f ,1.0f ,1.0f);
	glBegin(GL_LINES);
	
		glVertex2i(685,604);
		glVertex2i(675,590);

		glVertex2i(675,590);
		glVertex2i(770,590);

		glVertex2i(770,590);
		glVertex2i(760,604);
		
	glEnd();
	
	//roof
	glColor3f(0.5f, 0.2f, 0.2f);
	glBegin(GL_POLYGON);
		glVertex2i(680,590);
		glVertex2i(700,640);
		glVertex2i(740,640);
		glVertex2i(765,590);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(740,604);
		glVertex2i(740,640);
		glVertex2i(830,604);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(620,604);
		glVertex2i(700,640);
		glVertex2i(690,604);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(460,564);
		glVertex2i(626,605);
		glVertex2i(700,640);
	glEnd();
	

	//steps
	glColor3f(1.0f,0.0f,1.0f);
	glBegin(GL_LINES);

		//left steps
		glVertex2i(720,490);
		glVertex2i(740,450);

		glVertex2i(738,450);
		glVertex2i(760,450);
		
		glVertex2i(758,450);
		glVertex2i(770,430);
		
		//right steps
		glVertex2i(820,490);
		glVertex2i(840,450);

		glVertex2i(838,450);
		glVertex2i(860,450);
		
		glVertex2i(858,450);
		glVertex2i(880,400);

	glEnd();
	//under left steps
	glBegin(GL_POLYGON);
		glVertex2i(718,490);
		glVertex2i(720,470);
		glVertex2i(737,449);
	glEnd();
	//under left steps
	glBegin(GL_POLYGON);
		glVertex2i(738,449);
		glVertex2i(760,449);
		glVertex2i(770,430);
	glEnd();

	
	//right under steps
	glBegin(GL_POLYGON);
		glVertex2i(818,480);
		glVertex2i(818,490);
		glVertex2i(840,450);
		glVertex2i(840,440);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2i(840,440);
		glVertex2i(840,450);
		glVertex2i(860,450);
		glVertex2i(860,440);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(860,440);
		glVertex2i(860,450);
		glVertex2i(880,400);
		glVertex2i(880,390);
	glEnd();

}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
	if(day){
		glClearColor(0.0, 0.498039, 1.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
		clouds();
	}
	else{ stars(); }
	
	sun();	
	road();
	ground();
	walls();
	cylinder();
	gate();
	centerBuilding();
	leftBuilding();
	fence();

	if(day){
		stickman();
	}
	

	glFlush();
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void inputHandler(GLFWwindow *window){

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    if(glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS){
		day = true;
		
    }

    if(glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS){
        
		day = false;
		glClearColor(0.0f,0.0f,0.0f,0.0f);
        glClear(GL_COLOR_BUFFER_BIT); 
    }
    
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height){

    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

int main(){
    
    GLFWwindow* window;

    if(!glfwInit()){ return -1; }
    
    glewInit();

    // glfw window creation
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "MY PARK", NULL, NULL);
    windowErrorHandler(window);

    // render loop
    while (!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT);

        inputHandler(window);
		display();
        
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

//Returns a error messages in console if the window crashes
int windowErrorHandler( GLFWwindow* window ){
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
	//Makes current contex window
    glfwMakeContextCurrent(window);
	

	// essentially set coordinate system
    glOrtho( 0, SCR_WIDTH, 0, SCR_HEIGHT, 0, 1 ); 
	 
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return 0;
}
