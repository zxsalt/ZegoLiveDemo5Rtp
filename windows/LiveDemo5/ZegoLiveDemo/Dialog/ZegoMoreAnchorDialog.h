﻿#pragma execution_character_set("utf-8")

#ifndef ZEGOMOREANCHORDIALOG_H
#define ZEGOMOREANCHORDIALOG_H

#include "Base/ZegoBaseDialog.h"

class ZegoMoreAnchorDialog : public ZegoBaseDialog
{
	Q_OBJECT

public:
	ZegoMoreAnchorDialog(QWidget *parent = 0);
	ZegoMoreAnchorDialog(qreal dpi, SettingsPtr curSettings, RoomPtr room, QString curUserID, QString curUserName, QDialog *lastDialog, QDialog *parent = 0);
	~ZegoMoreAnchorDialog();
	void initDialog();

protected slots:
	void OnLoginRoom(int errorCode, const QString& roomId, QVector<StreamPtr> vStreamList);
	void OnStreamUpdated(const QString& roomId, QVector<StreamPtr> vStreamList, LIVEROOM::ZegoStreamUpdateType type);
	void OnPublishStateUpdate(int stateCode, const QString& streamId, StreamPtr streamInfo);
	void OnPlayStateUpdate(int stateCode, const QString& streamId);
	void OnJoinLiveRequest(int seq, const QString& fromUserId, const QString& fromUserName, const QString& roomId);


private slots:
    void OnButtonSwitchPublish();

private:
	void StartPublishStream();
	void StopPublishStream(const QString& streamID);
	void StartPlayStream(StreamPtr stream);
	void StopPlayStream(const QString& streamID);
	bool praseJsonData(QJsonDocument doc);
	void GetOut();
	
private:
	
	QString m_strPublishStreamID;
	QString m_strCurUserID;
	QString m_strCurUserName;	
	bool m_bIsPublishing = false;
};

#endif
