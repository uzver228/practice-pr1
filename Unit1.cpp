//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    AnsiString login = Edit1->Text, password = Edit2->Text;
    AnsiString auLogin = "test1", auPassword = "test1";
    if(login == auLogin && password == auPassword) {
        Edit1->Visible = false;
        Edit2->Visible = false;
        Button1->Visible = false;
        Button2->Visible = false;
        Image1->Visible = false;
        Label1->Visible = false;
        Label2->Visible = false;
        N1->Visible = true;
        N2->Visible = true;
        N3->Visible = true;
        Label3->Visible = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    N1->Visible = false;
    N2->Visible = false;
    N3->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
    Form2 = new TForm2(this);
    Form2->ShowModal();
    delete Form2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
    Form3 = new TForm3(this);
    Form3->ShowModal();
    delete Form3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
    Form4 = new TForm4(this);
    Form4->ShowModal();
    delete Form4;
}
//---------------------------------------------------------------------------

