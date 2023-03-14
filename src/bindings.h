// Copyright (c) 2015 Sergio Gonzalez. All rights reserved.
// License: https://github.com/serge-rgb/milton#license

#pragma once

enum BindableAction : u32
{
    // Do not reuse IDs
    Action_NONE = 0,

    Action_FIRST = 1,

    Action_DECREASE_BRUSH_SIZE      = Action_FIRST,
    Action_INCREASE_BRUSH_SIZE      = 2,
    Action_ZOOM_IN                  = 3,
    Action_ZOOM_OUT                 = 4,
    Action_REDO                     = 5,
    Action_UNDO                     = 6,
    Action_EXPORT                   = 7,
    Action_QUIT                     = 8,
    Action_NEW                      = 9,
    Action_SAVE                     = 10,
    Action_SAVE_AS                  = 11,
    Action_OPEN                     = 12,
    Action_TOGGLE_MENU              = 13,
    Action_TOGGLE_GUI               = 14,
    Action_MODE_ERASER              = 15,
    Action_MODE_PEN                 = 16,
    Action_MODE_EYEDROPPER          = 17,
    Action_MODE_PRIMITIVE_LINE      = 18,
    Action_MODE_PRIMITIVE_RECTANGLE = 19,
    Action_MODE_PRIMITIVE_GRID      = 20,
    Action_SET_BRUSH_ALPHA_10       = 21,
    Action_SET_BRUSH_ALPHA_20       = 22,
    Action_SET_BRUSH_ALPHA_30       = 23,
    Action_SET_BRUSH_ALPHA_40       = 24,
    Action_SET_BRUSH_ALPHA_50       = 25,
    Action_SET_BRUSH_ALPHA_60       = 26,
    Action_SET_BRUSH_ALPHA_70       = 27,
    Action_SET_BRUSH_ALPHA_80       = 28,
    Action_SET_BRUSH_ALPHA_90       = 29,
    Action_SET_BRUSH_ALPHA_100      = 30,
    Action_HELP                     = 31,
    Action_PEEK_OUT                 = 32,
    Action_DRAG_BRUSH_SIZE          = 33,
    Action_DRAG_ZOOM                = 34,
    Action_TRANSFORM                = 35,

    #if MILTON_ENABLE_PROFILING && 0
        // Debug bindings
        Action_TOGGLE_DEBUG_WINDOW = 41,
    #endif

    Action_COUNT,

    // Press-and-release actions.
    ActionRelease_PEEK_OUT        = 37,
    ActionRelease_DRAG_BRUSH_SIZE = 38,
    ActionRelease_DRAG_ZOOM       = 39,
    ActionRelease_TRANSFORM       = 40,

    Action_COUNT_WITH_RELEASE,
};

enum ModifierFlags : u32
{
    Modifier_NONE = 0,

    Modifier_CTRL = 1<<0,
    Modifier_WIN = 1<<1,
    Modifier_ALT = 1<<2,
    Modifier_SPACE = 1<<3, // Spaaaaaace
    Modifier_SHIFT = 1<<4,
};

#pragma pack(push, 1)
struct Binding
{
    u8 accepts_repeats;
    u8 on_release;

    u8 _padding1[2];

    ModifierFlags modifiers;

    i8 bound_key;  // Positive values are ascii keys.
    // Zero/Negative values:
    enum Key
    {
        UNBOUND = 0,
        TAB = '\t',
        ESC = 27,

        F1 = -2,
        F2 = -3,
        F3 = -4,
        F4 = -5,
        F5 = -6,
        F6 = -7,
        F7 = -8,
        F8 = -9,
        F9 = -10,
        F10 = -11,
        F11 = -12,
        F12 = -13,

        KP_DIVIDE = '/',
        KP_MULTIPLY = '*',
        KP_MINUS = '-',
        KP_PLUS = '+',
        KP_PERIOD = '.',
        KP_0 = '0',
        KP_1 = '1',
        KP_2 = '2',
        KP_3 = '3',
        KP_4 = '4',
        KP_5 = '5',
        KP_6 = '6',
        KP_7 = '7',
        KP_8 = '8',
        KP_9 = '9',
    };

    u8 _padding2[3];

    BindableAction action;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct MiltonBindings
{
    // NOTE: On key-down, we have to loop over this array to find a matching
    // binding. Action_COUNT is a small number so this is not really a problem.
    // It's unlikely to ever be a problem, but if we ever get to a point where
    // there are enough actions that looping over this array feels too wrong,
    // we can add a map here.
    Binding bindings[Action_COUNT_WITH_RELEASE];
};
#pragma pack(pop)

