class TBot
{
public:
int PosX;
int PosY;
int pbot;
int way;
int x1,y1;
int x2,y2;
int b[21][21];
int c[21][21];
int PX,PY;
int side;
bool dead;
bool escape;
bool BotLeft,BotRight,BotUp,BotDown,BotMove;
Graphics::TBitmap *Man;
TBot()
{
Man=new Graphics::TBitmap();
Man->LoadFromFile("pic\\Blinky_1.bmp");
Man->Transparent=true;
PosX=300;
PosY=240;
pbot=1;
side=0;
BotMove=true;
}
void __fastcall LoadImagea()
{
if (!dead){
        if(BotLeft) pbot=3;
        if(BotRight)pbot=4;
        if(BotUp) pbot=1;
        if(BotDown)pbot=2;
Man->LoadFromFile("pic\\Blinky_"+ IntToStr(pbot)+".bmp");
if (escape)
Man->LoadFromFile("pic\\Blinky_5.bmp");
}
if (dead){
        if(BotLeft) pbot=3;
        if(BotRight)pbot=4;
        if(BotUp) pbot=1;
        if(BotDown)pbot=2;
        Man->LoadFromFile("pic\\orb_"+ IntToStr(pbot)+".bmp");
        }

Man->Transparent=true;
}
void __fastcall PaintOn(TCanvas *Canvas)
{
Canvas->Draw(PosX,PosY,Man);
}

void __fastcall PaintY(TCanvas *Canvas)
{
   for(int i=0;i<21;i++)
   {
   for(int j=0;j<21;j++)
   {
    Canvas->Brush->Color=b[i][j]*500;
    Canvas->Rectangle(i*30,j*30,i*30+30,j*30+30);  // 30 = размер клетки в пикселях
    Canvas->Font->Color=clWhite;
    Canvas->TextOutA(i*30,j*30,b[i][j]);

    if(c[i][j]==20)
     {
     Canvas->Brush->Color=clWhite;
     Canvas->Brush->Style=bsCross;
     Canvas->Rectangle(i*30,j*30,i*30+30,j*30+30);  // 30 = размер клетки в пикселях
     Canvas->Brush->Style=bsClear;
     }
   }
   }

}

void __fastcall FindWay(int PacX,int PacY, int a[][21])
{
x2=PacX/30, y2=PacY/30;
x1=PosX/30, y1=PosY/30;
for(int i=0;i<21;i++)
 {
 for(int j=0;j<21;j++)
 {
  b[i][j]=0;
  c[i][j]=0;

  if(a[i][j]==4||a[i][j]==2||a[i][j]==3||
     a[i][j]==5||a[i][j]==6||a[i][j]==7||
     a[i][j]==8||a[i][j]==9||a[i][j]==10||
     a[i][j]==11||a[i][j]==12||a[i][j]==13||
     a[i][j]==14||a[i][j]==15||a[i][j]==16
  )
   b[i][j]=200;
 }
 }

 b[x1][y1]=1;


 /****************** СОЗДАНИЕ КАРТЫ ПОТЕНЦИАЛОВ *****************************/

 for(int k=0;k<42;k++)
 {
 for(int i=0;i<21;i++)
 {
 for(int j=0;j<21;j++)
 {
  if(b[i][j]==0 && b[i+1][j]==k+1 && i+1<20 && a[i][j]==0||a[i][j]==1)
    { b[i][j]=k+2;}
  if(b[i][j]==0 && b[i-1][j]==k+1 && i-1>0 && a[i][j]==0||a[i][j]==1)
    { b[i][j]=k+2;}
  if(b[i][j]==0 && b[i][j+1]==k+1 && j+1<20 && a[i][j]==0||a[i][j]==1)
    { b[i][j]=k+2;}
  if(b[i][j]==0 && b[i][j-1]==k+1 && j-1>0 && a[i][j]==0||a[i][j]==1)
    { b[i][j]=k+2;}
 }
 }
 }

 /***************************************************************************/

 int x3=x2;
 int y3=y2;

 for(int i=0;i<b[x2][y2];i++)
 {
 if(a[x2][y2]!=1)
  c[x2][y2]=20;

 if(i%2)
 {
  if(b[x3][y3+1]<b[x3][y3])
    { y3++;  goto bc; }
  if(b[x3][y3-1]<b[x3][y3])
    { y3--;  goto bc; }
  if(b[x3+1][y3]<b[x3][y3])
    { x3++;  goto bc; }
  if(b[x3-1][y3]<b[x3][y3])
    { x3--;  goto bc; }
 }
 else
 {
  if(b[x3+1][y3]<b[x3][y3])
    { x3++;  goto bc; }
  if(b[x3-1][y3]<b[x3][y3])
    { x3--;  goto bc; }
  if(b[x3][y3+1]<b[x3][y3])
    { y3++;  goto bc; }
  if(b[x3][y3-1]<b[x3][y3])
    { y3--;  goto bc; }
 }
   bc:
     c[x3][y3]=20;
 }

}
void __fastcall Move()
{
if (BotMove){
 if(c[x1+1][y1]==20)
  {
  BotRight=true;
  c[x1][y1]=0;
  x1++;
  PX=x1;
  }
else if(c[x1-1][y1]==20)
  {
  BotLeft=true;
  c[x1][y1]=0;
  x1--;
  PX=x1;
  }
else if(c[x1][y1+1]==20)
  {
  BotDown=true;
  c[x1][y1]=0;
  y1++;
  PY=y1;
  }
else   if(c[x1][y1-1]==20)
  {
  BotUp=true;
  c[x1][y1]=0;
  y1--;
  PY=y1;
  }
}
if (BotRight)
{
        if (PosX<PX*30){
        PosX+=5;
        BotMove=false;
        side=3;
        }
        if(PosX==PX*30){
        BotMove=true;
        BotRight=false;
        }
}

else if (BotLeft)
{
        if (PosX>PX*30){
        PosX-=5;
        BotMove=false;
        side=2;
        }
        if(PosX==PX*30){
        BotMove=true;
        BotLeft=false;
         }
}

else if (BotDown)
{
        if (PosY<PY*30){
        PosY+=5;
        BotMove=false;
        side=1;
        }
        if(PosY==PY*30){
        BotMove=true;
        BotDown=false;
         }
}

else if (BotUp)
{
        if (PosY>PY*30){
        PosY-=5;
        BotMove=false;
        side=0;
        }
        if(PosY==PY*30){
        BotMove=true;
        BotUp=false;
        }
}

if (PosX==0 && PosY==270 && side==2)PosX=630;
if (PosX==600 && PosY==270 && side==3)PosX=0;


}


void __fastcall FreeMove( int a[][21])
{
Randomize();
if (side==2){//двигается влево
                if(
        (PosX%30!=0||(a[PosX/30-1][PosY/30]==0||a[PosX/30-1][PosY/30]==1||a[PosX/30-1][PosY/30]==16) &&
        (PosY%30==0||(a[PosX/30-1][PosY/30+1]==0||a[PosX/30-1][PosY/30+1]==1||a[PosX/30-1][PosY/30+1]==16)))
           )
                {
                pbot=3;
                PosX-=5;
                }
           else side=random(2);
        }
        if (side==3){//двигается вправо
                if(
        (a[PosX/30+1][PosY/30]==0||a[PosX/30+1][PosY/30]==1||a[PosX/30+1][PosY/30]==16)&&
        (PosY%30==0||(a[PosX/30+1][PosY/30+1]==0||a[PosX/30+1][PosY/30+1]==1||a[PosX/30+1][PosY/30+1]==16)))
                {
                pbot=4;
                PosX+=5;
                }
                else side=random(2);
        }

        if (side==1){//вниз
                if(
        (a[PosX/30][PosY/30+1]==0||a[PosX/30][PosY/30+1]==1||a[PosX/30][PosY/30+1]==16)&&
        (PosX%30==0||(a[PosX/30+1][PosY/30+1]==0||a[PosX/30+1][PosY/30+1]==1||a[PosX/30+1][PosY/30+1]==16)))
                {
                pbot=2;
                PosY+=5;
                }
                else side=random(2)+2;
        }
        if (side==0){//вверх
         if(PosY%30!=0||(a[PosX/30][PosY/30-1]==0||a[PosX/30][PosY/30-1]==1||a[PosX/30][PosY/30-1]==16)&&
        (PosX%30==0||(a[PosX/30+1][PosY/30-1]==0||a[PosX/30+1][PosY/30-1]==1||a[PosX/30+1][PosY/30-1]==16)))
                {
                pbot=1;
                PosY-=5;
                }
                else side=random(2)+2;
        }

if (PosX==0 && PosY==270 && side==2)PosX=630;
if (PosX==600 && PosY==270 && side==3)PosX=0;
}


};
TBot bot[10];
