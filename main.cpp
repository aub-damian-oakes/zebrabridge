#include <Windows.h>
#include <aclapi.h>
#include <tchar.h>
#include "controlflagdefs.h"
#include <iostream>


int WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int iShowCmd) {
	HANDLE		input;
	HANDLE		printer;
	DWORD		controlFlags	= NO_CONTROL_FLAG;
	LPWSTR		commandLine		= GetCommandLineW();
	LPWSTR		port;
	LPWSTR		printerName;
	LPWSTR*		arguments;
	int			argc;

	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	// Zero initialize necessary variables.
	ZeroMemory(&arguments,		sizeof(arguments));
	ZeroMemory(&argc,			sizeof(int));
	ZeroMemory(&port,			sizeof(LPWSTR));
	ZeroMemory(&printerName,	sizeof(LPWSTR));
	ZeroMemory(&input,			sizeof(HANDLE));
	ZeroMemory(&printer,		sizeof(HANDLE));

	// Parse command line arguments.
	arguments = CommandLineToArgvW(commandLine, &argc);
	if (arguments == NULL) {
		return 100;
	}

	// Parse arguments from command line.
	if (argc > 2) {
		for (int i = 0; i < argc; i++) {
			// Check for debug flag.
			if (wcscmp(arguments[i], L"/debug") == 0) {
				controlFlags = (controlFlags | DEBUG_CONTROL_FLAG);
			}
			// Check for port argument.
			if ((wcscmp(arguments[i], L"/port") == 0)) {
				if ((i + 1) > argc) {
					return 101;
				}
				else {
					port = arguments[i + 1];
				}
			}
			// Check for printer argument.
			if ((wcscmp(arguments[i], L"/printer") == 0)) {
				if ((i + 1) > argc) {
					return 101;
				}
				else {
					printerName = arguments[i + 1];
				}
			}
		}
	}

	std::wcout << printerName << L" " << port;

	// Create handle to file.
	if (!CreateFile(
		port,
		GENERIC_READ | GENERIC_WRITE,

	))

	return 0;
}