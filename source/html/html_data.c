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
#include <strings.h>

#include <types.h>
#include <html/html_datatype.h>

byte HTML_GetIDFromTagString(char* tag_name)
{
    if (strcasecmp(tag_name, "a") == 0) {
        return HTML_ELEM_A;
    }

    if (strcasecmp(tag_name, "abbr") == 0) {
        return HTML_ELEM_ABBR;
    }

    if (strcasecmp(tag_name, "acronym") == 0) {
        return HTML_ELEM_ACRONYM;
    }

    if (strcasecmp(tag_name, "address") == 0) {
        return HTML_ELEM_ADDRESS;
    }

    if (strcasecmp(tag_name, "applet") == 0) {
        return HTML_ELEM_APPLET;
    }

    if (strcasecmp(tag_name, "area") == 0) {
        return HTML_ELEM_AREA;
    }

    if (strcasecmp(tag_name, "b") == 0) {
        return HTML_ELEM_B;
    }

    if (strcasecmp(tag_name, "base") == 0) {
        return HTML_ELEM_BASE;
    }

    if (strcasecmp(tag_name, "basefont") == 0) {
        return HTML_ELEM_BASEFONT;
    }

    if (strcasecmp(tag_name, "bdo") == 0) {
        return HTML_ELEM_BDO;
    }

    if (strcasecmp(tag_name, "big") == 0) {
        return HTML_ELEM_BIG;
    }

    if (strcasecmp(tag_name, "blockquote") == 0) {
        return HTML_ELEM_BLOCKQUOTE;
    }

    if (strcasecmp(tag_name, "body") == 0) {
        return HTML_ELEM_BODY;
    }

    if (strcasecmp(tag_name, "br") == 0) {
        return HTML_ELEM_BR;
    }

    if (strcasecmp(tag_name, "button") == 0) {
        return HTML_ELEM_BUTTON;
    }

    if (strcasecmp(tag_name, "caption") == 0) {
        return HTML_ELEM_CAPTION;
    }

    if (strcasecmp(tag_name, "center") == 0) {
        return HTML_ELEM_CENTER;
    }

    if (strcasecmp(tag_name, "cite") == 0) {
        return HTML_ELEM_CITE;
    }

    if (strcasecmp(tag_name, "code") == 0) {
        return HTML_ELEM_CODE;
    }

    if (strcasecmp(tag_name, "col") == 0) {
        return HTML_ELEM_COL;
    }

    if (strcasecmp(tag_name, "colgroup") == 0) {
        return HTML_ELEM_COLGROUP;
    }

    if (strcasecmp(tag_name, "dd") == 0) {
        return HTML_ELEM_DD;
    }

    if (strcasecmp(tag_name, "del") == 0) {
        return HTML_ELEM_DEL;
    }

    if (strcasecmp(tag_name, "dfn") == 0) {
        return HTML_ELEM_DFN;
    }

    if (strcasecmp(tag_name, "dir") == 0) {
        return HTML_ELEM_DIR;
    }

    if (strcasecmp(tag_name, "div") == 0) {
        return HTML_ELEM_DIV;
    }

    if (strcasecmp(tag_name, "dl") == 0) {
        return HTML_ELEM_DL;
    }

    if (strcasecmp(tag_name, "dt") == 0) {
        return HTML_ELEM_DT;
    }

    if (strcasecmp(tag_name, "em") == 0) {
        return HTML_ELEM_EM;
    }

    if (strcasecmp(tag_name, "fieldset") == 0) {
        return HTML_ELEM_FIELDSET;
    }

    if (strcasecmp(tag_name, "font") == 0) {
        return HTML_ELEM_FONT;
    }

    if (strcasecmp(tag_name, "form") == 0) {
        return HTML_ELEM_FORM;
    }

    if (strcasecmp(tag_name, "frame") == 0) {
        return HTML_ELEM_FRAME;
    }

    if (strcasecmp(tag_name, "frameset") == 0) {
        return HTML_ELEM_FRAMESET;
    }

    if (strcasecmp(tag_name, "h1") == 0) {
        return HTML_ELEM_H1;
    }

    if (strcasecmp(tag_name, "h2") == 0) {
        return HTML_ELEM_H2;
    }

    if (strcasecmp(tag_name, "h3") == 0) {
        return HTML_ELEM_H3;
    }

    if (strcasecmp(tag_name, "h4") == 0) {
        return HTML_ELEM_H4;
    }

    if (strcasecmp(tag_name, "h5") == 0) {
        return HTML_ELEM_H5;
    }

    if (strcasecmp(tag_name, "h6") == 0) {
        return HTML_ELEM_H6;
    }

    if (strcasecmp(tag_name, "head") == 0) {
        return HTML_ELEM_HEAD;
    }

    if (strcasecmp(tag_name, "hr") == 0) {
        return HTML_ELEM_HR;
    }

    if (strcasecmp(tag_name, "html") == 0) {
        return HTML_ELEM_HTML;
    }

    if (strcasecmp(tag_name, "i") == 0) {
        return HTML_ELEM_I;
    }

    if (strcasecmp(tag_name, "iframe") == 0) {
        return HTML_ELEM_IFRAME;
    }

    if (strcasecmp(tag_name, "img") == 0) {
        return HTML_ELEM_IMG;
    }

    if (strcasecmp(tag_name, "input") == 0) {
        return HTML_ELEM_INPUT;
    }

    if (strcasecmp(tag_name, "ins") == 0) {
        return HTML_ELEM_INS;
    }

    if (strcasecmp(tag_name, "isindex") == 0) {
        return HTML_ELEM_ISINDEX;
    }

    if (strcasecmp(tag_name, "kbd") == 0) {
        return HTML_ELEM_KBD;
    }

    if (strcasecmp(tag_name, "label") == 0) {
        return HTML_ELEM_LABEL;
    }

    if (strcasecmp(tag_name, "legend") == 0) {
        return HTML_ELEM_LEGEND;
    }

    if (strcasecmp(tag_name, "li") == 0) {
        return HTML_ELEM_LI;
    }

    if (strcasecmp(tag_name, "link") == 0) {
        return HTML_ELEM_LINK;
    }

    if (strcasecmp(tag_name, "map") == 0) {
        return HTML_ELEM_MAP;
    }

    if (strcasecmp(tag_name, "menu") == 0) {
        return HTML_ELEM_MENU;
    }

    if (strcasecmp(tag_name, "meta") == 0) {
        return HTML_ELEM_META;
    }

    if (strcasecmp(tag_name, "noframes") == 0) {
        return HTML_ELEM_NOFRAMES;
    }

    if (strcasecmp(tag_name, "noscript") == 0) {
        return HTML_ELEM_NOSCRIPT;
    }

    if (strcasecmp(tag_name, "object") == 0) {
        return HTML_ELEM_OBJECT;
    }

    if (strcasecmp(tag_name, "ol") == 0) {
        return HTML_ELEM_OL;
    }

    if (strcasecmp(tag_name, "optgroup") == 0) {
        return HTML_ELEM_OPTGROUP;
    }

    if (strcasecmp(tag_name, "option") == 0) {
        return HTML_ELEM_OPTION;
    }

    if (strcasecmp(tag_name, "p") == 0) {
        return HTML_ELEM_P;
    }

    if (strcasecmp(tag_name, "param") == 0) {
        return HTML_ELEM_PARAM;
    }

    if (strcasecmp(tag_name, "pre") == 0) {
        return HTML_ELEM_PRE;
    }

    if (strcasecmp(tag_name, "q") == 0) {
        return HTML_ELEM_Q;
    }

    if (strcasecmp(tag_name, "s") == 0) {
        return HTML_ELEM_S;
    }

    if (strcasecmp(tag_name, "samp") == 0) {
        return HTML_ELEM_SAMP;
    }

    if (strcasecmp(tag_name, "script") == 0) {
        return HTML_ELEM_SCRIPT;
    }

    if (strcasecmp(tag_name, "select") == 0) {
        return HTML_ELEM_SELECT;
    }

    if (strcasecmp(tag_name, "small") == 0) {
        return HTML_ELEM_SMALL;
    }

    if (strcasecmp(tag_name, "span") == 0) {
        return HTML_ELEM_SPAN;
    }

    if (strcasecmp(tag_name, "strike") == 0) {
        return HTML_ELEM_STRIKE;
    }

    if (strcasecmp(tag_name, "strong") == 0) {
        return HTML_ELEM_STRONG;
    }

    if (strcasecmp(tag_name, "style") == 0) {
        return HTML_ELEM_STYLE;
    }

    if (strcasecmp(tag_name, "sub") == 0) {
        return HTML_ELEM_SUB;
    }

    if (strcasecmp(tag_name, "sup") == 0) {
        return HTML_ELEM_SUP;
    }

    if (strcasecmp(tag_name, "table") == 0) {
        return HTML_ELEM_TABLE;
    }

    if (strcasecmp(tag_name, "tbody") == 0) {
        return HTML_ELEM_TBODY;
    }

    if (strcasecmp(tag_name, "td") == 0) {
        return HTML_ELEM_TD;
    }

    if (strcasecmp(tag_name, "textarea") == 0) {
        return HTML_ELEM_TEXTAREA;
    }

    if (strcasecmp(tag_name, "tfoot") == 0) {
        return HTML_ELEM_TFOOT;
    }

    if (strcasecmp(tag_name, "th") == 0) {
        return HTML_ELEM_TH;
    }

    if (strcasecmp(tag_name, "thead") == 0) {
        return HTML_ELEM_THEAD;
    }

    if (strcasecmp(tag_name, "title") == 0) {
        return HTML_ELEM_TITLE;
    }

    if (strcasecmp(tag_name, "tr") == 0) {
        return HTML_ELEM_TR;
    }

    if (strcasecmp(tag_name, "tt") == 0) {
        return HTML_ELEM_TT;
    }

    if (strcasecmp(tag_name, "u") == 0) {
        return HTML_ELEM_U;
    }

    if (strcasecmp(tag_name, "ul") == 0) {
        return HTML_ELEM_UL;
    }

    if (strcasecmp(tag_name, "var") == 0) {
        return HTML_ELEM_VAR;
    }

    printf("HTML_GetIDFromTagString: Unknown Element: %s\n", tag_name);
    return HTML_ELEM_ERROR;
}

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