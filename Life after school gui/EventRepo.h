#pragma once
#include "Date.h"
#include "Event.h"

#include <vector>
#include <algorithm>

class EventRepo {
protected:
	std::vector<Event>elems;
public:
	EventRepo() = default;
	EventRepo(const EventRepo& er);
	virtual ~EventRepo() = default;
	virtual void addEvent(Event e);
	virtual void removeEvent(Event e);
	virtual void updateEvent(Event oldE, Event newE);
	int getLength();
	Event& searchEvent(Event e);
	Event getEvent(Event e);
	std::vector<Event> eventsByMonth(int month);
	void modifyAttendance(Event e, int delta);

	std::vector<Event> getEvents() { return this->elems; }

	friend std::ostream& operator<<(std::ostream& os, EventRepo& r);

	virtual void read() = 0;
	virtual void write() = 0;
	virtual void open() = 0;
};

class FileEventRepo : public EventRepo {
public:
	FileEventRepo();
	void addEvent(Event e) override;
	void removeEvent(Event e) override;
	void updateEvent(Event oldE, Event newE) override;

	void read() override;
	void write() override;
	void open() override {}
};

class ConsoleEventRepo : public EventRepo {
public:
	ConsoleEventRepo() {}
	void read() override {}
	void write() override {}
	void open() override {}
};

class CVSEventRepo : public EventRepo {
public:
	CVSEventRepo() = default;
	void addEvent(Event e) override;
	void removeEvent(Event e) override;
	void updateEvent(Event oldE, Event newE) override;

	void read() override {}
	void write() override;
	void open() override;
};

class HTMLEventRepo : public EventRepo {
public:
	HTMLEventRepo() = default;
	void addEvent(Event e) override;
	void removeEvent(Event e) override;
	void updateEvent(Event oldE, Event newE) override;

	void read() override {}
	void write() override;
	void open() override;
};