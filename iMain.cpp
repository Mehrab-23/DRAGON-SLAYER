#include "iGraphics.h"
#include "Intro.h"
#include "HomePage.h"
#include "StartGame.h"
#include "ControlsPage.h"
#include "SettingsPage.h"
#include "Exit.h"
#include "Story.h"
#include "windows.h"
//include "Hero.h"
//include"Villain.h"
#include <mmsystem.h> // Multimedia functions
#pragma comment(lib, "winmm.lib")  // Link Windows multimedia library
#include<stdio.h>
#include<time.h>
//#include "Villain2.h"
bool isBackButtonHovered = false;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://


void goBack()
{
	if (controlsPageChecker)
	{
		controlsPageChecker = 0;
		homePageChecker = 1;
	}
	else if (settingsPageChecker)
	{
		settingsPageChecker = 0;
		homePageChecker = 1;
	}
	else if (startGameChecker)
	{
		startGameChecker = 0;
		homePageChecker = 1;
	}
}


void iDraw()
{
	iClear();

	if (introductionPageChecker == 1)
	{
		displayIntroductionPage();
	}
	else if (homePageChecker == 1)
	{
		displayHomePage();
	}
	else if (startGameChecker == 1)
	{
		if (showStory) {
			displayStory();  // Show story with fade-in effect and music
		}
		else
		{
			displayStartGame();
		}
	}
	else if (controlsPageChecker == 1)
	{
		displayControlsPage();
	}
	else if (settingsPageChecker == 1)
	{
		displaySettingsPage();
	}

	villainMoving();
	updateVillain1DyingAnimation();
	lavaPortese();
	updateLava();
	lavaAttackHero();
}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	int backX = 900, backY = 0, backWidth = 100, backHeight = 40;

	// Check if cursor is over the back button
	if (mx >= backX && mx <= backX + backWidth && my >= backY && my <= backY + backHeight)
	{
		isBackButtonHovered = true;
	}
	else
	{
		isBackButtonHovered = false;
	}
}


void iMouse(int button, int state, int mx, int my)
{
	printf("%d %d ", mx, my);

	// Back button coordinates
	int backX = 900, backY = 0, backWidth = 100, backHeight = 40;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (!startGameChecker) { // Ensure the back button does not work during gameplay
			if (mx >= backX && mx <= backX + backWidth && my >= backY && my <= backY + backHeight)
			{
				playButtonClickSound(); // Click sound effect
				goBack(); // Function to handle back button action
			}
		}

		if (mx >= 28 && mx <= 225 && my >= 193 && my <= 298)
		{
			playButtonClickSound();
			secondSwitch();
		}
		else if (mx >= 291 && mx <= 486 && my >= 194 && my <= 301)
		{
			playButtonClickSound();
			thirdSwitch();
		}
		else if (mx >= 536 && mx <= 733 && my >= 191 && my <= 297)
		{
			playButtonClickSound();
			forthSwitch();
		}
		else if (mx >= 783 && mx <= 980 && my >= 195 && my <= 301)
		{
			playButtonClickSound();
			exitGame();
		}
	}

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{

	if (key == 'x' || key == 'X')
	{
		firstSwitch();
	}
	if (showStory) {
		if (key == '\r') {  // Press Enter to move to the next story image
			nextStoryPart();
		}
		else if (key == 's' || key == 'S') {  // Press S to skip the story
			showStory = false;
			stopStoryMusic();
		}
	}

	if (key == 'd' || key == 'D') {  // Move right
		moveHeroForward();
	}
	else if (key == 'a' || key == 'A') {  // Move left
		moveHeroBackward();
	}
	else if (key == ' ') {  // Space bar is pressed
		attackHero();
	}
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

	if (key == GLUT_KEY_HOME)
	{

	}
	if (key == GLUT_KEY_RIGHT) {

	}
	if (key == GLUT_KEY_LEFT) {

	}

}


int main()
{


	///srand((unsigned)time(NULL));
	iInitialize(1000, 600, "Project Title");
	///updated see the documentations
	loadStoryImages();
	loadHeroIdleImages();
	loadHeroRunImages();
	loadHeroAttackImages();
	loadVillainIdleImages();
	loadVillainAttackImages();
	loadVillainHurtImages();
	loadVillainDyingImages();
	loadHeroHurtImages();
	loadVillain1IdleImages();
	loadVillain1AttackImages();
	loadVillain1HurtImages();
	loadVillain1DyingImages();
	loadVillainWalkImages();

	setupAnimationTimer();
	setupVillainTimers();
	setupVillain1Timers();



	iStart();
	return 0;
}