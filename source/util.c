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
