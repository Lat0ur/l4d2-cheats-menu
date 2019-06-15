#include <Windows.h>

#include "main.h"


    namespace entry
    {
        unsigned long __stdcall begin(void* instance)
        {
            main::begin(instance);

            return false;
        }
    }


bool __stdcall DllMain(void* instance, const unsigned long reason, void* reserved)
{
    if (reason == 1)
    {
        const auto thread = CreateThread(nullptr, 0,entry::begin, instance, 0, nullptr);

        CloseHandle(thread);
    }

    return true;
}