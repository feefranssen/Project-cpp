#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Start/restart knop
    connect(ui->startButton, &QPushButton::clicked, this, [this]() {
        game.resetGame();       // maak hero + enemy opnieuw aan
        ui->textEdit->clear();  // log leegmaken
        ui->textEdit->append("Game gestart!");
        updateLabels();
        ui->stepButton->setEnabled(true);
    });

    // Step knop → 1 ronde hero-aanval
    connect(ui->stepButton, &QPushButton::clicked, this, [this]() {
        game.stepCombat();
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

    // Step knop disablen als hero of enemy dood is
    if (game.getHeroHP() <= 0 || game.getEnemyHP() <= 0)
        ui->stepButton->setEnabled(false);
    else
        ui->stepButton->setEnabled(true);
}
