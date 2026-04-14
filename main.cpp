#include "databasemanager.h"
#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    qputenv("QT_QPA_PLATFORM", "windows:darkmode=0");
    QApplication a(argc, argv);

    QApplication::setStyle("Fusion");

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TimeManagementApplication_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    DatabaseManager::instance();

    // Add the test data
    DatabaseManager::instance().addTestEmployee();

    MainWindow w;
    //w.show();
    w.showMaximized();
    return a.exec();
}
