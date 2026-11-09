enum ApplicationEventType {
	APPLICATION_EVENT_TYPE_NONE, APPLICATION_EVENT_TYPE_EXIT_REQUEST
};

struct ApplicationEvent {
	enum ApplicationEventType type;
};

