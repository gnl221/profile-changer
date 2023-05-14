//
// Created by GNL22 on 5/14/2023.
//

#include "Profile.h"

Profile::Profile(const QString &name, const QString &settingsPath)
        : m_name(name), m_settingsPath(settingsPath) {}

QString Profile::name() const {
    return m_name;
}

void Profile::setName(const QString &name) {
    m_name = name;
}

QString Profile::settingsPath() const {
    return m_settingsPath;
}

void Profile::setSettingsPath(const QString &settingsPath) {
    m_settingsPath = settingsPath;
}

