int imageIDIntro; // Variable to load the intro page

int introductionPageChecker = 1; // Variable to execute the button x(if pressed)
int homePageChecker = 0;

int toggle = 0;  // Variable to track the toggle state for blinking effect
clock_t lastTime = 0;  // Variable to track time for blinking effect


// Function to handle the blinking text logic
void displayBlinkingText()
{	
	// Get the current time in milliseconds
	clock_t currentTime = clock();

	// Toggle the visibility of the text every 500 milliseconds
	if ((currentTime - lastTime) / CLOCKS_PER_SEC * 1000 > 500) {
		toggle = !toggle;  // Toggle between 0 and 1
		lastTime = currentTime;  // Update the last time
	}

	if (toggle == 1) {
		// Set the color for the text (you can adjust the RGB values)
		iSetColor(255, 255, 255);  // White text

		// Draw the text at a specific position (e.g., 300, 300)
		iText(750, 20, "Press X to continue", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

// Function to create the introduction page
void displayIntroductionPage()
{
	imageIDIntro = iLoadImage("IntroPictures\\intro.png");
	iShowImage(0, 0, 1000, 600 , imageIDIntro);
	
	// Call the function to display the blinking text
	displayBlinkingText();

}

//// Function to handle the page switching

void firstSwitch()
{
	introductionPageChecker = 0;
	homePageChecker = 1;
}
