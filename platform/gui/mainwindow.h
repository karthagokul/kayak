#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected slots:
    void showCanLogView();
    void showCanSettings();
    void showCanFrameGenerator();
private:
    void addSubWindow(QWidget *widget);
private:
    Ui::MainWindow *ui;
    QMdiArea *mdiArea;
};
#endif // MAINWINDOW_H
