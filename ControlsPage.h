int imageIDControlsPage;
void displayControlsPage()
{
	imageIDControlsPage = iLoadImage("ControlsPagePictures\\controlspage.png");
	iShowImage(0, 0, 1000, 600, imageIDControlsPage);
	
	// Draw back button
	drawBackButton();
}
