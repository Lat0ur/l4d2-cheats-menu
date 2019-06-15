#pragma once


    enum move
    {
        move_none = 0,
        move_isometric,
        move_walk,
        move_step,
        move_fly,
        move_fly_gravity,
        move_physics,
        move_push,
        move_no_clip,
        move_ladder,
        move_observer,
        move_custom,
        move_last = move_custom,
        move_max_bits = 4,
        move_max
    };
