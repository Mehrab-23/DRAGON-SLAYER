int imageIDHomePage;
int startGameChecker = 0;
int controlsPageChecker = 0;
int settingsPageChecker = 0;

void displayHomePage()
{
	imageIDHomePage= iLoadImage("HomePagePictures\\homepage.png");
	iShowImage(0, 0, 1000, 600, imageIDHomePage);
}

void secondSwitch()
{
	homePageChecker = 0;
	startGameChecker = 1;
}
void thirdSwitch()
{
	homePageChecker = 0;
	controlsPageChecker = 1;
}
void forthSwitch()
{
	homePageChecker = 0;
	settingsPageChecker = 1;
}
void playButtonClickSound() {
	PlaySound("Music\\buttonclicksound.wav", NULL, SND_ASYNC);
}
