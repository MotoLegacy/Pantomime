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

void HTML_InitializeAttribute(attribute_t* attr) {
    // A
    attr->accept_charset    = CS_NONE;
    attr->accept            = CTYPE_APP_NONE;
    attr->accesskey         = '\0';
    attr->action            = NULL;
    attr->align             = ALIGN_NONE;
    attr->alt               = NULL;
    attr->archive           = NULL;
    attr->axis              = NULL;
    // B
    attr->background        = NULL;
    attr->bgcolor.r         = -1;
    attr->bgcolor.g         = -1;
    attr->bgcolor.b         = -1;
    attr->border            = -1;
    // C
    attr->cellpadding.len   = -1;
    attr->checked           = false;
    attr->_char             = '\0';
    attr->class             = NULL;
    attr->classid           = NULL;
    attr->clear             = CLEAR_NONE;
    attr->code              = NULL;
    attr->codebase          = NULL;
    attr->codetype          = CTYPE_APP_NONE;
    attr->color.r           = -1;
    attr->color.g           = -1;
    attr->color.b           = -1;
    attr->cols.len          = -1;
    attr->colspan           = -1;
    attr->compact           = NULL;
    attr->content           = NULL;
    attr->coords.x          = -1;
    attr->coords.y          = -1;
    attr->coords.w          = -1;
    attr->coords.h          = -1;
    // D
    attr->data              = NULL;
    attr->datetime          = NULL;
    attr->declare           = false;
    attr->dir               = false;
    attr->disabled          = false;
    // E
    attr->enctype           = CTYPE_APP_NONE;
    // F
    attr->face              = NULL;
    attr->_for              = NULL;
    attr->frame             = TF_NONE;
    attr->frameborder       = false;
    // H
    attr->headers           = NULL;
    attr->height.len        = -1;
    attr->href              = NULL;
    attr->hreflang          = NULL;
    attr->hspace            = -1;
    attr->http_equiv        = NULL;
    // I
    attr->id                = NULL;
    attr->ismap             = false;
    // L
    attr->label             = NULL;
    attr->lang              = NULL;
    attr->language          = NULL;
    attr->link.r            = -1;
    attr->link.g            = -1;
    attr->link.b            = -1;
    attr->longdesc          = NULL;
    // M
    attr->marginheight      = -1;
    attr->marginwidth       = -1;
    attr->maxlength         = -1;
    attr->media             = NULL;
    attr->method            = METHOD_NONE;
    attr->multiple          = false;
    // N
    attr->name              = NULL;
    attr->nohref            = false;
    attr->noresize          = false;
    attr->noshade           = false;
    attr->nowrap            = false;
    // O
    attr->object            = NULL;
    // P
    attr->profile           = NULL;
    attr->prompt            = NULL;
    // R
    attr->readonly          = false;
    attr->rel               = NULL;
    attr->required          = false;
    attr->rows.len          = -1;
    attr->rowspan           = -1;
    attr->rules             = TR_NONE;
    // S
    attr->scheme            = NULL;
    attr->scrolling         = SCROLL_NONE;
    attr->selected          = false;
    attr->shape             = SHAPE_NONE;
    attr->size              = NULL;
    attr->span              = -1;
    attr->src               = NULL;
    attr->standby           = NULL;
    attr->start             = -1;
    attr->style             = NULL;
    attr->summary           = NULL;
    // T
    attr->tabindex          = -1;
    attr->target            = NULL;
    attr->text.r            = -1;
    attr->text.b            = -1;
    attr->text.g            = -1;
    attr->title             = NULL;
    // U
    attr->usemap            = NULL;
    // V
    attr->valign            = VA_NONE;
    attr->value             = NULL;
    attr->valuetype         = VT_NONE;
    attr->version           = NULL;
    attr->vlink.r           = -1;
    attr->vlink.g           = -1;
    attr->vlink.b           = -1;
    attr->vspace            = -1;
    // W
    attr->width.len         = -1;

}


char* HTML_ParseTextAttribute(char* value)
{
    char* dest = malloc(sizeof(char)*(strlen(value) + 1));
    strcpy(dest, value);
    return dest;
}

charsets_t HTML_ParseCharsetsAttribute(char* value) 
{
    charsets_t charset;

    if (strcasecmp(value, "utf-8") == 0) {
        charset = CS_UTF8;
    } else if (strcasecmp(value, "iso-8859-1") == 0) {
        charset = CS_ISO8859;
    } else if (strcasecmp(value, "ascii") == 0) {
        charset = CS_ASCII;
    } else if (strcasecmp(value, "ansi") == 0) {
        charset = CS_ANSI;
    } else {
        printf("HTML_ParseCharsetsAttribute: Unknown charset %s, "
        "defaulting to UTF-8\n", value);
        charset = CS_UTF8;
    }

    return charset;
}

contenttypes_t HTML_ParseContentTypesAttribute(char* value)
{
    contenttypes_t content_type;

    if (strcasecmp("application/EDI-X12", value) == 0) {
        content_type = CTYPE_APP_EDIX12;
    } else if (strcasecmp("application/EDIFACT", value) == 0) {
        content_type = CTYPE_APP_EDIFACT;
    } else if (strcasecmp("application/javascript", value) == 0) {
        content_type = CTYPE_APP_JS;
    } else if (strcasecmp("application/octet-stream", value) == 0) {
        content_type = CTYPE_APP_OCTETSTREAM;
    } else if (strcasecmp("application/ogg", value) == 0) {
        content_type = CTYPE_APP_OGG;
    } else if (strcasecmp("application/pdf", value) == 0) {
        content_type = CTYPE_APP_PDF;
    } else if (strcasecmp("application/xhtml+xml", value) == 0) {
        content_type = CTYPE_APP_XHTMLXML;
    } else if (strcasecmp("application/x-shockwave-flash", value) == 0) {
        content_type = CTYPE_APP_XSHOCKWAVEFLASH;
    } else if (strcasecmp("application/json", value) == 0) {
        content_type = CTYPE_APP_JSON;
    } else if (strcasecmp("application/ld+json", value) == 0) {
        content_type = CTYPE_APP_LDJSON;
    } else if (strcasecmp("application/xml", value) == 0) {
        content_type = CTYPE_APP_XML;
    } else if (strcasecmp("application/zip", value) == 0) {
        content_type = CTYPE_APP_ZIP;
    } else if (strcasecmp("application/x-www-form-urlencoded", value) == 0) {
        content_type = CTYPE_APP_XWWWFORMURLENCODED;
    } else if (strcasecmp("audio/mpeg", value) == 0) {
        content_type = CTYPE_AUD_MPEG;
    } else if (strcasecmp("audio/x-ms-wma", value) == 0) {
        content_type = CTYPE_AUD_XMASWMA;
    } else if (strcasecmp("audio/vnd.rn-realaudio", value) == 0) {
        content_type = CTYPE_AUD_VNDRNREALAUDIO;
    } else if (strcasecmp("audio/x-wav", value) == 0) {
        content_type = CTYPE_AUD_XWAV;
    } else if (strcasecmp("image/gif", value) == 0) {
        content_type = CTYPE_IMG_GIF;
    } else if (strcasecmp("image/jpeg", value) == 0) {
        content_type = CTYPE_IMG_JPEG;
    } else if (strcasecmp("image/png", value) == 0) {
        content_type = CTYPE_IMG_PNG;
    } else if (strcasecmp("image/tiff", value) == 0) {
        content_type = CTYPE_IMG_TIFF;
    } else if (strcasecmp("image/vnd.microsoft.icon", value) == 0) {
        content_type = CTYPE_IMG_VNDMICROSOFTICON;
    } else if (strcasecmp("image/x-icon", value) == 0) {
        content_type = CTYPE_IMG_XICON;
    } else if (strcasecmp("image/vnd.djvu", value) == 0) {
        content_type = CTYPE_IMG_VNDDJVU;
    } else if (strcasecmp("image/svg+xml", value) == 0) {
        content_type = CTYPE_IMG_SVGXML;
    } else if (strcasecmp("multipart/mixed", value) == 0) {
        content_type = CTYPE_MPA_MIXED;
    } else if (strcasecmp("multipart/alternative", value) == 0) {
        content_type = CTYPE_MPA_ALTERNATIVE;
    } else if (strcasecmp("multipart/related", value) == 0) {
        content_type = CTYPE_MPA_RELATED;
    } else if (strcasecmp("multipart/form-data", value) == 0) {
        content_type = CTYPE_MPA_FORMDATA;
    } else if (strcasecmp("text/css", value) == 0) {
        content_type = CTYPE_TXT_CSS;
    } else if (strcasecmp("text/csv", value) == 0) {
        content_type = CTYPE_TXT_CSV;
    } else if (strcasecmp("text/html", value) == 0) {
        content_type = CTYPE_TXT_HTML;
    } else if (strcasecmp("text/javascript", value) == 0) {
        content_type = CTYPE_TXT_JS;
    } else if (strcasecmp("text/plain", value) == 0) {
        content_type = CTYPE_TXT_PLAIN;
    } else if (strcasecmp("text/xml", value) == 0) {
        content_type = CTYPE_TXT_XML;
    } else if (strcasecmp("video/mpeg", value) == 0) {
        content_type = CTYPE_VID_MPEG;
    } else if (strcasecmp("video/mp4", value) == 0) {
        content_type = CTYPE_VID_MP4;
    } else if (strcasecmp("video/quicktime", value) == 0) {
        content_type = CTYPE_VID_QUICKTIME;
    } else if (strcasecmp("video/x-ms-wmv", value) == 0) {
        content_type = CTYPE_VID_XMSWMV;
    } else if (strcasecmp("video/x-msvideo", value) == 0) {
        content_type = CTYPE_VID_XMSVIDEO;
    } else if (strcasecmp("video/x-flv", value) == 0) {
        content_type = CTYPE_VID_XFLV;
    } else if (strcasecmp("video/webm", value) == 0) {
        content_type = CTYPE_VID_WEBM;
    } else if (strcasecmp("application/vnd.oasis.opendocument.text", value) == 0) {
        content_type = CTYPE_APP_VNDOASISOPENDOCUMENTTEXT;
    } else if (strcasecmp("application/vnd.oasis.opendocument.spreadsheet", value) == 0) {
        content_type = CTYPE_APP_VNDOASISOPENDOCUMENTSPREADSHEET;
    } else if (strcasecmp("application/vnd.oasis.opendocument.presentation", value) == 0) {
        content_type = CTYPE_APP_VNDOASISOPENDOCUMENTPRESENTATION;
    } else if (strcasecmp("application/vnd.oasis.opendocument.graphics", value) == 0) {
        content_type = CTYPE_APP_VNDOASISOPENDOCUMENTGRAPHICS;
    } else if (strcasecmp("application/vnd.ms-excel", value) == 0) {
        content_type = CTYPE_APP_VNDMSEXCEL;
    } else if (strcasecmp("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet", value) == 0) {
        content_type = CTYPE_APP_VNDOPENXMLFORMATSOFFICEDOCUMENTSPREADSHEET;
    } else if (strcasecmp("application/vnd.ms-powerpoint", value) == 0) {
        content_type = CTYPE_APP_VNDMSPOWERPOINT;
    } else if (strcasecmp("application/vnd.openxmlformats-", value) == 0) {
        content_type = CTYPE_APP_VNDOPENXMLFORMATS;
    } else if (strcasecmp("officedocument.presentationml.presentation", value) == 0) {
        content_type = CTYPE_APP_VNDOPENXMLFORMATSOFFICEDOCUMENTPRESENTATIONMLPRESENTATION;
    } else if (strcasecmp("application/msword", value) == 0) {
        content_type = CTYPE_APP_MSWORD;
    } else if (strcasecmp("officedocument.wordprocessingml.document", value) == 0) {
        content_type = CTYPE_APP_VNDOPENXMLFORMATSOFFICEDOCUMENTWORDPROCESSINGMLDOCUMENT;
    } else if (strcasecmp("application/vnd.mozilla.xul+xml", value) == 0) {
        content_type = CTYPE_APP_VNDMOZILLAXULXML;
    } else {
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

    if (strcasecmp("top", value) == 0) {
        align = ALIGN_TOP;
    } else if (strcasecmp("left", value) == 0) {
        align = ALIGN_LEFT;
    } else if (strcasecmp("center", value) == 0) {
        align = ALIGN_CENTER;
    } else if (strcasecmp("right", value) == 0) {
        align = ALIGN_RIGHT;
    } else if (strcasecmp("bottom", value) == 0) {
        align = ALIGN_BOTTOM;
    } else if (strcasecmp("middle", value) == 0) {
        align = ALIGN_MIDDLE;
    } else if (strcasecmp("justify", value) == 0) {
        align = ALIGN_JUSTIFY;
    } else if (strcasecmp("char", value) == 0) {
        align = ALIGN_CHAR;
    } else {
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
        //
        // Standard HTML 4.01 colors
        // https://en.wikipedia.org/wiki/Web_colors#Basic_colors
        //
        if (strcasecmp("white", value) == 0) {
            color.r = 255;
            color.g = 255;
            color.b = 255;
        } else if (strcasecmp("silver", value) == 0) {
            color.r = 191;
            color.g = 191;
            color.b = 191;
        } else if (strcasecmp("gray", value) == 0) {
            color.r = 128;
            color.g = 128;
            color.b = 128;
        } else if (strcasecmp("black", value) == 0) {
            color.r = 0;
            color.g = 0;
            color.b = 0;
        } else if (strcasecmp("red", value) == 0) {
            color.r = 255;
            color.g = 0;
            color.b = 0;
        } else if (strcasecmp("maroon", value) == 0) {
            color.r = 128;
            color.g = 0;
            color.b = 0;
        } else if (strcasecmp("yellow", value) == 0) {
            color.r = 255;
            color.g = 255;
            color.b = 0;
        } else if (strcasecmp("olive", value) == 0) {
            color.r = 128;
            color.g = 128;
            color.b = 0;
        } else if (strcasecmp("lime", value) == 0) {
            color.r = 0;
            color.g = 255;
            color.b = 0;
        } else if (strcasecmp("green", value) == 0) {
            color.r = 0;
            color.g = 128;
            color.b = 0;
        } else if (strcasecmp("aqua", value) == 0) {
            color.r = 0;
            color.g = 255;
            color.b = 255;
        } else if (strcasecmp("teal", value) == 0) {
            color.r = 0;
            color.g = 128;
            color.b = 128;
        } else if (strcasecmp("blue", value) == 0) {
            color.r = 0;
            color.g = 0;
            color.b = 255;
        }  else if (strcasecmp("navy", value) == 0) {
            color.r = 0;
            color.g = 0;
            color.b = 128;
        } else if (strcasecmp("fuschia", value) == 0) {
            color.r = 255;
            color.g = 0;
            color.b = 255;
        } else if (strcasecmp("purple", value) == 0) {
            color.r = 128;
            color.g = 0;
            color.b = 128;
        }
        //
        // Extended HTML colors
        // https://en.wikipedia.org/wiki/Web_colors#Extended_colors
        //
        // Pink colors
        else if (strcasecmp("mediumvioletred", value) == 0) {
            color.r = 199;
            color.g = 21;
            color.b = 133;
        } else if (strcasecmp("deeppink", value) == 0) {
            color.r = 255;
            color.g = 20;
            color.b = 147;
        } else if (strcasecmp("palevioletred", value) == 0) {
            color.r = 219;
            color.g = 112;
            color.b = 147;
        } else if (strcasecmp("hotpink", value) == 0) {
            color.r = 255;
            color.g = 105;
            color.b = 180;
        } else if (strcasecmp("lightpink", value) == 0) {
            color.r = 255;
            color.g = 182;
            color.b = 193;
        } else if (strcasecmp("pink", value) == 0) {
            color.r = 255;
            color.g = 192;
            color.b = 203;
        } 
        // Red colors
        else if (strcasecmp("darkred", value) == 0) {
            color.r = 139;
            color.g = 0;
            color.b = 0;
        } else if (strcasecmp("firebrick", value) == 0) {
            color.r = 178;
            color.g = 34;
            color.b = 34;
        } else if (strcasecmp("crimson", value) == 0) {
            color.r = 220;
            color.g = 20;
            color.b = 60;
        } else if (strcasecmp("indianred", value) == 0) {
            color.r = 205;
            color.g = 92;
            color.b = 92;
        } else if (strcasecmp("lightcoral", value) == 0) {
            color.r = 240;
            color.g = 128;
            color.b = 128;
        } else if (strcasecmp("salmon", value) == 0) {
            color.r = 250;
            color.g = 128;
            color.b = 114;
        } else if (strcasecmp("darksalmon", value) == 0) {
            color.r = 233;
            color.g = 150;
            color.b = 122;
        } else if (strcasecmp("lightsalmon", value) == 0) {
            color.r = 255;
            color.g = 160;
            color.b = 122;
        } 
        // Orange colors
        else if (strcasecmp("orangered", value) == 0) {
            color.r = 255;
            color.g = 69;
            color.b = 0;
        } else if (strcasecmp("tomato", value) == 0) {
            color.r = 255;
            color.g = 99;
            color.b = 71;
        } else if (strcasecmp("darkorange", value) == 0) {
            color.r = 255;
            color.g = 140;
            color.b = 0;
        } else if (strcasecmp("coral", value) == 0) {
            color.r = 255;
            color.g = 127;
            color.b = 80;
        } else if (strcasecmp("orange", value) == 0) {
            color.r = 255;
            color.g = 165;
            color.b = 0;
        } 
        // Yellow colors
        else if (strcasecmp("darkkhaki", value) == 0) {
            color.r = 189;
            color.g = 183;
            color.b = 107;
        } else if (strcasecmp("gold", value) == 0) {
            color.r = 255;
            color.g = 215;
            color.b = 0;
        } else if (strcasecmp("khaki", value) == 0) {
            color.r = 240;
            color.g = 230;
            color.b = 140;
        } else if (strcasecmp("peachpuff", value) == 0) {
            color.r = 255;
            color.g = 218;
            color.b = 185;
        } else if (strcasecmp("palegoldenrod", value) == 0) {
            color.r = 238;
            color.g = 232;
            color.b = 170;
        } else if (strcasecmp("moccasin", value) == 0) {
            color.r = 255;
            color.g = 228;
            color.b = 181;
        } else if (strcasecmp("papayawhip", value) == 0) {
            color.r = 255;
            color.g = 239;
            color.b = 213;
        } else if (strcasecmp("lightgoldenrodyellow", value) == 0) {
            color.r = 250;
            color.g = 250;
            color.b = 210;
        } else if (strcasecmp("lemonchiffon", value) == 0) {
            color.r = 255;
            color.g = 250;
            color.b = 205;
        } else if (strcasecmp("lightyellow", value) == 0) {
            color.r = 255;
            color.g = 255;
            color.b = 224;
        } 
        // Brown colors
        else if (strcasecmp("brown", value) == 0) {
            color.r = 165;
            color.g = 42;
            color.b = 42;
        } else if (strcasecmp("saddlebrown", value) == 0) {
            color.r = 139;
            color.g = 69;
            color.b = 19;
        } else if (strcasecmp("sienna", value) == 0) {
            color.r = 160;
            color.g = 82;
            color.b = 45;
        } else if (strcasecmp("chocolate", value) == 0) {
            color.r = 210;
            color.g = 105;
            color.b = 30;
        } else if (strcasecmp("darkgoldenrod", value) == 0) {
            color.r = 184;
            color.g = 134;
            color.b = 11;
        } else if (strcasecmp("peru", value) == 0) {
            color.r = 205;
            color.g = 133;
            color.b = 63;
        } else if (strcasecmp("rosybrown", value) == 0) {
            color.r = 188;
            color.g = 143;
            color.b = 143;
        } else if (strcasecmp("goldenrod", value) == 0) {
            color.r = 218;
            color.g = 165;
            color.b = 32;
        } else if (strcasecmp("sandybrown", value) == 0) {
            color.r = 244;
            color.g = 164;
            color.b = 96;
        } else if (strcasecmp("tan", value) == 0) {
            color.r = 210;
            color.g = 180;
            color.b = 140;
        } else if (strcasecmp("burlywood", value) == 0) {
            color.r = 222;
            color.g = 184;
            color.b = 135;
        } else if (strcasecmp("wheat", value) == 0) {
            color.r = 245;
            color.g = 222;
            color.b = 179;
        } else if (strcasecmp("navajowhite", value) == 0) {
            color.r = 255;
            color.g = 222;
            color.b = 173;
        } else if (strcasecmp("bisque", value) == 0) {
            color.r = 255;
            color.g = 228;
            color.b = 196;
        } else if (strcasecmp("blanchedalmond", value) == 0) {
            color.r = 255;
            color.g = 235;
            color.b = 205;
        } else if (strcasecmp("cornsilk", value) == 0) {
            color.r = 255;
            color.g = 248;
            color.b = 220;
        } 
        // Purple, violet, and magenta colors
        else if (strcasecmp("indigo", value) == 0) {
            color.r = 75;
            color.g = 0;
            color.b = 130;
        } else if (strcasecmp("darkmagenta", value) == 0) {
            color.r = 139;
            color.g = 0;
            color.b = 139;
        } else if (strcasecmp("darkviolet", value) == 0) {
            color.r = 148;
            color.g = 0;
            color.b = 211;
        } else if (strcasecmp("darkslateblue", value) == 0) {
            color.r = 72;
            color.g = 61;
            color.b = 139;
        } else if (strcasecmp("blueviolet", value) == 0) {
            color.r = 138;
            color.g = 43;
            color.b = 226;
        } else if (strcasecmp("darkorchid", value) == 0) {
            color.r = 153;
            color.g = 50;
            color.b = 204;
        } else if (strcasecmp("magenta", value) == 0) {
            color.r = 255;
            color.g = 0;
            color.b = 255;
        } else if (strcasecmp("slateblue", value) == 0) {
            color.r = 106;
            color.g = 90;
            color.b = 205;
        } else if (strcasecmp("mediumslateblue", value) == 0) {
            color.r = 123;
            color.g = 104;
            color.b = 238;
        } else if (strcasecmp("mediumorchid", value) == 0) {
            color.r = 186;
            color.g = 85;
            color.b = 211;
        } else if (strcasecmp("mediumpurple", value) == 0) {
            color.r = 147;
            color.g = 112;
            color.b = 219;
        } else if (strcasecmp("orchid", value) == 0) {
            color.r = 218;
            color.g = 112;
            color.b = 214;
        } else if (strcasecmp("violet", value) == 0) {
            color.r = 238;
            color.g = 130;
            color.b = 238;
        } else if (strcasecmp("plum", value) == 0) {
            color.r = 221;
            color.g = 160;
            color.b = 221;
        } else if (strcasecmp("thistle", value) == 0) {
            color.r = 216;
            color.g = 191;
            color.b = 216;
        } else if (strcasecmp("lavender", value) == 0) {
            color.r = 230;
            color.g = 230;
            color.b = 250;
        } 
        // Blue colors
        else if (strcasecmp("midnightblue", value) == 0) {
            color.r = 25;
            color.g = 25;
            color.b = 112;
        } else if (strcasecmp("darkblue", value) == 0) {
            color.r = 0;
            color.g = 0;
            color.b = 139;
        } else if (strcasecmp("mediumblue", value) == 0) {
            color.r = 0;
            color.g = 0;
            color.b = 205;
        } else if (strcasecmp("royalblue", value) == 0) {
            color.r = 65;
            color.g = 105;
            color.b = 225;
        } else if (strcasecmp("steelblue", value) == 0) {
            color.r = 70;
            color.g = 130;
            color.b = 180;
        } else if (strcasecmp("dodgerblue", value) == 0) {
            color.r = 30;
            color.g = 144;
            color.b = 255;
        } else if (strcasecmp("deepskyblue", value) == 0) {
            color.r = 0;
            color.g = 191;
            color.b = 255;
        } else if (strcasecmp("cornflowerblue", value) == 0) {
            color.r = 100;
            color.g = 149;
            color.b = 237;
        } else if (strcasecmp("skyblue", value) == 0) {
            color.r = 135;
            color.g = 206;
            color.b = 235;
        } else if (strcasecmp("lightskyblue", value) == 0) {
            color.r = 135;
            color.g = 206;
            color.b = 250;
        } else if (strcasecmp("lightsteelblue", value) == 0) {
            color.r = 176;
            color.g = 196;
            color.b = 222;
        } else if (strcasecmp("lightblue", value) == 0) {
            color.r = 173;
            color.g = 216;
            color.b = 230;
        } else if (strcasecmp("powderblue", value) == 0) {
            color.r = 176;
            color.g = 224;
            color.b = 230;
        } 
        // Cyan colors
        else if (strcasecmp("darkcyan", value) == 0) {
            color.r = 0;
            color.g = 139;
            color.b = 139;
        } else if (strcasecmp("lightseagreen", value) == 0) {
            color.r = 32;
            color.g = 178;
            color.b = 170;
        } else if (strcasecmp("cadetblue", value) == 0) {
            color.r = 95;
            color.g = 158;
            color.b = 160;
        } else if (strcasecmp("darkturquoise", value) == 0) {
            color.r = 0;
            color.g = 206;
            color.b = 209;
        } else if (strcasecmp("mediumturquoise", value) == 0) {
            color.r = 72;
            color.g = 209;
            color.b = 204;
        } else if (strcasecmp("turquoise", value) == 0) {
            color.r = 64;
            color.g = 224;
            color.b = 208;
        } else if (strcasecmp("cyan", value) == 0) {
            color.r = 0;
            color.g = 255;
            color.b = 255;
        } else if (strcasecmp("aquamarine", value) == 0) {
            color.r = 127;
            color.g = 255;
            color.b = 212;
        } else if (strcasecmp("paleturquoise", value) == 0) {
            color.r = 175;
            color.g = 238;
            color.b = 238;
        } else if (strcasecmp("lightcyan", value) == 0) {
            color.r = 224;
            color.g = 255;
            color.b = 255;
        } 
        // Green colors
        else if (strcasecmp("darkgreen", value) == 0) {
            color.r = 0;
            color.g = 100;
            color.b = 0;
        } else if (strcasecmp("darkolivegreen", value) == 0) {
            color.r = 85;
            color.g = 107;
            color.b = 47;
        } else if (strcasecmp("forestgreen", value) == 0) {
            color.r = 34;
            color.g = 139;
            color.b = 34;
        } else if (strcasecmp("seagreen", value) == 0) {
            color.r = 46;
            color.g = 139;
            color.b = 87;
        } else if (strcasecmp("olivedrab", value) == 0) {
            color.r = 107;
            color.g = 142;
            color.b = 35;
        } else if (strcasecmp("mediumseagreen", value) == 0) {
            color.r = 60;
            color.g = 179;
            color.b = 113;
        } else if (strcasecmp("limegreen", value) == 0) {
            color.r = 50;
            color.g = 205;
            color.b = 50;
        } else if (strcasecmp("springgreen", value) == 0) {
            color.r = 0;
            color.g = 255;
            color.b = 127;
        } else if (strcasecmp("mediumspringgreen", value) == 0) {
            color.r = 0;
            color.g = 250;
            color.b = 154;
        } else if (strcasecmp("darkseagreen", value) == 0) {
            color.r = 143;
            color.g = 188;
            color.b = 143;
        } else if (strcasecmp("mediumaquamarine", value) == 0) {
            color.r = 102;
            color.g = 205;
            color.b = 170;
        } else if (strcasecmp("yellowgreen", value) == 0) {
            color.r = 154;
            color.g = 205;
            color.b = 50;
        } else if (strcasecmp("lawngreen", value) == 0) {
            color.r = 124;
            color.g = 252;
            color.b = 0;
        } else if (strcasecmp("chartreuse", value) == 0) {
            color.r = 127;
            color.g = 255;
            color.b = 0;
        } else if (strcasecmp("lightgreen", value) == 0) {
            color.r = 144;
            color.g = 238;
            color.b = 144;
        } else if (strcasecmp("greenyellow", value) == 0) {
            color.r = 173;
            color.g = 255;
            color.b = 47;
        } else if (strcasecmp("palegreen", value) == 0) {
            color.r = 152;
            color.g = 251;
            color.b = 152;
        } 
        // White colors
        else if (strcasecmp("mistyrose", value) == 0) {
            color.r = 255;
            color.g = 228;
            color.b = 225;
        } else if (strcasecmp("antiquewhite", value) == 0) {
            color.r = 250;
            color.g = 235;
            color.b = 215;
        } else if (strcasecmp("linen", value) == 0) {
            color.r = 250;
            color.g = 240;
            color.b = 230;
        } else if (strcasecmp("beige", value) == 0) {
            color.r = 245;
            color.g = 245;
            color.b = 220;
        } else if (strcasecmp("whitesmoke", value) == 0) {
            color.r = 245;
            color.g = 245;
            color.b = 245;
        } else if (strcasecmp("lavenderblush", value) == 0) {
            color.r = 255;
            color.g = 240;
            color.b = 245;
        } else if (strcasecmp("oldlace", value) == 0) {
            color.r = 253;
            color.g = 245;
            color.b = 230;
        } else if (strcasecmp("aliceblue", value) == 0) {
            color.r = 240;
            color.g = 248;
            color.b = 255;
        } else if (strcasecmp("seashell", value) == 0) {
            color.r = 255;
            color.g = 245;
            color.b = 238;
        } else if (strcasecmp("ghostwhite", value) == 0) {
            color.r = 248;
            color.g = 248;
            color.b = 255;
        } else if (strcasecmp("honeydew", value) == 0) {
            color.r = 240;
            color.g = 255;
            color.b = 240;
        } else if (strcasecmp("floralwhite", value) == 0) {
            color.r = 255;
            color.g = 250;
            color.b = 240;
        } else if (strcasecmp("azure", value) == 0) {
            color.r = 240;
            color.g = 255;
            color.b = 255;
        } else if (strcasecmp("mintcream", value) == 0) {
            color.r = 245;
            color.g = 255;
            color.b = 250;
        } else if (strcasecmp("snow", value) == 0) {
            color.r = 255;
            color.g = 250;
            color.b = 250;
        } else if (strcasecmp("ivory", value) == 0) {
            color.r = 255;
            color.g = 255;
            color.b = 240;
        }
        // Gray and black colors
        else if (strcasecmp("darkslategray", value) == 0) {
            color.r = 47;
            color.g = 79;
            color.b = 79;
        } else if (strcasecmp("dimgray", value) == 0) {
            color.r = 105;
            color.g = 105;
            color.b = 105;
        } else if (strcasecmp("slategray", value) == 0) {
            color.r = 112;
            color.g = 128;
            color.b = 144;
        } else if (strcasecmp("lightslategray", value) == 0) {
            color.r = 119;
            color.g = 136;
            color.b = 153;
        } else if (strcasecmp("darkgray", value) == 0) {
            color.r = 169;
            color.g = 169;
            color.b = 169;
        } else if (strcasecmp("lightgray", value) == 0) {
            color.r = 211;
            color.g = 211;
            color.b = 211;
        } else if (strcasecmp("gainsboro", value) == 0) {
            color.r = 220;
            color.g = 220;
            color.b = 220;
        } else {
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

    if (strcasecmp("left", value) == 0) {
        clear = CLEAR_LEFT;
    } else if (strcasecmp("right", value) == 0) {
        clear = CLEAR_RIGHT;
    } else if (strcasecmp("all", value) == 0) {
        clear = CLEAR_ALL;
    } else if (strcasecmp("none", value) == 0) {
        clear = CLEAR_NONE;
    } else {
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

    if (strcasecmp("void", value) == 0) {
        tframe = TF_VOID;
    } else if (strcasecmp("above", value) == 0) {
        tframe = TF_ABOVE;
    } else if (strcasecmp("below", value) == 0) {
        tframe = TF_BELOW;
    } else if (strcasecmp("hsides", value) == 0) {
        tframe = TF_HSIDES;
    } else if (strcasecmp("lhs", value) == 0) {
        tframe = TF_LHS;
    } else if (strcasecmp("rhs", value) == 0) {
        tframe = TF_RHS;
    } else if (strcasecmp("vsides", value) == 0) {
        tframe = TF_VSIDES;
    } else if (strcasecmp("box", value) == 0) {
        tframe = TF_BOX;
    } else if (strcasecmp("border", value) == 0) {
        tframe = TF_BORDER;
    } else {
        printf("HTML_ParseTFrameAttribute: Unknown tframe %s\n", value);
    }

    return tframe;
}

method_t HTML_ParseMethodAttribute(char* value)
{
    method_t method;

    if (strcasecmp("get", value) == 0) {
        method = METHOD_GET;
    } else if (strcasecmp("post", value) == 0) {
        method = METHOD_POST;
    } else {
        printf("HTML_ParseMethodAttribute: Unknown method %s\n", value);
    }

    return method;
}

trules_t HTML_ParseTRulesAttribute(char* value)
{
    trules_t trules;

    if (strcasecmp("none", value) == 0) {
        trules = TR_NONE;
    } else if (strcasecmp("groups", value) == 0) {
        trules = TR_GROUPS;
    } else if (strcasecmp("rows", value) == 0) {
        trules = TR_ROWS;
    } else if (strcasecmp("cols", value) == 0) {
        trules = TR_COLS;
    } else if (strcasecmp("all", value) == 0) {
        trules = TR_ALL;
    } else {
        printf("HTML_ParseTRulesAttribute: Unknown rule %s\n", value);
    }

    return trules;
}

scope_t HTML_ParseScopeAttribute(char* value)
{
    scope_t scope;

    if (strcasecmp("row", value) == 0) {
        scope = SCOPE_ROW;
    } else if (strcasecmp("col", value) == 0) {
        scope = SCOPE_COL;
    } else if (strcasecmp("rowgroup", value) == 0) {
        scope = SCOPE_ROWGROUP;
    } else if (strcasecmp("colgroup", value) == 0) {
        scope = SCOPE_COLGROUP;
    } else {
        printf("HTML_ParseScopeAttribute: Unknown scope %s\n", value);
    }

    return scope;
}

scroll_t HTML_ParseScrollAttribute(char* value)
{
    scroll_t scroll;

    if (strcasecmp("yes", value) == 0) {
        scroll = SCROLL_YES;
    } else if (strcasecmp("no", value) == 0) {
        scroll = SCROLL_NO;
    } else if (strcasecmp("auto", value) == 0) {
        scroll = SCROLL_AUTO;
    } else {
        printf("HTML_ParseScrollAttribute: Unknown scroll value %s\n", value);
    }

    return scroll;
}

shape_t HTML_ParseShapeAttribute(char* value)
{
    shape_t shape;

    if (strcasecmp("rect", value) == 0) {
        shape = SHAPE_RECT;
    } else if (strcasecmp("circle", value) == 0) {
        shape = SHAPE_CIRCLE;
    } else if (strcasecmp("poly", value) == 0) {
        shape = SHAPE_POLY;
    } else if (strcasecmp("default", value) == 0) {
        shape = SHAPE_DEFAULT;
    } else {
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

    if (strcasecmp("top", value) == 0) {
        valign = VA_TOP;
    } else if (strcasecmp("middle", value) == 0) {
        valign = VA_MIDDLE;
    } else if (strcasecmp("bottom", value) == 0) {
        valign = VA_BOTTOM;
    } else if (strcasecmp("baseline", value) == 0) {
        valign = VA_BASELINE;
    } else {
        printf("HTML_ParseShapeAttribute: Unknown valign %s\n", value);
    }

    return valign;
}

valuetype_t HTML_ParseValueTypeAttribute(char* value)
{
    valuetype_t valuetype;

    if (strcasecmp("data", value) == 0) {
        valuetype = VT_DATA;
    } else if (strcasecmp("ref", value) == 0) {
        valuetype = VT_REF;
    } else if (strcasecmp("object", value) == 0) {
        valuetype = VT_OBJECT;
    } else {
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

    if (attribute_name[0] == 'a' || attribute_name[0] == 'A') {
        if (strcasecmp(attribute_name, "abbr") == 0) {
            attributes->abbr = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "accept-charset") == 0) {
            attributes->accept_charset = HTML_ParseCharsetsAttribute(real_value);
        } else if (strcasecmp(attribute_name, "accept") == 0) {
            attributes->accept = HTML_ParseContentTypesAttribute(real_value);
        } else if (strcasecmp(attribute_name, "accesskey") == 0) {
            attributes->accesskey = HTML_ParseCharacterAttribute(real_value);
        } else if (strcasecmp(attribute_name, "action") == 0) {
            attributes->action = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "align") == 0) {
            attributes->align = HTML_ParseAlignAttribute(real_value);
        } else if (strcasecmp(attribute_name, "alt") == 0) {
            attributes->alt = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "archive") == 0) {
            attributes->archive = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "axis") == 0) {
            attributes->axis = HTML_ParseTextAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'b' || attribute_name[0] == 'B') {
        if (strcasecmp(attribute_name, "background") == 0) {
            attributes->background = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "bgcolor") == 0) {
            attributes->bgcolor = HTML_ParseColorAttribute(real_value);
        } else if (strcasecmp(attribute_name, "border") == 0) {
            attributes->border = HTML_ParsePixelsAttribute(real_value);
        } else if (strcasecmp(attribute_name, "bottommargin") == 0) {
            attributes->bottommargin = HTML_ParseLengthAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'c' || attribute_name[0] == 'C') {
        if (strcasecmp(attribute_name, "cellpadding") == 0) {
            attributes->cellpadding = HTML_ParseLengthAttribute(real_value);
        } else if (strcasecmp(attribute_name, "cellspacing") == 0) {
            attributes->cellspacing = HTML_ParseLengthAttribute(real_value);
        } else if (strcasecmp(attribute_name, "char") == 0) {
            attributes->_char = HTML_ParseCharacterAttribute(real_value);
        } else if (strcasecmp(attribute_name, "charoff") == 0) {
            attributes->charoff = HTML_ParseLengthAttribute(real_value);
        } else if (strcasecmp(attribute_name, "charset") == 0) {
            attributes->charset = HTML_ParseCharsetsAttribute(real_value);
        } else if (strcasecmp(attribute_name, "checked") == 0) {
            if(attributes->checked != true) {
                printf("HTML_ParseAttributeContent: Attribute '%s' already defined. Ignoring duplicate definition.\n", attribute_name);
            } else {
                attributes->checked = true;
            }
        } else if (strcasecmp(attribute_name, "cite") == 0) {
            attributes->cite = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "class") == 0) {
            attributes->class = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "classid") == 0) {
            attributes->class = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "clear") == 0) {
            attributes->clear = HTML_ParseClearAttribute(real_value);
        } else if (strcasecmp(attribute_name, "code") == 0) {
            attributes->code = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "codebase") == 0) {
            attributes->codebase = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "codetype") == 0) {
            attributes->codetype = HTML_ParseContentTypesAttribute(real_value);
        } else if (strcasecmp(attribute_name, "color") == 0) {
            attributes->color = HTML_ParseColorAttribute(real_value);
        } else if (strcasecmp(attribute_name, "cols") == 0) {
            attributes->cols = HTML_ParseLengthAttribute(real_value);
        } else if (strcasecmp(attribute_name, "colspan") == 0) {
            attributes->colspan = HTML_ParseNumberAttribute(real_value);
        } else if (strcasecmp(attribute_name, "compact") == 0) {
            attributes->compact = true;
        } else if (strcasecmp(attribute_name, "content") == 0) {
            attributes->content = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "coords") == 0) {
            attributes->coords = HTML_ParseCoordsAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'd' || attribute_name[0] == 'D') {
        if (strcasecmp(attribute_name, "data") == 0) {
            attributes->data = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "datetime") == 0) {
            attributes->datetime = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "declare") == 0) {
            attributes->declare = true;
        } else if (strcasecmp(attribute_name, "dir") == 0) {
            attributes->dir = true;
        } else if (strcasecmp(attribute_name, "disabled") == 0) {
            attributes->disabled = true;
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'e' || attribute_name[0] == 'E') {
        if (strcasecmp(attribute_name, "enctype") == 0) {
            attributes->enctype = HTML_ParseContentTypesAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'f' || attribute_name[0] == 'F') {
        if (strcasecmp(attribute_name, "face") == 0) {
            attributes->face = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "for") == 0) {
            attributes->_for = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "frame") == 0) {
            attributes->frame = HTML_ParseTFrameAttribute(real_value);
        } else if (strcasecmp(attribute_name, "frameborder") == 0) {
            if (real_value[0] == '0')
                attributes->frameborder = false;
            else if (real_value[0] == '1')
                attributes->frameborder = true;
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'h' || attribute_name[0] == 'H') {
        if (strcasecmp(attribute_name, "headers") == 0) {
            attributes->headers = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "height") == 0) {
            attributes->height = HTML_ParseLengthAttribute(real_value);
        } else if (strcasecmp(attribute_name, "href") == 0) {
            attributes->href = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "hreflang") == 0) {
            attributes->hreflang = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "hspace") == 0) {
            attributes->hspace = HTML_ParsePixelsAttribute(real_value);
        } else if (strcasecmp(attribute_name, "http-equiv") == 0) {
            attributes->http_equiv = HTML_ParseTextAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'i' || attribute_name[0] == 'I') {
        if (strcasecmp(attribute_name, "id") == 0) {
            attributes->id = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "ismap") == 0) {
            attributes->ismap = true;
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'l' || attribute_name[0] == 'L') {
        if (strcasecmp(attribute_name, "label") == 0) {
            attributes->label = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "lang") == 0) {
            attributes->lang = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "language") == 0) {
            attributes->language = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "leftmargin") == 0) {
            attributes->leftmargin = HTML_ParseLengthAttribute(real_value);
        } else if (strcasecmp(attribute_name, "link") == 0) {
            attributes->link = HTML_ParseColorAttribute(real_value);
        } else if (strcasecmp(attribute_name, "longdesc") == 0) {
            attributes->longdesc = HTML_ParseTextAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'm' || attribute_name[0] == 'M') {
        if (strcasecmp(attribute_name, "marginheight") == 0) {
            attributes->marginheight = HTML_ParsePixelsAttribute(real_value);
        } else if (strcasecmp(attribute_name, "marginwidth") == 0) {
            attributes->marginwidth = HTML_ParsePixelsAttribute(real_value);
        } else if (strcasecmp(attribute_name, "maxlength") == 0) {
            attributes->maxlength = HTML_ParseNumberAttribute(real_value);
        } else if (strcasecmp(attribute_name, "media") == 0) {
            attributes->media = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "method") == 0) {
            attributes->method = HTML_ParseMethodAttribute(real_value);
        } else if (strcasecmp(attribute_name, "multiple") == 0) {
            attributes->multiple = true;
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'n' || attribute_name[0] == 'N') {
        if (strcasecmp(attribute_name, "name") == 0) {
            attributes->name = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "nohref") == 0) {
            attributes->nohref = true;
        } else if (strcasecmp(attribute_name, "noresize") == 0) {
            attributes->noresize = true;
        } else if (strcasecmp(attribute_name, "noshade") == 0) {
            attributes->noshade = true;
        } else if (strcasecmp(attribute_name, "nowrap") == 0) {
            attributes->nowrap = true;
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'o' || attribute_name[0] == 'O') {
        if (strcasecmp(attribute_name, "object") == 0) {
            attributes->object = HTML_ParseTextAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'p' || attribute_name[0] == 'P') {
        if (strcasecmp(attribute_name, "profile") == 0) {
            attributes->profile = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "prompt") == 0) {
            attributes->prompt = HTML_ParseTextAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'r' || attribute_name[0] == 'R') {
        if (strcasecmp(attribute_name, "readonly") == 0) {
            attributes->readonly = true;
        } else if (strcasecmp(attribute_name, "rel") == 0) {
            attributes->rel = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "required") == 0) {
            if(attributes->required != true) {
                printf("HTML_ParseAttributeContent: Attribute '%s' already defined. Ignoring duplicate definition.\n", attribute_name);
            } else {
                attributes->required = true;
            }
            attributes->required = true;
        } else if (strcasecmp(attribute_name, "rightmargin") == 0) {
            attributes->rightmargin = HTML_ParseLengthAttribute(real_value);
        } else if (strcasecmp(attribute_name, "rows") == 0) {
            attributes->rows = HTML_ParseLengthAttribute(real_value);
        } else if (strcasecmp(attribute_name, "rowspan") == 0) {
            attributes->rowspan = HTML_ParseNumberAttribute(real_value);
        } else if (strcasecmp(attribute_name, "rules") == 0) {
            attributes->rules = HTML_ParseTRulesAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 's' || attribute_name[0] == 'S') {
        if (strcasecmp(attribute_name, "scheme") == 0) {
            attributes->scheme = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "scope") == 0) {
            attributes->scope = HTML_ParseScopeAttribute(real_value);
        } else if (strcasecmp(attribute_name, "scrolling") == 0) {
            attributes->scrolling = HTML_ParseScrollAttribute(real_value);
        } else if (strcasecmp(attribute_name, "selected") == 0) {
            attributes->selected = true;
        } else if (strcasecmp(attribute_name, "shape") == 0) {
            attributes->shape = HTML_ParseShapeAttribute(real_value);
        } else if (strcasecmp(attribute_name, "size") == 0) {
            attributes->size = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "span") == 0) {
            attributes->span = HTML_ParseNumberAttribute(real_value);
        } else if (strcasecmp(attribute_name, "src") == 0) {
            attributes->src = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "standby") == 0) {
            attributes->standby = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "start") == 0) {
            attributes->start = HTML_ParseNumberAttribute(real_value);
        } else if (strcasecmp(attribute_name, "style") == 0) {
            if(attributes->style != NULL) {
                printf("HTML_ParseAttributeContent: Attribute '%s' already defined. Ignoring duplicate definition.\n", attribute_name);
            } else {
                attributes->style = HTML_ParseStyleSheetAttribute(real_value);
            }
        } else if (strcasecmp(attribute_name, "summary") == 0) {
            attributes->summary = HTML_ParseTextAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 't' || attribute_name[0] == 'T') {
        if (strcasecmp(attribute_name, "tabindex") == 0) {
            attributes->tabindex = HTML_ParseNumberAttribute(real_value);
        } else if (strcasecmp(attribute_name, "target") == 0) {
            attributes->target = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "text") == 0) {
            attributes->text = HTML_ParseColorAttribute(real_value);
        } else if (strcasecmp(attribute_name, "title") == 0) {
            attributes->title = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "topmargin") == 0) {
            attributes->topmargin = HTML_ParseLengthAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'u' || attribute_name[0] == 'U') {
        if (strcasecmp(attribute_name, "usemap") == 0) {
            attributes->usemap = HTML_ParseTextAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'v' || attribute_name[0] == 'V') {
        if (strcasecmp(attribute_name, "valign") == 0) {
            attributes->valign = HTML_ParseVAlignAttribute(real_value);
        } else if (strcasecmp(attribute_name, "value") == 0) {
            attributes->value = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "valuetype") == 0) {
            attributes->valuetype = HTML_ParseValueTypeAttribute(real_value);
        } else if (strcasecmp(attribute_name, "version") == 0) {
            attributes->version = HTML_ParseTextAttribute(real_value);
        } else if (strcasecmp(attribute_name, "vlink") == 0) {
            attributes->vlink = HTML_ParseColorAttribute(real_value);
        } else if (strcasecmp(attribute_name, "vspace") == 0) {
            attributes->vspace = HTML_ParsePixelsAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else if (attribute_name[0] == 'w' || attribute_name[0] == 'W') {
        if (strcasecmp(attribute_name, "width") == 0) {
            attributes->width = HTML_ParseLengthAttribute(real_value);
        } else {
            printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
            attribute_name);
        }
    } else {
        printf("HTML_ParseAttributeContent: Unrecognized attribute name %s\n", 
        attribute_name);
    }

}
