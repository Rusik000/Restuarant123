#pragma once

#include"AllNotification.h"
#include <vector>

class Not {
	vector<Notification> notifications;
public:
	Not() :notifications(NULL) {}

	void addNotification(Notification notification) {
		notifications.push_back(notification);
	}

	void show() {
		for (auto i = notifications.begin(); i != notifications.end(); i++) {
			i->printMessage();
		}
	}
};


