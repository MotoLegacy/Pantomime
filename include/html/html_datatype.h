#ifndef _HTMLDATA_H_
#define _HTMLDATA_H_

#include <stdbool.h>

#include "types.h"
#include "html_elements.h"
#include "html_attributetypes.h"

typedef struct {
    text_t*					abbr;
    charsets_t				accept_charset;
    contenttypes_t			accept;
    character_t			    accesskey;
    uri_t*					action;
    align_t                 align;
    text_t*                 alt;
    cdata_t*                archive;
    cdata_t*                axis;
    uri_t*                  background;
    color_t                 bgcolor;
    pixels_t                border;
    length_t                bottommargin;
    length_t                cellpadding;
    length_t                cellspacing;
    character_t             _char;              // Is this a stupid way to get around typing?
    length_t                charoff;
    charsets_t              charset;
    bool                    checked;
    uri_t*                  cite;
    cdata_t*                class;
    uri_t*                  classid;
    clear_t                 clear;
    cdata_t*                code;
    uri_t*                  codebase;
    contenttypes_t          codetype;
    color_t                 color;
    multilengths_t          cols;
    number_t                colspan;
    bool                    compact;
    cdata_t*                content;
    coords_t                coords;
    uri_t*                  data;
    datetime_t*             datetime;
    bool                    declare;
    // SCRIPT type for defer is unimplemented..
    bool                    dir;
    bool                    disabled;
    contenttypes_t          enctype;
    cdata_t*                face;
    idref_t*                _for;                // Is this a stupid way to get around typing?
    tframe_t                frame;
    bool                    frameborder;
    idrefs_t*               headers;
    length_t                height;
    uri_t*                  href;
    languagecode_t*         hreflang;
    pixels_t                hspace;
    name_t*                 http_equiv;
    _id_t*                  id;
    bool                    ismap;
    text_t*                 label;
    languagecode_t*         lang;
    cdata_t*                language;
    length_t                leftmargin;
    color_t                 link;
    uri_t*                  longdesc;
    pixels_t                marginheight;
    pixels_t                marginwidth;
    number_t                maxlength;
    mediadesc_t*            media;
    method_t                method;
    bool                    multiple;
    cdata_t*                name;
    bool                    nohref;
    bool                    noresize;
    bool                    noshade;
    bool                    nowrap;
    cdata_t*                object;
    // SCRIPT type for onblur is unimplemented..
    // SCRIPT type for onchange is unimplemented..
    // SCRIPT type for onclick is unimplemented..
    // SCRIPT type for ondblclick is unimplemented..
    // SCRIPT type for onfocus is unimplemented..
    // SCRIPT type for onkeydown is unimplemented..
    // SCRIPT type for onkeypress is unimplemented..
    // SCRIPT type for onkeyup is unimplemented..
    // SCRIPT type for onload is unimplemented..
    // SCRIPT type for onmousedown is unimplemented..
    // SCRIPT type for onmousemove is unimplemented..
    // SCRIPT type for onmouseout is unimplemented..
    // SCRIPT type for onmouseover is unimplemented..
    // SCRIPT type for onmouseup is unimplemented..
    // SCRIPT type for onreset is unimplemented..
    // SCRIPT type for onselect is unimplemented..
    // SCRIPT type for onsubmit is unimplemented..
    // SCRIPT type for onunload is unimplemented..
    uri_t*                  profile;
    text_t*                 prompt;
    bool                    readonly;
    bool                    required;
    linktypes_t*            rel;
    length_t                rightmargin;
    multilengths_t          rows;
    number_t                rowspan;
    trules_t                rules;
    cdata_t*                scheme;
    scope_t                 scope;
    scroll_t                scrolling;
    bool                    selected;
    shape_t                 shape;
    cdata_t*                size;
    number_t                span;
    uri_t*                  src;
    text_t*                 standby;
    number_t                start;
    stylesheet_t*           style;
    text_t*                 summary;
    number_t                tabindex;
    frametarget_t*          target;
    color_t                 text;
    text_t*                 title;
    length_t                topmargin;
    // TODO: These will be a bit more complicated to parse.
    //contenttypes_t          type_content;
    //style_t*                type_style;
    //ulstyle_t               type_ulstyle;
    uri_t*                  usemap;
    valign_t                valign;
    cdata_t*                value;
    valuetype_t             valuetype;
    cdata_t*                version;
    color_t                 vlink;
    pixels_t                vspace;
    length_t                width;
} attribute_t;

typedef struct {
    byte                    tag;            // The ID of the element.
    char*                   content;        // The text content inside of the element.
    bool                    has_attributes; // Whether or not the element contains attributes.
	attribute_t             attributes;     // The attribute storage structure for the element.
} element_t;

#endif // _HTMLDATA_H
