
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<windows.h>
#include<time.h>
using namespace std;
//setting integers put these at the top of the code i set these to the values they need to be at for new game
int spotions = 0;
int mpotions = 0;
int lpotions = 0;
int maxpotions = 0;
int has_sword = 0;
int has_dagger = 0;
int has_bow = 0;
int weapon_out = 0;
/* 
0 = Fists
1 = Sword
2 = Spear
3 = Bow
4 = Dagger 
5 = Axe
Used for inentory (FYI I have an idea of how to use the inventory for showing spells and using them in the magic area
*/
int statdamage;
int player_accuracy = 90;
int max_health = 1000;
int current_health = 1000;
int attribute_damage = 90;
int weapon_damage = 0;
int run_away = 0;
int overalldamage = 0;
int battlelocation = 0; //choosing enemy
char battlemenu = 0;
int escape = 25;
char itemmenu = 0;
int current_mana = 100;
int max_mana = 100;
int mainehitratio = 0;
char spellmenu = 0;
int fire_spell = 0;
int eletric_spell = 0;
int sleep_spell = 0;
int spell_count = 0;
int current_xp=0;
int xp_left=100;
int player_lvl=1;
int damagedif=10;
int player_speed=100;
float player_armor = 1;
float accuracy = 0;
float player_dodge = 1;
string player_name = "PLAYER";
string current_weapon ="FISTS";
//these are the variables that I will make local but just want to get the game working 
/*Yes Joey I will fix this I just 
added this for geting the game 
working on your end and I will 
start using local variables 
soon to save space */
int xp_drop = 0;
float earmor = 0;
float edodge = 0;
string enemy_name = "ENEMY";
int edamagedif = 0;
float damagedelt = 0;
int money_drop = 0;
int paralyze =0;
int sleep =0;
int ehitratio = 0;
int enemy_damage;
int enemy_health = 0;
int MAXenemy_health;
int random = 0;
int espeed = 0;
//end of local variables
void EnemyDCode();
void MenuChoice1();
void MenuChoice2();
void MenuChoice3();
void MenuChoice4();
void MenuChoice5();
void EndTurnStuff();
void SPotion();
void MPotion();
void LPotion();
void MAXPotion();
void Menu();
void BattleReset();
void ChooseEnemy();
void PlayerDCode();
void Music();
int main(){
	//delete the next line in use for testing purposes
current_xp=99;current_weapon="SWORD"; player_name="TEST"; fire_spell=1; eletric_spell=1; sleep_spell=1; spotions=5; mpotions=3; lpotions=1; maxpotions=0;player_dodge=.95;player_armor = .9;
//actual code starts here copy and paste all this where the battle code needs to be
//Battlelocation is how to descide what enemies show up
ChooseEnemy();
cout<<"You encountered "<<enemy_name<<"!"<<endl;
system("PAUSE");
//All of these need to be set up so that the code works you NEED to set these variables everytime
BattleReset();
while(current_health>0 && enemy_health>0 && run_away==0){
	//Menu
	Menu();
EndTurnStuff();
}
if (current_health>0 && run_away==0){
cout<<"XP needed to level up "<<xp_left-current_xp<<endl;
system("PAUSE");
system("CLS");
}
return 0;
}

void EnemyDCode (){
	random=0;
			srand(time(NULL));
			random=rand()%100+1;
			accuracy=0;
			accuracy=ehitratio*player_dodge;
			if (random<=accuracy){
				srand(time(NULL));
				damagedelt=rand()%edamagedif+enemy_damage;
				damagedelt=damagedelt*player_armor;
				current_health=current_health-damagedelt;
				cout << "You Got Hit!\n";
				system("PAUSE");
				system("CLS");
			}
			else {
				cout<<enemy_name<<" missed "<<player_name<<"!"<<endl;
				if (sleep>0){
					cout<<enemy_name<<" is asleep"<<endl;
				}
				if (paralyze>0){
					cout<<enemy_name<<" is paralyzed"<<endl;
				}
				system("PAUSE");
				system("CLS");
			}
			if (current_health<=0){
				cout<<"You were defeated by "<<enemy_name<<endl;
				system("PAUSE");
				system("CLS");
			}
}
void PlayerDCode(){
		accuracy=0;
	accuracy=player_accuracy*edodge;
		srand(time(NULL));
		random=rand()%100+1;
		if (random<=accuracy){
			system("CLS");
			srand(time(NULL));
			damagedelt=rand()%damagedif+overalldamage;
			damagedelt=damagedelt*earmor;
			enemy_health=enemy_health-damagedelt;
			cout << "You Hit The Enemy!\n";
			system("PAUSE");
			system("CLS");
		}
		else {
			system("CLS");
			cout<<player_name<<" missed!"<<endl;
			system("PAUSE");
			system("CLS");
		}
}
void MenuChoice1(){
		system("CLS");
		if (player_speed>=espeed){
			PlayerDCode();
			if (enemy_health<=0){
				if (enemy_health<=0) {
					cout<<"You defeated "<<enemy_name<<endl;
					system("PAUSE");
					system("CLS");
					cout<<"You gained "<<xp_drop<<"XP"<<endl;
					system("PAUSE");
					system("CLS");
					current_xp=current_xp+xp_drop;
					if (current_xp>=xp_left){
						cout<<"You leveled up!\n";
						Music();
						cout<<"Old Level "<<player_lvl<<endl;
						player_lvl=player_lvl+1;
						cout<<"New Level "<<player_lvl<<endl;
						current_xp=current_xp-xp_left;
						xp_left=xp_left*2;
						cout<<"Xp till next lvl "<<xp_left<<endl<<"Old Skill Damage "<<attribute_damage<<endl;
						attribute_damage=attribute_damage+50;
						cout<<"New Skill Damage "<<attribute_damage<<endl<<"Old Max Health "<<max_health<<endl;
						max_health=max_health+100;
						cout<<"New Max Health "<<max_health<<endl;
						system("PAUSE");
						system("CLS");
					}
				}
			}
			else{
				EnemyDCode();
			}
		}
		else{
			EnemyDCode();
			if(current_health>=0){
				PlayerDCode();
				if (enemy_health<=0){
					if (enemy_health<=0) {
					cout<<"You defeated "<<enemy_name<<endl;
					system("PAUSE");
					system("CLS");
					cout<<"You gained "<<xp_drop<<"XP"<<endl;
					system("PAUSE");
					system("CLS");
					current_xp=current_xp+xp_drop;
						if (current_xp>=xp_left){
							player_lvl=player_lvl+1;
							current_xp=current_xp-xp_drop;
							xp_drop=xp_drop*2;
							attribute_damage=attribute_damage+50;
							max_health=max_health+100;
						}		
					}
				}
			}
		}
}

void MenuChoice2(){
	system("CLS");
		cout<<player_name<<"'s Stats"<<endl<<"Health:"<<current_health<<endl<<"Max Health:"<<max_health<<endl<<"Damage:"<<overalldamage<<"-"<<statdamage<<endl<<"Weapon In Use:"<<current_weapon<<endl;
		system("PAUSE");
		system("CLS");
}

void MenuChoice3(){
	system("CLS");
		itemmenu=0;
		cout<<"What do you want to use?"<<endl<<"1.Small Potions:"<<spotions<<endl<<"2.Medium Potions:"<<mpotions<<endl<<"3.Large Potions:"<<lpotions<<endl<<"4.Max Potions:"<<maxpotions<<endl<<"If you don't want to do anything them use any other number"<<endl;
		itemmenu = getch();
		switch (itemmenu){
		//Small Potions
		case '1':
			SPotion();
		break;
		//Medium Potions
		case '2':
			MPotion();
		break;
		//Large Potions
		case '3':
			LPotion();
		break;
		//Max Potions
		case '4':
			MAXPotion();
		break;
		//Nothing Used
		default:
			system("CLS");
			cout<<"You did not use anything"<<endl;
			system("PAUSE");
			system("CLS");
			break;
	}
}

void MenuChoice4(){
	system("CLS");
		spellmenu=0;
		cout<<"Which spell do you want to use"<<endl;
		if (spell_count==0){
			cout<<"You don't have any spells to use"<<endl;
		}
		if (fire_spell==1){
		cout<<"1.Fire 50 Mana"<<endl;
	}
		if (eletric_spell==1){
		cout<<"2.Electirc 25 Mana"<<endl;
	}
		if (sleep_spell==1){
		cout<<"3.Sleep 100 Mana"<<endl;
	}
		cout<<"Mana: "<<current_mana<<" out of "<<max_mana<<endl<<"If you don't want to use any spells use a number that isn't a spell"<<endl;
		spellmenu=getch();
		//Using Fire Stuff
		if (spellmenu=='1'&&fire_spell==1){
			current_mana=current_mana-50;
			if (current_mana>=0){
				enemy_health=enemy_health-500;
				cout<<player_name<<" used Fire!"<<endl<<enemy_name<<" took 500 health"<<endl<<enemy_name<<" has "<<enemy_health<<" left"<<endl;
			system("PAUSE");
			system("CLS");
			if (enemy_health<=0){
				cout<<player_name<<" defeated "<<enemy_name<<endl;
				system("PAUSE");
				system("CLS");
				cout<<"You gained "<<xp_drop<<"XP"<<endl;
				system("PAUSE");
				system("CLS");
				current_xp=current_xp+xp_drop;
					if (current_xp>=xp_left){
						cout<<"You leveled up!\n";
						Music();
						cout<<"Old Level "<<player_lvl<<endl;
						player_lvl=player_lvl+1;
						cout<<"New Level "<<player_lvl<<endl;
						current_xp=current_xp-xp_left;
						xp_left=xp_left*2;
						cout<<"Xp till next lvl "<<xp_left<<endl<<"Old Skill Damage "<<attribute_damage<<endl;
						attribute_damage=attribute_damage+50;
						cout<<"New Skill Damage "<<attribute_damage<<endl<<"Old Max Health "<<max_health<<endl;
						max_health=max_health+100;
						cout<<"New Max Health "<<max_health<<endl;
						system("PAUSE");
						system("CLS");
			}
			}
			else {
			EnemyDCode();
			}
			}	
			else {
				cout<<"You don't have enough mana to do that";
				current_mana=current_mana+50;
				system("PAUSE");
				system("CLS");
			}
		}
		//Using Eletric Spell
		if (spellmenu=='2'&&eletric_spell==1){
			current_mana=current_mana-25;
			if (current_mana>=0){
				cout<<player_name<<" used Eletric!"<<endl<<player_name<<" paralyzed "<<enemy_name<<endl;
				system("PAUSE");
				system("CLS");
				paralyze=5;
				ehitratio=ehitratio/2;
				EnemyDCode();
			}
			else {
				cout<<"You don't have enough mana to do that";
				current_mana=current_mana+25;
				system("PAUSE");
				system("CLS");
			}
		}
		//Using Sleep Spell
		if (spellmenu=='3'&&sleep_spell==1){
			current_mana=current_mana-100;	
			if (current_mana>=0){
				cout<<player_name<<" used Sleep!"<<endl<<player_name<<" put "<<enemy_name<<" to sleep"<<endl;
				system("PAUSE");
				system("CLS");
				sleep=3;
				ehitratio=0;
				EnemyDCode();
			}
			else{
				cout<<"You don't have enought mana to do that";
				current_mana=current_mana=100;
				system("PAUSE");
				system("CLS");
			}
	}
}

void MenuChoice5(){
		system("CLS");
		random=0;
		srand(time(NULL));
		random=rand()%100+1;
		if (random<=escape){
			cout<<"You got away\n";
			system("PAUSE");
			system("CLS");
			run_away=1;
		}
		else {
			cout<<"You couldn't get away"<<endl;
			system("PAUSE");
			system("CLS");
			EnemyDCode();
		}
}

void EndTurnStuff(){
	//mana regain (I could probably change the regen rate when you get items
current_mana=current_mana+10;
if (current_mana>max_mana){
	current_mana=max_mana;
}
//Paralization
paralyze=paralyze-1;
if (paralyze==0){
	cout<<enemy_name<<" is not paralyzed anymore!"<<endl;
	ehitratio=mainehitratio;
	system("PAUSE");
	system("CLS");
}
//Sleep
sleep=sleep-1;
if (sleep==0){
	cout<<enemy_name<<" woke up"<<endl;
	ehitratio=mainehitratio;
	system("PAUSE");
	system("CLS");
}
}

void SPotion(){
		if (spotions==0){
				system("CLS");
				cout<<player_name<<" doesn't have any small potions"<<endl;
				system("PAUSE");
				system("CLS");
			}
			else{
				spotions=spotions-1;
				current_health=current_health+100;
				if (current_health>max_health){
					current_health=max_health;
				}
				cout<<"The potions gave "<<player_name<<" 100 health"<<endl<<player_name<<" has "<<current_health<<" out of "<<max_health<<endl;
				system("PAUSE");
				system("CLS");
			EnemyDCode();
			}
}

void MPotion(){
	if (mpotions==0){
				system("CLS");
				cout<<player_name<<" doesn't' have any medium potions"<<endl;
				system("PAUSE");
				system("CLS");
			}
			else{
				mpotions=mpotions-1;
				current_health=current_health+400;
				if (current_health>max_health){
					current_health=max_health;
				}
				cout<<"The potions gave "<<player_name<<" 400 health"<<endl<<player_name<<" has "<<current_health<<" out of "<<max_health<<endl;
				system("PAUSE");
				system("CLS");
			EnemyDCode();
			}
}

void LPotion(){
		if (lpotions==0){
				system("CLS");
				cout<<player_name<<" doesn't have any large potions"<<endl;
				system("PAUSE");
				system("CLS");
			}
			else{
				lpotions=lpotions-1;
				current_health=current_health+1000;
				if (current_health>max_health){
					current_health=max_health;
				}
				cout<<"The potions gave "<<player_name<<" 1000 health"<<endl<<player_name<<" has "<<current_health<<" out of "<<max_health<<endl;
				system("PAUSE");
				system("CLS");
				EnemyDCode();
			}
}

void MAXPotion(){
		if (maxpotions==0){
				system("CLS");
				cout<<player_name<<" doesn't have any max potions"<<endl;
				system("PAUSE");
				system("CLS");
			}
			else {
				current_health=max_health;
				cout<<player_name<<" has max health"<<endl;
				system("PAUSE");
				system("CLS");
				EnemyDCode();
			}
}

void Menu(){
	system("CLS");
	cout << player_name << ": " << "Health: " << current_health << "/" << max_health << endl;
	cout << "      Mana: " << current_mana << "/" << max_mana<<endl;
	cout << enemy_name << " Health: " << enemy_health << "/" <<MAXenemy_health<<endl;
	cout<<"What do you want to do?\n"<<"1.Attack\n"<<"2.Stats\n"<<"3.Item\n"<<"4.Magic\n"<<"L.Flee\n";
	battlemenu = getch ();
	switch (battlemenu) {
	case '1':
		MenuChoice1();
	break;
	//Stats
	case '2':
		MenuChoice2();
	break;
	//Items
	case '3':
		MenuChoice3();
	break;
	//Magic
	case '4':
		MenuChoice4();
	break ;
	//Run Away
	case 'L':
		MenuChoice5();
	break;
	
	case 'l':
		MenuChoice5();
	break;
	//Not a choice
	default :
		system("CLS");
		cout<<"Pick a correct choice\n";
		system("PAUSE");
		system("CLS");
	break;
}
}

void BattleReset(){
	run_away=0;
	overalldamage=attribute_damage+weapon_damage;
	current_mana=max_mana;
	ehitratio=mainehitratio;
	spell_count=fire_spell+eletric_spell+sleep_spell;
	statdamage=overalldamage+damagedif;
	sleep=0;
	paralyze=0;
}

void ChooseEnemy(){
	if (battlelocation==0){
	srand(time(NULL));
	random=rand()%100+1;
	if (random<=51){
	//If making a new emeny use these exact variables we can add more stuff if we need to
		enemy_damage=75;
		mainehitratio=50;
		enemy_health=500;
		enemy_name="Enemy";
		money_drop=100;
		xp_drop=25;
		edodge=.95;
		edamagedif=5;
		earmor=.90;
		espeed=75;
	}
	if (random>=50){
		enemy_damage=50;
		mainehitratio=75;
		enemy_health=300;
		enemy_name="Enemy 2";
		money_drop=125;
		xp_drop=50;
		edodge=.75;
		edamagedif=10;
		earmor=1;
		espeed=125;
	}
}
MAXenemy_health=enemy_health;
}
void Music(){
	Beep (330,100);Sleep(100);
        Beep (330,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (330,100);Sleep(300);
        Beep (392,100);Sleep(700);
        Beep (196,100);Sleep(700);
        Beep (196,100);Sleep(125);
        Beep (262,100);Sleep(125);
        Beep (330,100);Sleep(125);
        Beep (392,100);Sleep(125);
        Beep (523,100);Sleep(125);
        Beep (660,100);Sleep(125);
        Beep (784,100);Sleep(575);
        Beep (660,100);Sleep(575);
        Beep (207,100);Sleep(125);
        Beep (262,100);Sleep(125);
        Beep (311,100);Sleep(125);
        Beep (415,100);Sleep(125);
        Beep (523,100);Sleep(125);
        Beep (622,100);Sleep(125);
        Beep (830,100);Sleep(575);
        Beep (622,100);Sleep(575);
        Beep (233,100);Sleep(125);
        Beep (294,100);Sleep(125);
        Beep (349,100);Sleep(125);
        Beep (466,100);Sleep(125);
        Beep (587,100);Sleep(125);
        Beep (698,100);Sleep(125);
        Beep (932,100);Sleep(575);
        Beep (932,100);Sleep(125);
        Beep (932,100);Sleep(125);
        Beep (932,100);Sleep(125);
        Beep (1046,675);
}
