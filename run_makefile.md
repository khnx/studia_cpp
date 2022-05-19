# Windows

Żeby plik makefile zadziałał, należy zainstalować program, który obsłuży plik makefile. Takim programem jest make.
Aby zainstalować make, potrzebny jest menedżer pakietów, który tego dokona. Tutaj użyję Chocolatey.

## Instalacja Chocolatey

Wejść na stronę https://chocolatey.org/install i podążać za instrukcjami.

Alternatywnie, włączyć program PowerShell jako administrator. W Start wpisujemy PowerShell; pojawi się kilka opcji, zaznaczyć Windows PowerShell (będzie podświetlone na niebiesko). Na pasku po prawej pojawi się kilka opcji - wybrać Run as Administrator (włącz jako administrator).

W PowerShellu wpisać polecenie

`code()`
   Get-ExecutionPolicy

Jeżeli program odpowie "Restricted", wpisać

  `code()`
  Set-ExecutionPolicy AllSigned

Następnie wpisać

  `code()`
  Y

Dalej, wkleić podane polecenie:

  `code()`
  Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
  
Po kilku sekundach Chocolatey powinien być zainstalowany. Aby to sprawdzić, należy wpisać:

  `code()`
  choco -?

Skoro Chocolatey jest już zainstalowany, można zainstalować make.

Należy wpisać w PowerShell:

  `code()`
  choco install make
  
Make jest już zainstalowany.

Aby teraz odpalić program, zamknij sesję PowerShell (nie ma potrzeby, by dłużej używać go jako administrator) i włącz PowerShell (jako zwykły użytkownik - czyli domyślnie). Nawiguj do odpowiedniego folderu poleceniem cd, np.:

  `code()`
  cd "C:\Users\radek\Desktop\studia_cpp-main\projekt\"
  
Dalej, w PowerShell (upewnij się, że jesteś w folderze, w którym znajduje się plik makefile) wpisz

  `code()`
  make

## Linux

Użytkownik powinien wiedzieć, jak używać make.
