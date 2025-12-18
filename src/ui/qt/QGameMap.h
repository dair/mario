#ifndef QGAMEMAP_H
#define QGAMEMAP_H

#include <QObject>
#include <unordered_set>
#include <memory>
#include "game_map.hpp"
#import "QUIObject.h"

class QGameMap : public QObject, public biv::GameMap
{
    Q_OBJECT
private:
    std::unordered_set<std::shared_ptr<QUIObject>> objects;

public:
    QGameMap(
            const int height,
            const int width,
            QObject *parent=nullptr
            );

    virtual void clear() noexcept;
    virtual void refresh() noexcept;
    virtual void remove_objs();
    virtual void show() const noexcept;

    void remove_obj(std::shared_ptr<QUIObject> object);
    void add_obj(std::shared_ptr<QUIObject> object);
};

#endif // QGAMEMAP_H
