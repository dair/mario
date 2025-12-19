#ifndef QGAME_H
#define QGAME_H

#include <QObject>
//#include "console_ui_factory.hpp"
#include "ui_factory.hpp"
#include "first_level.hpp"
#include "game.hpp"
#include "game_level.hpp"
#include "game_map.hpp"
#include "mario.hpp"
#include "os_control_settings.hpp"
#include "ui_factory.hpp"
#include "user_input.hpp"

class QGame : public QObject
{
    Q_OBJECT
private:
    biv::Game game;
    biv::UIFactory* ui_factory;
    biv::GameMap* game_map;
    biv::GameLevel* game_level;
    biv::Mario* mario;
	int keyEvents;

	void processKeyEvent();

public:
	explicit QGame(QWidget* widgetParent, QObject *parent = nullptr);
    virtual ~QGame();

public slots:
    void onTimer();
	void onKeyEvent(int input);

signals:
    void gameOver();

};


#endif // QGAME_H
