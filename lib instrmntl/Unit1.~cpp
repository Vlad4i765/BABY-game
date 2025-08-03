//---------------------------------------------------------------------------
#include <stdio.h>
#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPlayer pacman;//Класс Игрока
TForm1 *Form1;
Graphics::TBitmap*_Point;//
Graphics::TBitmap*Bonus;//

Graphics::TBitmap*background;//
Graphics::TBitmap*Horizontal;
Graphics::TBitmap*Vertical;

Graphics::TBitmap*angle_LV;
Graphics::TBitmap*angle_RV;
Graphics::TBitmap*angle_RD;
Graphics::TBitmap*angle_LD;

Graphics::TBitmap*arc_down;
Graphics::TBitmap*arc_right;
Graphics::TBitmap*arc_left;
Graphics::TBitmap*arc_up;

Graphics::TBitmap*arc2_down;
Graphics::TBitmap*arc2_right;
Graphics::TBitmap*arc2_left;
Graphics::TBitmap*arc2_up;


Graphics::TBitmap*BG;//Задний буффер
int lvl=1;
int b[21][21]={{20,20,20,20,20,20,20,20,2,0,2,20,20,20,20,20,20,20,20,20,20},
{4,3,3,3,3,3,7,20,2,0,2,20,4,3,3,3,13,3,3,3,7},
{2,0,16,0,0,0,2,20,2,0,2,20,2,0,0,16,10,0,0,0,2},
{2,0,9,0,9,0,2,20,2,0,2,20,2,0,9,0,0,0,9,0,2},
{2,0,10,0,10,0,5,3,6,0,5,3,6,0,5,3,8,0,2,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,2},
{2,0,9,0,11,3,13,3,8,0,11,3,8,0,9,0,11,3,15,0,2},
{2,0,2,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,2,0,2},
{2,0,10,0,9,0,10,0,4,3,7,0,9,0,10,0,9,0,10,0,2},
{2,0,0,0,2,0,0,0,2,0,2,0,2,0,0,0,2,0,0,0,2},
{12,3,8,0,12,3,8,0,0,0,2,0,12,3,8,0,12,3,8,0,2},
{2,0,0,0,2,0,0,0,2,0,2,0,2,0,0,0,2,0,0,0,2},
{2,0,9,0,10,0,9,0,5,3,6,0,10,0,9,0,10,0,9,0,2},
{2,0,2,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,2,0,2},
{2,0,10,0,11,3,14,3,8,0,11,3,8,0,10,0,11,3,15,0,2},
{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,2},
{2,0,9,0,9,0,4,3,7,0,4,3,7,0,4,3,8,0,2,0,2},
{2,0,10,0,10,0,2,20,2,0,2,20,2,0,10,0,0,0,10,0,2},
{2,0,16,0,0,0,2,20,2,0,2,20,2,0,0,16,9,0,0,0,2},
{5,3,3,3,3,3,6,20,2,0,2,20,5,3,3,3,14,3,3,3,6},
{20,20,20,20,20,20,20,20,2,0,2,20,20,20,20,20,20,20,20,20,20}}
;
int a[21][21];
int p[21][21];
int Count_Bot=0;
bool pause;
bool find;
int EatBot=0;
int lvl_point=0;
int lvl_time=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
find=true;
for (int i=0;i<21;i++)
        for(int j=0;j<21;j++)
        a[i][j]=b[i][j];
for (int i=0;i<21;i++)
        for(int j=0;j<21;j++){
                p[i][j]=a[i][j];
                if (p[i][j]==0 )p[i][j]=1;}
                p[11][9]=0;
                p[10][9]=0;
                p[9][9]=0;
                p[10][8]=0;

_Point = new Graphics::TBitmap();
_Point->LoadFromFile("pic\\Point.bmp");
Bonus = new Graphics::TBitmap();
Bonus->LoadFromFile("pic\\bonus.bmp");
Horizontal = new Graphics::TBitmap();
Horizontal->LoadFromFile("pic\\horizontal.bmp");

Vertical = new Graphics::TBitmap();
Vertical->LoadFromFile("pic\\vertical.bmp");

angle_LV = new Graphics::TBitmap();
angle_LV->LoadFromFile("pic\\angle_LV.bmp");

angle_RV = new Graphics::TBitmap();
angle_RV->LoadFromFile("pic\\angle_RV.bmp");

angle_LD = new Graphics::TBitmap();
angle_LD->LoadFromFile("pic\\angle_LD.bmp");

angle_RD = new Graphics::TBitmap();
angle_RD->LoadFromFile("pic\\angle_RD.bmp");

arc_down = new Graphics::TBitmap();
arc_down->LoadFromFile("pic\\arc_down.bmp");

arc_right = new Graphics::TBitmap();
arc_right->LoadFromFile("pic\\arc_right.bmp");

arc_left = new Graphics::TBitmap();
arc_left->LoadFromFile("pic\\arc_left.bmp");

arc_up = new Graphics::TBitmap();
arc_up->LoadFromFile("pic\\arc_up.bmp");


arc2_down = new Graphics::TBitmap();
arc2_down->LoadFromFile("pic\\arc2_down.bmp");

arc2_right = new Graphics::TBitmap();
arc2_right->LoadFromFile("pic\\arc2_right.bmp");

arc2_left = new Graphics::TBitmap();
arc2_left->LoadFromFile("pic\\arc2_left.bmp");

arc2_up = new Graphics::TBitmap();
arc2_up->LoadFromFile("pic\\arc2_up.bmp");


background = new Graphics::TBitmap();
background->LoadFromFile("pic\\background.bmp");


BG = new Graphics::TBitmap(); //Задний буффер
BG->Width=Form1->Width;
BG->Height=Form1->Height;
}
//---------------------------------------------------------------------------
void TForm1::DrawMap()
{
 for (int i=0;i<21;i++)
        {
                for (int j=0;j<21;j++)
                {
                        switch (a[i][j])
                        {
                        case 0: BG->Canvas->Draw(i*30,j*30,background) ; break;
                        case 1: BG->Canvas->Draw(i*30,j*30,_Point)     ; break;
                        case 2: BG->Canvas->Draw(i*30,j*30,Horizontal) ; break;
                        case 3: BG->Canvas->Draw(i*30,j*30,Vertical)   ; break;
                        case 4: BG->Canvas->Draw(i*30,j*30,angle_LV)   ; break;
                        case 5: BG->Canvas->Draw(i*30,j*30,angle_RV)   ; break;
                        case 6: BG->Canvas->Draw(i*30,j*30,angle_RD)   ; break;
                        case 7: BG->Canvas->Draw(i*30,j*30,angle_LD)   ; break;
                        case 8: BG->Canvas->Draw(i*30,j*30,arc_down)   ; break;
                        case 9: BG->Canvas->Draw(i*30,j*30,arc_left)   ; break;
                        case 10: BG->Canvas->Draw(i*30,j*30,arc_right) ; break;
                        case 11: BG->Canvas->Draw(i*30,j*30,arc_up)    ; break;
                        case 12: BG->Canvas->Draw(i*30,j*30,arc2_down) ; break;
                        case 13: BG->Canvas->Draw(i*30,j*30,arc2_right); break;
                        case 14: BG->Canvas->Draw(i*30,j*30,arc2_left) ; break;
                        case 15: BG->Canvas->Draw(i*30,j*30,arc2_up)   ; break;
                        case 16: BG->Canvas->Draw(i*30,j*30,Bonus)   ; break;
                        case 20: BG->Canvas->Draw(i*30,j*30,background) ; break;
                        }
                        if (p[i][j]==1)
                           BG->Canvas->Draw(i*30,j*30,_Point);
                        BG->Canvas->Brush->Color=clYellow;
                        BG->Canvas->Rectangle(300,240,330,245);
                }
        }

}
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
DrawMap();
if (Form2->sound)
mciSendString("play sound\\Siren_Sound_Effect.wav ", 0, 0,0);
//bot[0].PaintY(BG->Canvas);
for (int i=0; i<Count_Bot;i++){
        bot[i].PaintOn(BG->Canvas);
        bot[i].LoadImagea();
        }

EatPoint();
pacman.LoadImagea();
pacman.PaintOn(BG->Canvas);
pacman.PlayerMove(a);
dmg();
Nextlvl();
GameOver();

//-------------------------рисуем таблицу очей,жизней и тд.-----------------
BG->Canvas->Brush->Color=clBlack;
BG->Canvas->Rectangle(630,0,830,630);
BG->Canvas->Brush->Color=clBlue;
BG->Canvas->Rectangle(635,0,640,630);
BG->Canvas->Brush->Color=clBlack;
AddFontResourceA("font\\digital-7.ttf");
BG->Canvas->Font->Name="Digital-7";
BG->Canvas->Font->Size=30;
BG->Canvas->Font->Color=clGray;
BG->Canvas->TextOutA(Form1->Width-150,30,"Score:");
BG->Canvas->TextOutA(Form1->Width-150,80,pacman.score);
BG->Canvas->Font->Color=clGreen;
BG->Canvas->TextOutA(Form1->Width-150,130,"LVL:");
BG->Canvas->TextOutA(Form1->Width-150,180,lvl);
BG->Canvas->Font->Color=clBlue;
BG->Canvas->TextOutA(Form1->Width-150,550,"Life: ");
BG->Canvas->TextOutA(Form1->Width-80,550,pacman.life);




Form1->Canvas->Draw(0,0,BG);

}

//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key=='D' || Key==VK_RIGHT){pacman.RightKeyDown=true;pacman.LeftKeyDown=false;pacman.UpKeyDown=false;pacman.DownKeyDown=false;}
if(Key=='A' || Key==VK_LEFT){pacman.LeftKeyDown=true;pacman.RightKeyDown=false;pacman.UpKeyDown=false;pacman.DownKeyDown=false;}
if(Key=='W' || Key==VK_UP){pacman.UpKeyDown=true;pacman.DownKeyDown=false;pacman.RightKeyDown=false;pacman.LeftKeyDown=false;}
if(Key=='S' || Key==VK_DOWN){pacman.DownKeyDown=true;pacman.UpKeyDown=false;pacman.LeftKeyDown=false;pacman.RightKeyDown=false;}
if(Key==VK_F2){NewGame();}
if(Key==VK_PAUSE) {
if(!pause){
pause=true;
        BG->Canvas->Font->Color=clRed;
        BG->Canvas->TextOutA(Form1->Width-150,230,"PAUSE");
        Form1->Canvas->Draw(0,0,BG);
}
else pause=false;
Pause();
}
if(Key==VK_F4)pacman.life--;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key=='D'|| Key==VK_RIGHT){pacman.RightKeyDown=false;}
if(Key=='A'|| Key==VK_LEFT){pacman.LeftKeyDown=false;}
if(Key=='W'|| Key==VK_UP){pacman.UpKeyDown=false;}
if(Key=='S'|| Key==VK_DOWN){pacman.DownKeyDown=false;}
}
//---------------------------------------------------------------------------

void TForm1::EatPoint()
{
        RECT RMan=Rect(pacman.PosX,pacman.PosY,pacman.PosX+30,pacman.PosY+30);
        RECT Rect0=Rect(0,0,0,0);

          for (int i=0;i<21;i++)
        {
                for (int j=0;j<21;j++)
                {
                        switch (p[i][j])
                        {
                        case 1: { RECT Rect2=Rect(i*30,j*30,i*30+10,j*30+10);
                                if (IntersectRect(&Rect0,&RMan,&Rect2)){
                                if (Form2->sound)
                                mciSendString("play sound\\pacman_chomp.wav ", 0, 0,0);
                                p[i][j]=0;
                                pacman.score+=10;
                                lvl_point++;
                                }break;}
                        case 16: { RECT Rect2=Rect(i*30,j*30,i*30+30,j*30+30);
                                if (IntersectRect(&Rect0,&RMan,&Rect2)){
                                if (Form2->sound)
                               mciSendString("play sound\\pacman_eatfruit.wav ", 0, 0,0);
                                p[i][j]=0;
                                a[i][j]=0;
                                find=false;
                                Timer4->Enabled=true;
                                Timer2->Interval=80;
                                for(int i=0;i<Count_Bot;i++)
                                bot[i].escape=true;
                                }break;}
                        }
                }
        }

}



//---------------------------------------------------------------------------



void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
for (int i=0; i<Count_Bot;i++){
if(!bot[i].escape){
bot[i].FindWay(pacman.PosX,pacman.PosY,a);

}
if (bot[i].PosX==300 && bot[i].PosY==240) bot[i].dead=false;
if (bot[i].escape) {
bot[i].FindWay(300,240,a);
bot[i].Move();
}
}
if(find)
FindPacman();
}
//---------------------------------------------------------------------------
void TForm1::FindPacman()
{
RECT RMan=Rect(pacman.PosX-120,pacman.PosY-120,pacman.PosX+30+120,pacman.PosY+30+120);
RECT Rect0=Rect(0,0,0,0);
for (int i=0; i<Count_Bot;i++){
        if(!bot[i].escape ){
        RECT RBOT=Rect(bot[i].PosX,bot[i].PosY,bot[i].PosX+30,bot[i].PosY+30);
        if (IntersectRect(&Rect0,&RMan,&RBOT)){

        bot[i].Move();
        }
        else {bot[i].FreeMove(a);bot[i].BotMove=true;}
        }
        }
}
void TForm1::dmg()
{
RECT RMan=Rect(pacman.PosX,pacman.PosY,pacman.PosX+30,pacman.PosY+30);
RECT Rect0=Rect(0,0,0,0);
for (int i=0; i<Count_Bot;i++){
RECT RBOT=Rect(bot[i].PosX,bot[i].PosY,bot[i].PosX+30,bot[i].PosY+30);
if (IntersectRect(&Rect0,&RMan,&RBOT)){
if(!bot[i].escape){
        if (Form2->sound)
        mciSendString("play sound\\pacman_death.wav ", 0, 0,0);
        pacman.PosX=300;
        pacman.PosY=450;
        bot[i].PosX=300;
        bot[i].PosY=240;
        pacman.life--;
        Count_Bot=-1;
        }
else{
if (!bot[i].dead){
        if (Form2->sound)
        mciSendString("play sound\\Pacman_Eating_Ghost.wav ", 0, 0,0);
        EatBot++;
        pacman.score=pacman.score+(EatBot*200);
        bot[i].dead=true;
        bot[i].FindWay(300,240,a);
        bot[i].Move();
        }
}
}
}
}
void TForm1::GameOver()
{
if (pacman.life==-1)
{
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
Timer4->Enabled=false;
        BG->Canvas->Font->Color=clRed;
        BG->Canvas->Font->Size=90;
        BG->Canvas->TextOutA(Form1->Width/8,Form1->Height/4,"Game over");
        Form1->Canvas->Draw(0,0,BG);

}
}
void TForm1::NewGame()
{
if (Form2->sound)
mciSendString("play sound\\pacman_beginning.wav ", 0, 0,0);
lvl=1;
lvl_point=0;
lvl_time=0;
pacman.PosY=450;
pacman.PosX=300;
Count_Bot=0;
bot[0].PosX=300;
bot[0].PosY=240;
bot[0].side=0;
bot[0].pbot=1;
for (int i=0;i<21;i++)
        for(int j=0;j<21;j++)
        a[i][j]=b[i][j];
for (int i=0;i<21;i++)
        for(int j=0;j<21;j++){
                p[i][j]=a[i][j];
                if (p[i][j]==0 )p[i][j]=1;}
                p[11][9]=0;
                p[10][9]=0;
                p[9][9]=0;
                p[10][8]=0;
pacman.life=3;
pacman.score=0;
Timer3->Enabled=true;
DrawMap();
Form1->Canvas->Draw(0,0,BG);
}

void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
if (Count_Bot<4)
Count_Bot++;
bot[Count_Bot].PosX=300;
bot[Count_Bot].PosY=240;
bot[Count_Bot].side=0;
if (Timer1->Enabled==false){
Timer1->Enabled=true;
Timer2->Enabled=true;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormPaint(TObject *Sender)
{
DrawMap();
BG->Canvas->Brush->Color=clBlack;
BG->Canvas->Rectangle(630,0,830,630);
BG->Canvas->Brush->Color=clBlue;
BG->Canvas->Rectangle(635,0,640,630);
Form1->Canvas->Draw(0,0,BG);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
Timer2->Interval=50;
find=true;
for (int i=0; i<Count_Bot;i++){
bot[i].escape=false;
if (!bot[i].dead){
bot[i].side=0;
bot[i].pbot=1;
EatBot=0;
}
bot[i].dead=false;
}
Timer4->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
Form2->ShowModal();
if (Form2->sound)
mciSendString("play sound\\pacman_beginning.wav ", 0, 0,0);

}
//---------------------------------------------------------------------------
void TForm1::Nextlvl()
{
if (lvl_point==183)
        {
        lvl_point=0;
        lvl++;
        lvl_time+=100;
        Count_Bot=0;
        pacman.PosY=450;
        pacman.PosX=300;
        for (int i=0; i<Count_Bot;i++){
                bot[i].PosX=300;
                bot[i].PosY=240;
                bot[i].side=0;
                bot[i].pbot=1;
                EatBot=0;
                }
        for (int i=0;i<21;i++)
                for(int j=0;j<21;j++)
                a[i][j]=b[i][j];
        for (int i=0;i<21;i++)
                for(int j=0;j<21;j++){
                p[i][j]=a[i][j];
                if (p[i][j]==0 )p[i][j]=1;}
                p[11][9]=0;
                p[10][9]=0;
                p[9][9]=0;
                p[10][8]=0;
                if (lvl_time<7500)
                Timer4->Interval-=lvl_time;
        }
}


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
Timer4->Enabled=false;
//ShowMessage("thx for testing  by name?");
}
//---------------------------------------------------------------------------

void TForm1::Pause()
{
if (pause)
        {
        Timer1->Enabled=false;
        Timer2->Enabled=false;
        Timer3->Enabled=false;
        Timer4->Enabled=false;
        }
else
        {
        Timer1->Enabled=true;
        Timer2->Enabled=true;
        Timer3->Enabled=true;
        Timer4->Enabled=true;
        }
}
