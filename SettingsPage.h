int imageIDSettingsPage;
void displaySettingsPage()
{
	imageIDSettingsPage = iLoadImage("SettingsPagePictures\\settingspage.png");
	iShowImage(0, 0, 1000, 600, imageIDSettingsPage);
	

	// Draw back button
	drawBackButton();
}