#pragma once

#include <Windows.h>
#include <string>


    class tools
    {
    public:
        template <class fn> static fn find_table(void* base, const std::size_t size)
        {
            return (*static_cast<fn**>(base))[size];
        }

        template <class fn> static fn find_interface(const std::string& module, const std::string& address)
        {
            return static_cast<fn>(reinterpret_cast<void*(*)(const char*, void*)>(GetProcAddress(
                GetModuleHandleA(module.c_str()), "CreateInterface"))(address.c_str(), nullptr));
        }
    };


	template<typename Fn>
	Fn GetFunction(void* Base, std::int32_t Index)
	{
		std::uintptr_t** uVTablePtr = static_cast<std::uintptr_t**>(Base);
		std::uintptr_t* uVTableFnBase = *uVTablePtr;
		std::uintptr_t uAddress = uVTableFnBase[Index];
		return reinterpret_cast<Fn>(uAddress);
	}