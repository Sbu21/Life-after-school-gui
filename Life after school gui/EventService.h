#pragma once
#include "EventRepo.h"
#include "RepoValidator.h"

#include <stdexcept>
#include <assert.h>

class EventService {
private:
	EventRepo* adminRepo;
	EventRepo* userRepo;
public:
	EventService() = default;
	EventService(EventRepo* adminRepo, EventRepo* userRepo);
	~EventService();
	EventService(const EventService& es) = default;
	void addEvent(std::string title, std::string description, std::string link, int nrPeople, Date d);
	void removeAdminEvent(std::string title, Date d);
	void removeUserEvent(std::string title, Date d);
	void updateEvent(std::string oldTitle, Date oldD, std::string newTitle, std::string newDescription, std::string newLink, Date newD);
	Event& searchEvent(std::string title, Date d);
	EventRepo& getAdminRepo();
	EventRepo& getUserRepo();
	void going(Event e, int delta);

	std::vector<Event>eventsByMonth(int month);
};