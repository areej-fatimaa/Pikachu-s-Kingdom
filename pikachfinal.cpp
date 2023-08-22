#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
void printmaze();
void gameover();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void printscore();
void printpikachu(int &);
void printspiko(int &, int &, int &);
void printmisty(int &, int &, int &, int &);
void printdarco(int &, int &, int &);
void movepikachuleft(int &, int &, int &);
void movepikachuright(int &, int &, int &);
void movepikachuup(int &, int &, int &);
void movepikachudown(int &, int &, int &);
void movespiko(int &, int &, int &, int &, int &, int &);
void movemisty(int &, int &, int &, int &, int &, int &);
void movedarco(int &, int &, int &, int &, int &, int &);
void erasespiko(int &, int &);
void erasemisty(int &, int &);
void erasedarco(int &, int &);
void erasepikachu(int &, int &);
void erasebulletpikachu(int x, int y);
void eraseBulletMisty(int x, int y);
void eraswBulletDarco(int x, int y);
void eraseBulletspiko(int x, int y);
void generatebulletpikachu(int &, int &);
void generateBulletMistyRight(int &, int &);
void generateBulletDarco(int &, int &, int &);
void generateBulletspiko(int &, int &);
void generateBulletMistyLeft(int &, int &);
void generatebulletpikachupikachuleft(int &, int &);
void movebulletpikachu();
void moveBulletMisty();
void moveBulletDarco();
void moveBulletSpiko();
void printbulletpikachu(int x, int y);
void printBulletMisty(int x, int y);
void printBulletDarco(int x, int y);
void printBulletspiko(int x, int y);
void makebulletinactivepikachu(int i);
void makeBulletInactivemisty(int i);
void makeBulletInactivespiko(int i);
void makeBulletInactiveDarco(int i);
void bulletcollisionwitspiko(int &, int &, int &);
void bulletcollisionwithmisty(int &, int &, int &);
void bulletcollisionwithdarco(int &, int &, int &);
void bulletcollisionwithpikachuofmisty(int &, int &, int &);
void bulletcollisionwithpikachuofdarco(int &, int &, int &);
void bulletcollisionwithpikachuofspiko(int &, int &, int &);
void addscore();
void printscore();
void printBulletDetail();
void spikohealth(int &);
void mistyhealth(int &);
void darcohealth(int &);
void printspikohealth(int &);
void printdarcohealth(int &);
void printmistyhealth(int &);
void header();
void welcome();
void instructions();
void keys();
void gameInstuctions();
void printpikachuhealth(int &, int &, int &);
void pikachuhealth(int &);
void printbulletenemy(int x, int y);
void startgame(int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &);
const int MAX_ROWS = 100;
void readMazeFromFile(char maze[][MAX_ROWS], int &numRows, int &numCols);
void writegametofile(int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &);
void readgamefromfile(int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int &);
string spikodirection = "Down";
string mistydirection = "Right";

// const int MAX_ROWS = 100;
char pika = 1;
char pika2 = 17;
char pika3 = 16;
char pika4 = 124;
char shark = 2;
char misty1 = 19;
char pikachu[2][3] = {{' ', pika, ' '}, {pika2, pika4, pika3}};
char spiko[2][3] = {{' ', shark, ' '}, {pika2, misty1, pika3}};
char misty[2][3] = {{' ', shark, ' '}, {pika2, misty1, pika3}};
char darco[2][3] = {{' ', shark, ' '}, {pika2, misty1, pika3}};
int pikachubulletx[1000];
int pikachubullety[1000];
int mistyBulletx[10000];
int darcoBulletx[10000];
int darcoBullety[10000];
int spikoBulletx[10000];
int spikoBullety[10000];
int mistyBullety[10000];
int timer = 0;
int score = 0;
bool isbulletactive[1000];
bool isBulletActiveMisty[10000];
bool isBulletActiveDarco[10000];
bool isBulletActivespiko[10000];
bool isfacingleft[1000];
bool isfacingleftmisty[10000];
int pikachuBulletcount = 0;
int darcoBulletCount = 0;
int mistyBulletCount = 0;
int spikoBulletCount = 0;
int totalbullet = 1000;
string option;

main()
{
    int pikachuhealthcounter = 80;
    int spikohealthcounter = 6;
    int mistyhealthcounter = 6;
    int darcohealthcounter = 6;

    int pikachux = 10;
    int pikachuy = 2;
    int spikox = 4;
    int spikoy = 8;
    int mistyx = 56;
    int mistyy = 18;
    int darcox = 50;
    int darcoy = 2;
    welcome();
    while (true)
    {
        startgame(spikohealthcounter, mistyhealthcounter, darcohealthcounter, pikachuhealthcounter, pikachux, pikachuy, spikox, spikoy, mistyx, mistyy, darcox, darcoy);
        system("cls");
        header();
        cout << "1.start" << endl;
        cout << "2.option" << endl;
        cout << "3.exit" << endl;
        cout << "Enter Your option:" << endl;
        cin >> option;
        if (option == "1")
        {
            string choice;
            cout << "1.New Game" << endl;
            cout << "2.Resume" << endl;
            cin >> choice;
            if (choice == "1")
            {
                startgame(spikohealthcounter, mistyhealthcounter, darcohealthcounter, pikachuhealthcounter, pikachux, pikachuy, spikox, spikoy, mistyx, mistyy, darcox, darcoy);
            }
            if (choice == "2")
            {
                readgamefromfile(spikohealthcounter, mistyhealthcounter, darcohealthcounter, pikachuhealthcounter, pikachux, pikachuy, spikox, spikoy, mistyx, mistyy, darcox, darcoy);
            }
            cout << "LOADING.........." << endl;
            cout << "Press any key to continue! " << endl;
            bool gameRun = true;
            system("cls");
            printmaze();
            if (spikohealthcounter > 0)
            {
                printspiko(spikohealthcounter, spikox, spikoy);
            }
            if (mistyhealthcounter > 0)
            {
                printmisty(mistyhealthcounter, pikachuhealthcounter, mistyx, mistyy);
            }
            if (darcohealthcounter > 0)
            {
                printdarco(darcohealthcounter, darcox, darcoy);
            }
            while (gameRun)
            {

                printscore();
                printspikohealth(spikohealthcounter);
                printmistyhealth(mistyhealthcounter);
                printdarcohealth(darcohealthcounter);
                printpikachuhealth(pikachuhealthcounter, pikachux, pikachuy);
                printBulletDetail();
                if (GetAsyncKeyState(VK_LEFT))
                {
                    movepikachuleft(pikachuhealthcounter, pikachux, pikachuy);
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    movepikachuright(pikachuhealthcounter, pikachux, pikachuy);
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    movepikachuup(pikachuhealthcounter, pikachux, pikachuy);
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    movepikachudown(pikachuhealthcounter, pikachux, pikachuy);
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    generatebulletpikachu(pikachux, pikachuy);
                }
                if (GetAsyncKeyState(VK_TAB))
                {
                    generatebulletpikachupikachuleft(pikachux, pikachuy);
                }
                // if (timer == 3)
                // {
                generateBulletDarco(darcohealthcounter, darcox, darcoy);
                generateBulletspiko(spikox, spikoy);
                //   timer = 0;
                // }
                timer++;
                movespiko(pikachuhealthcounter, spikohealthcounter, spikox, spikoy, pikachux, pikachuy);
                movemisty(mistyhealthcounter, pikachuhealthcounter, mistyx, mistyy, pikachux, pikachuy);
                movedarco(darcohealthcounter, pikachuhealthcounter, darcox, darcoy, pikachux, pikachuy);
                moveBulletMisty();
                moveBulletDarco();
                moveBulletSpiko();

                movebulletpikachu();
                bulletcollisionwithpikachuofmisty(pikachuhealthcounter, pikachux, pikachuy);
                bulletcollisionwithpikachuofdarco(pikachuhealthcounter, pikachux, pikachuy);
                bulletcollisionwithpikachuofspiko(pikachuhealthcounter, pikachux, pikachuy);
                bulletcollisionwitspiko(spikohealthcounter, spikox, spikoy);
                bulletcollisionwithmisty(mistyhealthcounter, mistyx, mistyy);
                bulletcollisionwithdarco(darcohealthcounter, darcox, darcoy);
                writegametofile(spikohealthcounter, mistyhealthcounter, darcohealthcounter, pikachuhealthcounter, pikachux, pikachuy, spikox, spikoy, mistyx, mistyy, darcox, darcoy);

                if (pikachuhealthcounter <= 0)
                {
                    gameRun = false;
                    system("cls");
                    gameover();
                    cout << "Enter any key to continue";
                    getch();
                }
            }
        }
        else if (option == "2")
        {
            system("cls");
            gameInstuctions();
        }
        else if (option == "3")
        {
            cout << "Exit";
            system("cls");
            break;
        }
    }
}

void welcome()
{
    SetConsoleTextAttribute(color, 14);
    cout << "      %%%+.                                                                     " << endl;
    cout << "     =%%%%%*:                                                                   " << endl;
    cout << "     =%%%%%*:                                                                   " << endl;
    cout << "     %%%%%%%%*.                                                                 " << endl;
    cout << "    =%%%%%%%%%%*.                                                               " << endl;
    cout << "    %%%%%%%%%%%%%=                                                              " << endl;
    cout << "   :@%%%%@%@%%%%%%#-                                                            " << endl;
    cout << "   +%%%%@=#@-%%%%%%@+                                                           " << endl;
    cout << "   #%%%%@::+-:#%%%%%%#.                                                         " << endl;
    cout << "   @%%%%%.::::.=%%%%%%%:                                                        " << endl;
    cout << "  .@%%%%*:::::::-%%%%%%%-                                                       " << endl;
    cout << "  :%%%%@=:::::::::+@%%%%@+                                                      " << endl;
    cout << "  -%%%%@-::::::::::-%%%%%%*                             ..:-===++***##%%%%%%@@%#" << endl;
    cout << "  =%%%%@::::::::::::-%%%@%%-                    :-=+*#%@@%%%%%%%%%%%%%%%%%%%%%@:" << endl;
    cout << "  +%%%%@.:::::::::::::*%%%@:                  -%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@- " << endl;
    cout << "  +%%%%@.::::::::::::::+@%-                  =%%%%%%%%@@%%#***+++#@@%%%%%%%%@-  " << endl;
    cout << "  +%%%%%.::::::::::::::.+-                  :%%%@%#*+=-:.::::::*#*==%%%%%%%%:   " << endl;
    cout << "  :#@%%#.::::::::::::::-:..........         ++=-::::::::::::::-:::=%%%%%%%@-    " << endl;
    cout << "    :+%#.:::::::::::::::::::::::::::::::.  :::::::::::::::::::::.+%%%%%%%%:     " << endl;
    cout << "      .=-::::::::::::::::::::::::::::::::::-::::::::::::::::::::*%%%%%%%#       " << endl;
    cout << "         :::::::::::::::::::::::::::::::::::::::::::::::::::::-%%%%%%%@*.       " << endl;
    cout << "          -::::::::::::::::::::::::::::::::::::::::::::::::::+@%@%%%%%:         " << endl;
    cout << "        .-:::::-==:::::::::::::::::::::::::::::::::::::::::-#%%%%%%@+           " << endl;
    cout << "       :::::-#@-  =%-:::::::::::::::::=--=-:::::::::::::::*@%%%%%%+.            " << endl;
    cout << "      .::::=@@@*::*@*:::::::::::::::.%:  :@@+.::::::::::*@%%%%%%+.              " << endl;
    cout << "      ::::.%@@@@@@@@=:::::::::::::::=@#==#@@@*.:::::-:-###%%%*-                 " << endl;
    cout << "      :.:::+@@@@@@@+:::::::::::::::::@@@@@@@@@.::::.-                           " << endl;
    cout << "      -===-:-+**+-:::::::::-:::::::::-#@@@@@@+::::::-                           " << endl;
    cout << "      :=====-:::::::::::::::::::::::::::=+++::-====--                           " << endl;
    cout << "       :=====::::::::::::###%%=:::::::::::::========                            " << endl;
    cout << "        .-===::::::::::::+*++*:::::::::::::-=======.                            " << endl;
    cout << "          :=:::::::::::::-++*=:::::::::::::-=====:                              " << endl;
    cout << "            .::::::::::::::-::::::::::::::::-==:                                " << endl;
    cout << "               .::-:::::::::::::::::::::::-::                                   " << endl;
    cout << "                 ::%#*+=--:::::::::--==-:.                                      " << endl;
    cout << "                ::-+#%%%@@@@@@@@@@@@@@#.:                                       " << endl;
    cout << "               -::::=%%#=*%%%++@@%%%-:::::                                      " << endl;
    cout << "             :::::::#=::::=:::-*%%-:::::-:=:                                    " << endl;
    cout << "              -::::::-::::::::::::=::::::.*%%#=                                 " << endl;
    cout << "             .--::::::-:::::::::::::::::---@%%%%*-.                             " << endl;
    cout << "             .::-::::::-:::::::::=:::::--:-%%%%%%%@*:                           " << endl;
    cout << "             .:::--::.=:::::::::=:::::-:::=@%%%%%%%%%%+:                        " << endl;
    cout << "              ::::::--:::::::::::----:::::=%%%%%%%%%%%%%%-                      " << endl;
    cout << "              .:-::::::::::::::::::::::::. .#%%%%%%%%@#-                        " << endl;
    cout << "           .:::::---::::::::::::::::::---:.. =%%%%%*-.                          " << endl;
    cout << "         .-::::::::-==--::::::::::--=-:::::::: ==:                              " << endl;
    cout << "        :-::::::::::=-:.          :=-::::::::::.                                " << endl;
    cout << "        :-::-:::-:::.              .:-::::::::--                                " << endl;
    cout << "          ....                        :::::::::-                                " << endl;
    cout << "                                         ......                                 " << endl;

    cout << endl;
    cout << "Press any key to continue:";
    getch();
}
void header()
{
    SetConsoleTextAttribute(color, 4);
    cout << "LOADING...." << endl;
    getch();
    system("cls");
    cout << " OooOOo.     o                   o           Oo             `o    O                       o               " << endl;
    cout << "O     `O o  O                  O            oO              o   O   o                   O                 " << endl;
    cout << "o      O    o                  o             O              O  O                        o                 " << endl;
    cout << "O     .o    o                  O            o'              oOo                         o                 " << endl;
    cout << "oOooOO'  O  O  o  .oOoO' .oOo  OoOo. O   o     .oOo         o  o    O  'OoOo. .oOoO .oOoO  .oOo. `oOOoOO. " << endl;
    cout << "o        o  OoO   O   o  O     o   o o   O     `Ooo.        O   O   o   o   O o   O o   O  O   o  O  o  o " << endl;
    cout << "O        O  o  O  o   O  o     o   O O   o         O        o    o  O   O   o O   o O   o  o   O  o  O  O " << endl;
    cout << "o'       o' O   o `OoO'o `OoO' O   o `OoO'o    `OoO'        O     O o'  o   O `OoOo `OoO'o `OoO'  O  o  o " << endl;
    cout << "                                                                                  O                       " << endl;
    cout << "                                                                               OoO'                       " << endl;
    cout << endl;
}
void keys()
{
    SetConsoleTextAttribute(color, 11);
    cout << "LOADING........" << endl;
    getch();
    cout << ":::    ::: :::::::::: :::   :::  ::::::::   " << endl;
    cout << ":+:   :+:  :+:        :+:   :+: :+:    :+:  " << endl;
    cout << "+:+  +:+   +:+         +:+ +:+  +:+         " << endl;
    cout << "+#++:++    +#++:++#     +#++:   +#++:++#++  " << endl;
    cout << "+#+  +#+   +#+           +#+           +#+  " << endl;
    cout << "#+#   #+#  #+#           #+#    #+#    #+#  " << endl;
    cout << "###    ### ##########    ###     ########   " << endl;

    SetConsoleTextAttribute(color, 8);
    cout << "Prees up key to move up" << endl;
    cout << "Press down key to move " << endl;
    cout << "Press left key to move left" << endl;
    cout << "Press right key to move right" << endl;
    cout << "Press space key to shoot right" << endl;
    cout << "Press tab key to shoot left" << endl;
}
void instructions()
{
    SetConsoleTextAttribute(color, 13);
    cout << "LOADING....." << endl;
    getch();
    system("cls");
    cout << "::::::::::: ::::    :::  ::::::::  ::::::::::: :::::::::  :::    :::  ::::::::  ::::::::::: :::::::::::  ::::::::  ::::    :::  ::::::::  " << endl;
    cout << "    :+:     :+:+:   :+: :+:    :+:     :+:     :+:    :+: :+:    :+: :+:    :+:     :+:         :+:     :+:    :+: :+:+:   :+: :+:    :+: " << endl;
    cout << "    +:+     :+:+:+  +:+ +:+            +:+     +:+    +:+ +:+    +:+ +:+            +:+         +:+     +:+    +:+ :+:+:+  +:+ +:+        " << endl;
    cout << "    +#+     +#+ +:+ +#+ +#++:++#++     +#+     +#++:++#:  +#+    +:+ +#+            +#+         +#+     +#+    +:+ +#+ +:+ +#+ +#++:++#++ " << endl;
    cout << "    +#+     +#+  +#+#+#        +#+     +#+     +#+    +#+ +#+    +#+ +#+            +#+         +#+     +#+    +#+ +#+  +#+#+#        +#+ " << endl;
    cout << "    #+#     #+#   #+#+# #+#    #+#     #+#     #+#    #+# #+#    #+# #+#    #+#     #+#         #+#     #+#    #+# #+#   #+#+# #+#    #+# " << endl;
    cout << "########### ###    ####  ########      ###     ###    ###  ########   ########      ###     ###########  ########  ###    ####  ########  " << endl;

    SetConsoleTextAttribute(color, 18);
    cout << "shoot the sharks to get extra point" << endl;
    cout << "collect fishes to get points" << endl;
    cout << "find a key to go to next leve" << endl;
    cout << "save your player from bullets of sharks" << endl;
    cout << "sharks health will decrease your bullets will hit them" << endl;
    cout << "Player bullets should not touch small fishes because they will die" << endl;
}

void gameInstuctions()
{
    string choice;
    while (choice != "3")
    {
        cout << "1.keys" << endl;
        cout << "2.instructions" << endl;
        cout << "3.exit" << endl;
        cout << "Enter your option:" << endl;
        cin >> choice;

        if (choice == "1")
        {
            system("cls");
            keys();
            cout << endl;
            cout << "Press any key to continue";
            getch();
            system("cls");
            gameInstuctions();
        }

        else if (choice == "2")
        {
            system("cls");
            instructions();
            cout << endl;
            cout << "Press any key to continue";
            getch();
            system("cls");
            gameInstuctions();
        }

        else if (choice == "3")
        {
            system("cls");
        }
    }
}

void printmaze()
{
    SetConsoleTextAttribute(color, 8);
    char maze[MAX_ROWS][MAX_ROWS] = {};
    int numRows = 0, numCols = 0;

    readMazeFromFile(maze, numRows, numCols);

    // print the maze array
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            cout << maze[row][col];
        }
        cout << endl;
    }
}
void startgame(int &spikohealthcounter, int &mistyhealthcounter, int &darcohealthcounter, int &pikachuhealthcounter, int &pikachux, int &pikachuy, int &spikox, int &spikoy, int &mistyx, int &mistyy, int &darcox, int &darcoy)
{
    pikachux = 10;
    pikachuy = 2;
    spikox = 4;
    spikoy = 8;
    mistyx = 56;
    mistyy = 18;
    darcox = 50;
    darcoy = 2;
    timer = 0;
    score = 0;
    pikachuBulletcount = 0;
    darcoBulletCount = 0;
    mistyBulletCount = 0;
    spikoBulletCount = 0;
    totalbullet = 1000;
    spikohealthcounter = 6;
    mistyhealthcounter = 6;
    darcohealthcounter = 6;
    pikachuhealthcounter = 20;
}
void writegametofile(int &spikohealthcounter, int &mistyhealthcounter, int &darcohealthcounter, int &pikachuhealthcounter, int &pikachux, int &pikachuy, int &spikox, int &spikoy, int &mistyx, int &mistyy, int &darcox, int &darcoy)
{
    fstream file;
    file.open("game.txt", ios::out);
    file << pikachux << endl;
    file << pikachuy << endl;
    file << spikox << endl;
    file << spikoy << endl;
    file << mistyx << endl;
    file << mistyy << endl;
    file << darcox << endl;
    file << darcoy << endl;
    file << timer << endl;
    file << score << endl;
    file << pikachuBulletcount << endl;
    file << darcoBulletCount << endl;
    file << mistyBulletCount << endl;
    file << spikoBulletCount << endl;
    file << totalbullet << endl;
    file << spikohealthcounter << endl;
    file << mistyhealthcounter << endl;
    file << darcohealthcounter << endl;
    file << pikachuhealthcounter << endl;
    file.close();
}
void readgamefromfile(int &spikohealthcounter, int &mistyhealthcounter, int &darcohealthcounter, int &pikachuhealthcounter, int &pikachux, int &pikachuy, int &spikox, int &spikoy, int &mistyx, int &mistyy, int &darcox, int &darcoy)
{
    fstream file;
    file.open("game.txt", ios::in);
    while (!(file.eof()))
    {
        file >> pikachux;
        file >> pikachuy;
        file >> spikox;
        file >> spikoy;
        file >> mistyx;
        file >> mistyy;
        file >> darcox;
        file >> darcoy;
        file >> timer;
        file >> score;
        file >> pikachuBulletcount;
        file >> darcoBulletCount;
        file >> mistyBulletCount;
        file >> spikoBulletCount;
        file >> totalbullet;
        file >> spikohealthcounter;
        file >> mistyhealthcounter;
        file >> darcohealthcounter;
        file >> pikachuhealthcounter;
    }
    file.close();
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void printpikachu(int &pikachuhealthcounter, int &pikachux, int &pikachuy)
{
    SetConsoleTextAttribute(color, 14);
    if (pikachuhealthcounter != 0)
        for (int i = 0; i < 2; i++)
        {
            gotoxy(pikachux, pikachuy + i);
            for (int j = 0; j < 3; j++)
            {
                cout << pikachu[i][j];
            }
        }
    else if (pikachuhealthcounter <= 0)
    {
        erasepikachu(pikachux, pikachuy);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << pikachu[i][j];
            }
        }
    }
}
void printspiko(int &spikohealthcounter, int &spikox, int &spikoy)
{
    SetConsoleTextAttribute(color, 13);
    if (spikohealthcounter != -1)
    {
        for (int i = 0; i < 2; i++)
        {
            gotoxy(spikox, spikoy + i);
            for (int j = 0; j < 3; j++)
            {
                cout << spiko[i][j];
            }
        }
    }
    else if (spikohealthcounter < 0)
    {
        erasespiko(spikox, spikoy);
    }
}
void printmisty(int &mistyhealthcounter, int &pikachuhealthcounter, int &mistyx, int &mistyy)
{
    SetConsoleTextAttribute(color, 4);

    if (mistyhealthcounter != 0)
    {
        for (int i = 0; i < 2; i++)
        {
            gotoxy(mistyx, mistyy + i);
            for (int j = 0; j < 3; j++)
            {
                cout << misty[i][j];
            }
        }
    }
    else if (mistyhealthcounter <= 0)
    {
        erasemisty(mistyx, mistyy);
    }
}
void printdarco(int &darcohealthcounter, int &darcox, int &darcoy)
{
    SetConsoleTextAttribute(color, 4);
    if (darcohealthcounter != 0)
    {
        for (int i = 0; i < 2; i++)
        {
            gotoxy(darcox, darcoy + i);
            for (int j = 0; j < 3; j++)
            {
                cout << darco[i][j];
            }
        }
    }
    else if (darcohealthcounter <= 0)
    {
        erasedarco(darcox, darcoy);
    }
}
void movepikachuleft(int &pikachuhealthcounter, int &pikachux, int &pikachuy)
{

    char next1 = getCharAtxy(pikachux - 1, pikachuy);
    char next2 = getCharAtxy(pikachux - 1, pikachuy + 1);
    if (next1 == ' ' && next2 == ' ')
    {
        erasepikachu(pikachux, pikachuy);
        pikachux = pikachux - 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    if (next1 == '.' && next2 == '.')
    {
        erasepikachu(pikachux, pikachuy);
        pikachux = pikachux - 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == '.' && next2 == '.')
    {
        erasepikachu(pikachux, pikachuy);
        pikachux = pikachux - 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == '-' && next2 == '-')
    {
        erasepikachu(pikachux, pikachuy);
        pikachux = pikachux - 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
        pikachuhealth(pikachuhealthcounter);
    }
    else if (next1 == '^' || next2 == '^')
    {
        erasepikachu(pikachux, pikachuy);
        pikachux = pikachux - 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
        addscore();
    }
    else if (next1 == '&' || next2 == '&')
    {
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == shark || next2 == shark || next1 == pika2 || next2 == pika2 || next1 == misty1 || next2 == misty1 || next1 == pika3 || next2 == pika3)
    {
        pikachuhealth(pikachuhealthcounter);
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
}
void movepikachuright(int &pikachuhealthcounter, int &pikachux, int &pikachuy)
{
    char next1 = getCharAtxy(pikachux + 3, pikachuy);
    char next2 = getCharAtxy(pikachux + 3, pikachuy + 1);
    if (next1 == ' ' && next2 == ' ')
    {
        erasepikachu(pikachux, pikachuy);
        pikachux = pikachux + 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    if (next1 == '.' && next2 == '.')
    {
        erasepikachu(pikachux, pikachuy);
        pikachux = pikachux + 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }

    else if (next1 == '.' && next2 == '.')
    {
        erasepikachu(pikachux, pikachuy);
        pikachux = pikachux + 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == '-' && next2 == '-')
    {
        erasepikachu(pikachux, pikachuy);
        pikachux = pikachux + 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
        pikachuhealth(pikachuhealthcounter);
    }
    else if (next1 == '^' || next2 == '^')
    {
        erasepikachu(pikachux, pikachuy);
        pikachux = pikachux + 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
        addscore();
    }
    else if (next1 == '&' || next2 == '&')
    {
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == shark || next2 == shark || next1 == pika2 || next2 == pika2 || next1 == misty1 || next2 == misty1 || next1 == pika3 || next2 == pika3)
    {
        pikachuhealth(pikachuhealthcounter);
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
}
void movepikachuup(int &pikachuhealthcounter, int &pikachux, int &pikachuy)
{
    char next1 = getCharAtxy(pikachux, pikachuy - 1);
    char next2 = getCharAtxy(pikachux + 1, pikachuy - 1);
    char next3 = getCharAtxy(pikachux + 2, pikachuy - 1);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ')
    {
        erasepikachu(pikachux, pikachuy);
        pikachuy = pikachuy - 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == '.' && next2 == '.')
    {
        erasepikachu(pikachux, pikachuy);
        pikachuy = pikachuy - 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == '-' && next2 == '-')
    {
        erasepikachu(pikachux, pikachuy);
        pikachuy = pikachuy - 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
        pikachuhealth(pikachuhealthcounter);
    }
    else if (next1 == '^' || next2 == '^' || next3 == '^')
    {
        erasepikachu(pikachux, pikachuy);
        pikachuy = pikachuy - 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
        addscore();
    }
    else if (next1 == '&' || next2 == '&' || next3 == '&')
    {
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == shark || next2 == shark || next3 == shark || next1 == pika2 || next2 == pika2 || next3 == pika2 || next1 == misty1 || next2 == misty1 || next3 == misty1 || next1 == pika3 || next2 == pika3 || next3 == pika3)
    {
        pikachuhealth(pikachuhealthcounter);
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == '-' || next2 == '-' || next3 == '-')
    {
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
        pikachuhealth(pikachuhealthcounter);
    }
}
void movepikachudown(int &pikachuhealthcounter, int &pikachux, int &pikachuy)
{
    char next1 = getCharAtxy(pikachux, pikachuy + 2);
    char next2 = getCharAtxy(pikachux + 1, pikachuy + 2);
    char next3 = getCharAtxy(pikachux + 2, pikachuy + 2);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ')
    {
        erasepikachu(pikachux, pikachuy);
        pikachuy = pikachuy + 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == '.' && next2 == '.')
    {
        erasepikachu(pikachux, pikachuy);
        pikachuy = pikachuy + 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == '-' && next2 == '-')
    {
        erasepikachu(pikachux, pikachuy);
        pikachuy = pikachuy + 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
        pikachuhealth(pikachuhealthcounter);
    }
    else if (next1 == '^' || next2 == '^' || next3 == '^')
    {
        erasepikachu(pikachux, pikachuy);
        pikachuy = pikachuy + 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
        addscore();
    }
    else if (next1 == '&' || next2 == '&' || next3 == '&')
    {
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == shark || next2 == shark || next3 == shark || next1 == pika2 || next2 == pika2 || next3 == pika2 || next1 == misty1 || next2 == misty1 || next3 == misty1 || next1 == pika3 || next2 == pika3 || next3 == pika3)
    {
        pikachuhealth(pikachuhealthcounter);
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
    }
    else if (next1 == '-' || next2 == '-' || next3 == '-')
    {
        erasepikachu(pikachux, pikachuy);
        pikachuy = pikachuy + 1;
        printpikachu(pikachuhealthcounter, pikachux, pikachuy);
        pikachuhealth(pikachuhealthcounter);
    }
}
void movespiko(int &pikachuhealthcounter, int &spikohealthcounter, int &spikox, int &spikoy, int &pikachux, int &pikachuy)
{
    if (spikohealthcounter > 0)
    {
        if (spikodirection == "Up")
        {

            char next1 = getCharAtxy(spikox, spikoy - 1);
            char next2 = getCharAtxy(spikox + 1, spikoy - 1);
            char next3 = getCharAtxy(spikox + 2, spikoy - 1);
            char next4 = getCharAtxy(spikox + 3, spikoy - 1);
            if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ')
            {
                erasespiko(spikox, spikoy);
                spikoy--;
                printspiko(spikohealthcounter, spikox, spikoy);
            }
            if (next1 == '&' && next2 == '&' && next3 == '&' && next4 == '&')
            {
                spikodirection = "Down";
            }
            if (next1 == '.' && next2 == '.' && next3 == '.' && next4 == '.')
            {
                erasespiko(spikox, spikoy);
                spikoy--;
                printspiko(spikohealthcounter, spikox, spikoy);
            }
            if (next1 == pika || next1 == pika2 || next1 == pika4 || next1 == pika3 || next2 == pika || next2 == pika2 || next2 == pika4 || next2 == pika3 || next3 == pika || next3 == pika2 || next3 == pika3 || next3 == pika4 || next4 == pika || next4 == pika2 || next4 == pika3 || next4 == pika4)
            {
                pikachuhealth(pikachuhealthcounter);
                printspiko(spikohealthcounter, spikox, spikoy);
            }
        }
        if (spikodirection == "Down")
        {
            char next1 = getCharAtxy(spikox, spikoy + 2);

            if (next1 == ' ')
            {
                erasespiko(spikox, spikoy);
                spikoy++;
                printspiko(spikohealthcounter, spikox, spikoy);
            }
            if (next1 == '&')
            {
                spikodirection = "Up";
            }
            if (next1 == pika || next1 == pika2 || next1 == pika3 || next1 == pika4)
            {
                printspiko(spikohealthcounter, spikox, spikoy);
                pikachuhealth(pikachuhealthcounter);
            }
        }
    }
    else if (spikohealthcounter == 0)
    {
        erasespiko(spikox, spikoy);
        spikohealthcounter--;
    }
}
void movemisty(int &mistyhealthcounter, int &pikachuhealthcounter, int &mistyx, int &mistyy, int &pikachux, int &pikachuy)
{
    if (mistyhealthcounter > 0)
    {
        if (mistydirection == "Left")
        {
            char next1 = getCharAtxy(mistyx - 1, mistyy);
            char next2 = getCharAtxy(mistyx - 1, mistyy + 1);
            if (next1 == ' ' && next2 == ' ')
            {
                generateBulletMistyRight(mistyx, mistyy);
                erasemisty(mistyx, mistyy);
                mistyx--;
                printmisty(mistyhealthcounter, pikachuhealthcounter, mistyx, mistyy);
            }
            else if (next1 == '^' || next2 == '^')
            {
                erasemisty(mistyx, mistyy);
                mistyx--;
                printmisty(mistyhealthcounter, pikachuhealthcounter, mistyx, mistyy);
            }

            else if (next1 == '&' || next2 == '&')
            {
                mistydirection = "Right";
            }
            else if (next1 == pika || next1 == pika2 || next1 == pika3 || next1 == pika4 || next2 == pika || next2 == pika2 || next2 == pika3 || next2 == pika4)
            {
                printmisty(mistyhealthcounter, pikachuhealthcounter, mistyx, mistyy);
                pikachuhealth(pikachuhealthcounter);
            }
        }
        if (mistydirection == "Right")
        {
            char next1 = getCharAtxy(mistyx + 3, mistyy);
            char next2 = getCharAtxy(mistyx + 3, mistyy + 1);
            if (next1 == ' ' && next2 == ' ')
            {
                generateBulletMistyLeft(mistyx, mistyy);
                erasemisty(mistyx, mistyy);
                mistyx++;
                printmisty(mistyhealthcounter, pikachuhealthcounter, mistyx, mistyy);
            }
            else if (next1 == '^' || next2 == '^')
            {
                erasemisty(mistyx, mistyy);
                mistyx++;
                printmisty(mistyhealthcounter, pikachuhealthcounter, mistyx, mistyy);
            }
            else if (next1 == '&', next2 == '&')
            {
                mistydirection = "Left";
            }
            else if (next1 == pika || next1 == pika2 || next1 == pika3 || next1 == pika4 || next2 == pika || next2 == pika2 || next2 == pika3 || next2 == pika4)
            {
                printmisty(mistyhealthcounter, pikachuhealthcounter, mistyx, mistyy);
                pikachuhealth(pikachuhealthcounter);
            }
        }
    }
    else if (mistyhealthcounter == 0)
    {
        erasemisty(mistyx, mistyy);
        mistyhealthcounter--;
    }
}
void movedarco(int &darcohealthcounter, int &pikachuhealthcounter, int &darcox, int &darcoy, int &pikachux, int &pikachuy)
{
    if (darcohealthcounter > 0)
    {
        if (darcox < pikachux)
        {
            char next1 = getCharAtxy(darcox + 3, darcoy);
            char next2 = getCharAtxy(darcox + 3, darcoy + 1);
            if (next1 == ' ' && next2 == ' ' || next1 == '-' || next2 == '-')
            {
                erasedarco(darcox, darcoy);
                darcox++;
                printdarco(darcohealthcounter, darcox, darcoy);
            }
            else if (next1 == '^' || next2 == '^' || next1 == '-' || next2 == '-')
            {
                erasedarco(darcox, darcoy);
                darcox++;
                printdarco(darcohealthcounter, darcox, darcoy);
            }
            else if (next1 == pika || next1 == pika2 || next1 == pika3 || next1 == pika4 || next2 == pika || next2 == pika2 || next2 == pika3 || next2 == pika4)
            {
                printdarco(darcohealthcounter, darcox, darcoy);
                pikachuhealth(pikachuhealthcounter);
            }
        }
        else if (darcox > pikachux)
        {
            char next1 = getCharAtxy(darcox - 1, darcoy);
            char next2 = getCharAtxy(darcox - 1, darcoy + 1);
            if (next1 == ' ' && next2 == ' ')
            {
                erasedarco(darcox, darcoy);
                darcox--;
                printdarco(darcohealthcounter, darcox, darcoy);
            }
            else if (next1 == '^' || next2 == '^')
            {
                erasedarco(darcox, darcoy);
                darcox--;
                printdarco(darcohealthcounter, darcox, darcoy);
            }
            else if (next1 == pika || next1 == pika2 || next1 == pika3 || next1 == pika4 || next2 == pika || next2 == pika2 || next2 == pika3 || next2 == pika4)
            {
                printdarco(darcohealthcounter, darcox, darcoy);
                pikachuhealth(pikachuhealthcounter);
            }
        }
        else if (darcoy < pikachuy)
        {
            char next1 = getCharAtxy(darcox, darcoy + 2);
            char next2 = getCharAtxy(darcox + 1, darcoy + 2);
            if (next1 == ' ' && next2 == ' ')
            {
                erasedarco(darcox, darcoy);
                darcoy++;
                printdarco(darcohealthcounter, darcox, darcoy);
            }
            else if (next1 == '^' || next2 == '^' || next1 == '-' || next2 == '-')
            {
                erasedarco(darcox, darcoy);
                darcoy++;
                printdarco(darcohealthcounter, darcox, darcoy);
            }
            else if (next1 == pika || next1 == pika2 || next1 == pika3 || next1 == pika4 || next2 == pika || next2 == pika2 || next2 == pika3 || next2 == pika4)
            {
                printdarco(darcohealthcounter, darcox, darcoy);
                pikachuhealth(pikachuhealthcounter);
            }
        }
        else if (darcoy > pikachuy)
        {
            char next1 = getCharAtxy(darcox, darcoy - 1);
            char next2 = getCharAtxy(darcox + 1, darcoy - 1);
            char next3 = getCharAtxy(darcox + 2, darcoy - 1);
            char next4 = getCharAtxy(darcox + 3, darcoy - 1);
            if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' || next1 == '-' || next2 == '-' || next3 == '-' || next4 == '-')
            {
                erasedarco(darcox, darcoy);
                darcoy--;
                printdarco(darcohealthcounter, darcox, darcoy);
            }
            else if (next1 == '^' || next2 == '^' || next3 == '^' || next4 == '^')
            {
                erasedarco(darcox, darcoy);
                darcoy--;
                printdarco(darcohealthcounter, darcox, darcoy);
            }
            else if (next1 == pika || next1 == pika2 || next1 == pika3 || next1 == pika4 || next2 == pika || next2 == pika2 || next2 == pika3 || next2 == pika4)
            {
                printdarco(darcohealthcounter, darcox, darcoy);
                pikachuhealth(pikachuhealthcounter);
            }
        }
    }
    else if (darcohealthcounter == 0)
    {
        erasedarco(darcox, darcoy);
        darcohealthcounter--;
    }
}
void erasespiko(int &spikox, int &spikoy)
{

    gotoxy(spikox, spikoy);
    for (int i = 0; i < 4; i++)
    {
        cout << " ";
    }
    gotoxy(spikox, spikoy + 1);
    for (int i = 0; i < 4; i++)
    {
        cout << " ";
    }
}
void erasemisty(int &mistyx, int &mistyy)
{
    gotoxy(mistyx, mistyy);
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
    }
    gotoxy(mistyx, mistyy + 1);
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
    }
}
void erasedarco(int &darcox, int &darcoy)
{
    for (int i = 0; i < 2; i++)
    {
        gotoxy(darcox, darcoy + i);
        cout << "   ";
    }
}
void erasepikachu(int &pikachux, int &pikachuy)
{
    gotoxy(pikachux, pikachuy);
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
    }
    gotoxy(pikachux, pikachuy + 1);
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
    }
}
void generatebulletpikachu(int &pikachux, int &pikachuy)
{
    if (pikachuBulletcount <= 1000)
    {
        pikachubulletx[pikachuBulletcount] = pikachux + 2;
        pikachubullety[pikachuBulletcount] = pikachuy;
        isbulletactive[pikachuBulletcount] = true;
        isfacingleft[pikachuBulletcount] = false;
        gotoxy(pikachux + 2, pikachuy);
        cout << ".";
        pikachuBulletcount++;
        totalbullet--;
    }
}
void generatebulletpikachupikachuleft(int &pikachux, int &pikachuy)
{
    if (pikachuBulletcount <= 1000)
    {
        pikachubulletx[pikachuBulletcount] = pikachux - 1;
        pikachubullety[pikachuBulletcount] = pikachuy;
        isbulletactive[pikachuBulletcount] = true;
        isfacingleft[pikachuBulletcount] = true;
        gotoxy(pikachux - 1, pikachuy);
        cout << ".";
        pikachuBulletcount++;
        totalbullet--;
    }
}
void generateBulletMistyRight(int &mistyx, int &mistyy)
{
    mistyBulletx[mistyBulletCount] = mistyx + 2;
    mistyBullety[mistyBulletCount] = mistyy;
    isBulletActiveMisty[mistyBulletCount] = true;
    isfacingleftmisty[mistyBulletCount] = false;
    gotoxy(mistyx + 2, mistyy);
    cout << "-";
    mistyBulletCount++;
}
void generateBulletMistyLeft(int &mistyx, int &mistyy)
{
    mistyBulletx[mistyBulletCount] = mistyx - 1;
    mistyBullety[mistyBulletCount] = mistyy;
    isBulletActiveMisty[mistyBulletCount] = true;
    isfacingleftmisty[mistyBulletCount] = true;
    gotoxy(mistyx - 1, mistyy);
    cout << "-";
    mistyBulletCount++;
}
void generateBulletDarco(int &darcohealthcounter, int &darcox, int &darcoy)
{
    if (darcohealthcounter > 0)
    {
        darcoBulletx[darcoBulletCount] = darcox + 3;
        darcoBullety[darcoBulletCount] = darcoy;
        isBulletActiveDarco[darcoBulletCount] = true;
        gotoxy(darcox + 3, darcoy);
        cout << "-";
        darcoBulletCount++;
    }
}
void generateBulletspiko(int &spikox, int &spikoy)
{

    spikoBulletx[spikoBulletCount] = spikox + 2;
    spikoBullety[spikoBulletCount] = spikoy;
    isBulletActivespiko[spikoBulletCount] = true;
    gotoxy(spikox + 2, spikoy);
    cout << "-";
    spikoBulletCount++;
}
void movebulletpikachu()
{
    for (int i = 0; i < 1000; i++)
    {
        if (isbulletactive[i])
        {
            if (!(isfacingleft[i]))
            {
                char next = getCharAtxy(pikachubulletx[i] + 1, pikachubullety[i]);
                if (next != ' ' && next != '^')
                {
                    erasebulletpikachu(pikachubulletx[i], pikachubullety[i]);
                    makebulletinactivepikachu(i);
                }
                else
                {
                    erasebulletpikachu(pikachubulletx[i], pikachubullety[i]);
                    pikachubulletx[i] = pikachubulletx[i] + 1;
                    printbulletpikachu(pikachubulletx[i], pikachubullety[i]);
                }
            }
            else if (isfacingleft[i])
            {
                char next = getCharAtxy(pikachubulletx[i] - 1, pikachubullety[i]);
                if (next != ' ' && next != '^')
                {
                    erasebulletpikachu(pikachubulletx[i], pikachubullety[i]);
                    makebulletinactivepikachu(i);
                }
                else
                {
                    erasebulletpikachu(pikachubulletx[i], pikachubullety[i]);
                    pikachubulletx[i] = pikachubulletx[i] - 1;
                    printbulletpikachu(pikachubulletx[i], pikachubullety[i]);
                }
            }
        }
        else
        {
            erasebulletpikachu(pikachubulletx[i], pikachubullety[i]);
        }
    }
}
void moveBulletMisty()
{
    for (int i = 0; i < 1000; i++)
    {
        if (isBulletActiveMisty[i])
        {
            if (!(isfacingleftmisty[i]))
            {
                char next = getCharAtxy(mistyBulletx[i] + 1, mistyBullety[i]);
                if (next != ' ' && next != '^')
                {
                    erasebulletpikachu(mistyBulletx[i], mistyBullety[i]);
                    makeBulletInactivemisty(i);
                }
                else
                {
                    eraseBulletMisty(mistyBulletx[i], mistyBullety[i]);
                    mistyBulletx[i] = mistyBulletx[i] + 1;
                    printBulletMisty(mistyBulletx[i], mistyBullety[i]);
                }
            }
            else if (isfacingleftmisty[i])
            {
                char next = getCharAtxy(mistyBulletx[i] - 1, mistyBullety[i]);
                if (next != ' ' && next != '^')
                {
                    eraseBulletMisty(mistyBulletx[i], mistyBullety[i]);
                    makeBulletInactivemisty(i);
                }
                else
                {
                    eraseBulletMisty(mistyBulletx[i], mistyBullety[i]);
                    mistyBulletx[i] = mistyBulletx[i] - 1;
                    printBulletMisty(mistyBulletx[i], mistyBullety[i]);
                }
            }
        }
        else
        {
            eraseBulletMisty(mistyBulletx[i], mistyBullety[i]);
        }
    }
}
void moveBulletDarco()
{
    for (int x = 0; x < darcoBulletCount; x++)
    {
        if (isBulletActiveDarco[x] == true)
        {
            char next = getCharAtxy(darcoBulletx[x] + 2, darcoBullety[x]);
            if (next != ' ')
            {
                eraswBulletDarco(darcoBulletx[x], darcoBullety[x]);
                makeBulletInactiveDarco(x);
            }
            else
            {
                eraswBulletDarco(darcoBulletx[x], darcoBullety[x]);
                darcoBulletx[x] = darcoBulletx[x] + 2;
                printBulletDarco(darcoBulletx[x], darcoBullety[x]);
            }
        }
    }
}
void moveBulletSpiko()
{
    for (int x = 0; x < spikoBulletCount; x++)
    {
        if (isBulletActivespiko)
        {
            char next = getCharAtxy(spikoBulletx[x] + 1, spikoBullety[x]);
            if (next != ' ')
            {
                eraseBulletspiko(spikoBulletx[x], spikoBullety[x]);
                makeBulletInactivespiko(x);
            }
            else
            {
                eraseBulletspiko(spikoBulletx[x], spikoBullety[x]);
                spikoBulletx[x] = spikoBulletx[x] + 1;
                printBulletspiko(spikoBulletx[x], spikoBullety[x]);
            }
        }
    }
}
void printbulletpikachu(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void printBulletMisty(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}
void printBulletDarco(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}
void printBulletspiko(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}
void makebulletinactivepikachu(int i)
{
    isbulletactive[i] = false;
}
void makeBulletInactiveDarco(int i)
{
    isBulletActiveDarco[i] = false;
}
void makeBulletInactivespiko(int i)
{
    isBulletActivespiko[i] = false;
}
void makeBulletInactivemisty(int i)
{
    isBulletActiveMisty[i] = false;
}
void erasebulletpikachu(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void eraseBulletspiko(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void eraseBulletMisty(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void eraswBulletDarco(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void bulletcollisionwithpikachuofmisty(int &pikachuhealthcounter, int &pikachux, int &pikachuy)
{
    for (int x = 0; x < mistyBulletCount; x++)
    {
        if (isBulletActiveMisty[x] == true)
        {
            if (mistyBulletx[x] - 2 == pikachux && (mistyBullety[x] == pikachuy || mistyBullety[x] == pikachuy + 1) && isfacingleftmisty[x] == true)
            {
                pikachuhealth(pikachuhealthcounter);
            }
            if (pikachux + 2 == mistyBulletx[x] && pikachuy + 1 == mistyBullety[x])
            {
                pikachuhealth(pikachuhealthcounter);
            }
            if (mistyBulletx[x] + 2 == pikachux && (mistyBullety[x] == pikachuy || mistyBullety[x] == pikachuy + 1) && isfacingleftmisty[x] == false)
            {
                pikachuhealth(pikachuhealthcounter);
            }
            if (pikachux + 2 == mistyBulletx[x] && pikachuy + 1 == mistyBullety[x])
            {
                pikachuhealth(pikachuhealthcounter);
            }
        }
    }
}
void bulletcollisionwithpikachuofdarco(int &pikachuhealthcounter, int &pikachux, int &pikachuy)
{
    for (int x = 0; x < darcoBulletCount; x++)
    {
        if (isBulletActiveDarco[x] == true)
        {
            if (darcoBulletx[x] + 2 == pikachux && (darcoBullety[x] == pikachuy || darcoBullety[x] == pikachuy + 1))
            {
                pikachuhealth(pikachuhealthcounter);
            }
            if (pikachux + 2 == darcoBulletx[x] && pikachuy + 1 == darcoBullety[x])
            {
                pikachuhealth(pikachuhealthcounter);
            }
        }
    }
}
void bulletcollisionwithpikachuofspiko(int &pikachuhealthcounter, int &pikachux, int &pikachuy)
{
    for (int x = 0; x < spikoBulletCount; x++)
    {
        if (isBulletActivespiko[x] == true)
        {
            if (spikoBulletx[x] + 2 == pikachux && (spikoBullety[x] == pikachuy || spikoBullety[x] == pikachuy + 1))
            {
                pikachuhealth(pikachuhealthcounter);
            }
            if (pikachux - 1 == spikoBulletx[x] && pikachuy + 1 == spikoBullety[x])
            {
                pikachuhealth(pikachuhealthcounter);
            }
        }
    }
}
void bulletcollisionwitspiko(int &spikohealthcounter, int &spikox, int &spikoy)
{
    for (int x = 0; x < pikachuBulletcount; x++)
    {
        if (isbulletactive[x] == true)
        {
            if (pikachubulletx[x] + 2 == spikox && (pikachubullety[x] == spikoy || pikachubullety[x] == spikoy + 1) && isfacingleft[x] == false)
            {
                spikohealth(spikohealthcounter);
            }
            if (spikox + 1 == pikachubulletx[x] && spikoy + 1 == pikachubullety[x] && isfacingleft[x] == false)
            {
                spikohealth(spikohealthcounter);
            }
            if (pikachubulletx[x] - 2 == spikox && (pikachubullety[x] == spikoy || pikachubullety[x] == spikoy + 1) && isfacingleft[x] == true)
            {
                spikohealth(spikohealthcounter);
            }
            if (spikox + 1 == pikachubulletx[x] && spikoy + 1 == pikachubullety[x] && isfacingleft[x] == true)
            {
                spikohealth(spikohealthcounter);
            }
        }
    }
}
void bulletcollisionwithmisty(int &mistyhealthcounter, int &mistyx, int &mistyy)
{
    for (int x = 0; x < pikachuBulletcount; x++)
    {
        if (isbulletactive[x] == true)
        {
            if (pikachubulletx[x] + 1 == mistyx && (pikachubullety[x] == mistyy || pikachubullety[x] == mistyy + 1) && isfacingleft[x] == false)
            {
                mistyhealth(mistyhealthcounter);
            }
            if (mistyx - 1 == pikachubulletx[x] && mistyy + 1 == pikachubullety[x])
            {
                mistyhealth(mistyhealthcounter);
            }
        }
        if (pikachubulletx[x] - 1 == mistyx && (pikachubullety[x] == mistyy || pikachubullety[x] == mistyy + 1) && isfacingleft[x] == true)
        {
            mistyhealth(mistyhealthcounter);
        }
        if (mistyx - 1 == pikachubulletx[x] && mistyy + 1 == pikachubullety[x])
        {
            mistyhealth(mistyhealthcounter);
        }
    }
}
void bulletcollisionwithdarco(int &darcohealthcounter, int &darcox, int &darcoy)
{
    for (int x = 0; x < pikachuBulletcount; x++)
    {
        if (isbulletactive[x] == true)
        {
            if (pikachubulletx[x] + 1 == darcox && (pikachubullety[x] == darcoy || pikachubullety[x] == darcoy + 2) && isfacingleft[x] == false)
            {
                darcohealth(darcohealthcounter);
            }
            if (darcox - 1 == pikachubulletx[x] && darcoy + 1 == pikachubullety[x])
            {
                darcohealth(darcohealthcounter);
            }
            if (pikachubulletx[x] - 1 == darcox && (pikachubullety[x] == darcoy || pikachubullety[x] == darcoy + 2) && isfacingleft[x] == true)
            {
                darcohealth(darcohealthcounter);
            }
            if (darcox - 1 == pikachubulletx[x] && darcoy + 1 == pikachubullety[x])
            {
                darcohealth(darcohealthcounter);
            }
        }
    }
}
void addscore()
{
    score++;
}
void spikohealth(int &spikohealthcounter)
{
    spikohealthcounter--;
}
void mistyhealth(int &mistyhealthcounter)
{
    mistyhealthcounter--;
}
void darcohealth(int &darcohealthcounter)
{
    darcohealthcounter--;
}
void pikachuhealth(int &pikachuhealthcounter)
{
    pikachuhealthcounter--;
}
void printmistyhealth(int &mistyhealthcounter)
{
    if (mistyhealthcounter >= 0)
    {
        gotoxy(106, 5);
        cout << "misty health:" << mistyhealthcounter;
    }
    else if (mistyhealthcounter < 0)
    {
        gotoxy(106, 5);
        cout << "            Died";
    }
}
void printspikohealth(int &spikohealthcounter)
{
    if (spikohealthcounter >= 0)
    {
        gotoxy(105, 3);
        cout << "spiko health:" << spikohealthcounter;
    }
    else if (spikohealthcounter < 0)
    {
        gotoxy(105, 3);
        cout << "            Died";
    }
}
void printdarcohealth(int &darcohealthcounter)
{
    if (darcohealthcounter > 0)
    {
        gotoxy(105, 4);
        cout << "darco health" << darcohealthcounter;
    }
    else if (darcohealthcounter <= 0)
    {
        gotoxy(105, 4);
        cout << "            Died";
    }
}
void printpikachuhealth(int &pikachuhealthcounter, int &pikachux, int &pikachuy)
{
    if (pikachuhealthcounter >= 0)
    {
        gotoxy(105, 6);
        cout << "Pikachu Health:" << pikachuhealthcounter << " ";
    }
    else if (pikachuhealthcounter == 0)
    {
        gotoxy(105, 6);
        cout << "             Died";
    }
}
void printBulletDetail()
{
    if (totalbullet >= 0)
    {
        gotoxy(105, 7);
        cout << "Bullets Left: " << totalbullet << " ";
    }
    else if (totalbullet < 0)
    {
        gotoxy(105, 7);
        cout << "             Refill required";
    }
}
void printscore()
{
    gotoxy(105, 1);
    cout << "Fish:" << score;
}
void gameover()
{
    SetConsoleTextAttribute(color, 15);
    cout << " ::::::::      :::     ::::    ::::  ::::::::::   ::::::::  :::     ::: :::::::::: ::::::::: " << endl;
    cout << ":+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:         :+:    :+: :+:     :+: :+:        :+:    :+: " << endl;
    cout << "+:+         +:+   +:+  +:+ +:+:+ +:+ +:+         +:+    +:+ +:+     +:+ +:+        +:+    +:+" << endl;
    cout << ":#:        +#++:++#++: +#+  +:+  +#+ +#++:++#    +#+    +:+ +#+     +:+ +#++:++#   +#++:++#:  " << endl;
    cout << "+#+   +#+# +#+     +#+ +#+       +#+ +#+         +#+    +#+  +#+   +#+  +#+        +#+    +#+ " << endl;
    cout << "#+#    #+# #+#     #+# #+#       #+# #+#         #+#    #+#   #+#+#+#   #+#        #+#    #+# " << endl;
    cout << "########  ###     ### ###       ### ##########   ########      ###     ########## ###    ### " << endl;
    cout << "YOU HAVE COLLECTED " << score << " FISHES" << endl;
}
void readMazeFromFile(char maze[][MAX_ROWS], int &numRows, int &numCols)
{
    ifstream file("maze.txt");
    if (file.is_open())
    {
        string line;
        getline(file, line);
        numCols = line.length();
        maze[0][numCols] = {};
        int i = 0;
        while (getline(file, line))
        {
            numRows++;
            for (int j = 0; j < numCols; j++)
            {
                maze[i][j] = line[j];
            }
            i++;
        }
        file.close();
    }
}
