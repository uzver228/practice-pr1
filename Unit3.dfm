object Form3: TForm3
  Left = 13
  Top = 137
  BorderStyle = bsSingle
  Caption = #1042#1080#1074#1077#1076#1077#1085#1085#1103' '#1076#1072#1085#1080#1093
  ClientHeight = 244
  ClientWidth = 1360
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object StringGrid1: TStringGrid
    Left = 8
    Top = 8
    Width = 1377
    Height = 185
    ColCount = 8
    FixedCols = 0
    TabOrder = 0
    OnSelectCell = StringGrid1SelectCell
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
  object Button1: TButton
    Left = 608
    Top = 208
    Width = 105
    Height = 25
    Caption = #1042#1080#1081#1090#1080
    TabOrder = 1
    OnClick = Button1Click
  end
end
