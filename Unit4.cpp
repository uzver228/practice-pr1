//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "stdio.h"

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
AnsiString** lddata;
int rowsCount = 0;

void __fastcall TForm4::Edit1Change(TObject *Sender)
{
    //TODO: LinearSearch
    int showcounter=1;
    AnsiString keyWord = Edit1->Text;

    for(int i = 1; i < StringGrid1->RowCount; i++)
        for(int j = 0; j < 9; j++)
            StringGrid1->Cells[j][i] = "";

    for(int i = 0; i < StringGrid1->RowCount; i++)
        for(int j = 0; j < 9; j++)
            if(keyWord == lddata[i][j]) {
                for(int k = 0; k < 9; k++)
                    StringGrid1->Cells[k][showcounter] = lddata[i][k];
                showcounter++;
            }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{
    StringGrid1->Cells[0][0] = "№ картки";
    StringGrid1->Cells[1][0] = "ПІБ";
    StringGrid1->Cells[2][0] = "Рік нар.";
    StringGrid1->Cells[3][0] = "Стать";
    StringGrid1->Cells[4][0] = "Адреса";
    StringGrid1->Cells[5][0] = "Місце роботи";
    StringGrid1->Cells[6][0] = "Особ. облік";
    StringGrid1->Cells[7][0] = "Відмітки";

    char buf[100];
    rowsCount = 0;
    FILE *f;

    f = fopen("data.txt", "rt");

    while(!feof(f)) {
        fgets(buf, 100, f);
        rowsCount++;
    }
    fclose(f);
    f = fopen("data.txt", "rt");

    StringGrid1->RowCount = rowsCount/8 + 1;
    lddata = new AnsiString*[StringGrid1->RowCount];

    for(int i = 0; i < StringGrid1->RowCount; i++)
        lddata[i] = new AnsiString[9];

    for(int i = 0; i < StringGrid1->RowCount; i++)
        for(int j = 0; j < 9; j++) {
            fgets(buf, 100, f);
            buf[strlen(buf) - 1] = '\0';
            lddata[i][j] = buf;
        }

    //outout to grid
    /*
    for(int i = 1; i <= StringGrid1->RowCount; i++)
        for(int j = 0; j < 9; j++)
            StringGrid1->Cells[j][i] = lddata[i-1][j];
    */

    fclose(f);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
    for(int i = 0; i < StringGrid1->RowCount; i++)
        delete []lddata[i];
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
    Form4->Close();        
}
//---------------------------------------------------------------------------

