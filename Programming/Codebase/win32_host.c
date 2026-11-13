#include "application.h"

#include <windows.h>

static LRESULT CALLBACK window_procedure(HWND window_handle, UINT message, WPARAM word_parameter, LPARAM long_parameter) {
	switch (message) {
		// case WM_CLOSE:
		case WM_DESTROY:
			PostQuitMessage(0);

			return 0;
	}

	return DefWindowProcW(window_handle, message, word_parameter, long_parameter);
}

int WINAPI wWinMain(HINSTANCE instance_handle, HINSTANCE previous_instance_handle, PWSTR arguments, int display_command) {
	{
		const wchar_t window_class_name[] = L"EskeankerWindowClass";

		WNDCLASSW window_class = {};

		window_class.lpszClassName = window_class_name;
		window_class.lpfnWndProc = window_procedure;
		window_class.hInstance = instance_handle;

		RegisterClassW(&window_class);

		const wchar_t window_name[] = L"eskeanker";

		HWND window_handle = CreateWindowW(window_class_name, window_name, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, instance_handle, nullptr);

		ShowWindow(window_handle, display_command);

		application_initialize();
	}

	{
		LARGE_INTEGER frequency;
		LARGE_INTEGER leading_counter;
		LARGE_INTEGER trailing_counter;

		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&trailing_counter);

		uint64_t accumulator = 0;

		bool running = true;

		MSG message;

		while (running) {
			QueryPerformanceCounter(&leading_counter);

			uint64_t frame_duration = (leading_counter.QuadPart - trailing_counter.QuadPart) * 1'000'000'000 / frequency.QuadPart;

			accumulator += frame_duration;

			while (PeekMessageW(&message, nullptr, 0, 0, PM_REMOVE)) {
				if (message.message == WM_QUIT) {
					running = false;

					break;
				}

				TranslateMessage(&message);
				DispatchMessageW(&message);
			}

			while (accumulator >= application_update_duration) {
				application_update();

				accumulator -= application_update_duration;
			}

			application_render();

			trailing_counter = leading_counter;
		}
	}

	{
		application_terminate();

		return 0;
	}
}
