#include <windows.h>

static LRESULT CALLBACK window_procedure(HWND window_handle, UINT message, WPARAM word_parameter, LPARAM long_parameter) {
	switch (message) {
		// case WM_CLOSE:
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(window_handle, message, word_parameter, long_parameter);
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
	}

	{
		bool running = true;

		while (running) {
			MSG message;

			while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
				if (message.message == WM_QUIT) {
					running = false;
					break;
				}
				
				TranslateMessage(&message);
				DispatchMessageW(&message);
			}

			
		}
	}

	{
		return 0;
	}
}
