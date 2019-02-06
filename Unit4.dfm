object Form4: TForm4
  Left = -10
  Top = 241
  BorderStyle = bsSingle
  Caption = #1055#1086#1096#1091#1082
  ClientHeight = 245
  ClientWidth = 1360
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 9
    Top = 209
    Width = 136
    Height = 20
    Caption = #1050#1083#1102#1095' '#1076#1083#1103' '#1087#1086#1096#1091#1082#1091':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 8
    Width = 1377
    Height = 185
    ColCount = 8
    FixedCols = 0
    TabOrder = 0
    ColWidths = (
      62
      173
      59
      84
      216
      240
      271
      253)
  end
  object Edit1: TEdit
    Left = 152
    Top = 208
    Width = 113
    Height = 21
    TabOrder = 1
    OnChange = Edit1Change
  end
  object Button1: TButton
    Left = 616
    Top = 208
    Width = 89
    Height = 25
    Caption = #1042#1080#1093#1110#1076
    TabOrder = 2
    OnClick = Button1Click
  end
end
