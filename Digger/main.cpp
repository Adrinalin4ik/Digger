#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <math.h>
using namespace sf;


float offsetX=64, offsetY=64;
bool inHouse=false;
bool T=false;
const int H = 56;
const int W = 119;

String TileInsideHouse[H]={
"00000000000000000                                                                                                     ",
" H000000000000000                                                                                                     ",
"  000000000000000                                                                                                     ",
"  000000000ff0000                                                                                                     ",
"  0 00000    0000                                                                                                     ",
"  0  00        00                                                                                                     ",
"  0             0                                                                                                     ",
"  0        0    0                                                                                                     ",
"  00            0                                                                                                     ",
"  00           00                                                                                                     ",
"  000         000                                                                                                     ",
"000000  000000000                                                                                                     ",
"00000ttt000000000                                                                                                     ",
"     000                                                                                                              ",
"                                                                                                                      ",
"                                                                                                                      ",
"                                                                                                                      ",
"                                                                                                                      ",
"                                                                                                                      ",
"                                                                                                                      ",
"                                                                                                                      ",
"                                                                                                                      ",
"                                                                                                                      ",
"                                                                                                                      ",
"                                                                                                                      ",
"                                                                                                                      ",
};
String TileFloor[H]={
"r      														                                               ",
"	                                                                                                           ",
"															                                                   ",
"																                                               ",
"                                   JJJ                                                                        ",
"                                  JJJJJ                                                                       ",
"                                 JJJJJJ                                                                       ", 
"                                 JJJJJJJ                                                                      ",
"                                JJJJJJJJ                                                                      ",
"                                JJJJJJJJJ                                                                     ",
"                               JJJJJJJJJJJ                                                                    ",
"                               JJJJJJJJJJJ                                                                    ",
"                              JJJJJJJJJJJ                                                                     ",
"                              JJJJJJJJJJJ                                                                     ",
"                              JJJJJJJJJJ                                                                      ",
"                             JJJJJJJJJJJ                                                                      ",
"                             JJJJJJJJJJJJ                                                                     ",
"                             JJJJJJJJJJJJ                                                                     ",
"                              JJJJJJJJJJ                                                                      ",
"                              JJJJJJJJJ                                                                       ",
"                           JJJJJJJJJJJJ                                                                       ",
"                          JJJJJJJJJJJJJ                                                                       ",
"                          JJJJJJJJJJJJJ   JJ                                                                  ",
"                          JJJJJJJJJJJJJJJJJJ                                                                  ",
"                          JJJJJJJJJJJJJJJJJJ                                                                  ",
"                        JJJJJJJJJJJJJJJJJJJJJ                                                                 ",
"                       JJJJJJJJJJJJJJJJJJJJJJ                                                                 ",
"                       JJJJJJJJJJJJJJJJJJJJJJ                                                                 ",
"                      JJJJJJJJJJJJJJJJJJJJJJJ                                                                 ",
"                      JJJJJJJJJJJJJJJJJJJJJJJ                                                                 ",
"                      JJJJJJJJJJJJJJJJJJJJJJ                                                                  ",
"                       JJJJJJJJJJJJJJJJJJJJ                                                                   ",
"                        JJJJJJJJJJJJJJJJJJJ                                                                   ",
"                        JJJJJJJJJJJJJJJJJJJ                                                                   ",
"                          JJJJJJJJJJJJJJJJJ                                                                   ",
"                          JJJJJJJJJJJJJJJJJ                                                                   ",
"                            JJJJJJJJJJJJJJJ                                                                   ",
"                            JJJJJJJJJJJJJJJ                                                                   ",
"                            JJJJJJJJJJJJJJJ                                                                   ",
"                                JJJJJJJJJJJJ                                                                  ",
"                                     JJJJJJJ                                                                  ",
"                                     JJJJJJJJ                                                                 ",
"                                     JJJJJJJJJ                                                                ",
"                                     JJJJJJJJJ                                                                ",
"                                       JJJJJJJJJJJJ                                                           ",
"                                       JJJJJJJJJJJJ                                                           ",
"                                          JJJJJJJJJJJJJJJJJ                                                   ",
"                                                JJJJJJJJJJJJ                                                  ",
"                                                 JJJJJJJJJJJ                                                  ",
"                                                  JJJJJJJJJJ                                                  ",
"                                                           J                                                  ",
"                                                           J                                                  ",
"																                                               ",
"															                                                   ",
"																                                               ",
};

String TileMap[H] = {
"P P P P P P P P P P P P P P P P P P P P P P P P P P P P P P P                                                 ",
"PP P P P P P P P P P P P P P P0P000000000P P P P P P P P P P P                                                ",
"p P P P P P P P P P P P P P P P00       0   P P P P P P P P P                                                 ",
"P0000000000000000000000000000000        0000000000000000000000                                                ",
"PP0   wwldlwtt00p0                 JJJ          P 0P P    P p0                                                ",
"0P0     wll0  00p0                JJJJJ         0  0 0P     p0                                                ",
"PP0      www  ppp0               JJJJJJ               0     p0                                                ", 
"0P0           0000 h             JJJJJJJ               0P P p0                                                ",
"PP0KK         pl0p0             JJJJJJJJ                0  Pp0                                                ",
"0P0KK    pvpvpvP0p0             JJJJJJJJJ                0P p0                                                ",
"PP0KK    0p0p0p0p00            JJJJJJJJJJJ                0 p0                                                ",
"0P0      p00000000             JJJJJJJJJJJ       h          p0                                                ",
"PP0    b p   ww ew            JJJJJJJJJJJ l                 p0                                                ",
"0P0      p                    JJJJJJJJJJJ  l            l   p0                                                ",
"PP0     pp0  k       P        JJJJJJJJJJ  l         l  l  h p0                                                ",
"0P0    p p0 e P P P P P      JJJJJJJJJJJ                l   p0                                                ",
"PP0    0000P P P P P P       JJJJJJJJJJJ l l         l      p0                                                ",
"0P0     p 0000000000000      JJJJJJJJJJJJ              h l  p0                                                ",
"PP0     0l l                 EJJJJJJJJJJ  l           l l   p0                                                ",
"0P0       l  e              EEJJJJJJJJJ l                   p0                                                ",
"PP0     e    b             JJJJJJJJJJJJ                     p0                                                ",
"0P0                       JJJJJJJJJJJJJ  k                  p0                                                ",
"PP0                       JJJJJJJJJJJJJ   JJ                p0                                                ",
"0P0                       JJJJJJJJJJJJJJJJJJE               p0                                                ",
"PP0       l  l           bJJJJJJJJJJJJJJJJJJEE              p0                                                ",
"0P0         0           JJJJJJJJJJJJJJJJJJJJJEE             p0                                                ",
"PP0        l0l         JJJJJJJJJJJJJJJJJJJJJJE              p0                                                ",
"0P0         0 p  h     JJJJJJJJJJJJJJJJJJJJJJ               p0                                                ",
"PP0         l 0 p     JJJJJJJJJJJJJJJJJJJJJJJ         h     p0                                                ",
"0P0           l 0 p  EJJJJJJJJJJJJJJJJJJJJJJJE              p0                                                ",
"PP0             l 0 pEJJJJJJJJJJJJJJJJJJJJJJE               p0                                                ",
"0P0              l  0EEJJJJJJJJJJJJJJJJJJJJEE               p0                                                ",
"PP0               l  EEEJJJJJJJJJJJJJJJJJJJE                p0                                                ",
"0P0h                k EEJJJJJJJJJJJJJJJJJJJ                 p0                                                ",
"PP0                    EEhJJJJJJJJJJJJJJJJJ                 p0                                                ",
"0P0                       JJJJJJJJJJJJJJJJJ                 p0                                                ",
"PP0                      p  JJJJJJJJJJJJJJJ                 p0                                                ",
"0P0                      0p JJJJJJJJJJJJJJJ            l    p0                                                ",
"PP0                      p0 JJJJJJJJJJJJJJJE        l       p0                                                ",
"0P0                      0p  p  JJJJJJJJJJJJE            l  p0                                                ",
"PP0                       0p 0p p p  JJJJJJJEE    l         p0                                                ",
"0P0    l                  p0 p0p0p0p JJJJJJJJEE       h     p0                                                ",
"PP0                      e0  0 0 0 0 JJJJJJJJJE    l        p0                                                ",
"0P0      l   l            p0p 0p0p0  JJJJJJJJJEE     l  l   p0                                                ",
"PP0   l        l          0 0ee0e0p p  JJJJJJJJJJJJ         p0                                                ",
"0P0    l q   l                 ee 0p0p JJJJJJJJJJJJ         p0                                                ",
"PP0  l   000  e                  e 0p0    JJJJJJJJJJJJJJJJJ p0                                                ",
"0P0    l    l e                     0           JJJJJJJJJJJJp0                                                ",
"PP0  l  l   l a                                  JJJJJJJJJJJp0                                                ",
"0P0           h                              h    JJJJJJJJJJp0                                                ",
"PP0                                                        Jp0                                                ",
"0P0                                                        Jp0                                                ",
"0Pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp0                                                ",
"PPpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvpvv0                                                ",
"00000000000000000000000000000000000000000000000000000000000000                                                ",
}; 
class Texture_3{
public:
	Texture texture;
	Sprite sprite;
    FloatRect rect;
	float currentFrame;
	float speed;
	int frame_count;
	Texture_3(Texture &image,int rect_l,int rect_t,int rect_w,int rect_h,int frame_num){
	sprite.setTexture(image);
	rect = FloatRect(rect_l,rect_t,rect_w,rect_h);
	currentFrame = 0;
	speed=0.005;
	frame_count=frame_num;
	}
	void setPosition(int x,int y){
	  // rect.left=x;
	  // rect.top=y;
		sprite.setPosition(x,y);
   }
	 void update(float time)
   {	
     currentFrame += time * speed;
    if (currentFrame > frame_count) currentFrame -= frame_count;
	sprite.setTextureRect(IntRect(rect.left+rect.width*int(currentFrame),rect.top,rect.width,rect.height));
	//sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

   }
};
class Map{
public:
	Texture House;
	Sprite InsideHouse;
	void load()
	{
	
	House.loadFromFile("InsideHouse.png");
	InsideHouse.setTexture(House);
	}
	};

class PLAYER {

public:
int coin_count;
bool isVictory;
int collection_count;
int key_count;
float SaveCoordX,SaveCoordY;
float dx,dy;
FloatRect rect;
Sprite sprite;
bool onGround;
float currentFrame;
bool visible;
bool Mvisible;
float speed;
std::ostringstream notification_message;

    PLAYER(Texture &image)
   {
	sprite.setTexture(image);
	sprite.setTextureRect(IntRect(32,95,32,50));
	rect = FloatRect(100,180,32,50);

	isVictory=false;
	dx=dy=0;
	currentFrame = 0;
	sprite.setPosition(200,200);
	key_count = 0;
	coin_count = 0;
   }

	void SaveCoord()
	{
		SaveCoordX=rect.left;
		SaveCoordY=rect.top;
	}
	void ToSaveCoord(int x,int y)
	{
		rect.left=SaveCoordX+x;
		rect.top=SaveCoordY+y;
	}

   void update(float time)
   {	

	 rect.left += dx * time;	
     Collision(0);
   
	 rect.top += dy*time;
     Collision(1);
	

     currentFrame += time * 0.005;
     if (currentFrame > 3) currentFrame -= 3;
    if (dx>0) sprite.setTextureRect(IntRect(32*int(currentFrame),95,32,50));
	if (dx<0) sprite.setTextureRect(IntRect(32*int(currentFrame),48,32,50));
	if (dy>0) sprite.setTextureRect(IntRect(32*int(currentFrame),-2,32,50));
	if (dy<0) sprite.setTextureRect(IntRect(32*int(currentFrame),148,32,50));
  

	 sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	  
	 dx=0;
   }


   void Collision(int num) 
{
	

	if(!inHouse)
	{

				for (int i = rect.top/32 ; i<(rect.top+rect.height)/32; i++)
		for (int j = rect.left/32; j<(rect.left+rect.width)/32; j++)
			 {
				 if (TileMap[i][j]=='0' || TileMap[i][j]=='w'|| TileMap[i][j]=='d'|| TileMap[i][j]=='k' || 
					 TileMap[i][j]=='h' || TileMap[i][j]=='l' ||  TileMap[i][j]=='J'||  TileMap[i][j]=='e'||  TileMap[i][j]=='E'
					 ||  TileMap[i][j]=='b')
				                         { 
												   if (dy>0 && num==1)
												   { rect.top =   i*32 -  rect.height;    }
											       if (dy<0 && num==1)
												   { rect.top = i*32 + 32;   }
												   if (dx>0 && num==0)
												   { rect.left =  j*32 -  rect.width; }
											       if (dx<0 && num==0)
												   { rect.left =  j*32 +rect.width;}
										 }


				 if (TileMap[i][j]=='t'){ SaveCoord();rect.left=204;rect.top=317;inHouse=true; }
				 if (TileMap[i][j]=='c') {
												 // TileMap[i][j]=' '; 
			                          	 }

				 if ((TileMap[i][j]=='v')||(TileMap[i][j]=='p')||(TileMap[i][j]=='P')||(TileMap[i][j]=='р')||(TileMap[i][j]=='Р')) visible=false;
				 else visible = true;
				
				  if (TileMap[i][j]=='h'){// реакция на нажатие space при подходе к камню
					  if (Keyboard::isKeyPressed(Keyboard::Space))    {
						if (dy>0)
							{  TileMap[i+1][j]='c';  }
						if (dy<0)
							{ TileMap[i-1][j]='c';}
						if (dx>0)
							{ TileMap[i][j+1]='c'; }
						if (dx<0)
							{ TileMap[i][j-1]='c';}
					TileMap[i][j]=' ';
					 notification_message << "Collected stone\n";
					 collection_count++;
					 }
				 }
				  if (TileMap[i][j]=='k'){// реакция на нажатие space при подходе к камню
					  if (Keyboard::isKeyPressed(Keyboard::Space))    {
						if (dy>0)
							{  TileMap[i+1][j]='K';  }
						if (dy<0)
							{ TileMap[i-1][j]='K';}
						if (dx>0)
							{ TileMap[i][j+1]='K'; }
						if (dx<0)
							{ TileMap[i][j-1]='K';}
					 TileMap[i][j]=' ';
					 notification_message << "Collected stone!\n";
					 collection_count++;
					 }
				 }
				   if (TileMap[i][j]=='K'){// реакция на нажатие space при подходе к монете
					 if (Keyboard::isKeyPressed(Keyboard::Space))    {
					 TileMap[i][j]=' ';
					 notification_message << "Collected coin\n";
					 key_count++;
					 }
				 }
				  if (TileMap[i][j]=='c'){// реакция на нажатие space при подходе к монете
					 if (Keyboard::isKeyPressed(Keyboard::Space))    {
					 TileMap[i][j]=' ';
					 notification_message << "Collected coin\n";
					 coin_count++;
					 }
				 }
				 if ((TileMap[i][j]=='m')) Mvisible=false;
				 else Mvisible = true;
			 }
	}else
	{
		for (int i = rect.top/32 ; i<(rect.top+rect.height)/32; i++)
		for (int j = rect.left/32; j<(rect.left+rect.width)/32; j++)
		{
			 if (TileInsideHouse[i][j]=='0' || TileInsideHouse[i][j]=='f' || TileInsideHouse[i][j]=='J')
			 {
				 if (dy>0 && num==1)
				{ rect.top =   i*32 -  rect.height;  dy=0;  }
				 if (dy<0 && num==1)
				{ rect.top = i*32 + 32;   dy=0;}
				if (dx>0 && num==0)
				{ rect.left =  j*32 -  rect.width; }
				if (dx<0 && num==0)
				{ rect.left =  j*32 +32;}
			 }
			 if (TileInsideHouse[i][j]=='t'){T=true;;inHouse=false; }

			 if (TileInsideHouse[i][j]=='f' && Keyboard::isKeyPressed(Keyboard::Space)
				 && key_count >= 3){isVictory = true;}
		}
	}
		
}

};







int main()
{  
	Map map;
	map.load();
	float CordX,CordY;
	CordX=0;CordY=0;
	bool menuCall;
	int resX=1366,resY=768;
	RenderWindow window(VideoMode(resX, resY), "Digger",Style::Fullscreen);
	//Текустуры


	Texture MainHeroSet;
	MainHeroSet.loadFromFile("MainHero.png");

	Texture water_texture;
	water_texture.loadFromFile("Water.png");
	
	Texture empty_texture;
	empty_texture.loadFromFile("empty_test.png");

	Texture texture_set1;
	texture_set1.loadFromFile("texture.png");

	Texture coin_texture;
	coin_texture.loadFromFile("coin.png");

	Texture key_texture;
	key_texture.loadFromFile("key.png");

	Texture ElvinF;
	ElvinF.loadFromFile("ElvinForest.png");

	Texture Dange;
	Dange.loadFromFile("Dange.png");
	
	Texture Floor1;
	Floor1.loadFromFile("Sloy_1.png");

	///Классы
	PLAYER Player(MainHeroSet);	
	Player.speed =0.1; //0.2;//Player
	Texture_3 Water(water_texture,0,0,32,32,31);    //Water
	Water.speed=0.01;
	//ENEMY  enemy;
	//enemy.set(tileSet,48*16,13*16);



	Sprite tile(ElvinF);
	Sprite ElvinForest(ElvinF);
	Sprite TileDange(Dange);
	Sprite Floor_stage_sprite(Floor1);
	Sprite empty(empty_texture);
	Sprite coin(coin_texture);
	Sprite texture1(texture_set1);
	Sprite key(key_texture);

	SoundBuffer buffer;
	buffer.loadFromFile("PlayerStep.ogg");
	Sound sound(buffer);

	SoundBuffer buffer1;
	buffer1.loadFromFile("PlayerWoodStep.ogg");
	Sound soundWoodStep(buffer1);

	SoundBuffer buffer2;
	buffer2.loadFromFile("stone_sample_1.ogg");
	Sound soundStoneBreak(buffer2);
	soundStoneBreak.setVolume(20);

   // music.play();
	
	SoundBuffer buffer3;
	buffer3.loadFromFile("victory.ogg");
	Sound soundVictory(buffer3);

	SoundBuffer buffer4;
	buffer4.loadFromFile("background.ogg");
	Sound backgroundSound(buffer4);
	backgroundSound.play();

	Font font;
	font.loadFromFile("sansation.ttf");

	

	Texture menu_texture1,menu_texture2,victory_texture, texture_backgroundMenu;
	menu_texture1.loadFromFile("111.png");
    menu_texture2.loadFromFile("333.png");
	victory_texture.loadFromFile("victory.png");
	texture_backgroundMenu.loadFromFile("background_menu.png");
	Sprite backgroundMenu(texture_backgroundMenu),menu1(menu_texture1),menu2(menu_texture2), victory_sprite(victory_texture);
	bool Menu=true;
	int MenuNum=0;
	int x,y,x1,y1;
	menu1.setPosition(x=resX/2-100,y=resY/2-60);
    menu2.setPosition(x1=resX/2-100,y1=resY/2);
	
	Clock clock;
	bool isNotificationShow = false;
	float message_time = 0;
	int messageCoordX = 0;
	int item_count = 0;
	bool openVictoryWindow = false;
    while (window.isOpen())
    { 
	/////меню
	while(Menu)
	{	   
	   //Player.sprite.setPosition(200,200);
	   menu1.setColor(Color::Red);
	   menu2.setColor(Color::White);
	   MenuNum=0;
	   window.clear(Color(0,0,0));

	   if (IntRect(x,y,300,50).contains(Mouse::getPosition(window))) {menu1.setColor(Color::Yellow); MenuNum=1;}
       if (IntRect(x1,y1,300,50).contains(Mouse::getPosition(window))) {menu2.setColor(Color::Yellow); MenuNum=2;}

	   if (Mouse::isButtonPressed(Mouse::Left))
	     {
			 if (MenuNum==1) {Menu=false;Player.collection_count = 0;}
			 if (MenuNum==2)  {window.close();Menu=false;}
	     }
			window.draw(backgroundMenu);
		    window.draw(menu1);
            window.draw(menu2);

		window.display();
	}
	while(openVictoryWindow)
	{
		backgroundSound.stop();
		MenuNum=0;
		menu2.setColor(Color::White);
		if (IntRect(x1,y1,300,50).contains(Mouse::getPosition(window))) {menu2.setColor(Color::Yellow); MenuNum=2;}
		 if (Mouse::isButtonPressed(Mouse::Left))
	     {
			if (MenuNum==2)  {window.close();Menu=false;}
	     }
		window.draw(victory_sprite);
		window.draw(menu2);
		
		window.display();
	}
    ////////////////

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time /=800;  // здесь регулируем скорость игры

		//if (time > 6) time -= 6; 

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)      
                window.close();
		}


		if (Keyboard::isKeyPressed(Keyboard::A))    {Player.dx=-Player.speed;} 
       
		if (Keyboard::isKeyPressed(Keyboard::D))    {Player.dx=Player.speed;}
    
	    if (Keyboard::isKeyPressed(Keyboard::W))	
			{Player.dy=-Player.speed;    } else Player.dy=0;
	    if (Keyboard::isKeyPressed(Keyboard::S))	
			{ Player.dy=Player.speed;   }

		if (Keyboard::isKeyPressed(Keyboard::F1)) {Player.SaveCoord();}
		if (Keyboard::isKeyPressed(Keyboard::F2)) {Player.ToSaveCoord(0,+50);}
        
		if (Keyboard::isKeyPressed(Keyboard::Escape)) Menu=true;
		
		if ((Player.dx!=0 || Player.dy!=0) && sound.getStatus()!=2 && !inHouse )
		{
			sound.play();
		}
		if ((Player.dx!=0 || Player.dy!=0) && soundWoodStep.getStatus()!=2 && inHouse )
		{
			soundWoodStep.play();
		}

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			//sound.stop();
			if (item_count != Player.collection_count && !Player.isVictory) {
				soundStoneBreak.play();
			    item_count = Player.collection_count;
			}
			if (Player.isVictory && soundVictory.getStatus()!=2)
			{
				soundVictory.play();
				Player.isVictory=false;
				openVictoryWindow =true;
			}
		}
		

		 Player.update(time);
		 Water.update(time);
		 if (backgroundSound.getStatus()!=2)backgroundSound.play();
		 
//		 if  (Player.rect.intersects( enemy.rect ) )
//		 {
//			 if (enemy.life) {
//			 if (Player.dy>0) { enemy.dx=0; Player.dy=-Player.speed; enemy.life=false;}
//			 else Player.sprite.setColor(Color::Red);
//			 }
//		 }


		 if (Player.rect.left<32*W-resX/2 && Player.rect.left>resX/2+64) offsetX = Player.rect.left-resX/2;
		 if (Player.rect.top<32*H-resY/2 && Player.rect.top>resY/2+64) offsetY = Player.rect.top-resY/2;


		 if (!inHouse)
		 {
		 window.clear(Color(107,140,255));
		////// Второй слой
		 int y1,x1;
			 x1=0,y1=0;
 		// for (int i=0; i<H; i++)
		//	 for (int j=0; j<W; j++)
		//	 {
		//		
		//		  if (TileFloor[i][j]=='r') {Floor_stage_sprite.setTextureRect(IntRect(0,0,1600,1600));x1=0;y1=32;}
		//		 //if (TileFloor[i][j]=='g') {ElvinForest.setTextureRect(IntRect(225,0,32,32));x1=0;y1=32;}
		//		 else continue;
				 //Floor_stage_sprite.setPosition(((j*32 - offsetX)+x1),((i*32 - offsetY)+y1)) ;
				 //Water.sprite.setPosition(((j*32 - offsetX)+x1),((i*32 - offsetY)+y1));
				 //window.draw(Floor_stage_sprite);
				 
				 
				
			// }
		//////

			  if (!Player.visible) window.draw(Player.sprite);
        //////Первый слой

		 for (int i=0; i<H; i++)
			 for (int j=0; j<W; j++)
			  { 
				  
				int y,x;
				x=0;y=0;
				  if (TileFloor[i][j]=='r') {Floor_stage_sprite.setTextureRect(IntRect(0,0,1920,1920));x1=0;y1=32;
				 
				  Floor_stage_sprite.setPosition(((j*32 - offsetX)+x1),((i*32 - offsetY)+y1)) ;
				   window.draw(Floor_stage_sprite);
				  }
				   if (TileFloor[i][j]=='J') {Water.sprite.setPosition(((j*32 - offsetX)+x),(i*32 - offsetY)+y); window.draw(Water.sprite);}
				  
				  if (TileMap[i][j]=='p')  { ElvinForest.setTextureRect( IntRect(135,13,80,100)); x=-32;y=-32; }//дерево снизу
				  if(TileMap[i][j]=='P') { ElvinForest.setTextureRect( IntRect(135,13,80,100)); x=-32;y=0; }// Дерево сверху
				  if (TileMap[i][j]=='l') { ElvinForest.setTextureRect( IntRect(135,13,80,100));x=-32;y=-32;}//дерево ровное
				if (TileMap[i][j]=='w') {ElvinForest.setTextureRect(IntRect (98,133,33,33));x=0;y=32;}// пеньки
				if (TileMap[i][j]=='W') {ElvinForest.setTextureRect(IntRect (98,133,33,33));x=0;y=64;}// пеньки
				if (TileMap[i][j]=='k') {ElvinForest.setTextureRect(IntRect (224,32,32,32));x=0;y=0;}// камень с ключем
				if (TileMap[i][j]=='h') {ElvinForest.setTextureRect(IntRect (224,32,32,32));x=0;y=0;}// камень
				if (TileMap[i][j]=='q') {// палатка
					texture1.setTextureRect(IntRect (224,64,96,96));
					x=0;y=0;
					texture1.setPosition(((j*32 - offsetX)+x),(i*32 - offsetY)+y);
					window.draw(texture1);
					continue;}// палатка
				if (TileMap[i][j]=='e') {//куст фиолетовый
					texture1.setTextureRect(IntRect (352,128,32,32));
					x=0;y=0;
					texture1.setPosition(((j*32 - offsetX)+x),(i*32 - offsetY)+y);
					window.draw(texture1);
					continue;}
				if (TileMap[i][j]=='E') {//куст ;желтый
					texture1.setTextureRect(IntRect (384,128,32,32));
					x=0;y=0;
					texture1.setPosition(((j*32 - offsetX)+x),(i*32 - offsetY)+y);
					window.draw(texture1);
					continue;}
				if (TileMap[i][j]=='b') {//бревно
					texture1.setTextureRect(IntRect (448,192,32,32));
					x=0;y=0;
					texture1.setPosition(((j*32 - offsetX)+x),(i*32 - offsetY)+y);
					window.draw(texture1);
					continue;}
				if (TileMap[i][j]=='a') {//ель
					texture1.setTextureRect(IntRect (224,190,96,32));
					x=0;y=0;
					texture1.setPosition(((j*32 - offsetX)+x),(i*32 - offsetY)+y);
					window.draw(texture1);
					continue;}
				if (TileMap[i][j]=='K') {//Ключ
					key.setTextureRect(IntRect (0,0,32,32));
					x=0;y=0;
					key.setPosition(((j*32 - offsetX)+x),(i*32 - offsetY)+y);
					window.draw(key);
					continue;}

				if (TileMap[i][j]=='c'){ 
					coin.setTextureRect(IntRect(0,0,32,32));
					coin.setPosition(((j*32 - offsetX)+x),(i*32 - offsetY)+y); 
					window.draw(coin);
					continue; }// монета
				if (TileMap[i][j]=='g') {ElvinForest.setTextureRect(IntRect(225,0,32,32));x1=0;y1=32;}
				if (TileMap[i][j]=='J'){continue;} //{Water.sprite.setPosition(((j*32 - offsetX)+x),(i*32 - offsetY)+y); window.draw(Water.sprite);continue;}
				if (TileMap[i][j]=='d') 
				{
				TileDange.setTextureRect(IntRect(0,0,306,168));
				x=-16;y=-32;
				TileDange.setPosition(((j*32 - offsetX)+x),(i*32 - offsetY)+y) ;
				
				window.draw(TileDange);
				
				continue;
				}
				  


				if (TileMap[i][j]=='0') {
					//empty.setTextureRect( IntRect(0,0,32,32));					//раскоментировать , если нужно показить обрамления нулевых блоков
					//empty.setPosition(((j*32 - offsetX)+x),(i*32 - offsetY)+y); //
					//window.draw(empty);											//
					continue;
				}
				if ((TileMap[i][j]==' ') 
					||(TileMap[i][j]=='v')
					||(TileMap[i][j]=='r')
					||(TileMap[i][j]=='t')
					) {
						continue;
						//x=-32;y=0;
				}

				
		         ElvinForest.setPosition(((j*32 - offsetX)+x),(i*32 - offsetY)+y) ;
				 window.draw(ElvinForest); //расстояние между элементами карты
				 if (T)
				 {
					 Player.ToSaveCoord(0,10);
					 T=false;
				 }
				 
		     }
		 }
		 else
		 {
			 window.clear(Color(0,0,0));

					 map.InsideHouse.setTextureRect(IntRect(0,0,498,361));
				// map.InsideHouse.setPosition((resX/4),resY/4) ;
				 window.draw(map.InsideHouse);
			 
		 }
		 ////////
			 //window.draw(enemy.sprite);
			  
			 if (Player.visible) window.draw(Player.sprite);
			 //if(Skills.dx!=0) window.draw(Skills.sprite);

			 if (Player.notification_message.str() != ""){
				if(message_time/100<2){
					if(!isNotificationShow){
						 message_time = 0;
						 isNotificationShow = true;
						 messageCoordX = resX/2-Player.notification_message.str().length()*20/2;
					}
				  message_time++;
				}else{
						Player.notification_message.str("");
						isNotificationShow = false;
						message_time = 0;
			}

		Text notification_text((char)Player.rect.top,font,40);
		notification_text.setColor(Color::Green);
		notification_text.setPosition(messageCoordX,resY/10);
		//std::ostringstream notification_str;
		notification_text.setString(Player.notification_message.str()+ "\n");
		
		
		if (isNotificationShow) window.draw(notification_text);
	}

	Text mytext((char)Player.rect.top,font,20);
	mytext.setColor(Color::Red);
	mytext.setPosition(50,resY-400);

	std::ostringstream str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,str11,str12,str13,str14,str15,str16;    
	str1<< Player.rect.top;
	str2<<Player.rect.left;
	str9<<CordX;
	str10<<CordY;
	str11<<Player.SaveCoordX;
	str12<<Player.SaveCoordY;
	str13<<time;
	str14<<Player.collection_count;
	str15<<Player.key_count;
	str16<<Player.coin_count;
	//str14 << message_time/100;
		 mytext.setString("Collected " +str15.str()+ "/3 keys\n"+
			 "Collected " +str16.str()+ " coins\n"+
			 "Collected " +str14.str()+ " items\n"+"Time "+str13.str()+"\nSaveCoordX= "+str11.str()+"\nSaveCoordY= "+str12.str()+"\nCordX= "+str9.str()+"\nCordY= "+str10.str()+"\nx= "+str2.str()+"\ny= "+str1.str() );
		 window.draw(mytext);
		window.display();
    }

    return 0;
}

