# PUST_SN3

## Punktacja 
Początek realizacji
08 .03.2018; 
Projekt wstępny
10.04.2018; 
Przekazanie zadań
05.06.2018; 
Wystawienie punktów
12.06.2018

## Treść 

GB.SN.3
Baza danych CVE (https://cve.mitre.org/)  gromadzi informacje o tzw. podatnościach, czyli
błędach oprogramowania prowadzących do naruszenia bezpieczeństwa systemów. Podatności
dotyczą zarówno oprogramowania uniwersalnego (np. serwera WWW Apache) jak i
oprogramowania ściśle związanego z konkretnym sprzętem (np. firmware rutera Wi-Fi prod.
D-Link model AC1200). W tym drugim przypadku podany jest zawsze producent i model
sprzętu, baza nie zawiera jednak informacji o klasie sprzętu, nie wiemy więc czy podatność
dotyczy   np.:   smartfona,   urządzenia   typu   domowy   ruter   internetowy,   sterownika
przemysłowego, rutera klasy operatorskiej, itd. Baza CVE w opisie podatności zawiera
zawsze URL prowadzący do strony producenta. Naszym celem jest pozyskanie informacji o
klasie sprzętu na podstawie analizy strony WWW producenta.   Do tego celu należy
wykorzystać sieć neuronową klasyfikującą strony na podstawie ograniczonego zbioru
atrybutów z nich pozyskanych. Do przetwarzania stron należy użyć narzędzia BeautifulSoup
–   https://www.crummy.com/software/BeautifulSoup/bs4/doc/.   Zespół   otrzyma   dane
treningowe oraz testowe. Uwaga: do tego zadania wymagane jest wykorzystanie języka
Python.

## Warunki zaliczenia i punktacja:
Program powinien być napisany w języku Python; C/C++ lub Java. Preferowany jest język
Python, w niektórych zadaniach Python jest wymagany. Preferowanym środowiskiem jest
Unix, Windows jest dopuszczalne. Zaliczenie zadania odbywa się na podstawie projektu
wstępnego (5p), sprawozdania (10p) oraz pokazu działającego programu i oceny kodu (15 p.).
Pokaz   w godz. konsultacji lub innym uzgodnionym terminie.   Opóźnienie powoduje
obniżenie punktacji. Niedostarczenie projektu wstępnego i/lub sprawozdania (opóźnienie 2
tyg. w dostarczeniu projektu wstępnego lub niedostarczenie w terminie ostatecznym)
powoduje niezaliczenie zadania i przedmiotu.

### Co powinien zawierać projekt wstępny (3-4 strony):
Sprawozdanie musi być dostarczone osobiście - “na papierze”, postać elektroniczna nie jest
akceptowana i nie będzie brana pod uwagę. Dostarczone sprawozdanie może, ale nie musi
być od razu omówione, ocena ze sprawozdania wstępnego zostanie wystawiona w ciągu
tygodnia od dostarczenia.

Sprawozdanie wstępne powinno zawierać:
1. Skład zespołu, treść zadania z wyraźnym oznaczeniem wariantu (o ile dotyczy)
– najlepiej na samym początku w tytule;
2. interpretację treści zadania – dodatkowe założenia, doprecyzowanie treści, itp.
3. krótki opis funkcjonalny – “black-box” (bez informacji o implementacji)
opis i uzasadnienie przyjętego rozwiązania przyjętego sposobu realizacji (np.
dobór typu sieci neuronowej i sposobu jej symulacji, itd).
5. planowany podział na komponenty i sposób komunikacji między nimi (np.
specyfikacja kluczowego API)
6. zarys koncepcji implementacji (najważniejsze funkcje, algorytmy, obiekty
komunikacyjne, itp.).

Co powinien zawierać projekt ostateczny (6-10 stron)
1. To co projekt wstepny, ewentualnie poprawione i uzupełnione;
2. pełen opis funkcjonalny ;
3. opis interfejsu użytkownika;
4. postać plików konfiguracyjnych, logów, itp.;
5. raport z przeprowadzonych testów oraz wnioski;
6. opis wykorzystanych narzędzi, bibliotek, itp;
7 opis metodyki testów i wyników testowania;

### WAŻNE:
drukowane sprawozdanie powinno składać się ze zszytych (trwale 
zespolonych kartek), sprawozdania składające się z luźnych kartek lub kartek 
spiętych spinaczem biurowym nie będą przyjmowane :-( 

Uwaga:
1. Sprawozdanie wstępne przekazane zostaje w formie pisemnej, nie jest wymagana 
   obecność całego zespołu przy jego przekazaniu.
2. Konsultacje w trakcie realizacji projektu nie wymagają obecności całego zespołu.
3. Sprawozdanie końcowe i pokaz funkcjonowania musi odbywać się w obecności 
   całego zespołu.
4. opisywanie ogólnie znanych rozwiązań  jest niepotrzebne i niewskazane
5. Po pokazie działania i przekazaniu dokumentacji kod źródłowy proszę przesyłać 
   wyłącznie w formacie tar.gz lub zip na adres: GBlinowski@ii.pw.edu.pl
   
UWAGA
dopiero po zaaprobowaniu programu i sprawozdania! Załącznik powinien mieć nazwę
wg. wzorca: PSZT_2018L_AIksinsnski.tar.gz

