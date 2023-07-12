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

#define ASSIGN_ELEM(tag, name, element) { \
    if (strcasecmp(tag, name) == 0) { \
        return element; \
    } \
}

byte HTML_GetIDFromTagString(char* tag_name)
{
    ASSIGN_ELEM(tag_name, "a", HTML_ELEM_A);
    ASSIGN_ELEM(tag_name, "abbr", HTML_ELEM_ABBR);
    ASSIGN_ELEM(tag_name, "acronym", HTML_ELEM_ACRONYM);
    ASSIGN_ELEM(tag_name, "address", HTML_ELEM_ADDRESS);
    ASSIGN_ELEM(tag_name, "applet", HTML_ELEM_APPLET);
    ASSIGN_ELEM(tag_name, "area", HTML_ELEM_AREA);
    ASSIGN_ELEM(tag_name, "b", HTML_ELEM_B);
    ASSIGN_ELEM(tag_name, "base", HTML_ELEM_BASE);
    ASSIGN_ELEM(tag_name, "basefont", HTML_ELEM_BASEFONT);
    ASSIGN_ELEM(tag_name, "bdo", HTML_ELEM_BDO);
    ASSIGN_ELEM(tag_name, "big", HTML_ELEM_BIG);
    ASSIGN_ELEM(tag_name, "blockquote", HTML_ELEM_BLOCKQUOTE);
    ASSIGN_ELEM(tag_name, "body", HTML_ELEM_BODY);
    ASSIGN_ELEM(tag_name, "br", HTML_ELEM_BR);
    ASSIGN_ELEM(tag_name, "button", HTML_ELEM_BUTTON);
    ASSIGN_ELEM(tag_name, "caption", HTML_ELEM_CAPTION);
    ASSIGN_ELEM(tag_name, "center", HTML_ELEM_CENTER);
    ASSIGN_ELEM(tag_name, "cite", HTML_ELEM_CITE);
    ASSIGN_ELEM(tag_name, "code", HTML_ELEM_CODE);
    ASSIGN_ELEM(tag_name, "col", HTML_ELEM_COL);
    ASSIGN_ELEM(tag_name, "colgroup", HTML_ELEM_COLGROUP);
    ASSIGN_ELEM(tag_name, "dd", HTML_ELEM_DD);
    ASSIGN_ELEM(tag_name, "del", HTML_ELEM_DEL);
    ASSIGN_ELEM(tag_name, "dfn", HTML_ELEM_DFN);
    ASSIGN_ELEM(tag_name, "dir", HTML_ELEM_DIR);
    ASSIGN_ELEM(tag_name, "div", HTML_ELEM_DIV);
    ASSIGN_ELEM(tag_name, "dl", HTML_ELEM_DL);
    ASSIGN_ELEM(tag_name, "dt", HTML_ELEM_DT);
    ASSIGN_ELEM(tag_name, "em", HTML_ELEM_EM);
    ASSIGN_ELEM(tag_name, "fieldset", HTML_ELEM_FIELDSET);
    ASSIGN_ELEM(tag_name, "font", HTML_ELEM_FONT);
    ASSIGN_ELEM(tag_name, "form", HTML_ELEM_FORM);
    ASSIGN_ELEM(tag_name, "frame", HTML_ELEM_FRAME);
    ASSIGN_ELEM(tag_name, "frameset", HTML_ELEM_FRAMESET);
    ASSIGN_ELEM(tag_name, "h1", HTML_ELEM_H1);
    ASSIGN_ELEM(tag_name, "h2", HTML_ELEM_H2);
    ASSIGN_ELEM(tag_name, "h3", HTML_ELEM_H3);
    ASSIGN_ELEM(tag_name, "h4", HTML_ELEM_H4);
    ASSIGN_ELEM(tag_name, "h5", HTML_ELEM_H5);
    ASSIGN_ELEM(tag_name, "h6", HTML_ELEM_H6);
    ASSIGN_ELEM(tag_name, "head", HTML_ELEM_HEAD);
    ASSIGN_ELEM(tag_name, "hr", HTML_ELEM_HR);
    ASSIGN_ELEM(tag_name, "html", HTML_ELEM_HTML);
    ASSIGN_ELEM(tag_name, "i", HTML_ELEM_I);
    ASSIGN_ELEM(tag_name, "iframe", HTML_ELEM_IFRAME);
    ASSIGN_ELEM(tag_name, "img", HTML_ELEM_IMG);
    ASSIGN_ELEM(tag_name, "input", HTML_ELEM_INPUT);
    ASSIGN_ELEM(tag_name, "ins", HTML_ELEM_INS);
    ASSIGN_ELEM(tag_name, "isindex", HTML_ELEM_ISINDEX);
    ASSIGN_ELEM(tag_name, "kbd", HTML_ELEM_KBD);
    ASSIGN_ELEM(tag_name, "label", HTML_ELEM_LABEL);
    ASSIGN_ELEM(tag_name, "legend", HTML_ELEM_LEGEND);
    ASSIGN_ELEM(tag_name, "li", HTML_ELEM_LI);
    ASSIGN_ELEM(tag_name, "link", HTML_ELEM_LINK);
    ASSIGN_ELEM(tag_name, "map", HTML_ELEM_MAP);
    ASSIGN_ELEM(tag_name, "menu", HTML_ELEM_MENU);
    ASSIGN_ELEM(tag_name, "meta", HTML_ELEM_META);
    ASSIGN_ELEM(tag_name, "noframes", HTML_ELEM_NOFRAMES);
    ASSIGN_ELEM(tag_name, "noscript", HTML_ELEM_NOSCRIPT);
    ASSIGN_ELEM(tag_name, "object", HTML_ELEM_OBJECT);
    ASSIGN_ELEM(tag_name, "ol", HTML_ELEM_OL);
    ASSIGN_ELEM(tag_name, "optgroup", HTML_ELEM_OPTGROUP);
    ASSIGN_ELEM(tag_name, "option", HTML_ELEM_OPTION);
    ASSIGN_ELEM(tag_name, "p", HTML_ELEM_P);
    ASSIGN_ELEM(tag_name, "param", HTML_ELEM_PARAM);
    ASSIGN_ELEM(tag_name, "pre", HTML_ELEM_PRE);
    ASSIGN_ELEM(tag_name, "q", HTML_ELEM_Q);
    ASSIGN_ELEM(tag_name, "s", HTML_ELEM_S);
    ASSIGN_ELEM(tag_name, "samp", HTML_ELEM_SAMP);
    ASSIGN_ELEM(tag_name, "script", HTML_ELEM_SCRIPT);
    ASSIGN_ELEM(tag_name, "select", HTML_ELEM_SELECT);
    ASSIGN_ELEM(tag_name, "small", HTML_ELEM_SMALL);
    ASSIGN_ELEM(tag_name, "span", HTML_ELEM_SPAN);
    ASSIGN_ELEM(tag_name, "strike", HTML_ELEM_STRIKE);
    ASSIGN_ELEM(tag_name, "strong", HTML_ELEM_STRONG);
    ASSIGN_ELEM(tag_name, "style", HTML_ELEM_STYLE);
    ASSIGN_ELEM(tag_name, "sub", HTML_ELEM_SUB);
    ASSIGN_ELEM(tag_name, "sup", HTML_ELEM_SUP);
    ASSIGN_ELEM(tag_name, "table", HTML_ELEM_TABLE);
    ASSIGN_ELEM(tag_name, "tbody", HTML_ELEM_TBODY);
    ASSIGN_ELEM(tag_name, "td", HTML_ELEM_TD);
    ASSIGN_ELEM(tag_name, "textarea", HTML_ELEM_TEXTAREA);
    ASSIGN_ELEM(tag_name, "tfoot", HTML_ELEM_TFOOT);
    ASSIGN_ELEM(tag_name, "th", HTML_ELEM_TH);
    ASSIGN_ELEM(tag_name, "thead", HTML_ELEM_THEAD);
    ASSIGN_ELEM(tag_name, "title", HTML_ELEM_TITLE);
    ASSIGN_ELEM(tag_name, "tr", HTML_ELEM_TR);
    ASSIGN_ELEM(tag_name, "tt", HTML_ELEM_TT);
    ASSIGN_ELEM(tag_name, "u", HTML_ELEM_U);
    ASSIGN_ELEM(tag_name, "ul", HTML_ELEM_UL);
    ASSIGN_ELEM(tag_name, "var", HTML_ELEM_VAR);

    printf("HTML_GetIDFromTagString: Unknown Element: %s\n", tag_name);
    return HTML_ELEM_ERROR;
}

void HTML_InitializeAttribute(attribute_t* attr) {
    // A
    attr->abbr              = NULL;
    attr->accept_charset    = CS_NONE;
    attr->accept            = CTYPE_NONE;
    attr->accesskey         = '\0';
    attr->action            = NULL;
    attr->align             = ALIGN_NONE;
    attr->alt               = NULL;
    attr->archive           = NULL;
    attr->axis              = NULL;
    // B
    attr->background        = NULL;
    attr->bgcolor.used      = false;
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
    attr->codetype          = CTYPE_NONE;
    attr->color.used        = false;
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
    attr->enctype           = CTYPE_NONE;
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
    attr->link.used         = false;
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
    attr->text.used         = false;
    attr->title             = NULL;
    // U
    attr->usemap            = NULL;
    // V
    attr->valign            = VA_NONE;
    attr->value             = NULL;
    attr->valuetype         = VT_NONE;
    attr->version           = NULL;
    attr->vlink.used        = false;
    attr->vspace            = -1;
    // W
    attr->width.len         = -1;
}