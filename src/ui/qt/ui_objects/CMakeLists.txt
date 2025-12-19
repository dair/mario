target_sources(${PROJECT_NAME}
	PRIVATE
	QBox.cpp
	QEnemy.cpp
	QJumpEnemy.cpp
	QFlyEnemy.cpp
	QFullBox.cpp
	QMario.cpp
        QUIObject.cpp
	QMoney.cpp
	QShip.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
