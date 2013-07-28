#include "uicommonframe.h"
#include "ui_uicommonframe.h"
#include "skinmanager.h"
#include <QMouseEvent>
#include <QPainter>
#include <QBitmap>
#include <QPixmap>
#include <QDebug>

#define RESIZE_BOX_SIZE 3

UICommonFrame::UICommonFrame(QWidget *centerWidget, QWidget *parent) :
    QFrame(parent),
    m_bMove(true),
    m_bResizeable(true),
    m_direction(CENTER),
    m_roundRadius(5.0),
    ui(new Ui::UICommonFrame)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_NoSystemBackground);
    ui->setupUi(this);

    ui->frame->setMouseTracking(true);
    ui->widget->setMouseTracking(true);

    setCenterWidget(centerWidget);

    this->setMouseTracking(true);

    GlobalSkinManager().addObject(this);
}

UICommonFrame::~UICommonFrame()
{
    delete ui;
    GlobalSkinManager().removeObject(this);
}

void UICommonFrame::setCenterWidget(QWidget *center)
{
    if(center != NULL)
    {
        QWidget* temp = ui->widget;
        ui->widget = center;
        temp->setParent(NULL);
        delete temp;
        temp = NULL;
        center->setMouseTracking(true);
        ui->verticalLayout->addWidget(ui->widget);
        resize(center->size());
    }
}

void UICommonFrame::setResizeable(bool bResizeable)
{
    m_bResizeable = bResizeable;
}

bool UICommonFrame::getResizeable() const
{
    return m_bResizeable;
}

void UICommonFrame::setTitleBarIcon(const QString &iconPath)
{
    m_titleBarIcon = QIcon(iconPath);
    ui->pushButton_2->setIcon(m_titleBarIcon);
}

QString UICommonFrame::getTitleBarText() const
{
    return m_titleBarText;
}


void UICommonFrame::setTitleBarText(const QString &text)
{
    m_titleBarText = text;
    ui->pushButton_2->setWindowIconText(text);
}

void UICommonFrame::setTitleBarIcon(const QIcon &icon)
{
    m_titleBarIcon = icon;
    ui->pushButton_2->setIcon(m_titleBarIcon);
}

void UICommonFrame::paintEvent(QPaintEvent *)
{

    QPainter p;

    QBitmap bmp(this->size());
    bmp.fill(QColor(255, 255, 255));

    p.begin(&bmp);

    p.setRenderHint(QPainter::Antialiasing);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(), m_roundRadius, m_roundRadius);

    p.end();

    this->setMask(bmp);

    p.begin(this);

    if(GlobalSkinManager().getPictureEnable() && !GlobalSkinManager().getPicture().isNull())
    {
        p.setCompositionMode(QPainter::CompositionMode_Plus);
        p.drawPixmap(this->rect(), GlobalSkinManager().getPicture());
    }

    p.setBrush(GlobalSkinManager().getColor());
    p.drawRoundedRect(this->rect().adjusted(0, 0, -1, -1), m_roundRadius, m_roundRadius);

    p.end();
}

void UICommonFrame::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bMove = m_direction == CENTER ? true : false;

        dragPosition = event->globalPos() - frameGeometry().topLeft();
        m_prevPos = event->globalPos();
        event->accept();
    }

}

void UICommonFrame::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        if(m_bMove == true)
        {
            move(event->globalPos() - dragPosition);
        }
        else
        {
            if(m_direction == RIGHT)
            {
                qDebug("right");
                this->resize(this->width() + event->globalPos().x() - m_prevPos.x(), this->height() );
            }
            else if(m_direction == BOTTOM)
            {
                qDebug("bottom");
                this->resize(this->width(), this->height() + event->globalPos().y() - m_prevPos.y());
            }
            else if(m_direction == TOP)
            {
                qDebug("top");
                this->move(this->x(), this->y() + event->globalPos().y() - m_prevPos.y());
                this->resize(this->width(), this->height() + m_prevPos.y() - event->globalPos().y());
            }
            else if(m_direction == LEFT)
            {
                qDebug("left");
                this->move(this->x() + event->globalPos().x() - m_prevPos.x(), this->y());
                this->resize(this->width() + m_prevPos.x() - event->globalPos().x() , this->height());
            }
            else if(m_direction == TOP_LEFT)
            {
                qDebug("top left");
                this->move(this->x() + event->globalPos().x() - m_prevPos.x(), this->y() + event->globalPos().y() - m_prevPos.y() );
                this->resize(this->width() + m_prevPos.x() - event->globalPos().x(),
                             this->height() + m_prevPos.y() - event->globalPos().y());
            }
            else if(m_direction == TOP_RIGHT)
            {
                qDebug("top right");
                this->move(this->x(), this->y() + event->globalPos().y() - m_prevPos.y());
                this->resize(this->width() + event->globalPos().x() - m_prevPos.x(),
                             this->height() + m_prevPos.y() - event->globalPos().y());
            }
            else if(m_direction == BOTTOM_RIGHT)
            {
                qDebug("bottom right");
                this->resize(this->width() + event->globalPos().x() - m_prevPos.x(),
                             this->height() + event->globalPos().y() - m_prevPos.y());
            }
            else if(m_direction == BOTTOM_LEFT)
            {
                qDebug("bottom left");
                this->move(this->x() + event->globalPos().x() - m_prevPos.x(), this->y());
                this->resize(this->width() + m_prevPos.x() - event->globalPos().x(),
                             this->height() + event->globalPos().y() - m_prevPos.y());
            }
        }
        m_prevPos = event->globalPos();
        event->accept();
    }
    else
    {
        m_direction = CENTER;

        //if(!m_bResizeable) return;

        QRect rect = this->rect();
        QPoint topLeft = rect.topLeft();
        QPoint topRight = rect.topRight();
        QPoint bottomLeft = rect.bottomLeft();
        QPoint bottomRight = rect.bottomRight();

        qDebug() << rect;

        if(QRect(topLeft + QPoint(RESIZE_BOX_SIZE, RESIZE_BOX_SIZE), bottomRight - QPoint(RESIZE_BOX_SIZE, RESIZE_BOX_SIZE)).contains(event->pos()))
        {
            m_direction = CENTER;
            this->unsetCursor();
        }
        else
        {


            if(QRect(topLeft, topLeft+QPoint(RESIZE_BOX_SIZE, RESIZE_BOX_SIZE)).contains(event->pos()))
            {
                //左上
                m_direction = TOP_LEFT;
                this->setCursor(Qt::SizeFDiagCursor);
            }
            else if( QRect(bottomRight - QPoint(RESIZE_BOX_SIZE, RESIZE_BOX_SIZE), bottomRight).contains(event->pos()))
            {
                //右下
                m_direction = BOTTOM_RIGHT;
                this->setCursor(Qt::SizeFDiagCursor);
            }
            else if(QRect(topLeft + QPoint(RESIZE_BOX_SIZE, 0), topRight - QPoint(RESIZE_BOX_SIZE, -RESIZE_BOX_SIZE)).contains(event->pos()))
            {
                //上
                m_direction = TOP;
                this->setCursor(Qt::SizeVerCursor);
            }
            else if(QRect(bottomLeft - QPoint(-RESIZE_BOX_SIZE, RESIZE_BOX_SIZE), bottomRight - QPoint(RESIZE_BOX_SIZE, 0)).contains(event->pos()))
            {
                //下
                m_direction = BOTTOM;
                this->setCursor(Qt::SizeVerCursor);
            }
            else if(QRect(topRight - QPoint(RESIZE_BOX_SIZE, 0), topRight + QPoint(0, RESIZE_BOX_SIZE)).contains(event->pos()) )
            {
                //右上
                this->setCursor(Qt::SizeBDiagCursor);
                m_direction = TOP_RIGHT;
                qDebug("move top right");
            }
            else if(QRect(bottomLeft - QPoint(0, RESIZE_BOX_SIZE), bottomLeft + QPoint(RESIZE_BOX_SIZE, 0)).contains(event->pos()))
            {
                //左下
                m_direction = BOTTOM_LEFT;
                this->setCursor(Qt::SizeBDiagCursor);
            }
            else if(QRect(topLeft + QPoint(0, RESIZE_BOX_SIZE), bottomLeft + QPoint(RESIZE_BOX_SIZE, -RESIZE_BOX_SIZE)).contains(event->pos()))
            {
                //左
                m_direction = LEFT;
                this->setCursor(Qt::SizeHorCursor);
            }
            else if( QRect(topRight + QPoint(-RESIZE_BOX_SIZE, RESIZE_BOX_SIZE), bottomRight - QPoint(0, RESIZE_BOX_SIZE)).contains(event->pos()))
            {
                //右
                m_direction = RIGHT;
                this->setCursor(Qt::SizeHorCursor);
            }
        }
    }
}

void UICommonFrame::mouseReleaseEvent(QMouseEvent *event)
{
    m_direction = CENTER;
    m_bMove = true;
    this->unsetCursor();
    QFrame::mouseReleaseEvent(event);
}

void UICommonFrame::childEvent(QChildEvent *event)
{
    event->child()->installEventFilter(this);
    QFrame::childEvent(event);
}

bool UICommonFrame::eventFilter(QObject *obj, QEvent *event)
{
    Q_UNUSED(obj)
    if(event->type() == QEvent::MouseMove )
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        qApp->sendEvent(this, mouseEvent);
    }
    return QFrame::eventFilter(obj, event);
}



