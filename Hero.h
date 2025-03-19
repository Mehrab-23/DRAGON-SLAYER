int heroIdleImages[10];  // Idle animation frames
int heroForwardRunImages[16];   // Forward movement animation frames
int heroBackwardRunImages[16];  // Backward movement animation frames
int heroAttackImages[7];  // Attack animation frames
int currentIdleFrame = 0;  // Idle animation index
int currentRunFrame = 0;   // Running animation index
int currentAttackFrame = 0; // Attack animation index
bool isRunning = false;   // Check if hero is moving
bool isMoving = false;    // Track if a movement key is pressed
bool isMovingForward = true;  // Track the direction of movement (true = forward, false = backward)
bool isAttacking = false; // Check if hero is attacking
int heroX = 50, heroY = 65;  // Hero position
int heroHP = 100; // Hero starts with 100 HP
int heroHurtImages[4];  // Hurt animation frames
int currentHurtFrame = 0; // Hurt animation index
bool isHurt = false; // Track if hero is hurt
bool showHero = true;


void loadHeroHurtImages() {
	heroHurtImages[0] = iLoadImage("HeroHurt/HURT1.png");
	heroHurtImages[1] = iLoadImage("HeroHurt/HURT2.png");
	heroHurtImages[2] = iLoadImage("HeroHurt/HURT3.png");
	heroHurtImages[3] = iLoadImage("HeroHurt/HURT4.png");
}


// Function to load hero idle images
void loadHeroIdleImages() {
	heroIdleImages[0] = iLoadImage("HeroIdle/IDLE1.png");
	heroIdleImages[1] = iLoadImage("HeroIdle/IDLE2.png");
	heroIdleImages[2] = iLoadImage("HeroIdle/IDLE3.png");
	heroIdleImages[3] = iLoadImage("HeroIdle/IDLE4.png");
	heroIdleImages[4] = iLoadImage("HeroIdle/IDLE5.png");
	heroIdleImages[5] = iLoadImage("HeroIdle/IDLE6.png");
	heroIdleImages[6] = iLoadImage("HeroIdle/IDLE7.png");
	heroIdleImages[7] = iLoadImage("HeroIdle/IDLE8.png");
	heroIdleImages[8] = iLoadImage("HeroIdle/IDLE9.png");
	heroIdleImages[9] = iLoadImage("HeroIdle/IDLE10.png");
}

// Function to load hero running images (forward and backward)
void loadHeroRunImages() {
	// Load forward movement images (first 16)
	heroForwardRunImages[0] = iLoadImage("HeroRun/RUN1.png");
	heroForwardRunImages[1] = iLoadImage("HeroRun/RUN2.png");
	heroForwardRunImages[2] = iLoadImage("HeroRun/RUN3.png");
	heroForwardRunImages[3] = iLoadImage("HeroRun/RUN4.png");
	heroForwardRunImages[4] = iLoadImage("HeroRun/RUN5.png");
	heroForwardRunImages[5] = iLoadImage("HeroRun/RUN6.png");
	heroForwardRunImages[6] = iLoadImage("HeroRun/RUN7.png");
	heroForwardRunImages[7] = iLoadImage("HeroRun/RUN8.png");
	heroForwardRunImages[8] = iLoadImage("HeroRun/RUN9.png");
	heroForwardRunImages[9] = iLoadImage("HeroRun/RUN10.png");
	heroForwardRunImages[10] = iLoadImage("HeroRun/RUN11.png");
	heroForwardRunImages[11] = iLoadImage("HeroRun/RUN12.png");
	heroForwardRunImages[12] = iLoadImage("HeroRun/RUN13.png");
	heroForwardRunImages[13] = iLoadImage("HeroRun/RUN14.png");
	heroForwardRunImages[14] = iLoadImage("HeroRun/RUN15.png");
	heroForwardRunImages[15] = iLoadImage("HeroRun/RUN16.png");

	// Load backward movement images (last 16)
	heroBackwardRunImages[0] = iLoadImage("HeroRun/RUN17.png");
	heroBackwardRunImages[1] = iLoadImage("HeroRun/RUN18.png");
	heroBackwardRunImages[2] = iLoadImage("HeroRun/RUN19.png");
	heroBackwardRunImages[3] = iLoadImage("HeroRun/RUN20.png");
	heroBackwardRunImages[4] = iLoadImage("HeroRun/RUN21.png");
	heroBackwardRunImages[5] = iLoadImage("HeroRun/RUN22.png");
	heroBackwardRunImages[6] = iLoadImage("HeroRun/RUN23.png");
	heroBackwardRunImages[7] = iLoadImage("HeroRun/RUN24.png");
	heroBackwardRunImages[8] = iLoadImage("HeroRun/RUN25.png");
	heroBackwardRunImages[9] = iLoadImage("HeroRun/RUN26.png");
	heroBackwardRunImages[10] = iLoadImage("HeroRun/RUN27.png");
	heroBackwardRunImages[11] = iLoadImage("HeroRun/RUN28.png");
	heroBackwardRunImages[12] = iLoadImage("HeroRun/RUN29.png");
	heroBackwardRunImages[13] = iLoadImage("HeroRun/RUN30.png");
	heroBackwardRunImages[14] = iLoadImage("HeroRun/RUN31.png");
	heroBackwardRunImages[15] = iLoadImage("HeroRun/RUN32.png");
}

// Function to load hero attack images
void loadHeroAttackImages() {
	heroAttackImages[0] = iLoadImage("HeroAttack/ATTACK1.png");
	heroAttackImages[1] = iLoadImage("HeroAttack/ATTACK2.png");
	heroAttackImages[2] = iLoadImage("HeroAttack/ATTACK3.png");
	heroAttackImages[3] = iLoadImage("HeroAttack/ATTACK4.png");
	heroAttackImages[4] = iLoadImage("HeroAttack/ATTACK5.png");
	heroAttackImages[5] = iLoadImage("HeroAttack/ATTACK6.png");
	heroAttackImages[6] = iLoadImage("HeroAttack/ATTACK7.png");
}

void displayHeroHealth() {
	int barWidth = 200, barHeight = 20; // Health bar size
	int x = 50, y = 550; // Top-left position

	// Outline
	iSetColor(255, 255, 255);
	iRectangle(x - 2, y - 2, barWidth + 4, barHeight + 4);

	// Background
	iSetColor(50, 50, 50);
	iFilledRectangle(x, y, barWidth, barHeight);

	// Health (green -> red gradient effect)
	iSetColor(255 - (heroHP * 2.55), heroHP * 2.55, 0);
	iFilledRectangle(x, y, heroHP * 2, barHeight);
}


void displayHero() {
	if (isHurt) {  // If hero is hurt, show hurt animation
		iShowImage(heroX, heroY, 150, 225, heroHurtImages[currentHurtFrame]);
	}
	else if (isAttacking) {
		iShowImage(heroX, heroY, 150, 225, heroAttackImages[currentAttackFrame]);
	}
	else if (isRunning) {
		if (isMovingForward) {
			iShowImage(heroX, heroY, 150, 225, heroForwardRunImages[currentRunFrame]);
		}
		else {
			iShowImage(heroX, heroY, 150, 225, heroBackwardRunImages[currentRunFrame]);
		}
	}
	else {
		iShowImage(heroX, heroY, 150, 225, heroIdleImages[currentIdleFrame]);
	}
	displayHeroHealth();
}


// Function to update animation frames
void updateHeroAnimation() {
	if (isAttacking) {
		currentAttackFrame = (currentAttackFrame + 1) % 7;  // Loop through attack frames
		if (currentAttackFrame == 0) {
			isAttacking = false;  // Stop attacking after the last frame
		}
	}
	else if (isRunning) {
		currentRunFrame = (currentRunFrame + 1) % 16;  // Loop through running frames
	}
	else {
		currentIdleFrame = (currentIdleFrame + 1) % 10;  // Loop through idle frames
	}
}


// Function to move hero forward
void moveHeroForward() {
	if (heroX < 700) {  // Prevent going off-screen
		heroX += 10;
		isRunning = true;
		isMoving = true;
		isMovingForward = true;  // Set flag for forward movement
	}
}

// Function to move hero backward
void moveHeroBackward() {
	if (heroX > 0) {  // Prevent going off-screen
		heroX -= 10;
		isRunning = true;
		isMoving = true;
		isMovingForward = false;  // Set flag for backward movement
	}
}

void updateHeroMovement() {
	if (!isMoving) {  // If no movement key is pressed, stop running
		isRunning = false;
		currentRunFrame = 0;  // Reset running animation frame
	}
	isMoving = false;  // Reset movement flag for the next frame
}
void updateHeroHurtAnimation() {
	if (isHurt) {
		currentHurtFrame = (currentHurtFrame + 1) % 4;
		if (currentHurtFrame == 0) {
			isHurt = false; // Stop hurt animation after one cycle
		}
	}
}





// Call this function in your main file to set a timer for animation updates
void setupAnimationTimer() {
	iSetTimer(100, updateHeroAnimation);
	iSetTimer(100, updateHeroMovement);
	iSetTimer(100, updateHeroHurtAnimation);
}