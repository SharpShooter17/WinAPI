#include "File.h"



File::File() : m_name(nullptr)
{
}


File::File(const char * filename) : m_name(filename)
{
}

void File::openFile(const char * filename, ACCESS mode)
{
	m_name = filename;

}

File::~File()
{
}
