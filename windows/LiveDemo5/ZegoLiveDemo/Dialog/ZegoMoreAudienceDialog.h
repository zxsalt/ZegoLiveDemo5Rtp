﻿#pragma execution_character_set("utf-8")

#ifndef ZEGOMOREAUDIENCEDIALOG_H
#define ZEGOMOREAUDIENCEDIALOG_H

#include "Base/ZegoBaseDialog.h"

class ZegoMoreAudienceDialog : public ZegoBaseDialog
{
	Q_OBJECT

public:
	ZegoMoreAudienceDialog(QWidget *parent = 0);
	ZegoMoreAudienceDialog(qreal dpi, SettingsPtr curSettings, RoomPtr room, QString curUserID, QString curUserName, QDialog *lastDialog, QDialog *parent = 0);
	~ZegoMoreAudienceDialog();
	void initDialog();

protected slots:
	void OnLoginRoom(int errorCode, const QString& roomId, QVector<StreamPtr> vStreamList);
	void OnStreamUpdated(const QString& roomId, QVector<StreamPtr> vStreamList, LIVEROOM::ZegoStreamUpdateType type);
	void OnPublishStateUpdate(int stateCode, const QString& streamId, StreamPtr streamInfo);
	void OnPlayStateUpdate(int stateCode, const QString& streamId);
	void OnJoinLiveResponse(int result, const QString& fromUserId, const QString& fromUserName, int seq);
	void OnRecvEndJoinLiveCommand(const QString& userId, const QString& userName, const QString& roomId);

private slots:
	void OnButtonJoinLive();

private:
	void StartPublishStream();
	void StopPublishStream(const QString& streamID);
	void StartPlayStream(StreamPtr stream);
	void StopPlayStream(const QString& streamID);
	void GetOut();
	bool praseFirstAnchorJsonData(QJsonDocument doc);
	void praseOtherAnchorJsonData(QJsonDocument doc);

private:
	bool m_bIsJoinLive = false;
	int m_iRequestJoinLiveSeq = -1;
	QString m_strPublishStreamID;
	QString m_strCurUserID;
	QString m_strCurUserName;

};

#endif
