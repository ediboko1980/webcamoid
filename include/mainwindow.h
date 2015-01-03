/* Webcamoid, webcam capture application.
 * Copyright (C) 2011-2014  Gonzalo Exequiel Pedone
 *
 * Webcamod is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamod is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamod. If not, see <http://www.gnu.org/licenses/>.
 *
 * Email     : hipersayan DOT x AT gmail DOT com
 * Web-Site 1: http://github.com/hipersayanX/Webcamoid
 * Web-Site 2: http://opendesktop.org/content/show.php/Webcamoid?content=144796
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <QResizeEvent>

#include "generalconfig.h"
#include "streamsconfig.h"
#include "mediatools.h"
#include "videorecordconfig.h"
#include "cameraconfig.h"
#include "imagedisplay.h"
#include "configdialog.h"
#include "about.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow: public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent=NULL);

    private:
        QSharedPointer<Ui::MainWindow> ui;

        GeneralConfig *m_cfgGeneralConfig;
        QbPacket m_webcamFrame;
        StreamsConfig *m_cfgStreams;
        MediaTools *m_mediaTools;
        VideoRecordConfig *m_cfgVideoFormats;
        CameraConfig *m_cfgWebcamDialog;
        ImageDisplay *m_imageDispay;

        void showConfigDialog(ConfigDialog *configDialog=NULL);
        QString saveFile(bool video=false);

    protected:
        void changeEvent(QEvent *event);
        void resizeEvent(QResizeEvent *event);
        void enterEvent(QEvent *event);
        void leaveEvent(QEvent *event);
        void closeEvent(QCloseEvent *event);

    public slots:
        void addWebcamConfigDialog(ConfigDialog *configDialog);
        void addVideoFormatsConfigDialog(ConfigDialog *configDialog);
        void addStreamsConfigDialog(ConfigDialog *configDialog);
        void addGeneralConfigsDialog(ConfigDialog *configDialog);
        void showFrame(const QbPacket &webcamFrame);

    private slots:
        void updateWebcams();
        void stateChanged();
        void recordingChanged(bool recording);
        void showError(const QString &message);
        void updateContents();

        void on_btnTakePhoto_clicked();
        void on_btnVideoRecord_clicked();
        void on_cbxSetWebcam_currentIndexChanged(int index);
        void on_btnStartStop_clicked();
        void on_btnConfigure_clicked();
        void on_btnAbout_clicked();
};

#endif // MAINWINDOW_H