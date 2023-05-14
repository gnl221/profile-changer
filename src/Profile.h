//
// Created by GNL22 on 5/14/2023.
//

//#ifndef PROFILE_CHANGER_PROFILE_H
//#define PROFILE_CHANGER_PROFILE_H

#ifndef PROFILE_H
#define PROFILE_H

#include <QString>

class Profile {
public:
    Profile(const QString &name = "", const QString &settingsPath = "");

    QString name() const;
    void setName(const QString &name) { m_name = name; }

    QString settingsPath() const;
    void setSettingsPath(const QString &settingsPath) { m_settingsPath = settingsPath; }

private:
    QString m_name;
    QString m_settingsPath;
};

#endif // PROFILE_H


//#endif //PROFILE_CHANGER_PROFILE_H
