#pragma once
#include <Windows.h>
#include <string>

class File
{
	const char * m_name;
	HANDLE handle;
public:

	enum ACCESS {
		READ = GENERIC_READ,
		WRITE = GENERIC_WRITE
	};

	enum SHARE {
		WRITE = FILE_SHARE_WRITE,
		READ = FILE_SHARE_READ,
		ONLY_FOR_ME = 0
	};

	enum OPEN {
		EXISTING = OPEN_EXISTING,
		ALWAYS = OPEN_ALWAYS,
		TRUNCATE = TRUNCATE_EXISTING
	};

	File();
	File(const char * filename);
	void openFile(const char * filename, ACCESS access = READ, OPEN = ALWAYS, SHARE share = SHARE(READ | WRITE));
	~File();
};

