#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    // Initialize GUI components
    // Initialize File Menu
    fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *newProfileAction = new QAction(tr("&New Profile"), this);
    QAction *deleteProfileAction = new QAction(tr("&Delete Profile"), this);
    fileMenu->addAction(newProfileAction);
    fileMenu->addAction(deleteProfileAction);

    // Initialize Settings Menu
    settingsMenu = menuBar()->addMenu(tr("&Settings"));

    QAction *switchThemeAction = new QAction(tr("&Switch Theme"), this);
    settingsMenu->addAction(switchThemeAction);

    // Initialize Line Edit for Profile Name
    profileName = new QLineEdit(this);

    // Initialize Buttons
    launchButton = new QPushButton(tr("Launch"), this);
    updateButton = new QPushButton(tr("Update"), this);

    ui->setupUi(this);

    profileListWidget = new QListWidget(this);
    mainLayout = new QVBoxLayout; // Initialize the layout

    mainLayout->addWidget(profileListWidget); // Add the list widget to the layout

    // If you have a central widget set in your main window
    // You will want to set the layout to the central widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);

    // Connect slots
    connect(ui->selectSettingsFileButton, &QPushButton::clicked, this, &MainWindow::selectSettingsFile);
    connect(newProfileAction, &QAction::triggered, this, &MainWindow::newProfile);
    connect(deleteProfileAction, &QAction::triggered, this, &MainWindow::deleteProfile);
    connect(switchThemeAction, &QAction::triggered, this, &MainWindow::switchTheme);
    connect(launchButton, &QPushButton::clicked, this, &MainWindow::launchProfile);
    connect(updateButton, &QPushButton::clicked, this, &MainWindow::updateProfile);
    // Connect other slots

}

void MainWindow::newProfile() {
    // Ask the user for the profile name
    profileListWidget->addItem(newProfile.name());
    bool ok;
    QString text = QInputDialog::getText(this, tr("New Profile"),
                                         tr("Profile name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty()) {
        // Create a new profile
        Profile newProfile;
        newProfile.setName(text);

        // Create a new directory for the profile
        QDir dir;
        QString path = "profiles/" + text; // Modify this path as needed
        if (dir.mkpath(path)) {
            newProfile.setSettingsPath(path);
        } else {
            // Handle the error
            QMessageBox::critical(this, tr("Error"), tr("Could not create directory for the new profile."));
            return;
        }

        // Add the new profile to your list of profiles
        // Assume profiles is a QList<Profile> member of MainWindow
        profiles.append(newProfile);

        // Refresh the profile list in the GUI
        // Assume profileListWidget is a QListWidget member of MainWindow
        profileListWidget->addItem(newProfile.name());
    }
}


void MainWindow::deleteProfile() {
    // Check if there are profiles to delete
    delete profileListWidget->takeItem(i);
    if (profiles.empty()) {
        QMessageBox::information(this, tr("Delete Profile"), tr("No profiles to delete."));
        return;
    }

    // Ask the user which profile they want to delete
    bool ok;
    QStringList profileNames;
    for (const Profile &profile : profiles) {
        profileNames.append(profile.name);
    }
    QString text = QInputDialog::getItem(this, tr("Delete Profile"),
                                         tr("Select profile to delete:"), profileNames, 0, false, &ok);
    if (ok && !text.isEmpty()) {
        // Find and delete the profile
        for (int i = 0; i < profiles.size(); ++i) {
            if (profiles[i].name == text) {
                // Remove the profile's directory
                QDir dir(profiles[i].settingsPath);
                if (!dir.removeRecursively()) {
                    // Handle the error
                    QMessageBox::critical(this, tr("Error"), tr("Could not delete the profile's directory."));
                    return;
                }

                // Remove the profile from the list
                profiles.removeAt(i);

                // Refresh the profile list in the GUI
                delete profileListWidget->takeItem(i);
                break;
            }
        }
    }
}


void MainWindow::selectSettingsFile() {
    // Open a file dialog to select the settings file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select Settings File"),
                                                    "", tr("Settings Files (*.ini *.cfg);;All Files (*)"));
    if (!fileName.isEmpty()) {
        // Store the selected settings file path
        // Assume settingsFilePath is a QLineEdit member of MainWindow
        settingsFilePath->setText(fileName);
    }
}


void MainWindow::selectExecutable() {
    // Open a file dialog to select the executable
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select Executable"),
                                                    "", tr("Executable Files (*.exe);;All Files (*)"));
    if (!fileName.isEmpty()) {
        // Store the selected executable file path
        // Assume executableFilePath is a QLineEdit member of MainWindow
        executableFilePath->setText(fileName);
    }
}


void MainWindow::switchTheme() {
    // Assuming darkMode is a boolean member of MainWindow
    if (darkMode) {
        // Switch to light mode
        qApp->setStyleSheet("");
    } else {
        // Switch to dark mode
        QFile file(":/dark.qss");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        qApp->setStyleSheet(styleSheet);
    }

    // Toggle darkMode
    darkMode = !darkMode;
}


void MainWindow::launchProfile() {
    // Assuming selectedProfile is a Profile member of MainWindow
    // Copy the settings file to the correct directory
    QString sourcePath = selectedProfile.settingsPath + "/settings.ini"; // Modify this as needed
    QString destPath = settingsFilePath->text();
    if (QFile::copy(sourcePath, destPath)) {
        // Launch the executable
        QProcess::startDetached(executableFilePath->text());
    } else {
        // Handle the error
        QMessageBox::critical(this, tr("Error"), tr("Could not copy the settings file."));
    }
}


void MainWindow::updateProfile() {
    // Assuming selectedProfile is a Profile member of MainWindow
    // Copy the settings file from the correct directory to the profile's directory
    QString sourcePath = settingsFilePath->text();
    QString destPath = selectedProfile.settingsPath + "/settings.ini"; // Modify this as needed
    if (!QFile::copy(sourcePath, destPath)) {
        // Handle the error
        QMessageBox::critical(this, tr("Error"), tr("Could not copy the settings file."));
    }
}


