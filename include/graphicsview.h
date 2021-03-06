/*!
 * \file graphicsview.h
 * \author Caleb Amoa Buahin <caleb.buahin@gmail.com>
 * \version 1.0.0
 * \description
 * \license
 * This file and its associated files, and libraries are free software.
 * You can redistribute it and/or modify it under the terms of the
 * Lesser GNU Lesser General Public License as published by the Free Software Foundation;
 * either version 3 of the License, or (at your option) any later version.
 * This file and its associated files is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.(see <http://www.gnu.org/licenses/> for details)
 * \copyright Copyright 2014-2018, Caleb Buahin, All rights reserved.
 * \date 2014-2018
 * \pre
 * \bug
 * \warning
 * \todo
 */

#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGLWidget>
#include <QGraphicsView>
#include <QGraphicsRectItem>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

  public:

    enum Tool
    {
      Default,
      ZoomIn,
      ZoomOut,
      Pan,
    };

    GraphicsView(QWidget *parent);

    virtual ~GraphicsView();

  public slots:

    void onCurrentToolChanged(int currentTool);

  protected:

    void dragEnterEvent(QDragEnterEvent * event) override;

    void dragMoveEvent(QDragMoveEvent * event) override;

    void dropEvent(QDropEvent * event) override;

    void wheelEvent(QWheelEvent * event) override;

    void mousePressEvent(QMouseEvent * event) override;

    void mouseReleaseEvent(QMouseEvent * event) override;

    void mouseMoveEvent(QMouseEvent * event) override;

    bool viewportEvent(QEvent *event) override;

  private:

    QRectF getRectFrom(const QPointF &p1, const QPointF p2);

  signals:

    void mouseMapCoordinatesChanged(double mapX , double mapY, const QString &status);

  private:
    QPointF m_scenePosition;
    QPointF m_viewportPosition;
    QPointF m_mousePressPosition;
    bool m_mouseIsPressed, m_isBusy;
    Tool m_currentTool;
    QRectF m_zoomRect;
    QGraphicsRectItem m_zoomItem;
    qreal totalScaleFactor;
};

#endif // GRAPHICSVIEW_H
