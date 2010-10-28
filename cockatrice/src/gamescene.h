#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QList>

class Player;
class ZoneViewWidget;
class CardZone;
class ServerInfo_Card;

class GameScene : public QGraphicsScene {
	Q_OBJECT
private:
	static const int playerAreaSpacing = 5;
	
	QList<Player *> players;
	QRectF playersRect;
	QList<ZoneViewWidget *> views;
	QSize viewSize;
public:
	GameScene(QObject *parent = 0);
	void retranslateUi();
	const QRectF &getPlayersRect() const { return playersRect; }
	void processViewSizeChange(const QSize &newSize);
public slots:
	void toggleZoneView(Player *player, const QString &zoneName, int numberCards);
	void addRevealedZoneView(Player *player, CardZone *zone, const QList<ServerInfo_Card *> &cardList);
	void removeZoneView(ZoneViewWidget *item);
	void addPlayer(Player *player);
	void removePlayer(Player *player);
	void clearViews();
	void closeMostRecentZoneView();
private slots:
	void rearrange();
};

#endif
