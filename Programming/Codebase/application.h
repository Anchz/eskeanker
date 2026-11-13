#include <stdint.h>

constexpr uint64_t application_update_duration = 15'625'000;

enum ApplicationEventType {
	APPLICATION_EVENT_TYPE_NONE, APPLICATION_EVENT_TYPE_EXIT_REQUEST
};

struct ApplicationEvent {
	enum ApplicationEventType type;
};

void application_initialize(void);
void application_terminate(void);

void application_update(void);
void application_render(void);
