object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 422
  ClientWidth = 643
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object NumOfBookGet: TLabel
    Left = 40
    Top = 329
    Width = 153
    Height = 21
    AutoSize = False
    BiDiMode = bdLeftToRight
    Caption = #1050#1085#1080#1075' '#1087#1086#1083#1091#1095#1077#1085#1086': '
    Color = clSilver
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentBiDiMode = False
    ParentColor = False
    ParentFont = False
    Transparent = False
    Layout = tlCenter
  end
  object BooksToRepair: TLabel
    Left = 240
    Top = 329
    Width = 153
    Height = 22
    AutoSize = False
    Caption = #1053#1091#1078#1085#1072' '#1088#1077#1089#1090#1072#1074#1088#1072#1094#1080#1103': '
    Color = clSilver
    ParentColor = False
    Transparent = False
    Layout = tlCenter
  end
  object ProgBar1Label: TLabel
    Left = 40
    Top = 281
    Width = 153
    Height = 15
    Alignment = taCenter
    AutoSize = False
    Layout = tlCenter
  end
  object ProgBar2Label: TLabel
    Left = 240
    Top = 281
    Width = 153
    Height = 15
    Alignment = taCenter
    AutoSize = False
    Color = clBtnFace
    ParentColor = False
    Transparent = False
  end
  object ProgBar3Label: TLabel
    Left = 440
    Top = 281
    Width = 153
    Height = 15
    Alignment = taCenter
    AutoSize = False
    Layout = tlCenter
  end
  object LibraryStringTree: TVirtualStringTree
    Left = 0
    Top = 0
    Width = 643
    Height = 193
    Align = alTop
    DefaultNodeHeight = 19
    Header.AutoSizeIndex = -1
    Header.MainColumn = 1
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 1
    OnGetText = LibraryStringTreeGetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    ExplicitWidth = 665
    Columns = <
      item
        Position = 0
        Text = #1043#1086#1076' '#1080#1079#1076#1072#1085#1080#1103
        Width = 80
      end
      item
        Position = 1
        Text = #1050#1086#1083'-'#1074#1086' '#1089#1090#1088#1072#1085#1080#1094
        Width = 100
      end
      item
        Position = 2
        Text = #1057#1086#1089#1090#1086#1103#1085#1080#1077
        Width = 80
      end
      item
        Position = 3
        Text = #1044#1086#1087'. '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
        Width = 115
      end
      item
        Position = 4
        Text = #1058#1080#1087
        Width = 150
      end>
  end
  object GetBooks: TButton
    Left = 40
    Top = 220
    Width = 153
    Height = 49
    Caption = #1055#1086#1083#1091#1095#1080#1090#1100' '#1082#1085#1080#1075#1080' '#1089#1086' '#1089#1082#1083#1072#1076#1072
    TabOrder = 2
    OnClick = GetBooksClick
  end
  object InspectBooks: TButton
    Left = 240
    Top = 220
    Width = 153
    Height = 49
    Caption = #1054#1089#1084#1086#1090#1088#1077#1090#1100' '#1082#1085#1080#1075#1080
    TabOrder = 3
    OnClick = InspectBooksClick
  end
  object ProgressBar1: TProgressBar
    Left = 40
    Top = 302
    Width = 153
    Height = 21
    Hint = #1092#1099#1074#1072#1092#1099#1074#1072
    BarColor = clBlack
    BackgroundColor = clBlack
    TabOrder = 0
  end
  object ProgressBar2: TProgressBar
    Left = 240
    Top = 302
    Width = 153
    Height = 21
    TabOrder = 4
  end
  object RepairBooks: TButton
    Left = 440
    Top = 220
    Width = 153
    Height = 49
    Caption = #1056#1077#1089#1090#1072#1074#1088#1080#1088#1086#1074#1072#1090#1100' '#1082#1085#1080#1075#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = RepairBooksClick
  end
  object ProgressBar3: TProgressBar
    Left = 440
    Top = 302
    Width = 153
    Height = 21
    TabOrder = 6
  end
end
