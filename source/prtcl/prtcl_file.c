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

char* PRTCL_RetrieveFile(char* file_path)
{
    // Open the document through standard FIO
    FILE* document;
    document = fopen(file_path, "r");

    if (document == NULL) {
        printf("PRTCL_RetrieveFile: No such file '%s'\n", file_path);
        return NULL;
    }

    // Seek to the end of the file to get its size.
    fseek(document, 0, SEEK_END);
    int document_size = ftell(document);
    fseek(document, 0, SEEK_SET);

    // Toss the HTML data into a char[].
    char html_doc[document_size];
    int i = -1;
    int c;
    while(EOF != (c = fgetc(document)) && ++i < document_size)
        html_doc[i] = c;

    // Close file pointer.
    fclose(document);

    // Now convert HTML data from char[] to char*.
    char* html_data = malloc(sizeof(char)*document_size);
    for(int i = 0; i < document_size; i++) {
        html_data[i] = html_doc[i];
        html_data[i + 1] = '\0';
    }

    return html_data;
}