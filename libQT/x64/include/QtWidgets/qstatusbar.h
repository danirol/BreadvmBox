/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtWidgets module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSTATUSBAR_H
#define QSTATUSBAR_H

#include <QtWidgets/qwidget.h>

QT_BEGIN_NAMESPACE


#ifndef QT_NO_STATUSBAR

class QStatusBarPrivate;

class Q_WIDGETS_EXPORT QStatusBar: public QWidget
{
    Q_OBJECT

    Q_PROPERTY(bool sizeGripEnabled READ isSizeGripEnabled WRITE setSizeGripEnabled)

public:
    explicit QStatusBar(QWidget *parent = Q_NULLPTR);
    virtual ~QStatusBar();

    void addWidget(QWidget *widget, int stretch = 0);
    int insertWidget(int index, QWidget *widget, int stretch = 0);
    void addPermanentWidget(QWidget *widget, int stretch = 0);
    int insertPermanentWidget(int index, QWidget *widget, int stretch = 0);
    void removeWidget(QWidget *widget);

    void setSizeGripEnabled(bool);
    bool isSizeGripEnabled() const;

    QString currentMessage() const;

public Q_SLOTS:
    void showMessage(const QString &text, int timeout = 0);
    void clearMessage();


Q_SIGNALS:
    void messageChanged(const QString &text);

protected:
    void showEvent(QShowEvent *) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *) Q_DECL_OVERRIDE;

    // ### Qt 6: consider making reformat() and hideOrShow() private
    void reformat();
    void hideOrShow();
    bool event(QEvent *) Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(QStatusBar)
    Q_DECLARE_PRIVATE(QStatusBar)
};

#endif // QT_NO_STATUSBAR

QT_END_NAMESPACE

#endif // QSTATUSBAR_H
