#include <cmath>  
bool villain1 = false;
int villain1IdleImages[10];  // Idle animation frames  
int villain1CurrentFrame = 0; // Current frame index  
int villain1X = 750, villain1Y = 97;  // Villain's position  
int villain1HP = 100; // Villain starts with 100 HP
bool isVillain1Attacking = false; // Is villain attacking?  
int villain1AttackImages[5]; // Attack animation frames  
int attackRange1 = 100;  // Distance at which villain starts attacking  
int x = 1;
int villain1HurtImages[3];   // Hurt animation frames
int villain1HurtFrame = 0;   // Current hurt frame index
bool isVillain1Hurt = false; // Flag to check if hurt animation is active
int villain1DyingImages[5];   // Dying animation frames
int villain1DyingFrame = 0;     // Current dying frame index
bool isVillain1Dying = false;   // Flag to check if death animation is active
int villainWalkImages[12];
int villainWalkFrame = 0;
bool isVillainWalk = false;
bool fightmusic2 = false;

bool isDead = false;
bool villain2 = false;

void loadVillainWalkImages() {
	villainWalkImages[0] = iLoadImage("VillainWalk/Walk_Frame_1.png");
	villainWalkImages[1] = iLoadImage("VillainWalk/Walk_Frame_2.png");
	villainWalkImages[2] = iLoadImage("VillainWalk/Walk_Frame_3.png");
	villainWalkImages[3] = iLoadImage("VillainWalk/Walk_Frame_4.png");
	villainWalkImages[4] = iLoadImage("VillainWalk/Walk_Frame_5.png");
	villainWalkImages[5] = iLoadImage("VillainWalk/Walk_Frame_6.png");
	villainWalkImages[6] = iLoadImage("VillainWalk/Walk_Frame_7.png");
	villainWalkImages[7] = iLoadImage("VillainWalk/Walk_Frame_8.png");
	villainWalkImages[8] = iLoadImage("VillainWalk/Walk_Frame_9.png");
	villainWalkImages[9] = iLoadImage("VillainWalk/Walk_Frame_10.png");
	villainWalkImages[10] = iLoadImage("VillainWalk/Walk_Frame_11.png");
	villainWalkImages[11] = iLoadImage("VillainWalk/Walk_Frame_12.png");
}


void displayVillain1Health() {
	if (!isDead){
		int barWidth = 200, barHeight = 20;
		int x = 750, y = 550; // Top-right position

		// Outline
		iSetColor(255, 255, 255);
		iRectangle(x - 2, y - 2, barWidth + 4, barHeight + 4);

		// Background
		iSetColor(50, 50, 50);
		iFilledRectangle(x, y, barWidth, barHeight);

		// Health (green -> red gradient)
		iSetColor(255 - (villain1HP * 2.55), villain1HP * 2.55, 0);
		iFilledRectangle(x + (200 - villain1HP * 2), y, villain1HP * 2, barHeight);
	}
}




void loadVillain1IdleImages() {
	villain1IdleImages[0] = iLoadImage("Villain1Idle/Vidle1.png");
	villain1IdleImages[1] = iLoadImage("Villain1Idle/Vidle2.png");
	villain1IdleImages[2] = iLoadImage("Villain1Idle/Vidle3.png");
	villain1IdleImages[3] = iLoadImage("Villain1Idle/Vidle4.png");
	villain1IdleImages[4] = iLoadImage("Villain1Idle/Vidle5.png");
	villain1IdleImages[5] = iLoadImage("Villain1Idle/Vidle6.png");
	villain1IdleImages[6] = iLoadImage("Villain1Idle/Vidle7.png");
	villain1IdleImages[7] = iLoadImage("Villain1Idle/Vidle8.png");
	villain1IdleImages[8] = iLoadImage("Villain1Idle/Vidle9.png");
	villain1IdleImages[9] = iLoadImage("Villain1Idle/Vidle10.png");
}



void loadVillain1AttackImages() {
	villain1AttackImages[0] = iLoadImage("Villain1Attack/1AttackV1.png");
	villain1AttackImages[1] = iLoadImage("Villain1Attack/1AttackV2.png");
	villain1AttackImages[2] = iLoadImage("Villain1Attack/1AttackV3.png");
	villain1AttackImages[3] = iLoadImage("Villain1Attack/1AttackV4.png");
	villain1AttackImages[4] = iLoadImage("Villain1Attack/1AttackV5.png");

}

void loadVillain1HurtImages() {
	villain1HurtImages[0] = iLoadImage("Villain1Hurt/1hurt1.png");
	villain1HurtImages[1] = iLoadImage("Villain1Hurt/1hurt2.png");
	villain1HurtImages[2] = iLoadImage("Villain1Hurt/1hurt3.png");
}
// Function to load villain dying images
void loadVillain1DyingImages() {
	villain1DyingImages[0] = iLoadImage("Villain1Dying/1die1.png");
	villain1DyingImages[1] = iLoadImage("Villain1Dying/1die2.png");
	villain1DyingImages[2] = iLoadImage("Villain1Dying/1die3.png");
	villain1DyingImages[3] = iLoadImage("Villain1Dying/1die4.png");
	villain1DyingImages[4] = iLoadImage("Villain1Dying/1die5.png");
}







void displayVillain1(){
	if (!isDead){
		if (isVillain1Dying) {
			iShowImage(villain1X, villain1Y, 150, 225, villain1DyingImages[villain1DyingFrame]);
		}

		else if (isVillain1Hurt) {
			iShowImage(villain1X, villain1Y, 150, 225, villain1HurtImages[villain1HurtFrame]);
		}
		else if (isVillain1Attacking) {
			iShowImage(villain1X, villain1Y, 150, 225, villain1AttackImages[villain1CurrentFrame]);
		}
		else if (isVillainWalk) {
			iShowImage(villain1X, villain1Y, 150, 225, villainWalkImages[villainWalkFrame]);
		}
		else {
			iShowImage(villain1X, villain1Y, 150, 225, villain1IdleImages[villain1CurrentFrame]);
		}
	}
	displayVillain1Health();
	if (!fightmusic2) {
		PlaySound(TEXT("Music\\fight.wav"), NULL, SND_ASYNC | SND_LOOP);
		fightmusic2 = true;
	}

}


// Update villain animation  
void updateVillain1Animation() {
	if (isVillain1Attacking) {
		villain1CurrentFrame++;
		if (villain1CurrentFrame >= 5) {
			villain1CurrentFrame = 0;
			isVillain1Attacking = false; // Return to idle after attack finishes  
		}
	}
	else {
		villain1CurrentFrame = (villain1CurrentFrame + 1) % 10;
	}
}



void villain1AttackHero() {
	// Check if hero is within attack range
	if (abs(heroX - villain1X) <= attackRange1 && villain1 == true && x == 1) {  // Horizontal distance check
		heroHP -= 5;  // Reduce hero's health (adjust this value as needed)
		isHurt = true;
		if (heroHP < 0) {
			heroHP = 0;  // Ensure health doesn't go below 0
			showHero = false;
			isVillain1Attacking = false;
		}
	}
}

// Villain attack logic  
void villain1Attack() {
	isVillain1Attacking = true;
	villain1CurrentFrame = 0;
	villain1AttackHero();
}

void checkVillain1Attack() {
	int distance = abs(heroX - villain1X);
	if (distance <= attackRange1 && !isVillain1Attacking) {
		villain1Attack();
	}
}


void updateVillain1HurtAnimation() {
	if (isVillain1Hurt) {
		villain1HurtFrame++;
		if (villain1HurtFrame >= 3) {  // Assuming 3 hurt frames
			// End hurt animation after playing all frames
			villain1HurtFrame = 0;
			isVillain1Hurt = false;
		}
	}
}

void updateVillainWalkAnimation() {
	if (isVillainWalk) {
		villainWalkFrame++;
		if (villainWalkFrame >= 12) {  // Assuming 3 hurt frames
			// End hurt animation after playing all frames
			villainWalkFrame = 0;
			isVillainWalk = false;
		}
	}
}



void checkVillain1Death() {
	if (villain1HP <= 0 && !isVillain1Dying) {
		isVillain1Dying = true;
		villain1DyingFrame = 0;
		x = 0;
		villain1 = false;
		// Optionally, disable other actions here (e.g., stop attacking, movement, etc.)
	}
}

void updateVillain1DyingAnimation() {
	if (isVillain1Dying) {
		villain1DyingFrame++;
		if (villain1DyingFrame >= 5) {
			villain1 = false;
			isDead = true;
			villain2 = true;
		}
	}
}

void villainMoving(){
	if (!isDead){
		if (heroX < villain1X && villain1X - heroX < 200){
			villain1X-=5;
			isVillainWalk = true;
		}
		else if (heroX > villain1X &&  heroX - villain1X < 200){
			villain1X+=5;
			isVillainWalk = true;
		}
	}
}






void setupVillain1Timers() {
	iSetTimer(150, updateVillain1Animation);
	iSetTimer(500, checkVillain1Attack);
	iSetTimer(100, updateVillain1HurtAnimation);
	iSetTimer(200, updateVillain1DyingAnimation);
	iSetTimer(200, updateVillainWalkAnimation);
}