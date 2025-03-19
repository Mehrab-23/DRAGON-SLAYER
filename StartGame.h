#include"Villain.h"
int imageIDBackGround;
int imageGameOver;
int imageVictory;
extern bool isBackButtonHovered;
void drawBackButton()
{
	// Draw the "Back" button
	int backX = 900, backY = 0, backWidth = 100, backHeight = 40;
	if (isBackButtonHovered)
	{
		iSetColor(255, 255, 0); // Glowing yellow color when hovered
		iText(backX, backY + 10, "Back", GLUT_BITMAP_HELVETICA_18);
	}
	else
	{
		iSetColor(255, 255, 255); // Normal white color
		iText(backX, backY + 10, "Back", GLUT_BITMAP_HELVETICA_18);
	}

}




// Function to display the game scene
void displayStartGame() {
	imageIDBackGround = iLoadImage("StartGamePictures\\background.png");
	imageGameOver = iLoadImage("StartGamePictures\\gameover.png");
	imageVictory = iLoadImage("StartGamePictures\\victory.png");
	iShowImage(0, 0, 1000, 600, imageIDBackGround);
	if (showHero)
	{
		displayHero();
	}
	else
	{
		villain = false;
		villain1 = false;
		iShowImage(0, 0, 1000, 600, imageGameOver);
	}
	if (villain == true)
	{
		displayVillain();
	}
	else if (villain1 == true){

		displayVillain1();
	}
	if (isDead)
	{
		fightmusic2 = false;
		iShowImage(0, 0, 1000, 600, imageVictory);
		
		
	}
	else if (!showHero)
	{
		fightmusic2 = false;
		iShowImage(0, 0, 1000, 600, imageGameOver);
	}
	

}







	