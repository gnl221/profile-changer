//
// Created by GNL22 on 5/14/2023.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>
#include <QFile>
#include <QProcess>
#include <QFileDialog>
#include <QAction>
#include <QMenuBar>
#include <QLineEdit>
#include <QPushButton>
#include <QList>
#include "Profile.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Slots for handling GUI events
private slots:
    void newProfile();
    void deleteProfile();
    void selectSettingsFile();
    void selectExecutable();
    void switchTheme();
    void launchProfile();
    void updateProfile();

private:
    // GUI components
    Ui::MainWindow *ui;
    QVBoxLayout *mainLayout;
    QListWidget *profileListWidget;
    QMenu *fileMenu;
    QMenu *settingsMenu;
    QPushButton *launchButton;
    QPushButton *updateButton;
    QLineEdit *profileName;
    QLineEdit *settingsFilePath;
    QLineEdit *executableFilePath;
    QList<Profile> profiles;
    // Other members to store profiles and their settings

};

#endif // MAINWINDOW_H
