// Copyright (c) 2015 Sergio Gonzalez. All rights reserved.
// License: https://github.com/serge-rgb/milton#license

#pragma once

#include "platform.h"

struct Milton;
struct MiltonSettings;

struct MiltonPersist
{
    // Persistence
    PATH_CHAR*  mlt_file_path;
    u32         mlt_binary_version;
    WallTime    last_save_time;

    float target_MB_per_sec;

    sz bytes_to_last_block;
};

struct milton_save_return {
    i64 bytes_written;
    b32 error;
};

PATH_CHAR* milton_get_last_canvas_fname();

void milton_load(Milton* milton);
milton_save_return milton_save_as(Milton* milton, PATH_CHAR* new_file);
u64 milton_save(Milton* milton);
b32 milton_prompt_and_save_default_canvas_as(Milton* milton);

void milton_save_buffer_to_file(PATH_CHAR* fname, u8* buffer, i32 w, i32 h);

b32  platform_settings_load(PlatformSettings* prefs);
void platform_settings_save(PlatformSettings* prefs);

b32 milton_settings_load(MiltonSettings* settings);
void milton_settings_save(MiltonSettings* settings);


