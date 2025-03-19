int storyIndex = 0;  // Track the current story page
bool showStory = true;  // Ensure the story sequence runs before gameplay
int storyImages[5];  // Array to store the story image IDs
bool musicPlaying = false;  // Track if music is playing


// Function to load story images
void loadStoryImages() {
	storyImages[0] = iLoadImage("StoryPictures\\story1.png");
	storyImages[1] = iLoadImage("StoryPictures\\story2.png");
	storyImages[2] = iLoadImage("StoryPictures\\story3.png");
	storyImages[3] = iLoadImage("StoryPictures\\story4.png");
	storyImages[4] = iLoadImage("StoryPictures\\story5.png");
}

void playStoryMusic() {
	if (!musicPlaying) {
		PlaySound(TEXT("Music\\storymusic.wav"), NULL, SND_ASYNC | SND_LOOP);
		musicPlaying = true;
	}
}
void stopStoryMusic() {
	PlaySound(NULL, 0, 0);
	musicPlaying = false;
}

// Function to display the current story image
void displayStory() {

	if (!musicPlaying) {
		playStoryMusic();  // Start music when the story begins
	}

	// Draw the current story image
	iShowImage(0, 0, 1000, 600, storyImages[storyIndex]);
}


// Function to proceed to the next story image
void nextStoryPart() {
	if (storyIndex < 4) {
		storyIndex++;  // Move to the next image
	}
	else {
		showStory = false;  // End story and start gameplay
		stopStoryMusic();
	}
}


