#ifndef SKINMANAGER_H
#define SKINMANAGER_H

#include <QObject>
#include <QList>
#include <QColor>
#include <QPixmap>

class UICommonFrame;

class SkinManager : public QObject
{
    Q_OBJECT
public:
    explicit SkinManager(QObject *parent = 0);

    ~SkinManager();

    static SkinManager& instance();

    bool init();
    bool deInit();

    bool addObject(UICommonFrame* obj);
    bool removeObject(UICommonFrame* obj);

    void clear();

    void setColorR(int r);
    void setColorG(int g);
    void setColorB(int b);
    void setColorA(int a);
    void setColor(int r, int g, int b, int a = 255);

    QColor getColor() const;

    void setPictureEnable(bool enable);
    bool getPictureEnable() const;

    void setPicture(const QString& picturePath);
    void setPicture(const QPixmap& pixmap);

    const QPixmap& getPicture() const;
    
signals:
    void backgroundChanged();
    
public slots:
    void updateAll();

private:
    bool m_bPictureEnable;
    QPixmap m_pixmap;
    QColor m_color;
    QList<UICommonFrame*> m_items;
    
};

#define GlobalSkinManager() SkinManager::instance()

#endif // SKINMANAGER_H
