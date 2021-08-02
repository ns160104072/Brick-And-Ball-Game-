
/*
	author: NAZMUS SAKIB
	last modified: December, 30, 2016
*/

#include<iostream>
using namespace std;
# include "iGraphics.h"

#define _CRT_SECURE_NO_WARNINGS
#define screenWidth 1200
#define screenHight 650
#define yAxisMargin 50
#define totalBricks 4*10
#define qetaDefine 0
#define PI 3.14159235

bool isBullet = false;
//int mode;
//int lives = 1;
//void pages();
char str[80];

int levelState = 1;
/*int point_x = screenWidth / 2;
int point_y = screenHight;
int point_dx = 30;
int point_dy = 30;
int point_x1 = screenWidth / 4;
int point_y1 = screenHight;
 point_dx1 = 30;
 point_dy1 = 30;
int point_x2 = screenWidth / 3;
int point_y2 = screenHight;
int point_dx2= 30;
int point_dy2 = 30;
int point_x3 = screenWidth / 5;
int point_y3 = screenHight;
int point_dx3 = 30;
int point_dy3 = 30;
bool isPoint = false;
bool isPoint1 = false;
bool isPoint2 = false;
bool isPoint3 = false;*/

int callPointTimer;

//#define SPEED1 2
//#define SPEED2 1
#define choice 

struct brickStructure
{
	int x;
	int y;
	int dx = 100;
	int dy = 20;
	bool show = true;  
	int red;
	int green;
	int blue;
};
brickStructure bricks[totalBricks];

struct highScore
{
	char name[20];
	int score;

}player, saved[5], temp;

FILE *fp;

//int length;*/

//FILE *fp;

/*bool takeInput;
bool newHighScore;
char highScore0[20];
char highScore1[20];
char highScore2[20];
char highScore3[20];
char highScore4[20];
void gameOverPage();*/

/*void scoreSort()
{
	fp = fopen("High Scores.txt", "w");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j > i; j--)
		{
			if (saved[j].score > saved[j - 1].score)
			{
				strcpy(temp.name, saved[j].name);
				strcpy(saved[j].name, saved[j - 1].name);
				strcpy(saved[j - 1].name, temp.name);

				temp.score = saved[j].score;
				saved[j].score = saved[j - 1].score;
				saved[j - 1].score = temp.score;
			}
		}
	}

	for (int j = 0; j <= 5; j++)
	{
		fputs(saved[j].name, fp);
		fprintf(fp, " %d\n", saved[j].score);
	}

	fclose(fp);
}*/


/////// Scoring 

char showScore[20];
struct point
{
	int x;
	int y;
	int value;
	bool status;
}point[5];

int pointTimer;

char lifeCountString[10] = "3";
char scoreCountString[5];
int x_ball = (int)screenWidth / 2;
int y_ball = yAxisMargin;
int xboard = x_ball - 50;
int yboard = y_ball-10;
int dxboard = 100;
int dyboard = 10;
int radius = 10;
bool musicOn = true;
//bool musicOn1 = true;

int point_dx1 = 40;
int point_dy1 = 40;

int lifeCount = 3;
//int scoreCount = 0;
int bullet_x = xboard + 45;
int bullet_y = yboard + dyboard;
int bullet_dx = 10;
int bullet_dy = 20;
int page = 0;
//int bullet_x1 = xboard + dxboard-10;
//int bullet_y1= yAxisMargin;
//int bullet_dx1 =10;
//int bullet_dy1 = 20;




//int  dx = 7;
//int  dy = 5;


int mposx, mposy;
int red = 255;
int green =255;
int blue = 255;
int bullet = 0;
int score = 0;

//int page = 1; // homemenu == 0 // gameplay == 1;


int qeta = 60;

int v = 10;
//int dx = v*cos(qeta);
//  int dy = v*sin(qeta);
int dx = (int)v*cos(qeta*PI / 180);
int dy = (int) v*sin(qeta*PI / 180);



bool isStarted = false;
void defineBricks();
void restartBall();
void textShow();
void defineBricks();
void displayLifes();
void displayScore();
void lifeShow();


// point initialize

void pointInitialize()
{
	for (int i = 0; i < 5; i++)
	{
		point[i].x = rand() % screenWidth;
		point[i].y = screenHight;
		point[i].value = i;
		point[i].status = false;
	}
}

void mainMenu()
{
	
	iShowBMP(0, 0, "pics\\menu5.bmp");// ishowbmp

}

void instruction()
{
	iShowBMP(0, 0, "pics\\instruction14.bmp");
}
void highScore()
{
	iShowBMP(0, 0, "pics\\HighScorePage2.bmp");
}
void gameOverPage()
{
	iShowBMP(0, 0, "pics\\5.bmp");
	iSetColor(0, 0, 0);
	iFilledRectangle(550, 200, 150, 35);
	iSetColor(255, 255, 255);
	iText(570, 210, "SCORE", GLUT_BITMAP_HELVETICA_18);
	iText(650, 210, str, GLUT_BITMAP_HELVETICA_18);

}
void congratulationPage(){
	iShowBMP(0, 0, "pics\\congratulation4.bmp");
}

void game()
{
	
	/*if (musicOn)
	{
		musicOn = false;
		PlaySound(0, 0, 0);
	}*/
	void ballChange();
	
	///game play
	//displayScore();
	lifeShow();
	//iShowBMP(0,0,)
	iShowBMP(0, 0, "pics\\s4.bmp");
	//iShowBMP(550, 330, "pics\\s7.bmp");
	iSetColor(red, green, blue);
	//iText(100, 610, "LIFE:");
	//iText(100 + 50, 610, lifeCountString);
	//iText(800, 610, "Score:");
	//iText(800 + 50, 610, scoreCountString);
	iSetColor(255, 255, 255);
	_itoa_s(score, str, 10);
	iText(800, 610, "SCORE", GLUT_BITMAP_HELVETICA_18);
	iText(880, 610, str, GLUT_BITMAP_HELVETICA_18);


	// iText(545, 630, "SAKIB PRODUCTION");
	lifeShow();
	iText(520, 610, "SPACE FOR START", GLUT_BITMAP_HELVETICA_18);
	iText(460, 570, "P FOR PAUSE AND R FOR RESUME", GLUT_BITMAP_HELVETICA_18);
	iSetColor(255, 255, 255);
	iFilledCircle(x_ball, y_ball, radius, 1000);
	iSetColor(153, 217, 234);
	iFilledRectangle(xboard, yboard, dxboard, dyboard);
	iSetColor(185, 122, 87);

	iFilledRectangle(bullet_x, bullet_y, bullet_dx, bullet_dy);
	//iFilledRectangle(bullet_x1 , bullet_y1, bullet_dx1, bullet_dy1);
	//iFilledRectangle(point_x, point_y, point_dx, point_dy);


	for (int i = 0; i < 5; i++)
	{
		if (point[i].status)
		{
			if (point[i].value == 0)
			{
				iSetColor(250, 180, 48);
			}
			else if (point[i].value == 1)
			{

				iSetColor(230, 0, 0);
			}
			else if (point[i].value == 2)
			{
				iSetColor(0, 0, 160);
			}
			else if (point[i].value == 3)
			{
				iSetColor(0, 128, 0);
			}
			else if (point[i].value == 4){
				iSetColor(255, 255, 0);
			}

			iFilledRectangle(point[i].x, point[i].y, point_dx1, point_dy1);

		}
	}

	for (int i = 0; i < totalBricks; i++)
	{
		if (bricks[i].show)
		{
			iSetColor(bricks[i].red, bricks[i].green, bricks[i].blue);
			iFilledRectangle(bricks[i].x, bricks[i].y, bricks[i].dx, bricks[i].dy);
		
			iShowBMP(bricks[i].x + 1.5, bricks[i].y + 1.5, "pics\\s19.bmp");
		}
	}

}


void iDraw()
{
	//place your drawing codes here	
	iClear();
	
	if (page == 0)
	{

		mainMenu();

		// home menu
		///background
		///button image
	}
	else if (page == 1)
	{
		
		game(); // playgame
	}
	else if (page == 2)
	{
		highScore();// highscore
	}
	else if (page == 3)
	{
		
		instruction();// instruction
	}
	else if (page == 4)
	{
		  gameOverPage();		// gameover
	}
	else if (page == 5){
		 congratulationPage();
	}
	
}


/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (page == 0)
		{
			if (my >= 476 - 59 && my <= 476)
			{
				if (mx >= 660 - 180 && mx <= 660)
					page++;
	
				cout << page << endl;
			}
			/*pressing high score*/
		  if (page == 0){
				if (my >= 387 - 71 && my <= 387)
				{
					if (mx >= 674 - 201 && mx <= 674)
						page = 2;

				}
			}
			/*instruction*/
		 if (page == 0){
				if (my >= 286 - 60 && my <= 286)
				{
					if (mx >= 683 - 221 && mx <= 683)
						page = 3;
				}
			}

			/*exit*/
		 if (page == 0){
				if (my >= 198 - 52 && my <= 198)
				{
					if (mx >= 611 - 78 && mx <= 611)
						exit(0);
				}
			}//if ( mx , my // between newGame rectangle) page = 1
			// else if (mx , my // between instruction) page = 2

		}
	 if (page == 2)
		{
			if (my >= 226 - 170 && my <= 226)
			{
				if (mx >= 1087 - 261 && mx <= 1087)
					page = 0;

			}
		}
	 if (page == 3)
		{
			if (my >= 99 - 36 && my <= 99)
			{
				if (mx >= 805 - 404 && mx <= 805)
					page = 0;
					
			}
		}
	 if (page == 4)
		{
			if (my >= 111- 89 && my <= 111)
			{
				if (mx >= 1083 - 256 && mx <= 1083)
					 exit(0);

			}
		}
	 if (page == 4)
		{
			if (my >= 598 -130 && my <= 598)
			{
				if (mx >= 661 - 177 && mx <= 661)
					page = 0;
				//isStarted = false;

			}
		}
	 if (page == 5)
	 {
		 if (my >=451-62 && my <= 451)
		 {
			 if (mx >= 801 - 434 && mx <= 801)
				 page = 0;
			 //isStarted = false;

		 }
	 }
	 if (page == 5)
	 {
		 if (my >= 647 - 62 && my <= 647)
		 {
			 if (mx >= 1200 - 56 && mx <= 1200)
				 exit(0);

		 }
	 }
	}
	

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void gameover()
{
	if (y_ball < yboard)
	{
		if (lifeCount != 0)
		{
			lifeCount--;
			lifeShow();
			page = 4;
			//restartBall();
			textShow();
			//lifecount();
		}
		else
		{
			lifeCount = 3;
			page = 4;
			//lifeShow();
			//page = 0; /// returning to homemenu /// game over page
		}
	}
}

void congratulation()
{
	
}
void iKeyboard(unsigned char key)
{

	if (key == ' ')

	if (!isStarted)
	{
		isStarted = true;
	}
	if (key == 'r')
	{
		iResumeTimer(0);
		isStarted = true;
	}
	if (key == 'p')
	{
		iPauseTimer(0);
		isStarted = false;
	}
	
	if (key == 's')
	{
		if (bullet == 1){
			isBullet = true;
		}
	}
	//if (key == 27)
	//{
		//page = 1;
	//}
	/*if (key == 'g')
	{
		isPoint = true;
		//isStarted = true;
	}
	if (key == 'd')
	{
		isPoint1 = true;

	}
	if (key == 'e')
	{
		isPoint2 = true;
	}
	if (key == 'b')
	{
		isPoint3 = true;
	}
	*/
}
/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if (key == GLUT_KEY_RIGHT)
	{
		if ( xboard <= screenWidth - dxboard)
		{

			xboard += 40;

			bullet_x += 40;
			//bullet_x1 += 30;
			if (!isStarted)
			{
				x_ball += 40;
			
			}
		}
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (xboard >= 0)
		{
			xboard -= 40;
			bullet_x -= 40;
			//bullet_x1-= 30;
			if (!isStarted)
			{
				x_ball -= 40;
			}
		}
	}
	else if (key == GLUT_KEY_HOME)
	{
		if (!isStarted)
		{
			isStarted = true;
		}
	}

	//place your codes for other keys here
}

//int speed1Check = 0;
//int speed2Check = 0;
/*void scoreCheck()
{
	player.score = score;

	saved[4].score = player.score;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (saved[i].score > saved[j].score)
			{
				temp = saved[i];
				saved[i] = saved[j];
				saved[j] = temp;
			}
		}
	}

	fp = fopen("High Scores.txt", "w");

	for (int i = 0; i < 4; i++)
	{
		fprintf(fp , "%s %d\n" , saved[i].name , saved[i].score);
	}
}*/
void ballChange(){


	//if (speed1Check != SPEED1)
	//{
		//speed1Check++;
	//}
		//speed1Check = 0;
		if (isStarted){
			x_ball += dx;
			y_ball += dy;

			if (x_ball >= screenWidth || x_ball <= 0)

				dx *= (-1);

			if (y_ball >= screenHight || y_ball <= 0)

				dy *= (-1);
			//BRICK Collision

			for (int i = 0; i < totalBricks; i++)
			{
				if (bricks[i].show)
				{
					if (x_ball >= bricks[i].x+1.5&&x_ball <= bricks[i].x+1.5 + bricks[i].dx)
					{
						if (y_ball >= bricks[i].y+1.5&&y_ball <= bricks[i].y+1.5 + bricks[i].dy)
						{
							dy *= (-1);
							bricks[i].show = false;
							score += 1;
							if (score == 80){
								page = 5;
							}
							if (musicOn)
								//PlaySound("music\\start.wav", NULL, SND_ASYNC);
								PlaySound("music\\playerhit.wav", NULL, SND_ASYNC);
							
								//scoreCountString[0] = scoreCount + '0';
								/*if (scoreCount == 10)
								continue;*/
								//restartBall();
								//textShow();
					
							
								//scoreCountString[0] = scoreCount + '0';
								/*if (scoreCount == 10)
									continue;*/
								//restartBall();
								//textShow();
							
						}
					}
					else if (y_ball >= bricks[i].y+1.5&&y_ball <= bricks[i].y+1.5 + bricks[i].dy)
					{
						if (x_ball >= bricks[i].x+1.5&&x_ball <= bricks[i].x+1.5 + bricks[i].dx)
						{
							dx *= (-1);
							bricks[i].show = false;
							if (musicOn)
								//PlaySound("music\\start.wav", NULL, SND_ASYNC);
								PlaySound("music\\playerhit.wav", NULL, SND_ASYNC);
							
								score++;
								if (score == 80){
									page = 5;
								}
								//scoreCountString[0] = scoreCount + '0';
								/*if (scoreCount == 10)
									continue;*/
								//restartBall();
								//textShow();
							
						}
					}
				}
			}
			
			if (x_ball >= xboard && x_ball <= xboard + dxboard&&y_ball >= yboard && y_ball <= yboard + dyboard)
			{
				/*
				xboard = 200;
				dxboard = 100;
				x_ball = 150;
				*/

				qeta = (xboard + dxboard - x_ball) + 40;
				dx = (int)v*cos(qeta*PI / 180);
				dy = (int)v*sin(qeta*PI / 180);
				cout << qeta << "\t\t" << dx << "\t\t" << dy << endl;
				//dy *= (-1);
			}
			else
			{
				if (y_ball < yboard)
				{
					if (lifeCount !=0)
					{
						lifeCount--;
					    lifeShow();
						restartBall();
						textShow();
						//lifecount();
					}
					else
					{
						lifeCount = 3;
						gameOverPage();
						gameover();
						//lifeShow();
						//page = 0; /// returning to homemenu /// game over page
					}
				}
			}
		}
	
}

/*void lifecount()
{
	if (y_ball < yboard)
	{
		if (lifeCount != 0){
			lifeCount--;
			iShowBMP(100, 610, "pics\\Life1.bmp");
			iShowBMP(172, 610, "pics\\Life2.bmp");
			iShowBMP(210, 610, "pics\\Life3.bmp");
		}
		else
		{
			lifeCount = 3;
			page = 0; /// returning to homemenu /// game over page
		}
	}
}*/


void displayScore(){

	for (int i = 0; i < totalBricks; i++)
	{
		if (bricks[i].show)
		{
			if (x_ball >= bricks[i].x+1.5&&x_ball <= bricks[i].x+1.5 + bricks[i].dx)
			{
				if (y_ball >= bricks[i].y+1.5&&y_ball <= bricks[i].y+1.5 + bricks[i].dy)
				{
					dy *= (-1);
					bricks[i].show = false;
				}
			}
			else if (y_ball >= bricks[i].y+1.5&&y_ball <= bricks[i].y+1.5 + bricks[i].dy)
			{
				if (x_ball >= bricks[i].x+1.5&&x_ball <= bricks[i].x +1.5+ bricks[i].dx)
				{
					dx *= (-1);
					bricks[i].show = false;
				}
			}
		}
		score++;
		cout << score << endl;
	}

}
void defineBricks()
{
	int sumx = 100;
	int sumy = 400;
	for (int i = 0; i<totalBricks; i++)
	{
		//bricks[i].red = rand() % 255;
		//bricks[i].green = rand() % 255;
		//bricks[i]. blue = rand() % 255;
		bricks[i].x = sumx;
		bricks[i].y = sumy;
		cout << "brick number" << i + 1 << " " << bricks[i].x << bricks[i].y << endl;;
		sumx += 100;
		if (sumx>1000){
			sumx = 100;
			sumy += 20;
		}
	}
}

void restartBall()
{
	 x_ball = (int)screenWidth / 2;
	 y_ball = yAxisMargin;


	 xboard = x_ball - 50;
	 yboard = y_ball -10;

	
	  dx = (int)v*cos(qeta*PI / 180);
	  dy = (int)v*sin(qeta*PI / 180);
	   dxboard = 100;
	   dyboard = 10;
	   bullet_x = xboard + 45;
	   bullet_y = yboard + dyboard;

	   bullet_dx = 10;
	   bullet_dy = 20;
	   //bullet_x1 = xboard + dxboard - 10;
	   //bullet_y1 = yAxisMargin;

	   //bullet_dx1 = 10;
	   //bullet_dy1 = 20;
	   isBullet = false;


	   //bullet_x = x_ball - 50;
	   //bullet_y = y_ball;
	   //bullet_dx = 10;
	   //bullet_dy = 20;
	   //isBullet = false;
	   radius = 10;
	   bullet = 0;
	   //bool isPoint = false;
	   

	 isStarted = false;

}
void bulletMove(){
	//BULLET COLLISION
	if (isBullet){
		bullet_y += 20;
		for (int i = 0; i < totalBricks; i++)
		{
			if (bricks[i].show)
			{
				if (bullet_x >= bricks[i].x&&bullet_x <= bricks[i].x + bricks[i].dx)
				{
					if (bullet_y >= bricks[i].y&&bullet_y <= bricks[i].y + bricks[i].dy)
					{
						bricks[i].show = false;
						score++;
						if (score == 80){
							page = 5;
						}
						if (musicOn)
							//PlaySound("music\\start.wav", NULL, SND_ASYNC);
							PlaySound("music\\playerhit.wav", NULL, SND_ASYNC);
						bullet_x = xboard + 45;
						bullet_y = yboard + dyboard;
						bullet_dx = 10;
						bullet_dy = 20;

						isBullet = false;
					}
				}
				else if (bullet_y >= bricks[i].y&&bullet_y <= bricks[i].y + bricks[i].dy)
				{
					if (bullet_x >= bricks[i].x&&bullet_x <= bricks[i].x + bricks[i].dx)
					{
						bricks[i].show = false;
						score++;
						if (score == 80){
							page = 5;
						}
						if (musicOn)
							//PlaySound("music\\start.wav", NULL, SND_ASYNC);
							PlaySound("music\\playerhit.wav", NULL, SND_ASYNC);
						
						bullet_x = xboard + 45;
						bullet_y = yboard + dyboard;
						bullet_dx = 10;
						bullet_dy = 20;
						isBullet = false;

					}
				}
			}
		}
		if (bullet_y + bullet_dy >= screenHight){
			bullet_x = xboard + 45;
			bullet_y = yboard + dyboard;
			bullet_dx = 10;
			bullet_dy = 20;

			isBullet = false;
		}
	}

}

void callPoint()
{
	int pointNumber = rand() % 5;

	if (point[pointNumber].status == false)
	{
		point[pointNumber].status = true;
	}
}
void lifeShow()
{
	if (lifeCount == 3){
		lifeCount = 3;
		iShowBMP(220, 580, "pics\\live.bmp");
		iShowBMP(170, 580, "pics\\live.bmp");
		iShowBMP(120, 580, "pics\\live.bmp");
	}
	if (lifeCount == 2){
		lifeCount = 2;
		iShowBMP(170, 580, "pics\\live.bmp");
		iShowBMP(120, 580, "pics\\live.bmp");
		
	}
	if (lifeCount == 1){
		lifeCount = 1;
		iShowBMP(120, 580, "pics\\live.bmp");
		
	}


}

void pointUpdate()
{
	for (int i = 0; i < 5; i++)
	{
		if (point[i].status)
		{
			point[i].y -= 20;
			if (point[i].x >= xboard && point[i].x <= xboard + dxboard && point[i].y >= yboard && point[i].y <= yboard + dyboard)
			{
				if (point[i].value == 0)
				{
					point[i].status = false;
					point[i].x = rand() % screenWidth;
					point[i].y = screenHight;
					bullet = 1;
				}
				else if (point[i].value == 1)
				{
					point[i].status = false;
					point[i].x = rand() % screenWidth;
					point[i].y = screenHight;
					dxboard -=40;
					bullet_x -= 20;
					x_ball -= 20;


				}
				else if (point[i].value == 2)
				{
					point[i].status = false;
					point[i].x = rand() % screenWidth;
					point[i].y = screenHight;
					dxboard += 25;
					bullet_x += 12;
					x_ball += 12;
				}
				else if (point[i].value == 3)
				{
					point[i].status = false;
					point[i].x = rand() % screenWidth;
					point[i].y = screenHight;
					radius = 15;
				}
				else if (point[i].value == 4)
				{
					point[i].status = false;
					point[i].x = rand() % screenWidth;
					point[i].y = screenHight;
					radius = 5;
				}
			}
			else if (point[i].y <= 0)
			{
				point[i].status = false;
				point[i].x = rand() % screenWidth;
				point[i].y = screenHight;
			}
		}
	}
}
/*void leve2()
{
	if (score == 80&&lifeCount>1){
		int sumx = 100;
		int sumy = 350;
		for (int i = 0; i<totalBricks; i++)
		{
			bricks[i].red = rand() % 255;
			bricks[i].green = rand() % 255;
			bricks[i].blue = rand() % 255;
			bricks[i].x = sumx;
			bricks[i].y = sumy;
			cout << "brick number" << i + 1 << " " << bricks[i].x << bricks[i].y << endl;;
			sumx += 100;
			if (sumx>1000){
				sumx = 100;
				sumy += 30;
				x_ball = (int)screenWidth / 2;
				y_ball = yAxisMargin;
				xboard = x_ball - 50;
				yboard = y_ball - 10;
				dxboard = 100;
				dyboard = 10;
				radius = 10;
				musicOn = true;

				point_dx1 = 40;
				point_dy1 = 40;

				lifeCount = 3;
				//int scoreCount = 0;
				bullet_x = xboard + 45;
				bullet_y = yboard + dyboard;
				bullet_dx = 10;
				bullet_dy = 20;
				lifeShow;
				bulletMove();
			}
		}
	}
}*/



/*void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(50, 250, 250, 30);
}*/

/*void pointTime()
{
	if (isPoint){
		point_y -= 20;
		if (point_x >= xboard && point_x <= xboard + dxboard&&point_y >= yboard && point_y <= yboard + dyboard)
		{
			 isPoint = false;
			 point_x = screenWidth / 2;
			 point_y = screenHight;
			 point_dx = 30;
			 point_dy = 30;
			 bulletMove();
			isPoint = true;
			isBullet = true;
		}
	}
}*/
/* pointTime1()
{
	if (isPoint1)
	{
		point_y1 -= 20;
		if (point_x1 >= xboard && point_x1 <= xboard + dxboard&&point_y1 >= yboard && point_y1 <= yboard + dyboard)
		{
			isPoint1 = false;
			dxboard -= 40;

			 point_x1 = screenWidth / 4;
			 point_y1 = screenHight;
			 point_dx1 = 30;
			 point_dy1 = 30;
			isPoint1 = true;
		}
		else if (point_y1 < 10)
		{
			point_x1 = screenWidth / 4;
			point_y1 = screenHight;
			point_dx1 = 30;
			point_dy1 = 30;
			isPoint1 = true;
			cout << "point is zero" << endl;
		}
	}
}
void pointTime2()
{
	if (isPoint2){
		point_y2 -= 20;
		if (point_x2 >= xboard && point_x2 <= xboard + dxboard&&point_y2 >= yboard && point_y2 <= yboard + dyboard)
		{
			isPoint2 = false;
			dxboard += 60;

			 point_x2 = screenWidth / 3;
			 point_y2 = screenHight;
			 point_dx2 = 30;
			 point_dy2 = 30;
			isPoint2 = true;
		}
	}
}
void pointTime3()
{
	if (isPoint3){
		point_y3 -= 20;
		if (point_x3 >= xboard && point_x3 <= xboard + dxboard&&point_y3 >= yboard && point_y3 <= yboard + dyboard)
		{
			isPoint3 = false;
			radius = 20;
			 point_x3 = screenWidth / 5;
			 point_y3 = screenHight;
			 point_dx3 = 30;
			 point_dy3 = 30;

			isPoint3 = true;

		}
	}
}*/




void textShow()
{
	iText(350, 350, "RESTART");
}


int main()
{
	//place your own initialization codes here.
	
	/*fp = fopen("High Scores.txt", "r");
	if (fp == NULL)
		fp = fopen("High Scores.txt", "w");
	int i;
	
	while ((fscanf(fp, "%s %d", saved[i].name, &saved[i].score)) != EOF)
		i++;
	
	fclose(fp);
	player.score = 0;*/
	if (musicOn)
		PlaySound("music\\Intense.wav", NULL, SND_ASYNC);
	
	textShow();
	displayScore();
	defineBricks();
	//defineBricks2();
	pointInitialize();
	callPointTimer = iSetTimer(10000, callPoint);
	pointTimer = iSetTimer(100 , pointUpdate);
	iSetTimer(25, ballChange);
	iSetTimer(40, bulletMove);
	

	//iSetTimer(40, pointTime);
	//iSetTimer(40, pointTime1);
	//iSetTimer(40, pointTime2);
	//iSetTimer(40, pointTime3);

	iInitialize(screenWidth,screenHight, "BRICK AND BALL GAME");
	return 0;
}	