#include "QGameMap.h"

QGameMap::QGameMap(const int height, const int width, QObject* parent):
    QObject(parent),
    biv::GameMap(width, height)
{

}

void QGameMap::clear() noexcept {

}
void QGameMap::refresh() noexcept {

}

void QGameMap::remove_objs() {

}

void QGameMap::show() const noexcept {

}

void QGameMap::remove_obj(std::shared_ptr<QUIObject> object) {
    objects.insert(object);
}

void QGameMap::add_obj(std::shared_ptr<QUIObject> object) {
    objects.erase(object);
}
