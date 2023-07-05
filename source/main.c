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

#include <html/html_parser.h>
#include <prtcl/protocol.h>

int main(int argc, char *argv[])
{
    // If there aren't any args specified, just close and report
    // an error, change this when we have an interface.
    if (argc < 2) {
        printf("Fatal: Pantomime requires a file to be specified "
        "as a command line argument. \nExample: "
        "pantomime file://tests/simple_document.html\n"
        "Terminating.\n");
        return 0;
    }

    // Have the protocol manager send us the HTML document as
    // a char*
    char* html_data = NULL;
    html_data = PRTCL_RetrieveDocument(argv[1]);

    if (html_data != NULL) {
        // Send it off to the HTML Parser
        HTML_BeginParse(html_data);
    } else {
        printf("Something went wrong, could not start HTML parser.\n");
    }
    
    return 0;
}
