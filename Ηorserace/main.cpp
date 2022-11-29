#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <algorithm>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

class horse{
private:
    string name;
    int startup_speed;
    int power;
    int stamina;
public:
    void stats(int speed,int pwr,int stm){
    	startup_speed=speed;
    	power=pwr;
    	stamina=stm;
	}
    int id;
    int possition;	//yes, I know that the word is: position, but I like it with 2 s's
    void set_id(int i){id=i;}
    void set_name(string n){name=n;}
    void get_name(){cout << name;}
    void set_possition(int ps){possition=ps;} 
    bool move_forward(int c,int r){
        bool f=false;
        if((c==1 && startup_speed > r) || ((c>=2 && c<=8) && power>r))
        {
            f = true;
        }
        else if(((power+stamina)/2)>r && c>8)
        {
            f=true;
        }   
        return f;
    }
};
horse h0;
horse h1;
horse h2;
horse h3;
horse h4;
horse h5;
horse h6;
horse h7;
horse h8;
horse h9;


//====================================================================================================================================race graffix
void placement(int i,int r ,int ps) {
	int j;
	cout << "           ";
	for(j=0;j<r;j++)
	{
		if (j!=ps)
			cout << " .";
		else
			cout << " "<< i;
	}
	if(ps==r){
		cout<<" |" << i << endl;
	}else{
		cout << " |_" << endl;
	}
}


//====================================================================================================================================manual placement of the cersor in the cmd terminal
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x, y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}


//====================================================================================================================================basic scene output
int screen(string state,int i,int j){
	if (state=="start")
	{
		cout << "   ======================================" << endl;
    	cout << "   ==                                  ==" << endl;
        cout << "   ==       Extreme(ly slow)           ==" << endl;
        cout << "   ==          Horse racing            ==" << endl;
        cout << "   ==                Delux edition     ==" << endl;
        cout << "   ==                                  ==" << endl;
        cout << "   ======================================" << endl;
        cout << "         TYPE ANYTHING TO CONTINUE" << endl;
	}
	else if(state=="begin1"){
    	cout << "   ==                                  ==" << endl;
        cout << "   ==            * start               ==" << endl;
        cout << "   ==              credits             ==" << endl;
        cout << "   ==              exit                ==" << endl;
        cout << "   ==                                  ==" << endl;
	}
	else if(state=="begin2"){
    	cout << "   ==                                  ==" << endl;
        cout << "   ==              start               ==" << endl;
        cout << "   ==            * credits             ==" << endl;
        cout << "   ==              exit                ==" << endl;
        cout << "   ==                                  ==" << endl;
	}
	else if(state=="begin3"){
    	cout << "   ==                                  ==" << endl;
        cout << "   ==              start               ==" << endl;
        cout << "   ==              credits             ==" << endl;
        cout << "   ==            * exit                ==" << endl;
        cout << "   ==                                  ==" << endl;
	}
	else if(state=="credits"){
		cout << "   ==                                  ==" << endl;
        cout << "   ==         Haris Leontidis          ==" << endl;
        cout << "   ==               &&                 ==" << endl;
        cout << "   ==         Giorgos Kefalas          ==" << endl;
        cout << "   ==                                  ==" << endl;
	}
	else if(state=="game0" || state=="game1" || state=="game2"){
		cout << "   ==                                    ==" << endl;
		if(state=="game0"){
			cout << "   ==     * Number of horses             ==" << endl;
		}
		else{
			cout << "   ==       Number of horses             ==" << endl;
		}
		switch(i){
		case 1:
			cout << "   ==  <| |___________________  |>   1   ==" << endl;
        	break;
        case 2:
        	cout << "   ==  <| __|_________________  |>   2   ==" << endl;
			break;
		case 3:
        	cout << "   ==  <| ____|_______________  |>   3   ==" << endl;
			break;
		case 4:
        	cout << "   ==  <| ______|_____________  |>   4   ==" << endl;
			break;
		case 5:
        	cout << "   ==  <| ________|___________  |>   5   ==" << endl;
			break;
		case 6:
        	cout << "   ==  <| __________|_________  |>   6   ==" << endl;
			break;
		case 7:
        	cout << "   ==  <| ____________|_______  |>   7   ==" << endl;
			break;
		case 8:
        	cout << "   ==  <| ______________|_____  |>   8   ==" << endl;
			break;
		case 9:
        	cout << "   ==  <| ________________|___  |>   9   ==" << endl;
			break;
		case 10:
        	cout << "   ==  <| ___________________|  |>   10  ==" << endl;
			break;
		}
		cout << "   ==                                    ==" << endl;
        if(state=="game1"){
			cout << "   ==     * Number of laps               ==" << endl;
		}
		else{
			cout << "   ==       Number of laps               ==" << endl;
		}
		cout <<  "   ==  <| ";//rounds
		for(int jj=1;jj<=20;jj++){
			if(jj==j)
				cout << "|";
			else
				cout << "_";
		}
		cout<< "  |>   "<< j <<"   ==" << endl;
		cout << "   ==                                    ==" << endl;
        cout << "   ==                                    ==" << endl;
        
		if (state=="game2")
			cout << "   ==                       * begin      ==" << endl;
        else
			cout << "   ==                         begin      ==" << endl;
		
		cout << "   ==                                    ==" << endl;
	}
}


//====================================================================================================================================betting scene output
int screenb(string &state,int i,int &j,int s,string names[],int h){
	if (state=="betting"){
		cout << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" <<"  Total money:"<< s  << endl;
    	cout << "   $$                                  $$" << endl;
		if(i==1 && h>=0)
			cout << "   $$    *   < 0.  "<< names[0]<<"      >         $$" << endl;
		else if(i==2 && h>=1)
			cout << "   $$    *   < 1.  "<< names[1]<<"      >         $$" << endl;
		else if(i==3 && h>=2)
			cout << "   $$    *   < 2.  "<< names[2]<<"      >         $$" << endl;
		else if(i==4 && h>=3)
			cout << "   $$    *   < 3.   "<< names[3]<<"      >         $$" << endl;
		else if(i==5 && h>=4)
			cout << "   $$    *   < 4.   "<< names[4]<<"      >         $$" << endl;
		else if(i==6 && h>=5)
			cout << "   $$    *   < 5.   "<< names[5]<<"      >         $$" << endl;
		else if(i==7 && h>=6)
			cout << "   $$    *   < 6.   "<< names[6]<<"      >         $$" << endl;
		else if(i==8 && h>=7)
			cout << "   $$    *   < 7.   "<< names[7]<<"      >         $$" << endl;
		else if(i==9 && h>=8)
			cout << "   $$    *   < 8.   "<< names[8]<<"      >         $$" << endl;
		else if(i==10 && h>=9)
			cout << "   $$    *   < 9.   "<< names[9]<<"      >         $$" << endl;
        cout << "   $$                                  $$" << endl;
        cout << "   $$                                  $$" << endl;
        cout << "   $$           BET ["<<j<<"]             $$" << endl;
        cout << "   $$                                  $$" << endl;
        cout << "   $$                        begin     $$" << endl;
        cout << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;	
	}
	else if (state=="betting2" || state=="betting3"){
		cout << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" <<"  Total money:"<< s <<endl;
    	cout << "   $$                                  $$" << endl;
		if(i==1 && h>=0)
			cout << "   $$        < 0.  "<< names[0]<<"      >         $$" << endl;
		else if(i==2 && h>=1)   
			cout << "   $$        < 1.  "<< names[1]<<"      >         $$" << endl;
		else if(i==3 && h>=2)   
			cout << "   $$        < 2.  "<< names[2]<<"      >         $$" << endl;
		else if(i==4 && h>=3)   
			cout << "   $$        < 3.  "<< names[3]<<"      >         $$" << endl;
		else if(i==5 && h>=4)   
			cout << "   $$        < 4.  "<< names[4]<<"      >         $$" << endl;
		else if(i==6 && h>=5)   
			cout << "   $$        < 5.  "<< names[5]<<"      >         $$" << endl;
		else if(i==7 && h>=6)   
			cout << "   $$        < 6.  "<< names[6]<<"      >         $$" << endl;
		else if(i==8 && h>=7)   
			cout << "   $$        < 7.  "<< names[7]<<"      >         $$" << endl;
		else if(i==9 && h>=8)   
			cout << "   $$        < 8.  "<< names[8]<<"      >         $$" << endl;
		else if(i==10 && h>=9)
			cout << "   $$        < 9.  "<< names[9]<<"      >         $$" << endl;
		if(state=="betting2"){
			cout << "   $$                                  $$" << endl;
        	cout << "   $$                                  $$" << endl;
        	cout << "   $$        *  BET ["<<j<<"]             $$" << endl;
        	cout << "   $$                                  $$" << endl;
        	cout << "   $$                        begin     $$" << endl;
        	cout << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
        }
		else if(state =="betting3"){
			cout << "   $$                                  $$" << endl;
        	cout << "   $$                                  $$" << endl;
        	cout << "   $$        *  BET [    ]             $$" << endl;
        	cout << "   $$                                  $$" << endl;
        	cout << "   $$                        begin     $$" << endl;
        	cout << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
        	do{
        		gotoxy(21,5);
        		cout<<"    ";
        		gotoxy(21,5);
        		cin>>j;
			}while(j<0 || j>s);
        	state="betting2";
        }
	}
	else if (state=="betting4"){
		cout << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" <<"  Total money:"<< s  << endl;
    	cout << "   $$                                  $$" << endl;
		if(i==1 && h>=0)
			cout << "   $$        < 0.  "<< names[0]<<"      >         $$" << endl;
		else if(i==2 && h>=1)
			cout << "   $$        < 1.  "<< names[1]<<"      >         $$" << endl;
		else if(i==3 && h>=2)
			cout << "   $$        < 2.  "<< names[2]<<"      >         $$" << endl;
		else if(i==4 && h>=3)
			cout << "   $$        < 3.  "<< names[3]<<"      >         $$" << endl;
		else if(i==5 && h>=4)
			cout << "   $$        < 4.  "<< names[4]<<"      >         $$" << endl;
		else if(i==6 && h>=5)     
			cout << "   $$        < 5.  "<< names[5]<<"      >         $$" << endl;
		else if(i==7 && h>=6)
			cout << "   $$        < 6.  "<< names[6]<<"      >         $$" << endl;
		else if(i==8 && h>=7)
			cout << "   $$        < 7.  "<< names[7]<<"      >         $$" << endl;
		else if(i==9 && h>=8)
			cout << "   $$        < 8.  "<< names[8]<<"      >         $$" << endl;
		else if(i==10 && h>=9)
			cout << "   $$        < 9.  "<< names[9]<<"      >         $$" << endl;
        cout << "   $$                                  $$" << endl;
        cout << "   $$                                  $$" << endl;
        cout << "   $$           BET ["<<j<<"]             $$" << endl;
        cout << "   $$                                  $$" << endl;
        cout << "   $$                      * begin     $$" << endl;
        cout << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;	
	}
}


//====================================================================================================================================betting result scene output
int screenr(int hb,int s,int ranking[],int h){
	int ss=0;
	int hh=h;
	if(h>3){
		hh=3;
	}
	cout << "   ==" << endl;
	for (int i=0;i<hh;i++){
		cout << "   ==        "  <<   ranking[i]     <<"   ";
		if(ranking[i]==0){
			h0.get_name();
		}
		if(ranking[i]==1){
			h1.get_name();
		}
		if(ranking[i]==2){
			h2.get_name();
		}
		if(ranking[i]==3){
			h3.get_name();
		}
		if(ranking[i]==4){
			h4.get_name();
		}
		if(ranking[i]==5){
			h5.get_name();
		}
		if(ranking[i]==6){
			h6.get_name();
		}
		if(ranking[i]==7){
			h7.get_name();
		}
		if(ranking[i]==8){
			h8.get_name();
		}
		if(ranking[i]==9){
			h9.get_name();
		}
		cout << endl;
	}
	cout << "   ==" << endl;
	cout << "   ==" << endl;
	if ((hb-1 != ranking[0]) && (hb-1 != ranking[1]) && (hb-1 != ranking[2]) )
	{
		cout << "   ==            You lost!" << endl;
	}
	else if (hb-1 == ranking[0])
	{
		cout << "   ==            You Won!" << endl;	
	}
	else
	{
		cout << "   ==             Eeeeeeeeeh..." << endl;
		cout << "   ==             You tried!?" << endl;
		cout << "   ==             Keep Trying!!!" << endl;
	}
	cout << "   ==   PRESS ANYTHING TO CONTINUE" << endl;
	if ((hb-1 != ranking[0]) && (hb-1 != ranking[1]) && (hb-1 != ranking[2]) )
	{
		ss=-s;
	}
	else if (hb-1 == ranking[0])
	{
		ss=s*2;	
	}
	return ss;
}

//====================================================================================================================================checking if a key is pressed
int input(char keypressed){
keypressed=' ';
while(kbhit()){
	keypressed=getch();
	while(kbhit())
	keypressed=getch();
}
return keypressed;
}



int main(){
    srand(time(0));
    int ranking[10];
    char keypressed='i';
    int delaytime=60;
    int sum=100;
    int bet;
    int hbet=1;
    bool fl2=true;
    short int m;
    int h=4;//number of horses
    int r=10;//number of rounds 
        //object initialization
        h0.set_id(0);
        h1.set_id(1);
        h2.set_id(2);
        h3.set_id(3);
        h4.set_id(4);
        h5.set_id(5);
        h6.set_id(6);
        h7.set_id(7);
        h8.set_id(8);
        h9.set_id(9);
		string names[10] = {"Blitz", "Bolt", "Goliath", "Hercules", "Rogue", "Danger", "Raider", "Storm", "Nitro","Hulk"};
		string state="start";
    while (1){
        if (state=="start")//hapens only once
        {
            system ("CLS");//clear screen
			screen(state,h,r);
            keypressed=input(keypressed);
        	Sleep(delaytime);
        	if(keypressed!=' ')
            	state="begin1";
        }
        else if(state=="bad_end"){
        	system ("CLS");
        	cout<<"LOSER";
        	Sleep(5000);
        	return 5;
		}
		else if(state != "exit"){
        	//==================================================================================================================================== betting output screen
			if(state=="betting" || state == "betting2" || state == "betting3" || state == "betting4"){
				if (keypressed != ' '){
					system ("CLS");
					screenb(state,hbet,bet,sum,names,h);
        		}
			}
			//==================================================================================================================================== result output screen
        	else if (state=="results"){
				if (keypressed !=' '){
				system ("CLS");
				cout << "   ======================================" << endl;
				sum+=screenr(hbet,bet,ranking,h);
        		cout << "   ======================================" << endl;
        		}
        	}
			//==================================================================================================================================== main output screen
			else{
				if (keypressed !=' '){
				system ("CLS");
				cout << "   ======================================" << endl;
				screen(state,h,r);
        		cout << "   ======================================" << endl;
        		}
			}
        	//====================================================================================================================================scene map
        	keypressed=input(keypressed);
			if(keypressed!=' '){	
				switch(keypressed)
				{
					case 72://=============================up
						if(state=="begin1")
    						state="begin3";
    					else if (state=="begin3")
    						state="begin2";
    					else if (state=="begin2")
    						state="begin1";
    						else if(state=="game0")
    						state="game2";
    					else if (state=="game1")
    						state="game0";
    					else if(state=="game2")
    						state="game1";
    					else if (state=="betting2")
    						state="betting";
    					else if (state=="betting4")
    						state="betting2";
						break;
					case 77://=============================right
						if(state=="game0" && h<10 )
							h++;
						else if (state=="game1" && r<20)
							r++;
						else if (state=="betting" && hbet<h)
							hbet++;
						break;
					case 80://=============================down
						if(state=="begin1")
    						state="begin2";
    					else if (state=="begin3")
    						state="begin1";
    					else if(state=="begin2")
    						state="begin3";
    					else if(state=="game0")
    						state="game1";
    					else if (state=="game1")
    						state="game2";
    					else if(state=="game2")
    						state="game0";
    					else if (state=="betting")
    						state="betting2";
    					else if (state=="betting2")
    						state="betting4";
						break;
					case 75://=============================left
						if(state=="game0" && h>1 )
							h--;
						else if (state=="game1" && r>1)
							r--;
						else if (state=="betting" && hbet>1)
							hbet--;
						break;
					case 13://=============================enter
						if (state=="begin1")
							state="game0";
						else if (state=="begin2")
							state="credits";
						else if(state=="begin3")
							return 0;
						else if (state=="game2")
						{
							state="betting";
							random_shuffle(&names[0],&names[10]);
							h0.set_name(names[0]);
        					h1.set_name(names[1]);
        					h2.set_name(names[2]);
        					h3.set_name(names[3]);
        					h4.set_name(names[4]);
        					h5.set_name(names[5]);
        					h6.set_name(names[6]);
        					h7.set_name(names[7]);
        					h8.set_name(names[8]);
        					h9.set_name(names[9]);
						}
						else if (state=="credits")
							state="begin1";
						else if (state=="betting2")
    						state="betting3";
    					else if (state=="betting4")
    						state="race0";
    					else if (state=="results")
							if(sum != 0)
							{
								state="begin1";
							}
							else 
							{
								state="bad_end";	
							}
						break;
				}
        	}
		}
		//====================================================================================================================================main race logic initialization
		if (state=="race0")
		{
        	h0.set_possition(0);
        	h1.set_possition(0);
        	h2.set_possition(0);
        	h3.set_possition(0);
        	h4.set_possition(0);
        	h5.set_possition(0);
        	h6.set_possition(0);
        	h7.set_possition(0);
        	h8.set_possition(0);
        	h9.set_possition(0);
        	h0.stats ((49+(rand() % 50) + 1),(49+(rand() % 50) + 1),(49+(rand() % 50) + 1));
        	h1.stats ((49+(rand() % 50) + 1),(49+(rand() % 50) + 1),(49+(rand() % 50) + 1));
        	h2.stats ((49+(rand() % 50) + 1),(49+(rand() % 50) + 1),(49+(rand() % 50) + 1));
        	h3.stats ((49+(rand() % 50) + 1),(49+(rand() % 50) + 1),(49+(rand() % 50) + 1));
        	h4.stats ((49+(rand() % 50) + 1),(49+(rand() % 50) + 1),(49+(rand() % 50) + 1));
        	h5.stats ((49+(rand() % 50) + 1),(49+(rand() % 50) + 1),(49+(rand() % 50) + 1));
        	h6.stats ((49+(rand() % 50) + 1),(49+(rand() % 50) + 1),(49+(rand() % 50) + 1));
        	h7.stats ((49+(rand() % 50) + 1),(49+(rand() % 50) + 1),(49+(rand() % 50) + 1));
        	h8.stats ((49+(rand() % 50) + 1),(49+(rand() % 50) + 1),(49+(rand() % 50) + 1));
        	h9.stats ((49+(rand() % 50) + 1),(49+(rand() % 50) + 1),(49+(rand() % 50) + 1));
        	short int fl3=0;
        	int tp=0;
        	int place[10]={0,0,0,0,0,0,0,0,0,0};
			int i=0;
			int gk=0;
        	//====================================================================================================================================race scene and logic
			while(fl3==0){
				i++;
				system ("CLS");
				int ch=0;
				
				cout << "   ==============================================================" << endl;
				if (h>=1)
				{
					placement(h0.id,r,h0.possition);
				}
				if (h>=2)
				{
					placement(h1.id,r,h1.possition);
				}
				if (h>=3)
				{
					placement(h2.id,r,h2.possition);
				}
				if (h>=4)
				{
					placement(h3.id,r,h3.possition);
				}
				if (h>=5)
				{
					placement(h4.id,r,h4.possition);
				}
				if (h>=6)
				{
					placement(h5.id,r,h5.possition);
				}
				if (h>=7)
				{
					placement(h6.id,r,h6.possition);
				}
				if (h>=8)
				{
					placement(h7.id,r,h7.possition);
				}
				if (h>=9)
				{
					placement(h8.id,r,h8.possition);
				}
				if (h==10)
				{
					placement(h9.id,r,h9.possition);
				}
        		cout << "   ==============================================================" << endl;
        		Sleep(1000);
        		if (h0.move_forward(i,(rand() % 100) + 1)){
        			if(h0.possition<r)
						h0.set_possition(h0.possition+1);
				}
				if (h1.move_forward(i,(rand() % 100) + 1)){
        			if(h1.possition<r)
						h1.set_possition(h1.possition+1);
				}
				if (h2.move_forward(i,(rand() % 100) + 1)){
        			if(h2.possition<r)
						h2.set_possition(h2.possition+1);
				}
				if (h3.move_forward(i,(rand() % 100) + 1)){
        			if(h3.possition<r)
						h3.set_possition(h3.possition+1);
				}
				if (h4.move_forward(i,(rand() % 100) + 1)){
        			if(h4.possition<r)
						h4.set_possition(h4.possition+1);
				}
				if (h5.move_forward(i,(rand() % 100) + 1)){
        			if(h5.possition<r)
						h5.set_possition(h5.possition+1);
				}
				if (h6.move_forward(i,(rand() % 100) + 1)){
        			if(h6.possition<r)
						h6.set_possition(h6.possition+1);
				}
				if (h7.move_forward(i,(rand() % 100) + 1)){
        			if(h7.possition<r)
						h7.set_possition(h7.possition+1);
				}
				if (h8.move_forward(i,(rand() % 100) + 1)){
        			if(h8.possition<r)
						h8.set_possition(h8.possition+1);
				}
				if (h9.move_forward(i,(rand() % 100) + 1)){
        			if(h9.possition<r)
						h9.set_possition(h9.possition+1);
				}
				//====================================================================================================================================finish line check
				if((h0.possition==r) && place[0]==0 && h>=1){
					ranking[gk]=h0.id;
					gk++;
					place[0]=1;
				}
				if((h1.possition==r) && place[1]==0 && h>=2){
					ranking[gk]=h1.id;
					gk++;
					place[1]=1;
				}
				if((h2.possition==r) && place[2]==0 && h>=3){
					ranking[gk]=h2.id;
					gk++;
					place[2]=1;
				}
				if((h3.possition==r) && place[3]==0 && h>=4){
					ranking[gk]=h3.id;
					gk++;
					place[3]=1;
				}
				if((h4.possition==r) && place[4]==0 && h>=5){
					ranking[gk]=h4.id;
					gk++;
					place[4]=1;
				}
				if((h5.possition==r) && place[5]==0 && h>=6){
					ranking[gk]=h5.id;
					gk++;
					place[5]=1;
				}
				if((h6.possition==r) && place[6]==0 && h>=7){
					ranking[gk]=h6.id;
					gk++;
					place[6]=1;
				}
				if((h7.possition==r) && place[7]==0 && h>=8){
					ranking[gk]=h7.id;
					gk++;
					place[7]=1;
				}
				if((h8.possition==r) && place[8]==0 && h>=9){
					ranking[gk]=h8.id;
					gk++;
					place[8]=1;
				}
				if((h9.possition==r) && place[9]==0 && h==10){
					ranking[gk]=h9.id;
					gk++;
					place[9]=1;
				}
				if(gk==h || (i==(r*2)))
					fl3=1;
        	}
        	//====================================================================================================================================ranking mistake check and fix
			if(gk<h){
				for (int ii=0;i<h;i++){
					if(place[ii]==0){
						place[ii]=1;
						if(ii==0)
							ranking[gk]=h0.id;
						else if(ii==1)
							ranking[gk]=h1.id;
						else if(ii==2)
							ranking[gk]=h2.id;
						else if(ii==3)
							ranking[gk]=h3.id;
						else if(ii==4)
							ranking[gk]=h4.id;
						else if(ii==5)
							ranking[gk]=h5.id;
						else if(ii==6)
							ranking[gk]=h6.id;
						else if(ii==7)
							ranking[gk]=h7.id;
						else if(ii==8)
							ranking[gk]=h8.id;
						else if(ii==9)
							ranking[gk]=h9.id;
						gk++;
					}
				}
			}
			state="results";
		}
    }
    return 0;
}
