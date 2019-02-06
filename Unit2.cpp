//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
    char buf[100];
    FILE *f;
    f = fopen("addr.txt", "rt");
    while(!feof(f)) {
        fgets(buf, 100, f);
        buf[strlen(buf) - 1] = '\0';
        ComboBox2->Items->Add(buf);
    }
    fclose(f);
}
//---------------------------------------------------------------------------
bool fmem = false;
void __fastcall TForm2::Button1Click(TObject *Sender)
{
    Label14->Visible = false;

    TEdit* earr[5];
    void* elarr[6];
    TLabel* larr[7];
    bool lbl = false;

    earr[0] = Edit1; earr[1] = Edit2; earr[2] = Edit3;
    earr[3] = Edit4; earr[4] = Edit5;

    elarr[0] = Edit1; elarr[1] = Edit2; elarr[2] = Edit3;
    elarr[3] = Edit4; elarr[4] = Edit5; elarr[5] = ComboBox1;

    larr[0] = Label1; larr[1] = Label2; larr[2] = Label3;
    larr[3] = Label4; larr[4] = Label5; larr[5] = Label6;
    larr[6] = Label10;

    for(int i = 0; i < 7; i++) {
        if((i < 5) ? (((TEdit*)elarr[i])->Text.Length() == 0) :
          ((i < 6) ? (((TComboBox*)elarr[i])->Text.Length() == 0) :
          (CheckBox4->Checked == false && CheckBox5->Checked == false &&
           CheckBox6->Checked == false))) {
            larr[i]->Font->Color = clRed;
            lbl = true;
        }
        else
            larr[i]->Font->Color = clBlack;
    }
    if(lbl)
        MessageDlg("��������� ����'����� ����!", mtInformation, TMsgDlgButtons() << mbOK, 0);
    else {
        Memo1->Lines->Add(Edit1->Text);
        Memo1->Lines->Add(Edit2->Text + " " + Edit3->Text + " " + Edit4->Text + " ");
        Memo1->Lines->Add(Edit5->Text);
        Memo1->Lines->Add(ComboBox1->Text);
        if(ComboBox2->Text.Length() > 0 && Edit6->Text.Length() > 0 && Edit7->Text.Length() > 0)
            Memo1->Lines->Add("���. " + ComboBox2->Text + ", ���. " + Edit6->Text + ", ��. " + Edit7->Text);
        else
            Memo1->Lines->Add("-");
        if(Edit8->Text.Length() > 0)
            Memo1->Lines->Add(Edit8->Text);
        else
            Memo1->Lines->Add("-");

        AnsiString arr1 = "", arr2 = "";
        if(!CheckBox1->Checked && !CheckBox2->Checked && !CheckBox3->Checked)
            arr1="-";
        if(!CheckBox4->Checked && !CheckBox5->Checked && !CheckBox6->Checked)
            arr2="-";

        if(CheckBox1->Checked)
            arr1 += (CheckBox2->Checked || CheckBox3->Checked) ? "�����������, " : "�����������";
        if(CheckBox2->Checked)
            arr1 += (CheckBox3->Checked) ? "�������� ������������, " : "�������� ������������";
        if(CheckBox3->Checked)
            arr1 += (Edit9->Text.Length() > 0) ? Edit9->Text : (AnsiString)"����";

        if(CheckBox4->Checked)
            arr2 += (CheckBox5->Checked || CheckBox6->Checked) ? "�������, " : "�������";
        if(CheckBox5->Checked)
            arr2 += (CheckBox6->Checked) ? "��������, " : "��������";
        if(CheckBox6->Checked)
            arr2 += "�������� ����������";


        Memo1->Lines->Add(arr1);
        Memo1->Lines->Add(arr2);
        Memo1->Lines->Add("");
        fmem = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1KeyPress(TObject *Sender, char &Key)
{
    if(Sender == Edit1)
        if(Key != VK_BACK && (Key < '0' || Key > '9'))
            Key = 0;
    if(Sender == Edit2 || Sender == Edit3 || Sender == Edit4)
        if(Key != VK_BACK && (Key < '�' || Key > '�') && (Key < '�' || Key > '�') && Key != '�' && Key != '�')
            Key = 0;
    if(Sender == Edit5)
        if(Key != VK_BACK && ((Key < '0' || Key > '9') || Edit5->Text.Length() > 3))
            Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
    if(fmem) {
        Memo1->Lines->SaveToFile("data.txt");
        Label14->Visible = true;
    }
    else
        MessageDlg("�������� ��������� �����!", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button4Click(TObject *Sender)
{
    Memo1->Lines->LoadFromFile("data.txt");
}
//---------------------------------------------------------------------------

