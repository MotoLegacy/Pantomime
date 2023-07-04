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
#include <string.h>

#include <util.h>
#include <prtcl/protocol_file.h>

char* PRTCL_RetrieveDocument(char* req_uri)
{
    // Check the protocol identifier so we know
    // how to handle retrieving the document.
    // file://
    if (req_uri[0] == 'f' && req_uri[1] == 'i' &&
    req_uri[2] == 'l' && req_uri[3] == 'e' && 
    req_uri[4] == ':' && req_uri[5] == '/' &&
    req_uri[6] == '/') {
        // Build a new string omitting the protocol
        char* file_path = Util_BuildStringFromChunk(req_uri, 
                                        7, strlen(req_uri));
        return PRTCL_RetrieveFile(file_path);
    } else {
        printf("PTRCL_RetrieveDocument: Unknown protocol "
        "in provided URI '%s'\n", req_uri);
        return NULL;
    }
}