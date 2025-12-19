#pragma once

#include <QWidget>
#include <unordered_set>
#include <memory>
#include "game_map.hpp"
#include "QUIObject.h"
#include "user_input.hpp"

class QGridLayout;

class QGameMap : public QWidget, public biv::GameMap
{
    Q_OBJECT
private:
	QSize cellSize{0, 0};

    std::unordered_set<std::shared_ptr<QUIObject>> objects;
	void positionObject(std::shared_ptr<QUIObject> object);

	int currentInput = (int)biv::os::UserInput::NO_INPUT;

protected:
	virtual void keyPressEvent(QKeyEvent *event) override;
	virtual void keyReleaseEvent(QKeyEvent *event) override;

public:
    QGameMap(
            const int height,
            const int width,
			QWidget *parent=nullptr
            );

	void resizeEvent(QResizeEvent *event) override;

    virtual void clear() noexcept;
    virtual void refresh() noexcept;
    virtual void remove_objs();
    virtual void show() const noexcept;

    void remove_obj(std::shared_ptr<QUIObject> object);
    void add_obj(std::shared_ptr<QUIObject> object);

signals:
	void userInput(int input);
};
