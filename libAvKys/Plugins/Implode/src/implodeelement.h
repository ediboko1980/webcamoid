/* Webcamoid, webcam capture application.
 * Copyright (C) 2011-2016  Gonzalo Exequiel Pedone
 *
 * Webcamoid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamoid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
 *
 * Email   : hipersayan DOT x AT gmail DOT com
 * Web-Site: http://github.com/hipersayanX/webcamoid
 */

#ifndef IMPLODEELEMENT_H
#define IMPLODEELEMENT_H

#include <QQmlComponent>
#include <QQmlContext>
#include <ak.h>
#include <akutils.h>

class ImplodeElement: public AkElement
{
    Q_OBJECT
    Q_PROPERTY(qreal amount
               READ amount
               WRITE setAmount
               RESET resetAmount
               NOTIFY amountChanged)

    public:
        explicit ImplodeElement();

        Q_INVOKABLE QObject *controlInterface(QQmlEngine *engine,
                                              const QString &controlId) const;

        Q_INVOKABLE qreal amount() const;

    private:
        qreal m_amount;

    signals:
        void amountChanged(qreal amount);

    public slots:
        void setAmount(qreal amount);
        void resetAmount();
        AkPacket iStream(const AkPacket &packet);
};

#endif // IMPLODEELEMENT_H