//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <string.h>

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void workswap(int col, int a, int b) {
    for(int i = 0; i <= Form3->StringGrid1->ColCount; i++) {
    AnsiString temp = Form3->StringGrid1->Cells[i][a];
    Form3->StringGrid1->Cells[i][a] = Form3->StringGrid1->Cells[i][b];
    Form3->StringGrid1->Cells[i][b] = temp;
    }
}

void __fastcall TForm3::FormCreate(TObject *Sender)
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
    int rowsCount = 0;
    FILE *f;
    f = fopen("data.txt", "rt");

    while(!feof(f)) {
        fgets(buf, 100, f);
        rowsCount++;
    }
    fclose(f);
    f = fopen("data.txt", "rt");

    StringGrid1->RowCount = rowsCount/8 + 1;

    for(int i = 1; i <= StringGrid1->RowCount; i++)
        for(int j = 0; j < 9; j++) {
            fgets(buf, 100, f);
            buf[strlen(buf) - 1] = '\0';
            StringGrid1->Cells[j][i] = buf;
        }

    fclose(f);
    
}
//---------------------------------------------------------------------------
void __fastcall TForm3::StringGrid1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    char* buf;

    buf = StringGrid1->Cells[ACol][ARow].c_str();

    if(isdigit(buf[0])) {
        for(int i = 1; i <= StringGrid1->RowCount - 1; i++)
        for(int j = 1; j <= StringGrid1->RowCount-i-1; j++)
            if(StrToInt(StringGrid1->Cells[ACol][j]) >
               StrToInt(StringGrid1->Cells[ACol][j+1]))
                workswap(ACol, j, j+1);
    }
    else {
        for(int i = 1; i <= StringGrid1->RowCount - 1; i++)
        for(int j = 1; j <= StringGrid1->RowCount-i-1; j++)
            if(StringGrid1->Cells[ACol][j] > StringGrid1->Cells[ACol][j+1])
                workswap(ACol, j, j+1);
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
    Form3->Close();
}
//---------------------------------------------------------------------------

