class TPlayer
{
public:
int PosX;
int PosY;
int pman;
int life;
int score;
bool LeftKeyDown,RightKeyDown,UpKeyDown,DownKeyDown;
Graphics::TBitmap *Man;
TPlayer()
{
Man=new Graphics::TBitmap();
Man->LoadFromFile("pic\\pman_1.bmp");
Man->Transparent=true;
PosX=300;
PosY=450;
pman=1;
life=3;
score=0;
}
void __fastcall LoadImagea()
{
if(LeftKeyDown) pman=3;
if(RightKeyDown)pman=4;
if(DownKeyDown) pman=2;
if(UpKeyDown)   pman=1;
Man->LoadFromFile("pic\\pman_"+ IntToStr(pman)+".bmp");
if (PosX%15 && LeftKeyDown)
Man->LoadFromFile("pic\\pman_3_2.bmp");
if (PosX%15 && RightKeyDown)
Man->LoadFromFile("pic\\pman_4_2.bmp");
if (PosY%15 && UpKeyDown)
Man->LoadFromFile("pic\\pman_1_2.bmp");
if (PosY%15 && DownKeyDown)
Man->LoadFromFile("pic\\pman_2_2.bmp");
Man->Transparent=true;

}

void __fastcall PaintOn(TCanvas *Canvas)
{
Canvas->Draw(PosX,PosY,Man);
}

void __fastcall PlayerMove(int a[][21])
{
if (LeftKeyDown){
        if(
        (PosX%30!=0||(a[PosX/30-1][PosY/30]==0||a[PosX/30-1][PosY/30]==1||a[PosX/30-1][PosY/30]==16) &&
        (PosY%30==0||(a[PosX/30-1][PosY/30+1]==0||a[PosX/30-1][PosY/30+1]==1||a[PosX/30-1][PosY/30+1]==16))))
                {
                PosX-=5;
                }
}
if (RightKeyDown){
        if(
        (a[PosX/30+1][PosY/30]==0||a[PosX/30+1][PosY/30]==1||a[PosX/30+1][PosY/30]==16)&&
        (PosY%30==0||(a[PosX/30+1][PosY/30+1]==0||a[PosX/30+1][PosY/30+1]==1||a[PosX/30+1][PosY/30+1]==16)))
                {
                PosX+=5;
                }
}
if (DownKeyDown){
        if((a[PosX/30][PosY/30+1]==0||a[PosX/30][PosY/30+1]==1||a[PosX/30][PosY/30+1]==16)
        && (PosX%30==0||(a[PosX/30+1][PosY/30+1]==0||a[PosX/30+1][PosY/30+1]==1||a[PosX/30+1][PosY/30+1]==16)))
                {
                PosY+=5;
                }
}
if (UpKeyDown){
        if(PosY%30!=0||(a[PosX/30][PosY/30-1]==0||a[PosX/30][PosY/30-1]==1||a[PosX/30][PosY/30-1]==16)
        &&(PosX%30==0||(a[PosX/30+1][PosY/30-1]==0||a[PosX/30+1][PosY/30-1]==1||a[PosX/30+1][PosY/30-1]==16)))
                {
                PosY-=5;
                }
}

if (PosX==0 && PosY==270 && LeftKeyDown)PosX=630;
if (PosX==600 && PosY==270 && RightKeyDown)PosX=0;


}



};