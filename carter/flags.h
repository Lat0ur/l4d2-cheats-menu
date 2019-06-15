#pragma once


    enum flags
    {
        flags_on_ground = (1 << 0),
        flags_ducking = (1 << 1),
        flags_water_jump = (1 << 2),
        flags_on_train = (1 << 3),
        flags_in_rain = (1 << 4),
        flags_frozen = (1 << 5),
        flags_controls = (1 << 6),
        flags_client = (1 << 7),
        flags_fake_client = (1 << 8)
    };
