#ifndef QGAMEWINDOW_H
#define QGAMEWINDOW_H

#include <QObject>
#include <QWidget>

class QGameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QGameWindow(QWidget *parent = nullptr);
	void resizeEvent(QResizeEvent *event) override;
signals:

};

#endif // QGAMEWINDOW_H
