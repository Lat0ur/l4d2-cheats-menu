#pragma once

#include <memory>

    class vmt
    {
    public:
        vmt() = default;

        explicit vmt(void* table) 
        {
            base = static_cast<std::uintptr_t**>(table);

            while (static_cast<std::uintptr_t*>(*base)[size])
                ++size;

            total = *base;
            current = std::make_unique<std::size_t[]>(size);

            std::memcpy(current.get(), total, size * sizeof(std::size_t));

            *base = current.get();
        }

        ~vmt() 
        {
            *base = total;
        }

        void hook(void* function, const std::size_t index) const
        {
            current[index] = reinterpret_cast<std::uintptr_t>(function);
        }

        void unhook(const std::size_t index) const
        {
            current[index] = total[index];
        }

        template <class fn = void*> fn original(const std::size_t index) 
        {
            return reinterpret_cast<fn>(total[index]);
        }
    private:
        std::size_t size = 0;
        std::uintptr_t** base = nullptr;
        std::uintptr_t* total = nullptr;
        std::unique_ptr<std::uintptr_t[]> current = nullptr;
    };
