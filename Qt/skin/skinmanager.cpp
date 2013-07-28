#include "skinmanager.h"
#include "uicommonframe.h"

SkinManager::SkinManager(QObject *parent) :
    QObject(parent),
    m_bPictureEnable(true),
    m_color(156, 156, 156, 255)
{

    QObject::connect(this, SIGNAL(backgroundChanged()), this, SLOT(updateAll()));
}

SkinManager::~SkinManager()
{
    clear();
}

SkinManager &SkinManager::instance()
{
    static SkinManager inst;
    return inst;
}

bool SkinManager::init()
{
    clear();
    setColor(255, 255, 255, 255);
    return true;
}

bool SkinManager::deInit()
{
    clear();
    return true;
}

bool SkinManager::addObject(UICommonFrame *obj)
{
    m_items.push_back(obj);
    return true;
}

bool SkinManager::removeObject(UICommonFrame *obj)
{
    return m_items.removeOne(obj);
}

void SkinManager::clear()
{
    m_items.clear();
}

void SkinManager::setColorR(int r)
{
    m_color.setRed(r);
    emit backgroundChanged();
}

void SkinManager::setColorG(int g)
{
    m_color.setGreen(g);
    emit backgroundChanged();
}

void SkinManager::setColorB(int b)
{
    m_color.setBlue(b);
    emit backgroundChanged();
}

void SkinManager::setColorA(int a)
{
    m_color.setAlpha(a);
    emit backgroundChanged();
}

void SkinManager::setColor(int r, int g, int b, int a)
{
    m_color = QColor(r, g, b, a);
    emit backgroundChanged();
}

QColor SkinManager::getColor() const
{
    return m_color;
}

void SkinManager::setPictureEnable(bool enable)
{
    m_bPictureEnable = enable;
    emit backgroundChanged();
}

bool SkinManager::getPictureEnable() const
{
    return m_bPictureEnable;

}

void SkinManager::setPicture(const QString &picturePath)
{
    m_pixmap.load(picturePath);
    if(m_pixmap.hasAlphaChannel())
    {
        qDebug("has alpha channel");
    }
    if(m_pixmap.hasAlpha())
    {
        qDebug("has alpha");
    }
    emit backgroundChanged();
}

void SkinManager::setPicture(const QPixmap &pixmap)
{
    m_pixmap = pixmap;
}

const QPixmap &SkinManager::getPicture() const
{
    return m_pixmap;
}


void SkinManager::updateAll()
{
    foreach(UICommonFrame* frame, m_items)
    {
        frame->update();
    }
}
