#include "Game.h"

int main() {
    Game::Game game;
    game.startGame();    // Vraag 2 – clean main (logica zit in Game class)
    return 0;
}


//Vraag 7 – Project compiles & does not crash


/*
 //vervang de main code hierdoor om de gui te builden


#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);     // Vraag 47 usage of a GUI
    MainWindow w;
    w.show();
    return a.exec();
}


 */
