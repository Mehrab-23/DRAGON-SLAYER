#include <cmath>  
#include "Hero.h"  
#include "Villain1.h"
#include "Villain2.h"


#include< iostream>

int villainIdleImages[10];  // Idle animation frames  
int villainAttackImages[5]; // Attack animation frames  
int villainCurrentFrame = 0; // Current frame index  
int villainX = 750, villainY = 97;  // Villain's position  
bool isVillainAttacking = false; // Is villain attacking?  
int attackRange = 100;  // Distance at which villain starts attacking  
int villainHP = 100; // Villain starts with 100 HP
int villainHurtImages[3];   // Hurt animation frames
int villainHurtFrame = 0;   // Current hurt frame index
bool isVillainHurt = false; // Flag to check if hurt animation is active
int villainDyingImages[5];   // Dying animation frames
int villainDyingFrame = 0;     // Current dying frame index
bool isVillainDying = false;   // Flag to check if death animation is active
bool villain = true;
bool fightmusic = false;


// Load idle images  
void loadVillainIdleImages() {
	villainIdleImages[0] = iLoadImage("VillainIdle/idleV1.png");
	villainIdleImages[1] = iLoadImage("VillainIdle/idleV2.png");
	villainIdleImages[2] = iLoadImage("VillainIdle/idleV3.png");
	villainIdleImages[3] = iLoadImage("VillainIdle/idleV4.png");
	villainIdleImages[4] = iLoadImage("VillainIdle/idleV5.png");
	villainIdleImages[5] = iLoadImage("VillainIdle/idleV6.png");
	villainIdleImages[6] = iLoadImage("VillainIdle/idleV7.png");
	villainIdleImages[7] = iLoadImage("VillainIdle/idleV8.png");
	villainIdleImages[8] = iLoadImage("VillainIdle/idleV9.png");
	villainIdleImages[9] = iLoadImage("VillainIdle/idleV10.png");
}

// Load attack images  
void loadVillainAttackImages() {
	villainAttackImages[0] = iLoadImage("VillainAttack/AttackV1.png");
	villainAttackImages[1] = iLoadImage("VillainAttack/AttackV2.png");
	villainAttackImages[2] = iLoadImage("VillainAttack/AttackV3.png");
	villainAttackImages[3] = iLoadImage("VillainAttack/AttackV4.png");
	villainAttackImages[4] = iLoadImage("VillainAttack/AttackV5.png");
	
}

void loadVillainHurtImages() {
	villainHurtImages[0] = iLoadImage("VillainHurt/hurt1.png");
	villainHurtImages[1] = iLoadImage("VillainHurt/hurt2.png");
	villainHurtImages[2] = iLoadImage("VillainHurt/hurt3.png");
}

// Function to load villain dying images
void loadVillainDyingImages() {
	villainDyingImages[0] = iLoadImage("VillainDying/die1.png");
	villainDyingImages[1] = iLoadImage("VillainDying/die2.png");
	villainDyingImages[2] = iLoadImage("VillainDying/die3.png");
	villainDyingImages[3] = iLoadImage("VillainDying/die4.png");
	villainDyingImages[4] = iLoadImage("VillainDying/die5.png");
}



void displayVillainHealth() {
	int barWidth = 200, barHeight = 20;
	int x = 750, y = 550; // Top-right position

	// Outline
	iSetColor(255, 255, 255);
	iRectangle(x - 2, y - 2, barWidth + 4, barHeight + 4);

	// Background
	iSetColor(50, 50, 50);
	iFilledRectangle(x, y, barWidth, barHeight);

	// Health (green -> red gradient)
	iSetColor(255 - (villainHP * 2.55), villainHP * 2.55, 0);
	iFilledRectangle(x + (200 - villainHP * 2), y, villainHP * 2, barHeight);
}


// Modify the display function to include dying animation
void displayVillain() {
	if (isVillainDying) {
		// Display dying animation if villain is in death state
		iShowImage(villainX, villainY, 150, 225, villainDyingImages[villainDyingFrame]);
	}
	else if (isVillainHurt) {
		iShowImage(villainX, villainY, 150, 225, villainHurtImages[villainHurtFrame]);
	}
	else if (isVillainAttacking) {
		iShowImage(villainX, villainY, 150, 225, villainAttackImages[villainCurrentFrame]);
	}
	else {
		iShowImage(villainX, villainY, 150, 225, villainIdleImages[villainCurrentFrame]);
	}
	displayVillainHealth();
	if (!fightmusic) {
		PlaySound(TEXT("Music\\fight.wav"), NULL, SND_ASYNC | SND_LOOP);
		fightmusic = true;
	}
}


// Update villain animation  
void updateVillainAnimation() {
	if (isVillainAttacking) {
		villainCurrentFrame++;
		if (villainCurrentFrame >= 5) {
			villainCurrentFrame = 0;
			isVillainAttacking = false; // Return to idle after attack finishes  
		}
	}
	else {
		villainCurrentFrame = (villainCurrentFrame + 1) % 10;
	}
}
void updateVillainHurtAnimation() {
	if (isVillainHurt) {
		villainHurtFrame++;
		if (villainHurtFrame >= 3) {  // Assuming 3 hurt frames
			// End hurt animation after playing all frames
			villainHurtFrame = 0;
			isVillainHurt = false;
		}
	}
}

void updateVillainDyingAnimation() {
	if (isVillainDying) {
		villainDyingFrame++;
		if (villainDyingFrame >= 5) {
			villainDyingFrame = 4; // Freeze on the last dying frame
			villain = false; // Villain disappears from the game
			villain1 = true; // Next villain appears (if applicable)
			//fightmusic = false;
		}
	}
}




// Function to trigger villain's attack and reduce hero's health
void villainAttackHero() {
	// Check if hero is within attack range
	if (abs(heroX - villainX) <= attackRange && villain == true) {  // Horizontal distance check
		heroHP -= 3;  // Reduce hero's health (adjust this value as needed)
		isHurt = true;
		if (heroHP < 0) {
			heroHP = 0;  // Ensure health doesn't go below 0
			showHero = false;
			isVillainAttacking = false;
		}
	}
}
// Villain attack logic  
void villainAttack() {
	isVillainAttacking = true;
	villainCurrentFrame = 0;
	villainAttackHero();
}



// Check if the hero is within attack range  
void checkVillainAttack() {
	int distance = abs(heroX - villainX);
	if (distance <= attackRange && !isVillainAttacking) {
		villainAttack();
	}
}

void checkVillainDeath() {
	if (villainHP <= 0 && !isVillainDying) {
		isVillainDying = true;
		villainDyingFrame = 0;
		isVillainAttacking = false; // Stop attacks when dying
	}
}


// Setup timers for animation and attack checking  
void setupVillainTimers() {
	iSetTimer(150, updateVillainAnimation);
	iSetTimer(500, checkVillainAttack);
	iSetTimer(100, updateVillainHurtAnimation);
	iSetTimer(200, updateVillainDyingAnimation);
}

void attackHero() {
	if (!isAttacking) {  // Prevent attacking if already attacking
		isAttacking = true;
		currentAttackFrame = 0;  // Reset attack frame

		// Check if villain is within attack range
		if (abs(heroX - villainX) <= attackRange && villain == true) {  // Horizontal distance check
			villainHP -= 15;  // Reduce villain's health (adjust as needed)
			if (villainHP < 0) villainHP = 0;  // Ensure health doesn't go below 0

			// Trigger hurt animation for the villain
			isVillainHurt = true;
			villainHurtFrame = 0;

			// **Call the death check here**
			checkVillainDeath();
		}
		if (abs(heroX - villain1X) <= attackRange1 && villain1 == true) {  // Horizontal distance check
			villain1HP -= 15;  // Reduce villain's health (adjust as needed)
			if (villain1HP < 0) villain1HP = 0;  // Ensure health doesn't go below 0

			// Trigger hurt animation for the villain
			isVillain1Hurt = true;
			villain1HurtFrame = 0;

			// **Call the death check here**
			checkVillain1Death();
		}
	}
}
void lavaAttackHero() {
	double distance1 = std::sqrt((double)(((lava1X - heroX)*(lava1X - heroX) + (lava1Y - heroY)*(lava1Y - heroY))));
	double distance2 = std::sqrt((double)(((lava2X - heroX)*(lava2X - heroX) + (lava2Y - heroY)*(lava2Y - heroY))));

	if (distance1 < 100 && villain1)
	{
		heroHP -= 5;
		if (heroHP < 0){
			heroHP = 0;
			showHero = false;
		}
	}
	if (distance2 < 100 && villain1)
	{
		heroHP -= 5;
		if (heroHP < 0){
			heroHP = 0;
			showHero = false;
		}
	}
		
}




