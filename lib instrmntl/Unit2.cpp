//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int PosM=1;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
AddFontResourceA("font\\Mistral.ttf");
Form2->Canvas->Brush->Color=clBlack;
Form2->Canvas->Rectangle(0,0,Form2->Width,Form2->Height);
Form2->Canvas->Font->Name="Mistral";
Form2->Canvas->Font->Size=100;
Form2->Canvas->Font->Color=clRed;
Form2->Canvas->TextOutA(Form2->Width/7+30,50,"BABY");
Form2->Canvas->Font->Size=40;
Form2->Canvas->Font->Color=clRed;
Form2->Canvas->TextOutA(Form2->Width/3,290,"GO");
if (sound)
Form2->Canvas->TextOutA(Form2->Width/3,360,"saund ON");
else
Form2->Canvas->TextOutA(Form2->Width/3,360,"saund OFF");
Form2->Canvas->TextOutA(Form2->Width/3,420,"END");
if (PosM==1){
Form2->Canvas->Font->Color=clWhite;
Form2->Canvas->TextOutA(Form2->Width/3,290,"GO");
}
if (PosM==2){
Form2->Canvas->Font->Color=clWhite;
if (sound)
Form2->Canvas->TextOutA(Form2->Width/3,360,"saund ON");
else
Form2->Canvas->TextOutA(Form2->Width/3,360,"saund OFF");}
if (PosM==3){
Form2->Canvas->Font->Color=clWhite;
Form2->Canvas->TextOutA(Form2->Width/3,420,"END");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
Form1->Timer3->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{

if (Key==VK_UP)
        {
        PosM--;
        if (PosM==0)
        PosM=3;
}

if (Key==VK_DOWN)
{
        PosM++;
        if (PosM==4)
        PosM=1;
}
if (Key==VK_RETURN)
{
        if (PosM==1)
        {Form2->Close();}
if (PosM==2){if (sound) sound=false; else sound=true;}
if (PosM==3) {Form2->Close();Form1->Close();}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
sound=true;
Form2->Top=Screen->Height/4;
Form2->Left=Screen->Width/4;
Form1->Top=Screen->Height/4;
Form1->Left=Screen->Width/4;
}
//---------------------------------------------------------------------------
