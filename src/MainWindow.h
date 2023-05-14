//
// Created by GNL22 on 5/14/2023.
//

#ifndef PROFILE_CHANGER_MAINWINDOW_H
#define PROFILE_CHANGER_MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // GUI components
    QMenu *fileMenu;
    QMenu *settingsMenu;
    QPushButton *launchButton;
    QPushButton *updateButton;
    QLineEdit *profileName;
    QLineEdit *settingsFilePath;
    QLineEdit *executableFilePath;
    // Other members to store profiles and their settings
    ...

    // Slots for handling GUI events
private slots:
            void newProfile();
    void deleteProfile();
    void selectSettingsFile();
    void selectExecutable();
    void switchTheme();
    void launchProfile();
    void updateProfile();
};

#endif //PROFILE_CHANGER_MAINWINDOW_H
