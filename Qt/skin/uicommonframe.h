#ifndef UICOMMONFRAME_H
#define UICOMMONFRAME_H

#include <QFrame>
#include <QIcon>

namespace Ui {
class UICommonFrame;
}

class UICommonFrame : public QFrame
{
    Q_OBJECT
    enum ResizeDirection{  LEFT, TOP_LEFT, TOP, TOP_RIGHT, RIGHT, BOTTOM_RIGHT, BOTTOM, BOTTOM_LEFT, CENTER };
    
public:
    explicit UICommonFrame(QWidget* centerWidget = 0, QWidget *parent = 0);
    ~UICommonFrame();

    void setCenterWidget(QWidget* center);

    void setResizeable(bool bResizeable);
    bool getResizeable() const;

    void setTitleBarIcon(const QString& iconPath);
    void setTitleBarIcon(const QIcon& icon);
    QIcon& getTileBarIcon() const;

    void setTitleBarText(const QString& text);
    QString getTitleBarText() const;


protected:
    void paintEvent(QPaintEvent *);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    void childEvent(QChildEvent *);

    bool eventFilter(QObject *, QEvent *);
    
private:
    bool m_bMove;
    bool m_bResizeable;
    qreal m_roundRadius;
    ResizeDirection m_direction;
    QPoint m_prevPos;
    QPoint dragPosition;
    QString m_titleBarText;
    QIcon m_titleBarIcon;
    Ui::UICommonFrame *ui;
};

#endif // UICOMMONFRAME_H
