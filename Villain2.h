
extern bool villain2;
extern bool isHurt;

int lava1X = rand()%1000;
int lava1Y = 500;

int lava2X = rand()%1000;
int lava2Y = 400;

extern int heroHP;

void lavaPortese(){
	if (villain1){
		iShowBMP2(lava1X, lava1Y, "lava.bmp",0);
		iShowBMP2(lava2X, lava2Y, "lava.bmp", 0);

	}
}

void updateLava(){
	lava1Y-=5;
	lava2Y-=5;
	
	if (lava1Y < 90){
		lava1Y = 500;
		lava1X = rand() % 1000;
	}
	if (lava2Y < 90){
		lava2Y = 400;
		lava2X = rand() % 1000;
	}

}
