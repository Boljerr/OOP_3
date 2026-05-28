#define MyAppName "Studentu pazymiu skaiciavimo programa"
#define MyAppVersion "3.0"
#define MyAppPublisher "VU"
#define MyAppExeName "Studentai.exe"

[Setup]
AppId={{A7D4A8F1-2B84-4C94-8B12-123456789ABC}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={autopf}\VU\Ignas-Simaitis
DefaultGroupName=VU\Ignas-Simaitis
OutputDir=.
OutputBaseFilename=Setup
Compression=lzma
SolidCompression=yes
PrivilegesRequired=admin

[Files]
Source: "..\build\Release\Studentai.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\test_files\studentai10000.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\test_files\studentai100000.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\README.md"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{autodesktop}\Studentu programa"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\Studentu programa"; Filename: "{app}\{#MyAppExeName}"

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "Paleisti programa"; Flags: nowait postinstall skipifsilent runascurrentuser