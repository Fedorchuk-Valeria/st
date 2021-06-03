object Form10: TForm10
  Left = 0
  Top = 0
  Caption = 'Form10'
  ClientHeight = 242
  ClientWidth = 527
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 224
    Top = 61
    Width = 3
    Height = 13
  end
  object Label2: TLabel
    Left = 224
    Top = 101
    Width = 3
    Height = 13
  end
  object ExpressionEnter: TEdit
    Left = 40
    Top = 24
    Width = 145
    Height = 21
    TabOrder = 0
  end
  object RPN: TButton
    Left = 110
    Top = 56
    Width = 75
    Height = 25
    Caption = 'RPN'
    TabOrder = 1
    OnClick = RPNClick
  end
  object CountUp: TButton
    Left = 110
    Top = 87
    Width = 75
    Height = 25
    Caption = 'Count Up'
    TabOrder = 2
    OnClick = CountUpClick
  end
end
