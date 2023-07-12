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
#include <stdbool.h>
#include <ctype.h>

#include <util.h>
#include <html/html_parser.h>
#include <html/html_datatype.h>
#include <html/html_attributeparser.h>

char* HTML_ParseTextAttribute(char* value)
{
    char* dest = malloc(sizeof(char)*(strlen(value) + 1));
    strcpy(dest, value);
    return dest;
}

charsets_t HTML_ParseCharsetsAttribute(char* value) 
{
    charsets_t charset;
    int result = 0;

    GEN_FROM_VALUE(value, "utf-8", CS_UTF8, charset, result);
    GEN_FROM_VALUE(value, "iso-8859-1", CS_ISO8859, charset, result);
    GEN_FROM_VALUE(value, "ascii", CS_ASCII, charset, result);
    GEN_FROM_VALUE(value, "ansi", CS_ANSI, charset, result);

    if (result == 0) {
        printf("HTML_ParseCharsetsAttribute: Unknown charset %s, "
        "defaulting to UTF-8\n", value);
        charset = CS_UTF8;
    }

    return charset;
}

contenttypes_t HTML_ParseContentTypesAttribute(char* value)
{
    contenttypes_t content_type;
    int result = 0;

    GEN_FROM_VALUE(value, "application/EDI-X12", 
                    CTYPE_APP_EDIX12, content_type, result);
    GEN_FROM_VALUE(value, "application/EDIFACT", 
                    CTYPE_APP_EDIFACT, content_type, result);
    GEN_FROM_VALUE(value, "application/javascript", 
                    CTYPE_APP_JS, content_type, result);
    GEN_FROM_VALUE(value, "application/octet-stream", 
                    CTYPE_APP_OCTETSTREAM, content_type, result);
    GEN_FROM_VALUE(value, "application/ogg", 
                    CTYPE_APP_OGG, content_type, result);
    GEN_FROM_VALUE(value, "application/pdf", 
                    CTYPE_APP_PDF, content_type, result);
    GEN_FROM_VALUE(value, "application/xhtml+xml", 
                    CTYPE_APP_XHTMLXML, content_type, result);
    GEN_FROM_VALUE(value, "application/x-shockwave-flash", 
                    CTYPE_APP_XSHOCKWAVEFLASH, content_type, result);
    GEN_FROM_VALUE(value, "application/json",
                CTYPE_APP_JSON, content_type, result);
    GEN_FROM_VALUE(value, "application/ld+json",
                CTYPE_APP_LDJSON, content_type, result);
    GEN_FROM_VALUE(value, "application/xml",
                CTYPE_APP_XML, content_type, result);
    GEN_FROM_VALUE(value, "application/zip",
                CTYPE_APP_ZIP, content_type, result);
    GEN_FROM_VALUE(value, "application/x-www-form-urlencoded",
                CTYPE_APP_XWWWFORMURLENCODED, content_type, result);
    GEN_FROM_VALUE(value, "audio/mpeg",
                CTYPE_AUD_MPEG, content_type, result);
    GEN_FROM_VALUE(value, "audio/x-ms-wma",
                CTYPE_AUD_XMASWMA, content_type, result);
    GEN_FROM_VALUE(value, "audio/vnd.rn-realaudio",
                CTYPE_AUD_VNDRNREALAUDIO, content_type, result);
    GEN_FROM_VALUE(value, "audio/x-wav",
                CTYPE_AUD_XWAV, content_type, result);
    GEN_FROM_VALUE(value, "image/gif",
                CTYPE_IMG_GIF, content_type, result);
    GEN_FROM_VALUE(value, "image/jpeg",
                CTYPE_IMG_JPEG, content_type, result);
    GEN_FROM_VALUE(value, "image/png",
                CTYPE_IMG_PNG, content_type, result);
    GEN_FROM_VALUE(value, "image/tiff",
                CTYPE_IMG_TIFF, content_type, result);
    GEN_FROM_VALUE(value, "image/vnd.microsoft.icon",
                CTYPE_IMG_VNDMICROSOFTICON, content_type, result);
    GEN_FROM_VALUE(value, "image/x-icon",
                CTYPE_IMG_XICON, content_type, result);
    GEN_FROM_VALUE(value, "image/vnd.djvu",
                CTYPE_IMG_VNDDJVU, content_type, result);
    GEN_FROM_VALUE(value, "image/svg+xml",
                CTYPE_IMG_SVGXML, content_type, result);
    GEN_FROM_VALUE(value, "multipart/mixed",
                CTYPE_MPA_MIXED, content_type, result);
    GEN_FROM_VALUE(value, "multipart/alternative",
                CTYPE_MPA_ALTERNATIVE, content_type, result);
    GEN_FROM_VALUE(value, "multipart/related",
                CTYPE_MPA_RELATED, content_type, result);
    GEN_FROM_VALUE(value, "multipart/form-data",
                CTYPE_MPA_FORMDATA, content_type, result);
    GEN_FROM_VALUE(value, "text/css",
                CTYPE_TXT_CSS, content_type, result);
    GEN_FROM_VALUE(value, "text/csv",
                CTYPE_TXT_CSV, content_type, result);
    GEN_FROM_VALUE(value, "text/html",
                CTYPE_TXT_HTML, content_type, result);
    GEN_FROM_VALUE(value, "text/javascript",
                CTYPE_TXT_JS, content_type, result);
    GEN_FROM_VALUE(value, "text/plain",
                CTYPE_TXT_PLAIN, content_type, result);
    GEN_FROM_VALUE(value, "text/xml",
                CTYPE_TXT_XML, content_type, result);
    GEN_FROM_VALUE(value, "video/mpeg",
                CTYPE_VID_MPEG, content_type, result);
    GEN_FROM_VALUE(value, "video/mp4",
                CTYPE_VID_MP4, content_type, result);
    GEN_FROM_VALUE(value, "video/quicktime",
                CTYPE_VID_QUICKTIME, content_type, result);
    GEN_FROM_VALUE(value, "video/x-ms-wmv",
                CTYPE_VID_XMSWMV, content_type, result);
    GEN_FROM_VALUE(value, "video/x-msvideo",
                CTYPE_VID_XMSVIDEO, content_type, result);
    GEN_FROM_VALUE(value, "video/x-flv",
                CTYPE_VID_XFLV, content_type, result);
    GEN_FROM_VALUE(value, "video/webm",
                CTYPE_VID_WEBM, content_type, result);
    GEN_FROM_VALUE(value, "application/vnd.oasis.opendocument.text",
                CTYPE_APP_VNDOASISOPENDOCUMENTTEXT, content_type, result);
    GEN_FROM_VALUE(value, "application/vnd.oasis.opendocument.spreadsheet",
                CTYPE_APP_VNDOASISOPENDOCUMENTSPREADSHEET, content_type, result);
    GEN_FROM_VALUE(value, "application/vnd.oasis.opendocument.presentation",
                CTYPE_APP_VNDOASISOPENDOCUMENTPRESENTATION, content_type, result);
    GEN_FROM_VALUE(value, "application/vnd.oasis.opendocument.graphics",
                CTYPE_APP_VNDOASISOPENDOCUMENTGRAPHICS, content_type, result);
    GEN_FROM_VALUE(value, "application/vnd.ms-excel",
                CTYPE_APP_VNDMSEXCEL, content_type, result);
    GEN_FROM_VALUE(value, "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet",
                CTYPE_APP_VNDOPENXMLFORMATSOFFICEDOCUMENTSPREADSHEET, content_type, result);
    GEN_FROM_VALUE(value, "application/vnd.ms-powerpoint",
                CTYPE_APP_VNDMSPOWERPOINT, content_type, result);
    GEN_FROM_VALUE(value, "application/vnd.openxmlformats-",
                CTYPE_APP_VNDOPENXMLFORMATS, content_type, result);
    GEN_FROM_VALUE(value, "officedocument.presentationml.presentation",
                CTYPE_APP_VNDOPENXMLFORMATSOFFICEDOCUMENTPRESENTATIONMLPRESENTATION, content_type, result);
    GEN_FROM_VALUE(value, "application/msword",
                CTYPE_APP_MSWORD, content_type, result);
    GEN_FROM_VALUE(value, "officedocument.wordprocessingml.document",
                CTYPE_APP_VNDOPENXMLFORMATSOFFICEDOCUMENTWORDPROCESSINGMLDOCUMENT, content_type, result);
    GEN_FROM_VALUE(value, "application/vnd.mozilla.xul+xml",
                CTYPE_APP_VNDMOZILLAXULXML, content_type, result);
    
    if (result == 0) {
        printf("HTML_ParseContentTypesAttribute: Unknown content type %s, \
        defaulting to text/plain\n", value);
        content_type = CTYPE_TXT_PLAIN;
    }

    return content_type;
}

char HTML_ParseCharacterAttribute(char* value)
{
    if (strlen(value) > 1) {
        printf("HTML_ParseCharacterAttribute: character attribute %s "
        "has length of %lu, only using first character.\n", value, strlen(value));
    }

    return value[0];
}

align_t HTML_ParseAlignAttribute(char* value)
{
    align_t align;
    int result = 0;

    GEN_FROM_VALUE(value, "top", ALIGN_TOP, align, result);
    GEN_FROM_VALUE(value, "left", ALIGN_LEFT, align, result);
    GEN_FROM_VALUE(value, "center", ALIGN_CENTER, align, result);
    GEN_FROM_VALUE(value, "right", ALIGN_RIGHT, align, result);
    GEN_FROM_VALUE(value, "bottom", ALIGN_BOTTOM, align, result);
    GEN_FROM_VALUE(value, "middle", ALIGN_MIDDLE, align, result);
    GEN_FROM_VALUE(value, "justify", ALIGN_JUSTIFY, align, result);
    GEN_FROM_VALUE(value, "char", ALIGN_CHAR, align, result);

    if (result == 0) {
        printf("HTML_ParseAlignAttribute: Unknown alignment %s,"
        " ignoring.", value);
    }

    return align;
}

color_t HTML_ParseColorAttribute(char* value)
{
    color_t color;

    // Colors are an annoyingly involved process.
    // There are basically 3 different possibilities
    // for assigning color values.
    // 1. "rgb(255, 255, 255)", can also be rgba (we
    //    will parse this but won't support alpha).
    // 2. "#FFFFFF" / hex colors
    // 3. pre-defined color-word such as "red", "silver",
    //    "fuchsia".. there are 16 total in HTML 4.01, and
    //    more were added later that we will support
    //    due to the simplicity of appending the list.
    // ----
    // Also note that every browser basically has broken
    // rgb() with bgcolor with no documentation as to how.
    // Forget that, we will just give it the same love as
    // everything else.

    //
    // RGB(A)
    //
    if (value[0] == 'r' && value[1] == 'g' && value[2] == 'b') {
        byte colors[3]; // Stores the RGB color values
        byte col_index; // Keeps track of if we're filling R, G, or B
        for (int i = 3; i < strlen(value); i++) {
            // Ignore alpha (or anything else after)
            if (col_index > 2)
                continue;
            // This is off spec, but basically if it's not
            // a number, we don't care about it.
            if (value[i] >= '0' && value[i] <= '9') {
                colors[col_index] = colors[col_index] * 10 + (value[i] - '0');
            } else if (value[i] == ',') {
                col_index++; // Move to the next color component
            }
        }

        // Fill the attribute struct with the values
        color.r = colors[0];
        color.g = colors[1];
        color.b = colors[2];
    }
    //
    // Hex Colors
    //
    else if (value[0] == '#') {
        byte colors[3]; // Stores the RGB color values
        for (int i = 1; i < strlen(value); i += 2) {
            char hex[3] = {value[i], value[i + 1], '\0'};
            int decimal = strtol(hex, NULL, 16); // Convert hex to decimal
            colors[(i - 1) / 2] = (byte)decimal;
        }

        // Fill the attribute struct with the values
        color.r = colors[0];
        color.g = colors[1];
        color.b = colors[2];
    }
    //
    // Color names
    //
    else {
        int result = 0;

        //
        // Standard HTML 4.01 colors
        // https://en.wikipedia.org/wiki/Web_colors#Basic_colors
        //
        COLOR_FROM_NAME(value, "white", 255, 255, 255, color, result);
        COLOR_FROM_NAME(value, "silver", 191, 191, 191, color, result);
        COLOR_FROM_NAME(value, "gray", 128, 128, 128, color, result);
        COLOR_FROM_NAME(value, "black", 0, 0, 0, color, result);
        COLOR_FROM_NAME(value, "red", 255, 0, 0, color, result);
        COLOR_FROM_NAME(value, "maroon", 128, 0, 0, color, result);
        COLOR_FROM_NAME(value, "yellow", 255, 255, 0, color, result);
        COLOR_FROM_NAME(value, "olive", 128, 128, 0, color, result);
        COLOR_FROM_NAME(value, "lime", 0, 255, 0, color, result);
        COLOR_FROM_NAME(value, "green", 0, 128, 0, color, result);
        COLOR_FROM_NAME(value, "aqua", 0, 255, 255, color, result);
        COLOR_FROM_NAME(value, "teal", 0, 128, 128, color, result);
        COLOR_FROM_NAME(value, "blue", 0, 0, 255, color, result);
        COLOR_FROM_NAME(value, "navy", 0, 0, 128, color, result);
        COLOR_FROM_NAME(value, "fuschia", 255, 0, 255, color, result);
        COLOR_FROM_NAME(value, "purple", 128, 0, 128, color, result);
        //
        // Extended HTML colors
        // https://en.wikipedia.org/wiki/Web_colors#Extended_colors
        //
        // Pink colors
        COLOR_FROM_NAME(value, "mediumvioletred", 199, 21, 133, color, result);
        COLOR_FROM_NAME(value, "deeppink", 255, 20, 147, color, result);
        COLOR_FROM_NAME(value, "palevioletred", 219, 112, 147, color, result);
        COLOR_FROM_NAME(value, "hotpink", 255, 105, 180, color, result);
        COLOR_FROM_NAME(value, "lightpink", 255, 182, 193, color, result);
        COLOR_FROM_NAME(value, "pink", 255, 192, 203, color, result);
        // Red colors
        COLOR_FROM_NAME(value, "darkred", 139, 0, 0, color, result);
        COLOR_FROM_NAME(value, "firebrick", 178, 34, 34, color, result);
        COLOR_FROM_NAME(value, "crimson", 220, 20, 60, color, result);
        COLOR_FROM_NAME(value, "indianred", 205, 92, 92, color, result);
        COLOR_FROM_NAME(value, "lightcoral", 240, 128, 128, color, result);
        COLOR_FROM_NAME(value, "salmon", 250, 128, 114, color, result);
        COLOR_FROM_NAME(value, "darksalmon", 233, 150, 122, color, result);
        COLOR_FROM_NAME(value, "lightsalmon", 255, 160, 122, color, result);
        // Orange colors
        COLOR_FROM_NAME(value, "orangered", 255, 69, 0, color, result);
        COLOR_FROM_NAME(value, "tomato", 255, 99, 71, color, result);
        COLOR_FROM_NAME(value, "darkorange", 255, 140, 0, color, result);
        COLOR_FROM_NAME(value, "coral", 255, 127, 80, color, result);
        COLOR_FROM_NAME(value, "orange", 255, 165, 0, color, result);
        // Yellow colors
        COLOR_FROM_NAME(value, "darkkhaki", 189, 183, 107, color, result);
        COLOR_FROM_NAME(value, "gold", 255, 215, 0, color, result);
        COLOR_FROM_NAME(value, "khaki", 240, 230, 140, color, result);
        COLOR_FROM_NAME(value, "peachpuff", 255, 218, 185, color, result);
        COLOR_FROM_NAME(value, "palegoldenrod", 238, 232, 170, color, result);
        COLOR_FROM_NAME(value, "moccasin", 255, 228, 181, color, result);
        COLOR_FROM_NAME(value, "papayawhip", 255, 239, 213, color, result);
        COLOR_FROM_NAME(value, "lightgoldenrodyellow", 250, 250, 210, color, result);
        COLOR_FROM_NAME(value, "lemonchiffon", 255, 250, 205, color, result);
        COLOR_FROM_NAME(value, "lightyellow", 255, 255, 224, color, result);
        // Brown colors
        COLOR_FROM_NAME(value, "brown", 165, 42, 42, color, result);
        COLOR_FROM_NAME(value, "saddlebrown", 139, 69, 19, color, result);
        COLOR_FROM_NAME(value, "sienna", 160, 82, 45, color, result);
        COLOR_FROM_NAME(value, "chocolate", 210, 105, 30, color, result);
        COLOR_FROM_NAME(value, "darkgoldenrod", 184, 134, 11, color, result);
        COLOR_FROM_NAME(value, "peru", 205, 133, 63, color, result);
        COLOR_FROM_NAME(value, "rosybrown", 188, 143, 143, color, result);
        COLOR_FROM_NAME(value, "goldenrod", 218, 165, 32, color, result);
        COLOR_FROM_NAME(value, "sandybrown", 244, 164, 96, color, result);
        COLOR_FROM_NAME(value, "tan", 210, 180, 140, color, result);
        COLOR_FROM_NAME(value, "burlywood", 222, 184, 135, color, result);
        COLOR_FROM_NAME(value, "wheat", 245, 222, 179, color, result);
        COLOR_FROM_NAME(value, "navajowhite", 255, 222, 173, color, result);
        COLOR_FROM_NAME(value, "bisque", 255, 228, 196, color, result);
        COLOR_FROM_NAME(value, "blanchedalmond", 255, 235, 205, color, result);
        COLOR_FROM_NAME(value, "cornsilk", 255, 248, 220, color, result);
        // Purple, violet, and magenta colors
        COLOR_FROM_NAME(value, "indigo", 75, 0, 130, color, result);
        COLOR_FROM_NAME(value, "darkmagenta", 139, 0, 139, color, result);
        COLOR_FROM_NAME(value, "darkviolet", 148, 0, 211, color, result);
        COLOR_FROM_NAME(value, "darkslateblue", 72, 61, 139, color, result);
        COLOR_FROM_NAME(value, "blueviolet", 138, 43, 226, color, result);
        COLOR_FROM_NAME(value, "darkorchid", 153, 50, 204, color, result);
        COLOR_FROM_NAME(value, "magenta", 255, 0, 255, color, result);
        COLOR_FROM_NAME(value, "slateblue", 106, 90, 205, color, result);
        COLOR_FROM_NAME(value, "mediumslateblue", 123, 104, 238, color, result);
        COLOR_FROM_NAME(value, "mediumorchid", 186, 85, 211, color, result);
        COLOR_FROM_NAME(value, "mediumpurple", 147, 112, 219, color, result);
        COLOR_FROM_NAME(value, "orchid", 218, 112, 214, color, result);
        COLOR_FROM_NAME(value, "violet", 238, 130, 238, color, result);
        COLOR_FROM_NAME(value, "plum", 221, 160, 221, color, result);
        COLOR_FROM_NAME(value, "thistle", 216, 191, 216, color, result);
        COLOR_FROM_NAME(value, "lavender", 230, 230, 250, color, result);
        // Blue colors
        COLOR_FROM_NAME(value, "midnightblue", 25, 25, 112, color, result);
        COLOR_FROM_NAME(value, "darkblue", 0, 0, 139, color, result);
        COLOR_FROM_NAME(value, "mediumblue", 0, 0, 205, color, result);
        COLOR_FROM_NAME(value, "royalblue", 65, 105, 225, color, result);
        COLOR_FROM_NAME(value, "steelblue", 70, 130, 180, color, result);
        COLOR_FROM_NAME(value, "dodgerblue", 30, 144, 255, color, result);
        COLOR_FROM_NAME(value, "deepskyblue", 0, 191, 255, color, result);
        COLOR_FROM_NAME(value, "cornflowerblue", 100, 149, 237, color, result);
        COLOR_FROM_NAME(value, "skyblue", 135, 206, 235, color, result);
        COLOR_FROM_NAME(value, "lightskyblue", 135, 206, 250, color, result);
        COLOR_FROM_NAME(value, "lightsteelblue", 176, 196, 222, color, result);
        COLOR_FROM_NAME(value, "lightblue", 173, 216, 230, color, result);
        COLOR_FROM_NAME(value, "powderblue", 176, 224, 230, color, result);
        // Cyan colors
        COLOR_FROM_NAME(value, "darkcyan", 0, 139, 139, color, result);
        COLOR_FROM_NAME(value, "lightseagreen", 32, 178, 170, color, result);
        COLOR_FROM_NAME(value, "cadetblue", 95, 158, 160, color, result);
        COLOR_FROM_NAME(value, "darkturquoise", 0, 206, 209, color, result);
        COLOR_FROM_NAME(value, "mediumturquoise", 72, 209, 204, color, result);
        COLOR_FROM_NAME(value, "turquoise", 64, 224, 208, color, result);
        COLOR_FROM_NAME(value, "cyan", 0, 255, 255, color, result);
        COLOR_FROM_NAME(value, "aquamarine", 127, 255, 212, color, result);
        COLOR_FROM_NAME(value, "paleturquoise", 175, 238, 238, color, result);
        COLOR_FROM_NAME(value, "lightcyan", 224, 255, 255, color, result);
        // Green colors
        COLOR_FROM_NAME(value, "darkgreen", 0, 100, 0, color, result);
        COLOR_FROM_NAME(value, "darkolivegreen", 85, 107, 47, color, result);
        COLOR_FROM_NAME(value, "forestgreen", 34, 139, 34, color, result);
        COLOR_FROM_NAME(value, "seagreen", 46, 139, 87, color, result);
        COLOR_FROM_NAME(value, "olivedrab", 107, 142, 35, color, result);
        COLOR_FROM_NAME(value, "mediumseagreen", 60, 179, 113, color, result);
        COLOR_FROM_NAME(value, "limegreen", 50, 205, 50, color, result);
        COLOR_FROM_NAME(value, "springgreen", 0, 255, 127, color, result);
        COLOR_FROM_NAME(value, "mediumspringgreen", 0, 250, 154, color, result);
        COLOR_FROM_NAME(value, "darkseagreen", 143, 188, 143, color, result);
        COLOR_FROM_NAME(value, "mediumaquamarine", 102, 205, 170, color, result);
        COLOR_FROM_NAME(value, "yellowgreen", 154, 205, 50, color, result);
        COLOR_FROM_NAME(value, "lawngreen", 124, 252, 0, color, result);
        COLOR_FROM_NAME(value, "chartreuse", 127, 255, 0, color, result);
        COLOR_FROM_NAME(value, "lightgreen", 144, 238, 144, color, result);
        COLOR_FROM_NAME(value, "greenyellow", 173, 255, 47, color, result);
        COLOR_FROM_NAME(value, "palegreen", 152, 251, 152, color, result);
        // White colors
        COLOR_FROM_NAME(value, "mistyrose", 255, 228, 225, color, result);
        COLOR_FROM_NAME(value, "antiquewhite", 250, 235, 215, color, result);
        COLOR_FROM_NAME(value, "linen", 250, 240, 230, color, result);
        COLOR_FROM_NAME(value, "beige", 245, 245, 220, color, result);
        COLOR_FROM_NAME(value, "whitesmoke", 245, 245, 245, color, result);
        COLOR_FROM_NAME(value, "lavenderblush", 255, 240, 245, color, result);
        COLOR_FROM_NAME(value, "oldlace", 253, 245, 230, color, result);
        COLOR_FROM_NAME(value, "aliceblue", 240, 248, 255, color, result);
        COLOR_FROM_NAME(value, "seashell", 255, 245, 238, color, result);
        COLOR_FROM_NAME(value, "ghostwhite", 248, 248, 255, color, result);
        COLOR_FROM_NAME(value, "honeydew", 240, 255, 240, color, result);
        COLOR_FROM_NAME(value, "floralwhite", 255, 250, 240, color, result);
        COLOR_FROM_NAME(value, "azure", 240, 255, 255, color, result);
        COLOR_FROM_NAME(value, "mintcream", 245, 255, 250, color, result);
        COLOR_FROM_NAME(value, "snow", 255, 250, 250, color, result);
        COLOR_FROM_NAME(value, "ivory", 255, 255, 240, color, result);
        // Gray and black colors
        COLOR_FROM_NAME(value, "darkslategray", 47, 79, 79, color, result);
        COLOR_FROM_NAME(value, "dimgray", 105, 105, 105, color, result);
        COLOR_FROM_NAME(value, "slategray", 112, 128, 144, color, result);
        COLOR_FROM_NAME(value, "lightslategray", 119, 136, 153, color, result);
        COLOR_FROM_NAME(value, "darkgray", 169, 169, 169, color, result);
        COLOR_FROM_NAME(value, "lightgray", 211, 211, 211, color, result);
        COLOR_FROM_NAME(value, "gainsboro", 220, 220, 220, color, result);
        
        if (result == 0) {
            printf("HTML_ParseColorAttribute: Unknown color %s\n", value);
        }
    }

    return color;
}

pixels_t HTML_ParsePixelsAttribute(char* value)
{
    pixels_t pixels = atoi(value);
    return pixels;
}

length_t HTML_ParseLengthAttribute(char* value)
{
    length_t length;

    // First, get the actual number specified in the length.
    int len;
    for (int i = 0; i < strlen(value); i++) {
        // If it's not a number, we don't care about it.
        if (value[i] >= '0' && value[i] <= '9') {
            len = len * 10 + (value[i] - '0');
        }
    }
    length.len = len;
    
    // Now parse the suffix to determine whether its absolute
    // or relative.
    // Why can't these all have a static measurement length.. :(
    char last_char = value[strlen(value) - 1];
    char last2_char = value[strlen(value) - 2];
    char last3_char = value[strlen(value) - 3];
    char last4_char = value[strlen(value) - 4];

    // Relative Measurements
    if (last_char == '%') {
        length.type = LEN_PERCENT;
    } else if (last2_char == 'e') {
        if (last_char == 'm') {
            if (last3_char == 'r') {
                length.type = LEN_REM;
            } else {
                length.type = LEN_EM;
            }
        }
     
        if (last_char == 'x') {
            length.type = LEN_EX;
        }
    } else if (last2_char == 'c' && last_char == 'h') {
        length.type = LEN_CH;
    } else if (last2_char == 'v') {
        if (last_char == 'w') {
            length.type = LEN_VW;
        } else if (last_char == 'h') {
            length.type = LEN_VH;
        }
    } else if (last4_char == 'v' && last3_char == 'm') {
        if (last2_char == 'i' && last_char == 'n') {
            length.type = LEN_VMIN;
        } else if (last2_char == 'a' && last_char == 'x') {
            length.type = LEN_VMAX;
        }
    }
    // Absolute measurements
    // We only store these in pixels, despite there being
    // a lot of different absolute measurements. The reason
    // being, they all have documented conversion factors:
    // (https://www.w3schools.com/cssref/css_units.php)
    // -----
    // cm   centimeters
    // mm   millimeters
    // in   inches (1in = 96px = 2.54cm)
    // px   pixels (1px = 1/96th of 1in)
    // pt   points (1pt = 1/72 of 1in)
    // pc   picas (1pc = 12 pt) 
    // -----
    // We only use integer precision here though. So there
    // is going to be some inaccuracy. Hopefully it'll never
    // be too bad!

    // Centimeter
    else if (last2_char == 'c' && last_char == 'm') {
        // 1 in = 2.54 cm
        // 1 pixel = 1/96 in
        // pixel = (2.54 * (1/96))
        length.len *= (int)(2.54 * (float)(1/96));
        length.type = LEN_PIXEL;
    }
    // Millimeter
    else if (last2_char == 'm' && last_char == 'm') {
        // 1cm = 10mm
        // pixel = (2.54 * 10 * (1/96))
        length.len *= (int)(2.54 * 10 * (float)(1/96));
        length.type = LEN_PIXEL;
    }
    // Inch
    else if (last2_char == 'i' && last_char == 'n') {
        // pixel = (1/96) in
        length.len = (int)((float)(length.len) * (float)(1/96));
        length.type = LEN_PIXEL;
    }
    // Pixel (do nothing)
    else if (last2_char == 'p' && last_char == 'x') {
        length.type = LEN_PIXEL;
    }
    // Point
    else if (last2_char == 'p' && last_char == 't') {
        // 1 pt = 1.33 px 
        // (i cheated: https://weboverhauls.github.io/conversion-table/)
        length.len = (int)((float)length.len * 1.33);
        length.type = LEN_PIXEL;
    }
    // Pica
    else if (last2_char == 'p' && last_char == 'c') {
        // 1 pc = 12pt
        length.len = (int)((float)length.len * 1.33 * 12);
        length.type = LEN_PIXEL;
    } else {
        if (last_char >= '0' && last_char <= '9') {
            length.type = LEN_PIXEL;
        } else {
            printf("HTML_ParseLengthAttribute: Unknown measurement"
            " in length %s. Ignoring\n", value);
            length.len = 0; 
        }
    }

    return length;
}

clear_t HTML_ParseClearAttribute(char* value)
{
    clear_t clear;
    int result = 0;

    GEN_FROM_VALUE(value, "left", CLEAR_LEFT, clear, result);
    GEN_FROM_VALUE(value, "right", CLEAR_RIGHT, clear, result);
    GEN_FROM_VALUE(value, "all", CLEAR_ALL, clear, result);
    GEN_FROM_VALUE(value, "none", CLEAR_NONE, clear, result);

    if (result == 0) {
        printf("HTML_ParseClearAttribute: Unknown clear value %s\n", value);
    }

    return clear;
}

number_t HTML_ParseNumberAttribute(char* value)
{
    number_t number = strtod(value, NULL);
    return number;
}

coords_t HTML_ParseCoordsAttribute(char* value)
{
    coords_t coords;

    unsigned int coord[4];
    int coord_index = 0;
    for (int i = 0; i < strlen(value); i++) {
        // Ignore any number after the 4 coords
        if (coord_index > 3)
            continue;
        // This is off spec, but basically if it's not
        // a number, we don't care about it.
        if (value[i] >= '0' && value[i] <= '9') {
            coord[coord_index] = coord[coord_index] * 10 + (value[i] - '0');
        } else if (value[i] == ',') {
            coord_index++; // Move to the next color component
        }
    }

    // Fill the coords struct with the data
    coords.x = coord[0];
    coords.y = coord[1];
    coords.w = coord[2];
    coords.h = coord[3];

    return coords;
}

tframe_t HTML_ParseTFrameAttribute(char* value)
{
    tframe_t tframe;
    int result = 0;

    GEN_FROM_VALUE(value, "void", TF_VOID, tframe, result);
    GEN_FROM_VALUE(value, "above", TF_ABOVE, tframe, result);
    GEN_FROM_VALUE(value, "below", TF_BELOW, tframe, result);
    GEN_FROM_VALUE(value, "hsides", TF_HSIDES, tframe, result);
    GEN_FROM_VALUE(value, "lhs", TF_LHS, tframe, result);
    GEN_FROM_VALUE(value, "rhs", TF_RHS, tframe, result);
    GEN_FROM_VALUE(value, "vsides", TF_VSIDES, tframe, result);
    GEN_FROM_VALUE(value, "box", TF_BOX, tframe, result);
    GEN_FROM_VALUE(value, "border", TF_BORDER, tframe, result);
    
    if (result == 0) {
        printf("HTML_ParseTFrameAttribute: Unknown tframe %s\n", value);
    }

    return tframe;
}

method_t HTML_ParseMethodAttribute(char* value)
{
    method_t method;
    int result = 0;

    GEN_FROM_VALUE(value, "get", METHOD_GET, method, result);
    GEN_FROM_VALUE(value, "post", METHOD_POST, method, result);
    
    if (result == 0) {
        printf("HTML_ParseMethodAttribute: Unknown method %s\n", value);
    }

    return method;
}

trules_t HTML_ParseTRulesAttribute(char* value)
{
    trules_t trules;
    int result = 0;

    GEN_FROM_VALUE(value, "none", TR_NONE, trules, result);
    GEN_FROM_VALUE(value, "groups", TR_GROUPS, trules, result);
    GEN_FROM_VALUE(value, "rows", TR_ROWS, trules, result);
    GEN_FROM_VALUE(value, "cols", TR_COLS, trules, result);
    GEN_FROM_VALUE(value, "all", TR_ALL, trules, result);

    if (result == 0) {
        printf("HTML_ParseTRulesAttribute: Unknown rule %s\n", value);
    }

    return trules;
}

scope_t HTML_ParseScopeAttribute(char* value)
{
    scope_t scope;
    int result = 0;

    GEN_FROM_VALUE(value, "row", SCOPE_ROW, scope, result);
    GEN_FROM_VALUE(value, "col", SCOPE_COL, scope, result);
    GEN_FROM_VALUE(value, "rowgroup", SCOPE_ROWGROUP, scope, result);
    GEN_FROM_VALUE(value, "colgroup", SCOPE_COLGROUP, scope, result);
    
    if (result == 0) {
        printf("HTML_ParseScopeAttribute: Unknown scope %s\n", value);
    }

    return scope;
}

scroll_t HTML_ParseScrollAttribute(char* value)
{
    scroll_t scroll;
    int result = 0;

    GEN_FROM_VALUE(value, "yes", SCROLL_YES, scroll, result);
    GEN_FROM_VALUE(value, "no", SCROLL_NO, scroll, result);
    GEN_FROM_VALUE(value, "auto", SCROLL_AUTO, scroll, result);

    if (result == 0) {
        printf("HTML_ParseScrollAttribute: Unknown scroll value %s\n", value);
    }

    return scroll;
}

shape_t HTML_ParseShapeAttribute(char* value)
{
    shape_t shape;
    int result = 0;

    GEN_FROM_VALUE(value, "rect", SHAPE_RECT, shape, result);
    GEN_FROM_VALUE(value, "circle", SHAPE_CIRCLE, shape, result);
    GEN_FROM_VALUE(value, "poly", SHAPE_POLY, shape, result);
    GEN_FROM_VALUE(value, "default", SHAPE_DEFAULT, shape, result);

    if (result == 0) {
        printf("HTML_ParseShapeAttribute: Unknown shape %s\n", value);
    }

    return shape;
}

char* HTML_ParseStyleSheetAttribute(char* value)
{
    int size = strlen(value);

    // If the end of a stylesheet has whitespace,
    // adjust the size to avoid copying it.
    if (value[size - 1] == ' ')
        size -= 1;

    char* dest = malloc(sizeof(char)*(size + 1));

    for (int i = 0; i < size; i++) {
        dest[i] = value[i];
    }
    dest[size + 1] = '\0';

    if (dest[strlen(dest) - 1] != ';')
        printf("HTML_ParseStyleSheetAttribute: style \'%s\'"
        " is missing ending semi-colon (;)\n", value);

    return dest;
}

valign_t HTML_ParseVAlignAttribute(char* value)
{
    valign_t valign;
    int result = 0;

    GEN_FROM_VALUE(value, "top", VA_TOP, valign, result);
    GEN_FROM_VALUE(value, "middle", VA_MIDDLE, valign, result);
    GEN_FROM_VALUE(value, "bottom", VA_BOTTOM, valign, result);
    GEN_FROM_VALUE(value, "baseline", VA_BASELINE, valign, result);

    if (result == 0) {
        printf("HTML_ParseShapeAttribute: Unknown valign %s\n", value);
    }

    return valign;
}

valuetype_t HTML_ParseValueTypeAttribute(char* value)
{
    valuetype_t valuetype;
    int result = 0;

    GEN_FROM_VALUE(value, "data", VT_DATA, valuetype, result);
    GEN_FROM_VALUE(value, "ref", VT_REF, valuetype, result);
    GEN_FROM_VALUE(value, "object", VT_OBJECT, valuetype, result);

    if (result == 0) {
        printf("HTML_ParseValuetypeAttribute: Unknown valuetype %s\n", value);
    }

    return valuetype;
}

void HTML_ParseAttributeContent(char* html_data, char* attribute_name, bool has_value,
                                        attribute_t* attributes, int* offset)
{
    // First off - we need to store the value in a char*,
    // so let's prep that.
    char* attr_value = NULL;
    char* real_value = NULL;

    if (has_value) {
        // Before we begin, there's potential need to scrub the
        // data at this point: we're particularly looking for
        // whitespace and the start identifier ('"").
        bool whitespace = true;
        while(whitespace) {
            if (html_data[*offset] != ' ') {
                whitespace = false;
                break;
            } else {
                *offset += 1;
            }
        }

        if (html_data[*offset - 1] == '"' && 
        html_data[*offset] == '"') {
            has_value = false;
            *offset += 1;
            return;
        } 

        if (html_data[*offset - 1] == ' ' && 
        html_data[*offset - 2] == '"' &&
        html_data[*offset] == '"') {
            has_value = false;
            *offset += 1;
            return;
        }

        // Now, if we're at a '"', skip that too.
        if (html_data[*offset] == '"') {
            *offset += 1;
        }
            

        // Allocate memory for the char* that holds the value.
        attr_value = malloc(sizeof(char)*MAX_ATTR_VAL_LEN);

        // Store the offset index for the value parsing.
        int val_offset = 0;

        // Just like BeginParse, iterate through the document.
        int i = 0;

        for (i = 0; i < MAX_ATTR_VAL_LEN; i++) {
            // End of value, break off.
            if (html_data[i + *offset] == '"') {
                i++;
                break;
            }

            // Otherwise, append to value contents.
            attr_value[val_offset] = html_data[i + *offset];
            attr_value[val_offset + 1] = '\0';
            val_offset++;
        }

        // Update the document position.
        *offset += i;

        // Now we have a mess to clean up, obviously we don't want
        // to allocate 512 bytes for every attribute value.
        real_value = malloc(sizeof(char)*(val_offset + 1));

        // Copy the value data to the optimized char*.
        for (int j = 0; j < val_offset + 1; j++) {
            real_value[j] = attr_value[j];
        }

        // Free the bloaty one.
        free(attr_value);
    }

    // Iterate through all supported attributes and fill
    // the value accordingly.
    char* name = attribute_name;
    int result = 0;

    if (name[0] == 'a' || name[0] == 'A') {
        ASSIGN_TEXT_ATTR(name, "abbr", attributes->abbr, real_value, result);
        ASSIGN_CSET_ATTR(name, "accept-charset", attributes->accept_charset,
                        real_value, result);
        ASSIGN_CONT_ATTR(name, "accept", attributes->accept, real_value, result);
        ASSIGN_CHAR_ATTR(name, "accesskey", attributes->accesskey, real_value, result);
        ASSIGN_TEXT_ATTR(name, "action", attributes->action, real_value, result);
        ASSIGN_ALGN_ATTR(name, "align", attributes->align, real_value, result);
        ASSIGN_TEXT_ATTR(name, "alt", attributes->alt, real_value, result);
        ASSIGN_TEXT_ATTR(name, "archive", attributes->archive, real_value, result);
        ASSIGN_TEXT_ATTR(name, "axis", attributes->axis, real_value, result);
    } else if (attribute_name[0] == 'b' || attribute_name[0] == 'B') {
        ASSIGN_TEXT_ATTR(name, "background", attributes->background, real_value, result);
        ASSIGN_COLR_ATTR(name, "bgcolor", attributes->bgcolor, real_value, result);
        ASSIGN_PIXL_ATTR(name, "border", attributes->border, real_value, result);
        ASSIGN_LENG_ATTR(name, "bottommargin", attributes->bottommargin, real_value, result);
    } else if (attribute_name[0] == 'c' || attribute_name[0] == 'C') {
        ASSIGN_LENG_ATTR(name, "cellpadding", attributes->cellpadding, real_value, result);
        ASSIGN_LENG_ATTR(name, "cellspacing", attributes->cellspacing, real_value, result);
        ASSIGN_CHAR_ATTR(name, "char", attributes->_char, real_value, result);
        ASSIGN_LENG_ATTR(name, "charoff", attributes->charoff, real_value, result);
        ASSIGN_CSET_ATTR(name, "charset", attributes->charset, real_value, result);
        ASSIGN_BOOL_ATTR(name, "checked", attributes->checked, real_value, result);
        ASSIGN_TEXT_ATTR(name, "cite", attributes->cite, real_value, result);
        ASSIGN_TEXT_ATTR(name, "class", attributes->class, real_value, result);
        ASSIGN_TEXT_ATTR(name, "classid", attributes->classid, real_value, result);
        ASSIGN_CLER_ATTR(name, "clear", attributes->clear, real_value, result);
        ASSIGN_TEXT_ATTR(name, "code", attributes->code, real_value, result);
        ASSIGN_TEXT_ATTR(name, "codebase", attributes->codebase, real_value, result);
        ASSIGN_CONT_ATTR(name, "codetype", attributes->codetype, real_value, result);
        ASSIGN_COLR_ATTR(name, "color", attributes->color, real_value, result);
        ASSIGN_LENG_ATTR(name, "cols", attributes->cols, real_value, result);
        ASSIGN_NUMB_ATTR(name, "colspan", attributes->colspan, real_value, result);
        ASSIGN_BOOL_ATTR(name, "compact", attributes->compact, real_value, result);
        ASSIGN_TEXT_ATTR(name, "content", attributes->content, real_value, result);
        ASSIGN_CORD_ATTR(name, "coords", attributes->coords, real_value, result);
    } else if (attribute_name[0] == 'd' || attribute_name[0] == 'D') {
        ASSIGN_TEXT_ATTR(name, "data", attributes->data, real_value, result);
        ASSIGN_TEXT_ATTR(name, "datetime", attributes->datetime, real_value, result);
        ASSIGN_BOOL_ATTR(name, "declare", attributes->declare, real_value, result);
        ASSIGN_BOOL_ATTR(name, "dir", attributes->dir, real_value, result);
        ASSIGN_BOOL_ATTR(name, "disabled", attributes->disabled, real_value, result);
    } else if (attribute_name[0] == 'e' || attribute_name[0] == 'E') {
        ASSIGN_CONT_ATTR(name, "enctype", attributes->enctype, real_value, result);
    } else if (attribute_name[0] == 'f' || attribute_name[0] == 'F') {
        ASSIGN_TEXT_ATTR(name, "face", attributes->face, real_value, result);
        ASSIGN_TEXT_ATTR(name, "for", attributes->_for, real_value, result);
        ASSIGN_TFRM_ATTR(name, "frame", attributes->frame, real_value, result);
        ASSIGN_BOOL_ATTR(name, "frameborder", attributes->frameborder, real_value, result);
    } else if (attribute_name[0] == 'h' || attribute_name[0] == 'H') {
        ASSIGN_TEXT_ATTR(name, "headers", attributes->headers, real_value, result);
        ASSIGN_LENG_ATTR(name, "height", attributes->height, real_value, result);
        ASSIGN_TEXT_ATTR(name, "href", attributes->href, real_value, result);
        ASSIGN_TEXT_ATTR(name, "hreflang", attributes->hreflang, real_value, result);
        ASSIGN_PIXL_ATTR(name, "hspace", attributes->hspace, real_value, result);
        ASSIGN_TEXT_ATTR(name, "http-equiv", attributes->http_equiv, real_value, result);
    } else if (attribute_name[0] == 'i' || attribute_name[0] == 'I') {
        ASSIGN_TEXT_ATTR(name, "id", attributes->id, real_value, result);
        ASSIGN_BOOL_ATTR(name, "ismap", attributes->ismap, real_value, result);
    } else if (attribute_name[0] == 'l' || attribute_name[0] == 'L') {
        ASSIGN_TEXT_ATTR(name, "label", attributes->label, real_value, result);
        ASSIGN_TEXT_ATTR(name, "lang", attributes->lang, real_value, result);
        ASSIGN_TEXT_ATTR(name, "language", attributes->language, real_value, result);
        ASSIGN_LENG_ATTR(name, "leftmargin", attributes->leftmargin, real_value, result);
        ASSIGN_COLR_ATTR(name, "link", attributes->link, real_value, result);
        ASSIGN_TEXT_ATTR(name, "longdesc", attributes->longdesc, real_value, result);
    } else if (attribute_name[0] == 'm' || attribute_name[0] == 'M') {
        ASSIGN_PIXL_ATTR(name, "marginheight", attributes->marginheight, real_value, result);
        ASSIGN_PIXL_ATTR(name, "marginwidth", attributes->marginwidth, real_value, result);
        ASSIGN_NUMB_ATTR(name, "maxlength", attributes->maxlength, real_value, result);
        ASSIGN_TEXT_ATTR(name, "media", attributes->media, real_value, result);
        ASSIGN_MTHD_ATTR(name, "method", attributes->method, real_value, result);
        ASSIGN_BOOL_ATTR(name, "multiple", attributes->multiple, real_value, result);
    } else if (attribute_name[0] == 'n' || attribute_name[0] == 'N') {
        ASSIGN_TEXT_ATTR(name, "name", attributes->name, real_value, result);
        ASSIGN_BOOL_ATTR(name, "nohref", attributes->nohref, real_value, result);
        ASSIGN_BOOL_ATTR(name, "noresize", attributes->noresize, real_value, result);
        ASSIGN_BOOL_ATTR(name, "noshade", attributes->noshade, real_value, result);
        ASSIGN_BOOL_ATTR(name, "nowrap", attributes->nowrap, real_value, result);
    } else if (attribute_name[0] == 'o' || attribute_name[0] == 'O') {
        ASSIGN_TEXT_ATTR(name, "object", attributes->object, real_value, result);
    } else if (attribute_name[0] == 'p' || attribute_name[0] == 'P') {
        ASSIGN_TEXT_ATTR(name, "profile", attributes->profile, real_value, result);
        ASSIGN_TEXT_ATTR(name, "prompt", attributes->prompt, real_value, result);
    } else if (attribute_name[0] == 'r' || attribute_name[0] == 'R') {
        ASSIGN_BOOL_ATTR(name, "readonly", attributes->readonly, real_value, result);
        ASSIGN_TEXT_ATTR(name, "rel", attributes->rel, real_value, result);
        ASSIGN_BOOL_ATTR(name, "required", attributes->required, real_value, result);
        ASSIGN_LENG_ATTR(name, "rightmargin", attributes->rightmargin, real_value, result);
        ASSIGN_LENG_ATTR(name, "rows", attributes->rows, real_value, result);
        ASSIGN_NUMB_ATTR(name, "rowspan", attributes->rowspan, real_value, result);
        ASSIGN_TRLE_ATTR(name, "rules", attributes->rules, real_value, result);
    } else if (attribute_name[0] == 's' || attribute_name[0] == 'S') {
        ASSIGN_TEXT_ATTR(name, "scheme", attributes->scheme, real_value, result);
        ASSIGN_SCOP_ATTR(name, "scope", attributes->scope, real_value, result);
        ASSIGN_SCRL_ATTR(name, "scrolling", attributes->scrolling, real_value, result);
        ASSIGN_BOOL_ATTR(name, "selected", attributes->selected, real_value, result);
        ASSIGN_SHPE_ATTR(name, "shape", attributes->shape, real_value, result);
        ASSIGN_TEXT_ATTR(name, "size", attributes->size, real_value, result);
        ASSIGN_NUMB_ATTR(name, "span", attributes->span, real_value, result);
        ASSIGN_TEXT_ATTR(name, "src", attributes->src, real_value, result);
        ASSIGN_TEXT_ATTR(name, "standby", attributes->standby, real_value, result);
        ASSIGN_NUMB_ATTR(name, "start", attributes->start, real_value, result);
        ASSIGN_STYL_ATTR(name, "style", attributes->style, real_value, result);
        ASSIGN_TEXT_ATTR(name, "summary", attributes->summary, real_value, result);
    } else if (attribute_name[0] == 't' || attribute_name[0] == 'T') {
        ASSIGN_NUMB_ATTR(name, "tabindex", attributes->tabindex, real_value, result);
        ASSIGN_TEXT_ATTR(name, "target", attributes->target, real_value, result);
        ASSIGN_COLR_ATTR(name, "text", attributes->text, real_value, result);
        ASSIGN_TEXT_ATTR(name, "title", attributes->title, real_value, result);
        ASSIGN_LENG_ATTR(name, "topmargin", attributes->topmargin, real_value, result);
        ASSIGN_TEXT_ATTR(name, "type", attributes->type, real_value, result);
    } else if (attribute_name[0] == 'u' || attribute_name[0] == 'U') {
        ASSIGN_TEXT_ATTR(name, "usemap", attributes->usemap, real_value, result);
    } else if (attribute_name[0] == 'v' || attribute_name[0] == 'V') {
        ASSIGN_VALN_ATTR(name, "valign", attributes->valign, real_value, result);
        ASSIGN_TEXT_ATTR(name, "value", attributes->value, real_value, result);
        ASSIGN_VALT_ATTR(name, "valuetype", attributes->valuetype, real_value, result);
        ASSIGN_TEXT_ATTR(name, "version", attributes->version, real_value, result);
        ASSIGN_COLR_ATTR(name, "vlink", attributes->vlink, real_value, result);
        ASSIGN_PIXL_ATTR(name, "vspace", attributes->vspace, real_value, result);
    } else if (attribute_name[0] == 'w' || attribute_name[0] == 'W') {
        ASSIGN_LENG_ATTR(name, "width", attributes->width, real_value, result);
    } 
    
    if (result == 0) {
        printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
        attribute_name);
    }

}
