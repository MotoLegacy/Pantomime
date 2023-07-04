//
// Copyright (C) 2023 by Ivy Bowling <motolegacy.git@gmail.com>
//
// Permission to use, copy, modify, and/or distribute this software 
// for any purpose with or without fee is hereby granted.
// 
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL 
// WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL 
// THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM 
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, 
// NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN 
// CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <types.h>

#define MAX_TEMP_STR_LEN    512

char* tempstr = NULL;

char* Util_CharDeleteAtIndex(char* src, int index)
{
    int len = strlen(src);

    if (tempstr != NULL) {
        free(tempstr);
        tempstr = NULL;
    }

    tempstr = malloc(sizeof(char) * (len + 1));

    int j = 0;
    for(int i = 0; i < len; i++) {
        if (i != index) {
            tempstr[j] = src[i];
            j++;
        }
    }
    tempstr[j] = '\0';

    return tempstr;
}

char* Util_BuildStringFromChunk(char* str, int start, int end)
{
    // Ensure the string isn't too big
    if (start >= MAX_TEMP_STR_LEN || end >= MAX_TEMP_STR_LEN) {
        printf("Util_BuildStringFromChunk: Received "
        "a string that is above the max length. "
        "Returning 'nil'.\n");

        return "nil";
    }

    // Or that we aren't trying some weird
    // backwards junk.
    if (start > end) {
        printf("Util_BuildStringFromChunk: Start position "
        "is larger than end. Returning 'nil'\n");

        return "nil";
    }

    // Fill a large char* with the chunk'd string.
    char* bloaty_chunk = malloc(sizeof(char)*MAX_TEMP_STR_LEN);

    int ofs;
    for (ofs = 0; ofs < end - start; ofs++) {
        bloaty_chunk[ofs] = str[ofs + start];
        bloaty_chunk[ofs + 1] = '\0';
    }

    // Now that we have our messy string, let's have it
    // occupy less memory.
    char* real_chunk = malloc(sizeof(char)*(ofs + 1));

    // Copy the data to the optimized char*.
    for (int i = 0; i < ofs + 1; i++) {
        real_chunk[i] = bloaty_chunk[i];
    }

    // Free the bloaty one.
    free(bloaty_chunk);

    return real_chunk;
}