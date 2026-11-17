#include <windows.h>

static LRESULT CALLBACK window_procedure(HWND window_handle, UINT message, WPARAM word_parameter, LPARAM long_parameter) {
	switch (message) {
		case WM_DESTROY: {
			PostQuitMessage(0);

			return 0;
		}

		default: {
			return DefWindowProcW(window_handle, message, word_parameter, long_parameter);
		}
	}
}

[[noreturn]]
void run() {
	HINSTANCE instance_handle = GetModuleHandleW(nullptr);
	const wchar_t window_class_name[] = L"EskeankerWindowClass";

	WNDCLASSW window_class = {};

	window_class.lpfnWndProc = window_procedure;
	window_class.hInstance = instance_handle;
	window_class.lpszClassName = window_class_name;

	RegisterClassW(&window_class);

	const wchar_t window_name[] = L"eskeanker";

	HWND window_handle = CreateWindowW(window_class_name, window_name, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, instance_handle, nullptr);

	ShowWindow(window_handle, SW_SHOW);

	MSG message;
	BOOL status;

	while ((status = GetMessageW(&message, nullptr, 0, 0)) > 0) {
		TranslateMessage(&message);
		DispatchMessageW(&message);
	}

	if (status == 0) {
		ExitProcess((UINT)message.wParam);
	}

	ExitProcess(1);
}
