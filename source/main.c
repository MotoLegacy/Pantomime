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

#include "html_parser.h"

int main(void)
{
    // Dummy test case - just grab a document locally.
    FILE* test_document;
    test_document = fopen("tests/simple_document.html", "r");

    if (test_document == NULL) {
        printf("Couldn't find test HTML document.\n");
        return 0;
    }

    // Seek to end of dummy file to get its size.
    fseek(test_document, 0, SEEK_END);
    int document_size = ftell(test_document);
    fseek(test_document, 0, SEEK_SET);

    // Toss the HTML data into a char[].
    char document[document_size];
    int i = -1;
    int c;
    while(EOF != (c = fgetc(test_document)) && ++i < document_size)
        document[i] = c;

    // Close file pointer.
    fclose(test_document);

    // Now convert HTML data from char[] to char*.
    char* html_data = malloc(sizeof(char)*document_size);
    for(int i = 0; i < document_size; i++) {
        html_data[i] = document[i];
        html_data[i + 1] = '\0';
    }

    // Send it off to the HTML Parser
    HTML_BeginParse(html_data);

    return 0;
}
