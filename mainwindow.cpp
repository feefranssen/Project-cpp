#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Start/restart button
    connect(ui->startButton, &QPushButton::clicked, this, [this]() {
        game.resetGame(); // nieuwe functie in Game.cpp
        ui->textEdit->clear();
        ui->textEdit->append("Game gestart!");
        updateLabels();
    });

    // Step button → 1 ronde hero-aanval
    connect(ui->stepButton, &QPushButton::clicked, this, [this]() {
        game.stepCombat(); // minimale ronde
        ui->textEdit->append("Hero valt aan!");
        updateLabels();
    });

    // Initial labels
    updateLabels();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLabels() {
    ui->heroLabel->setText(QString::fromStdString("Hero HP: " + std::to_string(game.getHeroHP())));
    ui->enemyLabel->setText(QString::fromStdString("Enemy HP: " + std::to_string(game.getEnemyHP())));
}
